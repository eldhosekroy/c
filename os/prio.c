#include<stdio.h>

struct pro{
	int pid;
	int at;
	int bt;
	int pri;
	int tat;
	int wt;
	int ct;
};

int main(){
	int n,i,j,k,time = 0,avgw = 0, avgt = 0;
	printf("Enter the number of process : ");
	scanf("%d",&n);
	printf("pid at bt pri\n");
	struct pro p[n];
	for(i = 0; i < n; i++)
		scanf("%d%d%d%d",&p[i].pid,&p[i].at,&p[i].bt,&p[i].pri);

	for(i = 0; i < n -1; i++)
		for(j = 0; j < n - 1 - i; j++){
			if(p[j].pri > p[j+1].pri || (p[j].pri == p[j+1].pri && p[j].at > p[j+1].at)){
				struct pro temp = p[j];
				p[j] = p[j +1];
				p[j + 1] = temp;
			}
		}

	
	for(i = 0; i < n; i++){
		if(time < p[i].at){
			time = p[i].at;
		}
		time += p[i].bt;
		p[i].ct = time;
		p[i].tat = p[i].ct - p[i].at;
		p[i].wt = p[i].tat - p[i].bt;
	}

	 printf("PID\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
	  for (i = 0; i < n; i++) {
		  printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].pri, p[i].wt, p[i].tat);
    }
}
