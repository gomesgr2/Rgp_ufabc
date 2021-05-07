    // FILE *fp;
    // FILE *usersWrite;
    // FILE *usersRead;
    // char nome[MAX_TAMANHO_NOME];
    // char aux[MAX_TAMANHO_NOME];
    // char c;
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
#include <string.h>

//Seção de variáveis
#define MAX_TAMANHO_DA_PALAVRA 100
#define NUMERO_ITENS 5
#define OPCOES_DIA 3
#define OPCOES_MENU 4
#define MAX_TAMANHO_NOME 150

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
    int dia_atual;
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
   
    char aux_str[MAX_TAMANHO_DA_PALAVRA];

    FILE *fpInfo;
    int num = 0;
   
    fpInfo = fopen("Save.txt" , "r");
   
    char att[6] = {'e', '&','s','z','d','a'};
    char attInfo[6][MAX_TAMANHO_DA_PALAVRA] = {"Energia", "Estudo", "Social", "Saude", "Dinheiro","Dia Atual"};

    printf("Carregando as informacoes...... \n");
    criarlinha(34);

    if(fpInfo == NULL){
        printf("Erro na abertura do arquivo -> não foi possível recuperar as informações salvas\n");
        return;
    } 


    printf("Informaçoes salvas :");



    while(!feof(fpInfo)){
        if(num == 0){
            fgets(aux_str,MAX_TAMANHO_DA_PALAVRA, fpInfo);
            strcpy(protagonista.nome , aux_str);
            printf("Bem vindo de volta %s\n", protagonista.nome);

        } else if (num > 0 && num < 7){
            int info = atoi(fgets(aux_str,MAX_TAMANHO_DA_PALAVRA, fpInfo));
            printf("%s : %d\n",attInfo[num - 1], info);
            inserindoInfoDoProtagonista(att[num - 1], info);
        } else {
            break;
        }
        num ++;
   }

    fclose(fpInfo);


}

int obtendoInfoDoProtagonista(char tipo){
    switch(tipo){
        case 'e' :
            return protagonista.energia;
        case '&' : 
            return protagonista.estudo;
        case 's' :
            return protagonista.social;
        case 'z' :
            return protagonista.saude;
        case 'd' :
            return protagonista.dinheiro;
        default :
            return protagonista.dia_atual;
    }
}

void inserindoInfoDoProtagonista(char tipo, int info){
    switch(tipo) {
        case 'e' :
            protagonista.energia = info;
        case '&' :
            protagonista.estudo = info;
        case 's' :
            protagonista.social = info;
        case 'z' :
            protagonista.saude = info;
        case 'd' :
            protagonista.dinheiro = info;
        default :
            protagonista.dia_atual = info;
    }

}


void Salvar(){
    char aux_str[MAX_TAMANHO_DA_PALAVRA];
    FILE *fpInfo;

    char c;
    
    fpInfo = fopen("Save.txt" , "w");


    char att[6] = {'e', '&','s','z','d','a'};

    if( fpInfo == NULL){
        printf("Erro na abertura do arquivo - Não foi possível salvar as informações\n");
        return;
    } 

    fprintf(fpInfo, protagonista.nome);

    for(int i =0; i < 6; i++){
        fprintf(fpInfo, strcat(itoa(obtendoInfoDoProtagonista(att[i]), aux_str, 10), "\n"));
    }
    fclose(fpInfo);
}

//Ações nos dias comuns
void atividade(){
    char ativ;
    printf("Praticou alguma atividade fisica? (s ou n) \n");
    scanf(" %c", &ativ);
      if(ativ == 's'){
        protagonista.saude += 2;
        protagonista.energia -=1;
        printf("Voce ganhou 2 pontos! \n");
        } else if (ativ == 'n'){
            printf("Sem alteracao na pontuacao. \n");
            } else{
               printf("Resposta invalida! Por favor, responda com 's' em caso afirmativo ou com 'n' em caso negativo.\n");
               criarlinha(34);
               atividade();
               }
 printf("\n");
}

void agua(){
    char agu;
    printf("Bebeu 2L ou mais de agua? (s ou n)\n");
    scanf(" %c", &agu);
    if(agu == 's'){
        protagonista.saude += 3;
        protagonista.energia -=1;
        printf("Voce ganhou 3 pontos! \n");
        } else if (agu == 'n'){
              printf("Sem alteracao na pontuacao. \n");
              } else{
                 printf("Resposta invalida! Por favor, responda com 's' em caso afirmativo ou com 'n' em caso negativo.\n");
                 printf("As perguntas serao recomecadas: \n");
                 criarlinha(34);
                 agua();
                 }
 printf("\n");
}

void sono(){
    char son;
    printf("Teve de 7 a 9 horas de sono? (s ou n) \n");
    scanf(" %c", &son);
    if(son == 's'){
        protagonista.saude += 4;
        protagonista.energia -=1;
        printf("Voce ganhou 4 pontos! \n");
        } else if (son == 'n'){
            printf("Sem alteracao na pontuacao. \n");
            }else {
              printf("Resposta invalida! Por favor, responda com 's' em caso afirmativo ou com 'n' em caso negativo.\n");
              printf("As perguntas serao recomecadas: \n");
              criarlinha(34);
              sono();
              }
 printf("\n");
}

void compra(){
    char comp;
    printf("Fez compra on-line sem necessidade? \n");
    scanf(" %c", &comp);
    if(comp == 's'){
        protagonista.dinheiro -= 4;
        protagonista.energia -=1;
        printf("Voce perdeu 4 pontos! \n");
        } else if (comp == 'n'){
            printf("Sem alteracao na pontuacao. \n");
        }else{
            printf("Resposta invalida! Por favor, responda com 's' em caso afirmativo ou com 'n' em caso negativo.\n");
            printf("As perguntas serao recomecadas: \n");
            criarlinha(34);
            compra();
            }
 printf("\n");
}

