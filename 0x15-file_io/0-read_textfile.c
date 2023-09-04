#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h" // Include your header file with the prototype

ssize_t read_textfile(const char *filename, size_t letters)
{
	    if (filename == NULL)
		            return 0; // Return 0 if the filename is NULL

	        int fd = open(filename, O_RDONLY); // Open the file for reading
		    if (fd == -1)
			            return 0; // Return 0 if there was an error opening the file

		        char *buffer = malloc(sizeof(char) * letters); // Allocate a buffer
			    if (buffer == NULL)
				        {
						        close(fd);
							        return 0; // Return 0 if memory allocation fails
								    }

			        ssize_t bytes_read = read(fd, buffer, letters); // Read from the file
				    if (bytes_read == -1)
					        {
							        free(buffer);
								        close(fd);
									        return 0; // Return 0 if there was an error reading from the file
										    }

				        ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_read); // Write to standard output
					    free(buffer);
					        close(fd);

						    if (bytes_written == -1 || bytes_written != bytes_read)
							            return 0; // Return 0 if there was an error writing or not all bytes were written

						        return bytes_written; // Return the actual number of letters read and printed
}

