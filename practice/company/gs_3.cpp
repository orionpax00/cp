#include <bits/stdc++.h>
//#define int long long

using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);	

	string s1, s2; cin >> s1 >> s2;
	vector<int> v1(135);
	vector<int> v2(135);
	
	for(char c : s1) v1[c - ' ']++;
	for(char c : s2) v2[c - ' ']++;

	for(int i = 0 ; i < 135; i++){
		if(v1[i] != v2[i] && ' ' + i != '@') {
			cout << "False" ; return 0;	
		}
	}
	cout << "True";
  

  return 0;
}
