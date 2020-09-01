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

    T get(int x){ // sum of values in [0, x)
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
			if (pos + pw <= sz(s) && s[pos + pw-1] < _sum)
				pos += pw, _sum -= s[pos-1];
		}
		return pos;
	}
};

struct node{
    int a = ...; // don't forget to set default value

    inline void operator+=(node &other){
        ...
    }
};