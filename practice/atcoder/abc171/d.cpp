#include <bits/stdc++.h>
#define int long long

using namespace std;
int32_t main(){

	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int s = 0;
	int n ; cin >>n;
	vector<int> c(100001);
	for(int i = 0 ; i < n ; i++) {
		int t ;
		cin >> t;	s+=t;
		c[t]++;
	}
	int q ;
	cin >> q;
	for(int i =0 ; i< q; i++){
		int a, b;
		cin >> a >> b;
		cout << s - c[a] * a + c[a] * b << "\n";
		s += c[a] * b;
		s -= c[a] * a;
		c[b] += c[a];
		c[a] = 0;
  }

  return 0;
}
