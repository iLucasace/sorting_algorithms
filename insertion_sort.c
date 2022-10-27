#include <stdio.h>

void INSERTION(char *V, int length);
void SHOW_VET(char *V, int length);

void main() {
    char V[] = {'E', 'C', 'K', 'H', 'A', 'R', 'D', 'T'};
    int length = 8;
    
    INSERTION(V, length);
    SHOW_VET(V, length);
} 

void INSERTION(char *V, int length) {
    int count = 0;
    for(int i = 1; i < length; i++) {
        int j = i;
        int t = V[i];
        while((j >= 1) && (V[j - 1] > t)) {
            V[j] = V[j - 1];
            j--;
            count++;
        }
        V[j] = t;
        count++;
    }
}

void SHOW_VET(char *V, int length){
    for (int i = 0; i < length; i++) {
        printf("%c ", V[i]);
    }

    printf("\n");
}
