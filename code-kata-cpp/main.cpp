//
//  main.cpp
//  code-kata-cpp
//

#include "CodingInterview1.h"
#include "CodingInterview7.h"
#include "OptimizedSwitch.h"
#include "DivideAndConquer.h"
#include "Stack.h"
#include "CodingInterview4.h"
#include <chrono>
#include <vector>

int main(int argc, const char * argv[])
{
    cout<<"SIZE OF CHAR : "<<sizeof(char)<<endl;
    cout<<"SIZE OF BOOL : "<<sizeof(bool)<<endl<<endl;
    
    // todo time, memory 계산
    // 1.1 문자열에서 문자가 중복되어 포함되어 있는지 검사하기
    isUniqueAsciiChars("abcdefghijklmnopqrstuvwxyz")? cout<<"isUniqueAsciiChars TEST PASS\n" : cout<<"isUniqueAsciiChars TEST FAIL\n";
    isUniqueAsciiChars("duplication in here!")? cout<<"isUniqueAsciiChars TEST FAIL\n" : cout<<"isUniqueAsciiChars TEST PASS\n";
    cout<<endl;
    
    // 1.3 한 문자열이 다른 문자열의 sub-set인지 검사하기
    findSubstring("b", "abc") ? cout<<"findSubstring TEST PASS\n" : cout<<"findSubstring TEST FAIL\n";
    findSubstring("abc", "abc") ? cout<<"findSubstring TEST PASS\n" : cout<<"findSubstring TEST FAIL\n";
    findSubstring("abc", "a") ? cout<<"findSubstring TEST FAIL\n" : cout<<"findSubstring TEST PASS\n";
    findSubstring("abc", "aaa") ? cout<<"findSubstring TEST FAIL\n" : cout<<"findSubstring TEST PASS\n";
    cout<<endl;
    
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

    cout<<"after iterator erase size : "<<v.size()<<" v[3] : " << *ptrV<<endl<<endl;  // v size 변함없음

    // main이 종료될 때 deallocate에서 "malloc: *** error for object 0x1001000e0: pointer being freed was not allocated" 에러 발생
    //v.~vector();

    
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


    // c++은 파라메터가 하나인 생성자를 암시적 형변환에 사용한다.
    Stack stack = 20;   // int를 받는 생성자가 묵시적으로 호출된다
    cout<<"SIZE OF STACK : "<<stack.size()<<endl<<endl;

    // DFS binary tree search
    //     1
    //    / \
    //   2   4
    //  /     \
    // 3       5
    Node* root = new Node;
    root->value = 1;
    root->left = new Node;
    root->left->value = 2;
    root->left->left = new Node;
    root->left->left->value = 3;
    root->right = new Node;
    root->right->value = 4;
    root->right->right = new Node;
    root->right->right->value = 5;

    cout<<"recursive DFS : ";   recursiveDFS(root); cout<< endl;
    cout<<"loop DFS : ";        loopDFS(root);      cout<< endl;

    cout<<"recursive BFS : ";   recursiveBFS(root);  cout<<endl;
    cout<<"loop BFS : ";        loopBFS(root);      cout<<endl;

    return 0;
}