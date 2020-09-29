#include <bits/stdc++.h>
#define int long long

using namespace std;


template <typename T>
class fenwick{
public:
    vector<T> fenw;
    int n;

    fenwick(int _n) : n(_n){
        fenw.resize(n);
    }

    void modify(int x, T v){
        while (x < n){
            fenw[x] += v;
            x |= (x + 1);
        }
    }

    T get(int x){ // sum of values in [0, x]
        T v{};
        while (x >= 0){
            v += fenw[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }

    int lower_bound(long long _sum) {// min pos such that sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (_sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= size(fenw) && fenw[pos + pw-1] < _sum)
				pos += pw, _sum -= fenw[pos-1];
		}
		return pos;
	}
};



int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

  int n ; cin >> n;
	fenwick<int> fen(n + 1);
	for(int i = 0; i < n; i++){
		int t; cin >> t;
		fen.modify(i + 1, t);
	}

	int q; cin >> q;
	while(q--){
		string type; int a, b; cin >> type >> a >> b;

		if(type == "past") fen.modify(b, a);
		if(type == "present"){
			cout << (fen.get(b) - fen.get(a-1))  << "\n";
		}
		
	}



	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
