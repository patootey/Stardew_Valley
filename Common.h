#ifndef _COMMON_H

#include <iostream> 
#include <iomanip>  
#include <cctype> 

const int  MAXCHAR = 200; 

char lesChar(const char* t)  {
    char tegn;
    std::cout << t << ":  ";
    std::cin >> tegn;  std::cin.ignore(MAXCHAR, '\n');
    return (toupper(tegn));
}

#endif