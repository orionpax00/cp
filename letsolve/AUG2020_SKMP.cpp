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
		string s,p;
		cin >> s >> p;
		vector<int> v(26);
		for(char c : s) v[c - 'a']++;
		for(char c : p) v[c - 'a']--;
		char occ_2 = '~';
		if(p.length() > 1){
  	  char prev = p[0]; int i = 1;
  	  while(p[i]==prev) i++;
  	  occ_2 = p[i];
		}
		string ans = "";
		bool done = false;
		for(int i = 0 ; i < 26; i++){
			if('a' + i == p[0] && p.length() > 1 && occ_2 < p[0]){ 
				ans+=p; done=true;	
			}
      int t = v[i];
			while(t--) ans += 'a' + i;
			if('a' + i == p[0] && !done) ans += p;
		}
		cout << ans << "\n";
	}

  return 0;
}

