#include <bits/stdc++.h>
using namespace std;

vector<int> sie(int n){
	vector<int> aux(n + 1);
	for(int i = 2; i <= n; i++){
		for(int j = i*i; j <= n; j += i){
			aux[i] = 1;
		}
	}
	vector<int> ans;
	for(int i = 2; i <= n; i++)
		if(!aux[i])
			ans.push_back(i);

	return ans;
}




void solve(){
	int n; cin >> n;
	vector<int> primes = sie(n);
	
	vector<char> v(n); for(char& x : v) cin >> x;
	vector<int> a(n + 1);
	vector<int> b;
	vector<int> c(n + 1);



	for(int i = 0; i < n; i++){
		if(v[i] == 'a') a[i +1] = 1;
		else if(v[i] == 'b') b.push_back(i + 1);
		else c[i + 1] = 1;
	}

	int ans = 0;
	
	for(int i = 0; i < n; i++){
		vector<int> fac;
		int t = b[i];
		for(int j = 0; j*j <= b[i]; ){
			if(t%primes[j] == 0){
				fac.push_back(primes[j]);
				t /= primes[j];
				if(t == 0) break;
			}else{
				j++;
			}
		}

		int n_ = fac.size();
		int t_ = 1;
		int qq = t*t;
		for(int k = 0; k < n_; k++){
			t_ *= fac[k];
			int t1 = qq/t_; 
			if(a[t] && c[t1]) ans++;
		}	
		t_ = 1;
		qq = t*t;
		for(int k = 0; k < n_; k++){
			t_ *= fac[k];
			int t1 = qq/t_; 
			if(c[t] && a[t1]) ans++;
		}	
	}
	cout << ans << " ";

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
