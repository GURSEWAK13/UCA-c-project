#include <stdio.h>
#include <stdlib.h>
#include "string.h"


// ... other includes

int main() {
    // ... existing code

    char command[100];

    while (1) {
        printf(">>> ");
        scanf("%s", command);

        if (strcmp(command, "execute_blockchain") == 0) {
            system("gcc blockChain.c -o blockChain.o -lcrypto");
            system("./blockChain.o");
        }

        // ... other command handling
    }
}
