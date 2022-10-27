#include <stdio.h>

void SHELLSORT(char *V, int length);
void SHOW_VET(char *V, int length);

void main(){
    char V[] = {'E', 'C', 'K', 'H', 'A', 'R', 'D', 'T'};
    int length = 8;

    SHELLSORT(V, length);
    SHOW_VET(V, length);
}

void SHELLSORT(char *V, int length) {
    int jump = length / 2;
    while(jump > 0) {
        for(int i = jump; i < length; i++) {
            int aux = V[i];
            int j = i;
            while((j >= jump) && (V[j - jump] > aux)) {
                V[j] = V[j - jump];
                j -= jump;
            }
            V[j] = aux;
            
        }
        jump = jump / 2;
    }
}

void SHOW_VET(char *V, int length){
    for (int i = 0; i < length; i++) {
        printf("%c ", V[i]);
    }

    printf("\n");
}