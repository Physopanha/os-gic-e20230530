#include <fcntl.h>
#include <unistd.h>

int main() {
    char buffer[256];
    int fd;
    ssize_t bytesRead;

    // 1. Open "output.txt" for reading using open()
    fd = open("output.txt", O_RDONLY);
    
    // Check if the file opened successfully
    if (fd < 0) {
        write(2, "Error opening file\n", 19);
        return 1; 
    }

    // 2 & 3. Read content into buffer using read() in a loop, write to terminal
    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        write(1, buffer, bytesRead);
    }

    // 4. Close the file using close()
    close(fd);

    return 0;
}
