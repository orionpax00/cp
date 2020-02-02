#include <bits/stdc++.h>

using namespace std;

void JsonParse(string& str1, string& str2){
  str1 = str1.substr(1, str1.length());
  str2 = str2.substr(1, str2.length());

  int a =1;
  int b =1;

  while(a > 0){
      a = str1.find(",");
      b = str2.find(",");


      string sub_str1 = str1.substr(0, a);
      int a1 = sub_str1.find(":");

      cout<<sub_str1;

      string sub_str2 = str2.substr(0, b);
      int b1 = sub_str2.find(":");

      cout<<" "<<sub_str1;

      cout<<sub_str1.substr(a1+2, a - a1 - 3)<< " ";
      cout<<sub_str2.substr(b1+2, b - b1 - 3);

      if(sub_str1.substr(a1+2, a - a1 - 3) == sub_str2.substr(b1+2, b - b1 - 3)) {str1.erase(0,a); str2.erase(0,b) ;}
      else{cout<<sub_str2.substr(b1+2, b - b1 - 3); str1.erase(0,a); str2.erase(0,b);};

      cout<<a;
  }
}
int main(){
  string input = "{\"Geeks\":\"Test1\",\"Are\":\"hey\",\"Cool\":\"yeah\"}";
  string input2 = "{\"Geeks\":\"Test1\",\"Are\":\"20\",\"Cool\":[2,12]}";

  JsonParse(input, input2);

}