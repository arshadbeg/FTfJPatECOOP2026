import re
import os
import pandas as pd
import matplotlib.pyplot as plt

# ============================================================
# CONFIGURATION
# ============================================================
LOG_FILE = "wp_output_all.txt"
OUTPUT_DIR = "figures_wp"
SOLVERS = ["Alt-Ergo", "Z3", "CVC4", "CVC5"]

os.makedirs(OUTPUT_DIR, exist_ok=True)

# ============================================================
# STEP 1: Load log file
# ============================================================
with open(LOG_FILE, "r", encoding="utf-8", errors="ignore") as f:
    text = f.read()

# ============================================================
# STEP 2: Split into WP blocks
# ============================================================
wp_blocks = re.split(r"\[wp\] Running WP plugin\.\.\.", text)

records = []
solver_index = {}

for block in wp_blocks[1:]:
    # --------------------------------------------------------
    # Extract file name
    # --------------------------------------------------------
    file_match = re.search(r"Parsing\s+([A-Za-z0-9_\-]+(?:_rte)?\.c)", block)
    if not file_match:
        continue

    file_name = file_match.group(1)

    # --------------------------------------------------------
    # Assign solver round-robin per file
    # --------------------------------------------------------
    idx = solver_index.get(file_name, 0)
    solver = SOLVERS[idx] if idx < len(SOLVERS) else "Unknown"
    solver_index[file_name] = idx + 1

    # --------------------------------------------------------
    # Initialize record
    # --------------------------------------------------------
    record = {
        "file": file_name,
        "solver": solver,
        "proved": None,
        "goals": None,
        "timeouts": 0,
        "qed": 0,
        "qed_time_ms": None,
        "wp_ran": False,
    }

    # --------------------------------------------------------
    # WP ran marker
    # --------------------------------------------------------
    record["wp_ran"] = "[wp] Running WP plugin" in block

    # --------------------------------------------------------
    # Proved / goals
    # --------------------------------------------------------
    m = re.search(r"Proved goals:\s*(\d+)\s*/\s*(\d+)", block)
    if m:
        record["proved"] = int(m.group(1))
        record["goals"] = int(m.group(2))

    # --------------------------------------------------------
    # Timeouts
    # --------------------------------------------------------
    record["timeouts"] = len(re.findall(r"Timeout", block, re.IGNORECASE))

    # --------------------------------------------------------
    # Qed count and time
    # --------------------------------------------------------
    m = re.search(r"Qed:\s*(\d+)\s*\(([^)]*)\)", block)
    if m:
        record["qed"] = int(m.group(1))
        tm = re.search(r"([0-9.]+)\s*ms", m.group(2))
        if tm:
            record["qed_time_ms"] = float(tm.group(1))

    records.append(record)

# ============================================================
# STEP 3: Build DataFrame
# ============================================================
df = pd.DataFrame(records)

for col in ["proved", "goals", "timeouts", "qed", "qed_time_ms", "wp_ran"]:
    if col not in df.columns:
        df[col] = pd.NA

# Proof success (raw numeric values retained)
df["proof_success_pct"] = (
    df["proved"] / df["goals"] * 100
).where(df["goals"].notna() & (df["goals"] > 0))

# ============================================================
# STEP 4: Summary statistics (STANDARD DEVIATION based)
# ============================================================
summary = df.groupby("solver").agg(
    runs=("file", "count"),
    wp_reached=("wp_ran", "sum"),
    min_success=("proof_success_pct", "min"),
    max_success=("proof_success_pct", "max"),
    std_success=("proof_success_pct", "std"),
    total_timeouts=("timeouts", "sum"),
    mean_qed_time_ms=("qed_time_ms", "mean"),
    std_qed_time_ms=("qed_time_ms", "std"),
)

print("\n===== WP VERIFIER SUMMARY (STD-BASED) =====\n")
print(summary.round(2))

# ============================================================
# STEP 5: Plot style
# ============================================================
plt.rcParams.update({
    "font.size": 12,
    "axes.titlesize": 14,
    "axes.labelsize": 12,
    "figure.figsize": (6, 4),
    "axes.grid": True,
    "grid.alpha": 0.3,
})

# ============================================================
# STEP 6: Box Plot – Proof Success per Solver
# ============================================================
plt.figure()
success_data = [
    df[(df["solver"] == solver) & df["proof_success_pct"].notna()]["proof_success_pct"]
    for solver in SOLVERS
]
plt.boxplot(success_data, labels=SOLVERS, showfliers=True)
plt.ylabel("Proof Success (%)")
plt.title("Proof Success Distribution by Solver")
plt.tight_layout()
plt.savefig(f"{OUTPUT_DIR}/proof_success_boxplot.png", dpi=300)
plt.close()

# ============================================================
# STEP 7: Box Plot – Qed Time per Solver
# ============================================================
plt.figure()
qed_time_data = [
    df[(df["solver"] == solver) & df["qed_time_ms"].notna()]["qed_time_ms"]
    for solver in SOLVERS
]
plt.boxplot(qed_time_data, labels=SOLVERS, showfliers=True)
plt.ylabel("Qed Time (ms)")
plt.title("Qed Time Distribution by Solver")
plt.tight_layout()
plt.savefig(f"{OUTPUT_DIR}/qed_time_boxplot.png", dpi=300)
plt.close()

# ============================================================
# STEP 8: WP execution outcome per solver
# ============================================================
outcomes = df.groupby("solver")["wp_ran"].value_counts().unstack(fill_value=0)
outcomes.plot(kind="bar", stacked=True)
plt.ylabel("Number of Runs")
plt.title("WP Execution Outcome by Solver")
plt.tight_layout()
plt.savefig(f"{OUTPUT_DIR}/wp_outcomes.png", dpi=300)
plt.close()

# ============================================================
# STEP 9: Automated numeric analysis paragraph
# ============================================================
analysis = []

for solver, row in summary.iterrows():
    variability = (
        "high" if row["std_success"] > 20 else
        "moderate" if row["std_success"] > 10 else
        "low"
    )

    stability = (
        "unstable" if row["std_qed_time_ms"] > row["mean_qed_time_ms"]
        else "consistent"
    )

    analysis.append(
        f"{solver} was executed {int(row['runs'])} times, with WP reaching proof "
        f"obligations in {int(row['wp_reached'])} runs. Proof success values ranged "
        f"from {row['min_success']:.2f} to {row['max_success']:.2f}, with a standard "
        f"deviation of {row['std_success']:.2f}, indicating {variability} variability "
        f"across verification tasks. The solver incurred {int(row['total_timeouts'])} "
        f"timeouts in total. Qed times had a mean of {row['mean_qed_time_ms']:.2f} ms "
        f"and a standard deviation of {row['std_qed_time_ms']:.2f} ms, suggesting "
        f"{stability} proof discharge performance."
    )

print("\n===== AUTOMATED SOLVER ANALYSIS =====\n")
print("\n\n".join(analysis))

print(f"\nAll WP verifier figures saved in: {OUTPUT_DIR}")

