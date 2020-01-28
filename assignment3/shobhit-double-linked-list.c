#include <stdio.h>
#include <stdlib.h>

typedef int data;

typedef struct node {
    data value;
    struct node* next;
    struct node* prev;
} node;

node* addbeg(node* head, data val)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->value = val;
    temp->prev = NULL;
    if (head == NULL) {
        temp->next = NULL;
        head = temp;
        return head;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
    return head;
}

void print(node* head)
{
    printf(" ");
    node* temp = head;
    while (temp) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void printback(node* head)
{
    node* temp = head;
    while (temp->next)
        temp = temp->next;
    while (temp) {
        printf(" %d", temp->value);
        temp = temp->prev;
    }
    printf("\n");
}
node* deletefirst(node* head)
{
    node* temp = head;
    if (!temp->next) {
        head = NULL;
        free(temp);
        return head;
    }
    printf("%d is deleted\n ", temp->value);
    temp->next->prev = NULL;
    head = temp->next;
    free(temp);
    return head;
}
node* addend(node* head, data val)
{
    if (!head) {
        head = addbeg(head, val);
        return head;
    }
    node* p = (node*)malloc(sizeof(node));
    p->value = val;
    node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = p;
    p->prev = temp;
    return head;
}
void deletelast(node* head)
{

    node* p = head;
    node* temp;
    if (!head->next) {
        temp = head;
        free(temp);
        head = NULL;
        return;
    }
    while (p->next) {
        p = p->next;
    }
    temp = p;
    temp->prev->next = NULL;
    free(temp);
}
int count(node* head)
{
    int i = 0;
    node* p = head;
    while (p) {
        i++;
        p = p->next;
    }
    return i;
}
node* addpos(node* head, data pos, data val)
{
    if (pos == count(head) + 1) {
        head = addend(head, val);
        return head;
    } else if (pos == 1) {
        head = addbeg(head, val);
        return head;
    }
    node* p = head;
    node* temp;
    temp->value = val;
    int i = 0;
    while (p) {
        i++;
        if (i == pos - 1) {
            temp->next = p->next;
            temp->prev = p;
            p->next->prev = temp;
            p->next = temp;
            return head;
        }
        p = p->next;
    }
    return head;
}
node* removepos(node* head, data pos)
{
    if (pos == 1) {
        head = deletefirst(head);
        return head;
    } else if (pos == count(head)) {
        deletelast(head);
        return head;
    }
    node* p = head;
    int i = 0;
    while (p) {
        i++;
        if (i == pos) {
            node* temp = p;
            p->prev->next = p->next;
            p->next->prev = p->prev;
            free(temp);
            return head;
        }
        p = p->next;
    }
    return head;
}
int main()
{
    node* head = NULL;
    int choice = 1;
    while (choice) {
        printf("1. Enter one to add elements in the begining of the list\n");
        printf("2. To print elements of the list with forward traversal\n");
        printf("3. To print elements of the list with backward traversal\n");
        printf("4. To delete first element of the list\n");
        printf("5. To enter element at the end of the list\n");
        printf("6. To remove the last element of the list\n");
        printf("7. To add element at the position of the list\n");
        printf("8. To remove elements at a postion in the list\n");
        printf("9. To add data after the first occurance of the key elements\n");
        scanf(" %d", &choice);
        switch (choice) {
        case 1: {
            printf("Enter the value you want to enter : ");
            int val;
            scanf(" %d", &val);
            head = addbeg(head, val);
            break;
        }
        case 2: {
            print(head);
            break;
        }
        case 3: {
            printback(head);
            break;
        }
        case 4: {
            head = deletefirst(head);
            break;
        }
        case 5: {
            data val;
            printf("Enter the data to be entered : ");
            scanf(" %d", &val);
            head = addend(head, val);
            break;
        }
        case 6: {
            deletelast(head);
            break;
        }
        case 7: {
            data pos, val;
            printf("Enter position and value which you want to enter :");
            scanf(" %d%d", &pos, &val);
            head = addpos(head, pos, val);
            break;
        }
        case 8: {
            data pos;
            printf("Enter the position at which you want to delete the elements from : ");
            scanf(" %d", &pos);
            head = removepos(head, pos);
            break;
        }
        case 9: {
            data key, val;
            printf("Enter the key value and element you want to add after key element : ");
            scanf(" %d%d", &key, &val);
            int i = 0;
            node* p = head;
            while (p) {
                i++;
                if (p->value == key) {
                    head = addpos(head, ++i, val);
                    break;
                }
                p = p->next;
            }
            break;
        }
        }
    }
    return 0;
}