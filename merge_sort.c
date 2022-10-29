#include <stdio.h>


void MERGESORT(char* V, int l, int r);
void MERGE(char* V, int l1, int r1, int l2, int r2);
void SHOW_VET(char *V, int length);

void main() {
    char V[] = {'E', 'C', 'K', 'H', 'A', 'R', 'D', 'T'};
    int length = 8;
    
    MERGESORT(V, 0, length - 1);
    SHOW_VET(V, length);
}


void MERGESORT(char* V, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        MERGESORT(V, l, m);
        MERGESORT(V, m + 1, r);
        MERGE(V, l, m, m + 1, r);
    }
}

void MERGE(char* V, int l1, int r1, int l2, int r2) {
    int aux[r2 - l1 + 1];
    int i = l1;
    int j = l2;
    int k = 0;

    while (i <= r1 && j <= r2) {
        if (V[i] < V[j]) {
            aux[k] = V[i];
            i++;
        } else {
            aux[k] = V[j];
            j++;
        }
        k++;
    }

    while (i <= r1) {
        aux[k] = V[i];
        i++;
        k++;
    }

    while (j <= r2) {
        aux[k] = V[j];
        j++;
        k++;
    }

    for (i = l1, j = 0; i <= r2; i++, j++) {
        V[i] = aux[j];
    }
}

void SHOW_VET(char *V, int length){
    for (int i = 0; i < length; i++) {
        printf("%c ", V[i]);
    }

    printf("\n");
}
