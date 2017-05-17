#include <iostream>
#include <string>
#include "bet.h"
#include "expstack.h"
using namespace std;

int main(){
  Betree betree;
  string expression;
  expression = "((4*x)+(45-(24/6)))";
  betree.insert(expression);
  betree.calculate();
  betree.see();
}