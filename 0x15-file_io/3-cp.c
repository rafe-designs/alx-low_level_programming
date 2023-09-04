#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void error_exit(int code, const char *message) {
	    dprintf(STDERR_FILENO, "%s\n", message);
	        exit(code);
}

int main(int argc, char *argv[]) {
	    if (argc != 3)
		            error_exit(97, "Usage: cp file_from file_to");

	        const char *file_from = argv[1];
		    const char *file_to = argv[2];

		        int fd_src = open(file_from, O_RDONLY);
			    if (fd_src == -1)
				            error_exit(98, "Error: Can't read from file");

			        int fd_dest = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
				    if (fd_dest == -1)
					            error_exit(99, "Error: Can't write to file");

				        ssize_t bytes_read;
					    char buffer[1024];

					        while ((bytes_read = read(fd_src, buffer, sizeof(buffer))) > 0) {
							        ssize_t bytes_written = write(fd_dest, buffer, bytes_read);
								        if (bytes_written == -1)
										            error_exit(99, "Error: Can't write to file");
									    }

						    if (bytes_read == -1)
							            error_exit(98, "Error: Can't read from file");

						        if (close(fd_src) == -1)
								        error_exit(100, "Error: Can't close source file descriptor");

							    if (close(fd_dest) == -1)
								            error_exit(100, "Error: Can't close destination file descriptor");

							        return 0;
}

