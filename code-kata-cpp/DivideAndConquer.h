//
//  DivideAndConquer.h
//  code-kata-cpp
//
//  Created by 서 지혜 on 13. 2. 27..
//  Copyright (c) 2013년 rabierre. All rights reserved.
//

#ifndef code_kata_cpp_DivideAndConquer_h
#define code_kata_cpp_DivideAndConquer_h

// calculate factorial N! with traditional recursive way
int simpleFactorial(int N) {
    if(N <= 1) {
        return 1;
    }
    
    return N * simpleFactorial(N - 1);
}

// calculate factorial N! with divide and conquer
int DivideAndConquerFactorial(int N) {
    int midN = N/2;
    
    // N/2 x (N/2-1) x ... x 1
    int result1 = 1;
    for(int i = midN; i > 0; i--) {
        result1 *= i;
    }
    
    // N x (N-1)... x (N/2+1)
    int result2 = 1;
    for(int i = N; i > midN; i--) {
        result2 *= i;
    }
    
    return result1 * result2;
}

#endif
