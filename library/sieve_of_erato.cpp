//Sieve of erotosthenes
template<typename T>
vector<T> sie(T n){
	vector<T> v(n+1,0);
	v[0] = 1;
	v[1] = 1;
	for(T i = 2 ; i*i <= n; i++){
		if(!v[i]){
			for(T j = i*i ; j <= n ; j+=i){
				v[j] = 1;
			}
		}
	}
	return v;
}

