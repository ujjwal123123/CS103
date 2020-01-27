#include <malloc.h>
#include <stdio.h>

// Find length of a string
int length(char* string)
{
    int length = 0;

    while (string[length])
        length++;

    return length;
}

// Returns 0 if strings are same, otherwise returns difference in ASCII value of characters which are different
int compare(char* str1, char* str2)
{
    while (*str1 && *str1 == *str2) {
        str1++;
        str2++;
    }

    // TODO: Why does this work in case of "Hello!" and "Hello!!"
    return (*str1 - *str2);
}

// Returns 1 if strings are same and 0 otherwise
int areSame(char* str1, char* str2)
{
    if (compare(str1, str2) == 0)
        return 1;

    return 0;
}

// Checks if a character occurs in a string
int charInString(char* str, char ch)
{
    while (*str)
        if (*(str++) == ch)
            return 1;

    return -1;
}

// Concatenates two strings
char* concatenate(char* str1, char* str2, int n)
{
    char* newString = (char*)malloc(2 * n * sizeof(char));

    int i = 0;
    while (*str1)
        newString[i++] = *(str1++);
    while (*str2)
        newString[i++] = *(str2++);

    newString[i] = '\0';

    return newString;
}

// Find the first character in first string that matches any character specified in second string
char commonChar(char* str1, char* str2)
{
    while (*str1) {
        char* temp = str2;
        while (*temp) {
            if (*str1 == *temp)
                return *str1;

            temp++;
        }
        str1++;
    }

    return 0;
}

// Search for the last occurrence of a given character in a string and return index
int lastOccurrence(char* str, char ch)
{
    int index = 0;

    while (*str) {
        if (*(str + index) == ch)
            return index;
        index++;
    }

    return -1;
}

// TODO: for some reason, the below two function always result in segmentation fault

// // Reverse a string
// // TODO: this function is not working
// int reverse(char* string)
// {
//     int strlen = length(string);

//     char* start = string;
//     char* end = string + strlen - 1;

//     while (start < end) {
//         char temp = *end;
//         *end = *start;
//         *start = temp;

//         start++;
//         end--;
//     }

//     return 0;
// }

// Reverse a string in place
int reverse(char* string)
{
    int l = length(string);
    int i = 0;
    while (i < l - i - 1) {
        char temp = string[i];
        string[i] = string[l - i - 1];
        string[l - i - 1] = temp;
        i++;
    }

    return 0;
}