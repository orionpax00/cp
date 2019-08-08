#include <iostream>
#include <algorithm> 

using namespace std;
main(){
    
    int input;
    cout<<"please enter length of array: ";
    cin>>input;
    
    int arr[input];
    
    for (int i = 0 ; i < input; ++i){
        cin>>arr[i];
    };

    bool sort_ = std::is_sorted(arr, arr + input);

    if(sort_){
        cout<<"0";
    }
    else{
        
    }
}