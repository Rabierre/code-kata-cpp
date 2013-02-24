//
//  CodingInterview7.h
//  code-kata-cpp
//
//  Created by 서 지혜 on 13. 2. 24..
//  Copyright (c) 2013년 rabierre. All rights reserved.
//

#ifndef code_kata_cpp_CodingInterview7_h
#define code_kata_cpp_CodingInterview7_h

void swapWithoutTempVar(int* first, int* second) {
    // 둘다 2^8 - 1보다 작다면 가능
    if(*first > 255 && *second > 255) return;
    
    // todo first의 상위 8비트에 second의 값 셋
    *first |= (*second << 8);
    // todo second의 하위 8비트에 하위 first에 8비트 셋
    *second = (*first & 0x00ff);
    // first shift right 8
    *first = (*first >> 8);
}

#endif
