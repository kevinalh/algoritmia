#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int TElement;

typedef struct Entry {
    TElement value;
    struct Entry* right;
    struct Entry* below;
} TEntry;

typedef struct Matriz {
    TEntry* start;
    TEntry* lowleft;
    TEntry* topright;
    int rows;
    int columns;
} Matrix;

void printError(char* s) {
    printf("%s error\n", s);
    return;
}

/* List definitions */

typedef struct Node {
    TElement value;
    struct Node* next;
} TNode;

typedef struct Lista {
    TNode* start;
    TNode* end;
    int size;
} List;

void List_init(List* list) {
    list->start = NULL;
    list->end = NULL;
    list->size = 0;
    return;
}

int List_isEmpty(List* list) {
    return list->start == NULL;
}

void List_addElementEnd(List* list, TElement a) {
    TNode* node = malloc(sizeof(TNode));
    if(node) {
        node->value = a;
        node->next = NULL;
        if(List_isEmpty(list)) {
            list->start = node;
            list->end = node;
        } else {
            list->end->next = node;
            list->end = node;
        }
        list->size++;
    } else {
        printError("Memory");
    }    
    return;
}

void List_clean(List* list) {
    TNode* node = list->start;
    TNode* tmp;
    while(node != NULL) {
        tmp = node;
        node = node->next;
        free(tmp);
    }
    list->size = 0;
    list->end = NULL;
    list->start = NULL;
    return;
}


/* Matrix definitions */

void Matrix_init(Matrix* matrix) {
    matrix->columns = 0;
    matrix->rows = 0;
    matrix->start = NULL;
    matrix->lowleft = NULL;
    matrix->topright = NULL;
}

int Matrix_isEmpty(Matrix* matrix) {
    return matrix->start == NULL;
}

void Matrix_print(Matrix matrix) {
    TEntry* a = matrix.start;
    TEntry* b = matrix.start;
    while(a != NULL) {
        while(b != NULL) {
            printf("%d ", b->value);
            b = b->right;
        }
        printf("\n");
        a = a->below;
        b = a;
    }
    printf("\n");
    return;
}

void Matrix_addColumn(Matrix* matrix, List column) {
    int empty = Matrix_isEmpty(matrix);
    if(column.size != matrix->rows && !empty) {
        printError("Dimension");
        return;
    } else {
        TEntry* a = malloc(sizeof(TEntry));
        TEntry* tmp;
        TNode* b = column.start;
        a->value = b->value;
        a->below = NULL;
        a->right = NULL;
        if(empty) {
            matrix->start = a;
            matrix->rows = column.size;
            matrix->topright = a;
            b = b->next;
            while(b != NULL) {
                tmp = a;
                a = malloc(sizeof(TEntry));
                a->value = b->value;                
                a->right = NULL;
                tmp->below = a;
                b = b->next;
            }
            a->below = NULL;
            matrix->lowleft = a;
        }
        else {
            TEntry* c = matrix->topright;
            c->right = a;
            matrix->topright = a;
            b = b->next;
            c = c->below;
            while(b != NULL) {
                tmp = a;
                a = malloc(sizeof(TEntry));
                a->value = b->value;
                a->right = NULL;
                tmp->below = a;
                c->right = a;
                c = c->below;
                b = b->next;
            } 
            a->below = NULL;
        }
        matrix->columns++;
    }
    return;
}

void Matrix_addRow(Matrix* matrix, List row) {
    int empty = Matrix_isEmpty(matrix);
    if(row.size != matrix->columns && !empty) {
        printError("Dimension");
        return;
    } else {
        TEntry* a = malloc(sizeof(TEntry));
        TEntry* tmp;
        TNode* b = row.start;
        a->value = b->value;
        a->below = NULL;
        a->right = NULL;
        if(empty) {
            matrix->start = a;
            matrix->columns = row.size;
            matrix->lowleft = a;
            b = b->next;
            while(b != NULL) {
                tmp = a;
                a = malloc(sizeof(TEntry));
                a->value = b->value;                
                a->below = NULL;
                tmp->right = a;
                b = b->next;
            }
            a->right = NULL;
            matrix->topright = a;
        }
        else {
            TEntry* c = matrix->lowleft;
            c->below = a;
            matrix->lowleft = a;
            b = b->next;
            c = c->right;
            while(b != NULL) {
                tmp = a;
                a = malloc(sizeof(TEntry));
                a->value = b->value;
                a->below = NULL;
                tmp->right = a;
                c->below = a;
                c = c->right;
                b = b->next;
            } 
            a->right = NULL;
        }
        matrix->rows++;
    }
    return;
}

