#include <iostream>
#include "bintree.h"
using namespace std;

int main(){
  Tree tree;
  tree.insert(2);
  tree.insert(21);
  tree.insert(26);
  tree.insert(15);
  tree.insert(10);
  tree.insert(18);
  tree.insert(1);
  tree.insert(14);
  /*
  tree.del(2);
  cout << tree.exists(12) << endl;
  tree.del(15);
  cout << tree.exists(15) << endl;
  */
  tree.see(0);
}