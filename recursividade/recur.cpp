#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fib(int n){
  if(n == 1 or n == 0){
    return 1;
  }
  return(fib((n-1)) + fib((n-2)));
}

int fatorial(int n){
	if(n == 0){
		return 1;
	}
	else{
		return n * fatorial(n-1);
	}
}

void contagem(int n){
	if(n == 0){
		printf("bomba \n");
	}
	else{
		printf("%d \n", n);
		contagem(n-1);
	}
}

int padovan(int n){
	if(n == 0 || n == 1 || n == 2) {
		return 1;
	}
	return padovan(n - 2) + padovan(n - 3);
}

int somatoria(int i){
	if(i == 0){
		return 0;
	}
	else{
		return i + somatoria(i-1);
	}
}

int multi(int a, int b){
  if(b == 1) {
    return a;
  } else {
    return a + multi(a, b - 1);
  }
}

int quadrado (int n){
  if(n == 0){
    return 1;
  }
  else{
    return (2*n-1) + quadrado (n-1);
  }
}

void contagemCrescente(int a){
	if(a > 0){
	 	contagemCrescente(a-1);
	}
    printf("%d\n", a);
}

int rBinarySearch(vector<int> v, int first, int last, int key, int * a) {
	(*a)++; 
	if(first <= last) {
		int mid = (first + last) / 2;
		if (key == v[mid]) 
				return mid;
		else if(key < v[mid]){
			return rBinarySearch(v, first, mid-1, key, a);
		}
		else{
			return rBinarySearch(v, mid+1, last, key, a);
		}
	}
	return -1;
}

void hanoi(int discos, char veio_estaca, char para_estaca, char estaca_aux){
    if (discos == 1){
        printf("\n Moveu disco 1 da estaca %c para estaca %c \n", veio_estaca,  para_estaca);
        return;
    }
    hanoi(discos-1, veio_estaca, estaca_aux,  para_estaca);
    printf("\n Moveu disco %d da estaca %c para a estaca %c \n", discos, veio_estaca,  para_estaca);
    hanoi(discos-1, estaca_aux,  para_estaca, veio_estaca);
}

int main(){

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	stable_sort(v.begin(), v.end());
	int i = 0;
	int * a = &i;
	auto mid = rBinarySearch(v, 0, v.size(), 3, a);
	cout << i << endl;

  return 0;
}