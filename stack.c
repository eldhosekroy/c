#include<stdio.h>
#define size 10
int top=-1,stack[size];
int isfull(){
  if(top==size-1){
    printf("Stack Overflow\n");
    return 0;
  }else {
    printf("Enter the elemnt : ");
  }
}
int isempty(){
  if(top==-1){
    printf("Stack Underflow\n");
    return 0;
  }else 
    printf("Stack is not empty\n");
}
void push(){
  isfull();
  top++;
  scanf("%d",&stack[top]);
}
void pop(){
  isempty();
  top--;
}
void peak(){
  isempty();
  printf("%d\n",stack[top]);
}
void display(){
  for(int i=top;i>-1;i--){
    printf("%d\n",stack[top]);
  }
}


int main(){
  int num;
while(1){
    printf("1 for push\n2 for pop\n3 for peak\n4 for display\n5 for is empty\n6 for is full\n");
    scanf("%d",&num);
    switch (num) {
      case 1:push();break;
      case 2:pop();break;
      case 3:peak();break;
      case 4:display();break;
      case 5:isempty();break;
      case 6:isfull();break;
      default:printf("But y..?\n");return 0;
    }
  }
}
