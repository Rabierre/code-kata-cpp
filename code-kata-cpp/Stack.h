//
//  Stack.h
//  code-kata-cpp
//
//  Created by 서 지혜 on 13. 4. 8..
//  Copyright (c) 2013년 rabierre. All rights reserved.
//

#ifndef code_kata_cpp_Stack_h
#define code_kata_cpp_Stack_h

#include <vector>

class Stack {
public:
    const static int MIN_ELEMENT_SIZE = 10;
    
    Stack(int n = MIN_ELEMENT_SIZE) : _data(n), _pos(0) {
        cout<<"Stack(int n) called"<<endl;
    }
    
    long size() {
        return _data.size();
    }
private:
    vector<int> _data;
    int _pos;
};

#endif
