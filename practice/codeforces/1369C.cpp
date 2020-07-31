#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int t; cin >> t ; 
	while(t--){
		int n ; int k ;
		cin >> n >> k ;
		vector<int> v(n);
		vector< int > w(k);
		for(int i = 0 ; i < n ; i++){
			cin >> v[i];
		}
		for( int i = 0 ; i < k ; i++){
			cin >> w[i] ;
		}
		sort(v.begin() , v.end(), greater<int>());
		sort(w.begin(), w.end());
//		for(int x: w) cout<<x<<" ";
		long long ans = 0;
		int l = k;
		for(int i = 0 ; i < k; i++){
			if(w[i] == 1) {ans += v[i]*2;}
			else{
				ans += v[i] + v[l + w[i] - 2]; l += w[i] - 1;
			}
		}
		cout << ans << "\n";

	}
    

  return 0;
}
