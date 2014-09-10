#include "LinkedList.h"

void LinkedListContruct(LinkedListHeader *header)
{
	header->count = 0;
	header->head = NULL;
}

bool LinkedListDestruct(LinkedListHeader *header)
{
	if(header->head == NULL)
		return false;
	LinkedListNode *node = header->head;
	LinkedListNode *next = node->next;

	for(int i = 0; i < header->count; i++)
	{
		free(node);
		node = next;
	}

	return true;
}

int LinkedListCount(LinkedListHeader *header)
{
	int cnt = 0;

	if(header->head == NULL)
		return 0;

	LinkedListNode* node = header->head;

	while(1)
	{
		cnt++;

		if(node->next == NULL)
			break;
		else
			node = node->next;
	}

	header->count = cnt;

	return cnt;
}

void LinkedListAddFront(LinkedListHeader *header, LinkedListNode *item)
{
	if(header->head == NULL)
	{
		item->next = NULL;
		header->head = item;
		header->count++;
		return;
	}

	item->next = header->head;
	header->head = item;
	header->count++;
}

void LinkedListAddRear(LinkedListHeader *header, LinkedListNode *item)
{
	LinkedListNode *last = header->head;

	//Als er niks in de lijst zit, als eerste object toevoegen
	if(header->head == NULL)
	{
		header->head = item;
		header->count++;
		return;
	}

	//Laatste object in de lijst vinden
	while(1)
	{
		if(last->next == NULL)
			break;
		else
			last = last->next;
	}

	//Laatste blokje laten wijzen naar nieuw blokje
	last->next = item;

	//Volgende pointer in nieuw blokje naar null laten verwijzen
	item->next = NULL;
	header->count++;
}

LinkedListNode* LinkedListItem(LinkedListHeader *header, int itemNumber)
{
	//Eerst kijken of index binnen lijst valt
	if(itemNumber > header->count)
		return NULL;

	LinkedListNode *node = header->head;

	//aftellen totdat je itemNumber keer door de lijst bent geitereerd
	while(1)
	{
		if(itemNumber == 1)
			break;
		else
		{
			itemNumber--;
			node = node->next;
		}
	}

	return node;
}