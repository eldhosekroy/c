#include<stdio.h>
struct poly {
  int exp;
  int pow;
}a[10],b[10],c[20];


int main(){

  int i,j,k,num1,num2;

  printf("Enter the Number of terms in 1st poly : ");
  scanf("%d",&num1);
  printf("Enter terms in 1st poly \n");
  for(i=0;i<num1;i++){
    printf("Enter exp for %d : ",i+1);
    scanf("%d",&a[i].exp);
    printf("Enter pow for %d : ",i+1);
    scanf("%d",&a[i].pow);
  }

for(i=0;i<num1;i++)
    printf("%d (x^%d)  +  ",a[i].exp,a[i].pow);

  printf("\n\nEnter the Number of terms in 2st poly : ");
  scanf("%d",&num2);
  printf("Enter terms in 2st poly \n");
  for(i=0;i<num2;i++){
    printf("Enter exp for %d : ",i+1);
    scanf("%d",&b[i].exp);
    printf("Enter pow for %d : ",i+1);
    scanf("%d",&b[i].pow);
  }

for(i=0;i<num2;i++)
    printf("%d (x^%d)  +  ",b[i].exp,b[i].pow);

  i=0;j=0;k=0;



  while(i<num1 && j<num2){
    if(a[i].pow == b[j].pow){
      c[k].exp = a[i].exp + b[j].exp;
      c[k].pow = a[i].pow;
      i++;j++;k++;
    }else if(a[i].pow > b[j].pow){
      c[k].exp = a[i].exp;
      c[k].pow = a[i].pow;
      i++;k++;
    }else{
      c[k].exp = b[j].exp;
      c[k].pow = b[j].pow;
      k++;j++;
    }
  }
  while(i<num1){
    c[k].exp = a[i].exp;
    c[k].pow = a[i].pow;
    i++;k++;
  }
  while(j<num2){
    c[k].exp = b[j].exp;
    c[k].pow = b[j].pow;
    j++;k++;
  }



  printf("\n\nResult\n");

for(i=0;i<k;i++)
    printf("%d (x^%d)  +  ",c[i].exp,c[i].pow);


}






