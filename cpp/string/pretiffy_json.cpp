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
    
    // string A = "{A:'B',C:{D:'E',F:{G:'H',I:'J'}}}";
    string A = "['foo', {'bar':['baz',null,1.0,2]}]";
    
    // getline(cin, A);
    vector ans;
    bool first = true;
    int counter = 0;
    string B = "";
    for(auto x : A){
            
            if(x == ','){B += ",\n"; for(int i=0; i<counter;i++){B+="\t";}; ans.push_back(B)}
            else if(x == '{'){ B += "\n";for(int i=0; i<counter;i++){B+="\t";}; B+="{\n"; for(int i=0; i<=counter;i++){B+="\t";}; counter++;}
            else if(x == '}'){counter--; B+="\n"; for(int i=0; i<counter;i++){B+="\t";}; B += "}\n";}
            else if(x == '['){ B += "\n";for(int i=0; i<counter;i++){B+="\t";}; B+="[\n"; for(int i=0; i<=counter;i++){B+="\t";}; counter++;}
            else if(x == ']'){counter--; B+="\n"; for(int i=0; i<counter;i++){B+="\t";}; B += "]\n";}
            else{B+=x;}
    }

    cout<<B.substr(1, B.length() - 2);
    
    
    return 0;
}
