#include <stdio.h>


void MERGESORT(char* V, int left, int right);
void MERGE(char* V, int left1, int right1, int left2, int right2);
void SHOW_VET(char *V, int length);

void main() {
    char V[] = {'E', 'C', 'K', 'H', 'A', 'R', 'D', 'T'};
    int length = 8;
    
    MERGESORT(V, 0, length - 1);
    SHOW_VET(V, length);
}


void MERGESORT(char* V, int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;
        MERGESORT(V, left, middle);
        MERGESORT(V, middle + 1, right);
        MERGE(V, left, middle, middle + 1, right);
    }
}

void MERGE(char* V, int left1, int right1, int left2, int right2) {
    int aux_array[right2 - left1 + 1];
    int i = left1;
    int j = left2;
    int k = 0;

    while (i <= right1 && j <= right2) {
        if (V[i] < V[j]) {
            aux_array[k] = V[i];
            i++;
        } else {
            aux_array[k] = V[j];
            j++;
        }
        k++;
    }

    while (i <= right1) {
        aux_array[k] = V[i];
        i++;
        k++;
    }

    while (j <= right2) {
        aux_array[k] = V[j];
        j++;
        k++;
    }

    for (i = left1, j = 0; i <= right2; i++, j++) {
        V[i] = aux_array[j];
    }
}

void SHOW_VET(char *V, int length){
    for (int i = 0; i < length; i++) {
        printf("%c ", V[i]);
    }

    printf("\n");
}
