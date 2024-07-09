#include<stdio.h>
int main(){
	int n, i, j, k, str[20], f, pf = 0, flag = 0, count = 0, m[10];
	printf("Enter the number of ref string : ");
	scanf("%d",&n);
	printf("Enter the ref string : \n");
	for(i = 0; i < n; i++)
		scanf("%d",&str[i]);
	printf("Enter the number of Frames : ");
	scanf("%d",&f);

	for(i = 0; i < f; i++)
		m[i] = -1;

	for(i = 0; i < n; i++){
		for(j = 0; j < f; j++){
			if(str[i] == m[j]){
				flag = 1;
			}
		}
		if(flag != 1){
			pf++;
			m[count++] = str[i];
		}
		if(count == f)
			count = 0;
		flag = 0;

		for(k = 0; k < f; k++){
			printf("%d\t",m[k]);
		}
		printf("\n");

	}
	printf("\n\nPage fault : %d\nMiss : %d\nHit : %d\n",pf,pf,n-pf);
}
