#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

// Linked list node

typedef struct IntNode
{
  int data;
  struct IntNode *next;
} IntNode;

IntNode *IntNode_init(int data)
{
  IntNode *node = (IntNode *)malloc(sizeof(IntNode));
  node->data = data;
  node->next = NULL;
  return node;
}

int main(void)
{
  IntNode *head = IntNode_init(1);
  ll_append(head, 2);
  ll_append(head, 3);
  ll_append(head, 4);
  ll_append(head, 5);
  ll_remove(head, 3);
  printf("The list length is %d\n", ll_length(head));
  ll_for_each(head, node) { printf("%d ", node->data); }
  ll_free(head);

  return 0;
}
