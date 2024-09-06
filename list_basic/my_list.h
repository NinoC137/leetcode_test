#ifndef __MY_LIST_H__
#define __MY_LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct my_list_t
{
    char* str;
    struct my_list_t* next;
}list_node_t;

list_node_t* list_init();

list_node_t* list_append(list_node_t* head, list_node_t node);

void list_delete(list_node_t* head, char* str, uint32_t index);

list_node_t* list_find(list_node_t* head, char* str, uint32_t index);

void list_set_node(list_node_t* head, char* str, uint32_t index);

list_node_t* list_goThrough(list_node_t* head);

#endif