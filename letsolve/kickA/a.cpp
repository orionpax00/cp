#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int t ; cin >> t;
	int	ti = 0;
	while(t--){
		int n, b; cin >> n >> b;
		vector<int> v(n);
		for(int i = 0 ; i < n ; i++){
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int x = 0;	
		while(x < n){
			if( b >= v[x]){
				b -= v[x];
				x++;
			}else break;
		}
		cout << "Case #" << ti+1  << ": " << x << "\n";
		ti++;
	}
    

  return 0;
}
