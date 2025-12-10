#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node *next;
} Node;

typedef struct LinkedList{
	Node *head;
	Node *tail;
} LinkedList;

void insert_into_hash(LinkedList *, const int);
unsigned hashTableSize;

int main()
{
	unsigned numTests;
	Node *currentNode;
	int numElements, i, tempElement;

	scanf("%u", &numTests);

	while (numTests--)
	{
		scanf("%u %d", &hashTableSize, &numElements);

		LinkedList hashTable[hashTableSize];
		for (i = 0; i < hashTableSize; ++i)
		{
			hashTable[i].head = NULL;
			hashTable[i].tail = NULL;
		}

		for (i = 0; i < numElements; ++i)
		{
			scanf("%d", &tempElement);
			insert_into_hash(hashTable, tempElement);
		}

		for (i = 0; i < hashTableSize; ++i)
		{    
			printf("%d -> ", i);
			for (currentNode = hashTable[i].head; currentNode; currentNode = currentNode->next)
				printf("%d -> ", currentNode->value);

			printf("\\");
			printf("\n");
		}

		if (numTests)
			printf("\n");
	}

	return 0; 
}

void insert_into_hash(LinkedList *hashTable, const int key)
{
	Node *newNode;
	newNode = (Node *) malloc(sizeof(Node));

	if(!newNode)
		exit(1);

	int index = key % hashTableSize;
	if (hashTable[index].head)
		hashTable[index].tail->next = newNode;
	else
		hashTable[index].head = newNode;

	hashTable[index].tail = newNode;
	newNode->next = NULL;
	newNode->value = key;
}
