#include<stdio.h>
struct pro{
	int pid;
	int bt;
	int at;
	int tat;
	int ct;
	int wt;
};
int main(){
	int i,j,n,time = 0;
	printf("Enter the number of proces : ");
	scanf("%d",&n);

struct pro p[n];
printf("pid bt at\n");
for(i = 0; i < n; i++)
	scanf("%d%d%d",&p[i].pid,&p[i].bt,&p[i].at);

for(i = 0; i < n; i++){
	for(j = 0; j < n-1-i; j++){
		if(p[i].bt > p[i+1].bt){
		struct pro tem = p[i];
		p[i] = p[i+1];
		p[i+1] = tem;
		}
	}
}
	for(i = 0; i < n; i++){
		if(time < p[i].at){
			time += p[i].at;
		}
		p[i].ct = time + p[i].bt;
		time+=p[i].bt;
		p[i].tat = p[i].ct - p[i].at;
		p[i].wt = p[i].tat - p[i].bt;
	}
}
