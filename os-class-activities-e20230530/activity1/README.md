Task 1 Questions:
1. What flags did you pass to open()? What does each flag mean?

=> O_WRONLY: Opens the file for writing only.

   O_CREAT: Creates the file if it does not already exist.

   O_TRUNC: Truncates (clears) the file's contents to zero length if it already exists.

2. What is 0644 in the permission argument? What does each digit represent?
=> The 0 indicates it is an octal number.
   
   The 6 represents the Owner permissions: read (4) + write (2).

   The first 4 represents Group permissions: read-only (4).

   The second 4 represents Others/Public permissions: read-only (4).

3. What does fopen("output.txt", "w") do internally that you had to do manually with open()?

=> When you pass "w" to fopen(), the C standard library automatically combines the system-level flags to create the file if missing, open it as write-only, and truncate it. With open(), you had to explicitly specify O_WRONLY | O_CREAT | O_TRUNC and set the file permissions manually.

Task 2 Questions:
1. What struct does readdir() return? What fields does it contain?
=> It returns a dirent struct. It contains fields like d_ino (inode number), d_off (offset to the next dirent), d_reclen (length of this record), d_type (type of file), and d_name (null-terminated filename).

2. What information does stat() provide beyond file size?
=> It provides information like device ID, inode number, file mode (permissions and type), number of hard links, user ID of owner, group ID of owner, device ID (if special file), block size for filesystem I/O, number of 512B blocks allocated, and timestamps for last access, modification, and status change.

3. Why can't you just write(1, some_number, ...) directly - why do you need snprintf() first?
=> The write() system call outputs raw bytes to a file descriptor. If you pass an integer variable directly, write() will interpret those bytes as ASCII characters, printing gibberish or unprintable control characters. snprintf() is needed to convert the numerical value into a human-readable ASCII string representation before passing it to write().
