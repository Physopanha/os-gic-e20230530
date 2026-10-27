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

