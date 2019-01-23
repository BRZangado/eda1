#include <iostream>

using namespace std;
 
int main() {

    while(1){
      int N;
      cin >> N;
      if(N == 0){
        break;
      }
      else{
        int i, j, indice;
        int A[N];
        int maior = 0, segundo_maior = 0;

        for(i = 0; i<N; i++){
          int a;
          cin >> a;
          if(a>maior){
            segundo_maior = maior;
            maior = a;
          }
          else if(a>segundo_maior){
              segundo_maior = a;
            }
          A[i] = a;
        }

        for(j = 0; j<N; j++){
          if(A[j] == segundo_maior){
            indice = j;
            break;
          }
        }

        cout << indice+1 << endl;
        continue;
      }
    }
 
    return 0;
}