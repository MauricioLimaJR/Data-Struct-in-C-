#ifndef NULL
#define NULL 0
#endif

#include <iostream>
#include "tree.h"
using namespace std;

Node::Node(int value){
	data = value;
	left = NULL;
	right = NULL;
}

void Node::see(int depth){
  if(right != NULL){
    right->see(depth+1);
  }
  for(int i=0; i<depth; i++)cout << "--";
  cout << data << endl;
  if(left != NULL){
    left->see(depth+1);
  }
}

Tree::Tree(){
	root = NULL;
}

bool Tree::exists(int value){
	bool boo = false;
	Node *current_node = root;
	while(current_node != NULL){
		if(current_node->data == value){
			 cout << "Finded" << endl;
			 boo = true;
			 break;
		}
		else if(current_node->data > value){
				current_node = current_node->left;
			}
		else if(current_node->data < value){
				current_node = current_node->right;
			}
	}
	return boo;
}

void Tree::insert(int value){
	if(!exists(value)){
		Node *current_node = root;
		if(current_node == NULL){
		  Node *n = new Node(value);
		  root = n;
		  cout << root->data << endl;
		}
		
		while(current_node != NULL){
			if(current_node->data > value){
				if(current_node->left == NULL){
					current_node->left = new Node(value);
					break;
				}
				current_node = current_node->left;
			}
			else{
				if(current_node->right == NULL){
					current_node->right = new Node(value);
					break;
				}
				current_node = current_node->right;
			}
		}
	}
	
}

void Tree::remove(int value){
	if(root != NULL){
		if(root->data == value){
			if(root->left == NULL) root = root->right;
			else if(root->right == NULL) root = root->left;
			else{
				if(root->left->right == NULL){
					root->data = root->left->data;
					root->left = root->left->left;
				}
				else{
					Node *node = root->left;
					while(node->right->right != NULL){node = node->right;}
					root->data = node->right->data;
					node->right = node->right->left;
				}
			}
		}
	}
}

void Tree::del(int value){
  Node *current_node = root;
	while(current_node != NULL){
		if(current_node->data == value){
		  //cout << "deleting === " << current_node->data << endl;
		  //cout << current_node->left->data << "==" <<endl;// current_node->right->data << endl;
      if(current_node->left == NULL) current_node = current_node->right;
			else if(current_node->right == NULL) current_node = current_node->left;
			else{
				if(current_node->left->right == NULL){
					current_node->data = current_node->left->data;
					current_node->left = current_node->left->left;
				}
				else{
					Node *node = current_node->left;
					while(node->right->right != NULL){node = node->right;}
					current_node->data = node->right->data;
					node->right = node->right->left;
				}
	  	}
		}
		else if(current_node->data > value){
			current_node = current_node->left;
		}
		else{
			current_node = current_node->right;
		}
	}
}
	
void Tree::see(int depth){
  root->see(depth);
}
