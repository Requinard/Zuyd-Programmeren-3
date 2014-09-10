#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void main(void)
{
	LinkedListHeader list;

	LinkedListContruct(&list);

	while(1)
	{
		fflush(stdin);

		bool quit = false;
		char keuze;

		printf("1 = count, 2 = add front, 3 = add rear, 4 = find index, 5 = print all, 6 = quit: ");
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
		default:
			break;
		}

		printf("\n");

		if(quit)
			break;
	}

	LinkedListDestruct(&list);
}