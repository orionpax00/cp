#include <iostream>
#include <string.h>


using namespace std;

int counter_(string n,  char a){
    
    int count = 0;
    for (int i=0; i< n.length(); i++){
        if (n[i] == a){
            count++;
        }
    }

    return count;
}

int main(){
    int input;
    cin>>input;
    int counter = 0;
    while( counter < input){
        counter += 1;

        string n;

        cin>>n;
        int value_ = 0;
        char num_ = n[0];
        for (int i=0; i< n.length(); i++){
            int count = counter_(n, n[i]);
            if(count > value_){
                value_ = count;
                num_ = n[i];
            } 
            else if (count == value_){
                if(n[i]<num_){
                    num_ = n[i];
                }
            }       
        }
    
        cout<< value_  <<" " << num_<< "\n";

    }

    return 0;
}