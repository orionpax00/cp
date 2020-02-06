#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string str = "{\"group\" : {\"list\" : [1,2,3]}, \"list\" : [\"a\",\"b\",\"c\"], \"durgesh\":\"hi\"}";

  int whts =0;
  for(int i =0; i<str.size(); ++i){
   if(str[i] == '{'){cout<<"{\n";whts++;for(int j=0;j<whts;++j)cout<<"  ";continue;}
   else if(str[i] == '['){cout<<"[\n";whts++;for(int j=0;j<whts;++j)cout<<"  ";continue;}
   else if(str[i] == ','){cout<<",\n";for(int j=0;j<whts;++j)cout<<"  ";continue;}
   else if(str[i] == ']'){cout<<"\n";whts--;for(int j=0;j<whts;++j)cout<<"  ";cout<<"]";continue;}
   else if(str[i] == '}'){cout<<"\n";whts--;for(int j=0;j<whts;++j)cout<<"  ";cout<<"}";continue;}
   else{
     cout<<str[i];
   }
  }

  return 0;
}