#include <bits/stdc++.h>
//#define int long long

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

int solve(vector<vector<int>> &A){
	int n = A.size(), m = A[0].size(); int count_ = 0;
	vector<int> v = sie(1000007);
	for(int i = 0 ; i < n; i++){
		for(int j = 0; j < m; j++){
			if(v[A[i][j]]) count_++;
		}
	}
	if(count_ == 0) return 1;
	if(count_%2 == 0) return 2;
	return 1;
}


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n; int m; cin	>> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	for(auto& x : v)
		for(int& y: x) cin >> y;

	cout << solve(v);


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
