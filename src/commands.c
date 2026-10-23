#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "commands.h"
#include "command_handlers.h"

typedef struct Command {
    const char *name;
    bool (*action)(const char *arguments);
} Command;

static const Command CommandsTable[] = {
    {"help", cmd_help},
    {"exit", cmd_exit},
    {"version", cmd_version},
    {"echo", cmd_echo},
    {"clear", cmd_clear}
};

void printAvailableCommands(void) {
    printf("Available commands:\n");

    for (size_t i = 0;
         i < sizeof(CommandsTable) / sizeof(CommandsTable[0]);
         i++) {
        printf("%s\n", CommandsTable[i].name);
    }
}

bool validateAndRunCommands(const char *command,
                            const char *arguments) {
    for (size_t i = 0;
         i < sizeof(CommandsTable) / sizeof(CommandsTable[0]);
         i++) {
        if (strcmp(command, CommandsTable[i].name) == 0) {
            return CommandsTable[i].action(arguments);
        }
    }

    printf("Unavailable command: %s\n", command);
    return true;
}

