#ifndef STRING_H
#define STRING_H

#include <stdlib.h>

typedef struct
{
    char *content;
    unsigned int length;
    unsigned int capacity;
} String;

String *String_from_null_terminated(const char *str)
{
    String *string = (String *)malloc(sizeof(String));
    string->length = 0;
    string->capacity = 1;
    string->content = (char *)malloc(string->capacity * sizeof(char));

    while (*str)
    {
        if (string->length == string->capacity)
        {
            string->capacity *= 2;
            string->content = (char *)realloc(string->content, string->capacity * sizeof(char));
        }

        string->content[string->length++] = *str++;
    }

    return string;
}

String *String_from_chars(const char *chars, unsigned int length)
{
    String *string = (String *)malloc(sizeof(String));
    string->length = length;
    string->capacity = length;
    string->content = (char *)malloc(string->capacity * sizeof(char));

    for (unsigned int i = 0; i < length; i++)
    {
        string->content[i] = chars[i];
    }

    return string;
}

String *String_slice(String *string, unsigned int start, unsigned int end)
{
    if (end > string->length)
    {
        end = string->length;
    }

    if (start > end)
    {
        start = end;
    }

    unsigned int length = end - start;
    String *sliced = String_from_chars(string->content + start, length);
    return sliced;
}

long String_to_hash(String *string)
{
    long hash = 5381;
    int c;

    for (unsigned int i = 0; i < string->length; i++)
    {
        c = string->content[i];
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

void String_free(String *string)
{
    free(string->content);
    free(string);
}

#endif