#include<stdio.h>
#include<stdlib.h>

typedef struct node{
     int data;
     struct node *next;
}type;

void traversal(type *head){
    type *ptr;
    ptr =head;
     while(ptr!=NULL){
        printf("%d->",ptr->data);
        ptr =ptr->next;
     }
    printf("NULL\n");
}
type *creatnode(int data){
    type *ptr;
    ptr =(type *)malloc(sizeof(type));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}

void linknode(type **head,int data){
       type *ptr = creatnode(data);
   if(*head==NULL){
       *head= ptr;
   }else{
    type *temp;
    temp = *head;
      while(temp->next!=NULL){
         temp=temp->next;
      }
      temp->next = ptr;
   }

}

type *insertat1st(type *head,int m){
      type *ptr = (type *)malloc(sizeof(type));
      ptr->data = m;
      ptr->next=head;
      return ptr;
}

type *insertatanynode(type *head,int m,int index){
    type *temp=head;
        type *ptr = (type *)malloc(sizeof(type));
        ptr->data = m;
      for(int i=0;i<index-1;i++){
          temp=temp->next;
      }
        ptr->next=temp->next;
        temp->next=ptr;
        return head;
}

type *insertatlast(type *head,int m){
         type *ptr = (type *)malloc(sizeof(type));
         type *temp=head;
         ptr->data =m;
         while(temp->next!=NULL){
            temp=temp->next;
         }
         temp->next=ptr;
         ptr->next=NULL;
         return head;

}

int main(){
    type *head=NULL;
    int n,data,m;
    printf("Enter the number of nodes ypu want to creat\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the data of node %d: ",i+1);
        scanf("%d",&data);
    linknode(&head,data);
    }
    
     printf("The linked list is \n");
     traversal(head);
     printf("Enter the number you want to insert\n");
     scanf("%d",&m);

     //insert at beggning
    // head = insertat1st(head,m);

     //insert after any node
    // printf("enter the index at which you want to add the number\n");
    // int index;
    // scanf("%d",&index);
    // head =insertatanynode(head,m,index);

    //insert at last
     head=insertatlast(head,m);
     traversal(head);
    return 0;
}