#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char stringone[100],stringtwo[100];
    int stringiguais;

    puts("DIGITE A PRIMEIRA STRING: ");
    scanf("%99s",stringone);

    puts("DIGITE A SEGUNDA STRING: ");
    scanf("%99s",stringtwo);

    stringiguais = strcmp(stringone,stringtwo);

    if (stringiguais == 0) {
        puts("São iguais");
    }else {
        puts("São diferentes");
    }

    return 0;
}
