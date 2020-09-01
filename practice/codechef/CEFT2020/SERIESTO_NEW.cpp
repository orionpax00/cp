#include <bits/stdc++.h>
#define int int64_t

using namespace std;
int xnor(int a, int b) 
{ 
    // Make sure a is larger 
    if (a < b) 
        swap(a, b);  
  
    if (a == 0 && b == 0)  
        return 1;  
  
    int a_rem = 0; // for last bit of a 
    int b_rem = 0; // for last bit of b 
  
    // counter for count bit  
    // and set bit  in xnornum 
    int count = 0;  
  
    // to make new xnor number 
    int xnornum = 0; 
  
    // for set bits in new xnor number 
    while (a)  
    { 
        // get last bit of a 
        a_rem = a & 1;  
  
        // get last bit of b 
        b_rem = b & 1;  
  
        // Check if current two 
        // bits are same 
        if (a_rem == b_rem)         
            xnornum |= (1 << count); 
          
        // counter for count bit 
        count++;  
        a = a >> 1; 
        b = b >> 1;  
    } 
    return xnornum; 
} 

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while(t--){
		int a, b, n ; cin >> a >> b >> n;
		
		if(b > a) swap(a, b);
		int sh_ = 63 - __builtin_clzll(a);
		int t = 1 << sh_;
		if((b & t) == 0) {
				cout << a << " " << b <<"\n";
				cout << xnor(a, b);
		}else{
			cout << (a ^ b);
		}
		cout  << "\n";
	}
    

  return 0;
}
