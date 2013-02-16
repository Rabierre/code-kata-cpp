//
//  main.cpp
//  code-kata-cpp2
//
//  Created by 서 지혜 on 13. 2. 11..
//  Copyright (c) 2013년 rabierre. All rights reserved.
//

#include "UniqueCharSequence.h"
#include <vector>

int main(int argc, const char * argv[])
{
    cout<<"SIZE OF CHAR : "<<sizeof(char)<<endl;
    cout<<"SIZE OF BOOL : "<<sizeof(bool)<<endl<<endl;
    
    // todo time, memory 계산
    // 1.1 문자열에서 문자가 중복되어 포함되어 있는지 검사하기.
    isUniqueAsciiChars("abcdefghijklmnopqrstuvwxyz")? cout<<"TEST PASS\n" : cout<<"TEST FAIL\n";
    isUniqueAsciiChars("duplication in here!")? cout<<"TEST FAIL\n" : cout<<"TEST PASS\n";
    
    //
    int b=5,i;
    i=b++ + ++b + ++b + ++b + b++;
    printf("%d\n",i);
    
    // vector 무효화 테스트
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    
    int* ptrV = &v[3];
    cout<<"&v[3] : " << *ptrV<<endl;
    
    auto iterVec = v;                   // iterator의 원소만 삭제, v는 영향받지 않는다..!
    iterVec.erase(iterVec.cbegin());    // vector가 배열 크기를 늘릴 때의 무효화를 테스트하고싶다..
    
    cout<<"size : "<<v.size()<<" &v[3] : " << *ptrV<<endl;  // v size 변함없음
    
    return 0;
}	

            