typedef int BSTElement;

typedef struct binary_search_tree_node {
    BSTElement value;
    struct binary_search_tree_node* right;
    struct binary_search_tree_node* left;
} BSTNode;

typedef struct binary_search_tree {
    TBstNode root;
} BSTree;

void bstInsert(BSTree* tree, BSTElement a);
void bstInitialize(BSTree* tree);