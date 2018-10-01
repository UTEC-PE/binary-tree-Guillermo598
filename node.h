#ifndef NODE_H
#define NODE_H


template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;

    Node(T data) : data(data) {
        left = right = nullptr;
    };

    void killSelf(){
        if (left)
            left -> killSelf();
        if (right)
            right -> killSelf();
        delete this;
    };

};

#endif