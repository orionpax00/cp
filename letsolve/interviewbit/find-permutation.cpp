#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	vector<int> ans(n);
	vector<int> temp(n); iota(temp.begin(), temp.end(), 1);
	int c = 0;
	int d_count = 0;
	for(char c: s) if(c == 'D') d_count++;
	for(int i = 1; i < n; i++){
		if(s[i-1] == 'D'){
			ans[i] = temp[d_count - c - 1];
			c++;
		}
	}
	int t = 0;
	for(int i = 0; i < n; i++){
		if(ans[i] == 0){
			ans[i] = temp[c+t];
			t++;
		}
	}	

	for(int x : ans) cout << x << " ";
	cout << "\n";

}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tt; cin >> tt;
	while(tt--) solve();


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
