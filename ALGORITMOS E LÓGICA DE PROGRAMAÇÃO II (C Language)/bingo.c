#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){

int numcartela;
int cartelas[10];
int i, j, numero, k, l;
int flag;

flag=0;

   printf("Digite o numero de jogadoeres:");
   scanf("%i",&numcartela);
   fflush(stdin);
   srand(time(NULL));
   
   for(i=0; i<numcartela; i++){

       for(j=0 ; j < 10 ; j++){
           numero = (rand () % 99);
           for(k=0; k<=j-1; k++){
           if (numero==cartelas[k]){
               flag=1;
               break;
           }
           }

       
       if (flag==1){
           flag=0;
           j=j-1;
       }
       else{
           cartelas[j]=numero;
       }
   }
   printf("Cartela %d:  ", i+1);
    for(l=0; l<10; l++){
        printf("%d", cartelas[l]);
    }
    printf("\n");
       
   }

}
