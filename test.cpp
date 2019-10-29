
#include <iostream>
#include "util/util.h"
#include <vector>
using namespace std; 
using namespace vec_ops;

vector<double> create(double a, double b, double c){
  vector<double> x (3);
  x[0] = a;
  x[1] = b;
  x[2] = c;
  return x;
}

int main(){
  cout << "helloworld";
  vector<double> x = create(2,3,1);
  vector<double> y = create(3,2,1);
  cout<<dot(x,y);
}