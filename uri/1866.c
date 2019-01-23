#include <stdio.h>
 
int main() {

    int C;
    scanf("%d", &C);
    for (int i = 0; i < C; i++){
      int N;
      scanf("%d", &N);
      if(N % 2 == 0){
        printf("0\n");
      }
      else{
        printf("1\n");
      }
    }
 
    return 0;
}