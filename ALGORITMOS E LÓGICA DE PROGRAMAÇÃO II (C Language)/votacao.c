#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int vJoao = 0, vMaria = 0, vZe = 0, vVotoNulo = 0, vInvalido = 0;
int pZureta = 0, pGomes = 0, pVotoNulo = 0, pInvalido = 0;


int main () {

    setlocale(LC_ALL, "Portuguese");
    int opcao_menu;
    int opcao_vereador, opcao_prefeito;
    

    system("cls");
    printf("-----MENU-----\n");
    printf("1 - VOTAR \n");
    printf("2 - APURAR VOTOS \n");
    printf("3 - SAIR \n");
    printf("-------------- \n");
    printf("-->");
    scanf("%i", &opcao_menu);
    fflush(stdin);

    switch (opcao_menu)
{
    case 1: 
        system("cls");
        printf("------VOTACAO--VEREADOR------ \n");
        printf("111- Para vereador Joao do Frete \n");
        printf("222- Para vereador Maria da Pamonha \n");
        printf("333- Para vereador Ze da Farmacia \n");
        printf("444- Voto nulo \n");
        printf("----------------------- \n");
        printf("-->");
        scanf("%i", &opcao_vereador);
        fflush(stdin);
        switch (opcao_vereador)
        {
            case 111:
            printf("Voto confirmado - Vereador Joao do Frete \n");
            vJoao = vJoao + 1;
            break;
            case 222:
            printf("Voto confirmado - Vereador Maria da Pamonha \n ");
            vMaria = vMaria + 1;
            break;
            case 333:
            printf("Voto confirmado - Vereador Ze da Farmacia \n");
             vZe = vZe + 1;
            break;
            case 444:
            printf("Voto confirmado - Voto nulo \n");
            vVotoNulo = vVotoNulo + 1;
            break;
            default:
            printf("Voto invalido \n");
            vInvalido = vInvalido + 1;
            break;
        }
        
        system("pause");
        system("cls");
        printf("------VOTACAO--PREFEITO------ \n");
        printf("11- Para Dr. Zureta \n");
        printf("22- Para Senhor Gomes \n");
        printf("44- Voto nulo \n");
        printf("----------------------- \n");
        printf("-->");
        scanf("%i", &opcao_prefeito);
        fflush(stdin);
        switch (opcao_prefeito)
        {
        case 11:
        printf("Voto confirmado em Dr. Zureta \n");
        pZureta = pZureta + 1;
        break;
        case 22: 
        printf("Voto confirmado em Senhor Gomes \n");
        pGomes = pGomes + 1;
        break;
        case 44:
        printf("Voto nulo confirmado \n");
        pVotoNulo = pVotoNulo + 1;
        break;
        
        default:
        printf("Voto invalido \n");
        pInvalido = pInvalido + 1;
        break;
        
        }
        printf("Pressione enter para voltar ao MENU \n");
        getchar();
        main();
        
    break;
    
        
        
    case 2:
    system("cls");
    printf("----APURACAO DE VOTOS----\n");
    printf("-------------------------\n");
    printf("-----VEREADORES-----\n");
    printf("Vereador 111: %d votos \n", vJoao );
    printf("Vereador 222: %d votos \n", vMaria);
    printf("Vereador 333: %d votos \n", vZe);
    printf("Votos Nulos: %d votos \n", vVotoNulo);
    printf("Votos Invalidos: %d votos \n", vInvalido);
    printf("-------------------------\n");
    printf("--------PREFEITOS--------\n");
    printf("Prefeito 11: %d votos \n", pZureta);
    printf("Prefeito 22: %d votos \n", pGomes);
    printf("Votos nulos: %d votos \n", pVotoNulo);
    printf("Votos invalidos: %d votos \n", pInvalido);
    printf("---------------------------\n");
    printf("Pressione qualquer tecla para voltar ao Menu \n");
    getchar();
    main();
    break;
    



    case 3:
    printf("Finalizando o programa...\n");

    break;

    
    default:
    printf("Comando nao reconhecido\n");
    printf("Pressione Enter para voltar ao menu\n");
    getchar();
    main();
    break;
    }
    


}