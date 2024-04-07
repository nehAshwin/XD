#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
    //constant buffer size 16
    const int buffer_size = 16;
    //file descriptor number
    int file_desc = 0;
    //buffer array (size 16)
    char buffer[buffer_size];
    bool reached_eof = false;
    int fsize;
    (void) file_desc;
    //check that file has been given
    if (argc == 1) {
        file_desc = 0;
    } else if (argc == 2) {
        file_desc = open(argv[1], O_RDONLY);
        if (file_desc == -1) {
            return 1;
        }
    } else {
        return 1;
    }

    int count_buffers = 0;

    fsize = (int) lseek(file_desc, 0, SEEK_END);
    lseek(file_desc, 0, SEEK_SET);

    int total_chars = 0;

    ssize_t bytesRead;

    while (!reached_eof) {
        bytesRead = 0;

        (void) bytesRead;

        while (bytesRead < 16 && !reached_eof) {
            bytesRead += (int) read(
                file_desc, buffer + bytesRead, (size_t) (buffer_size - (int) bytesRead));
            total_chars += bytesRead;

            if (total_chars == fsize || bytesRead == 0) {
                reached_eof = true;
            }
        }

        if (bytesRead == 0) {
            reached_eof = true;
            break;
        }

        printf("%08x: ", count_buffers);

        for (int i = 0; i < bytesRead; ++i) {
            printf("%.2x", buffer[i] & 0xff);
            if (i % 2 != 0) {
                printf(" ");
            }
        }

        if (bytesRead < 16) {
            for (int i = 16 - (int) bytesRead; i > 0; --i) {
                printf("  ");
                if (i % 2 != 0) {
                    printf(" ");
                }
            }
        }
        printf(" ");

        for (int i = 0; i < bytesRead; ++i) {
            if (buffer[i] >= 32 && buffer[i] <= 126) {
                printf("%c", buffer[i]);
            } else {
                printf(".");
            }
        }
        printf("\n");
        count_buffers += 16;
    }

    bytesRead = close(file_desc);
    return 0;
}
