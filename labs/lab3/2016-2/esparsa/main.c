#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "list.h"

#define SMAX 300

void sum_lists(TList* list1, TList* list2, TList* sum) {
    TNode* actual1 = list1->first;
    TNode* actual2 = list2->first;
    TInfo x;
    int pos1, pos2, val1, val2;
    while(actual1!=NULL && actual2!=NULL) {
        pos1 = INT_MAX;
        pos2 = INT_MAX;
        val1 = 0;
        val2 = 0;
        if(actual1!=NULL) {
            pos1 = actual1->info.pos;
            val1 = actual1->info.val;
        }
        if(actual2!=NULL) {
            pos2 = actual2->info.pos;
            val2 = actual2->info.val;
        }
        if(pos1 == pos2) {
            x.pos = pos1;
            x.val = val1 + val2;
            insert_list_end(sum, x);
            actual1=actual1->next;
            actual2=actual2->next;
        }
        else if(pos1 < pos2) {
            x.pos = pos1;
            x.val = val1;
            insert_list_end(sum, x);
            actual1=actual1->next;
        }
        else {
            x.pos = pos2;
            x.val = val2;
            insert_list_end(sum, x);
            actual2=actual2->next;
        }
    }
    return;
}

int main() {
    TList list1, list2, suma;
    init_list(&list1);
    init_list(&list2);
    init_list(&suma);
    int n, pos, val, m;
    char line[SMAX];
    char* p;
    TInfo x;
    scanf("%d", &n);
    getchar();
    fgets(line, SMAX-1, stdin);
    for(p=line; sscanf(p, "%d %d%n", &pos, &val, &m)==2; p+=m) {
        x.pos = pos;
        x.val = val;
        insert_list_end(&list1, x);
    }
    fgets(line, SMAX-1, stdin);
    for(p=line; sscanf(p, "%d %d%n", &pos, &val, &m)==2; p+=m) {
        x.pos = pos;
        x.val = val;
        insert_list_end(&list2, x);
    }
    sum_lists(&list1, &list2, &suma);
    print_list(&suma);
    kill_list(&list1);
    kill_list(&list2);
    kill_list(&suma);
    return (EXIT_SUCCESS);
}

