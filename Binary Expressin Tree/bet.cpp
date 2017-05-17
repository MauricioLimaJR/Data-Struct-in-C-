#ifndef NULL
#define NULL 0
#define STANDARD_VALUE 0
#endif
#include <iostream>
#include <string>
#include "bet.h"
#include "expstack.h"
using namespace std;

BetNode::BetNode(string element){
  this->element = element;
  left = NULL;
  right = NULL;
}
void BetNode::see(int depth){
  if(right != NULL){
    right->see(depth+1);
  }
  for(int i=0; i<depth; i++)cout << "--";
  cout << element << endl;
  if(left != NULL){
    left->see(depth+1);
  }
}

Betree::Betree(){
  root = NULL;
}

void Betree::insert(string expression){
  ExpStack<BetNode*> nodes_stack;
  ExpStack<BetNode*> operators;
  BetNode *aux;
  
  int p, i, c=0;
  for(p=0; expression[p] != 0; p++, c=0){
    i = expression[p];
    //if(expression[p] >= 48 || expression[p] <= 57)
    if(i >= 48 && i <= 57){
      c=p;
      while(i >= 48 && i <= 57){
        p++;
        i = expression[p];
      }
      //cout << "end" << c << "--" << p <<" = " +expression.substr(c, p-c) << endl;
      nodes_stack.push(new BetNode(expression.substr(c, p-c)));
      p--;
    }
    else if(i >= 97 && i <= 122){
      //cout << p << " = "+expression.substr(p,1)  << endl;
      nodes_stack.push(new BetNode(expression.substr(p,1)));
    }
    else if(i == 42 || i == 43 || i == 45 || i == 47){
      //cout << p << " = "+expression.substr(p,1) << endl;
      operators.push(new BetNode(expression.substr(p,1)));
    }
    else if(i == 41){
      BetNode *node = operators.pop();
      node->right = nodes_stack.pop();
      node->left = nodes_stack.pop();
      
      nodes_stack.push(node);
    }
  }
  root = nodes_stack.pop();
}

int Betree::calculate(){
  return postOrderPercentage(root);
}

int Betree::postOrderPercentage(BetNode *node){
  int dft_return = 0;
  if(node != NULL){
    if(node->left == NULL && node->right == NULL){
       dft_return =  node->element[0];
       if(dft_return >= 48 && dft_return <= 57){
         dft_return =  stoi(node->element);
       }
       else cin >> dft_return;
    }
    else{
      int op1 = postOrderPercentage(node->left);
      int op2 = postOrderPercentage(node->right);
      dft_return = apllyOperator(node->element, op1, op2);
    }
  }
  cout << dft_return << endl;
  return dft_return;
}

int Betree::apllyOperator(string op, int op1, int op2){
  int dft_return = 0;
  switch((char)op[0]){
    case '+':
      dft_return = op1 + op2; break;
    case '-':
      dft_return = op1 - op2; break;
    case '*':
      dft_return = op1 * op2; break;
    case '/':
      dft_return = op1 / op2; break;
  }
  cout << op1 << " " << op << " " << op2 << " = " << dft_return << endl;
  return dft_return;
}

void Betree::see(){
  root->see(0);
}