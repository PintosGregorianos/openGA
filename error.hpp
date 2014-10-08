#pragma once

#include <iostream>

#ifdef DEBUG_MODE
    #define PRINT_ERROR(string) std::cout << "ERROR: " << string << std::endl
#else
    #define PRINT_ERROR(string)
#endif
