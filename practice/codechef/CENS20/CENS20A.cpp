#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m; cin >> n >> m;
	vector<string> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];

	vector< vector<int> > mat(n, vector<int>(m));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			mat[i][j] = v[i][j] - '0';

	vector< vector<int> > diff(n+1, vector<int> (m+1));
	int q; cin >> q;
	while(q--){
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2; x1--; x2--; y1--; y2--;
		diff[x1][y1]++;
		diff[x2+1][y2+1]++;
		diff[x2+1][y1]--;
		diff[x1][y2+1]--;
	}

	for(int i = 0; i < m; i++)
		for(int j = 1; j < n; j++)
			diff[j][i] += diff[j-1][i];

	for(int i = 0; i < n; i++)
		for(int j = 1; j < m; j++)
			diff[i][j] += diff[i][j-1];

	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(diff[i][j]&1){
				if(mat[i][j]) cout << 0 ;
				else cout << 1;
			}else cout << mat[i][j];
		}
		cout << "\n";
	}
    
  return 0;
}
