#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	
		vector<int> dp(2000000+1);
		dp[3] = 4;
		dp[2] = 0;
		for(int i = 4 ; i <= 2000000 ; i++){
			 dp[i] =  dp[i-1] + 2 * dp[i-2] % 1000000007 + (i%3 == 0 ? 4 : 0);
			 dp[i] %= 1000000007;
		}
	int t; cin >> t;
	while(t--){
		int n ; cin >> n;
		cout << dp[n] << "\n" ;	
  }

  return 0;
}
