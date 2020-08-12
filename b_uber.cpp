#include <bits/stdc++.h>
#define int long long
int M =1e9 + 7;

using namespace std;

int count(string a, string b) 
{ 
    int m = a.length(); 
    int n = b.length(); 
  
    int lookup[m + 1][n + 1] = { { 0 } }; 
  
    for (int i = 0; i <= n; ++i) 
        lookup[0][i] = 0; 
  
    for (int i = 0; i <= m; ++i) 
        lookup[i][0] = 1; 
  
    for (int i = 1; i <= m; i++){ 
        for (int j = 1; j <= n; j++){ 
            if (a[i - 1] == b[j - 1]){
                lookup[i][j] = lookup[i - 1][j - 1] +  
                               lookup[i - 1][j];
								lookup[i][j] %= M;
						} 
            else
                lookup[i][j] = lookup[i - 1][j]; 
        } 
    } 
  
    return lookup[m][n]; 
} 

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	string p, q, r; cin >> p >> q >> r;
	int a = count(p , r);
	int b = count(q , r);
	string s = p;
	s += q;
	int c = count(s, r);
	s = "";
	s += q; s+=p;
	int d = count(s , r);
	
	cerr << s << " " << c << " "  << a << " " << b <<"\n";

	cout << d+c - (a+b) << "\n";
    

  return 0;
}
