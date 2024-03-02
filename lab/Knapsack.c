#include<stdio.h>
int wght[10], prft[10], tempTable[10][10], obj, i, j, capacity, selected_obj[10] = {0};
int max_f(int a, int b) {
return ((a > b) ? a : b);
}
int knapsack_f(int obj_indx, int currentCapacity) {
int value;
if (tempTable[obj_indx][currentCapacity] < 0) {
if (currentCapacity < wght[obj_indx]) {
value = knapsack_f(obj_indx - 1, currentCapacity);
} else {
value = max_f(knapsack_f(obj_indx - 1, currentCapacity), prft[obj_indx] + 
knapsack_f(obj_indx - 1, currentCapacity - wght[obj_indx]));
 }
 tempTable[obj_indx][currentCapacity] = value;
 }
 return tempTable[obj_indx][currentCapacity];
}
int main() {
 int t_prft, cnt = 0;
 printf("\nEnter the number of objects ");
 scanf("%d", &obj);
 printf("Enter the profits and weights of the elements\n");
 for (i = 1; i <= obj; i++) {
 printf("\nEnter profit and weight for object no %d: ", i);
 scanf("%d %d", &prft[i], &wght[i]);
 }
 printf("\nEnter the knapsack capacity ");
 scanf("%d", &capacity);
 for (i = 0; i <= obj; i++) {
 for (j = 0; j <= capacity; j++) {
 if ((i == 0) || (j == 0)) {
 tempTable[i][j] = 0;
 } else {
 tempTable[i][j] = -1;
 }
 }
 }
 t_prft = knapsack_f(obj, capacity);
 i = obj;
 j = capacity;
 while (j != 0 && i != 0) {
 if (tempTable[i][j] != tempTable[i - 1][j]) {
 selected_obj[i] = 1;
 j = j - wght[i];
 i--;
 } else {
 i--;
 }
 }
 printf("\nObjects included in the knapsack:\n");
 printf("Sl.no\tWeight\tProfit\n");
 for (i = 1; i <= obj; i++) {
 if (selected_obj[i]) {
 printf("%d\t%d\t%d\n", ++cnt, wght[i], prft[i]);
 }
 }
 printf("Total profit = %d\n", t_prft);
 return 0;
}
