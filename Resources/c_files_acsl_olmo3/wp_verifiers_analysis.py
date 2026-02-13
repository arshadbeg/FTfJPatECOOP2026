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
# STEP 2: Split into WP blocks
# Each run starts with "[wp] Running WP plugin..."
# ============================================================
wp_blocks = re.split(r"\[wp\] Running WP plugin\.\.\.", text)
records = []
solver_index = {}

for block in wp_blocks[1:]:  # skip preamble
    # --------------------------------------------------------
    # File name (from preceding kernel parsing line)
    # --------------------------------------------------------
    file_match = re.search(r"Parsing\s+([A-Za-z0-9_\-]+(?:_rte)?\.c)", block)
    if not file_match:
        continue
    file_name = file_match.group(1)

    # --------------------------------------------------------
    # Solver assignment (round-robin per file)
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
        "wp_ran": False
    }

    # --------------------------------------------------------
    # Mark WP as run if present
    # --------------------------------------------------------
    if "[wp] Running WP plugin" in block:
        record["wp_ran"] = True

    # --------------------------------------------------------
    # Extract proved/goals
    # --------------------------------------------------------
    m = re.search(r"Proved goals:\s*(\d+)\s*/\s*(\d+)", block)
    if m:
        record["proved"] = int(m.group(1))
        record["goals"] = int(m.group(2))

    # --------------------------------------------------------
    # Extract Timeout count
    # --------------------------------------------------------
    timeout_matches = re.findall(r"Timeout", block, re.IGNORECASE)
    record["timeouts"] = len(timeout_matches)

    # --------------------------------------------------------
    # Extract Qed count and time
    # e.g., Qed: 2 (0.56ms) or Qed: 0 (1ms-2ms)
    # --------------------------------------------------------
    m = re.search(r"Qed:\s*(\d+)\s*\(([^)]*)\)", block)
    if m:
        record["qed"] = int(m.group(1))
        time_part = m.group(2)
        tm = re.search(r"([0-9\.]+)\s*ms", time_part)
        if tm:
            record["qed_time_ms"] = float(tm.group(1))

    records.append(record)

# ============================================================
# STEP 3: Build DataFrame safely
# ============================================================
df = pd.DataFrame(records)

# Ensure columns exist even if no matches
for col in ["proved", "goals", "timeouts", "qed", "qed_time_ms", "wp_ran"]:
    if col not in df.columns:
        df[col] = pd.NA

# Compute proof success only for valid goals
df["proof_success_pct"] = (df["proved"] / df["goals"] * 100).where(
    df["goals"].notna() & (df["goals"] > 0)
)

# ============================================================
# STEP 4: Summary table
# ============================================================
summary = df.groupby("solver").agg(
    runs=("file", "count"),
    wp_reached=("wp_ran", "sum"),
    mean_success=("proof_success_pct", "mean"),
    median_success=("proof_success_pct", "median"),
    total_timeouts=("timeouts", "sum"),
    mean_qed_time_ms=("qed_time_ms", "mean"),
)

print("\n===== WP VERIFIER SUMMARY =====\n")
print(summary.round(2))

# ============================================================
# STEP 5: Plot style
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
    subset = df[(df["solver"] == solver) & df["proof_success_pct"].notna()]["proof_success_pct"]
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
success_counts = df.groupby("solver")["wp_ran"].value_counts().unstack(fill_value=0)
plt.figure()
success_counts.plot(kind="bar", stacked=True)
plt.ylabel("Number of WP Runs")
plt.title("WP Outcome by Solver (Success = WP ran)")
plt.tight_layout()
plt.savefig(f"{OUTPUT_DIR}/solver_outcomes.png", dpi=300)
plt.close()

print(f"\nAll WP verifier figures saved in: {OUTPUT_DIR}")

