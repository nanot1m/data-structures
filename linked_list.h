#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define ll_for_each(head, node) \
  for (typeof(head) node = head; node != NULL; node = node->next)

#define ll_last(head)                                      \
  ({                                                       \
    typeof(head) _node;                                    \
    for (_node = head; _node != NULL; _node = _node->next) \
    {                                                      \
      if (_node->next == NULL)                             \
        break;                                             \
    }                                                      \
    _node;                                                 \
  })

#define ll_append(head, value)                                \
  {                                                           \
    typeof(head) _next = (typeof(head))malloc(sizeof(*head)); \
    _next->data = value;                                      \
    _next->next = NULL;                                       \
    ll_last(head)->next = _next;                              \
  }

#define ll_remove(head, value)      \
  {                                 \
    typeof(head) _prev = NULL;      \
    ll_for_each(head, node)         \
    {                               \
      if (node->data == value)      \
      {                             \
        if (_prev == NULL)          \
        {                           \
          head = node->next;        \
        }                           \
        else                        \
        {                           \
          _prev->next = node->next; \
        }                           \
        free(node);                 \
        break;                      \
      }                             \
      _prev = node;                 \
    }                               \
  }

#define ll_free(head)                   \
  {                                     \
    typeof(head) _node = head;          \
    while (_node != NULL)               \
    {                                   \
      typeof(head) _next = _node->next; \
      free(_node);                      \
      _node = _next;                    \
    }                                   \
  }

#define ll_contains(head, value) \
  ({                             \
    int _found = 0;              \
    ll_for_each(head, node)      \
    {                            \
      if (node->data == value)   \
      {                          \
        _found = 1;              \
        break;                   \
      }                          \
    }                            \
    _found;                      \
  })

#define ll_length(head)                 \
  ({                                    \
    int _len = 0;                       \
    ll_for_each(head, node) { _len++; } \
    _len;                               \
  })

#endif // LINKED_LIST_H
