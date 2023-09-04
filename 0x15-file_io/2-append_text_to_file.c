#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h" // Include your header file with the prototype

int append_text_to_file(const char *filename, char *text_content)
{
	    if (filename == NULL)
		            return -1; // Return -1 if the filename is NULL

	        int fd = open(filename, O_WRONLY | O_APPEND); // Open the file for appending
		    if (fd == -1)
			            return -1; // Return -1 if there was an error opening the file

		        if (text_content != NULL)
				    {
					            ssize_t bytes_written = write(fd, text_content, strlen(text_content)); // Append text content to the file
						            if (bytes_written == -1)
								            {
										                close(fd);
												            return -1; // Return -1 if there was an error writing to the file
													            }
							        }

			    close(fd);
			        return 1; // Return 1 on success
}

