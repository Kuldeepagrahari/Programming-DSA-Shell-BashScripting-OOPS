#include<bits/stdc++.h>
using namespace std;

class Tree{
    public:
    int data;
    Tree *left;
    Tree *right;

    Tree(int d){
        data = d;
        left = right = nullptr;
    }
};

void traversal ( Tree*root ){
    if ( root ){
        cout << root-> data << " ";
        traversal (root -> left);
        traversal (root -> right);
    }
}

void TreeConstruction (Tree*root){
    
}

int main(){
        Tree* root = new Tree(0);
    
    // int arr[] = {0, 1,2,}

    // for ( int i = 1; i < 5; i++ ){
        // Tree* child = new Tree(1);
        for ( int i = 0 ; i < 7; i++ ){
               Tree*child = new Tree(1);
               root -> 
        }
        root -> left = new Tree(1);
        // Tree* child = new Tree(2);
        // root = root->left;

        root -> right = new Tree(2);
        // Tree* child = new Tree(3);
        root -> left -> right = new Tree(3);
        traversal(root);

    // }
}