#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s; cin >> s;
	int sum_ = 0;
	for(int i = 0; i < (int) s.length(); i++) sum_ += s[i] - '0';     

	cout << (sum_ % 9 ? "No" : "Yes");

  return 0;
}
