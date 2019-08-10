#include <iostream>

using namespace std;

int main(){
    int input;
    cin>>input;
    int counter = 0;
    while( counter < input){
        counter += 1;
        int n;
        int x;
        int y;
        cin>>n;
        cin>>x;
        cin>>y;
        int arr[n];
        for( int i = 0; i < n; ++i){
            cin>>arr[i];
        }
        if (arr[0] == x && arr[n-1] == y){
            cout<<"BOTH"<<endl;
        }
        else if (arr[0] == x && arr[n-1] != y){
            cout<<"EASY"<<endl;
        }
        else if (arr[0] != x && arr[n-1] == y){
            cout<<"HARD"<<endl;
        }
        else if(arr[0] != x && arr[n-1] != y){
            cout<<"OKAY"<<endl;
        }
    }
}