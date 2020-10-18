#include <bits/stdc++.h>

using namespace std;


int sortedSubsegments(int k, vector<int> a, vector<vector<int>> queries) {
    int n = a.size(); int q = queries.size();
    vector<int> diff(n + 1);    for(int i = 0 ; i < q ; i++){
      sort(a.begin() + queries[i][0], a.begin() + queries[i][1] + 1);
    }

		return a[k];
}


int main(){
		
	int n, q, k; cin >> n >> q >> k;

	vector<int> v(n);
	for(int& x : v) cin >> x;
	vector<vector<int>> qw(q, vector<int>(2));

	for(auto& x : qw) cin >> x[0] >> x[1];

	cout << sortedSubsegments(k, v, qw);


	return 0;
}



















