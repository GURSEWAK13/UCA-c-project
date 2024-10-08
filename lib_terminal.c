#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
void read() {
    char a[100];
    printf("Use .txt or any other extension to read\nEx: hello.txt\n\n");

    printf("\033[1;34m");

    FILE *p;

    printf("Enter File Name To Read: ");
    scanf("%s", a);

    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");

    char c;

    p = fopen(a, "r");

    if (p == NULL) {
        printf("\nError: File '%s' not found.\n", a);
        return;
    }

    printf("\n");

    while ((c = fgetc(p)) != EOF) {
        printf("%c", c);
    }

    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");

    fclose(p);

    printf("\n\n Successfully Read\n");
}
void write(){

    char a[100];

    printf("Use .txt or any other extension to write\nEx: hello.txt\n\n");

    printf("\033[31m");

        FILE *p;

        printf("Enter File Name To Write: ");
        scanf("%s", a);

        p = fopen(a, "w");

        fflush(stdin);

        printf("Enter ~ to exit from writing\n");
        printf("Start writing: \n");

        int ch=0;

        while(ch != '~'){
            ch = getchar();

            if(ch != '~'){

            fputc(ch, p);

        }

    }



        fclose(p);

        printf("\n\nSuccessfully Written\n");
}

void append(){

    char a[100];

    printf("Use .txt or any other extension to append\nEx: hello.txt\n\n");

printf("\033[31m");

        FILE *p;

        printf("Enter File Name To Append: ");
        scanf("%s", a);

        if(p == NULL){
        printf("Error");
        }

        p = fopen(a, "a");

        printf("Enter ~ to exit from writing\n");
        printf("Start writing: \n");

        int ch=0;

        while(ch != '~'){
            ch = getchar();

            if(ch != '~'){

            fputc(ch, p);

        }

    }


        fclose(p);

        printf("\n\nSuccessfully Appended\n");

}

void clear(){
    system("cls");
    printf("\033[0m"); 
}

void dt(){
    time_t tt = time(NULL);
    printf("%s", ctime(&tt));
}

void startscreen(){
    system("clear");
    printf("Demon Terminal\n\n");

    dt();
    printf("Welcome To DEMON Terminal\n");
    printf("Type \"help\" for more things!\n\n");
}

void removes(){
    char a[100];
    int m;

    printf("Enter a file name to remove: ");
    scanf("%s", a);

    m = remove(a);

    if(m == 0){
        printf("Successfully removed a file\n");
    }else{
        printf("Error in removing please check if the file exists in directory\n");
    }

}

void renames(){

    char a[100], b[100];
    int m;

    printf("Enter a file name to rename: ");
    scanf("%s", a);

    printf("\nEnter new name: ");
    scanf("%s", b);

    m = rename(a, b);

    if(m == 0){
        printf("Successfully renamed a file\n");
    }else{
        printf("Error in removing please check if the file exists in directory\n");
    }

}

#include <stdio.h>
#include <stdlib.h>

void edit() {
    char a[100];
    printf("Warning: Close the editor to use DEMON Terminal\n");
    printf("Use .txt or any other extension to edit\nEx: hello.txt\n\n");
    printf("Enter file name to edit: ");
    scanf("%99s", a); // Limit input to avoid buffer overflow

    // Construct the command to open the editor with the specified file
    char command[150]; // Buffer for the command
    snprintf(command, sizeof(command), "nano %s", a); // Using nano as the editor

    // Execute the command
    int result = system(command);

    if (result == -1) {
        printf("Error: Unable to open the editor.\n");
    } else {
        printf("Successfully opened editing software\n");
    }
}

void cdir(){
    char a[100];

    printf("Your Directory:\n");
    system("dir");
}

void copy(){

    char a[100], b[100];
    int c;
    FILE *p, *q;

    printf("Use .txt or any other extension to copy\nEx: hello.txt\n\n");
    printf("Enter existing file name: ");
    scanf("%s", a);
    printf("\nEnter copy destination file name: ");
    scanf("%s", b);

    if(p == NULL){
        printf("The file is not found\n");
    }else{

    p = fopen(a, "r");
    q = fopen(b, "a");

    c = fgetc(p);
    while(c != EOF){
        fputc(c, q);
        c = fgetc(p);
    }

    fclose(p);
    fclose(q);

    printf("\nSuccessfully copied\n");
    }

}

void cknow(){

    char a[100], cha;
    int c, count=0;
    FILE *p;

    printf("Use .txt or any other extension to cknow\nEx: hello.txt\n\n");
    printf("Enter existing file name: ");
    scanf("%s", a);

    fflush(stdin);
    printf("\nEnter the character to search: ");
    scanf("%c", &cha);

    p = fopen(a, "r");

    if(p == NULL){
        printf("The file is not found\n");
    }else{

    c = fgetc(p);
    while(c != EOF){
        if(c == cha){
            count++;
        }
        c = fgetc(p);
    }

    fclose(p);

    printf("No. of times %c repeated is = %d\n",  cha, count);
    }
}

