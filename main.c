/****************************************
 * C-ploration 3 for CS 271
 * 
 * Patrick Punch
 * FALL 2024
 * 
 ****************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH  200

int main(int argc, const char *argv[])
{	
	if (argc != 2){
		printf("Usage: %s [filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	const char *file_name = argv[1];
	FILE *fin = fopen(file_name, "r");
	if (fin == NULL){
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }
	// Create the output file name
	int file_size = strlen(file_name) + 6;  // +5 for .echo, +1 for null terminator

    char out_file[file_size];

	strcpy(out_file, file_name);  // Copy filename to out_file

	strcat(out_file, ".echo");	// Concatenate ".echo" to the filename

    FILE *fout = fopen(out_file, "w+");	// Open the output file
    
    if (fout == NULL) {
        perror("Unable to open output file");
        fclose(fin);
        exit(EXIT_FAILURE);
    }
	
    char line[MAX_LINE_LENGTH] = {0};
    unsigned int line_num = 0;

    // Read lines from the input file
    while (fgets(line, sizeof(line), fin)) {
        line_num++;

        printf("[%04d] %s", line_num, line);	// Print the line number and the line text
        
        fprintf(fout, "%s", line);	// Write the line to the output file
    }

    fclose(fin);
    fclose(fout);

	return 1;
}
