# Class Activity 2 — Processes & Inter-Process Communication

- **Student Name:** Phy Sopanha
- **Student ID:** e20230530
- **Date:** November 6, 2026

---

## Task 1: Process Creation on Linux (fork + exec)

### Compilation & Execution
![Task 1 - Compile & Run](screenshots/task1_compile_run.png)

### Process Tree
![Task 1 - Process Tree](screenshots/task1_process_tree.png)

### Output
```text
Parent process (PID: 1405069) — creating child...
Child process (PID: 1405070, Parent PID: 1405069)
Child: sleeping 30s — observe the process tree now!
Parent: waiting for child (PID: 1405070) to finish...
Child: now executing 'ls -la'...
total 36
drwxr-xr-x 2 gic-phy-sopanha gic-phy-sopanha 4096 Nov  4 10:24 .
drwxr-xr-x 6 gic-phy-sopanha gic-phy-sopanha 4096 Nov  4 10:33 ..
-rw-r--r-- 1 gic-phy-sopanha gic-phy-sopanha 1184 Nov  4 10:29 command_used_forkchild.txt
-rwxr-xr-x 1 gic-phy-sopanha gic-phy-sopanha 16304 Nov  4 10:23 forkchild
-rw-r--r-- 1 gic-phy-sopanha gic-phy-sopanha 1234 Nov  4 10:22 forkchild.c
-rw-r--r-- 1 gic-phy-sopanha gic-phy-sopanha  736 Nov  4 10:28 result_forkchild.txt
Parent: child exited with status 0
Parent: done.
