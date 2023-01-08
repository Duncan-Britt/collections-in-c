#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "array.h"

int main()
{      
    printf("Hi world.\n");

    Array arr = { .elements = NULL, .capacity = 10, .size = 0 };
    arr.elements = (int*)malloc(arr.capacity * sizeof(int));

    int n = 0;
    for (; n < 11; ++n) {
        Array_push(n, &arr);
    }

    Array_println(&arr);

    printf("%d\n", Array_at(3, &arr));
    
    free(arr.elements);
    
    Node* head = (Node*)malloc(sizeof(Node));
    head->val = 0;
    head->succ = (Node*)malloc(sizeof(Node));
    head->succ->val = 1;
    head->succ->succ = NULL;
    /* list_println(head); */

    list_prepend(-1, &head);
    /* list_println(head); */

    list_append(2, head);
    /* list_println(head); */

    Node* list2 = NULL;
    list_prepend(4, &list2);
    list_append(-1, list2);
    list_prepend(3, &list2);
    /* list_println(list2); */

    list_append_list(list2, head);
    /* list_println(head); */
    list_prepend(-1, &head);

    Node* list3 = list_copy(head);
    /* list_println(list3); */

    list_filter(-1, &list3);
    list_println(list3);
    list_println(head);

    Node* list4 = list_concat(list3, head);
    list_println(list4);
    
    list_deallocate(head);
    list_deallocate(list3);
    list_deallocate(list4);
    return 0;
}

