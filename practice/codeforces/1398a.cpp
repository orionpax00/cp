#include <bits/stdc++.h>
#define int long long

using namespace std;
bool check(int a, int b , int c){
	return a+b > c && b+c > a && a + c > b;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v(n);
		for(int i =0; i < n; i++){
			cin >> v[i];
		}
	
		if(v[0] + v[1] > v[n - 1]) cout << -1 <<"\n";
		else cout << "1 2 " << n << "\n";
	
	}

  return 0;
}
