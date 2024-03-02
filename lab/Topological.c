#include<stdio.h>
int a[10][10],n,indegre[10];
void find_indegre() {
int j,i,sum;
for(i=1;i<n;i++) {
sum=0;
for(j=0;j<n;j++)
sum+=a[j][i];
indegre[i]=sum;
}
}
void topology() {
int i,u,v,stor[10],stk[10],top= -1,k=0;
find_indegre();
for(i=0;i<n;i++) {
if(indegre[i]==0)
stk[++top]=i;
}
while(top!= -1) {
u=stk[top--];
stor[k++]=u;
for(v=0;v<n;v++) {
if(a[u][v]==1) {
indegre[v]--;
if(indegre[v]==0)
stk[++top]=v; 
}
}
}
printf ("\nThe topological Sequence is:\n");
for(i=0;i<n;i++)
printf ("%d ",stor[i]);
}
void main() {
int i,j;
printf("Enter number of nodes:");
scanf("%d",&n);
printf("\nEnter the adjacency matrix:\n");
for(i=0;i<n;i++) {
for(j=0;j<n;j++)
scanf("%d",&a[i][j]);
}
topology();
}
