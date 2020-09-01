#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s; cin >> s; 
	map<char, int> m;
	for(char c : s) m[c]++;
	
	for(auto x : m) cout << x.second  << "\n";    

  return 0;
}
