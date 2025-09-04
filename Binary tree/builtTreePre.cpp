#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }

};

//Building binary tree of preorder manner
static int idx = -1;

Node* binaryTree(vector<int> nodes){
    idx++;

    if(nodes[idx] == -1){
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode->left = binaryTree(nodes);
    currNode->right = binaryTree(nodes);
    return currNode;
}

// printing tree in preorder manner

void preorder(Node* root){
    if(root==NULL){
        cout<<"-1"<<" ";
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//Inorder traversal

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//level order traversal

void lot(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int sum = 0;
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr){
            sum +=curr->data;

            if(curr->left){
                q.push(curr->left);
            }

            if(curr->right){
                q.push(curr->right);
            }
        }

        else{
            cout<<sum<<endl;
            sum = 0;
            if(!q.empty()){
                q.push(NULL);
            }
        }
    }
}


int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1}; 
    Node* root = binaryTree(nodes);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    lot(root);

    return 0;
}