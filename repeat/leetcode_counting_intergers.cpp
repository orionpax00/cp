//	
//	array
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countElements(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int f = arr[0];
        int counter1 = 1;
        int counter2 = 0;
        int ans=0;
        for(int i=1; i<arr.size(); i++){
            if(arr[i] != f) {
                if(arr[i]-f == 1){
                    int j =i;
                    while(arr[j] == arr[i]){
                        counter2++;
                        j++;
                    }
                    i=j;
                    ans+= (counter1+counter2)/2;
                }
                counter1 = 1;
                counter2 = 0;
                f = arr[i];
            }else{
                counter1++;
            }
        }
        return ans;
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  
  return 0;
}