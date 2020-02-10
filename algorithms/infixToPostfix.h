#include "stacks.h"
#include <malloc.h>
#include <stdio.h>

int opPrecedence(char ch)
{
    if (ch == '^')
        return 5;
    else if (ch == '/')
        return 4;
    else if (ch == '*')
        return 3;
    else if (ch == '+')
        return 2;
    else if (ch == '-')
        return 1;
    else
        return 0;
}

int isOperator(char ch)
{
    if (opPrecedence(ch) == 0)
        return 0;
    else
        return opPrecedence(ch);
}

int isAlpha(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return 1;
    else if (ch >= 'A' && ch <= 'Z')
        return 2;
    else
        return 0;
}

int convertToPostFix(char* infix)
{
    STACK operators = NULL;
    STACK output = NULL;

    // TODO: add support for expressions with bracket
    while (*infix != '\0') {

        // if (*infix == '(')
        //     push(&output, *infix);

        // else if (*infix == ')')
        //     ;


        if (isAlpha(*infix))
            push(&output, *infix);

        else if (isOperator(*infix)) {
            while (!isEmpty(operators) && opPrecedence(*infix) <= opPrecedence(peek(operators)))
                push(&output, pop(&operators));

            push(&operators, *infix);
        }

        infix++;
    }

    while (!isEmpty(operators)) {
        push(&output, pop(&operators));
    }

    STACK orderCorrect = NULL;
    orderCorrect = reverse(output);

    // TODO: correct order in which output is printed
    prints(orderCorrect);

    // TODO: free output stack
    free(operators);
    free(output);

    return 0;
}