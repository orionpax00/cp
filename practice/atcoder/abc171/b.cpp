#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int n , k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0 ; i < n ; i++){
		cin>>v[i];
	}
	sort(v.begin(), v.end());
			
	int ans = 0;

	for(int i = 0; i < k; i++) ans += v[i];
	cout << ans ;     

  return 0;
}
