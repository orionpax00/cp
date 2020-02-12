#include <bits/stdc++.h>

using namespace std;

vector<int> findfactors(int n){
	vector<int> factors;
	for(int i=1;i<sqrt(n);i++){
		if(n%i==0){
			if(n/i==i) factors.push_back(i);
			else {factors.push_back(i);factors.push_back(n/i);}
		}
	}
	return factors;
}			

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x=17;
	int ans = 8*sizeof(int) - __builtin_clz(x);
	cout<<pow(2,ans);
	
	return 0;
}