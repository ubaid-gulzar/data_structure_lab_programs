#include<stdio.h>
#include<stdlib.h>


typedef struct node{
     int data;
     struct node *next;

}type;
// displays the elements of a linked list
void traversal(type *head){
     while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
     }
}
//Deleting the 1st element from linked list
type *delete1stnode(type *head){
type *ptr;
ptr=head;
head=head->next;
    free(ptr);
    return head;
}
//Deleting any element with given index from linked list
type *deleteanynode(type *head,int index){
type *p=head;
if(index==0){
head=head->next;
 free(p);
 return head;
}else{
int i=0;
while(i!=(index-1)){
    p=p->next;
    i++;
}
type *ptr;
ptr=p->next;
p->next=ptr->next;
free(ptr);
return head;
}
}
//Deleting the last element from linked list
type *deletelastnode(type *head){
type *ptr,*p;

ptr=head;
p=ptr->next;
while(p->next!=NULL){
    ptr=ptr->next;
    p=p->next;
}
ptr->next=NULL;
free(p);
return head;
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

     head->data=8;
     head->next=second;

     second->data=9;
     second->next=third;

     third->data=10;
     third->next=fourth;

     fourth->data=11;
     fourth->next=fifth;

     fifth->data=12;
     fifth->next=NULL;
     printf("the linked list is\n");
     traversal(head);
//delete the 1st node

 /*  printf("the linked list after deletion of 1st node is\n");
     head=delete1stnode(head);   
 */
//delete at anywhere

 /*   printf("enter the node you want to delete\n");
    int index;
    scanf("%d",&index);
    printf("the new linked list is \n");
    head=deleteanynode(head,index);
*/
//delete at the end

   printf("the linked list is after deleting the last node is\n");
    head=deletelastnode(head);
  
     traversal(head);
    return 0;
}