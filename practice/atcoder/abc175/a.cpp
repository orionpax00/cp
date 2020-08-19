#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	string s;
	cin >> s; int ans = 0;
	for(int i = 0 ; i < 3 ; i++){
		int ans2 = 0;
		while(s[i] == 'R'){
			ans2++; i++;
		}
		ans = max(ans, ans2);
	}

	cout << ans;
    

  return 0;
}
