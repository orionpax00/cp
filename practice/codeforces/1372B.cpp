#include <bits/stdc++.h>
#define int long long

using namespace std;

//Sieve of erotosthenes
template<typename T>
vector<T> sie(T n){
	vector<T> v(n+1,0);
	v[0] = 1;
	v[1] = 1;
	for(T i = 2 ; i*i <= n; i++){
		if(!v[i]){
			for(T j = i*i ; j <= n ; j+=i){
				v[j] = 1;
			}
		}
	}
	return v;
}


int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 	int t; cin >> t;
	while(t--){
		int n; cin >> n;
			int i = 1;
			int ts = sqrt(n);
			while(true){
				if(i > ts){
					cout << n - 1 << " " << 1 <<"\n";
					break;
				} 
				if((i * n)%(i+1) == 0){
					cout << (i * n)/(i+1) << " " << n/(i+1) <<"\n";
					break;
				}

				i++;
			}
	}
    

  return 0;
}
