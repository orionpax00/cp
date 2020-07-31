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

		while (s.empty() == false && arr[s.top()] < arr[i]) 
    {          
        ans[s.top()] = i; 
        s.pop(); 
    } 
  
    s.push(i); 
  }
	
	while (s.empty() == false) { 
		ans[s.top()] = -1;
    s.pop(); 
  }

	return ans; 
} 

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	vector<int> v = {3, 1, 4, 1, 9};
	map<int, int> m = nge(v);
	for(auto x : m) {
		cout << x.first << " " << x.second << "\n";
	}

  return 0;
}
