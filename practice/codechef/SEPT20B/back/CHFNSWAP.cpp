#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> store(1000007);


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int counter = 2;
	for(int i = 3; i < 1000006; i+= 4){
		store[i] = counter;
		store[i+1] = counter;
		counter++;
	}

	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		cout << store[n] << "\n";
	}


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
