#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s; cin >> s;
	vector<vector<int>> v(26, vector<int>());
	int n = s.length();
	for(int i = 0; i < n; i++){
		v[s[i] - 'a'].push_back(i);
	}

	int idx = 25;
	
	for(int i = 0 ; i < 26; i++) 
		if(v[i].size() != 0) idx = i;

	bool ok = true;

	char prev = s[0];
	for(char c : s)
		if(c != prev) ok = false;

	if(ok){
		cout << s;
		return;
	}


	//vector<string> ans;
	string ans = "";
	for(int i = 0; i < (int)v[idx].size(); i++){
		string temp = s;
		int id = v[idx][i];
		reverse(temp.begin(), temp.begin() + id);
		reverse(temp.begin() + id, temp.end());
		reverse(temp.begin(), temp.end());
		ans = max(temp, ans);
	}

	cout << ans <<"\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tt = 1; 
//	cin >> tt;
	while(tt--) solve();


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
