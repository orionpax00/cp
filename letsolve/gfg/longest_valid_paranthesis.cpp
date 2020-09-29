#include <bits/stdc++.h>
using namespace std;

map<char char> m;
m['('] = ')';
m[')'] = '(';

int main(){
    int tt; cin >> tt;
    while(tt--){
        string s; cin >> s;
        stack<char> st;
        int ans = 0;
        st.push(s[0]);
        while(i < n){
            if(s[i] == '(') st.push(s[i]);
            else{
                if(st.top() == '('){
                    st.pop();
                    
                }
            }
        }
    }
    return 0;
}