void gasto(){
    char imp;
    printf("Teve que gastar com um imprevisto? \n");
    scanf(" %c", &imp);
    if(imp == 's'){
        protagonista.dinheiro -= 2;
        protagonista.energia -=1;
        printf("Voce perdeu 2 pontos! \n");
        } else if (imp == 'n'){
            printf("Sem alteracao na pontuacao. \n");
            }else{
            printf("Resposta invalida! Por favor, responda com 's' em caso afirmativo ou com 'n' em caso negativo.\n");
            printf("As perguntas serao recomecadas: \n");
            criarlinha(34);
            gasto();
            }
 printf("\n");
}

void mensagem(){
    char msg;
     printf("Teve uma troca de mensagens legal com alguem? \n");
    scanf(" %c", &msg);
    if(msg == 's'){
        protagonista.social += 3;
        protagonista.energia -=1;
        printf("Voce ganhou 3 pontos! \n");
        } else if (msg == 'n'){
            printf("Sem alteracao na pontuacao. \n");
            } else {
            printf("Resposta invalida! Por favor, responda com 's' em caso afirmativo ou com 'n' em caso negativo.\n");
            printf("As perguntas serao recomecadas: \n");
            criarlinha(34);
            mensagem();
            }
 printf("\n");
}

void redes(){
    char rede;
    printf("Interagiu nas redes sociais \n");
    scanf(" %c", &rede);
    if(rede == 's'){
        protagonista.social += 2;
        protagonista.energia -=1;
        printf("Voce ganhou 2 pontos! \n");
        } else if (rede == 'n'){
            printf("Sem alteracao na pontuacao. \n");
            } else {
            printf("Resposta invalida! Por favor, responda com 's' em caso afirmativo ou com 'n' em caso negativo.\n");
            printf("As perguntas serao recomecadas: \n");
            criarlinha(34);
            redes();
            }
 printf("\n");
}

void hoje(){
    char est1;
    printf("Voce estudou hoje? \n");
    scanf(" %c", &est1);
    if(est1 == 's'){
        protagonista.estudo += 4;
        protagonista.energia -=1;
        printf("Voce ganhou 4 pontos! \n");
        } else if (est1 == 'n'){
            printf("Sem alteracao na pontuacao. \n");
            } else {
            printf("Resposta invalida! Por favor, responda com 's' em caso afirmativo ou com 'n' em caso negativo.\n");
            printf("As perguntas serao recomecadas: \n");
            criarlinha(34);
            hoje();
            }
 printf("\n");
}

void curso(){
    char est2;
    printf("Estudou algum(a) curso/materia extracurricular? \n");
    scanf(" %c", &est2);
    if(est2 == 's'){
        protagonista.estudo += 2;
        protagonista.energia -=1;
        printf("Voce ganhou 2 pontos! \n");
        } else if (est2 == 'n'){
            printf("Sem alteracao na pontuacao. \n");
            } else {
            printf("Resposta invalida! Por favor, responda com 's' em caso afirmativo ou com 'n' em caso negativo.\n");
            printf("As perguntas serao recomecadas: \n");
            criarlinha(34);
            curso();
            }
 printf("\n");
}

void meta(){
    char est3;
    printf("Cumpriu sua meta de estudos do dia? \n");
    scanf(" %c", &est3);
    if(est3 == 's'){
        protagonista.estudo += 3;
        protagonista.energia -=1;
        printf("Voce ganhou 3 pontos! \n");
        } else if (est3 == 'n'){
            printf("Sem alteracao na pontuacao. \n");
        } else {
            printf("Resposta invalida! Por favor, responda com 's' em caso afirmativo ou com 'n' em caso negativo.\n");
            printf("As perguntas serao recomecadas: \n");
            criarlinha(34);
            meta();
            }
 printf("\n");
}

void AcoesDias(){

    char s, n;

    printf("Responda com 's' caso voce tenha feito aquela acao ou 'n' caso voce nao tenha a feito: \n");
    printf("\n");

    printf("Acoes relacionadas a saude: \n");
    printf("\n");
    atividade(s,n);
    agua(s,n);
    sono(s,n);

    printf("Acoes relacionadas ao dinheiro: \n");
    printf("\n");
    compra(s,n);
    gasto(s,n);

    printf("Acoes relacionadas a vida social: \n");
    printf("\n");
    mensagem(s,n);
    redes(s,n);

    printf("Acoes relacionadas ao estudo: \n");
    printf("\n");
    hoje(s,n);
    curso(s,n);
    meta(s,n);

}

//Sistema de provas
void Prova(){

}

void Final(){

}

//Exibe a tela de início
int tela(){
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

    return esc;
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


int determinarDia(int carregado){
    if(carregado == 1) {
        return protagonista.dia_atual;
    } 
    else{
        return 1;
    }

}

void passagemDasSemanas(int dia, char s){
    for (dia <= 7; dia++;){
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
                protagonista.dia_atual = dia;
                Salvar();
            }
    }
}

// getters e setters do "Java"
// void inserindoInfoDoProtagonista(char info[]){


// }


void main(){
    char s;
    LerInicio();

    while(sair == 0) {
        int carregado = tela();
        int dia = determinarDia(carregado);
        passagemDasSemanas(dia, s);
        Final();
    }

    printf("BYE BYE");

}


