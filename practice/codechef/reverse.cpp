#include <bits/stdc++.h>
#define int long long

using namespace std;

int reve(int n){
	string s = "";
	while(n){
		s += to_string(n%10);
		n /= 10;
	}
	return stoi(s);
}


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
 	while(t--){
		int a, b;
		cin >> a >> b;  
		cout << reve(reve(a) + reve(b)) << "\n";
	}		  

  return 0;
}
