#include <stdio.h>
#include <string.h>

int TAM_STR;

void prog(char sequencia[]) {
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
        printf("%c",ch);       
        printf("%i",nOcorrencia);
        if(i != TAM_STR){
            printf("-");      
        }
        
    }
}

int main() {
    char sequencia[] = "aaaaaaabbbbbaaaaaaaaaa";
    TAM_STR = strlen(sequencia);

    desprog(sequencia);

    return 0;
}