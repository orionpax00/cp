#include <bits/stdc++.h>

using namespace std;

bool solve(	vector<vector<int>> v){
	int ok = true;
	for(int 

int main(){
	vector<vector<int>> v(9, vector<int>(9));

	for(auto& x : v)
		for(int& y : x) cin >> y;
		

	cout << (solve(v) ? "Valid" : "Invalid") << "\n";

	return 0;
}
