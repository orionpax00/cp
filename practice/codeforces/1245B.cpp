#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  int t; cin>>t;
  while(t--){
    int n; cin >> n ;
    vector<int> v(3);
    for(int i=0; i<3;i++){
      cin>>v[i];
    }
    string s; cin >> s;
    map<char, int> m;
    for(char x: s) m[x]++;
    int sum = 0, i = 0;
    string ts = "SRP";
    for(char x : ts){
      sum += m[x] > v[i] ? v[i] : m[x];
      i++;
    }
    if(sum >= (n+1)/2){
        int a = v[0];
        int b = v[1];
        int c = v[2];
        cout << "YES" << '\n';
        string t;
        for (int i = 0; i != n; ++i)
        {
        	if (s[i] == 'S' && a)
        	{
        		t += 'R';
        		a--;
        	}
        	else if (s[i] == 'R' && b)
        	{
        		t += 'P';
        		b--;
        	}
        	else if (s[i] == 'P' && c)
        	{
        		t += 'S';
        		c--;
        	}
        	else
        		t += '_';
        }
        for (int i = 0; i != n; ++i)
        {
        	if (t[i] != '_')
        		continue;
        	
        	if (a)
        	{
        		t[i] = 'R';
        		a--;
        	}
        	else if (b)
        	{
        		t[i] = 'P';
        		b--;
        	}
        	else
        	{
        		t[i] = 'S';
        		c--;
        	}
        }
        cout << t << '\n';
    // }
    }else{
      cout<<"NO\n";
    }
  }
  return 0;
}