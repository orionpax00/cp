
// C++ program for left 
// rotation of matrix by 90 degree 
// without using extra space 
#include <bits/stdc++.h> 
using namespace std; 
#define R 3 
#define C 3 
  
void reverseRows(int arr[R][C]) { 
    for (int i = 0; i < R; i++) 
			reverse(arr[i], arr[i] + C);
} 
  
void transpose(int arr[R][C]) { 
    for (int i = 0; i < R; i++) {
        for (int j = i; j < C; j++){
						if(i == j || j == R - i - 1) continue; 
            swap(arr[i][j], arr[j][i]);
			}
	} 
} 
  
void printMatrix(int arr[R][C]) { 
    for (int i = 0; i < R; i++) { 
        for (int j = 0; j < C; j++) 
            cout << arr[i][j] << " "; 
        cout << '\n'; 
    } 
} 

void chageDi(int arr[R][C]){
		for(int i = 0 ; i < R; i++)
			swap(arr[i][i], arr[i][R - i - 1]); 
}
 
void rotate90(int arr[R][C]) { 
    transpose(arr);
		reverseRows(arr); 
		chageDi(arr);
} 

 
void ans(int arr[R][C], int t){
	for(int i = 0; i < t; i++){
		rotate90(arr);
	}
}
 
int main() {
		
    int arr[R][C] = { { 1, 2, 3 }, 
                      { 4, 5, 6 }, 
                      { 7, 8, 9 }};
													
    ans(arr, 1); 
    printMatrix(arr); 
    return 0; 
} 

