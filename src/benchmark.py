import subprocess
import matplotlib.pyplot as plt
import re
import os

input_files = [
    "example0.in", "example2.in", "example3.in", "example4.in", "example5.in",
    "example6.in", "example7.in", "example8.in", "example9.in", "example10.in"
]

execution_times = []

for i, input_file in enumerate(input_files, start=1):
    base_name = os.path.splitext(input_file)[0]
    output_file = f"{base_name}.out"

    process = subprocess.Popen(
        ["a.exe"],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )

    stdin_input = f"{input_file}\n{output_file}\n"
    stdout, stderr = process.communicate(input=stdin_input)

    if process.returncode != 0:
        print(f"Error running {input_file}: {stderr}")
        continue

    match = re.search(r"Execution time:\s*([\d.]+)", stdout)
    if match:
        exec_time = float(match.group(1))
        execution_times.append(exec_time)
        print(f"{input_file} → {exec_time} seconds")
    else:
        print(f"No execution time found in output for {input_file}")
        print(stdout)  # debug

plt.figure(figsize=(10, 6))
plt.plot(input_files, execution_times, marker='o')
plt.title("Execution Time vs. Input Files")
plt.xlabel("Input File")
plt.ylabel("Execution Time (seconds)")
plt.xticks(rotation=45)
plt.tight_layout()
plt.savefig('../images/execution_time_graph.png')
print("Graph saved as 'execution_time_graph.png' in images folder.")