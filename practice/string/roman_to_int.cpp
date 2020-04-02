/*
*   Author - Durgesh(orionpax00)
    Some legends are told
        Some turn to dust or to gold
            But you will remember me
                Remember me for centuries...
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds; 
#define fr(i,o,n) for(int i = o; i <= n; i++)
#define rep(i,o,n) for(int i = o; i < n; i++)
#define replli(i,o,n) for(long long int i = o; i < n; i++)
#define trav(x,a) for(auto &x : a)
#define lli long long int
#define mod 1000000007
#define pb push_back
#define local false


string removeSpaces(string str) 
{ 
    stringstream ss; 
    string temp; 
  
    /* Storing the whole string into string stream */
    ss << str; 
  
    /* Making the string empty */
    str = ""; 
  
    /* Running loop till end of stream */
    while (!ss.eof()) 
    { 
        /* extracting word by word from stream */
        ss >> temp; 
  
        /* concatenating in the string to be 
          returned*/
        str = str + temp; 
    } 
    return str; 
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int durgesh = 00;

    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);


    // auto start = chrono::high_resolution_clock::now();
    // auto stop = chrono::high_resolution_clock::now();
    
    map<char , int> value;
    value['I']= 1;
    value['V']= 5;
    value['X']= 10;
    value['L']= 50;
    value['C']= 100;
    value['D']= 500;
    value['M']= 1000;
    
    map<char, char> prevalue;
    prevalue['V'] = 'I';
    prevalue['X'] = 'I';
    prevalue['L'] = 'X';
    prevalue['C'] = 'X';
    prevalue['D'] = 'C';
    prevalue['M'] = 'C';
    // getline(cin, A);

    string roman = "MDCCCIV";
    int sum = 0;
    // cout<<roman.length() - 1;

    for (int i = roman.length() - 1; i >= 0; i--){
        char roman_i = roman[i];
        cout<<i<<endl;

        sum += value[roman_i];
        cout<<value[roman_i]<<endl;
        cout<<sum<<endl;
        

        if(i){
            if(roman[i-1] == prevalue[roman_i]) {
                cout<<"---------"<<endl;
                cout<<value[roman[i-1]]<<endl;
                sum -= value[roman[i-1]];i++;
            }
        }
    }
  
    cout<<sum;
    
    return 0;
}
