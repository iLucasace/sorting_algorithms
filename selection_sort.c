#include <stdio.h>

void SELECTION(char *V, int length);
void SHOW_VET(char *V, int length);
void SWAP(char *V, int i, int j);

void main() {
    char V[] = {'E', 'C', 'K', 'H', 'A', 'R', 'D', 'T'};
    int length = 8;
    
    SELECTION(V, length);
    SHOW_VET(V, length);
}

void SELECTION(char *V, int length) {
    int count = 0;
    for(int i = 0; i <= length - 1; i++) {
        int m = i;
        for(int j = i + 1; j < length; j++) {
            if(V[j] < V[m]) {
                m = j;
            }
            count++;
        }
        SWAP(V, i, m);
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
