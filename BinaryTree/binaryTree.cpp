#include <bits/stdc++.h>

using namespace std;

typedef struct node Node;

struct node{
       int data;
       Node *left;
       Node *right;
};

Node *create_Node(int item){
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
Node *create_tree(){

      Node *two=create_Node(2);
      Node *seven=create_Node(7);
      Node *nine=create_Node(9);
      Node *one=create_Node(1);
      Node *six=create_Node(6);
      Node *eight=create_Node(8);
      Node *five=create_Node(5);
      Node *ten=create_Node(10);
      Node *three=create_Node(3);
      Node *four=create_Node(4);

      add_left_child(two,seven);
      add_right_child(two,nine);

      add_left_child(seven,one);
      add_right_child(seven,six);

      add_right_child(nine,eight);

      add_left_child(six,five);
      add_right_child(six,ten);

      add_left_child(eight,three);
      add_right_child(eight,four);

      return two;
}

void pre_order(Node *node){

     printf("%d ",node->data);

     if(node->left!=NULL){
        pre_order(node->left);
     }
     if(node->right!=NULL){
        pre_order(node->right);
     }

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

void post_order(Node *node){

     if(node->left!=NULL){
        post_order(node->left);
     }
     if(node->right!=NULL){
        post_order(node->right);
     }
     printf("%d ",node->data);

}

int main()
{
    Node *root=create_tree();
    cout <<root->data<< endl;
    pre_order(root);
    post_order(root);
    in_order(root);
    return 0;
}
