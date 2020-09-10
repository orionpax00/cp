#include <bits/stdc++.h>
//#define int long long

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
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif



map<string, vector<vector<int>>> m;
map<string, vector<int>> ms;

vector<int> tokenize(string s){
	stringstream ss(s);
	string word;
	vector<int> res;

	while(ss >> word) res.push_back(stoi(word));

	return res;
}

string add_screen(string screen, string s){
	if(m.count(screen)) return "failure";
	vector<int> seats = tokenize(s);
	debug(seats);
	vector<vector<int>> v(seats[0], vector<int>(seats[1]));
	vector<int> vt((int) seats[1]);

	for(int i = 2; i < (int) seats.size(); i++){
		vt[--seats[i]]++;
	}	

	m[screen] = v;
	ms[screen] = vt;

	return "success";
}

string reserve_seat(string screen, string seat){
	vector<int> seats = tokenize(seat);
	int row = --seats[0];
	int n = seats.size();
	for(int i = 1; i < n; i++){
		if(m[screen][row][--seats[i]] != -1 && m[screen][row][seats[i]])  return "failure";
	}
	for(int i=1; i < n; i++){
		m[screen][row][seats[i]] = 1;
	}

	return "success";
}


vector<int> get_unres(string screen, int row){
	vector<int> ans;
	int counter = 1;
	debug(m[screen]);
	for(int i : m[screen][row]){
		if(!i) ans.push_back(counter);
		counter++;
	}

	return ans;
}

vector<int> suggest(string screen, int num_seats, int row, int c){
	vector<int> ans;
	int n = m[screen][row].size();
	for(int i = c; i < n && i < c + num_seats; i++){
			if(!m[screen][row][i] && !ms[screen][i])
				ans.push_back(i+1);
	}
	int size = ans.size();
	debug(ans);
	if(size < num_seats) ans.clear();
	else return ans;
	for(int i = c; i >= 0 && i > c - num_seats; i--){
			if(!m[screen][row][i] && !ms[screen][i])
				ans.push_back(i+1);
	}
	debug(ans);
	return ans;
}



int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int commands; cin >> commands;
	while(commands--){
		string ty, sc; cin >> ty >> sc;
		if(ty == "add-screen"){
			string st; getline(cin, st);
			cout << add_screen(sc, st) << "\n"; 
		}
		else if(ty == "reserve-seat"){
			string st; getline(cin, st);
			cout << reserve_seat(sc, st) << "\n";
		}
		else if(ty == "get-unreserved-seats"){
			int row; cin >> row; --row;
			vector<int> v = get_unres(sc, row);
			for(int i : v) cout << i << " ";
			cout << "\n";
		}
		else if(ty == "suggest-contiguous-seats"){
			int n, r, c; cin >> n >> r >> c; --r; --c;
			vector<int> sug = suggest(sc, n, r, c);
			if((int)sug.size() < n) cout << "none\n";
			else{
				for(int i : sug) cout << i << " ";
				cout << "\n";
			}
		}
		else{
			cerr << "Command Not Found";
		}
	}


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
