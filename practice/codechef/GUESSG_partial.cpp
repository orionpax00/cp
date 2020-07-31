#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

 	int n ; cin>>n;
	int left = 1;
	int right = n;
	int last_left = 1;
	int last_right = n;
	char lastans = 'A';

	while(true){
		int tn = (right+left)/2;
		cout<<tn<<endl;
		char ans; cin>>ans;
		if(ans == 'E') {cout<<tn; break;}
		else if(ans == 'G' && lastans == 'L') {
				last_left = left;
				left = tn + 1;
				right = last_right;	
		}else if(ans == 'L' && lastans == 'G'){
				last_right = right;
				right = tn - 1;
				left = last_left;
		}else if(ans == 'L') {
				last_right = right;
				right = tn - 1;
		}
		else {
			last_left = left;
			left = tn+1;
		}
		lastans = ans;
	}	   

  return 0;
}
