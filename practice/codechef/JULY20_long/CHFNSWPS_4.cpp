#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){

	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int t; cin >> t;

	while(t--){
		int n;
		cin >> n ;
		map < int , int > m , m2;
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
				tobe += abs(x.second)/2;
				sum_ += x.second;
				m2[x.first] = x.second;
			}

		}	

		cerr << gm_ << " " << m_ << " | tobe: " << tobe << " sum: " << sum_ << "| " <<notpos << "\n";
		if(!notpos){
			int ans = INT_MAX;
			int ct = 0;
			if(gm_ < m_){	
				ans = gm_ * (tobe);
				for(int i = gm_ + 1; i < 2 * gm_ && ct < tobe; i++){
					if(m.count(i) != 0){
						int t_ = min(abs(m[i]) , tobe - ct);
						ans -= gm_ * t_;
						ans += (t_/2) * i ;
						ct += t_;
					}
				}  
			}

			if(m.count(m_) != 0 ){
				int cofm = abs(m[m_]);
	
				int mans = m_*(cofm/2 + (tobe - cofm));
				int c = cofm;  
				for(int i = m_ + 1; i < 2 * m_ && c < tobe; i++){
					if(m.count(i) != 0){
						int t_ = min(abs(m[i]), tobe - c);
						cerr << "mi : " << t_  << " c :" << c << "\n";
						mans -= m_ * t_;
						mans += (t_/2) * i;
						c += t_;
					}
				}  
				
				cerr << ans << " " << mans << "\n";
				ans = min(ans, mans);
			}
				cout << ans << "\n";
		}
		else{
			cout << -1 << "\n";
		}
		

	}
	return 0;
}



