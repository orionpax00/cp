#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int t ; cin >> t ;
	while(t--){
		int n ; cin >> n;
		if(n%2 == 0) cout << n/2 << "\n";
		else cout << (n-1)/2 << "\n";
	}
    

  return 0;
}
