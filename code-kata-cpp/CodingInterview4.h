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

struct Node {
    int value;
    Node* left;
    Node* right;
};

void recursiveDFSVisit(Node* root) {
    if(root == NULL)
        return;
    
    cout<<root->value;
    
    recursiveDFSVisit(root->left);
    recursiveDFSVisit(root->right);
}

void loopDFSVisit(Node* root) {
    if(root == NULL)
        return;
    
    std::stack<Node*> nodes;
    
    while (true) {
        if(root == NULL && nodes.empty())
            return;
        
        if(root != NULL) {
            cout<<root->value;
            nodes.push(root->right);
            root = root->left;
        }
        else {
            root = nodes.top();
            nodes.pop();
        }
    }
}

#endif