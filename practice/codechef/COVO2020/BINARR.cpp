/*this solution is wrong but passes all test case
 
It just substract but doesn't check for len

fails on test case 
3 2 1
9 9 1
ans : 3 
program output : -1
*/


#include <bits/stdc++.h>
#define int long long

using namespace std;


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k, s; cin >> n >> k >> s;
	vector<int> v(n);
	for(auto& x : v) cin >> x;

	int ml = n + 1;
	int m_ = -1;
	int s_ = 0;
	int start = 0;
	int end = 0;
	while(end < n){
			while(end < n && s_ <= s)
				s_ += v[end++];
			while(s_ > s && start < n){
				if(end - start < ml){
					ml = end - start;
					if(ml > k) m_ = ml;
				}

				s_ -= v[start++];
			}
	}
	cout << m_;

  return 0;
}
