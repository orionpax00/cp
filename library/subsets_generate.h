vector<vector<int>> ans;
vector<int> ss;
vector<int> v;
int N;

void solve(int idx){
	ans.push_back(ss);
	for(int i = idx; i < N; i++){	
		ss.push_back(v[i]);
		solve(i + 1);
		ss.pop_back();
	}
	return;
};

void solvedp(){
	for(int i = 0; i < (1 << N); i++){
		vector<int> vt;
		for(int j = 0; j < N; j++){
			if((i & (1 << j)) != 0) vt.push_back(v[j]);
		}
		ans.push_back(vt);
	}
}