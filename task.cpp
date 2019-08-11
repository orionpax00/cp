#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int num_test_case;
    cin>>num_test_case;
    int counter = 0;
    while(counter < num_test_case){
        ++counter;
        int n;
        int m;
        cin>>n;
        cin>>m;
        int arr[n+2][m+2];

        for(int i = 1; i < n+1 ; ++i){
            for(int j = 1; j < m+1; j++ ){
                cin>>arr[i][j];
            }
        }

        for(int i = 0; i < n+2 ; ++i){
            if( i == 0 || i == n+1){
                for(int j = 1; j < m+2; j++ ){
                    arr[i][j] = 0;
                }
            }

            else{
                arr[i][0] = 0;
                arr[i][m+1] = 0;
            }
        }

        set< int > university;
        for(int i = 1; i < n+1 ; ++i){
            for(int j = 1; j < m+1; j++ ){
                    if(arr[i][j] != -1){
                        if( arr[i][j] == arr[i-1][j-1] || arr[i][j] == arr[i-1][j] || arr[i][j] == arr[i-1][j+1] || arr[i][j] == arr[i][j-1] || arr[i][j] == arr[i][j+1] || arr[i][j] == arr[i+1][j-1] || arr[i][j] == arr[i+1][j] || arr[i][j] == arr[i+1][j+1] ){
                            university.insert(arr[i][j]);
                        }
                    }
                }
            }
        
        cout << university.size() << endl;

        }

    return 0;
}