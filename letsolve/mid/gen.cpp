#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b){
	return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]){
	srand(atoi(argv[1]));
	int n = rand(10, 50);
	int m = rand(10, 50);
//	cout << n + m << "\n";

	set<int> tmp1;
	for(int i = 0 ; i < n ; i++){
		int t = rand(0, 100);
		tmp1.insert(t);
	}

	set<int> tmp2;
	for(int i = 0; i < m; i++){
		int t = rand(0, 100);
		tmp2.insert(t);
	}

	int x1 = rand(1, tmp1.size() - 1);
	int x2 = rand(1, tmp2.size() - 1);
//	sort(tmp1.begin(), tmp1.end());
//	sort(tmp2.begin(), tmp2.end());
	
	vector<int> vtmp1;
	vector<int> vtmp2;
	for(int x: tmp1) vtmp1.push_back(x);
	for(int x: tmp2) vtmp2.push_back(x);

	reverse(vtmp1.begin() + x1, vtmp1.end());
	reverse(vtmp2.begin() + x2, vtmp2.end());

	cout << tmp1.size() + tmp2.size() << "\n";
	for (int x : vtmp1) cout << x << " ";
	for (int x: vtmp2) cout << x << " ";
	cout << "\n";
	
	
	return 0;
}
