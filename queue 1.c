/*
    This code implements a queue with unlimited length.
*/

#include <stdio.h>
#include <stdlib.h>

static void queueMsg    (int value);
static void printQueue  (void);
static int  dequeueMsg  (void);

typedef struct
{
    struct node *   left;
    int             value;
    struct node *   right;
} node;

node * head = NULL;
node * tail = NULL;

int main(void)
{
    queueMsg(0);
    queueMsg(1);
    queueMsg(2);
    printQueue();
    printf("Dequeued %d\n", dequeueMsg());
    printf("Dequeued %d\n", dequeueMsg());
    printQueue();

    queueMsg(3);
    queueMsg(4);
    queueMsg(5);
    printQueue();

    return 0;
}

static void queueMsg(int value)
{
    node * temp = calloc(1, sizeof(node));

    temp->value = value;

    if(NULL == head)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->right = (struct node *)temp;
        temp->left  = (struct node *)tail;
        tail        = temp;
    }

    printf("Added %d\n", value);
}

static void printQueue(void)
{
    node * temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->value);
        temp = (node *)(temp->right);
    }
    printf("\n");
    printf("\n");
}

static int dequeueMsg(void)
{
    int    value = head->value;             // save the head node value
    node * temp  = head;                    // take a copy of head

    head         = (node *)(head->right);   // pointing to the next node in line
    head->left   = NULL;
    free(temp);                             // throw out previous head

    return value;
}


