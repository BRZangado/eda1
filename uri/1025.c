#include <stdio.h>
 
int main() {

    int N, Q;
    int i;
    scanf("%d %d", &N, &Q);
    int P[N], R[Q];

    for(i = 0; i<N; i++){
      scanf("%d", &P[i]);
    }

    for(int j = 0; j<N; j++){
      printf("%d", P[j]);
    }
 
    return 0;
}