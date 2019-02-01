#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
	int i;
	int  vagao, trem;
	bool certo = true;
	stack<int> pilha1 , pilha2, pilha3;

	do{
		cin >> trem ;
		
	do{

	certo = true;
	auto aux2 = trem;
	auto aux = trem;
		for ( i = trem; i > 0; i--){
			pilha1.push(i);
		}
		while(aux--){	
			cin >> vagao;
			
			if( vagao == 0)	{
				break;
			}
			do{
				//Da pilha1 para a pilha 3
				if(pilha1.empty() != true){
					if(vagao == pilha1.top()){
						pilha3.push(pilha1.top());
						pilha1.pop();
						break;
					}		
				}  // Da pilha 2 para a pilha 3
				if(pilha2.empty() != true){
					if(vagao == pilha2.top()){
						pilha3.push(pilha2.top());
						pilha2.pop();
						break;		
					}
							
				}// Da pilha 1 para a pilha 2  
				if(pilha1.empty() != true){
					if(vagao > pilha1.top()){
						pilha2.push(pilha1.top());
						pilha1.pop();	
						
					}
				}
				if(pilha3.empty() != true && pilha1.empty() != true){
					if(vagao != pilha3.top()){
						if(vagao < pilha1.top() && vagao < pilha2.top()){	
								certo = false;
								break;
						}
					}
				}
				if(pilha3.empty() != true && pilha1.empty() == true){
					if(vagao != pilha3.top()){
						if( vagao < pilha2.top()){
							certo = false;
							break;
						}
					}
				}
			}while(pilha1.empty() != true && vagao > pilha2.top());	

			}	
			if(vagao != 0){
			if(pilha3.size() == aux2){
				cout << "Yes" << endl;
			} else 
				cout << "No"<<  endl;
			}	

				while(!pilha1.empty())
    			pilha1.pop();

    		while(!pilha2.empty())
    			pilha2.pop();

    		while(!pilha3.empty())
    			pilha3.pop();

	if( vagao == 0)	{
				break;
			}

		}while(1);
		
			
			cout << endl;

			
    		
			if(trem == 0 )	{
				break;
		}

					}while(1);

	
	

	return 0;
}