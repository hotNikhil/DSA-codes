#include<iostream>
using namespace std;

class Node{
public:

    Node* left;
    Node* right;
    int data;

    Node(int data){
        left = right = nullptr;
        this->data = data;
    }
};


Node* insert(Node* root, int val ){
    if(root == NULL){
        root  = new Node(val);
        return root;
    }

    if(val<root->data){
        root->left = insert(root->left , val);
    }
    else{
        root->right = insert(root->right ,val);
    }

    return root;
}

int main(){
    int arr[] = {};


}