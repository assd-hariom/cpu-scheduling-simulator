
CPU Scheduling Simulator in C
# CPU Scheduling Simulator in C
Note

This project was developed primarily by me, with approximately 20% assistance from AI tools for coding support and documentation.

## Project Overview

The CPU Scheduling Simulator is a menu-driven program written in the C programming language that demonstrates the working of fundamental CPU scheduling algorithms used in Operating Systems. This project helps users understand how processes are scheduled and how different algorithms affect system performance.

The simulator accepts process details such as Arrival Time and Burst Time, executes selected scheduling algorithms, and calculates important metrics like Waiting Time and Turnaround Time.

---

## Algorithms Implemented

1. First Come First Serve (FCFS)
2. Shortest Job First (SJF) – Non-Preemptive
3. Round Robin (RR)

---

## Features

* Menu-driven interface
* User input for number of processes
* Gantt Chart display for scheduling visualization
* Waiting Time calculation
* Turnaround Time calculation
* Average Waiting Time and Average Turnaround Time
* Handles CPU idle time safely
* Simple and readable C implementation

---

## Technologies Used

* Programming Language: C
* Compiler: GCC
* Concepts: Operating Systems, CPU Scheduling, Process Management
* Platform: Linux / Windows / WSL

---

## How to Compile and Run

### Step 1: Compile the program

```bash
gcc cpu_scheduling_simulator.c -o scheduler
```

### Step 2: Run the program

```bash
./scheduler
```

---

## Example Input

Number of processes: 3

Process Details:

P1: Arrival Time = 0, Burst Time = 10
P2: Arrival Time = 1, Burst Time = 5
P3: Arrival Time = 2, Burst Time = 8

---

## Example Output

* Gantt Chart showing process execution order
* Waiting Time for each process
* Turnaround Time for each process
* Average Waiting Time
* Average Turnaround Time

---

## Learning Outcomes

By working with this project, students can:

* Understand CPU scheduling algorithms
* Learn process scheduling concepts
* Practice structured programming in C
* Prepare for Operating Systems lab exams and viva
* Build a basic system-level simulation program

---

## Future Improvements

* Add Priority Scheduling
* Add Preemptive SJF (Shortest Remaining Time First)
* Add graphical visualization of scheduling
* Export results to a file
* Sort processes automatically by arrival time

---

## Author

Name: Hariom Narayan Singh 
Course: Cdac LSP module 
Subject: Operating Systems
Year: 2026
