/* dir_list_sys.c */
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h> // only for snprintf to format numbers into strings

int main() {
    char buffer[512];

    // 1. Open current directory with opendir(".")
    DIR *dir = opendir(".");
    if (dir == NULL) {
        return 1;
    }

    // 2. Print header line using write()
    const char *header = "Filename                       Size (bytes)\n";
    const char *divider = "------------------------------ ----------\n";
    write(1, header, strlen(header));
    write(1, divider, strlen(divider));

    struct dirent *entry;
    struct stat fileStat;

    // 3. Loop through entries with readdir()
    while ((entry = readdir(dir)) != NULL) {
        // 4. For each entry, use stat() to get file size
        if (stat(entry->d_name, &fileStat) == 0) {
            // 5. Format output into buffer with snprintf(), then write() to fd 1
            int len = snprintf(buffer, sizeof(buffer), "%-30s %10ld\n", entry->d_name, fileStat.st_size);
            write(1, buffer, len);
        }
    }

    // 6. Close directory with closedir()
    closedir(dir);
    return 0;
}
