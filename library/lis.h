template <typename T>
int lis(const vector<T> &a) {
  vector<T> u;
  for (const T &x : a) {
    auto it = lower_bound(u.begin(), u.end(), x);
    if (it == u.end()) {
      u.push_back(x);
    } else {
      *it = x;
    }
  }
  return (int) u.size();
}

template<typename T>
int lisdp(const vector<T> &a){
	int n = a.size()
	vector<int> lis_(n, 1);
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			if(a[i] > a[j]){
				lis_[i] = max(lis_[i], lis_[j] + 1);
			}
		}
	}
	return *max_element(lis_.begin(), lis_.end());
}
