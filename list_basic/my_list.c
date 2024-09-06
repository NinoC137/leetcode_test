#include "my_list.h"

/**
 * note:
 *      前后指针的正确用法
 *         for(;ptr->next != NULL;){
 *              ptr_before = ptr;
 *              ptr = ptr->next;
 *          }
 *      这样的操作逻辑才能保证ptr_before指针才能保证永远在ptr前面
 */

list_node_t* list_init(){
    list_node_t* head_node = (list_node_t*)malloc(sizeof(list_node_t));
    head_node->str = "head";
    head_node->next = NULL;
    return head_node;
}

list_node_t* list_append(list_node_t* head, list_node_t node){
    list_node_t* ptr;
    list_node_t* node_memptr;
    ptr = list_goThrough(head);

    // printf("append info: ptr address: %p, head address: %p\r\n", ptr, head);

    node_memptr = (list_node_t*)malloc(sizeof(list_node_t));
    *node_memptr = node;
    node_memptr->next = NULL;
    
    ptr->next = node_memptr;
    return node_memptr;
}

void list_delete(list_node_t* head, char* str, uint32_t index){
    if(index != 0){
        list_node_t* ptr = head;
        list_node_t* ptr_before = NULL;

        for(int i = 0; i < index && ptr != NULL; i++){
            ptr_before = ptr;
            ptr = ptr->next;
        }
        if(ptr != NULL){
            if(ptr_before != NULL){
                ptr_before->next = ptr->next;
            }
        }
        
        printf("ptr_before str: %s, ptr_before's next str: %s\r\n", ptr_before->str, ptr_before->next->str);
        printf("find node index: %d, str: %s\r\n", index, ptr->str);
    }

    if(str != NULL){
        list_node_t* node_ptr = head;
        list_node_t* node_ptr_before = NULL;
        
        for(;node_ptr != NULL;){
            if(!strcmp(node_ptr->str, str)){
                if(node_ptr_before == NULL){
                    head = node_ptr->next;
                }else{
                    node_ptr_before->next = node_ptr->next;
                }
                printf("ptr_before str: %s, ptr_before's next str: %s\r\n", node_ptr_before->str, node_ptr->next->str);
                return;
            }
            node_ptr_before = node_ptr;
            node_ptr = node_ptr->next;
        }
        printf("cannot find node str %s\r\n", str);
    }
}

list_node_t* list_find(list_node_t* head, char* str, uint32_t index){
    list_node_t* node_ptr = head;
    uint32_t count = 0;
    for(;node_ptr != NULL;){
        if(strcmp(node_ptr->str, str) == 0){
            printf("find node str: %s, node count: %d\r\n", node_ptr->str, count);
            return node_ptr;
        }
        count++;
        node_ptr = node_ptr->next;
    }
}

void list_set_node(list_node_t* head, char* str, uint32_t index){

}

list_node_t* list_goThrough(list_node_t* head){
    list_node_t* node_ptr = head;
    for(;node_ptr->next != NULL;){
        node_ptr = node_ptr->next;
    }
    return node_ptr;
}

void list_printAll(list_node_t* head){
    list_node_t* node_ptr = head;
    uint32_t index = 0;
    while(node_ptr != NULL){
        printf("current node index: %d, str: %s\r\ncurrent address: %p, next node address: %p\r\n", 
                    index, node_ptr->str, node_ptr, node_ptr->next);
        index++;
        node_ptr = node_ptr->next;
    }

}

int main(){
    list_node_t* head;
    head = list_init();

    list_node_t node1;
    node1.str = "node1";
    list_append(head, node1);

    list_node_t node2;
    node2.str = "node2";
    list_append(head, node2);

    list_node_t node3;
    node3.str = "node3";
    list_append(head, node3);

    list_printAll(head);

    list_delete(head, "node2", 0);

    list_printAll(head);

    list_find(head, "node3", 0);

}