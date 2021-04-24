#include<stdio.h>
#include<stdlib.h>


void main(){

    FILE *fp;
    char c;

    fp = fopen("Hello_Ufabc.txt", "r");


    if( fp == NULL){
        printf("Erro na abertura do arquivo.\n");
    } 

    while((c = fgetc(fp)) != EOF){
        printf("%c", c);
    }

    fclose(fp);









}