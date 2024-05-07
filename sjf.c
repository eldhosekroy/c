#include<stdio.h>
void main(){
int i=0,j=0,b[20],g[20],p[20],w[20],t[20],a[20],n=0,m;
float avgw=0,avgt=0;
int k=1,min = 0, btime = 0;
printf("enter the number of process: ");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("process ID : ");
scanf("%d",&p[i]);
printf("burst time : ");
scanf("%d",&b[i]);
printf("Arrival Time: ");
scanf("%d",&a[i]);
}
int temp =0;
for(i=0;i<n-1;i++){
for(j=0;j<n-1;j++){
if(a[j]>a[j+1]){
temp = a[j];
a[i]=a[j+1];
a[j+1] = temp;
temp=b[j];
b[j]=b[j+1];
b[j+1]=temp;
temp=p[j];
p[j]=p[j+1];
p[j+1]=temp;
}
}
}
g[0]=0;
for(i=0;i<n;i++){
	btime = btime + b[j];
	min = b[k];
for(i=0;i<n;i++){
	if(btime >= a[j] && b[i]<min){
	temp = a[j];
	a[j] = a[j-1];
	a[j-1] = temp;
	temp = b[j];
	b[j] = b[j-1];
	b[j-1] = temp;
	temp = p[i];
	}
}	
k++;
}
g[0] = a[0];
for(i=0;i<n;i++){
g[i+1] = g[i] + b[i];
if(g[i] < a[i])
	g[i] = a[i];
}
for(i=0;i<n;i++){
t[i] = g[i+1]-a[i];
w[i] = t[i]-b[i];
avgw += w[i];
avgt += t[i];
}
avgw = avgw/n;
avgt = avgt/n;
printf("process ID\tBurst Time\tGannt Chart\tWaiting Time\tTurnaround Time\n");
for(i=0;i<n;i++){
printf("%d\t\t%d\t\t%d-%d\t\t%d\t\t%d\n",p[i],b[i],g[i],g[i+1],w[i],t[i]);
}
printf("\n avg waiting time: %f",avgw);
printf("\n avg turnaround time: %f", avgt);
}

