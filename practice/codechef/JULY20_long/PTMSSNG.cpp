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
		int n; cin >> n;
		map <int , int> mx;
		map <int , int> my;
		for(int i = 0 ; i < 4*n - 1 ; i++){
			int x ,y ; cin >> x >> y;
			mx[x]++;
			my[y]++;
		}

		int xans;
		int yans;

		for(auto x : mx){
			if(x.second%2 !=0) {
				if(mx.count(-x.first) !=0 && mx[x.first]%2 != 0) continue;
				else xans = x.first;
			}
		}
		for(auto x : my){
			if(x.second%2 !=0) {
				if(my.count(-x.first) !=0 && my[x.first]%2 != 0)	continue;
				else yans = x.first;
			}
		}
		cout << xans << " " << yans << "\n";	
	}

  return 0;
}
