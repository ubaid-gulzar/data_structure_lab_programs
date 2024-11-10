#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
void traversal(struct node *head){
    struct node *ptr=head;
     while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
     }
}

struct node *creatnode(int data){
  struct node*ptr;
  ptr=(struct node *)malloc(sizeof(struct node));
  ptr->data=data;
  ptr->next=NULL;
  return ptr;
}

void joinnode(struct node **head,int data){
    
   struct node *newnode = creatnode(data);
   if(*head==NULL){
      *head=newnode;
   }
   else{
       struct node *temp;
       temp =*head;
       while(temp->next!=NULL){
        temp=temp->next;
       }
       temp->next=newnode;

   }

}

int main() {
    struct node *head =NULL;
    int n,data;
    printf("enter the number of nodes you want\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
       printf("Enter the element %d: ",i+1);
       scanf("%d",&data);
       joinnode(&head,data);
    }
       printf("the linked list is\n");
       traversal(head);
       return 0;
}