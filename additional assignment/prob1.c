#include "prob1.h"

int main()
{
    char* str1 = (char*)malloc(100 * sizeof(char));

    scanf(" %[^\n]s", str1);
    //str1 = "HEllo! ";
    // char* str2 = "aaaaaaaa";

    printf("%d\n", length(str1));

    // printf("%d\n", compare(str1, str2));

    // printf("%d\n", areSame(str1, str2));

    // printf("%d\n", charInString(str1, 'p'));

    // printf("%s\n", concatenate(str1, str2, 10));

    // printf("%c\n", commonChar(str1, str2));

    // printf("%s\n", reverse(str1));

    // printf("%d\n", lastOccurrence(str1, 'H'));

    reverse(str1);
    printf("%s\n", str1);
}