void Matrix_deleteColumn(Matrix* matrix, int i) {
    if(i > matrix->columns || i <= 0) {
        printError("Out of bounds");
        return;
    }
    int j = i;
    TEntry* a = matrix->start;
    TEntry* b = NULL;
    TEntry* tmp = a;
    if(i == 1) {
        matrix->start = a->right;
    }
    while(--j) {
        b = a;
        a = a->right;
    }
    if(i == matrix->columns) {
        matrix->topright = b;
    }
    while(a != NULL) {
        if(b != NULL) {
            b->right = a->right;
            b = b->below;
        }
        tmp = a;
        a = a->below;
        free(tmp);
    }
    if(i == 1) {
        matrix->lowleft = tmp;
    }
    matrix->columns--;
    return;
}

void Matrix_deleteRow(Matrix* matrix, int i) {
    if(i > matrix->rows || i <= 0) {
        printError("Out of bounds");
        return;
    }
    int j = i;
    TEntry* a = matrix->start;
    TEntry* b = NULL;
    TEntry* tmp = a;
    if(i == 1) {
        matrix->start = a->below;
    }
    while(--j) {
        b = a;
        a = a->below;
    }
    if(i == matrix->rows) {
        matrix->lowleft = b;
    }
    while(a != NULL) {
        if(b != NULL) {
            b->below = a->below;
            b = b->right;
        }
        tmp = a;
        a = a->right;
        free(tmp);
    }
    if(i == 1) {
        matrix->topright = tmp;
    }
    matrix->rows--;
    return;
}

void Matrix_getColumn(Matrix* matrix, List* list, int i) {
    List_init(list);
    TEntry* a = matrix->start;
    if(i > matrix->columns || i <= 0) {
        printError("Out of bounds");
        return;
    }
    while(--i) {
        a = a->right;
    }
    while(a != NULL) {
        List_addElementEnd(list, a->value);
        a = a->below;
    }
    return;
}

void Matrix_getRow(Matrix* matrix, List* list, int i) {
    List_init(list);
    TEntry* a = matrix->start;
    if(i > matrix->rows || i <= 0) {
        printError("Out of bounds");
        return;
    }
    while(--i) {
        a = a->below;
    }
    while(a != NULL) {
        List_addElementEnd(list, a->value);
        a = a->right;
    }
    return;
}

void Matrix_transpose(Matrix matrix, Matrix* transpose) {
    List list;
    Matrix_init(transpose);
    int i;
    for(i = 1; i <= matrix.columns; ++i) {
        Matrix_getColumn(&matrix, &list, i);
        Matrix_addRow(transpose, list);
    }
    return;
}

int main() {
    TElement n;
    List list;
    Matrix matrix, trasp;
    List_init(&list);
    Matrix_init(&matrix);
    Matrix_init(&trasp);
    
    List_addElementEnd(&list, 1);
    List_addElementEnd(&list, 2);
    List_addElementEnd(&list, 3);
    List_addElementEnd(&list, 1);
    
    Matrix_addColumn(&matrix, list);
    List_clean(&list);
    
    List_addElementEnd(&list, 4);
    List_addElementEnd(&list, 5);
    List_addElementEnd(&list, 6);
    List_addElementEnd(&list, 1);
    
    Matrix_addColumn(&matrix, list);
    List_clean(&list);
    
    List_addElementEnd(&list, 9);
    List_addElementEnd(&list, 8);
    List_addElementEnd(&list, 1);
    List_addElementEnd(&list, 1);
    
    Matrix_addColumn(&matrix, list);
    List_clean(&list);

    List_addElementEnd(&list, 3);
    List_addElementEnd(&list, 4);
    List_addElementEnd(&list, 5);
    
    Matrix_addRow(&matrix, list);
    List_clean(&list);
    
    List_addElementEnd(&list, 9);
    List_addElementEnd(&list, 9);
    List_addElementEnd(&list, 9);
    List_addElementEnd(&list, 8);
    List_addElementEnd(&list, 8);
    
    Matrix_addColumn(&matrix, list);
    List_clean(&list);
    
    Matrix_print(matrix);
    
    Matrix_deleteColumn(&matrix, 1);
    
    Matrix_print(matrix);
    
    Matrix_deleteRow(&matrix, 2);
    
    Matrix_print(matrix);
    
    Matrix_deleteRow(&matrix, 4);
    
    Matrix_print(matrix);
    
    List_addElementEnd(&list, 4);
    List_addElementEnd(&list, 4);
    List_addElementEnd(&list, 5);
    
    Matrix_addRow(&matrix, list);
    Matrix_addRow(&matrix, list);
    Matrix_addRow(&matrix, list);
    List_clean(&list);
    
    Matrix_print(matrix);
    
    Matrix_deleteRow(&matrix, 3);
    
    Matrix_print(matrix);
    
    Matrix_transpose(matrix, &trasp);
    
    Matrix_print(trasp);
    
    return (EXIT_SUCCESS);
}

