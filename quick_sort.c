#include <stdio.h>

void QUICKSORT(char *V, int left, int right);
int PARTITION(char *V, int left, int right);
void SWAP(char *V, int i, int j);
void SHOW_VET(char *V, int length);

void main(){
    char V[] = {'E', 'C', 'K', 'H', 'A', 'R', 'D', 'T'};
    int length = 8;
    
    QUICKSORT(V, 0, length - 1);
    SHOW_VET(V, length);
}

void QUICKSORT(char *V, int left, int right) {
    if(left < right) {
        int pivot = PARTITION(V, left, right);
        QUICKSORT(V, left, pivot);
        QUICKSORT(V, pivot + 1, right);
    }
}

int PARTITION(char *V, int left, int right) {
    int i = left;
    int j = right;
    int pivot = V[(left + right) / 2];
    while(i <= j) {
        while(V[i] < pivot) {
            i += 1;
        }
        while(V[j] > pivot) {
            j -= 1;
        }
        if(i < j) {
            SWAP(V, i, j);
            i += 1;
            j -= 1;
        } else {
            break;
        }
    }
    return j;
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