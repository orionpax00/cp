#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);	

	int t; cin >> t;
	int ii = 1;
	while(t--){
		int n ; cin >> n ;
		vector<char> iv(n);
		vector<char> ov(n);
		for(auto &x: iv) cin >> x;
		for(auto &x: ov) cin >> x;
		cout << "Case #" << ii << ":" << "\n";
	
		vector< vector<char> > ans(n, vector<char>(n, 'N'));
		for(int i = 0 ; i < n ; i++) ans[i][i] = 'Y';
		for(int i = 0 ; i < n ; i++){
			int k = i;
			while(k < n - 1){
				if(ov[k] == 'Y' && iv[k+1] == 'Y') {ans[i][k+1] = 'Y'; k++;}
				else break;
			}
			k = i;
			while(k >= 1){
				if(ov[k] == 'Y' && iv[k-1] == 'Y') {ans[i][k-1] = 'Y'; k--;}
				else break;
			}
		}
//		if(ov[0] == 'Y' && iv[1] == 'Y') ans[0][1] = 'Y';
	//	if(ov[n-1] == 'Y' && iv[n-2] == 'Y') ans[n-1][n-2] = 'Y';
		for(auto x : ans) {
			for(char c : x) cout << c;
			cout << "\n";
		}
		ii++;
	}
    

  return 0;
}
