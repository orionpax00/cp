#include <bits/stdc++.h>
#define int long long
using namespace std;

// Next Greater Element

template < typename T > 
map< int, int > nge(vector< T > arr) { 
	map< int, int> ans;
  stack < T > s;
	int n = arr.size(); 
  s.push(0); 
 
	for (int i = 1; i < n; i++) { 
  
    if (s.empty()) { 
      s.push(i); 
      continue; 
    }

		while (s.empty() == false && arr[s.top()] <= arr[i]) 
    {          
        ans[s.top()] = i; 
        s.pop(); 
    } 
  
    s.push(i); 
  }
	
	while (s.empty() == false) { 
		ans[s.top()] = n+1;
    s.pop(); 
  }

	return ans; 
}

int MAX_N = 100009;
vector< vector<int> > T(MAX_N , vector<int>(MAX_N)); 

void make_table(map<int, int> m, map<int, int> mr ,vector<int> vt, int n){
for (int a = 1 ; a <= n ; a++){
	for(int b = 1 ; b <= n ; b++){					
			int s_ = 0;
			for(int j = a; j <= b; j++) {
				if(m[j] > b) {
					s_ += vt[j];
				}
			}
			T[a][b] = s_;
			if( b < a){
				int s_ = 0;
				for(int j = a; j >= b; j--){
					if(mr[n - j + 1] > n - b  + 1){
						s_ += vt[j];
					}
				}
				T[a][b] = s_;
			}		
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int n, q;
	cin >> n >> q;
	
	vector< int > h(n+1);
	vector< int > vt(n+1);
	vector< int > hr(n+1);

	for(int i = 0 ; i < n ; i++){	
    int t ; cin >> t ; h[i + 1] = t; hr[n-i] = t;
	}
	for(int i = 0 ; i < n ; i++){
		cin >> vt[i+1];
	}

	map < int, int > m = nge(h);
	map < int, int > mr = nge(hr);
	make_table(m,mr,vt, n);

	for( int i = 0 ; i < q; i++){
		int t , a , b;
		cin >> t >> a >> b;
		if( t == 1){
			vt[a] = b;
		}else{
			if( a <= b){
				if(m[a] <= b) cout << -1 << "\n";
				else{	
					cout << T[a][b] << "\n";
				}
			}
			else{
				if(mr[n - a + 1] <= n - b + 1) cout << -1 << "\n";
				else{	
					cout << T[a][b] << "\n";
				}
			}
		}
	}	

  return 0;
}
