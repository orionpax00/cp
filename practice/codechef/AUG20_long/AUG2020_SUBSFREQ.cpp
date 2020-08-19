#include <bits/stdc++.h>
#define int long long

using namespace std;

int M = 1e9 + 7;

long long bem(long long a, long long b, long long m){
	a %= m;
  long long res=1;
  while(b>0){
    if(b&1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}


int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;   
		for(int i = 0; i < n; i++){
			int temp; cin >>temp;
		}
	 
		for(int i = n - 1; i >= 0 ; i--){
			cout << bem(2, i, M) << " ";
		}
		cout << "\n";

	}

  return 0;
}
