#include <stdio.h>

void HEAPSORT(char *V, int length);
void BUILD_MAX_HEAP(char *V, int n);
void HEAP_DOWN(char *V, int i, int n);
void SWAP(char *V, int i, int j);
void SHOW_VET(char *V, int length);

void main() {
    char V[] = {'E', 'C', 'K', 'H', 'A', 'R', 'D', 'T'};
    int length = 8;
    
    HEAPSORT(V, length);
    SHOW_VET(V, length);
}

void HEAPSORT(char *V, int length) {
    BUILD_MAX_HEAP(V, length);
    
    int tam_heap = length - 1;
    for(int i = length - 1; i > 0; i--) {
        SWAP(V, 0, i);
        tam_heap--;
        HEAP_DOWN(V, 0, tam_heap);
    }
}

void BUILD_MAX_HEAP(char *V, int length) {
    for(int i = 1; i < length; i++) {
        int child = i;
        int parent = (child - 1) / 2;

        while(parent >= 0 && V[child] > V[parent]) {
            SWAP(V, child, parent);
            child = parent;
            parent = (child - 1) / 2;
        }
    }
}

void HEAP_DOWN(char *V, int i, int length) {
    int parent = i;
    
    while(2 * parent + 1 <= length) {
        int right = 2 * parent + 2;
        int left = 2 * parent + 1;
        int child = left;
        
        if(right <= length) {
            if(V[left] < V[right]) {
                child = right;
            }
        }
        
        if(V[child] > V[parent]) {
            SWAP(V, child, parent);
            parent = child;
        } else {
            break;
        }
    }
}

void SWAP(char *V, int i, int j) {
    int tmp = V[i];
    V[i] = V[j];
    V[j] = tmp;
}

void SHOW_VET(char *V, int length){
    for (int i = 0; i < length; i++) {
        printf("%c ", V[i]);
    }

    printf("\n");
}