void lknow(){

    char a[100], cha;
    int c, count=0;
    FILE *p;

    printf("Use .txt or any other extension to cknow\nEx: hello.txt\n\n");
    printf("Enter existing file name: ");
    scanf("%s", a);

    p = fopen(a, "r");

    if(p == NULL){
        printf("The file is not found\n");
    }else{

    c = fgetc(p);
    while(c != EOF){
        if(c == '\n'){
            count++;
        }
        c = fgetc(p);
    }

    fclose(p);

    printf("No. of lines = %d\n", count);
    }

}

void ccount(){

    char a[100], cha;
    int c, count=0;
    FILE *p;

    printf("Use .txt or any other extension to ccount\nEx: hello.txt\n\n");
    printf("Enter existing file name: ");
    scanf("%s", a);

    p = fopen(a, "r");

    if(p == NULL){
        printf("The file is not found\n");
    }else{

    c = fgetc(p);
    while(c != EOF){
        if(c != ' ' && c != '\n'){
            count++;
        }
        c = fgetc(p);
    }

    fclose(p);

    printf("No. of characters in file is = %d\n", count);
    }
}

void gcd(){
    int i, gcd, a, b;

    printf("Enter two numbers (by pressing enter):\n");
    scanf("%d %d", &a, &b);

    for(i=1; i<=a && i<=b; i++){
        if(a%i==0 && b%i == 0){
            gcd = i;
        }
    }

    printf("GCD = %d\n", gcd);
}

void lcm(){
    int i, gcd, lcm, a, b;

    printf("Enter two numbers (by pressing enter):\n");
    scanf("%d %d", &a, &b);

    for(i=1; i<=a && i<=b; i++){
        if(a%i==0 && b%i==0){
            gcd = i;
        }
    }

    lcm = (a*b)/gcd;

    printf("LCM = %d\n", lcm);
}

void tconv(){

    int temp, cases;
    float op;

    printf("Temperature Conversion Program\n");

    printf("\nPress 1 =  Celsius    -  Kelvin\n");
    printf("Press 2 =  Celsius    -  Fahrenheit\n");
    printf("Press 3 =  Kelvin     -  Fahrenheit\n");
    printf("Press 4 =  Kelvin     -  Celsius\n");
    printf("Press 5 =  Fahrenheit -  Celsius\n");
    printf("Press 6 =  Fahrenheit -  Kelvin\n");

    printf("\nType: ");
    scanf(" %d", &cases);

    printf("\nType temperature: ");
    scanf(" %d", &temp);

    printf("\nConversion: \n");

    switch(cases){
    case 1:
        op = temp + 273.15;
        printf("C - K = %f\n", op);
        break;

    case 2:
        op = (temp * 9/5) + 32;
        printf("C - F = %f\n", op);
        break;

    case 3:
        op = (temp - 273.15) * 9/5 + 32;
        printf("K - F = %f\n", op);
        break;

    case 4:
        op = temp - 273.15;
        printf("K - C = %g\n", op);
        break;

    case 5:
        op = (temp - 32) * 5/9;
        printf("F - C = %f\n", op);
        break;

    case 6:
        op = (temp - 32) * 5/9 + 273.15;
        printf("F - K = %f\n", op);
        break;

    default:
        printf("Type Only The Numbers Shown On The Screen\n");

    }
}


void help(){
    printf("\n");
    printf("You can enter the following commands:\n\n");
    printf("write  >>> To write to a file\n");
    printf("read   >>> To read from a file\n");
    printf("append >>> To append a file\n");
    printf("remove >>> To remove a file\n");
    printf("rename >>> To rename a file\n");
    printf("clr    >>> To clear the screen\n");
    printf("dt     >>> To show date and time\n");
    printf("stscr  >>> To show start screen\n");
    printf("edit   >>> To edit a file\n");
    printf("cdir   >>> To see the directory(location) and files\n");
    printf("copy   >>> To copy one file to new file or append to a existing file\n");
    printf("cknow  >>> To know how many time(s) a character repeated in file\n");
    printf("lknow  >>> To know how line(s) are there in a file\n");
    printf("gcd    >>> To perform GCD of numbers\n");
    printf("lcm    >>> To perform LCM of numbers\n");
    printf("tconv  >>> To convert temperatures\n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("LetsRock >>>> For Running BlockChain\n");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("exit   >>> To exit\n");
    printf("\n");
}

void exits(){
    exit(1);
}
