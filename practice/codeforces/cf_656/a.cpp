#include <bits/stdc++.h>
using namespace std;

void solve(){	
	int x, y, z; cin >> x >> y >> z;
//	if(x != y && y != z && z != x){ cout << "NO\n"; continue;}
	map<int, int> m;
	m[x]++; m[y]++; m[z]++;
	if(m.size() == 3){ cout << "NO\n";}
	else if(m.size() == 1) {
		cout << "YES\n";
		cout << x << " " << y << " " << z << "\n";
	}
	else{
		int a, b; 
		for(auto x: m){
			if(x.second == 2) a = x.first;
			else b = x.first;
		}
		if(a > b) {
			cout << "YES\n";
			cout << b << " " << 1 << " " << a <<"\n";
		}else{
			cout << "NO\n";
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tt; cin >> tt;
	while(tt--) solve();


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
