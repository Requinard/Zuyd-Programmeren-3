#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode {
	//Queue data goes here
	int number;

	//End of queue data. do not touch below
	bool isEmpty;
	QueueNode *next;
};

typedef struct QueueHeader {
	int count;
	QueueNode *head;
	QueueNode *tail;
};

void QueueInit(QueueHeader*);
void QueueDestruct(QueueHeader*);
int QueueEnqueue(QueueHeader*, QueueNode*);
QueueNode QueueDequeue(QueueHeader*);
QueueNode QueuePeek(QueueHeader*);
bool QueueIsEmpty(QueueHeader*);
bool QueueCount(QueueHeader*, int*);