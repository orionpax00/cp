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
		int n ;
		cin >> n ;    
		vector< int > ve;
		vector< int > vo; 
		for(int i = 0 ; i < 2*n ; i++){
			int t; cin >> t;
			if(t%2 == 0) ve.push_back(i+1);
			else vo.push_back(i+1);
		}	
		if(ve.size() % 2 == 0) {
			if(ve.size() > 2){
				for(int i = 2 ; i < ve.size() ; i+=2)	cout << ve[i] << " " << ve[i+1] << "\n";
				for(int i = 0 ; i < vo.size() ; i+=2) cout << vo[i] << " " << vo[i+1] << "\n";
			}else{
				for(int i = 0 ; i < ve.size() ; i+=2)	cout << ve[i] << " " << ve[i+1] << "\n";
				for(int i = 2 ; i < vo.size() ; i+=2) cout << vo[i] << " " << vo[i+1] << "\n";	
			}
		}else{
			for(int i = 1 ; i < ve.size() ; i+=2) cout << ve[i] << " " << ve[i+1] << "\n";
			for(int i = 1 ; i < vo.size() ; i+=2) cout << vo[i] << " " << vo[i+1] << "\n";
		}
	}		
  return 0;
}
