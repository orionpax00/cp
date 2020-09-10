#include <bits/stdc++.h>
#define int long long


using namespace std;

#include "../seive.h"

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

  vector<int> v = Sieve(10);	

	for(int x : v) cout << x << " ";

	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
