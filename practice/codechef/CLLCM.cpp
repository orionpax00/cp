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
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i = 0 ; i < n; i++){
			cin >> v[i];
		}    
		bool isno = false;
		for(int x : v)
			if( x%2 == 0)
				isno = true;
		if(isno) cout << "NO\n";
		else cout << "YES\n";
	}

  return 0;
}
