#include<stdio.h>
#include<stdlib.h>

int main(){
	int i,j,k,n,rs[100],size,total = 0, head, move;
	printf("Enter the number of request : ");
	scanf("%d",&n);
	printf("Enter the requset sequence : ");
	for(i = 0; i < n; i++)
		scanf("%d",&rs[i]);
	printf("Enter the head posistion : ");
	scanf("%d",&head);
	printf("Enter the size of the disk : ");
	scanf("%d",&size);
	printf("Enter the movent to hige - 1 , to low - 0 : ");
	scanf("%d",&move);

	rs[n++] = 0;
	rs[n++] = head;
	rs[n++] = size-1;


	for(i = 0; i < n; i++){
		for(j = 0; j < n-1; j++){
			if(rs[j] > rs[j+1]){
				int temp = rs[j];
				rs[j] = rs[j+1];
				rs[j+1] = temp;
			}
		}
	}

	for(i = 0; i < n; i++)
		if(rs[i] == head){
			k = i;
			break;
		}
	int pos = k, sort[100], num = 0;
	
	if(move){
		for(i = pos; i < n; i++){
			sort[num++] = rs[i];
		}
		for(i = 0; i < pos; i++)
			sort[num++] = rs[i];
	}

	for(i = 0; i < num; i++)
		printf("%d  ",sort[i]);

}
