#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack_arr[MAX];
int top=-1;

int isfull(){
      if(top==MAX-1){
        return 1;
      }
      else{
        return 0;
      }
}

int isempty(){
    if(top==-1){
        return 1;
    }else{
        return 0;
    }
}

int pop(){
    if(isempty()){
        printf("the stack is empty\n");
        exit(1);
    }else{
        int value;
        value=stack_arr[top];
        top=top-1;
        return value;
    }
}

void push(int data){
    if(isfull()){
        printf("stack is full\n");
    }
    else{
        top=top+1;
        stack_arr[top]=data;
    }
}

void print(){
    if(top==-1){
        printf("the stack is empty\n");
    }
    else{
        for(int i=0;i<=top;i++){
            printf("%d ",stack_arr[i]);
        }
    }
    printf("\n");
}

int main(){
    int choise,data;
    while(1){
    if(isfull()==0){
    printf("1: push\n");
    }
    if(isempty()==0){
    printf("2: pop\n");
    }
    printf("3: print the top element\n");
    printf("4: print all element\n");
    printf("5: Quit\n");
    printf("please enter your choise\n");
    scanf("%d",&choise);
       switch(choise){
        case 1:
             if(isfull()==1){
                printf("wrong option\n");
                break;
             }
             printf("enter the element you want to push\n");
             scanf("%d",&data);
             push(data);
             break;
        case 2:
            if(isempty()==1){
                printf("wrong option\n");
                break;
            }
            data= pop();
            printf("the deleted element is: %d\n",data);
             break;
        case 3: 
             if(top==-1){
                printf("their is no element in the stack\n");
                break;
             }
             printf("the top element is: %d\n",stack_arr[top]);
             break;
        case 4:
              if(top==-1){
                printf("their is no element in the stack\n");
                break;
             }
             printf("the elements of stack are\n");
             print();
             break;
        case 5:
             printf("The program has been terminated sucessfully\n");
             exit(1);
             break;
        default:
             printf("invalid option\n");
       }
    }

    return 0;
}