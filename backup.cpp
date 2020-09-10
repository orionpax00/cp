class Solution {
private:

public:
    string decodeString(string str) {
        stack<pair<string, int>> s;        
        int n = str.length();
        s.push({"", 1});
        
        for(int i = 0 ; i < n;){
            string count = "";
            while(isdigit(str[i])){
                count += str[i];
                i++;
                if(i >= n) break;
            }
            
            if(i >= n) break;
            
            if(str[i] == ']'){
                pair<string, int> te = s.top();
                s.pop();
                pair<string, int> te2 = s.top();
                
                for(int j = 0; j < te.second; j++){
                    te2.first += te.first;
                }
                
                // cout << i << " " << te.second << " "<< te2.first << " " << te.first << "\n";
                
            } else if(str[i] == '['){
                // cout << i << " " << count << "\n"; 
                pair<string, int> te2 = s.top();
                cout << i << " " << te2.first << "\n";
                s.push({"", stoi(count)});
            } else{
                s.top().first += str[i];
            }
            
            i++;
        }
        
        return s.top().first;
    }
};
