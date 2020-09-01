#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

 	int h, w, mi; cin >> h >> w >> mi;
	vector<pair<int,int>> vh(h+1);
	vector<pair<int,int>> vw(w+1);
	
	for(int i = 0; i <= h; i++) vh[i].second = i;
	for(int i = 0; i <= w; i++) vw[i].second = i;

	map<pair<int, int>, int> m;
	
	for(int i=0; i < mi; i++){
		int h1, w1;	cin >> h1 >> w1;    
		vh[h1].first++; vw[w1].first++;
		m[make_pair(h1, w1)]++;
	}

	sort(vh.rbegin(), vh.rend());
	sort(vw.rbegin(), vw.rend());


	//for(int i = 0 ; i < (int)vh.size(); i++) cout << vh[i].second << " -- " << vh[i].first << "\n"; 
	//for(int i = 0 ; i < (int)vw.size(); i++) cout << vw[i].second << " -- " << vw[i].first << "\n"; 
	
	
	int max_ = vh[0].first + vw[0].first;
	int i = 0;
	bool isless = false;
	int sh = vh[0].first, sw = vw[0].first;
	while(vh[0].first == sh && vw[i].first == sw){
	//	cout << "counter: " << i << "\n"; 
		if(m.count(make_pair(vh[0].second, vw[i].second)) == 0 ) isless = true; 
		i++;
	}
	i = 0;
	while(vh[i].first == sh && vw[0].first == sw){
	//	cout << "counter: " << i << "\n"; 
		if(m.count(make_pair(vh[i].second, vw[0].second)) == 0 ) isless = true; 
		i++;
	}
	i = 0;	
	while(vh[i].first == sh && vw[i].first == sw){
//		cout << "counter: " << i << "\n"; 
		if(m.count(make_pair(vh[i].second, vw[i].second)) == 0 ) isless = true; 
		i++;
	}

	if(isless) cout << max_;
	else cout << max_ - 1;

  return 0;
}
