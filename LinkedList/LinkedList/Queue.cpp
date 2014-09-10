#include "Queue.h"

void QueueInit(QueueHeader *header)
{
	if(header->count != 0)
	{
		while(header->head != NULL)
		{
			QueueDequeue(header);
		}
	}

	header->count = 0;
	header->head = NULL;
	header->tail = NULL;
}

void QueueDestruct(QueueHeader *header)
{
	while(header->head != NULL)
		QueueDequeue(header);
}

int QueueEnqueue(QueueHeader *header, QueueNode *node)
{
	//Als count null is moet moeten head en tail naar een ding wijzen
	if(header->count == 0)
	{
		node->next = NULL;
		node->isEmpty = false;
		header->head = node;
		header->tail = node;
		header->count++;
		return 1;
	}
	else
	{
		node->next = NULL;
		node->isEmpty = false;
		header->tail->next = node;
		header->tail = node;
		header->count++;
		return 1;
	}
	return 0;
}

QueueNode QueueDequeue(QueueHeader *header)
{
	if(header->count == 0)
	{
		//dummy queue terug geven om aan te geven dat er geen is
		QueueNode dummy = {0};
		dummy.isEmpty = true;
		return dummy;
	}
	else
	{
		//pointer houden voor reference
		QueueNode *postagePaid = header->head;
		//Andere node aanmaken om gegeheugen te kunnen wissen
		QueueNode package = *postagePaid;

		//Als er wel nog iets in de rij staat de pointers veranderen
		if(header->head->next != NULL)
		{
			header->head = header->head->next;
			header->count--;
		}
		//Anders is de head en tail nul
		else
		{
			header->head = NULL;
			header->tail = NULL;
			header->count--;
		}

		//Geheugen van pointer vrijmaken
		free(postagePaid);

		//Pakketje met data terug geven. Dit wordt opgehaald door de garbage collector
		return package;
	}
}

//Geeft het eerste object van de queue zonder deze te verwijderen
QueueNode QueuePeek(QueueHeader *header)
{
	if(header->count == 0)
	{
		//dummy queue terug geven om aan te geven dat er geen is
		QueueNode dummy = {0};
		dummy.isEmpty = true;
		return dummy;
	}
	else
		return *header->head;
}

bool QueueIsEmpty(QueueHeader *header)
{
	if(header->count == 0)
		return true;
	else
		return false;
}

bool QueueCount(QueueHeader *header, int *dst)
{
	if(header->count == 0)
	{
		*dst = -1;
		return false;
	}
	else
		*dst = header->count;

	return true;
}
