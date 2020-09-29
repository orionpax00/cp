#include <bits/stdc++.h>
using namespace std;

#define int long long


vector<vector<int>> subsets;
vector<int> ss;
vector<int> v;
int N;
int o, e;
int MOD = 1e9+7;


int gcdExtended(int a, int b, int *x, int *y) { 
    if (a == 0) { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    int x1, y1; 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 

int modInverse(int b, int m) { 
    int x, y;
    int g = gcdExtended(b, m, &x, &y); 
    if (g != 1) 
        return -1; 
    return (x%m + m) % m; 
} 



void subdp(){
	for(int i = 0; i < (1 << N); i++){
		vector<int> vt;
		for(int j = 0; j < N; j++){
			if((i & (1 << j)) != 0) vt.push_back(v[j]);
		}
		subsets.push_back(vt);
	}
}

int solve(){
	ss.clear(); subsets.clear();
	subdp();
	int inve = modInverse(e, MOD);
	int invo = modInverse(o, MOD);
	int ans = 0;
	for(auto x: subsets){
		int tempans = 1;
		int len = x.size();
		if(len&1){
			for(int t: x){
				tempans = (tempans * (t+o))%MOD;
			}
			tempans = (inve * tempans) % MOD;
		}else{
			for(int t: x){
				tempans = (tempans * (t+e))%MOD;
			}
			tempans = (invo * tempans) % MOD;
			
			if(len == 0) tempans = 0;
		}

		ans ^= tempans;
	}
	
	return ans;

}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tt = 1; cin >> tt;
	while(tt--){
		cin >> N >> o >> e; 
		v.clear();
		v.resize(N);
		for(int& x: v) cin >> x;
		cout << solve() << "\n";
	}


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
