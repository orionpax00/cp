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
		int n, k; cin >> n >> k;
		string s; cin >> s;
		vector<int> v(2);
		k = n/k;
		for(char c : s) v[c - '0']++;
		if(v[0]%k != 0 && v[1]%k != 0) { cout << "IMPOSSIBLE\n"; continue;}
		
		string ans = "";
		for(int i = 0; i < v[0]/k ; i++) ans += '0';
		for(int i = 0; i < v[1]/k ; i++) ans += '1';
	
		string fans = "";
		string rans = ans;
		reverse(rans.begin(), rans.end());
		for(int i = 0 ; i < k ; i++){
			if(i%2 == 0) fans += ans;
			else fans += rans;
		}

		cout << fans << "\n";
  }

  return 0;
}
