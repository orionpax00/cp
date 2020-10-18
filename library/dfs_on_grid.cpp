auto issafe = [&](int x, int y){
	return x >= 0 && y >= 0 && x < r && y < c;
}

pair<int, int> dirs[4] = {{-1, 0},{1, 0},{0, -1},{0, 1}};
//pair<int, int> dirs[8] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};
stack<pair<int, int>> s;
... // add initial logic like starting point... 
while(!s.empty()){
	pair<int, int> v = s.top();
	s.pop();
	int cx = v.first;
	int cy = v.second;
	for(pair<int, int> dir: dirs){
		int dx = dir.first;
		int dy = dir.second;
		if(issafe(cx + dx, cy + dy) && !vis[cx + dx][cy + dy] && ... ){ 
			s.push({cx + dx, cy + dy});
			vis[cx + dx][cy + dy] = 1;
		}
	}
}
