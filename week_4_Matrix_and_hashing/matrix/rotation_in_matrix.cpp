// Here we are rotating the matrix by 90 degrees.

// ALgoritm

// Input a 2-D integer array that will be treated as a matrix with row_col_size.

// Pass the data to the function Rotate_ClockWise(arr).

// Inside the function Rotate_ClockWise(arr)

// Start loop FOR from i to 0 till i less than row_col_size/2.

// Inside the loop, start another loop FOR from j to 0 till j less than row_col_size - i - 1.

// Inside the loop, set ptr to arr[i][j], arr[i][j] to arr[row_col_size - 1 - j][i], arr[row_col_size - 1 - j][i] to arr[row_col_size - 1 - i][row_col_size - 1 - j], arr[row_col_size - 1 - i][row_col_size - 1 - j] to arr[j][row_col_size - 1 - i] and arr[j][row_col_size - 1 - i] to ptr.

// Start loop FOR from i to 0 till i less than row_col_size. Inside the loop, start another loop FOR from j to 0 till j less than row_col_size; j++ and print arr[i][j].



// The code for the above algorithm is as follows:-



#include <bits/stdc++.h>
using namespace std;
#define row_col_size 3
void Rotate_ClockWise(int arr[row_col_size][row_col_size]){
    for(int i = 0; i < row_col_size / 2; i++){
      for(int j = i; j < row_col_size - i - 1; j++){
         int ptr = arr[i][j];
         arr[i][j] = arr[row_col_size - 1 - j][i];
         arr[row_col_size - 1 - j][i] = arr[row_col_size - 1 - i][row_col_size - 1 - j];
         arr[row_col_size - 1 - i][row_col_size - 1 - j] = arr[j][row_col_size - 1 - i];
         arr[j][row_col_size - 1 - i] = ptr;
      }
   }
}
int main(){
   int arr[row_col_size][row_col_size] = { { 5, 1, 4},{ 9, 16, 12 },{ 2, 8, 9}};
   Rotate_ClockWise(arr);
   cout<<"Rotation of a matrix by 90 degree in clockwise direction without using any extra space is: \n";
   for(int i = 0; i < row_col_size; i++){
      for(int j = 0; j < row_col_size; j++){
         cout << arr[i][j] << " ";
      }
      cout << '\n';
   }
   return 0;
}