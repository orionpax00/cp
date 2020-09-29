#include <bits/stdc++.h>
#define int long long

using namespace std;

#include "../trie.h"

map<string, int> m;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cout << "********************************\nSimple Search\n********************************\n";

	Trie trie;
	vector<string> dict = { "the", "a", "there", 
                    "answer", "any", "by", 
                    "bye", "their", "hero", "heroplane" };
	for(string x : dict) trie.insert(x);
	
	cout << trie.search("the") << "\n";
	cout << trie.search("durgesh") << "\n";

	// output should be 1 and 0;


	cout << "********************************\nPrefix Search Testing\n********************************\n";

	// testing prefix search
	Trie t;
	int n, q; cin >> n >> q;
	for(int i =0; i < n; i++){
		string s; cin >> s;
		t.insert(s);
		m[s]++;
	}
	for(int i = 0; i < q; i++){
		string s; cin >> s;
		t.prefixResults.clear();
		int res = t.prefixSearch(s);
		if(res == 1){
			int ans = 0;
			for(string x: t.prefixResults) ans += m[x];
			cout << ans << "\n";
		}else if(res == -1){
			cout << 1 << "\n";
		}else{
			cout << 0 <<"\n";
		}
	}



	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}

/*Prefix Search
	sample input 
	12 6
	bulldog
	dog
	dogged
	doggedly
	doggerel
	dogma
	dogmatic
	dogmatism
	dogs
	catastroph
	catastroph
	doctor
	cat
	dog
	dogg
	do
	doctrinography
	dogge

	output
	2
	8
	3
	9
	0
	3

command to test 
diff -w <(./trie < trie_in) ./trie_ans	
*/