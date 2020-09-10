template<typename T>
class prefixSumArray {
    vector<T> v;

    public:
    prefixSumArray(vector<T>& vi) {
        int n = vi.size();
        v.resize(n+1);
        v[0] = 0;
        for(int i = 0 ; i < n ; i++) v[i + 1] = v[i] + vi[i];
    }

    int query(pair<int, int> p){
        return v[p.second] - v[p.first - 1]; // query has 1 based indexing
    }
};
