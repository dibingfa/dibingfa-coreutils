#include "system.h"
#include <fcntl.h>
#include <getopt.h>

#define PROGRAM_NAME "dbf-cat"

#define LINE_COUNTER_BUF_LEN 20
static char line_buf[LINE_COUNTER_BUF_LEN] = {
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  ' ',
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', '0', '\t', '\0'};

/* Position in `line_buf' where printing starts.  This will not change
   unless the number of lines is larger than 999999.  */
static char *line_num_print = line_buf + LINE_COUNTER_BUF_LEN - 8;

/* Position of the first digit in `line_buf'.  */
static char *line_num_start = line_buf + LINE_COUNTER_BUF_LEN - 3;

/* Position of the last digit in `line_buf'.  */
static char *line_num_end = line_buf + LINE_COUNTER_BUF_LEN - 3;

static void next_line_num(void) {
    char *endp = line_num_end;
    do {
        if ((*endp)++ < '9')
            return;
        *endp-- = '0';
    } while (endp >= line_num_start);
    if (line_num_start > line_buf)
        *--line_num_start = '1';
    else
        *line_buf = '>';
    if (line_num_start < line_num_print)
        line_num_print--;
}

static int insize = 1024;
static int outsize = 1024;

static struct option long_options[] = {
    {"number", no_argument, 0, 'n'},
    {"remove-blanks", required_argument, 0, 'r'},
    {GETOPT_HELP_OPTION_DECL},
    {GETOPT_VERSION_OPTION_DECL},
    {0, 0, 0, 0}};

void usage() {
    printf("Usage: %s [SHORT-OPTION]... [STRING]...\n", PROGRAM_NAME);
    puts("Repeatedly output a line with all specified STRING(s), or 'y'.");
    puts("");
    puts("  -n, --number         show line number");
    puts("  -r, --remove-blanks  remove all blank lines and chars");
    puts(HELP_OPTION_DESCRIPTION);
    puts(VERSION_OPTION_DESCRIPTION);
    print_more_info(PROGRAM_NAME);
    exit(EXIT_SUCCESS);
}

static void simple_cat(int infd, char *inbuf) {
    while (true) {
        size_t n_read = read(infd, inbuf, insize);
        if (n_read == 0) {
            break;
        }
        write(STDOUT_FILENO, inbuf, n_read);
    }
}

static void cat(int infd, char *inbuf, char *outbuf, bool numbers,
                bool remove_blanks) {

    char *bpin;
    char *bpout = outbuf;
    size_t n_write = 0;
    unsigned char ch;
    int line_number = 0;
    char line_number_str[4] = {' ', ' ', ' ', ' '};

    while (true) {
        // read insize
        size_t n_read = read(infd, inbuf, insize);
        if (n_read == 0) {
            break;
        }
        bpin = inbuf;
        while (true) {

            // write buf full
            if (n_write == outsize) {
                write(STDOUT_FILENO, outbuf, n_write);
                bpout = outbuf;
                n_write = 0;
            }
            
            // read finish
            if (n_read == 0) {
                break;
            }

            // char by char read
            ch = *bpin++;
            n_read--;

            // char by char handle
            if(remove_blanks && (ch == ' ' || ch == '\n')) {
                continue;
            }
            if (numbers && ch == '\n') {
                *bpout++ = ch;
                next_line_num();
                bpout = stpcpy(bpout, line_num_print);
                continue;
            }

            // char by char write to outbuf
            *bpout++ = ch;
            n_write++;
            
        }

    }

    if (n_write != 0) {
        write(STDOUT_FILENO, outbuf, n_write);
        puts("");
    }
    
}

int main(int argc, char **argv) {
    int optc;
    bool numbers = false;
    bool remove_blanks = false;

    while ((optc = getopt_long(argc, argv, "nr", long_options, NULL)) != -1) {
        int a = optind;
        switch (optc) {
            case 'n': numbers = true; break;
            case 'r':
                remove_blanks = true;
                break;
                case_GETOPT_HELP_CHAR;
                case_GETOPT_VERSION_CHAR(PROGRAM_NAME);
            default: print_try_help(PROGRAM_NAME);
        }
    }

    int argind = optind;

    while (argind < argc) {
        char *infile = argv[argind++];
        int infd = open(infile, O_RDONLY);
        if (numbers || remove_blanks) {
            char *inbuf = malloc(insize);
            char *outbuf = malloc(outsize);
            cat(infd, inbuf, outbuf, numbers, remove_blanks);
        } else {
            char *inbuf = malloc(insize);
            simple_cat(infd, inbuf);
        }
    }

    return EXIT_SUCCESS;
}
