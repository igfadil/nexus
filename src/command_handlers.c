#include <stdio.h>

#include "command_handlers.h"
#include "commands.h"

#define VERSION 1.0

bool cmd_help(const char *arguments) {
    (void)arguments;
    printAvailableCommands();
    return true;
}

bool cmd_exit(const char *arguments) {
    (void)arguments;
    printf("Goodbye!\n");
    return false;
}

bool cmd_version(const char *arguments) {
    (void)arguments;
    printf("%.1f\n", VERSION);
    return true;
}

bool cmd_echo(const char *arguments) {
    printf("%s\n", arguments);
    return true;
}

bool cmd_clear(const char *arguments) {
    (void)arguments;

    printf("\033[3J\033[2J\033[H");
    fflush(stdout);

    return true;
}

