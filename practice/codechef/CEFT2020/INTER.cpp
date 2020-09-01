#include <bits/stdc++.h>
#define int long long

int MOD = 1e9 + 7; 

using namespace std;
int countDecodingDP(string digits) { 
	int n = digits.length();
    int count[n+1];  
    count[0] = 1; 
    count[1] = 1; 
    if(digits[0]=='0')   
         return 0; 
    for (int i = 2; i <= n; i++){ 
        count[i] = 0; 
  
        if (digits[i-1] > '0') 
            count[i] = count[i-1]; 

        if (digits[i-2] == '1' ||  (digits[i-2] == '2' && digits[i-1] < '7') ) 
            count[i] = (count[i] + count[i-2])%MOD; 
    } 
    return count[n]; 
} 

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		cout << countDecodingDP(s) << "\n";
	}
    

  return 0;
}
