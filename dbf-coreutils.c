#include "system.h"
#include <getopt.h>

#define PROGRAM_NAME "dbf-coreutils"

void usage () {
    printf("Usage: %s\n", PROGRAM_NAME);
    puts("Template program only help or version.");
    puts("");
    
    puts(HELP_OPTION_DESCRIPTION);
    puts(VERSION_OPTION_DESCRIPTION);
    print_more_info(PROGRAM_NAME);
}

static struct option long_options[] = {{GETOPT_HELP_OPTION_DECL},
                                       {GETOPT_VERSION_OPTION_DECL},
                                       {0, 0, 0, 0}};

int main(int argc, char **argv) {
    int optc;

    while ((optc = getopt_long(argc, argv, "", long_options, NULL)) != -1) {
        int a = optind;
        switch (optc) {
            case_GETOPT_HELP_CHAR;
            case_GETOPT_VERSION_CHAR(PROGRAM_NAME);
            default: print_try_help(PROGRAM_NAME);
        }
    }

   exit(EXIT_SUCCESS);
}
