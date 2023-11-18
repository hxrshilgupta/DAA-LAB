#include <stdio.h>
#include <stdlib.h>

struct SYMBOL
{
    char alphabet;
    int frequency;
};

struct Node
{
    struct SYMBOL symbol;
    struct Node *left;
    struct Node *right;
};

struct MinPriorityQueueNode
{
    struct Node *data;
    struct MinPriorityQueueNode *next;
};

struct MinPriorityQueue
{
    struct MinPriorityQueueNode *front;
};

struct Node *createSymbolNode(struct SYMBOL symbol)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->symbol = symbol;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct MinPriorityQueueNode *createMinPriorityQueueNode(struct Node *data)
{
    struct MinPriorityQueueNode *newNode = (struct MinPriorityQueueNode *)malloc(sizeof(struct MinPriorityQueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct MinPriorityQueue *createMinPriorityQueue()
{
    struct MinPriorityQueue *queue = (struct MinPriorityQueue *)malloc(sizeof(struct MinPriorityQueue));
    queue->front = NULL;
    return queue;
}

void insertMinPriorityQueue(struct MinPriorityQueue *queue, struct Node *data)
{
    struct MinPriorityQueueNode *newNode = createMinPriorityQueueNode(data);

    if (queue->front == NULL || data->symbol.frequency < queue->front->data->symbol.frequency)
    {
        newNode->next = queue->front;
        queue->front = newNode;
    }
    else
    {
        struct MinPriorityQueueNode *current = queue->front;
        while (current->next != NULL && current->next->data->symbol.frequency < data->symbol.frequency)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

struct Node *extractMin(struct MinPriorityQueue *queue)
{
    if (queue->front == NULL)
    {
        return NULL;
    }

    struct MinPriorityQueueNode *temp = queue->front;
    queue->front = queue->front->next;
    struct Node *data = temp->data;
    free(temp);
    return data;
}

struct Node *buildHuffmanTree(struct SYMBOL symbols[], int n)
{
    struct MinPriorityQueue *queue = createMinPriorityQueue();

    for (int i = 0; i < n; i++)
    {
        struct Node *symbolNode = createSymbolNode(symbols[i]);
        insertMinPriorityQueue(queue, symbolNode);
    }

    while (queue->front->next != NULL)
    {
        struct Node *left = extractMin(queue);
        struct Node *right = extractMin(queue);

        struct SYMBOL internalSymbol = {'$', left->symbol.frequency + right->symbol.frequency};
        struct Node *internalNode = createSymbolNode(internalSymbol);

        internalNode->left = left;
        internalNode->right = right;

        insertMinPriorityQueue(queue, internalNode);
    }

    return extractMin(queue);
}

void inOrderTraversal(struct Node *root)
{
    if (root)
    {
        inOrderTraversal(root->left);
        if (root->symbol.alphabet != '$')
        {
            printf("%c ", root->symbol.alphabet);
        }
        inOrderTraversal(root->right);
    }
}

int main()
{
    int n;
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    struct SYMBOL symbols[n];
    printf("Enter the alphabets:\n");
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &symbols[i].alphabet);
    }

    printf("Enter its frequencies:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &symbols[i].frequency);
    }

    struct Node *root = buildHuffmanTree(symbols, n);

    printf("In-order traversal of the tree (Huffman): ");
    inOrderTraversal(root);
    printf("\n");

    printf("\nHarshil Gupta");
    printf("\n2105889");
    printf("\nCSE 32");
    return 0;
}