#include <iostream>

using namespace std;

const int INF = 0x3f3f3f3f3f;

void EscreveTrocoMinimo(int M[], int t){
	int TM[t + 1];
	int Escolha[t + 1];
	int i, j;
	
	TM[0] = 0;
	
	for(i = 1; i <= t; i++){
		TM[i] = INF;
		for(j = 0; j < 6; j++){
			if(M[j] <= i){
				int moeda = M[j];
				if(1 + TM[i - moeda] < TM[i]){
					TM[i] = 1 + TM[i - moeda];
					Escolha[i] = moeda;
				}
			}
		}
	}
	cout << "Troco minimo: " << TM[t] << " moeda(s)" << endl;
	cout << "Moeda(s): ";
	while(t > 0){
		cout << Escolha[t] << " ";
		t = t - Escolha[t];
	}
}
int main(){
	int troco;
	int M[] = {1, 5, 10, 25, 50, 100};
	cout << "Digite o troco: ";
	cin >> troco;
	EscreveTrocoMinimo(M, troco);
}
