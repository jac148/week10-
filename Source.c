#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct _node {  //declare structure
    char* name;
    int score;
    struct node* next;
    struct node* prev;
}node;

node* head, * tail; // declare head and tail node 


 // head, tail »ý¼º
void init(void) {
    head = (node*)malloc(sizeof(node));
    tail = (node*)malloc(sizeof(node));
    head->next = tail; // direction of head and tail
    head->prev = head;
    tail->next = tail;
    tail->prev = head;
}

 // printList function that outputs all data in a double link list
void printList(node* p) {
    printf("\n");
    while (p != tail) {
        printf("name : %s \tscore : %-4d\n", &p->name, p->score);
        p = p->next;
    }
}

 //Insert function that inserts data into the double link list
void insert(char* paraname, int parascore) {
    node* s; // Node that store new data
    node* t; // head node that points to the next node

    s = (node*)malloc(sizeof(node));
    s->name = paraname;
    s->score = parascore;

    t = head->next; 
    head->next = s; // inseart node s
    s->prev = head;
    s->next = t;  
    t->prev = s;

}

/* Find function that retrieves data in a list with name as a parameter
 Search sequentially from head to tail  */
void find(char* name) {
    node* h;
    int result = 1; // variable that stores string comparison value 
    int count = 0; // Search confirmation variable

    h = head->next;

    while (h != tail) {
        result = strcmp(&name, &h->name);

        if (result == 0) {
            printf("name : %s   score : %-4d \n", &h->name, h->score);
            count++; // Search confirmation counter
        }
        h = h->next;
    }
    if (count == 0) { printf("no name founded\n"); }
}

///nodeDelete function that receives the name and deletes the node
int nodeDelete(char* name) {
    node* t; // node to be deleted t
    node* n; //  previous node of node t
    node* p; // next node of node t

    t = head->next;  //Start sequential search

    while (t != tail) {
        result = strcmp(&name, &t->name);

        //Delete the node when  founded
        if (result == 0) {
            printf("name: %s   score : %-4d \n", &t->name, t->score);
            if (t != tail) {
                n = t->next;
                p = t->prev;
                p->next = n;
                n->prev = p;
                free(t);
                break;
                return 0;
            }
        }
        t = t->next;
    }

    if (result == -1 || result == 1) { printf("no name found\n"); }
    return 0;
}

int main(void) {

    int loop = 1;
    char* name;
    int score = 0;

    init();

    while (loop != 0) {
        printf("\n0: end   1: input   2: outpur  3. search   4, delete   ==> ");
        scanf("%d", &loop);

        if (loop == 0) {
            break;
        }
        else if (loop == 1) {
            printf("name : "), scanf("%s", &name);
            printf("score : "), scanf("%d", &score);
            insert(name, score);

        }
        else if (loop == 2) {
            printList(head->next);
        }
        else if (loop == 3) {
            printf("name to be searched : "), scanf("%s", &name);
            find(name);
        }
        else if (loop == 4) {
            printf("name to be deleted : "), scanf("%s", &name);
            nodeDelete(name);
        }
    }
    return 0;
}