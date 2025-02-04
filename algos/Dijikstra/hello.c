#include<stdio.h>
int adder( int x, int y){
    return x + y;
}
int main(){
  int x =1;
  int arr[10];
//   printf("%d", arr[0]);
  int sum = 0;
  for ( int i = 0; i < 2; i++ ){
    scanf("%d", &arr[i]);
  }
  for ( int i = 0; i < 2; i++ ){
    printf("%d ", arr[i]);
    // sum = sum + arr[i];
  }
  printf("%d", sum);
}

