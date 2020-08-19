#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int n, k, d; cin >> n >> k >> d;
	if(n <= k*d){
		int r = n%d;
		if( r == 0 && k%2 == 0){
			cout << d;
		}else
			cout << min(r, d - r) ;
	}else{
		cout << n - k*d;
	}
    

  return 0;
}
