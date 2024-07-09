#include<stdio.h>
#include<stdlib.h>

int main(){
	int head, dq[100], i, n, totalhead = 0;
	printf("Enter the number of move : ");
	scanf("%d",&n);
	printf("Enter the points : ");
	for(i = 0; i < n; i++)
		scanf("%d",&dq[i]);
	printf("Enter the head posision : ");
	scanf("%d",&head);
	

	for(i = 0; i < n; i++){
		totalhead += abs(dq[i]-head);
		head = dq[i];
	}
	printf("Total head movement is %d", totalhead);
}
