#include <stdio.h>     /* for printf */
#include <stdlib.h>    /* for exit */
#include <getopt.h>

#define PROGRAM_NAME "dbf-yes"

void usage () {
    printf ("Usage: %s [OPTION]\n", PROGRAM_NAME);
    printf ("Try '%s -h' or '%s --help' for more information\n", PROGRAM_NAME, PROGRAM_NAME);
}

int main(int argc, char **argv) {
    int c;
    int digit_optind = 0;
    int show_num = 0;
    int sleep_second = 0;
    int print_char = 1;

    while (1) {
        int this_option_optind = optind ? optind : 1;
        int option_index = 0;
        static struct option long_options[] = {
            {"help",    no_argument,        0,  'h' },
            {"version", no_argument,        0,  'v' },
            {"num",     no_argument,        0,  'n' },
            {"sleep",   required_argument,  0,  's' },
            {0,0,0,0}
        };

        c = getopt_long(argc, argv, "+hvns:", long_options, &option_index);

        if(c == -1) {
            break;
        }

        switch (c) {
            case 'h': 
                printf("this is a test command by dibingfa\n");
                print_char = 0;
                break;
            case 'v':
                printf("program_name=%s version=1.0.0\n", PROGRAM_NAME);
                print_char = 0;
                break;
            case 'n': 
                show_num = 1;
                break;
            case 's': 
                sleep_second = atoi(optarg);
                break;
            default:
                break;
        }
    }

    if (!print_char) {
        exit(EXIT_SUCCESS);
    }

    int num = 0;

    if (optind <= argc) {
        while (1) {
            if (show_num) {
                printf("%d ", num++);
            }
            puts("y");
            sleep (sleep_second);
        }
    }
    
    while (1) {
        int i;
        for (i = optind; i < argc; i++) {
            if (show_num) {
                printf("%d ", num++);
            }
            fputs (argv[i], stdout);
            putchar (i == argc - 1 ? '\n' : ' ');
        }
        sleep (sleep_second);
    }

    exit(EXIT_SUCCESS);
}