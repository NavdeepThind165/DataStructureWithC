#include <stdio.h>
#include <stdlib.h>

static void addNode(int aValue);
static void printAllNodes(void);

typedef struct
{
    int               value;
    struct nodeType * next;
} nodeType;

nodeType * tail = NULL;
int count = 0;

int main(void)
{

    addNode(11);
    addNode(22);
    printAllNodes();

    addNode(33);
    addNode(44);
    printAllNodes();

    addNode(55);
    printAllNodes();

    addNode(66);
    printAllNodes();

    addNode(77);
    printAllNodes();

    return 0;
}

static void addNode(int aValue)
{
    nodeType * node = malloc(sizeof(nodeType));
    if(NULL == node)
    {
       printf("Program failed because no memory allocated.\n");
       exit(0);
    }

    node->value = aValue;

    printf("Adding %d\n", node->value);
    if(NULL == tail)
    {
        node->next = NULL;
        tail = node;
    }
    else
    {
        ++count;
        nodeType * temp = tail;
        if(count > 3)
        {
            temp=(nodeType *)temp->next;
            temp=(nodeType *)temp->next;
            temp->next=NULL;
        }
        
        node->next = (struct nodeType *)tail;
        tail = node;
    }
}

static void printAllNodes(void)
{
    nodeType * temp = tail;

    while(temp != NULL)
    {
        printf("%d ", temp->value);
        temp = (nodeType *)temp->next;
    }
    
    printf("\n");
    printf("\n");
}

