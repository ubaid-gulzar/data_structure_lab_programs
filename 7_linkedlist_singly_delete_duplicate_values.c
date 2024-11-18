//In singly linked list reove all duplicate(nodes with duplicate values)from the given list.
//Input: 1->2->3->2->1->5->5->NULL;
//Output: 1->2->3->5->NULL
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
     int data;
     struct node *next;

}type;

void traversal(type *head){
    type *ptr=head;
    while(ptr!=NULL){
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}

type *sort1(type *head){
    type *temp=head;
    type *ptr=head->next;
    type *prev=head;
   while(temp->next!=NULL){
    while(ptr!=NULL){
        int i=0;
         if(ptr->data==temp->data){
            prev->next=ptr->next;
            ptr->next=NULL;
            if(prev->next==NULL){
                return head; 
            }
            ptr=prev;
            ptr=ptr->next;
            i=1;
         }
         if(i==0){
         ptr=ptr->next;
         prev=prev->next;
    }
    }
    temp=temp->next;
    ptr=temp->next;
    prev=temp;
   }
   return head;
}
void createnode(type **head,int data){
       type *ptr=(type *)malloc(sizeof(type));
       ptr->data=data;
       ptr->next=NULL;
       if(*head==NULL){
        *head=ptr;
       }else{
          type *temp=*head;
          while(temp->next!=NULL){
            temp=temp->next;
          }
          temp->next=ptr;
       }
}

int main(){
    type *head=NULL;
    int n,data;
    printf("Enter the number of nodes in linked list\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter the data of node %d: ",i+1);
        scanf("%d",&data);
        createnode(&head,data);
    }

   printf("The linked list is \n");
   traversal(head);
   
   printf("The new linked list is\n");
   head=sort1(head);
   traversal(head);

    return 0;
}