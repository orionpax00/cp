#include <bits/stdc++.h>
#define int long long

using namespace std;


//Sieve of erotosthenes
template<typename T>
vector<T> sie(T n){
	vector<T> v(n+1,0);
	v[0] = 1;
	v[1] = 1;
	for(T i = 2 ; i*i <= n; i++){
		if(!v[i]){
			for(T j = i*i ; j <= n ; j+=i){
				v[j] = 1;
			}
		}
	}
	return v;
}



int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

  
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		vector<int> v = sie(n);
		int sum = 0;
		for(int i = 2 ; i <= n; i++){
			if(!v[i]) sum += i;
		}		

		cout << (sum%10) << "\n";
	}

	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
