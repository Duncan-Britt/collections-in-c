#ifndef GUARD_array_h
#define GUARD_array_h

typedef struct Array {
    int* elements;
    size_t capacity;
    size_t size;    
} Array;

void Array_print(Array* arr)
{
    int* end = arr->elements + arr->size;
    printf("{ ");
    int* p;
    for (p = arr->elements; p != end; ++p) {
        printf("%d ", *p);
    }
    printf("} size: %lu, cap: %lu", arr->size, arr->capacity);
}

void Array_println(Array* arr)
{
    Array_print(arr);
    printf("\n");
}

void Array_push(const int n, Array* arr)
{
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        arr->elements = (int*)realloc(arr->elements, arr->capacity * sizeof *(arr->elements));        
    }

    arr->elements[arr->size++] = n;
}

int Array_at(size_t i, Array* arr)
{
    return *(arr->elements + i);
}

#endif/*GUARD_array_h*/
