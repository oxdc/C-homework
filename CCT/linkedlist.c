/*
 * This file is part of the CppCommonTools distribution
 * Copyright (c) 2017 Oxdc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * C Linked List
 *
 * Author : Oxdc
 * Email : frnet2016@gmail.com
 *
 * Last update : 2017-12-17
 * Version : 0.0.0.2 (dev)
 */


#include "linkedlist.h"

void InitializeList(LinkedList* list)
{
	*list = NULL;
}

int IsListEmpty(const LinkedList* list)
{
	return *list == NULL ? TRUE : FALSE;
}

int IsListFull(const LinkedList* list)
{
#if defined(ENABLE_MEMORY_ALLOCATION_CHECK)
	Node * pNode = New(Node, 1);
	Delete(pNode);
#else
	Node * pNode = (Node*)malloc(sizeof(Node));
	free(pNode);
#endif // ! ENABLE_MEMORY_ALLOCATION_CHECK
	return pNode == NULL ? TRUE : FALSE;
}

unsigned int ListCount(const LinkedList* list)
{
	unsigned int count = 0;
	Node* seek = *list;
	while (seek != NULL)
	{
		seek = seek->pNext;
		count++;
	}
	return count;
}

Node* GetListNode(const LinkedList* list, unsigned int location)
{
	if (location >= ListCount(list))
	{
		return NULL;
	}

	Node* seek = *list;
	while (location-- > 0)
	{
		seek = seek->pNext;
	}

	return seek;
}

Item GetListItem(const LinkedList* list, unsigned int location)
{
	Node* seek = GetListNode(list, location);
	if (seek == NULL)
	{
		return NULL;
	}
	else
	{
		return seek->item;
	}
}

int AddItemToList(LinkedList* list, const Item item, unsigned int location)
{
	if (location > ListCount(list))
	{
		return FALSE;
	}

#if defined(ENABLE_MEMORY_ALLOCATION_CHECK)
	Node* pNewNode = New(Node, 1);
#else
	Node* pNewNode = (Node*)malloc(sizeof(Node));
#endif // ! ENABLE_MEMORY_ALLOCATION_CHECK

	if (pNewNode == NULL)
	{
		return FALSE;
	}
	pNewNode->item = item;

	if (location == 0)
	{
		pNewNode->pNext = (*list == NULL ? NULL : *list);
		*list = pNewNode;
	}
	else
	{
		Node* seek = GetListNode(list, location - 1);
		pNewNode->pNext = seek->pNext;
		seek->pNext = pNewNode;
	}
	
	return TRUE;
}

int PushBackToList(LinkedList* list, const Item item)
{
	return AddItemToList(list, item, ListCount(list));
}

int PushFrontToList(LinkedList* list, const Item item)
{
	return AddItemToList(list, item, 0);
}

int DeleteItemFromList(LinkedList* list, unsigned int location)
{
	if (location >= ListCount(list))
	{
		return FALSE;
	}

	Node* seek = *list;
	Node* former = seek;
	while (location-- > 0)
	{
		former = seek;
		seek = seek->pNext;
	}

	if (seek == former)
	{
		*list = seek->pNext;
	}
	else
	{
		former->pNext = seek->pNext;
	}

#if defined(ENABLE_MEMORY_ALLOCATION_CHECK)
	if (FindItem(list, seek->item) < 0)
	{
		Delete(seek->item);
	}
	Delete(seek);
#else
	if (FindItem(list, seek->item) < 0)
	{
		free(seek->item);
	}
	free(seek);
#endif // ! ENABLE_MEMORY_ALLOCATION_CHECK

	return TRUE;
}

int PopBackOfList(LinkedList* list)
{
	return DeleteItemFromList(list, ListCount(list) - 1);
}

int PopFrontOfList(LinkedList* list)
{
	return DeleteItemFromList(list, 0);
}

int FindItem(const LinkedList* list, const Item item)
{
	Node* seek = *list;

	if (seek == NULL)
	{
		return -1;
	}
	else
	{
		int count = 0;
		while (seek != NULL && seek->item != item)
		{
			seek = seek->pNext;
			count++;
		}
		return count;
	}
}

int FindItemByRule(const LinkedList* list, int(*rule)(const Item))
{
	Node* seek = *list;

	if (seek == NULL)
	{
		return -1;
	}
	else
	{
		int count = 0;
		while (seek != NULL && rule(seek->item))
		{
			seek = seek->pNext;
			count++;
		}
		return count;
	}
}

void TraverseList(const LinkedList * list, void(*func)(const Item))
{
	Node* seek = *list;

	while (seek != NULL)
	{
		func(seek->item);
		seek = seek->pNext;
	}
}

void EmptyTheList(LinkedList* list)
{
	Node* former;

	while (*list != NULL)
	{
		former = (*list)->pNext;
#if defined(ENABLE_MEMORY_ALLOCATION_CHECK)
		if (FindItem(list, (*list)->item) < 0)
		{
			Delete((*list)->item);
		}
		Delete(*list);
#else
		if (FindItem(list, (*list)->item) < 0)
		{
			free((*list)->item);
		}
		
		free(*list);
#endif // ! ENABLE_MEMORY_ALLOCATION_CHECK
		*list = former;
	}
}

void ShowHeapOfList(LinkedList * list)
{
	printf("------------------------------------\n");
	printf("List Head @ %p\n", list);
	if (*list != NULL)
	{
		Node* seek = *list;
		while (seek != NULL)
		{
			printf("- Node %p\n", seek);
			printf(" - Item %p\n", seek->item);
			seek = seek->pNext;
		}
	}
	printf("------------------------------------\n\n");
}
