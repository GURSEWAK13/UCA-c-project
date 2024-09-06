#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include "./header/terminal.h"

int main(){

    char a[100];

    printf("Lets Try Something Different\n\n");

    dt();
    printf("Welcome To My Hood\n");
    printf("Its my own custom Implementation of Terminal\n");
    printf("If you want to run blockchain localy type this command ----> LetsRock\n");
    printf("Type \"help\" for more things!\n\n");

    while(1){

    printf(">>> ");
    fflush(stdin);
    scanf("%s", a);

    if(strcmp(a, "read") == 0){

        read();

    }else if(strcmp(a, "write") == 0){

        write();

    }else if(strcmp(a, "append") == 0){

        append();

    }else if(strcmp(a, "clr") == 0){

        clear();

    }else if(strcmp(a, "help") == 0){

        help();

    }else if(strcmp(a, "dt") == 0){

        dt();

    }else if(strcmp(a, "stscr") == 0){

        startscreen();

    }else if(strcmp(a, "remove") == 0){

        removes();

    }else if(strcmp(a, "rename") == 0){

        renames();

    }else if(strcmp(a, "edit") == 0){

        edit();

    }else if(strcmp(a, "cdir") == 0){

        cdir();

    }else if(strcmp(a, "copy") == 0){

        copy();

    }else if(strcmp(a, "cknow") == 0){

        cknow();

    }else if(strcmp(a, "lknow") == 0){

        lknow();

    }else if(strcmp(a, "ccount") == 0){

        ccount();

    }else if(strcmp(a, "gcd") == 0){

        gcd();

    }else if(strcmp(a, "lcm") == 0){

        lcm();

    }else if(strcmp(a, "tconv") == 0){

        tconv();

    }else if(strcmp(a, "exit") == 0){

        exits();

    }else if (strcmp(a, "LetsRock") == 0) {
            system("gcc ./Blocky/blockChain.c -o ./output/blockChain.o -lcrypto");
            system("./output/blockChain.o");
    }else{
        printf("Oooh i think you typed somthing wrong\n");
    }
    

    }

    return 0;

}

