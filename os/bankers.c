#include<stdio.h>
int main(){
	int n,m,i,j,k,l,allo[20][20],max[20][20],avil[20],need[20][20];
	printf("Enter the number of process : ");
	scanf("%d",&n);
	printf("Enter the number of resoures : ");
	scanf("%d",&m);
	printf("Enter the allo matrix :\n");
	for(i = 0; i < n; i++)
		for(j = 0;j < m; j++)
			scanf("%d",&allo[i][j]);
	printf("Enter the max matrix :\n");
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			scanf("%d",&max[i][j]);
	printf("Enter the avil matrix :\n");
	for(i = 0; i < m; i++)
		scanf("%d",&avil[i]);

	int finish[n] , work[m],safeseq[n],num = 0;

	printf("\n\nNeed matrix: \n");
	for(i = 0; i < n; i++){
		printf("\n");
		for(j = 0; j < m; j++){
			need[i][j] = max[i][j] - allo[i][j];
			printf("%d ",need[i][j]);
		}
	}

	for(i = 0; i < n; i++)
		finish[i] = 0;
	for(i = 0; i < m; i++)
		work[i] = avil[i];

	for(k = 0; k < n; k++){
		for(i = 0; i < n; i++){
			if(finish[i] == 0){
				int flag = 0;
				for(j = 0; j < m; j++){
					if(need[i][j] > work[j]){
						flag = 1;
						break;
					}
				}
				if(flag == 0){
					safeseq[num++] = i;
					finish[i] = 1;
					for(l = 0; l < m; l++){
						work[l] += allo[i][l];
					}
				}
			}
		}
	}

	printf("\nSafe Sequence : \n");
	for(i = 0; i < num; i++)
		printf("%d  ",safeseq[i]);

}
