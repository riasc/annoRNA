#include "BinaryTree.h"
#include "Node.h"
#include <cstddef>
#include <iostream>

using namespace std;

BinaryTree::BinaryTree() {
  root = NULL;
}

BinaryTree::~BinaryTree() {}

void BinaryTree::insert(Node *newnode) {
  std::cout << "insert node with key: " << newnode->key << std::endl;  
  Node *temp = NULL;
  Node *top = root; // cache root for traversal
  while(top != NULL) {
    temp = top; // copy position (current root node) 
    if(newnode->key < top->key) {
      top = top->left; 
    }
    else {
      top = top->right; 
    }
  }

  if(temp == NULL) {
    root = newnode;
  }
  else {
    if(newnode->key < temp->key) {
      temp->left = newnode; 
    }
    else {
      temp->right = newnode;
    }
  }
}

Node* BinaryTree::search(int k) {
}


Node* BinaryTree::getRoot() {
  return root;
}

// prints value of root before values of subtrees
void BinaryTree::preorder_tree_walk(Node *ptr) {
  if(ptr != NULL) {
    std::cout << " " << ptr->key << " " << std::endl;
    preorder_tree_walk(ptr->left); 
    preorder_tree_walk(ptr->right); 
  }
}

// prints values of root between values of subtrees  
void BinaryTree::inorder_tree_walk(Node * startnode) {
  if(startnode != NULL) {
    inorder_tree_walk(startnode->left); 
    std::cout << " " << startnode->key << " ";
    inorder_tree_walk(startnode->right); 
  }
}

// prints values of root after values of subtrees
void BinaryTree::postorder_tree_walk(Node * startnode) {
  if(startnode != NULL) {
    inorder_tree_walk(startnode->left); 
    inorder_tree_walk(startnode->right); 
    std::cout << " " << startnode->key << " ";
  }
}
