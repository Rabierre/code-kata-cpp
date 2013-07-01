//
//  CodingInterview4.h
//  code-kata-cpp
//
//  Created by 서 지혜 on 13. 6. 25..
//  Copyright (c) 2013년 rabierre. All rights reserved.
//

#ifndef code_kata_cpp_CodingInterview4_h
#define code_kata_cpp_CodingInterview4_h

#include <stack>
#include <queue>

struct Node {
    int value;
    Node* left;
    Node* right;
};

void print(Node* node) {
    if(node == NULL)
        return;
    
    cout<<node->value;
}

void recursiveDFS(Node* root) {
    if(root == NULL)
        return;
    
    print(root);
    
    recursiveDFS(root->left);
    recursiveDFS(root->right);
}

void loopDFS(Node* root) {
    std::stack<Node*> children;
    
    if(root == NULL)
        return;
    
    while (true) {
        if(root == NULL && children.empty())
            return;
        
        if(root != NULL) {
            print(root);
            
            children.push(root->right);
            root = root->left;
        }
        else {
            root = children.top();
            children.pop();
        }
    }
}

void recursiveBFS(queue<Node*> q) {
    if(q.empty()){
        return;
    }
    
    Node* node = q.front();
    if(node != NULL) {
        print(node);
    
        q.push(node->left);
        q.push(node->right);
    }
    q.pop();

    recursiveBFS(q);
}

void recursiveBFS(Node* root) {
    queue<Node*> q;
    q.push(root);
    recursiveBFS(q);
}

void loopBFS(Node* root) {
    std::queue<Node*> children;
    
    while(true) {
        if(root == NULL && children.empty())
            return;
        
        if(root != NULL){
            print(root);
            
            children.push(root->left);
            children.push(root->right);
        }
        
        root = children.front();
        children.pop();
    }
}

#endif