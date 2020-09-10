/*
 Checking various methods for creating threads
 1. passing function refrence to thread object
 2. using lamda function
*/

#include <bits/stdc++.h>
#define int long long

using namespace std;

// Simple function declaration and defination
void func(){
	cout << "Simply Declared Function\n";
}



void MultiThread(){
	thread t1(func);
	
	// Lambda function
	auto func2 = [&](){
		cout << "Lambda Function\n";
	};

	thread t2(func2);

	t1.join(); t2.join();

	return;
}

using namespace std;


int32_t main(){
	MultiThread();
	return 0;
}
