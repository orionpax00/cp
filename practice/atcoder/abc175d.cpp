#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int n ; cin >> n;
	string s ; cin >> s;
	int cnt = 0 ;
	string sb = s;
	int t = s.length();
	sort(s.begin(), s.end());
	for(int i = 1 ; i < t; i++){
		if(sb[i] != s[i]) cnt++;
	}    
	cout << (cnt + 1)/2;
  return 0;
}
