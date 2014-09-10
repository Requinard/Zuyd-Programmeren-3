#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedListNode {
	//Definie�r datatypes
	int data;
	//Einde data van struct
	LinkedListNode* next;
};

typedef struct LinkedListHeader
{
	int count;
	LinkedListNode* head;
};

void LinkedListContruct(LinkedListHeader*);
bool LinkedListDestruct(LinkedListHeader*);
int LinkedListCount(LinkedListHeader*);
void LinkedListAddRear(LinkedListHeader*, LinkedListNode*);
void LinkedListAddFront(LinkedListHeader*, LinkedListNode*);
LinkedListNode* LinkedListItem(LinkedListHeader*, int);
//LinkedListHeader* LinkedListDeepCopy(LinkedListHeader*);


