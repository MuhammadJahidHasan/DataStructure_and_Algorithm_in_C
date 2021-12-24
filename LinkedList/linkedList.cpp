#include <bits/stdc++.h>

using namespace std;

typedef struct node Node;

struct node{
      int data;
      Node *next;

};

Node *create_node(int item, Node *next){

       Node *new_node=(Node*) malloc(sizeof(Node));

       if(new_node==NULL){
          printf("errors");
          exit(1);

       }

       new_node->data=item;
       new_node->next=next;
       return new_node;
}


Node *remove_node(Node *head, Node *node){

      if(node==head){
         head=node->next;
         free(node);
         return head;
      }

      Node *current_node=head;
      while(current_node!=NULL){
           if(current_node->next==node){
              break;
           }

           current_node=current_node->next;

      }

      if(current_node==NULL){return head;}

      current_node->next=node->next;
      free(node);
      return head;
}

Node *prepend(Node *head, int item){
      Node *new_node=create_node(item,head);
      return new_node;
}

Node *append(Node *head, int item){

      Node *new_node=create_node(item,NULL);
      if(head==NULL){return new_node;}

      Node *current_node=head;
      while(current_node->next!=NULL){
            current_node=current_node->next;
      }

      current_node->next=new_node;
      return head;
}

void insertt(Node *node, int item){
     Node *new_node=create_node(item,node->next);
     node->next=new_node;
}

void print_Linked_List(Node *head){
     Node *current_node=head;
     while(current_node!=NULL){
          printf("%d ",current_node->data);
          current_node=current_node->next;
     }
     printf("\n");
}


int main()
{
    Node *n,*head;
    head=create_node(10,NULL);

    for(int i=1;i<=10;i++){
    int input;
    cin>>input;
   if(input==1){
      printf("remove node");
    }
      else if(input==2){
      printf("prepend\n");
      int item;
      cin>>item;
      head=prepend(head,item);
    }

     else if(input==3){
      printf("append\n");
      int item;
      cin>>item;
      append(head,item);
    }

     else if(input==4){
      printf("insert\n");
      int item;
      cin>>item;
      Node *node,*n;
      node->data;
      insertt(node,item);
    }

    else if(input==5){
      printf("print\n");
      print_Linked_List(head);
    }
}
    return 0;
}
