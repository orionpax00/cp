#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> v){
	int n = v.size();
	map<int, int> m;

	int o1 = 0;

	for(int i : v){
		m[i]++;
		if(i == 1) o1++;
	}

	if(o1) return (o1 == 1 ? n-1: n); 

	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 1; j*j <= v[i]; j++){
			if(v[i]%j == 0){
				if(m.count(j)){ ans++; break;}
			}
		}
	}


	return ans;	
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tt = 1; cin >> tt;
	while(tt--){ 
		int n; cin >> n;
		vector<int> v(n); for(int& x: v) cin >> x;
		cout << solve(v) << "\n";
	}


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
