#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *next;
};
struct node *head=NULL, *tail=NULL;
//insert at begining 
void ifront()
{
    int ele;
    struct node p = (struct node)malloc(sizeof(struct node));
    printf("Enter the value to be inserted: \n");
    scanf("%d",&ele);
    p->data=ele;
    p->next=NULL;
    if(head==NULL){
        head=p;
        printf("%d is inserted\n",head->data);
        return;
    }
  p->next=head;
  head=p;
  printf("%d inserted\n",head->data);
}
//insert at end
void iend()
{
    int ele;
    struct node p= (struct node)malloc(sizeof(struct node));
    printf("Enter the value to be inserted: \n");
    scanf("%d",&ele);
    p->data=ele;
    p->next=NULL;
    if(head==NULL){
        head=p;
        printf("%d is inserted\n",head->data);
        return;
    }
   struct node *temp=head;
   while(temp->next!=NULL){
    temp=temp->next;
   }
   temp->next=p;
   printf("%d is inserted\n",p->data);
}
//insert at a position
void iposition()
{
    int ele,pos;
    struct node p = (struct node)malloc(sizeof(struct node));
    printf("enter the value to be inserted: ");
    scanf("%d",&ele);
    printf("\nenter the position: ");
    scanf("%d",&pos);
    p->data=ele;
    p->next=NULL;
   if(pos==0)
   {
    p->next=head;
    head=p;
    printf("%d is inserted at %d position\n",ele,pos);
    return;
   }
   struct node *temp=head;
   int i=0;
   while(i<pos-1)
   {
    temp=temp->next;
    if(temp==NULL)
    {
        printf("insertion is not posible\n");
        return;
    }
    i++;
   }
  p->next=temp->next;
  temp->next=p;
  printf("%d is inserted at %d postion\n",ele,pos);
}
//delete from the front
void def(){
    if(head==NULL){
        printf("list is empty\n");
        return;
    }
    printf("element deleted is %d\n",head->data);
   struct node *p;
   p=head;
   head=head->next;
   free(p);
}
//delete from last
void dee(){
    struct node *temp, *prev;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else {
        temp=head;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        printf("Deleted item is %d\n",temp->data);
        free(temp);
    }
}
//delete at a position 
void dep(){
    int pos;
    struct node *p;
    printf("Enter the position to be deleted: ");
    scanf("%d",&pos);
    if(pos==0){
        p=head;
        head=head->next;
        printf("%d is deleted at %d postion",p->data,pos);
        free(p);
        return;
    }
    struct node *temp=head;
    int i=0;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    p=temp->next;
    temp->next=p->next;
    printf("%d is deleted at position %d\n",p->data,pos);
    free(p);
}

//display 
void display()
{
    struct node *temp=head;
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
   while(temp!=NULL){
    printf("%d\n",temp->data);
    temp=temp->next;
   }
   printf("\n");
}
//main function
int main()
{
    int ch;
    printf("1.insert at the begining\n 2.insert at end\n 3.Insert at a position\n 4.delete from front\n 5.delete from end\n 6.delete from a position\n 7.Display\n 8.exit\n");
    while(1){
        printf("enter your choice: \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : ifront();
            break;
            case 2 : iend();
            break;
            case 3 : iposition();
            break;
            case 4 : def();
            break;
            case 5 : dee();
            break;
            case 6 : dep();
            break;
            case 7 : display();
            break;
            case 8 : exit(0);
            break;
            default : printf("invalid");
        }
    }
}