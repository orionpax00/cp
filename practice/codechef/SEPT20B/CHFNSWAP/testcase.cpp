#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i = 1; i < 100000000; i++){
		int t = 1 + 2 * ( i * i	 + i);
		int tt = sqrt(t);
		if(tt * tt == t) cout << i << " " <<  (tt%2 == 1 ? (tt - 1)/2 : 0 )<< "\n";
	}
    


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
