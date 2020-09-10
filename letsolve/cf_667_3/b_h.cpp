#include <bits/stdc++.h>
#define int long long
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
using namespace std;

int32_t main()
{
    FAST_IO;

    int t;
    cin >> t;
    while (t--)
    {

        int a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;

        if (a < b || (a == b && x < y)){  	
						int t = min(a - x, n);
						a -= min(a - x, n);
						n -= t;
           	if(n > 0 && b > y){
							t = min(b - y, n);
							n -= t;
							b -= t;
						}
        }
        else {
						int t = min(b - y, n);
						b -= t;
						n -= t;
						if(n > 0 && a > x){
							t = min(a - y, n);
							n -= t;
							a -= t;
						}	
        }

        cout << a*b << "\n";
    }
    return 0;
}
