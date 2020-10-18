#include <bits/stdc++.h>
using namespace std;

bool is_pal(string& s){
	int i = 0;
	int j = s.length() - 1;
	while(i<j){
		if(s[i] != s[j]) return false;
		i++; j--;
	}

	return true;
}


void solve(){
	string s; cin >> s;

	if(is_pal(s)) puts("YES");
	else puts("NO");
		
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tt = 1; cin >> tt;
	while(tt--) solve();


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
