#ifndef AVL_H
#define AVL_H

#include <iostream>

#include "NodeAVL.h"

using namespace std;

//AVL Tree
template <class TYPE>
class AVL {

    //Functions
    public:
        AVL();
        ~AVL();

        TYPE getRoot();
        bool empty() { return (root == NULL); };
        
        bool searchBST(TYPE val);
        void insertBST(TYPE val);

        void print();

    private:
        bool auxSearch(NodeAVL<TYPE> *n, TYPE val);

        void leftRotation(NodeAVL<TYPE> *n);
        void rightRotation(NodeAVL<TYPE> *n);
        void doubleLeftRotation(NodeAVL<TYPE> *n);
        void doubleRightRotation(NodeAVL<TYPE> *n);

        NodeAVL<TYPE>* auxInsert(NodeAVL<TYPE> *n, TYPE val);

        void auxPrint(string prefix, NodeAVL<TYPE>* n, bool left);

    //Variables
    public:

    private:
        NodeAVL<TYPE> *root;

};

#endif // AVL_H