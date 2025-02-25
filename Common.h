#ifndef _COMMON_H

#include <iostream> 
#include <iomanip>  
#include <cctype> 
#include <cstdlib>

const int  MAXCHAR = 200; 

char readChar(const char* t)  {
    char symbol;
    std::cout << t << ":  ";
    std::cin >> symbol;  std::cin.ignore(MAXCHAR, '\n');
    return (toupper(symbol));
}

int readInt(const char* t, const int min, const int max)  {
    char buffer[MAXCHAR] = "";
    int  number = 0;
    bool wrong = false;

    do {
        wrong = false;
        std::cout << t << " (" << min << " - " << max << "):  ";
        std::cin.getline(buffer, MAXCHAR);
        number = atoi(buffer);
        if (number == 0 && buffer[0] != '0')
        {  wrong = true;   std::cout << "\nERROR: Not an integer\n\n";  }
    } while (wrong  ||  number < min  ||  number > max);

    return number;
}


#endif