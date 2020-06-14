//UNSolved

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int t; cin >> t;

	while(t--){
		vector<int> dv(3);
		vector<int> pv(3);
		int p, q, r,a,b,c;
		cin>>p>>q>>r>>a>>b>>c;
		dv[0] = a - p;
		dv[1] = b - q;
		dv[2] = c - r;
		
		if(p != 0 && a%p == 0) pv[0] = a/p;
		if(q != 0 && b%q == 0) pv[1] = b/q;
		if(r != 0 && c%r == 0) pv[2] = c/r;
		
		int isz = 0;
		vector<int> d;
		for(int i = 0 ; i < 3 ; i++){
			if(dv[i] == 0) {
						isz++;
			}else d.push_back(dv[i]);
		}
		
	int ans = INT_MAX;

	if(isz >= 1){
		if(isz == 1) {
			if(d[0] == d[1]) ans = min(ans , 1);
			else ans = min(ans, 2);
		}
		else if( isz == 2) ans = min(ans , 1);
		else ans = 0;
	}else{
		if(d[1] == d[0] && d[0] == d[2]) ans = min(ans, 1);
		else if (d[1] == d[2] || d[1] == d[0] || d[0] == d[2]) ans = min(ans ,2);
		else ans = min(ans,3);
	}

	//if(pv[1] == pv[0] && pv[0] == pv[2]) ans = min(ans,1);
	//else if(pv[1] == pv[2] || pv[2] == pv[0] || pv[0] == pv[1]) ans = min(ans,2);
		
	cout<<ans<<"\n";
	}

  return 0;
}









