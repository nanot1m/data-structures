#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "string.h"

// Linked list node

long str_to_hash(const char *str)
{
  long hash = 5381;
  int c;

  while ((c = *str++))
  {
    hash = ((hash << 5) + hash) + c;
  }

  return hash;
}

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
  printf("Linked list tests\n");
  IntNode *head = IntNode_init(1);
  ll_append(head, 2);
  ll_append(head, 3);
  ll_append(head, 4);
  ll_append(head, 5);
  ll_remove(head, 3);
  printf("The list length is %d\n", ll_length(head));
  ll_for_each(head, node) { printf("%d ", node->data); }
  ll_free(head);

  printf("\n\n");
  printf("String tests\n");

  String *msg = String_from_null_terminated("Hello, World!");
  printf("The message is: %s\n", msg->content);
  printf("The message length is: %d\n", msg->length);
  printf("The message hash is: %ld\n", String_to_hash(msg));
  String *slice = String_slice(msg, 0, 5);
  printf("The slice is: %s\n", slice->content);
  printf("The slice length is: %d\n", slice->length);
  printf("The slice hash is: %ld\n", String_to_hash(slice));
  String_free(slice);
  String_free(msg);

  return 0;
}
