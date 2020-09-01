#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int x; cin >> x;
		bool notpos = false;
		int n = s.length();
		vector<char> v(n, '1');
		
		for(int i = 0; i < n; i++){
			if(s[i] == '0'){
				if(i - x >= 0 ) v[i-x] = '0';
				if(i + x < n) v[i+x] = '0';
			}
		}

		for(int i = 0; i < n ; i++){
			int c = 0;			
			if(s[i] == '1'){
				if(i - x >= 0 && v[i - x] == '1') c++;
			 	if(i + x < n && v[i+x] == '1') c++;
				if(c == 0) notpos = true;
			}
		}	

		if(notpos) cout << -1;
		else
			for(int i = 0 ; i < n ; i++) cout << v[i];
		cout << "\n";
	}

  return 0;
}
