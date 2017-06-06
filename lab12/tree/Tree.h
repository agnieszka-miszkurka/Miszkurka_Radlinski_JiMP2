//
// Created by radligna on 30.05.17.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <cstddef>
#include <iostream>

template<class T>
class Tree  {
public:
    T value;
    Tree *left;
    Tree *right;
    int size;
    Tree();

    bool operator<(const Tree &other) const {
        return this->value < other.value;
    }
    Tree<T> Find(T value);
    void Insert(T value);
};
template<class T>
void Tree<T>::Insert(T value) {
    if(size == 0) {
        this->value = value;
        size ++;
    }

    else{
        Tree *new_node = new Tree();
        new_node->value = value; //nowo stworzone dziecko nie ma nullptry na left i right
        new_node->left = nullptr;
        new_node->right = nullptr;
        if(*this < *new_node) {
            if(this->right != nullptr) {
                //delete new_node;
                this->right->Insert(value);
            }

            else {
                this->right = new_node;
                size ++;
            }
        }
        else{
            if(this->left != nullptr){
                std::cout<<"uu";
                //delete new_node;
                this->left->Insert(value);
            }
            else {
                this->left = new_node;
                size ++;
            }
        }
    }
}


template<class T>
Tree<T>::Tree() {
    size = 0;
    left = nullptr;
    right = nullptr;
}


template<class T>
Tree<T> Tree<T>::Find(T value) {
    std::cout<<this->value<<std::endl;
    if(this->value < value) {
        if(this->right != nullptr) {
            this->right->Find(value);
        }
    }
    else if(this->value > value){
        if(this->left != nullptr){
            this->left->Find(value);
        }
    }
    else
        return *this;
}


#endif //JIMP_EXERCISES_TREE_H