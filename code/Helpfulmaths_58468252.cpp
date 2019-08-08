#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

main(){

    string input;
    cin>>input;

    string delimiter = "+" ;
    string token;

    size_t pos = 0;
    size_t n = 0;

    for (int i = 0; i < input.size(); i++ ){
        if(input[i] == '+') n++;
    }

    int arr[n+1];

    int i = 0;

    while( (pos = input.find(delimiter)) != string::npos ){
        token = input.substr(0, pos);

        arr[i] =  std::stoi( token ) ;
        i++;
        input.erase(0, pos + delimiter.length());
    }
        arr[n] =  std::stoi( input ) ;

    int size = sizeof(arr)/sizeof(int);
    sort(arr, arr+n+1, greater<>());

    std::string final = "";

    for (int i= 0; i < n;++i){
        final.append(std::to_string(arr[i]) + "+");
    }
    final.append(std::to_string(arr[n]));
    std:: reverse(final.begin(), final.end());
    cout<<final<< std::endl;
}