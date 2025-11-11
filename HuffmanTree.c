
#include <stdio.h>
#include <stdlib.h>
// Huffman tree node
struct MinHeapNode{
    char data;
    unsigned freq;
    struct MinHeapNode *left,*right;
};
// Min Heap structure
struct MinHeap{
    unsigned size;
    unsigned capacity;
    struct MinHeapNode  **array;
};
// Create a new node 
struct MinHeapNode *newNode(char data,unsigned freq){
    struct MinHeapNode *node=(struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    node->data=data;
    node->freq=freq;
    node->left=NULL;
    node->right=NULL;
    return node;
}
// Create a min heap
struct MinHeap *createMinHeap(unsigned capacity){
    struct MinHeap *heap=(struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->size=0;
    heap->capacity=capacity;
    heap->array=(struct MinHeapNode**)malloc(capacity * sizeof(struct MinHeapNode*));
    return heap;
}
// Swap function
void swapMinHeapNode(struct MinHeapNode ** a,struct MinHeapNode** b) {
    struct MinHeapNode *temp=*a;
    *a=*b;
    *b=temp;
}
// Heapify
void minHeapify(struct MinHeap* heap, int idx) {
    int smallest=idx;
    int left=2*idx+1;
    int right=2*idx+2;
    if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq)
        smallest = left;
    if (right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq)
        smallest = right;
    if (smallest!= idx) {
        swapMinHeapNode(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}
// Build min heap
void buildMinHeap(struct MinHeap* heap) {
    int n = heap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; i--)
        minHeapify(heap, i);
}
// Insert node
void insertMinHeap(struct MinHeap* heap, struct MinHeapNode* node) {
    int i = heap->size++;
    while (i && node->freq < heap->array[(i - 1) / 2]->freq) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}
// Extract min
struct MinHeapNode* extractMin(struct MinHeap* heap) {
    struct MinHeapNode* temp = heap->array[0];
    heap->array[0] = heap->array[--heap->size];
    minHeapify(heap, 0);
    return temp;
}
// Check if only one node remains
int isSizeOne(struct MinHeap* heap) {
    return (heap->size == 1);
}
// Create and build min heap
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    struct MinHeap* heap = createMinHeap(size);
    for (int i = 0; i < size; i++)
        heap->array[i] = newNode(data[i], freq[i]);
    heap->size = size;
    buildMinHeap(heap);
    return heap;
}

// Build Huffman tree
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* heap = createAndBuildMinHeap(data, freq, size);

    while (!isSizeOne(heap)) {
        left = extractMin(heap);
        right = extractMin(heap);
        top = newNode('\0', left->freq + right->freq); // internal node has no character
        top->left = left;
        top->right = right;
        insertMinHeap(heap, top);
    }

    return extractMin(heap);
}

// Postorder traversal
void printPostOrder(struct MinHeapNode* root) {
    if (root == NULL)
        return;

    printPostOrder(root->left);
    printPostOrder(root->right);

    if (root->data != '\0') // leaf node
        printf("%c(%d) ", root->data, root->freq);
    else                   // internal node
        printf("INT(%d) ", root->freq);
}

// Main function
int main() {
    char arr[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);

    struct MinHeapNode* root = buildHuffmanTree(arr, freq, size);

    printf("Postorder traversal of Huffman Tree:\n");
    printPostOrder(root);
    printf("\n");

    return 0;
}
