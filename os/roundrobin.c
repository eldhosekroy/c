#include<stdio.h>
struct pro{
	int pid;
	int at;
	int bt;
	int tat;
	int wt;
	int rt;
};

int main(){
	int n,i,j,tq,avgw,avgt;
	printf("Enter the number of process : ");
	scanf("%d",&n);
	
	struct pro p[n];

	printf("pid at bt");
	for(i = 0; i < n; i++){
		scanf("%d%d%d",&p[i].pid,&p[i].at,&p[i].bt);
		p[i].rt = p[i].bt;
	}

	printf("Enter the time quantm : ");
	scanf("%d",&tq);

	int comp = 0, t = 0, flag = 0;

	while(comp != n){
		flag = 0;
		for(i = 0; i < n; i++){
			if(p[i].at <= t && p[i].rt > 0){
				if(p[i].rt <= tq){
					t += p[i].rt;
					p[i].rt = 0;
					comp++;
					p[i].tat = t - p[i].at;
					p[i].wt = p[i].tat - p[i].bt;
					avgw += p[i].wt;
					avgt += p[i].tat;
				}else{
					t += tq;
					p[i].rt -= tq;
				}
				flag = 1;
			}
		}
		if(flag == 0)
			t++;
	}
	printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tat);
    }
}
