#include<stdio.h>
#include<stdlib.h>

typedef struct node{
   struct node *prev;
   int data;
   struct node *next;
}type;
// traversal forward
void traversal1(type *head){
   while(head!=NULL){
      printf("%d ",head->data);
      head=head->next;
   }
}
//traversal backward
void traversal2(type *fifth){
      while(fifth!=NULL){
        printf("%d ",fifth->data);
        fifth=fifth->prev;
      }
       
}

int main(){
     type *head;
     type *second;
     type *third;
     type *fourth;
     type *fifth;
     

     head = (type *)malloc(sizeof(type));
     second = (type *)malloc(sizeof(type));
     third = (type *)malloc(sizeof(type));
     fourth = (type *)malloc(sizeof(type));
     fifth = (type *)malloc(sizeof(type));

     head->prev=NULL;
     head->data=7;
     head->next=second;

     second->prev=head;
     second->data=8;
     second->next=third;

     third->prev=second;
     third->data=9;
     third->next=fourth;

     fourth->prev=third;
     fourth->data=10;
     fourth->next=fifth;

     fifth->prev=fourth;
     fifth->data=11;
     fifth->next=NULL;
    
    printf("the linked list in forwar is\n");
    traversal1(head);
    printf("\n");
    printf("the linked list in backward is\n");
    traversal2(fifth);

    return 0;
}