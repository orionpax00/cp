#include <bits/stdc++.h>
#define int long long

using namespace std;

int digsum(int n){
	int ans = 0;
	while(n){
		ans += n%10;
		n /= 10;
	}	
	return ans;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	
	int t ; cin >> t;
	while(t--){
		int n; cin >> n ;
		int cp = 0; 
		int mp = 0;
		for(int i= 0 ; i < n ; i++){
			int a,b; cin >> a >> b;
			int cd = digsum(a);
			int md = digsum(b);
			if(md == cd){
				cp++; mp++;
			}else if(md > cd) mp++;
			else cp++;
		}
    if(mp > cp) cout << 1 << " " << mp <<"\n";
		else if(cp > mp) cout << 0 << " " << cp <<"\n";
		else cout << 2 << " " << mp << "\n";
	}

  return 0;
}
