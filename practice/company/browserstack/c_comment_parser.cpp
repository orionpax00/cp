#include <bits/stdc++.h>

using namespace std;

string removeComments(string code){
  
  int mComment = 0;
  int sComment = 0;
  string str_ = "";
  for (int i = 0; i < code.length(); ++i){
    if(code.substr(i, 2) == "//") {sComment = 1;continue;}
    else if(code.substr(i, 2) == "/*") {mComment = 1; continue;}
    else if(code.substr(i, 1) == "\n" && sComment) {sComment = 0; i+=1; continue;}
    else if(code.substr(i, 2) == "*/" && mComment) {mComment = 0; i+=1 ; continue;};
    if(!mComment && !sComment) str_ += code[i];
  }

  return str_;

}
int main(){

  string str = "   /* Test program */ \n"
                  "   int main()  \n"
                  "   {           \n"
                  "      // variable declaration \n"
                  "      int a, b, c;    \n"
                  "      /* This is a test  \n"
                  "          multiline     \n"
                  "          comment for   \n"
                  "          testing */      \n"
                  "      a = b + c;       \n"
                  "   }           \n"; 

  cout<<removeComments(str)<<endl;  
  return 0;

}