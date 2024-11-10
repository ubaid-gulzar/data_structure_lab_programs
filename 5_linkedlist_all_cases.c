#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;

}type;

void traversal(type *head){
     type *temp = head;
     while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
     }
     printf("NULL\n");
}

type *createnode(int data){
     type *ptr;
    ptr = (type *)malloc(sizeof(type));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

void linknodes(int data,type **head){
     type *newnode=createnode(data);
     if(*head==NULL){
        *head=newnode;
     }else{
           type *temp=*head;
           while(temp->next!=NULL){
             temp=temp->next;
           }
        temp->next=newnode;
     }
}

type *delete1stnode(type *head){
type *ptr;
ptr=head;
head=head->next;
    free(ptr);
    return head;
}

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

type *deletevalue(type *head,int value){
     type *ptr=head;
     type *p=head->next;
     if(head->data==value){
         head =head->next;
         free(ptr);
         return head;
     }else{
     while(p->data!=value && p->next!=NULL){
         ptr=ptr->next;
         p=p->next;
     }
       if(p->data==value){
            ptr->next=p->next;
            free(p);
            return head;
       }
     }     
     
}

type *insert1(type *head,int m){
      type *ptr;
      ptr = (type *)malloc(sizeof(type));
      ptr->data=m;
      ptr->next=head;
      return ptr;

}

type *insert2(type *head,int m,int index){
  type *ptr;
  ptr = (type *)malloc(sizeof(type));
      ptr->data=m;
      if(index==0){
        ptr->next=head;
        return ptr;
      }else if(index>0){
       struct node *p;
       p =head;
       int i=0;
      while(i!=(index-1)){
       p=p->next;
       i++;
      }
      ptr->next=p->next;
      p->next=ptr;
      return head;
      }
      
}

type *insert3(type *head,int m){
      struct node *ptr;
      ptr = (type *)malloc(sizeof(type));
      ptr->data=m;
      type *p;
      p=head;
      while(p->next!=NULL){
       p= p->next;
      }
      p->next=ptr;
      ptr->next=NULL;
      return head;
      
}

type *insert4( type *head,int data,int number){
      type *ptr;
      ptr= (type *)malloc(sizeof(type));
      ptr->data = data;
      type *p=head;
      while(p->data!=number && p->next!=NULL){
         p=p->next;
     }
      ptr->next =p->next;
      p->next=ptr;

      return head;
}

int main(){
    type *head = NULL;
    int n,data;
    printf("enter the number of nodes you want in linked list\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
      printf("enter the data of node %d: ",i+1);
      scanf("%d",&data);
      linknodes(data,&head);
    }
    printf("the linked list is\n");
    traversal(head); 

    printf("Enter 1 to delete the 1st node from linked list\n");
    printf("Enter 2 to delete the node at any index from linked list\n");
    printf("Enter 3 to delete the last node from linked list\n");
    printf("Enter 4 to delete the node of value given from linked list\n");
    printf("Enter 5 to insert a node at beggining in the linked list\n");
    printf("Enter 6 to insert a node at any index in the linked list\n");
    printf("Enter 7 to insert a node at the end of linked list\n");
    printf("Enter 8 to insert a node after a given value\n");
    int a;
    scanf("%d",&a);
    switch(a){
    case 1:   
            printf("the new linked list is\n");
            head =delete1stnode(head);
            traversal(head);
        break;
    case 2:  
            printf("enter the index where you want to delete the node\n");
            int n;
            scanf("%d",&n);
            printf("the new linked list is\n");
            head=deleteanynode(head,n);
            traversal(head);
        break;
    case 3: 
           printf("The new linked list is\n");
           head = deletelastnode(head);
           traversal(head);
        break;
    case 4:
           printf("enter the value younwant to delete\n");
           int m;
           scanf("%d",&m);
           printf("the new linked list is\n");
           head= deletevalue(head,m);
           traversal(head);
        break;
    case 5:
          printf("enter the number you want to insert\n");
          int n1;
          scanf("%d",&n1);
          printf("the new linked list is\n");
          head=insert1(head,n1);
          traversal(head);
        break; 
    case 6: 
          printf("enter the number you want insert and index where you want to insert\n");
          int n2,n3;
          scanf("%d%d",&n2,&n3);
          printf("the new linked list is\n");
          head=insert2(head,n2,n3);
          traversal(head);
        break;
    case 7:
          printf("enter the number you want to insert\n");
          int n4;
          scanf("%d",&n4);
          printf("the new linked list is\n");
          head=insert3(head,n4);
          traversal(head);
        break;
    case 8:
          printf("enter the number you want insert and a number after you want to insert\n");
          int n5,n6;
          scanf("%d%d",&n5,&n6);
          printf("the new linked list is\n");
          head=insert2(head,n5,n6);
          traversal(head);
        break;
    default :
          printf("you have enter the wrong number\n");        
    }
    
    return 0;
}