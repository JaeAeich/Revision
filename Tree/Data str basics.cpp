#include<bits/stdc++.h>
using namespace std;

// class tree

#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;

}

void printT(node* root){
    if(!root) return;

    cout<<root->data<<" ";
    printT(root->left);
    printT(root->right);
}


int main()
{
    // cout<<"run"<<endl;
    node* root=NULL;
    root=buildTree(root);
    printT(root);
    // cout<<"er"<<endl;
    return 0;
}
// Code By - Jae Aeich