#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int a, n;
	cin >> a >> n;
	
	vector<int> v(101);
	for(int i =1 ; i <= n ; i++){
		int t; cin >> t;
		v[t] = 1;
	}    	
	
	int l = a;
	int r = a;
	while(true){
		if(!v[l]) {
			cout<<l;return 0;
		}
		if(!v[r]) {
			cout << r; return 0;
		}
		l--;
		r++;
			
	}

  return 0;
}
