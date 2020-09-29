#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tt; cin >> tt; 
	while(tt--){
		int n; cin >> n;
		vector<int> a(n), b(n); 

		for(int& x : a) cin >> x;
		for(int& x : b) cin >> x;

		vector<int> t;
		for(int i =0 ; i < n; i++){
			if(b[i] == 0) t.push_back(a[i]);
		}
		int c = 0;
		sort(t.rbegin(), t.rend());
		for(int i = 0; i < n; i++){
			if(b[i] == 0) { a[i] = t[c]; c++;}
		}	

		for(int x : a) cout << x << " ";
		cout << "\n";
	}



	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
