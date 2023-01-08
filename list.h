#ifndef GUARD_list_h
#define GUARD_list_h

typedef struct Node {
    int val;
    struct Node* succ;
} Node;

void list_print(Node* node)
{
    printf("[ ");
    do {
        printf("%d ", node->val);
        node = node->succ;
    } while (node != NULL);
    printf("]");
}

void list_println(Node* node)
{
    list_print(node);
    printf("\n");
}

Node* list_tail(Node* node)
{
    while (node->succ != NULL) {
        node = node->succ;
    }

    return node;
}

void list_append_list(Node* list, Node* head)
{
    list_tail(head)->succ = list;
}

void list_prepend(int val, Node** head)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->succ = *head;
    *head = node;
}

void list_append(int val, Node* head)
{
    Node* tail = list_tail(head);
    tail->succ = (Node*)malloc(sizeof(Node));
    tail->succ->val = val;
    tail->succ->succ = NULL;
}

void list_deallocate(Node* node)
{
    Node* next;
    while(node != NULL) {
        next = node->succ;
        free(node);
        node = next;
    }
}

Node* list_copy(Node* node)
{
    Node* result_head = NULL;
    Node** result_tail = &result_head;
    
    while (node != NULL) {
        *result_tail = (Node*)malloc(sizeof(Node));
        (*result_tail)->val = node->val;
        (*result_tail)->succ = NULL;
        node = node->succ;
        result_tail = &((*result_tail)->succ);
    }

    return result_head;
}

/* list_remove, list_insert, list_concat */
/* chain should be renamed append_list(end, beg); */
void list_filter(int n, Node** head)
{
    Node* pred = NULL;
    Node* node = *head;
    
    while (node != NULL) {
        if (node->val == n) {
            if (pred == NULL) {
                *head = node->succ;
                free(node);
                node = *head;
            }
            else {
                pred->succ = node->succ;
                free(node);
                node = pred->succ;
            }
        }
        else {
            pred = node;
            node = node->succ;
        }
    }
}

Node* list_concat(Node* a, Node* b)
{
    Node* res = list_copy(a);
    Node* res2 = list_copy(b);
    list_append_list(res2, res);
    return res;
}

#endif/*GUARD_list_h*/
