#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int xnor(int a, int b) { 
    if(b > a) swap(a, b);
	int sh_ = 64 - __builtin_clzll(a);
	int t = pow(2, sh_) - 1;

    return (a^b)^t; 
} 

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t ; cin >> t;
	while(t--){
		int a, b, n; cin >> a >> b >> n;
		if(n%3 == 0) cout << max((a^b), xnor(a, b));
		else if(n%3 == 1) cout << a ;
		else cout << b ;

		cout << "\n";
	}

  return 0;
}
