#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
};

struct node *top=NULL;       //we make top universal of type struct node
   
int isempty(){
    if(top==NULL)
        return 1;
    else
        return 0;
}

void push(int data){
      struct node *ptr;
      ptr = (struct node *)malloc(sizeof(struct node));
      if(ptr==NULL){
        printf("stack ouverflow\n");
        exit(1);
      }
      ptr->data=data;
      ptr->next=NULL;

      ptr->next=top;
      top=ptr;

}

int pop(){
    int value;
    if(isempty()){
        printf("stack underflow\n");
        exit(1);
    }
    struct node *temp;
    temp=top;
    value=top->data;
    top=top->next;
    free(temp);
    temp=NULL;
    return value;
}

int peek(){
    if(isempty()){
        printf("stack underflow\n");
        exit(1);
    }
    return top->data;
}

void print(){
    if(isempty()){
        printf("stack underflow\n");
        exit(1);
    }
    struct node *temp;
    temp=top;
    printf("the stack elements are: ");
    while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
}
    printf("\n");
}

int main(){
    int choise,data;
    while(1){
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. print the top element\n");
        printf("4. print\n");
        printf("5. quit\n");
        printf("Enter your choise: ");
        scanf("%d",&choise);
        switch(choise){
        case 1:
               printf("enter the element to be pushed: ");
               scanf("%d",&data);
               push(data);
               break;
        case 2:
               printf("Deleted element is %d\n",pop());
               break;
        case 3:
               printf("The top element of the stack is %d\n",peek());
               break;
        case 4:
               print();
               break;
        case 5:
               printf("Program exits sucessuflly\n");
               exit(1);
               break;
        default:
               printf("wrong choise\n");
        }
    }
    return 0;
}