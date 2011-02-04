/*******************************
 * dime.c
 *
 * Source code for DIstributed MakE
 *
 ******************************/

#include "util.h"
#include "dime.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*********
 * Simple usage instructions
 *********/
void dime_usage(char* progname) {
	fprintf(stderr, "Usage: %s [options] [target]\n", progname);
	fprintf(stderr, "-f FILE\t\tRead FILE as a dimefile.\n");
	fprintf(stderr, "-h\t\tPrint this message and exit.\n");
	fprintf(stderr, "-n\t\tDon't actually execute commands, just print them.\n");
	exit(0);
}

/****************************** 
 * this is the function that, when given a proper filename, will
 * parse the dimefile and read in the rules
 ***************/
void parse_file(char* filename) {
	char* line = malloc(160*sizeof(char));
	FILE* fp = file_open(filename);
	while((line = file_getline(line, fp)) != NULL) {
	
	// this loop will go through the given file, one line at a time
	// this is where you need to do the work of interpreting
	// each line of the file to be able to deal with it later

	}
	fclose(fp);
	free(line);
}

int main(int argc, char* argv[]) {
	// Declarations for getopt
	extern int optind;
	extern char* optarg;
	int ch;
	char* format = "f:hn";
	
	// Variables you'll want to use
	char* filename = "Dimefile";
	bool execute = true;

	// Part 2.2.1: Use getopt code to take input appropriately.
	while((ch = getopt(argc, argv, format)) != -1) {
		switch(ch) {
			case 'f':
				filename = strdup(optarg);
				break;
			case 'n':
				execute = false;
				break;
			case 'h':
				dime_usage(argv[0]);
				break;
		}
	}
	argc -= optind;
	argv += optind;

	/* at this point, what is left in argv is the targets that were 
		specified on the command line. argc has the number of them.
		If getopt is still really confusing,
		try printing out what's in argv right here, then just running 
		dime with various command-line arguments. */

	parse_file(filename);

	/* after parsing the file, you'll want to execute all of the targets
		that were specified on the command line, along with their dependencies, etc. */
	
	return 0;
}
