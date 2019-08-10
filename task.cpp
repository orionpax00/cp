#include <iostream>

using namespace std;

int main(){
    int input;
    int arr[input][2];
    cin>>input;
    for (int i = 0; i<input; ++i){
            cin>>arr[i][0];
            cin>>arr[i][1];
        }
    for (int i = 0; i<input; ++i){
            cout<<arr[i][0]+arr[i][1]<<endl;
        }
    
    }