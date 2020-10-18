#include <bits/stdc++.h>

using namespace std;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
//void __print(graph::edge x) {cerr << "{" << x.from << "," << x.to << "," << x.cost <<"}";}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";
}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


// Complete the maxRegion function below.
int maxRegion(vector<vector<int>> g) {
    int r = g.size(); int c = g[0].size();
    vector<vector<int>> vis(r, vector<int>(c,0));
    auto issafe = [&](int x, int y){
        return x >= 0 && y >= 0 && x < r && y < c && g[x][y] == 1;
    };

    pair<int, int> dirs[8] = {{-1, 0},{1, 0},{0, -1},{0, 1}, {-1, -1},{1, 1},{1, -1},{-1, 1}};
    stack<pair<int, int>> s;
    int ans  = 0;
    for(int i=0; i < r; i++){
        for(int j = 0 ; j < c; j++){
            int tans = 0;
            if(!vis[i][j] && g[i][j]){
                s.push({i,j}); 
                vis[i][j] = 1;
            } 
            while(!s.empty()){
                pair<int, int> v = s.top();
                s.pop();
								tans++;
								debug(v);
                int cx = v.first;
                int cy = v.second;
                for(pair<int, int> dir: dirs){
                    int dx = dir.first;
                    int dy = dir.second;
                    if(issafe(cx + dx, cy + dy) && !vis[cx + dx][cy + dy]){
                        s.push({cx + dx, cy + dy});
                        vis[cx + dx][cy + dy] = 1;
                       // tans++;
                    }
                }
            }
						cerr << "=--------\n"; 
            ans = max(ans, tans);
        }
    }

    return ans;
}

int main()
{
//    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int res = maxRegion(grid);

    cout << res << "\n";

    //fout.close();

    return 0;
}
