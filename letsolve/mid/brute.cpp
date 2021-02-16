#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n;

bool check(int m){
	if(m < 1 || m == n - 1){
		return false;
	}
	
	if(v[m] > v[m-1] && v[m] > v[m+1]) return true;
	
	return false;
}

vector<int> solve(){
	vector<int> ans;
	for(int i = 0 ; i < n; i++){
		if(check(i)) ans.push_back(i);
	}

	return ans;
}

int main(){
	cin >> n;
	v.resize(n);
	for(auto & x: v) cin >> x;

	vector<int> ans = solve();

	cout << ans[0] << " " << ans[1] << "\n";

	return 0;
}
