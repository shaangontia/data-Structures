//
//  BST Insertion.cpp
//  trees
//
//  Created by Shaan Gontia on 22/04/17.
//  Copyright © 2017 Shaan Gontia. All rights reserved.
//

#include "BST Insertion.hpp"
using namespace std;

struct node {
    int key;
    struct node *parent;
    struct node *right;
    struct node *left;
};

struct node *root;

node initialiseEmptyNode(int data) {
    struct node *emptyNode = (struct node*) malloc(sizeof(struct node));
    emptyNode->key = data;
    emptyNode->parent = NULL;
    emptyNode->left = NULL;
    emptyNode->right = NULL;
    return *emptyNode;
}
void insert(int data) {
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    struct node *current;
    struct node *parent;
    
    *temp = initialiseEmptyNode(data);
    
    if (root == NULL) {
        root = temp;
        return;
    } else {
        current = root;
        parent = NULL;
        while (1) {
            parent = current;
            if (temp->key < parent->key) {
                current = current->left;
                if (current == NULL) {
                    parent->left = temp;
                    temp->parent = parent;
                    return;
                }
            } else {
                current = current->right;
                if(current == NULL){
                    parent->right = temp;
                    temp->parent = parent;
                    return;
                }
            }
        }
    }
}

void traverseLeft(node *BTnode) {
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp = BTnode;
    if (temp) {
        cout << temp->key << " ";
        temp = temp->left;
        traverseLeft(temp);
    }
}

void traverseRight(node *BTnode) {
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp = BTnode;
    if (temp) {
        cout << temp->key << " ";
        temp = temp->right;
        traverseRight(temp);
    }
}

void printTree() {
    
    if (root == NULL) {
        cout <<"Empty Tree";
    } else {
        cout << "Root : " << root->key << "\n";
        cout << "Left Nodes : ";
        traverseLeft(root->left);
        cout << "\n" << "Right Nodes : ";
        traverseRight(root->right);
    }
}

int main(int arg, const char * argv[]) {
    int data, input = 0;
    cout << "--------Begin with the tree insert program--------- \n";
    while (input == 0) {
        cout << "Enter the value to be inserted : ";
        cin >> data;
        insert(data);
        cout << "Data Inserted \n";
        cout << "Do you want to continue to insert data to the Binary Tree ? (0 to continue)";
        cin >> input;
    }
    printTree();
    return 0;
}
