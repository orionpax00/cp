#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  //naive algorithm
  int t;
  cin>>t;
  while(t--){
        
        int size_, Z;
        cin>>size_>>Z;
        int a[size_];
        for(int i=0;i<size_;i++){
            cin>>a[i];
        }
        
        int J,K;
        for(int i=0; i<size_;i++){
        bool ans=false;
        for(int j=0;j<size_-i;j++){
          int sum=0;
          for(int k=j;k<=j+i;k++) {
            sum+=a[k];
          }
          if (sum>=Z) {J=j;K=j+i;ans=true;break;}
        }if(ans)break;
      }
      cout<<K-J+1<<"\n";
  }

  return 0;
}