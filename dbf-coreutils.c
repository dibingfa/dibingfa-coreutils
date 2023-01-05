#include <stdio.h>     /* for printf */
#include <stdlib.h>    /* for exit */
#include <getopt.h>

#define PROGRAM_NAME "dbf-coreutils"

void usage () {
    printf ("Usage: %s [OPTION]\n", PROGRAM_NAME);
    printf ("Try '%s -h' or '%s --help' for more information\n", PROGRAM_NAME, PROGRAM_NAME);
}

int main(int argc, char **argv) {
    int c;
    int digit_optind = 0;

    while (1) {
        int this_option_optind = optind ? optind : 1;
        int option_index = 0;
        static struct option long_options[] = {
            {"help",    no_argument,        0,  'h' },
            {"version", no_argument,        0,  'v' },
            {"print",   required_argument,  0,  'p' },
            {0,0,0,0}
        };

        c = getopt_long(argc, argv, "hvp:", long_options, &option_index);
        if (c == -1) {
            break;
        }

        switch (c) {
            case 'h': 
                printf("this is a test command by dibingfa\n");
                break;
            case 'v':
                printf("program_name=%s version=1.0.0\n", PROGRAM_NAME);
                break;
            case 'p':
                printf("just print arg: %s\n", optarg);
                break;
            default:
                usage();
        }
    }

   exit(EXIT_SUCCESS);
}