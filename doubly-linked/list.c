/*
 Name: Daniel Blackley
 Matric number: 160007728
 Module code: AC21008
*/


#include<stdio.h>
#include<stdlib.h>
#include "list.h"

int setupNextNode(ListNode** ListNodePtr, int data);
int setupPrevNode(ListNode** ListNodePtr, int data);


/* Initialize a new List and record its pointer into (*listPtr).
		listPtr must not be NULL
		(*listPtr) must be NULL */
int listInit(List **listPtr) {

  if (listPtr == NULL) { return NULL_PARAM; }
  if (*listPtr != NULL) { return BAD_INIT_PARAM; }


  *listPtr = (struct List*) myMalloc(sizeof(struct List));
  if (*listPtr == NULL) { return OUT_OF_MEMORY; }

  (*listPtr)->head = NULL;
  (*listPtr)->tail = NULL;
  (*listPtr)->curr = NULL;

  return SUCCESS;
}

/* Insert 'data' as a new node into the List immediately before
   the current position ('curr')
		listPtr must not be NULL */
int insertBeforeCurr(List* listPtr, int data) {

  if (listPtr == NULL) { return NULL_PARAM; }

  if (listPtr->head == NULL && listPtr->tail == NULL) {

    listPtr->head = (struct ListNode*) myMalloc(sizeof(struct ListNode));

    if (listPtr->head == NULL) { return OUT_OF_MEMORY; }

    listPtr->curr = listPtr->tail = listPtr->head;

    listPtr->curr->data = data;

  } else {

    int returnStatis = setupPrevNode(&(listPtr->curr), data);

    if (returnStatis == OUT_OF_MEMORY) { return OUT_OF_MEMORY; }

    if (listPtr->head == listPtr->curr) {
      listPtr->head = listPtr->curr->prev;
    }

    listPtr->curr = listPtr->curr->prev;

  }

  return SUCCESS;
}

/* Insert 'data' as a new node into the List immediately after
   the current position ('curr'.)
		listPtr must not be NULL */
int insertAfterCurr(List* listPtr, int data) {


  if (listPtr == NULL) { return NULL_PARAM; }

  if (listPtr->head == NULL && listPtr->tail == NULL) {

    listPtr->head = (struct ListNode*) myMalloc(sizeof(struct ListNode));

    if (listPtr->head == NULL) { return OUT_OF_MEMORY; }

    listPtr->curr = listPtr->tail = listPtr->head;

    listPtr->curr->data = data;

  } else {

    int returnStatis = setupNextNode(&(listPtr->curr), data);

    if (returnStatis == OUT_OF_MEMORY) { return OUT_OF_MEMORY; }

    if (listPtr->tail == listPtr->curr) {
        listPtr->tail = listPtr->curr->next;
    }

    listPtr->curr = listPtr->curr->next;
  }

  return SUCCESS;
}


int setupNextNode(ListNode** listNodePtr, int data) {

  ListNode* listNodeTemp;

    listNodeTemp = (struct ListNode*) myMalloc(sizeof(struct ListNode));

    if (listNodeTemp == NULL) { return OUT_OF_MEMORY; }

    listNodeTemp->data = data;

  if ((*listNodePtr)->next == NULL ) {

    listNodeTemp->prev = *listNodePtr;
    listNodeTemp->next = NULL;
    (*listNodePtr)->next = listNodeTemp;

  } else {

    listNodeTemp->prev = *listNodePtr;
    listNodeTemp->next = (*listNodePtr)->next;
    (*listNodePtr)->next->prev = listNodeTemp;
    (*listNodePtr)->next = listNodeTemp;
  }

  return SUCCESS;
}

int setupPrevNode(ListNode** listNodePtr, int data) {


  ListNode* listNodeTemp;

    listNodeTemp = (struct ListNode*) myMalloc(sizeof(struct ListNode));

    if (listNodeTemp == NULL) { return OUT_OF_MEMORY; }

    listNodeTemp->data = data;

  if ((*listNodePtr)->prev == NULL ) {

    listNodeTemp->next = *listNodePtr;
    listNodeTemp->prev = NULL;
    (*listNodePtr)->prev = listNodeTemp;

  } else {

    listNodeTemp->next = *listNodePtr;
    listNodeTemp->prev = (*listNodePtr)->prev;
    (*listNodePtr)->prev->next = listNodeTemp;
    (*listNodePtr)->prev = listNodeTemp;
  }

  return SUCCESS;
}
