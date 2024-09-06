#include <stdio.h>
#include <stdlib.h>

int main() {
    // Clear the screen
    // system("clear"); // Use "cls" on Windows

    // Set the background color to red
     printf("\033[31m"); // Set background color to red

    // Print the ASCII art
    printf("                              \\\\\\\\\\\\\n");
    printf("                            \\\\\\\\\\\\\\\\\\\\\n");
    printf("                          \\\\\\\\\\\\\\\\\\\\\\\\\\\n");
    printf("  -----------,-|           |C>   // )\\\\\\|\n");
    printf("           ,','|          /    || ,'/////|\n");
    printf("---------,','  |         (,    ||   /////\n");
    printf("         ||    |          \\\\  ||||//''''|\n");
    printf("         ||    |           |||||||     _|\n");
    printf("         ||    |______      `````\\____/ \\\n");
    printf("         ||    |     ,|         _/_____/ \\\n");
    printf("         ||  ,'    ,' |        /          |\n");
    printf("         ||,'    ,'   |       |         \\  |\n");
    printf("_________|/    ,'     |      /           | |\n");
    printf("_____________,'      ,',_____|      |    | |\n");
    printf("             |     ,','      |      |    | |\n");
    printf("             |   ,','    ____|_____/    /  |\n");
    printf("             | ,','  __/ |             /   |\n");
    printf("_____________|','   ///_/-------------/   |\n");
    printf("              |==========='                \n");

    // Reset the attributes to the default
    printf("\033[0m"); // Reset to default colors

    return 0;
}