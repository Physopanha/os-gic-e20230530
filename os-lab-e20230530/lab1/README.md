    # OS Lab 1 - individual report

    Name or Student ID: Phy sopanha, ID: e20230530
    Workshop and environment: Course sever (`i4gic-os`, Ubuntu 26.04.01 LTS, Kernel `7.0.0-38-generic`) and local Windows 11 with Ubuntu WSL (`admin1@DESKTOP-LR7RTM4`).

    ## Original prediction (written before running)

    Expected outcome and reason:
    From `Lab1-predect.json`:
    * File (`file`): `y` - Creating, copying, and renaming `candle.txt` and `silver.txt` in `task2_files` leaves the expected files without the temporary copy.
    * Remove (`remove`): `y` - I originally predicted that `apt-get remove mc` would still leave the configuration directory `/etc/mc` present (or wondered whether `remove` vs. `purge` deletes `/etc/mc).
    * Sleeps (`sleeps`): `4` - Running 4 background `sleep` commands simultaneously results in 4 concurrent `sleep` processes because the OS kernel schedules and tracks each running instance in RAM.
    * Why (`why`): "program store in disk, process store in memory."

    ## Investigation artifact

    Decisive command lines:
    ```bash
    uname -a > take1_os_info.txt && lsb_release -a >> task1_os_info.txt
    mkdir -p task2_files && cp candle.txt task2.files/ && mv silver.txt task2_files/silver_renamed.txt
    sudo apt-get update && sudo apt-get install mc -y
    which mc > task3_apt.txt && ls -ld /etc/mc >> task3_apt.txt
    sudo apt-get remove mc -y && ls -ld /etc/mc >> task3_apt.txt
    sudo apt-get purge mc -y && ls -ld /etc/mc >> task3_apt.txt 2>&1
    sleep 30 & sleep 30 & sleep 30 & sleep 30 &
    ps aux | grep sleep > task5_multitasking.txt
    systemd-detect-virt > task6_virtualization_check.txt