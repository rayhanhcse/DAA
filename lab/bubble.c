#include<stdio.h>
int InvCnt(int arr[], int n){
int count=0;
for(int i=0; i<n-1; i++){
for(int j=i+1; j<n; j++){
if(arr[i] > arr[j]){
count++;
}
}
}
return count;
}
int main(){
int n;
printf("Enter array size: ");
scanf("%d", &n);
int arr[n];
printf("Enter array elements: ");
for(int i=0; i<n; i++){
scanf("%d", &arr[i]);
}
printf("Number of inversions are: %d", InvCnt(arr, n));
}
