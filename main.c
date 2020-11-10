#include <stdio.h>
#include <string.h>

int TAM_STR = 5;

char compacta(char sequencia[]) {
    char sbCompactado[TAM_STR];

    int i = 0;

    while(i < TAM_STR){
        int nOcorrencia = 0;
        char ch = sequencia[i];
        int j = i;

        while((j < TAM_STR) && (sequencia[j]==ch)){
            nOcorrencia++;
            j++;
            i++;
        }

        char cAdd = ch;

        if (nOcorrencia > 0){ 
            char num[10];
            
            sprintf(num,"%i",nOcorrencia);

            strcat(sbCompactado, num);
            strcat(sbCompactado, "-");

        }
    }
    return sbCompactado[TAM_STR];
}

int main() {
    char sequencia[] = "aaaaa";

    char vetor = compacta(sequencia);

    printf("final: %c", vetor);

    return 0;
}