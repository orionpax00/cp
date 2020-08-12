#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int n,q ; cin >> n >> q ;
 	vector<int> v(n);
	for(int i = 0 ; i < n ; i++){
		cin >> v[i];
	}
	
	while(q--){
	int l, r;
	cin >> l >> r;
	set<int> s;
	for(int i = l - 1; i < r ; i++) {
		s.insert(v[i]);   
	}
	cout << s.size() << "\n";
	}

  return 0;
}
