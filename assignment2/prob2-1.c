#include <stdio.h>
#include <stdlib.h>

typedef int DATA;

typedef struct node {
	DATA data;
	struct node* next;
} NODE;

typedef NODE* LIST;

int insert(LIST* plist, DATA Data) {
	NODE* new = (NODE*) malloc(sizeof(NODE));

	new->next = NULL;
	new->data = Data;

	if (*plist) {
		new->next = (*plist);
	}

	*plist = new;

	return 0;
}
	 

int print(LIST list) {
	NODE* pnode = list;

	int i = 0;
	while (pnode) {
		printf("%d: %d\n", i++, pnode->data);
		pnode = pnode->next;
	}

	printf("\n\n");

	return 0;
}
	
int addFirstOccur(LIST* ppnode, DATA key, DATA Data) {
	//printf("%d\n", __LINE__);
	NODE* new = (NODE*) malloc(sizeof(NODE));
	new->data = Data;
	new->next = NULL;
	
	NODE* pnode = *ppnode;
	//printf("%d\n", __LINE__);
	while (pnode) {
                if (pnode->data == key) {
	                break;
                }

                pnode = pnode->next;
	}
	//printf("%d\n", __LINE__);
	if (pnode == NULL) {
		fprintf(stderr, "error\n");
		free(new);
		return 1;
	}
	//printf("%d\n", __LINE__);
	new->next = pnode->next;
	pnode->next = new;
	//printf("%d\n", __LINE__);
	return 0;
}

// Write a function to remove the first occurrence of a given data of the list
DATA removeFirstOccurence(LIST* ppnode, DATA key) {
	NODE* pnode = *ppnode;
        
        while (*ppnode) {
                if ((*ppnode)->data == key)
                        break;

                *ppnode = (*ppnode)->next;
        }
        if (*ppnode == NULL) {
                fprintf(stderr, "key value could not be found in the list\n");
                return 1;
        }

	NODE* toDel = *ppnode;
	DATA returnData = (*ppnode)->data;

        *ppnode = (*ppnode)->next;
        
	free(toDel);

	return returnData;		
}

int main() {
	LIST list = NULL;

	insert(&list, 5);
	insert(&list, 7);
	insert(&list, 6);
	insert(&list, 9);

	print(list);

	removeFirstOccurence(&list, 7);

	//printf("%d\n", __LINE__);
	print(list);

	return 0;

}
