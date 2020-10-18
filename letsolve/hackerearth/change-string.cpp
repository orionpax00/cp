#include <bits/stdc++.h>
using namespace std;

bool isvow(char c){
	return  c == 'A' || c == 'a' || c == 'Y' || c == 'y' || c == 'I' || c == 'i' || c == 'O' || c == 'o' ||
					 c == 'E' || c == 'e' || c == 'U' || c == 'u';
}


void solve(){
	string s; cin >> s;
	string ans = "";
	int n = s.length();
	for(int i = 0; i < n; i++){
		if(isvow(s[i])) continue;
		if(isupper(s[i]))	ans += "." , ans += tolower(s[i]);
		else ans += ".", ans += s[i];
	}
	cout << ans << "\n";
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
