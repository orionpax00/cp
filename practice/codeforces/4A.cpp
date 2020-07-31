#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	
	int n;
	cin >> n ;
	if(n == 2) {
		cout << "NO" ; 
		return 0;
	}

	if(n % 2 == 0) cout << "YES" ;
	else cout << "NO" ;
    

  return 0;
}
