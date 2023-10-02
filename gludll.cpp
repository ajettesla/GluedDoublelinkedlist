#include "gludll.h"
#include <iostream>

int gdll::numberOfNodes = 0;

gdll::gdll(int data, std::string name){
    gdll_struct *stru = new gdll_struct;
    stru->data = data;
    stru->name = name;
    stru->glnode.left = NULL;
    stru->glnode.right = NULL;
    this->node = &(stru->glnode);
    gdll::numberOfNodes ++;
}

gdll::~gdll(){
}

void gdll::pushData(int data, std::string name){
    gdll_node *temp = this->node;
    while(temp->right != NULL){
        temp = temp->right;
    }
    gdll_struct *dataTemp = new gdll_struct;
    dataTemp->data = data;
    dataTemp->name = name;
    dataTemp->glnode.left = temp;
    dataTemp->glnode.right = NULL;
    temp->right = &(dataTemp->glnode);
}

void gdll::pushDataat(int data, std::string name, int pos){
    gdll_node *temp = this->node;
    while(pos != 1){
        pos--;
        temp = temp->right;
    }
    gdll_struct *tempData = new gdll_struct;
    tempData->data = data;
    tempData->name = name;
    tempData->glnode.right = temp->right;
    tempData->glnode.left = temp;
    temp->right = &(tempData->glnode);
}

void gdll::deleteData(int pos){
    gdll_node *temp = this->node;
    while(pos != 1){
        temp = temp->right;
        pos--;
    }
    temp->left->right = temp->right;
    temp->right->left = temp->left;
    size_t offset = offsetof(gdll_struct, glnode);
    gdll_struct *b = reinterpret_cast<gdll_struct*>(reinterpret_cast<char*>(temp) - offset);
    delete b;

    
}

void gdll::printData(){
     gdll_node *temp = this->node;
     while(temp != NULL){
        size_t offset = offsetof(gdll_struct, glnode);
        gdll_struct *b = reinterpret_cast<gdll_struct*>(reinterpret_cast<char*>(temp) - offset);
        std::cout <<"Name is " << b->name << " number is  " << b->data << std::endl;
        temp = temp ->right;
     }
    delete temp;
}