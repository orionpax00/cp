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
		int p,h;
		cin >> h >> p;
	
		while(p){
			h -= p;
			p >>= 1;
		}

	if(h > 0) cout << 0 << "\n";
	else cout << 1 << "\n";
	}

  return 0;
}
