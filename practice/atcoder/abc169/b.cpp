#include <bits/stdc++.h>
using namespace std;
long long MAX = 1e18;
int main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int n; cin >> n;
	long long ans = 1;
	
	vector<long long> v(n);
	for(int i=0 ; i < n ; i++){
		cin >> v[i];
		if(v[i] == 0 ) {
			cout<< 0 ; return 0;
		}
	}

	for(int i = 0 ; i < n ; i++){
		long long t = v[i];
		if( t <= MAX / ans) ans *= t;
		else{
			cout<< -1; return 0;	
		}	
	}    
	cout<<ans;

  return 0;
}
