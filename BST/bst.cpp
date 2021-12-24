#include <bits/stdc++.h>

using namespace std;

typedef struct node Node;

struct node{

       int data;
       Node *left;
       Node *right;
};

Node *create_node(int item){
     Node *new_node=(Node*)malloc(sizeof(Node));
     if(new_node==NULL){
       printf("error");
       exit(1);
     }

     new_node->data=item;
     new_node->left=NULL;
     new_node->right=NULL;
     return new_node;
}

void add_left_child(Node *node, Node *child){
     node->left=child;
}

void add_right_child(Node *node, Node *child){
     node->right=child;
}

Node *bst_insert(Node *root, Node *node){
      Node *parent_node, *current_node;
      if(root==NULL){
         root=node;
         return root;
      }

      parent_node=NULL;
      current_node=root;

      while(current_node!=NULL){
           parent_node=current_node;
           if(node->data<current_node->data){
             current_node=current_node->left;
           }
           else
             current_node=current_node->right;
      }

      if(node->data<parent_node->data){
         add_left_child(parent_node,node);
      }
      else
         add_right_child(parent_node,node);

      return root;
}

void in_order(Node *node){

     if(node->left!=NULL){
        in_order(node->left);
     }

     printf("%d ",node->data);

     if(node->right!=NULL){
        in_order(node->right);
     }
}

int main()
{
    Node *eight=create_node(8);
    Node *root=eight;
    Node *three=create_node(3);
    Node *ten=create_node(10);
    Node *one=create_node(1);
    Node *six=create_node(6);
    Node *forteen=create_node(14);
    Node *four=create_node(4);
    Node *seven=create_node(7);
    Node *thirteen=create_node(13);
    add_left_child(eight,three);
    add_right_child(eight,ten);
    add_left_child(three,one);
    add_right_child(three,six);
    add_right_child(six,seven);
    add_right_child(ten,forteen);

    bst_insert(root,four);
    bst_insert(root,thirteen);

    in_order(root);

    return 0;
}
