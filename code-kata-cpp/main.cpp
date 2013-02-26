//
//  main.cpp
//  code-kata-cpp
//

#include "CodingInterview1.h"
#include "CodingInterview7.h"
#include "OptimizedSwitch.h"
#include "DivideAndConquer.h"
#include <chrono>
#include <vector>

int main(int argc, const char * argv[])
{
    cout<<"SIZE OF CHAR : "<<sizeof(char)<<endl;
    cout<<"SIZE OF BOOL : "<<sizeof(bool)<<endl<<endl;
    
    // todo time, memory 계산
    // 1.1 문자열에서 문자가 중복되어 포함되어 있는지 검사하기.
    isUniqueAsciiChars("abcdefghijklmnopqrstuvwxyz")? cout<<"TEST PASS\n" : cout<<"TEST FAIL\n";
    isUniqueAsciiChars("duplication in here!")? cout<<"TEST FAIL\n" : cout<<"TEST PASS\n"<<endl;
    
    // 임시 변수 없이 두 값 바꾸기
    int first = 254, second = 255;
    cout<<"Before swap first : "<<first<<" second : "<<second<<endl;
    swapWithoutTempVar(&first, &second);
    cout<<"After swap first : "<<first<<" second : "<<second<<endl<<endl;
    
    // 연산자 우선순위 테스트
    int b=5,i;
    i=b++ + ++b + ++b + ++b + b++;
    cout<<"b++ + ++b + ++b + ++b + b++ : "<<i<<endl<<endl;
    
    // vector 무효화 테스트
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    
    int* ptrV = &v[3];
    cout<<"v[3] : " << *ptrV<<endl;
    
    auto iterVec = v;                   // iterator의 원소만 삭제, v는 영향받지 않는다..!
    iterVec.erase(iterVec.cbegin());    // vector가 배열 크기를 늘릴 때의 무효화를 테스트하고싶다..
    
    cout<<"size : "<<v.size()<<" v[3] : " << *ptrV<<endl<<endl;  // v size 변함없음
    
    // switch문에서의 문자열 반환 최적화
    cout<<"SWITCH STRING OPTIMIZATION : "<<Condition_String(10)<<endl;
    cout<<"SWITCH STRING OPTIMIZATION : "<<Condition_String2(10)<<endl;
    
    // 큰 수의 연속적인 계산을 Divide and Conquer로 나누었을 때의 상수 시간 복잡도 계산
    // 10!은 simpleFactorial 더 빠름. 500!은 DivideAndConquerFactorial이 더 빠름
    auto start = chrono::high_resolution_clock::now();
    cout<<"recursive 500! result : "<<simpleFactorial(500);
    auto end = chrono::high_resolution_clock::now();
    cout<<" took : "<<chrono::duration_cast<chrono::nanoseconds>(end - start).count()<<endl;
    
    start = chrono::high_resolution_clock::now();
    cout<<"dived and conquer 500! result : "<<DivideAndConquerFactorial(500);
    end = chrono::high_resolution_clock::now();
    cout<<" took : "<<chrono::duration_cast<chrono::nanoseconds>(end - start).count()<<endl;
    
    return 0;
}	

            