#include "infixToPostfix.h"

int main()
{
    char* infix = malloc(100 * sizeof(char));

    // infix = "a+b/c+d";

    infix = "3 + 3";

    convertToPostFix(infix);
}