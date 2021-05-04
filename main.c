    //FILE *fp;
    //char c;

    //fp = fopen("Hello_Ufabc.txt", "r");


    //if( fp == NULL){
        //printf("Erro na abertura do arquivo.\n");
    //} 

    //while((c = fgetc(fp)) != EOF){
        //printf("%c", c);
   // }

    //fclose(fp);

    
//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Seção de variáveis
#define MAX_TAMANHO_DA_PALAVRA 100
#define NUMERO_ITENS 5
#define OPCOES_DIA 3
#define OPCOES_MENU 4
int sair = 0;

struct protag
{
    char nome[MAX_TAMANHO_DA_PALAVRA];
    int energia;
    int estudo;
    //int item;
    int social;
    int dinheiro;
    int saude;
};

struct protag protagonista;


//Seção menus
void criarlinha(int n) {
    for (int i = 0; i < n; i++) {
        printf("-");
    }
    printf("\n");
}

void imprimeListaDePalavras(char arr[][MAX_TAMANHO_DA_PALAVRA], int tam){
    
    criarlinha(34);

    for(int i =0; i < tam; i++  ){
        printf("|(%d) %s \n",i, arr[i]);
        criarlinha(34);
    }

}


//Criar personagem
void Protagonista(){
    fflush(stdin);

    printf("Qual o nome do aluno?\n");
        fgets(protagonista.nome, MAX_TAMANHO_DA_PALAVRA, stdin);
    
    protagonista.energia = 10;
    protagonista.dinheiro = 20;
    protagonista.estudo = 0;
    protagonista.saude = 10;
    protagonista.social = 0;
}

//Lê os créditos
void LerCreditos(){

    printf("\n\n        CREDITOS           \nProjeto RPGemC\nDesenvolvedores:\n Gabriel Gomes De Oliveira Costa (RA: 11201921471)\n Isabela Leopoldino Conti (RA:11201811574)\n Lidia Victoria Alves de Araujo (RA:11201920456)\n Nathalia Caroline de Oliveira Pinto(RA:21088416)\nDisciplina Programacao Estruturada || Professor:  Wagner Tanaka Botelho\n\n\n");

}

//Introdução
void LerInicio(){

    printf("Texto do inicio\n");

}

//Compra de itens nos dias comuns
void ItemDias(){

}

//Sistema de Salvar (0 )
void Carregar(){

}

void Salvar(){

}

//Ações nos dias comuns
void AcoesDias(){

}

//Sistema de provas
void Prova(){

}

void Final(){

}

//Exibe a tela de início
void tela(){
    fflush(stdin);
    int esc = 0;

    char menu[OPCOES_MENU][MAX_TAMANHO_DA_PALAVRA] = {"Novo jogo", "Carregar jogo", "Creditos", "Sair"};
    imprimeListaDePalavras(menu, OPCOES_MENU);

    scanf(" %d", &esc);

    if (esc == 0) {
        Protagonista();
    } else if (esc == 1) {
        Carregar();
    } else if (esc == 2) {
        LerCreditos();
        tela();
    } else if (esc == 3){
        sair = 1;
    } else {
        printf("Houve um erro, por favor digite novamente\n");
        tela();
    }
}

void dias(){
    int esc;
    fflush(stdin);

    char diaacoes[OPCOES_DIA][MAX_TAMANHO_DA_PALAVRA] = {"Fazer alguma coisa!", "Ir no mercadinho", "Ir dormir (encerrar o dia)"};
    
    printf("Mais um dia comeca! O que %s vai fazer hoje?\n", protagonista.nome);
    while (1 == 1) {    

        printf("%s tem %d/10 de energia restando\n", protagonista.nome, protagonista.energia);
        imprimeListaDePalavras(diaacoes, OPCOES_DIA);
        scanf(" %d", &esc);

        if (esc == 0) {
            AcoesDias();
        } else if (esc == 1) {
            ItemDias();
        } else if (esc == 2) {
            break;
        } else {
            printf("Houve algum erro, por favor digite novamente");
        }
    }

}


void main(){
    char s;
    LerInicio();

    while(sair == 0) {
        tela();

        for (int dia = 1; dia <= 7; dia++){
            if (sair==1) {
                break;
            }
            
            printf("Voce esta no dia %d/7\n", dia);
            if (dia == 3 || dia == 7) {
                Prova();
            } else {
                dias();
                protagonista.energia = 10;
                protagonista.saude -= 2;                
            }

            fflush(stdin);
            printf("Pronto para o proximo dia? (s ou n)\n");
            scanf(" %c", &s);
            if (s == 'n') {
                sair = 1;
            }

            fflush(stdin);
            printf("Deseja salvar o jogo? (s ou n)\n");
            scanf(" %c", &s);
            if (s == 's') {
                Salvar();
            }
        }

        Final();
    }

    printf("BYE BYE");

}
