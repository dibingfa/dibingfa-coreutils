#include "system.h"
#include <getopt.h>

#define PROGRAM_NAME "dbf-echo"

void usage() {
    printf("Usage: %s [SHORT-OPTION]... [STRING]...\n", PROGRAM_NAME);
    puts("Echo the STRING(s) to standard output.");
    puts("");
    puts("  -r, --red          print red STRING(s)");
    puts("  -g, --greed        print greed STRING(s)");
    puts("  -y, --yellow       print yellow STRING(s)");
    puts("  -b, --blue         print blue STRING(s)");
    puts("  -w, --white        print white STRING(s)");
    puts("  -a, --all          print all colors STRING(s)");
    puts(HELP_OPTION_DESCRIPTION);
    puts(VERSION_OPTION_DESCRIPTION);
    print_more_info(PROGRAM_NAME);
    exit(EXIT_SUCCESS);
}

static struct option long_options[] = {{"red", no_argument, 0, 'r'},
                                       {"greed", no_argument, 0, 'g'},
                                       {"yellow", no_argument, 0, 'y'},
                                       {"blue", no_argument, 0, 'b'},
                                       {"white", no_argument, 0, 'w'},
                                       {"all", no_argument, 0, 'a'},
                                       {GETOPT_HELP_OPTION_DECL},
                                       {GETOPT_VERSION_OPTION_DECL},
                                       {0, 0, 0, 0}};

// Colors and formatting
// https://misc.flogisoft.com/bash/tip_colors_and_formatting
int main(int argc, char **argv) {
    int optc;
    char *str_template = "%s";
    bool print_all = false;

    while ((optc = getopt_long(argc, argv, "rgybwa", long_options, NULL)) != -1) {
        int a = optind;
        switch (optc) {
            case 'r': str_template = "\033[1;31m%s\033[0m"; break;
            case 'g': str_template = "\033[1;32m%s\033[0m"; break;
            case 'y': str_template = "\033[1;33m%s\033[0m"; break;
            case 'b': str_template = "\033[1;34m%s\033[0m"; break;
            case 'w': str_template = "\033[1;35m%s\033[0m"; break;
            case 'a': print_all = true; break;
            case_GETOPT_HELP_CHAR;
            case_GETOPT_VERSION_CHAR(PROGRAM_NAME);
            default: print_try_help(PROGRAM_NAME);
        }
    }

    int i, j;

    if (print_all) {
        for (i = 0; i < 10; i++) {
            for (j = optind; j < argc; j++) {
                printf("3%d \033[1;3%dm%s\033[0m", i, i, argv[j]);
                if (argc > i)
                    putchar(' ');
            }
            putchar('\n');
        }
        return EXIT_SUCCESS;
    }
    

    for (i = optind; i < argc; i++) {
        printf(str_template, argv[i]);
        if (argc > i)
            putchar(' ');
    }
    putchar('\n');

    return EXIT_SUCCESS;
}
