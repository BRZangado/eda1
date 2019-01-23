#include <stdio.h>
 
int main() {

    int T;
    int i, soma = 0;

    scanf("%d", &T);
    for(i = 0; i<5; i++){
      int resposta;
      scanf("%d", &resposta);
      if(resposta == T){
        soma+=1;
      }
    }

    printf("%d\n", soma);
 
    return 0;
}