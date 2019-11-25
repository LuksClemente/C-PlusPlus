#include <iostream>

using namespace std;

const int INF = 0x3f3f3f3f3f;

int BottomUpCut(int p[], int n){
	int q, i, j;
	int r[n];
	r[0] = 0;
	for(i = 1; i <= n; i++){
		q = -INF;
		for(j = 1; j <= i; j++){
			q = max(q, p[j - 1] + r[i - j]);
		}
		r[i] = q;
	}
	return r[n];
}
int main(){
	int p[10] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	int n, result;
	cout << "Digite o tamanho da haste a ser cortada: ";
	cin >> n;
	cout << "Valor maximo: ";
	cout << BottomUpCut(p, n) << endl;
}
