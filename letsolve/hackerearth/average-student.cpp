#include <bits/stdc++.h>
using namespace std;


//Sieve of erotosthenes
vector<int> sie(int n, vector<int>& v){
//	vector<int> v(n+1,0);
	v[0] = 1;
	v[1] = 1;
	for(int i = 2 ; i*i <= n; i++){
		if(!v[i]){
			for(int j = i*i ; j <= n ; j+=i){
				v[j] = 1;
			}
		}
	}

	vector<int> ans;
	for(int i = 0; i <= n; i++){
		if(!v[i]) ans.push_back(i);
	}

	return ans;
}
vector<int> primes_idx((int) 1e6 + 1);
vector<int> primes = sie((int) 1e6, primes_idx);
int N = primes.size();

void solve(){
	int n; cin >> n;
	
	int c1=0, c2 = 0 , c3 = 0 , c4 = 0;
	
	while(n--){
		int t; cin >> t;
		int t_ = t;
		if(t_ == 1) c1++;
		else if(!primes_idx[t]) c2++;
		else{
			int x = 0;
			set<int> s;
			for(int i = 0; primes[i] <= t_; i++){
				if(!primes_idx[t_]){
					x++;
					s.insert(t_);
					break;
				}
				while(t_%primes[i] == 0 && t_ > 1){
					x++;
					s.insert(primes[i]);
					t_ /= primes[i];
				}
			}
			if(s.size() == 1 && x == 3) c4++;
			else if(s.size() > 1 && x == 2) c4++;
			else if(x == 1) c3++;
			else if(s.size() == 1 && x == 2) c3++;
		}
	}
		cout << c2 + c3 - c4 - c1;


}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tt = 1; //cin >> tt;
	while(tt--) solve();


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
