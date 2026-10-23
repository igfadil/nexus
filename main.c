#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "commands.h"

int main(void) {
  printf("Welcome to NEXUS\n");

  bool running = true;
  char userInput[100];

  while (running) {
    printf("nexus> ");
    fflush(stdout);

    if (fgets(userInput, sizeof(userInput), stdin) == NULL) {
      break;
    }

    if(strchr(userInput, '\n') == NULL) {
      int leftOver = getchar();

      if(leftOver != '\n') {

        if(leftOver == EOF) {
          running = false;
          continue;
        }

        else {

          while(true) {
            leftOver = getchar();

            if(leftOver == '\n' || leftOver == EOF) { 
              printf("Finish draining output\n");
              break; 
            }

          }
          printf("Command is too long, max limit of 99 characters.\n");
          continue;
        }
      }
    }
    userInput[strcspn(userInput, "\n")] = '\0';

    char *command = userInput;
    char *space = strchr(userInput, ' ');
    const char *arguments = "";

    if (space != NULL) {
      *space = '\0';
      arguments = space + 1;
    }

    running = validateAndRunCommands(command, arguments);
  }

  return 0;
}
