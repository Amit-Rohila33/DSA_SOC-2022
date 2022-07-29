// The logic used to sort the rows in an ascending order is as follows −

// for (i=0;i<m;++i){
//    for (j=0;j<n;++j){
//       for (k=(j+1);k<n;++k){
//          if (ma[i][j] > ma[i][k]){
//             a = ma[i][j];
//             ma[i][j] = ma[i][k];
//             ma[i][k] = a;
//          }
//       }
//    }
// }


// The logic used to sort the rows in an descending order is as follows −

// for (j=0;j<n;++j){
//    for (i=0;i<m;++i){
//       for (k=i+1;k<m;++k){
//          if (mb[i][j] < mb[k][j]){
//             a = mb[i][j];
//             mb[i][j] = mb[k][j];
//             mb[k][j] = a;
//          }
//       }
//    }
// }



// The final code is as follows:-


#include <stdio.h>
void main(){
   int i,j,k,a,m,n;
   static int ma[10][10],mb[10][10];
   printf ("Enter the order of the matrix \n");
   scanf ("%d %d", &m,&n);
   printf ("Enter co-efficients of the matrix \n");
   for (i=0;i<m;++i){
      for (j=0;j<n;++j){
         scanf ("%d",&ma[i][j]);
         mb[i][j] = ma[i][j];
      }
   }
   printf ("The given matrix is \n");
   for (i=0;i<m;++i){
      for (j=0;j<n;++j){
         printf (" %d",ma[i][j]);
      }
      printf ("\n");
   }
   printf ("After arranging rows in ascending order\n");
   for (i=0;i<m;++i){
      for (j=0;j<n;++j){
         for (k=(j+1);k<n;++k){
            if (ma[i][j] > ma[i][k]){
               a = ma[i][j];
               ma[i][j] = ma[i][k];
               ma[i][k] = a;
            }
         }
      }
   }
   for (i=0;i<m;++i){
      for (j=0;j<n;++j){
         printf (" %d",ma[i][j]);
      }
      printf ("\n");
   }
   printf ("After arranging the columns in descending order \n");
   for (j=0;j<n;++j){
      for (i=0;i<m;++i){
         for (k=i+1;k<m;++k){
            if (mb[i][j] < mb[k][j]){
               a = mb[i][j];
               mb[i][j] = mb[k][j];
               mb[k][j] = a;
            }
         }
      }
   }
   for (i=0;i<m;++i){
      for (j=0;j<n;++j){
         printf (" %d",mb[i][j]);
      }
      printf ("\n");
   }
}
