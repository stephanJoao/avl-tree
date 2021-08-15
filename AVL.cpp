#include "AVL.h"

//AVL constructor
template <class TYPE>
AVL<TYPE>::AVL() {
    root = NULL;
}

//AVL destructor
template <class TYPE>
AVL<TYPE>::~AVL() {
    //dtor
}

template <class TYPE>
TYPE AVL<TYPE>::getRoot() {
    if(root != NULL)
        return root->getKey();
    else {
        cout << "Empty tree!" << endl;
        exit(1);
    }
}

//Auxiliary to BST search
template <class TYPE>
bool AVL<TYPE>::auxSearch(NodeAVL<TYPE>* n, TYPE val) {
    if(n == NULL)
        return false;
    else if(val == n->getKey())
        return true;
    else if(val < n->getKey())
        return auxSearch(n->getLeft(), val);
    else
        return auxSearch(n->getLeft(), val);
}

//BST search
template <class TYPE>
bool AVL<TYPE>::searchBST(TYPE val) {
    return auxSearch(root, val);
}

//Auxiliary to BST insertion
template <class TYPE>
NodeAVL<TYPE>* AVL<TYPE>::auxInsert(NodeAVL<TYPE>* n, TYPE val) {
    if(n == NULL) {
        n = new NodeAVL<TYPE>(val);
    }
    else if(val < n->getKey())
        n->setLeft(auxInsert(n->getLeft(), val));
    else if(val > n->getKey())
        n->setRight(auxInsert(n->getRight(), val));
    else {
        cout << "The value is already in the tree!" << endl;
    }
    return n;
}

//BST insertion
template <class TYPE>
void AVL<TYPE>::insertBST(TYPE val) {
    root = auxInsert(root, val);
}

//AVL left rotation
template <class TYPE>
void AVL<TYPE>::leftRotation(NodeAVL<TYPE>* n) {
    NodeAVL<TYPE>* aux = n->getRight();
    n->setRight(aux->getLeft());
    aux->setLeft(n);
}

//AVL right rotation
template <class TYPE>
void AVL<TYPE>::rightRotation(NodeAVL<TYPE>* n) {
    NodeAVL<TYPE>* aux = n->getLeft();
    n->setLeft(aux->getRight());
    aux->setRight(n);
}

//AVL double left rotation
template <class TYPE>
void AVL<TYPE>::doubleLeftRotation(NodeAVL<TYPE>* n) {
    NodeAVL<TYPE>* aux = n->getRight();
    NodeAVL<TYPE>* aux2 = aux->getLeft();
    n->setRight(aux2->getLeft());
    aux->setLeft(aux2->getRight());
    aux2->setLeft(n);
    aux2->setRight(aux);
}

//AVL double right rotation
template <class TYPE>
void AVL<TYPE>::doubleRightRotation(NodeAVL<TYPE>* n) {
    NodeAVL<TYPE>* aux = n->getLeft();
    NodeAVL<TYPE>* aux2 = aux->getRight();
    n->setLeft(aux2->getRight());
    aux->setRight(aux2->getLeft());
    aux2->setRight(n);
    aux2->setLeft(aux);
}

//Auxiliary to printing
template <class TYPE>
void AVL<TYPE>::auxPrint(string prefix, NodeAVL<TYPE>* n, bool left) {
    if(n != NULL) {
        cout << prefix;
        cout << (left ? "├──" : "└──");
        cout << n->getKey() << endl;
        auxPrint(prefix + (left ? "│   " : "    "), n->getLeft(), true);
        auxPrint(prefix + (left ? "│   " : "    "), n->getRight(), false);
    }
}

//Printing
template <class TYPE>
void AVL<TYPE>::print(){
    auxPrint("", root, false);
}

//Here is the explicit instantiation of the
//template types I'll want and need
template class AVL<int>;