// Convert infix to postfix and evaluate

#include "stacks.h"
#include <malloc.h>
#include <stdio.h>

#define RTL 1
#define LTR -1

int precedence(char ch)
{
    switch (ch) {
    case '^':
        return 3;
        break;
    case '/':
        return 2;
        break;
    case '*':
        return 2;
        break;
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    default:
        return 0;
    }
}

// check for operands -- a to z, A to Z and 0 to 9
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

int charToInt(char ch)
{
    return ch - '0';
}

int my_exp(int base, int exponent)
{
    int ans = 1;
    while (exponent--) {
        ans *= base;
    }
    return ans;
}

int evaluateHelper(int op1, int op2, char operand)
{
    switch (operand) {
    case '/':
        return op1 / op2;
        break;
    case '*':
        return op1 * op2;
        break;
    case '-':
        return op1 - op2;
        break;
    case '+':
        return op1 + op2;
        break;
    case '^':
        return my_exp(op2, op1);
        break;
    default:
        fprintf(stderr, "Invalid operation\n");
        return -1;
    }
}

int evaluate(char* postfix, int len)
{
    // ans is a stack of integers
    STACK ans = NULL;

    for (char* ch = postfix; ch < postfix + len; ch++) {
        if (isOperand(*ch))
            push(&ans, charToInt(*ch));

        else if (isOperator(*ch))
            push(&ans, evaluateHelper(pop(&ans), pop(&ans), *ch));

        else {
            fprintf(stderr, "Error occured.\n");
            return -1;
        }
    }

    printf("The ans is :%d\n", pop(&ans));
    return 0;
}

char* convertToPostFix(char* infix)
{
    STACK operators = NULL;
    char* postfix = (char*)malloc(sizeof(char) * 100);
    int len = 0;

    for (char* ch = infix; *ch != '\0'; ch++) {

        // deal with the brackets
        if (*ch == '(')
            push(&operators, *ch);

        else if (*ch == ')') {
            while (!isEmpty(operators) && peek(operators) != '(')
                postfix[len++] = pop(&operators);

            // pop '(' from the stack and do not push it into output
            pop(&operators);
        }

        // deal with operands
        else if (isOperand(*ch))
            postfix[len++] = *ch;

        // if operator follows right to left associativity
        else if (associativity(*ch) == RTL) {
            while (!isEmpty(operators) && precedence(*ch) < precedence(peek(operators)))
                postfix[len++] = pop(&operators);

            push(&operators, *ch);
        }

        // if operator follows left to right associativity
        else if (associativity(*ch) == LTR) {
            while (!isEmpty(operators) && precedence(*ch) <= precedence(peek(operators)))
                postfix[len++] = pop(&operators);

            push(&operators, *ch);
        }
    }

    // finally transfer all the leftover operators to output
    while (!isEmpty(operators))
        postfix[len++] = pop(&operators);

    printchararr(postfix, len);

    evaluate(postfix, len);

    // free operators stack and output array
    freeStack(&operators);
    free(postfix);

    return postfix;
}