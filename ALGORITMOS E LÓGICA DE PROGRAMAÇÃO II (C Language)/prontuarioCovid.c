#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

//variaveis globais

char nome[200];
char cpf[200];
char sexo[2];
int idade;
int main();


struct elemento {
    char pergunta[256];
    int pontuacao;
};

struct elemento questoes[]={
    { .pergunta = "Tem febre: ", .pontuacao = 5},
    { .pergunta = "Tem dor de cabeca:", .pontuacao = 1},
    { .pergunta = "Tem secrecao nasal ou espirros:", .pontuacao = 1},
    { .pergunta = "Tem dor/irritacao na garganta:", .pontuacao = 1},
    { .pergunta = "Tem tosse seca:", .pontuacao = 3},
    { .pergunta = "Tem dificuldade respiratoria:", .pontuacao = 10},
    { .pergunta = "Tem dores no corpo:", .pontuacao = 1},
    { .pergunta = "Tem diarreia: ", .pontuacao = 1},
    { .pergunta = "Teve contato com um caso diagnosticado de COVID-19 nos ultimos 14 dias: ", .pontuacao = 10},
    { .pergunta = "Esteve em locais com grande aglomeracao: ", .pontuacao = 3},

};



void perguntas(){
    
    char res;
    int soma = 0;
    int i=0;

    FILE *arquivoTxt; 
    arquivoTxt = fopen("dataBase.txt", "a");

    if (arquivoTxt==NULL)
    {
        printf("Erro ao criar arquivo. \n");
    }

    system("cls");
    printf("Responda as perguntas com: \n S -> sim \n N -> nao \n");
    printf("-------------------------\n");

    for(i=0; i<10; i++){
        printf("%s", questoes[i].pergunta);
        scanf("%c", &res);
        fflush(stdin);
        fprintf(arquivoTxt, "%s %c \n", questoes[i].pergunta, res);
        if( res== 'S' || res=='s'){
            soma= soma + questoes[i].pontuacao;
        }

    }
    fprintf(arquivoTxt, "O total de pontos do paciente %d", soma);
    fclose(arquivoTxt);

    system("cls");
    if (soma>=0 && soma<10){
        printf("Voce somou %d pontos, deve se encaminhar para ala de BAIXO RISCO\n", soma);
    }
    if (soma>=10 && soma<20){
        printf("Voce somou %d pontos, deve se encaminhar para ala de MEDIO RISCO\n", soma);
    }
    if (soma>=20){
        printf("Voce somou %d pontos, deve se encaminhar para ala de ALTO RISCO\n", soma);
    }

    soma=0;

    printf("Pressione Enter para voltar ao MENU PRINCIPAL\n");
    getchar();
    main();



}

void cadastrarPaciente() {

    setlocale(LC_ALL, "Portuguese");

    FILE *arquivoTxt; 
    arquivoTxt = fopen("dataBase.txt", "a");

    if (arquivoTxt==NULL)
    {
        printf("Erro ao criar arquivo. \n");
    }

    printf("Informe o nome do paciente: \n");
    scanf("%s", nome);
    fflush(stdin);

    printf("Informe o CPF do paciente: \n");
    scanf("%s", cpf);
    fflush(stdin);

    printf("Informe o sexo do paciente (M/F): \n");
    scanf("%s", sexo);
    fflush(stdin);

    printf("Informe a idade do paciente: \n");
    scanf("%d", &idade);
    fflush(stdin);

    fprintf(arquivoTxt, "Nome: %s\n", nome);
    fprintf(arquivoTxt, "CPF: %s \n", cpf);
    fprintf(arquivoTxt, "Sexo: %s \n", sexo);
    fprintf(arquivoTxt, "Idade: %d \n", idade);
    fclose(arquivoTxt);

    printf("Dados gravados com sucesso\n");
    printf("Pressione ENTER para continuar \n");
    getchar();
    perguntas();

} 


int main () 
{
    int opcao;

    printf("------MENU------ \n");
    printf("SELECIONE UMA OPCAO \n");
    printf("1 - CADASTRAR PACIENTE \n");
    printf("0 - SAIR \n");
    printf("--------------------\n");
    printf("-->");
    scanf("%i", &opcao);
    fflush(stdin);

    switch (opcao)
    {
    case 0:
    printf("Encerrando programa\n");
    
        break;
    
    case 1: 
    cadastrarPaciente();
    break;
    
    default:
        break;
    }
}
