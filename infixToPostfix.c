#include "infixToPostfix.h"

int main()
{
    char* infix = malloc(100 * sizeof(char));

    // infix = "a+b/c+d";

    infix = "a*b/c+d";

    convertToPostFix(infix);
} 