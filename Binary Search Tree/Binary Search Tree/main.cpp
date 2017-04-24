//
//  main.cpp
//  Binary Search Tree
//
//  Created by Shaan Gontia on 23/04/17.
//  Copyright © 2017 Shaan Gontia. All rights reserved.
//

#include <iostream>
using namespace std;

struct node {
    int key;
    struct node *parent;
    struct node *right;
    struct node *left;
};

//The root node of the tree
struct node *root;

/*
 the function initalises the empty node.
 */
node initialiseEmptyNode(int data) {
    struct node *emptyNode = (struct node*) malloc(sizeof(struct node));
    emptyNode->key = data;
    emptyNode->parent = NULL;
    emptyNode->left = NULL;
    emptyNode->right = NULL;
    return *emptyNode;
}

/*
 data : Accepts the data to be travesed right to.
 The function traveses to the left if data < root->key and right if data > root->key
 
 */
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

/*
 BTNode : Accepts the node to be travesed right to.
 The function traveses to the left of the input node and prints the key.
 */
void traverseLeft(node *BTnode) {
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp = BTnode;
    if (temp) {
        cout << temp->key << " ";
        temp = temp->left;
        traverseLeft(temp);
    }
}

/*
 BTNode : Accepts the node to be travesed right to.
 The function traveses to the right of the input node and prints the key.
 */
void traverseRight(node *BTnode) {
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp = BTnode;
    if (temp) {
        cout << temp->key << " ";
        temp = temp->right;
        traverseRight(temp);
    }
}

/*
 The function traverses through the tree and prints in the order
 Root
 Left side nodes
 Right side node
 */
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

void search(int data, node *BTnode) {
    //struct node *temp = (struct node*) malloc(sizeof(struct node));
    // temp = BTnode;
    if (!BTnode) {
        cout << "Data not found " << data << "\n";
    } else if (data == BTnode->key) {
        cout << "Data Found " << data << "\n";
    } else if (data < BTnode->key) {
        return search(data, BTnode->left);
    } else {
        return search(data, BTnode->right);
    }
}

int main(int argc, const char * argv[]) {
    int input, data = 0;
    
    while (input == 0) {
        cout << "Select the action \n" <<
        " 1. Create a tree \n 2. Search Tree \n";
        cin >> input;
        
        if (input == 1) {
            cout << "Enter the value to be inserted : ";
            cin >> data;
            insert(data);
            cout << "Data Inserted \n";
        } else if (input == 2) {
            cout << "Enter the node to searched: ";
            cin >> data;
            search(data, root);
        } else {
            cout << "Invalid input try again \n";
            break;
        }
        cout << "Do you want to continue ? (0 to continue) \n";
        cin >> input;
    }
    return 0;
}
