#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int m;
        cin>>n;
        cin>>m;
        int arr[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>arr[i][j];
            }
        }
        int k;
        cin>>k;
        
        map<int,pair<int,int>>maps;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
            { 
                 int top_left = (i + 1) * (j + 1);
                 int bottom_right = (n - i) * (m - j); 
                 maps.insert({top_left * bottom_right*arr[i][j],{top_left * bottom_right, arr[i][j]}});
                
                
            } 
         long long  sum=0;
				 map<int, pair<int,int>>:: reverse_iterator it;
         for (it = maps.rbegin(); it != maps.rend(); it++) 
         {
            if(k>0)
            {
                if(*it.second.second<=k)
                {
                    k-=*it.second.second;
                    *it.second.second=0;
                }
                else
                {
                    *it.second.second-=k;
                    k=0;
                }
                sum+=(*it.second.first * *it.second.second);
                sum%=1000000007;

            }
            else
            {
                sum+=*it.first;
                sum%=1000000007;
            }
         }
         cout<<sum%1000000007<<endl;
            
    }
    // your code goes here
    return 0;
}
