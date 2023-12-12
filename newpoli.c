#include <stdio.h>
#include <string.h>
struct poly{
	int co;
	int ex;
}p3[20], mp[20], temp;
int main(){
	int a, b, i, j;
	printf("ENter the size of polynomial one and two:");
	scanf("%d%d",&a,&b);
	printf("Enter  polynomial one\n");
	int c = a+b, flag, k = 0;
	memset(mp,0,sizeof(struct poly)*20);
	for(i = 0;i < c;i++){
		if(i==a) printf("Enter  polynomial two\n");
		printf("enter the co and ex:");
		scanf("%d%d",&p3[i].co,&p3[i].ex);
	}
	for(i = 0;i < a;i++){
		flag = 0;
		for(j = a;j < c;j++){
			if(p3[i].ex == p3[j].ex){
				mp[k].co = p3[i].co + p3[j].co;
				mp[k].ex = p3[i].ex;
				flag = 1;
			}
		}
		if(!flag) mp[k] = p3[i];
		k++;
	}
	for(i = 0;i < c; i++){
		for(j = i+1;j < c;j++){
			if(mp[i].ex < mp[j].ex){
				temp = mp[i];
				mp[i] = mp[j];
				mp[j] = temp;
			}
		}
	}
	i = 0;
	while(mp[i].co){
		printf("%dx^%d",mp[i].co,mp[i].ex);
		if(mp[i+1].co && i < 20)
			printf("+");
		i++;
	}
}
