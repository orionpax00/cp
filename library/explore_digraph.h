template<typename T>
class exp_graph : public digraph<T>{
  public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;
  using graph<T>::ignore;

  vector<T> d; //1e9
  vector<int> p;
  vector<int> neg_cycle;
  int INF = 1000000000;
  bool isnegative_cycle = false;

  exp_graph(int _n) : digraph<T>(_n) {}

  void dijkstra(int u){
    d.assign(n, INF); //1e9
    p.assign(n, -1);

    d[u] = 0;
    priority_queue< pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>> > q;
    q.push({0, u});
    while(!q.empty()){            
      int v = q.top().second;
      T d_v = q.top().first;
      q.pop();

      if(d_v != d[v]) continue;

      for(auto edge_id: g[v]){
        auto &e = edges[edge_id];
        int to = e.from ^ e.to ^ v;
        if(d[v] + e.cost < d[to]){
          d[to] = d[v] + e.cost;
          p[to] = v;
          q.push({d[to], to});
        }
      }
    }
  }

  void bellman_ford(int u){
    //init
    d.assign(n, INF); //1e9
    p.assign(n, -1);

    d[u] = 0;
    int x;
    for(int i = 0 ; i < n ; i++){
      x = -1;
      for(int j = 0; j < (int)edges.size(); j++){
        auto &e = edges[j];
        if(d[e.from] < INF){
          int to = e.from ^ e.to ^ i;
          if(d[to] > d[e.from] + e.cost){
            d[to] = max(-INF, d[e.from] + e.cost);
            p[to] = e.from;
            x = to;
          }
        }
      }
    }
    if(x != -1) isnegative_cycle = true;
    else{
      int y = x;
      for(int i = 0; i < n; i++) y = p[y];
      for(int curr = y; ;curr = p[curr]){
        neg_cycle.push_back(curr);
        if(curr == y && neg_cycle.size() > 1) break;
      }
      reverse(neg_cycle.begin(), neg_cycle.end());
    }
  }


  vector<int> restore_path(int s, int t) {
    vector<int> path;
    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
    return path;
  }

  vector<int> toposort(){
    vector<int> deg(n, 0);
    for (int id = 0; id < (int) edges.size(); id++) deg[edges[id].to]++;

    vector<int> x;
    for (int i = 0; i < n; i++) 
      if (deg[i] == 0) 
        x.push_back(i);
      
    for (int ptr = 0; ptr < (int) x.size(); ptr++) {
      int i = x[ptr];
      for (int id : g[i]) {
        auto &e = edges[id];
        int to = e.to;
        if (--deg[to] == 0) 
          x.push_back(to);
      }
    }

    if ((int) x.size() != g.n) 
      return vector<int>();
    
    return x;
  }
  

};
