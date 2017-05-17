#include <iostream>
#include <string>
using namespace std;

class BetNode{
  public:
    string element;
    BetNode* left;
    BetNode* right;
    BetNode(string element);
    void see(int depth);
};

class Betree{
  public:
    BetNode* root;
    Betree();
    void insert(string expression);
    int calculate();
    void see();
  private:
    int postOrderPercentage(BetNode *node);
    int apllyOperator(string op, int op1, int op2);
};