#include <stdio.h>
#include <string.h>

int TAM_STR;

void compacta(char sequencia[]) {
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

        printf("%d",to_string(nOcorrencia));
        /*
        if (nOcorrencia==1){
            strcat(sbCompactado,ch);
        }
        if (nOcorrencia > 1){
            strcat(sbCompactado,nOcorrencia);
            strcat(sbCompactado,cAdd);
        }*/
    }

}

int main(void) {

    printf("Digite o tamanho da sequencia");
    scanf("%d", & TAM_STR);

    char sequencia[] = "diandriax";
    TAM_STR = strlen(sequencia);
    compacta(sequencia);
}

