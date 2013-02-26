//
//  CodingInterview7.h
//  code-kata-cpp
//

#ifndef code_kata_cpp_CodingInterview7_h
#define code_kata_cpp_CodingInterview7_h

// 입력받은 두 변수의 사용하지 않는 상위 비트를 이용해 swap.
// 하지만 r-value도 임시변수인데!!
void swapWithoutTempVar(int* first, int* second) {
    // 둘다 2^8 - 1보다 작다면 가능
    if(*first > 255 || *second > 255) return;
    
    *first |= (*second << 8);
    *second = (*first & 0x00ff);
    *first = (*first >> 8);
}

// todo diff를 이용한 계산..
#endif
