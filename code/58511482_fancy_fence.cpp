#include <iostream>

using namespace std;

int main(){
    int input;
    cin>>input;

    int arr[input];
    for (int i = 0; i < input; ++i){
        cin>>arr[i];
    }

    for(int i=0; i<input; ++i){

        int divisor_ = 180 - arr[i];

        int n = 360/divisor_;

        if(360%divisor_ == 0 && n >= 3){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}