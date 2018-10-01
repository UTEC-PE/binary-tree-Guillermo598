#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <iostream>
#include "iterator.h"
#include <vector>
using namespace std;

template <typename T>
class Tree {
private:
    Node<T>* root;
    Node<T>* current;
    vector<auto> stack;

public:

    Tree() {
        root = nullptr;
    };

    bool search(int value, Node<T>* &aux){
        aux = root;
        while (aux -> data != value) {
            if (aux -> data > value)
                aux = aux -> left;
            else
                aux = aux -> right;
        }
        if (aux == nullptr)
            return false;
        else
            return true;
    }

    void insert(int value) {
        if (!root) {
            Node<T>* temp = new Node<T>(value);
            root = temp;
            current = root;
        }
        else {
            if (current -> data > value) {
                if (!current -> left) {
                    Node<T>* temp = new Node<T>(value);
                    current -> left = temp;
                    current = root;
                }
                else {
                    current = current -> left;
                    insert(value);
                }
            }
            else if (current -> data < value) {
                if (!current -> right) {
                    Node<T>* temp = new Node<T>(value);
                    current -> right = temp;
                    current = root;
                }
                else {
                    current = current -> right;
                    insert(value);
                }
            }
            else if (current -> data == value){
                cout << "Number already in tree" << endl;
                current = root;
            }

        }
    };

    void remove(int value) {
        current = root;
        if (search(value, current)) {
            if (current -> left) {
                Node<T> *tmp = current->left;
                while (tmp->right)
                    tmp = tmp->right;
                current->data = tmp->data;
                tmp->killSelf();
            }
            else if (current -> right) {
                Node<T> *tmp = current->right;
                while (tmp->left)
                    tmp = tmp->left;
                current->data = tmp->data;
                tmp->killSelf();
            }
            else {
                Node<T> *tmp = current;
                tmp->killSelf();
            }
        }
        else
            cout << "No number in tree to remove" << endl;
    };

    void print() {
        Iterator<int>* ite = new Iterator<T>(root);
        for (ite->begin(); ite!=ite->end(); ite++) {
            cout << current -> data;
        }
    };


    ~Tree() {
        root -> killSelf();
    };
};

#endif
