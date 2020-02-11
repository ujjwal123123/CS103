#include "stacks.h"
#include <malloc.h>
#include <stdio.h>

#define RTL 1
#define LTR -1

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '/')
        return 2;
    else if (ch == '*')
        return 2;
    else if (ch == '+')
        return 1;
    else if (ch == '-')
        return 1;
    else
        return 0;
}

// check for operands
int isOperand(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return 1;
    else if (ch >= 'A' && ch <= 'Z')
        return 2;
    else if (ch >= '0' && ch <= '9')
        return 3;
    else
        return 0;
}

int associativity(char ch)
{
    if (ch == '^')
        return RTL;
    
    else if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
        return LTR;

    // not an operator
    return 0;
}

int isOperator(char ch)
{
    return associativity(ch);
}

int printchararr(char* arr, int length)
{
    for (int i = 0; i < length; i++) 
        printf("%c ", arr[i]);
    
    printf("\n");
    return 0;
}

int evaluateHelper((int) op1, (int) op2, char operand) {
    if (operand == '/')
        return op1 / op2;
    else if (operand == '*')
        return op1 * op2;
    else if (operand == '-')
        return op1 - op2;
    else if (operand == '+')
        return op1 + op2;
}

int evaluate(int *postfix, int len)
{
    STACK ans = NULL;
    STACK operators = NULL;

    char* ch = postfix;

    if (isOperand(*ch)) {
        push(&ans, (int)*ch);
        ch++;
    }

    else if (isOperator(*ch)) {
        push(&ans, evaluateHelper(pop(&ans), pop(&ans), pop(&operators)));
    }

    return pop(&ans);
}

char* convertToPostFix(char* infix)
{
    STACK operators = NULL;
    char* output = (char*) malloc(sizeof(char) * 100);
    int len = 0;

    for (char* ch = infix; *ch != '\0'; ch++) {

        // deal with the brackets
        if (*ch == '(')
            push(&operators, *ch);

        else if (*ch == ')') {
            while (!isEmpty(operators) && peek(operators) != '(')
                output[len++] = pop(&operators);
            
            // pop '(' from the stack
            pop(&operators);
        }

        // deal with operands
        else if (isOperand(*ch))
            output[len++] = *ch;

        // if follows right to left associativity
        else if (associativity(*ch) == RTL) {
            while (!isEmpty(operators) && precedence(*ch) < precedence(peek(operators)))
                output[len++] = pop(&operators);

            push(&operators, *ch);
        }

        // operator follows left to right associativity
        else if (associativity(*ch) == LTR) {
            while (!isEmpty(operators) && precedence(*ch) <= precedence(peek(operators)))
                output[len++] = pop(&operators);

            push(&operators, *ch);
        }
    }

    // finally transfer all the leftover operators to output
    while (!isEmpty(operators))
        output[len++] = pop(&operators);
    
    printchararr(output, len);

    evaluate(output, len);

    // free operators stack and output array
    free(operators);
    free(output);

    return output;
}