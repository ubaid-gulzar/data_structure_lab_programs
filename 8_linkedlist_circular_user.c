#include<stdio.h>
#include<stdlib.h>

typedef struct node{
      int data;
      struct node *next;
}type;

void traversal(type*head){
    type *temp=head;
    do{
    printf("%d->",temp->data);
    temp=temp->next;
    }while(temp!=head);
     printf("\n");  
}

void creatnode(type **head,int data,int n){
     type *ptr=(type *)malloc(sizeof(type));
     int count=2;
     ptr->data=data;
     ptr->next=NULL;
     if(*head==NULL){
        *head =ptr;
     }
     else{
        type *temp=*head;
        while(temp->next!=NULL){
         count++;
            temp=temp->next;
        }
        temp->next=ptr;
        if(count==n){
         ptr->next=*head;
        }
     }

}

int main(){
   type *head=NULL;
   int n,data;
   printf("enter the number of nodes \n");
   scanf("%d",&n);
   for(int i=0;i<n;i++){
      printf("enter the data of node %d: ",i+1);
      scanf("%d",&data);
      creatnode(&head,data,n);
   }
    printf("the linked list is\n");  
    traversal(head);
    return 0;
}