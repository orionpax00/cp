#include <bits/stdc++.h>

using namespace std;

int32_t main(){

	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int t; cin >> t;

	while(t--){
		int n;
		cin >> n ;
		map < int , int > m;
		for(int i = 0 ; i < n ; i++){
			int t; cin >> t; m[t]++;
		}

		for(int i = 0 ; i < n ; i++){
			int t; cin >> t ; m[t]--;
		}
		int gm_ = INT_MAX;
		int m_  = INT_MAX;
		bool notpos = false;
		int tobe = 0;
		int sum_ = 0;

		for(auto x: m){
			if(x.second%2 != 0){
				notpos = true; break;
			}

			gm_ = min(gm_, x.first);
			if(x.second != 0){
				m_ = min(m_, x.first);
				tobe += abs(x.second);
				sum_ += x.second;
			}

		}	

		cerr << gm_ << " " << m_ << " " << tobe << " " << sum_ << " " <<notpos << "\n";
		if(!notpos){
			int ans = INT_MAX;
			if(sum_ != 0){
				cout<<-1 << "\n";
				break;
			}
			if(gm_ < m_){	
				int cofgm = min(abs(m[gm_]) + 2, (tobe+4)/4);
				ans = gm_ * ( 1 + (tobe+4)/2 - (cofgm + 1)/2);
			}
			int cofm = min(abs(m[m_]), tobe/4);

			int mans = m_*(tobe/2 - (cofm + 1)/2);
			
			cerr << ans << " " << mans << "\n";
			ans = min(ans, mans);
			
			cout << ans << "\n";
		}
		else{
			cout << -1 << "\n";
		}

	}
	return 0;
}



