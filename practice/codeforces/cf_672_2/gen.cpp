#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b){
	return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]){
	srand(atoi(argv[1]));
	int n = rand(1, 100);
	cout << 1 << " " << n << "\n";

	for(int i = 0 ; i < n ; i++){
		int t = rand(0, 1000000000);
		cout << t << " ";
	}cout << "\n" ;


	return 0;
}
