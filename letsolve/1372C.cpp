#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int t ; cin >> t;
	while(t--){
		int n ; cin >> n ;
		vector<int> v(n);
		for(auto& x: v) {cin >> x; x--;}
		int l = 0 ; int r = n - 1;
		while(l < r && v[l] == l) l++;
		while(l < r && v[r] == r) r--;
		int ans = 1;
		if( l == r) ans = 0;
		else{
			for(int i = l ; i < r ; i++) 
				if(v[i] == i) ans = 2;
		}
		cout << ans << "\n";
	}
		
	
		
    

  return 0;
}
