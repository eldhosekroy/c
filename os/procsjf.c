#include<stdio.h>
struct pro{
	int pid;
	int bt;
	int at;
	int tat;
	int wt;
};

int main(){
	int n,i,j,k;
	printf("Enter the number of process : ");
	scanf("%d",&n);

	int g[n+1];
	struct pro p[n];
	printf("pid bt at\n");
	for(i = 0; i < n; i++)
		scanf("%d%d%d",p[i].pid,p[i].bt,p[i].at);

	for(i = 0; i < n - 1; i++){
		for(j = 0; j < n - 1 - i; j++){
			if(p[j].at > p[j+1].at){
				struct pro temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
	for(i = 0; i < n - 1; i++){
		for(j = 0; j < n - 1 - i; j++){
			if(p[j].bt > p[j+1].bt){
				struct pro temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
	g[0] = 0;
	for(i = 0; i < n; i++)
		g[i + 1] = g[i] + p[i].bt;
	int avgw = 0, avgt = 0;
	for(i = 0; i < n; i++){
		p[i].tat = g[i+1] - p[i].at;
		p[i].wt = p[i].tat - p[i].bt;
		avgw += p[i].wt;
		avgt += p[i].wt;
	}

	printf("pid\tbt\tat\tct\twt\ttat\n");
	for(i = 0; i < n; i++)
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].bt,p[i].at,g[i+1],p[i].wt,p[i].tat);
}
