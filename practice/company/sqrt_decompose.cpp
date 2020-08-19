#include <bits/stdc++.h>
#define int long long

using namespace std;

template<typename T>
class sqrtDecomposition {
	public:
	vector<T> v;
	int len;
	sqrtDecomposition(const vector<T>& vi) {
		len = (int)sqrt(vi.size() + .0) + 1;
		v.resize(len);
		for(int i = 0 ; i < vi.size(); i++){
			v[i/len] += vi[i]; // summation due to sum queries
		}
	}
	
	T query(const pair<int, int>& p){
		int sum = 0;	
		//this method of computation is slow due to so
		//much divisions involved
		for(int i = p.first; i <= p.second; ){
			if(i%len == 0 && i + len - 1 <= r){
				sum += v[i/len]; i += len;
			}else{
				sum += a[i]; i++;
			}
		}
		return sum;
	}
} 

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

    

  return 0;
}
