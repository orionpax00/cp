#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s; cin >> s;
	for(auto& c : s)
		if (c == 'T') c = 'U';
   
	cout << s; 

  return 0;
}
