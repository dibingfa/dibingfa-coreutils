#include "system.h"
#include <getopt.h>

#define PROGRAM_NAME "dbf-yes"

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

static struct option long_options[] = {{"num", no_argument, 0, 'n'},
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

    int num = 0;

    if (argc <= optind) {
        optind = argc;
        argv[argc++] = "y";
    }

    while (1) {
        int i;
        for (i = optind; i < argc; i++) {
            if (show_num) {
                printf("%d ", num++);
            }
            fputs(argv[i], stdout);
            putchar(i == argc - 1 ? '\n' : ' ');
        }
        usleep(sleep_microsecond);
    }

    return EXIT_SUCCESS;
}
