typedef int TElement;

typedef struct node {
    TElement info;
    struct node *izq, *der;
} TNode;

typedef struct ABB {
    TNode *raiz;
} TABB;

void init_abb(TABB*);
void insert_abb(TABB*, TElement);
void print_abb(TABB*, int);

