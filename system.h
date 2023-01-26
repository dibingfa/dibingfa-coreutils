#include <stdio.h>    /* for printf */
#include <stdlib.h>   /* for exit */
#include <limits.h>   /* for CHAR_MIN */
#include <stdbool.h>  /* for bool */
#include <unistd.h>   /* for sleep */

enum {
  GETOPT_HELP_CHAR = (CHAR_MIN - 2),
  GETOPT_VERSION_CHAR = (CHAR_MIN - 3)
};

#define case_GETOPT_HELP_CHAR \
    case GETOPT_HELP_CHAR: usage(); break;

#define case_GETOPT_VERSION_CHAR(Program_name) \
    case GETOPT_VERSION_CHAR: \
        printf("%s (dibingfa coreutils) 1.0\n", Program_name); \
        puts("Thanks GNU coreutils Written by Joseph Arceneaux, David MacKenzie, and Michael Stone."); \
        exit (EXIT_SUCCESS);

#define HELP_OPTION_DESCRIPTION \
    "      --help        display this help and exit"
#define VERSION_OPTION_DESCRIPTION \
    "      --version     output version information and exit"

#define GETOPT_HELP_OPTION_DECL \
  "help", no_argument, NULL, GETOPT_HELP_CHAR
#define GETOPT_VERSION_OPTION_DECL \
  "version", no_argument, NULL, GETOPT_VERSION_CHAR

static inline void print_try_help(char * program_name) {
    fprintf (stderr, "Try '%s --help' for more information.\n", program_name);
    exit (EXIT_FAILURE);
}

static inline void print_more_info(char * program_name) {
    printf("\ncoreutils by dibingfa program:%s\n", program_name);
    puts("github: <https://github.com/dibingfa/dibingfa-coreutils>");
    puts("wechat: dibingfa");
    exit (EXIT_FAILURE);
}
