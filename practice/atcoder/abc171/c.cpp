#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 	
	long long n; cin >> n;
	string ans = "";
	string abc = "abcdefghijklmnopqrstuvwxyz";	
	int rem ; 
	while(n > 0){
		n -= 1;
		rem = n%26;
		ans += abc[rem];
		n /= 26;
	}

  reverse(ans.begin(), ans.end());
	cout << ans;

  return 0;
}
