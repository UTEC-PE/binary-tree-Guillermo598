#include "tree.h"
#include <iostream>
using namespace std;

int main(){
    Tree<int> test;
    test.insert(5);
    test.insert(3);
    test.insert(6);
    test.insert(4);
    test.remove(5);
    test.remove(4);
    test.print();
}