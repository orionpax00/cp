#include <bits/stdc++.h>
#define int long long

using namespace std;


vector<int> m = {3,5,7,9,11,13,15};

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
	int t ; cin >> t ;
	while(t--){
		int n ; cin >> n ; n--;
vector< vector<char> > B = {
 {'.', '.', '.' , '.', '.', '.', '.', '.', '.', '.'},
 {'.', '.', '.' , '.', '.', '.', '.', '.', '.', '.'},
 {'.', '.', '.' , '.', '.', '.', '.', '.', '.', '.'},
 {'.', '.', '.' , '.', '.', '.', '.', '.', '.', '.'},
 {'.', '.', '.' , '.', '.', '.', '.', '.', '.', '.'},
 {'.', '.', '.' , '.', '.', '.', '.', '.', '.', '.'},
 {'.', '.', '.' , '.', '.', '.', '.', '.', '.', '.'},
 {'.', '.', '.' , '.', '.', '.', '.', '.', '.', '.'},
 {'.', '.', '.' , '.', '.', '.', '.', '.', '.', '.'},
 {'.', '.', '.' , '.', '.', '.', '.', '.', '.', '.'},
};
		B[0][0] = '0';
		int row = 1;
		for(int i = 0 ; i < m.size(); i++){
			if(n - m[i] >= 0){ row++; n -= m[i];}
		}
		if(n !=0){	
		for(int i = 0 ; i < min(row,n); i++){
			B[row + 1][i] = 'X';
		}
		for(int i = 0 ; i < n - row; i++){
			B[i][row + 1] = 'X';
		}
		}
		for(int i = 0 ; i < row+1 ; i++){
			if(B[i][row+1] == '.') B[i][row] = 'X';
			if(B[row+1][i] == '.') B[row][i] = 'x';
		}

		for(int i = 0 ; i < 8 ; i++ ){
			for(int j = 0 ; j < 8 ; j++) {
				cout << B[i][j];
			} cout << "\n";
		}
	}
  
    

  return 0;
}
