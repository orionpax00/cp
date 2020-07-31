#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);


	int a, n;
	cin >> a >> n;    

	vector<int> v(n+1);

	int ans = 0;
	int m = INT_MIN;	
	for(int i = 0 ; i < n ; i++){
		int t;
		cin >>t;
		v[t] = 1;
		m = max(m, t);
	}
	
	if(n == 0){
		cout<<a;
		return 0;
	}

	for(int i = a; i <= m ; i++){
		if(v[i] == 0){
			 ans = i;
			 break;
		}
	}

	for(int i = a-1; i > 0; i--){
		if(v[i] == 0 ) {
			if(abs(ans - a) > abs(a-i)) {
				ans = i;
				break;
			}
		}
	}

	cout<<ans;

  return 0;
}
