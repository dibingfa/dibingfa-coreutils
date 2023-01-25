#include "system.h"
#include <getopt.h>
#include <fcntl.h>

#define PROGRAM_NAME "dbf-cat"

void usage() {
    printf("Usage: %s [SHORT-OPTION]... [STRING]...\n", PROGRAM_NAME);
    puts("Repeatedly output a line with all specified STRING(s), or 'y'.");
    puts("");
    puts("  -n, --num          show line number");
    puts("  -s, --sleep=NUM    sleep NUM microsecond between");
    puts(HELP_OPTION_DESCRIPTION);
    puts(VERSION_OPTION_DESCRIPTION);
    print_more_info(PROGRAM_NAME);
    exit(EXIT_SUCCESS);
}

static struct option long_options[] = {{"number", no_argument, 0, 'n'},
                                       {"sleep", required_argument, 0, 's'},
                                       {GETOPT_HELP_OPTION_DECL},
                                       {GETOPT_VERSION_OPTION_DECL},
                                       {0, 0, 0, 0}};

int main(int argc, char **argv) {
    int optc;
    int show_num = false;
    int sleep_microsecond = 0;

    while ((optc = getopt_long(argc, argv, "ns:", long_options, NULL)) != -1) {
        int a = optind;
        switch (optc) {
            case 'n': show_num = true; break;
            case 's':
                sleep_microsecond = atoi(optarg);
                break;
            case_GETOPT_HELP_CHAR;
            case_GETOPT_VERSION_CHAR(PROGRAM_NAME);
            default: print_try_help(PROGRAM_NAME);
        }
    }

    int argind = optind;
    int insize = 1024;

    while(argind < argc) {
        char *infile = argv[argind++];
        int infd = open(infile, O_RDONLY);
        void *inbuf = malloc(insize);
        while(true) {
           size_t n_read = read(infd, inbuf, insize);
            if(n_read == 0) {
                break;
            }
            usleep(sleep_microsecond);
            write(STDOUT_FILENO, inbuf, n_read);
        }
    }

    return EXIT_SUCCESS;
}