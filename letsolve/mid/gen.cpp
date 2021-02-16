#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b){
	return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]){
	srand(atoi(argv[1]));
	int n = rand(10, 50);
	int m = rand(10, 50);
	cout << n + m << "\n";

	vector<int> tmp1;
	for(int i = 0 ; i < n ; i++){
		int t = rand(0, 100);
		tmp1.push_back(t);
	}

	vector<int> tmp2;
	for(int i = 0; i < m; i++){
		int t = rand(0, 100);
		tmp2.push_back(t);
	}

	int x1 = rand(1, n - 1);
	int x2 = rand(1, m - 1);
	sort(tmp1.begin(), tmp1.end());
	sort(tmp2.begin(), tmp2.end());
	
	reverse(tmp1.begin() + x1, tmp1.end());
	reverse(tmp2.begin() + x2, tmp2.end());


	for (int x : tmp1) cout << x << " ";
	for (int x: tmp2) cout << x << " ";
	cout << "\n";
	
	
	return 0;
}
