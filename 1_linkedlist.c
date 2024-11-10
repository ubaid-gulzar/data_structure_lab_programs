#include<stdio.h>
#include<stdlib.h>
   struct node{
      int data;
      struct node *next;

};
void traversal(struct node *head){
    while(head!=NULL){
      printf("%d ",head->data);
      head =head->next;
    }

}
int main(){
    struct node *head;
    struct node *second;
    struct node *third;
    //allocate memory for nodes in the linked list in the heap
    head= (struct node *) malloc(sizeof(struct node));
    second= (struct node *) malloc(sizeof(struct node));
    third= (struct node *) malloc(sizeof(struct node));
  //link first and second node
   head-> data=1;
   head->next=second;
   //link second and third node
   second-> data=2;
   second->next=third;
   //terminate the linked list at third node
   third-> data=3;
   third->next=NULL;
    
   //traversal of linked list
   traversal(head);
    return 0;
}