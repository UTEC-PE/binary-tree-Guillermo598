#ifndef ITERATOR_H
#define ITERATOR_H


#include "node.h"
#include <vector>
using namespace std;

template <typename T>
class Iterator {
private:
    Node<T>* current;
    Node<T>* root;
    vector<auto> stack;

public:
    Iterator(){
        root = current = nullptr;
    };
    Iterator(Node<T>* node){
        this -> root = node;
    };

    Iterator<T> operator=(Iterator<T> node){
        this -> current = node.current;
        return *this;
    };
    bool operator!=(Iterator<T> cmp){
        return (this -> current != cmp.current);
    };

    T operator*(){
        return current -> data;
    };

    Iterator<T> begin(){
        current = root;
        while (current -> left) {
            stack.push_back(&current);
            current = current -> left;
        }
        return Iterator<T>(this -> current);
    };

    Iterator<T> operator++(){
        if (current -> right) {
            current = current->right;
            while (current->left) {
                stack.push_back(&current);
                current = current->left;
            }
            return current;
        }
        else {
            current = stack.back();
            stack.pop_back();
            return current;
        }
    };

    Iterator<T> end(){
        current = root;
        while (current -> right)
            current = current -> right;
        return Iterator<T>(this -> current);
    };

};

#endif
