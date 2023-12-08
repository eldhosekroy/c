#include<stdio.h>
int main(){
  int m,n,i,j,num=0;
  printf("Enter num of Row and col for matrix (m x n)\n");
  scanf("%d%d",&m,&n);
  int mat[m][n];
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      printf("Enter elemt at %d x %d : ",i+1,j+1);
      scanf("%d",&mat[i][j]);
      if(mat[i][j]!=0)
        num++;
    }
  }

printf("\n\n");
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      printf("%d\t",mat[i][j]);
    }
    printf("\n\n\n");
  }


  int Mat[num][3],k=0;

  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      if(mat[i][j]!=0){
        Mat[k][0]=i;
        Mat[k][1]=j;
        Mat[k][2]=mat[i][j];
        k++;
      }
    }
  }
  printf("\n___\t___\t___\n");
  printf("ROW\tCOL\tVAL\n");
  printf("-+-\t-+-\t-+-\n\n");

  for(i=0;i<k;i++){
    printf("%d\t%d\t%d\n\n",Mat[i][0],Mat[i][1],Mat[i][2]);
  }
}
