#include "LinkedList.h"
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void main(void)
{
	while(1)
	{
		char chc;
		printf("(1)Linked List, (2)Queue: ");
		scanf("%c", &chc);
		if(chc == '1')
		{

			LinkedListHeader list;

			LinkedListContruct(&list);

			bool quit = false;
			char keuze;

			while(1)
			{
				fflush(stdin);

				printf("1 = count, 2 = add front, 3 = add rear, 4 = find index, 5 = print all, 6 = quit: , 7 = Deep Copy");
				scanf("%c", &keuze);

				switch(keuze)
				{
				case '1':
					printf("%d", LinkedListCount(&list));
					break;
				case '2':
					{
					LinkedListNode *eerst = (LinkedListNode*)malloc(sizeof(LinkedListNode));
					printf("Waarde die je wilt invoegen: ");
					scanf("%d", &eerst->data);
					LinkedListAddFront(&list, eerst);
					}
					break;
				case '3':
					{
					LinkedListNode *laatst = (LinkedListNode*)malloc(sizeof(LinkedListNode));
					printf("Waarde die je wilt invoegen: ");
					scanf("%d", &laatst->data);
					LinkedListAddRear(&list, laatst);
					}
					break;
				case '4':
					{
						int index = 0;
						printf("index: ");
						scanf("%d", &index);
						LinkedListNode *node = LinkedListItem(&list, index);
						if(node != NULL)
							printf("Index %d heeft als waarde %d", index, node->data);
					}
					break;
				case '5':
					{
						int cnt = 1;
						while(1)
						{
							LinkedListNode *node = LinkedListItem(&list, cnt);
							if(node != NULL)
							{
								printf("Op index %d is het getal %d\n", cnt, node->data);
								cnt++;
							}
							else
								break;
						}
					}
					break;
				case '6':
					quit = true;
					break;
				case '7':
					{
						LinkedListHeader copiedHeader = {0};
						LinkedListContruct(&copiedHeader);
						LinkedListDeepCopy(&list, &copiedHeader);
						//Gekopieerd. _getch() wordt aangeroepen om te kijken of het ook werkt
						_getch();
					}
					break;
				default:
					break;
				}

				printf("\n");

				if(quit)
				{
					LinkedListDestruct(&list);
					break;
				}
			}
		}
		if(chc == '2')
		{
			QueueHeader header = {0};

			QueueInit(&header);

			bool quit = false;
			char keuze;

			while(1)
			{
				fflush(stdin);

				printf("1=enqueue, 2=dequeue, 3=peek, 4=isempty, 5=count,6=quit: ");
				scanf("%c", &keuze);

				switch(keuze)
				{
				case '1':
					{
						QueueNode *node = (QueueNode*)malloc(sizeof(QueueNode));
						int num = 0;
						printf("Getal om te queuen: ");
						scanf("%d", &num);
						node->number = num;
						QueueEnqueue(&header, node);
					}
					break;
				case '2':
					{
						QueueNode node = QueueDequeue(&header);
						if(!node.isEmpty)
							printf("Het volgende deel van de queue is %d" , node.number);
						else
							printf("De queue is leeg!");
					}
					break;
				case '3':
					{
						QueueNode node = QueuePeek(&header);
						if(!node.isEmpty)
							printf("Na het spieken blijkt dat het volgend nummer %d is" , node.number);
						else
							printf("de queue is leeg!");
					}
					break;
				case '4':
					if(QueueIsEmpty(&header))
						printf("ja");
					else
						printf("nee");
					break;
				case '5':
					{
						int num = 0;
						if(QueueCount(&header, &num))
							printf("Er staan %d nummers in de rij", num);
						else
							printf("Er staan geen nummers meer in de rij");
					}
					break;
				case '6':
					quit = true;
					break;
				default:
					break;
				}

				printf("\n");

				if(quit)
				{
					QueueDestruct(&header);
					break;
				}
			}
		}
	}
}