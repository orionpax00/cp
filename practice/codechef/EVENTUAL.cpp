#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s;
		cin >> s;
		map <char, int> m;
		for(char c : s) m[c]++;
	
		bool found = false;
		
		for(auto x : m){
			if(x.second % 2 != 0){
				found = true; 
				cout << "NO\n";
				break;
			}
		}
	
	if(!found) cout << "YES\n";
	}
    

  return 0;
}
