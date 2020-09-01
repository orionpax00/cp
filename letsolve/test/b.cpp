#include <bits/stdc++.h>
#define int long long

using namespace std;

template <class Container>
void split2(const std::string& str, Container& cont, char delim = ' ')
{
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        cont.push_back(token);
    }
}

int ans(vector<char> v, string s){
	vector<string> spliteds;
	split2(s, spliteds);
	map<char, int> m;
	for(auto x : v) m[tolower(x)]++;

	bool flag = true;
	int ans_ = 0; 
	for(auto x : spliteds){
		flag = true;
		for(char c : x){
			if(m.count(tolower(c)) != 0){ flag = false; break;}
		}
		if(flag) ans_++;
	}
	return ans_;
}


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n ; cin >> n;
	vector<char> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];     

	string s ; cin >> s;
	cout << ans(v, s);


  return 0;
}
