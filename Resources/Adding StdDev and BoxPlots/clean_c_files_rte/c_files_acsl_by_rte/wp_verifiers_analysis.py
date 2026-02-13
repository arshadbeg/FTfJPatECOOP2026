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
# STEP 1: Load log
# ============================================================
with open(LOG_FILE, "r", encoding="utf-8", errors="ignore") as f:
    text = f.read()

# ============================================================
# STEP 2: Split into WP runs
# Each run starts with "[wp] Running WP plugin..."
# ============================================================
wp_blocks = re.split(r"\[wp\] Running WP plugin\.\.\.", text)

records = []
solver_index = {}

for block in wp_blocks[1:]:  # skip preamble
    # --------------------------------------------------------
    # File name (from preceding kernel parsing line)
    # --------------------------------------------------------
    file_match = re.search(r"Parsing\s+([A-Za-z0-9_\-]+_rte\.c)", block)
    if not file_match:
        continue

    file_name = file_match.group(1)

    # --------------------------------------------------------
    # Solver assignment (round-robin per file)
    # --------------------------------------------------------
    idx = solver_index.get(file_name, 0)
    solver = SOLVERS[idx] if idx < len(SOLVERS) else "Unknown"
    solver_index[file_name] = idx + 1

    record = {
        "file": file_name,
        "solver": solver,
        "proved": 0,
        "goals": 0,
        "timeouts": 0,
        "qed": 0,
        "qed_time_ms": None,
        "analysis_successful": False
    }

    # --------------------------------------------------------
    # Proved goals
    # --------------------------------------------------------
    m = re.search(r"Proved goals:\s+(\d+)\s*/\s*(\d+)", block)
    if m:
        record["proved"] = int(m.group(1))
        record["goals"] = int(m.group(2))
        record["analysis_successful"] = True

    # --------------------------------------------------------
    # Timeout count
    # --------------------------------------------------------
    m = re.search(r"Timeout:\s+(\d+)", block)
    if m:
        record["timeouts"] = int(m.group(1))

    # --------------------------------------------------------
    # Qed count and time
    # Examples:
    # Qed: 0 (0.56ms)
    # Qed: 0 (1ms-2ms)
    # --------------------------------------------------------
    m = re.search(r"Qed:\s+(\d+)\s*\(([^)]*)\)", block)
    if m:
        record["qed"] = int(m.group(1))
        time_part = m.group(2)

        # Extract first ms value if present
        tm = re.search(r"([0-9\.]+)\s*ms", time_part)
        if tm:
            record["qed_time_ms"] = float(tm.group(1))

    records.append(record)

df = pd.DataFrame(records)

# ============================================================
# STEP 3: Derived metrics
# ============================================================
df["proof_success_pct"] = (df["proved"] / df["goals"]).where(df["goals"] > 0) * 100

# ============================================================
# STEP 4: Summary table (paper-ready)
# ============================================================
summary = df.groupby("solver").agg(
    runs=("file", "count"),
    mean_success=("proof_success_pct", "mean"),
    median_success=("proof_success_pct", "median"),
    total_timeouts=("timeouts", "sum"),
    mean_qed_time_ms=("qed_time_ms", "mean"),
)

print("\n===== WP VERIFIER SUMMARY =====\n")
print(summary.round(2))

# ============================================================
# STEP 5: Plot style (publishable)
# ============================================================
plt.rcParams.update({
    "font.size": 12,
    "axes.titlesize": 14,
    "axes.labelsize": 12,
    "figure.figsize": (6,4),
    "axes.grid": True,
    "grid.alpha": 0.3,
})

# ============================================================
# STEP 6: Histogram – Proof Success per Solver
# ============================================================
plt.figure()
for solver in SOLVERS:
    subset = df[df["solver"] == solver]["proof_success_pct"].dropna()
    plt.hist(subset, bins=20, alpha=0.6, label=solver)

plt.xlabel("Proof Success (%)")
plt.ylabel("Number of WP Runs")
plt.title("Distribution of Proof Success by Solver")
plt.legend()
plt.tight_layout()
plt.savefig(f"{OUTPUT_DIR}/proof_success_histogram.png", dpi=300)
plt.close()

# ============================================================
# STEP 7: Mean Proof Success per Solver
# ============================================================
plt.figure()
summary["mean_success"].plot(kind="bar")
plt.ylabel("Mean Proof Success (%)")
plt.title("Mean Proof Success by Solver")
plt.tight_layout()
plt.savefig(f"{OUTPUT_DIR}/mean_proof_success.png", dpi=300)
plt.close()

# ============================================================
# STEP 8: Timeouts per Solver
# ============================================================
plt.figure()
summary["total_timeouts"].plot(kind="bar")
plt.ylabel("Total Timeouts")
plt.title("Timeouts per Solver")
plt.tight_layout()
plt.savefig(f"{OUTPUT_DIR}/timeouts_per_solver.png", dpi=300)
plt.close()

# ============================================================
# STEP 9: Success vs Failure per Solver
# ============================================================
success_counts = df.groupby("solver")["analysis_successful"].value_counts().unstack(fill_value=0)

plt.figure()
success_counts.plot(kind="bar", stacked=True)
plt.ylabel("Number of WP Runs")
plt.title("WP Outcome by Solver")
plt.tight_layout()
plt.savefig(f"{OUTPUT_DIR}/solver_outcomes.png", dpi=300)
plt.close()

print(f"\nAll WP verifier figures saved in: {OUTPUT_DIR}")

