#include<iostream>
#include<queue>
#include<vector>
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



vector<int> klevel(Node* root , int k){
    queue<Node*> q;
    vector<int> ans;
    q.push(root);
    q.push(NULL);
    int temp = 1;

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr!=NULL){
            if(curr->left){
                q.push(curr->left);
            }

            if(curr->right){
                q.push(curr->right);
            }
        }

        else{
            if(!q.empty()){
                q.push(NULL);
                temp++;
            }
        }

        if(temp == k){
            while(q.front()!=NULL){
                ans.push_back(q.front()->data);
                q.pop();
            }
        }

        if(temp>k){
            break;
        }
        
    }

    return ans;
}