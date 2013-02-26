//
//  OptimizedSwitch.h
//  code-kata-cpp
//

#ifndef code_kata_cpp_OptimizedSwitch_h
#define code_kata_cpp_OptimizedSwitch_h

const char* Condition_String(int condition) {
    switch(condition) {
        case 0: return "EQ";
        case 1: return "NE";
        case 2: return "CS";
        case 3: return "CC";
        case 4: return "MI";
        case 5: return "PL";
        case 6: return "VS";
        case 7: return "VC";
        case 8: return "HI";
        case 9: return "LS";
        case 10: return "GE";
        case 11: return "LT";
        case 12: return "GT";
        case 13: return "LE";
        case 14: return "";
        default: return 0;
    }
}

const char* Condition_String2(int condition) {
    if ((unsigned) condition >= 15) return 0;

    // 단 문자열의 길이가 모두 같아야 함. \0을 삽입해서 길이를 맞출 수 있음.
    return &"EQ\0NE\0CS\0CC\0MI\0PL\0VS\0VC\0HI\0LS\0GE\0LT\0GT\0LE\0\0" [
        3 * condition];
}

#endif
