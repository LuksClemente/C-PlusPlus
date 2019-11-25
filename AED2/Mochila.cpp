#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f3f;

int memo[2020][2020];
int n, s;

int value[2020], weight[2020];

int pd(int ind, int cap){
	if(ind == n){
		return 0;
	}
	if(cap < 0){
		return -INF;
	}
	
	int& pdm = memo[ind][cap];
	if(pdm != -1){
		return pdm;
	}
	
	return pdm = max(pd(ind + 1, cap - weight[ind]) + value[ind], pd(ind + 1, cap));
}
int main(){
	cin >> s >> n;
	
	for(int i = 0; i < n; i++){
		cin >> weight[i] >> value[i];
	}
	
	 memset(memo, -1, sizeof(memo));
	 
	 cout << pd(0, s) << endl;
	
}
