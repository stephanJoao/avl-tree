#ifndef NODEAVL_H
#define NODEAVL_H

#include <iostream>

using namespace std;

//Node for a AVL Tree
template <class TYPE>
class NodeAVL {

    //Functions
    public:
        NodeAVL();
        NodeAVL(TYPE val);
        ~NodeAVL();

        void setLeft(NodeAVL *n) { left = n; };
        void setRight(NodeAVL *n) { right = n; };
        void setKey(TYPE k) { key = k; };
        void setBf(int val) { fb = val; };

        NodeAVL* getLeft() { return left; };
        NodeAVL* getRight() { return right; };
        TYPE getKey() { return key; };
        int getBf() { return fb; };

    private:

    //Variables
    public:

    private:
        NodeAVL *left;
        NodeAVL *right;
        TYPE key;
        short bf; //balance factor = right height - left height

};

template <class TYPE>
NodeAVL<TYPE>::NodeAVL() {
    left = NULL;
    right = NULL;
}

template <class TYPE>
NodeAVL<TYPE>::NodeAVL(TYPE val) {
    key = val;
    left = NULL;
    right = NULL;
}

template <class TYPE>
NodeAVL<TYPE>::~NodeAVL() {
    delete left;
    delete right;
}

#endif // NodeAVL_H