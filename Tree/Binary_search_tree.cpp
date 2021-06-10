#include<iostream>
using namespace std;

struct Node{
  int data;
  Node *left;
  Node *right;
};

Node *createNode(int data){
  Node *newnode = new(nothrow) Node;    //nothrow return NULL pointer in place of throwing exception.
  if(!newnode){
    cout <<"~ Memory Error ~\n";
    return NULL;
  }
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;

  return newnode;
}
// --------------  Insert node O(logn)/O(h) -----------------
Node *insertNode(int data, Node* root){
  if(!root){
    cout <<"~ Root node Intialized in insertNode ~\n";
    return createNode(data);
    }
  else{

    Node *newnode  = createNode(data);

    Node *temp = root;
    Node *temp2;
    while(temp){
      temp2 = temp;
      if(temp->data >= data){
        temp = temp->left;
      }
      else{
        temp = temp->right;
      }
    }
    if(temp2->data >= data){
      temp2->left = newnode;
    }
    else{
      temp2->right = newnode;
    }
    return temp2;

  }
}
// -------------- O(logn)/O(h) -----------------

int SearchNode(int data, Node* root){
  Node *temp = root;
  if(!root){
    return 0;
  }
  while(temp){
    if(temp->data > data){
      temp = temp->left;
    }
    else if(temp->data < data){
      temp = temp->right;
    }
    else{
      cout <<"~ Node exits with given data ~\n";
      return 1;
    }
  }
  cout <<"~ No node exits with given data ~\n";
  return 0;
}

Node* deleteNode(int data, Node *root){
  if(!root){
    cout <<"~ Given node doesn't exists ~\n";
    return NULL;
  }
  if(root->data > data){
    root->left = deleteNode(data,root->left);
  }
  else if(root->data < data){
    root->right = deleteNode(data,root->right);
  }
  else{
    if(!root->left){
      Node *temp = root->right;
      delete root;
      return temp;
    }
    else if(!root->right){
      Node *temp = root->left;
      delete root;
      return temp;
    }
    else{
      Node* temp = root->right;
      while(temp->left){
        temp = temp->left;
      }
      root->data = temp->data;
      root->right = deleteNode(temp->data,root->right);   // possiblity that temp node may have right Node
    }                                                     // so in above line we are deleting node having right child
  }
  return root;
}

void inorder(Node *temp)
{
  if(!temp)
    return;
  inorder(temp->left);        //leftmost
  cout << temp->data << ' ';  // parent node
  inorder(temp->right);       // then right to leftmost
}

//test

int main(){
  Node *root = createNode(1);
  insertNode(2,root);
  insertNode(3, root);
  insertNode(9, root);
  insertNode(17, root);
  insertNode(12, root);
  insertNode(0, root);
  insertNode(78, root);
  inorder(root);
  cout <<"\n";
  deleteNode(3,root);
  SearchNode(3,root);
  inorder(root);
}
