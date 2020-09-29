#include <bits/stdc++.h>
//#define int long long

using namespace std;

int MOD = 998244353;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int m; cin >> m;
	while(m--){
	
		string s; cin >> s;
	
		vector<int> v(26);
		for(char c : s) v[c - 'a']++;
	
		int n; cin >> n;
		vector<int> ans(n,1);
		vector<string> names(n);
		for(int i = 0; i < n; i++){
			string name; cin >> name;
			for(char c : name){
				ans[i] = (ans[i] * v[c - 'a'])%MOD;
			}
			names[i] = name;
		}

		for(int x : ans) cout << x << "\n";
		
		int idx = 0, sum_ = 0, max_ = INT_MIN;
	 	for(int i = 0 ; i < (int)ans.size(); i++){
			if(ans[i] > max_){
				max_ = ans[i]; 
				idx = i;
			}
			sum_ += ans[i];
		}	

		if(sum_ == 0) cout << "No Research This Month\n";
		else cout << names[idx] << "\n";
	}



    


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
