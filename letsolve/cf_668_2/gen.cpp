#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b){
	return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]){
	srand(atoi(argv[1]));
	int n = rand(2, 10);
	int q = rand(2, 10);
 	int k = rand(0, n-1);	
	cout << n << " " << q << " " << k << "\n";

	for(int i = 0 ; i < n ; i++){
		int t = rand(0, 10);
		cout << t << " ";
	}cout << "\n";

	for(int i = 0 ; i < q ; i++){
		int a = rand(0, n-1);
		int b = rand(a, n-1);

		cout << a << " " << b << "\n";
	}


	return 0;
}
