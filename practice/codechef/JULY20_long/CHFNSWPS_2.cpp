#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int t; cin >> t;
	while(t--){
		int n;
		cin >> n ;
		map<int , int> m;
		map<int , int> c;
		for(int i =0 ; i < n ; i++){
			int t; cin >> t; m[t]++; c[t]++; 
		}
		for(int i = 0 ; i < n ; i++){
			int t; cin >> t; m[t]--; c[t]++;
		}
		
		vector<int> v;
		int sum_ = 0;
		int tobe = 0;
		int m_ = INT_MAX;
		int gm_ = INT_MAX;
		bool isfound = false;
		for(auto x: m){
			if(x.second%2 != 0) {
				cout << -1 << "\n"; isfound = true; break;
			}
			else {
				if(x.second == 0) {
				  gm_ = min(gm_, x.first);
				}
				else{
//					cerr << "hi\n";
					sum_ += x.second;
					m_ = min(x.first, m_);
					tobe += abs(x.second);
				}
			}
		}
		cerr << m_ << " " << gm_ << "\n";
		if(!isfound){
			if(sum_ != 0){
				cout << -1 << "\n";
			}else{
				int ans = INT_MAX;
				int mans = INT_MAX;
				if(gm_ < m_){
					cerr << "yaa i got less:\n";
				  if(tobe == 0) ans =  0;
  				  int cofm_ = c[gm_];
  				  int tr = min((cofm_*2 + tobe)/4, cofm_);
  				  if(tr != 0 )
  				    mans = (cofm_/2 )* tr + (((tobe+cofm_*2)/2 -1)/(tr))*(tr * gm_) + (tr/2)*gm_;
  				  ans = min(ans , mans);
				}
				  int cofm_ = abs(m[m_]);
				  int tr = min(tobe/4, cofm_);
				  if(tr != 0)
  				  mans = ((tobe/2 - 1)/(tr))*(tr * m_) + (tr/2)*m_;
					cerr << ans << "  " << mans << "\n";
				  ans = min(ans , mans);

	    	cout << ans << "\n";
			}
		}
	}
  return 0;
}



