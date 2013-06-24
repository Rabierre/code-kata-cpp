//
//  CondingInterview1.h
//  code-kata-cpp
//

#ifndef __code_kata_cpp2__CodingInterview1__
#define __code_kata_cpp2__CodingInterview1__

#include <iostream>
#include <string>

using namespace std;

using namespace std;

// 문제 1.1
bool isUniqueAsciiChars(string chars)
{
    if(chars.length() > 256)    // 비둘기 집 원리
        return false;
    
    bool checkTable[256];
    memset(checkTable, '\0', 256);
    
    for(int i=0; i<chars.length(); i++) {
        if(checkTable[chars[i]] != '\0')
            return false;
        
        checkTable[chars[i]] = true;
    }
    
    return true;
}

bool isUniqueUnicodeChars(string chars)
{
    if(chars.length() > 65536)  // 비둘기 집 원리
        return false;
    // todo
    
    return true;
}

// 문제 1.3
// if sub is subset of source then return true or false
bool findSubstring(string sub, string source) {
    if(sub.length() > source.length())
        return false;
    
    for(int i=0; i<source.length(); i++) {
        if(source[i] == sub[0]) {
            if((source.length() - i) < sub.length())
                return false;
            if(source[i + sub.length() - 1] != sub[sub.length() - 1])
                continue;
            
            // sequence compare
            if(source.substr(i, sub.length()).compare(sub) == 0)
                return true;
        }
    }
    return false;
}

// todo 문제 1.5
// 문자열 압축하기
void compressString(string words) {
    // assume that chars has only ascii codes
    int countWords[256];
    memset(countWords, 0, 256);
    
    for(int i=0; i<words.length()-1; i++) {
        countWords[words[i]]++;
    }
    
    // todo print compressed words
}

#endif /* defined(__code_kata_cpp__CodingInterview1__) */
