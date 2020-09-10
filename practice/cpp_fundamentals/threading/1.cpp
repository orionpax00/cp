/*
 Just Checking thread library of cpp > 11 and comparing running time
 compile using -pthread: g++ -std=c++17 -pthread -o 1 1.cpp
 running time almost reduced to half 
*/


#include <bits/stdc++.h> // need threading module which is available above c++ 11
#define int long long
using namespace std;

void func(int l, int r){
		int sum_ = 0; int i = l;
		while(l < r){
			sum_ += l;
			l++;
		}
		cout << "from: " << i << " to: " << r << " : " << sum_ << "\n";
}

void singleThread(){
	func(0, 1000000000);
	func(0, 1000000000);
}

void MultiThread(){
	int l1 = 0, r1 = 1000000000;
	thread t1(func, l1, r1);
	thread t2(func, l1, r1);

	t1.join();
	t2.join(); // wait for the thread to complete

	return;
}

int32_t main(){
	singleThread();
	return 0;	
}

//run like time ./1 : to check how much time it take

