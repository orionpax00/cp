//How will there be a floating point error? And how will b=b*100+0.01 save from it?

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long a;
	float b; 
	cin>>a>>b;

	int B = b*100 + 0.01;
	long long ans = (a * B) / 100;

	cout << ans;


  return 0;
}
