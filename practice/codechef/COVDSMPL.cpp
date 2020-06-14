#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int t ; cin >> t;
	while(t--){
		int n,p;
		cin >> n >> p;
		vector<vector<int>> v(n+1, vector<int>(n+1));
		for(int i = 1; i <=n ; i++){
			for(int j = 1; j <=n;j++){
				cout<<1<<" " << i << " " << i <<" "<< j << " "  << j << endl;
				int x ;cin>>x;
				v[i][j] = x;
			}
		}
		cout<<2<<endl;
		for(int i = 1; i <=n ; i++){
			for(int j = 1; j <=n;j++){
				cout<<v[i][j]<<" ";
			}cout<<endl;
		}
		int temp;cin>>temp;
		if(temp == -1) return 0;
	}    

  return 0;
}
