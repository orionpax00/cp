#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);	

	int t; cin >> t;
	while(t--){
		int c, r; cin >> c >> r; 
		bool isanswer = false;
		for(int i = 0 ; i < 9; i++){
			if((c+i)%9 == 0 && (c+i) < r){
				int n = (c+i)/9;
				cout << 0 << " " << n << "\n";
				isanswer=true;
			}
		}

		if(!isanswer){
			if(min(r, c)%9 == 0) 
			 cout << 1 << " " << min(r, c)/9 << "\n";
			else
				cout << 1 << " " << min(r, c)/9 + 1 << "\n";
		}
	}
 

  return 0;
}
