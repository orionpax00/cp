#include <bits/stdc++.h>
#define int long long

using namespace std;

int bem(int a, int b, int m){
	a %= m;
  int res=1;
  while(b>0){
    if(b&1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}


int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int p, q, r; cin >> p >> q >> r;
	for(int i = 1 ; i <= q; i++){
		p = bem(p, i, r);
	}
	cout << p <<"\n";
	    

  return 0;
}
