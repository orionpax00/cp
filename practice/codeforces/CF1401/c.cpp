#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while(t--){
		int n ; cin >> n;
		vector<int> v(n), sc(n);
		int t;
		int m_ = INT_MAX;
		for(int i = 0; i < n; i++){
			 cin >> t; m_ = min(m_, t);
			 v[i] = t; sc[i] = t;
		} 
		
		sort(sc.begin(), sc.end());
		bool notpos = false;
   	for(int i = 0 ; i < n; i++)
			if(v[i] != sc[i] && v[i]%m_ != 0) notpos = true;   
		
		if(notpos) cout << "NO\n";
		else cout << "YES\n";
	}

  return 0;
}
