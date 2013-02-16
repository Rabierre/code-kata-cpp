//
//  UniqueCharSequence.cpp
//  code-kata-cpp2
//
//  Created by 서 지혜 on 13. 2. 12..
//  Copyright (c) 2013년 rabierre. All rights reserved.
//

#include <iostream>
#include <string>
#include "UniqueCharSequence.h"

using namespace std;

bool isUniqueAsciiChars(string chars)
{
    if(chars.length() > 256)    // 비둘기 집 원리
        return false;
    
    bool* checkTable = new bool[256];
    
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
    
    return true;
}