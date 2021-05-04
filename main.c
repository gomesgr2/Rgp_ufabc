#include<stdio.h>
#include<stdlib.h>
#define MAX_TAMANHO_NOME 150

void main(){

    FILE *fp;
    FILE *usersWrite;
    FILE *usersRead;
    char nome[MAX_TAMANHO_NOME];
    char aux[MAX_TAMANHO_NOME];
    char c;

    fp = fopen("Hello_Ufabc.txt", "r");

    usersWrite = fopen("Users.txt", "w");
    usersRead = fopen("Users.txt", "r");

    printf("Entre com o seu nome :");
    scanf("%s", nome);


    
    fputc(usersWrite, nome[0]);

    fclose(fp);









}