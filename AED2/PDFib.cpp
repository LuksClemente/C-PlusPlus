#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

const long long int MOD = 1e9+7;

int main(int argc, char* argv[]){
	int n;
	cout << "Digite um numero: ";
	cin >> n;
	
	long long int fibnow = 1;
	long long int fibprev = 0;
	
	for(int i = 1; i <= n; i++){
		fibprev += fibnow;
		swap(fibprev, fibnow);
		fibprev %= MOD;
		fibnow %= MOD;
	}
	
	cout << "Resultado: ";
	cout << fibprev << endl;
}
