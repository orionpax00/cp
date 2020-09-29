#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tt; cin >> tt;
	while(tt--){
		int a, b, c, d; cin >> a >> b >> c >> d;
		int count = 0;
		for(int i : {a, b, c, d})
			if(i%2) count++;

		if(count <= 1) cout << "YES\n";
		else{
		
			int m = min({a, b, c, (int)1});
			d += m;
			a -= m; b -= m; c -= m;
	
			count = 0;
			for(int i : {a, b, c, d})
				if(i%2) count++;
	
			if(count <= 1) cout << "YES\n";
			else cout << "NO\n";
		}
	}


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
