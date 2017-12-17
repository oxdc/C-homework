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

#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include<stdlib.h>
#include<stdio.h>

/*
 * Enable memory allocation check */
#define ENABLE_MEMORY_ALLOCATION_CHECK

#if defined(ENABLE_MEMORY_ALLOCATION_CHECK)
#include "autoalloc.h"
#endif // ! ENABLE_MEMORY_ALLOCATION_CHECK

typedef void* Item;

typedef struct _linklist_node {
	Item item;
	struct _linklist_node* pNext;
} Node;

typedef Node* LinkedList;

#define TRUE 1
#define FALSE 0

void InitializeList(LinkedList* list);
int IsListEmpty(const LinkedList* list);
int IsListFull(const LinkedList* list);
unsigned int ListCount(const LinkedList* list);
Node* GetListNode(const LinkedList* list, unsigned int location);
Item GetListItem(const LinkedList* list, unsigned int location);
int AddItemToList(LinkedList* list, const Item item, unsigned int location);
int PushBackToList(LinkedList* list, const Item item);
int PushFrontToList(LinkedList* list, const Item item);
int DeleteItemFromList(LinkedList* list, unsigned int location);
int PopBackOfList(LinkedList* list);
int PopFrontOfList(LinkedList* list);
int FindItem(const LinkedList* list, const Item item);
int FindItemByRule(const LinkedList* list, int(*rule)(const Item));
void TraverseList(const LinkedList* list, void(*func)(const Item));
void EmptyTheList(LinkedList* list);
void ShowHeapOfList(LinkedList * list);

#endif // !_LINKED_LIST_H_
