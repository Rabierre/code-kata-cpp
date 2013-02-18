//
//  FindSubstring.h
//  code-kata-cpp
//
//  Created by 서 지혜 on 13. 2. 18..
//  Copyright (c) 2013년 rabierre. All rights reserved.
//

#ifndef code_kata_cpp_FindSubstring_h
#define code_kata_cpp_FindSubstring_h

#include <string>

// if sub is subset of source then return true or false
bool FindSubstring(string source, string sub) {
    if(sub.length() > source.length())
        return false;
    
    for(int i=0; i<source.length(); i++) {
        if(source[i] == sub[0]) {
            if((source.length() - i) < sub.length())
                return false;
            if(source[i + sub.length() - 1] != sub[sub.length() - 1])
                return false;
            // todo sequence compare
        }
    }
}

#endif
