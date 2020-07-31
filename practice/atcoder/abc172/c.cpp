#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int n,m,t;
	cin >> n >> m >> t ;
	vector<int> N(n);
	vector<int> M(m);
	for(int i = 0 ; i < n ; i++){
    cin >> N[i];
	}

	for(int i = 0 ; i < m ; i++){
    cin >> M[i];
	}
	int k = 0;
	int l = 0;
	int ans = 0;
	while((k < n || l < m) && t > 0){
		if(N[k] < M[l]){
			if( t - N[k] >= 0){
			t -= N[k];k++; ans++;}
			else
				k = n;
		}else{
			if( t-M[l] >= 0){
			t -= M[l];l++; ans++;} else l =m;
		}
	}	
	cout << ans ;

  return 0;
}
