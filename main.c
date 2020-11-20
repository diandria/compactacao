/*
 * Script para executar os algoritmos de compactação e descompactação
 *
 * @link  do código https://repl.it/join/rylkyjwi-diandria
 * @author Daiane   - TIA: 4199227-1 
 * @author Diandria - TIA: 3190751-2
 * @author Leonardo - TIA: 4194942-0
 * @version 1.0
 */

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

//valor global que define o tamanho da sequencia
int TAM_STR;

//****               Funções                ****//

/**
 * Método que define o tipo de um caracter especifico
 *
 * @method getType
 * @param {char} getType - Caracter a ter seu tipo definido
 * @return {char} type - Tipo do caracter - N (Numero), C (Caracter especial), L (Letra)
 */
char getType(char ch) {
    char type;

    if (ch == '-') {
        type = 'C';
    } else if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9') {
        type = 'N';
    } else {
        type = 'L';
    }

    return type;
}

/**
 * Método que compacta elementos contíguos repetidos
 *
 * @method prog
 * @param {char} sequencia[] - Um vetor de char (string), contendo a sequencia a ser compactada
 */
void prog(char sequencia[]) {
    // String que guardará o sequencia compactada
    char sbCompactado[TAM_STR];

    int i = 0;
    // Enquanto não for o fim da sequencia ele vai procurar por um elemento repetido
    while (i < TAM_STR) {
        int nOcorrencia = 0;
        char ch = sequencia[i];

        int j = i;
        // Percorre a sequencia a fim de procurar quantas vezes o elemento vai se repetir, a partir da posição que esse elemento foi encontrado
        while ((j < TAM_STR) && (sequencia[j] == ch)) {
            nOcorrencia++;
            j++;
            i++;
        }
        // Exibe qual foi o elemento e quantas vezes ele foi repetido
        printf("%c%i", ch, nOcorrencia);
        if (i != TAM_STR) {
            printf("-");
        }

    }
}

/**
 * Método que descompacta uma sequencia compactada
 *
 * @method desprog
 * @param {char} sequencia[] - Um vetor de char (string), contendo a sequencia a ser descompactada
 */
void desprog(char sequencia[]) {
    // Cria uma variavel que guarda uma sequencia descompactada
    char sbDescompactado[184] = "";

    //Armazena num como uma variavel que será usada pra definir quantas vezes o elemento será repetido
    int num;

    //Guarda os valor dos elementos atual, anterior, proximo da sequencia
    char atual[100], ant[100], prox[100];

    //Guarda o tipo do elemento da sequencia
    char t_atual, t_prox, t_ant;
    //Percorre a sequencia para descompactar os elementos
    for (int i = 0; i < TAM_STR; i++) {
        strcpy(atual, " ");
        atual[0] = sequencia[i];
        t_atual = getType(atual[0]);

        // Se estamos na primeira posição seu valor será uma letra e seu valor, e como estamos na primeira posição não temos elemento anterior a ser analisado, guardamos então o seu valor como anterior e analisamos o proximo elemento
        if (i == 0) {
            t_atual = 'L';
            strcpy(ant, " ");
            ant[0] = atual[0];
            continue;
        } else {
            // Se for encontrado um numero, será verificado qual o seu valor para definir quantas vezes o elemento será repetido 
            if (t_atual == 'N') {

                prox[0] = sequencia[i + 1];
                t_prox = getType(prox[0]);
                int j = i;
                int cont = 0;
                // Se o proximo elemento tambem for um número, será concatenado ao numero atual que posteriormente será transformado em int
                while (t_prox == 'N') {
                    strcpy(atual, strcat(atual, prox));
                    j = j + 2;
                    prox[0] = sequencia[j];
                    t_prox = getType(prox[0]);

                    cont++;
                }
                i += cont;

                // Transforma o valor encontrado para o tipo inteiro
                num = atoi(atual);

                // Roda a quantidade de vezes solicitada, concatenando na string sbDescompactado a sequencia descompactada
                for (int k = 0; k < num; k++) {
                    strcpy(sbDescompactado, strcat(sbDescompactado, ant));
                }
                continue;
            }
            // Se o elemento que está sendo analisado é uma letra precisamos verificar qual é a subsequencia a ser descompactada
            else if (t_atual == 'L') {

                // A variavel 'ant' é a chave que é repetida, se o termo anterior é numero significa que esse elemento é uma nova subsequencia, substituindo então todos os valores guardados em 'ant'
                if (t_ant == 'N' || t_ant == 'C') {
                    strcpy(ant, " ");
                    ant[0] = atual[0];

                    t_ant = 'L';
                    continue;
                }
                // Se o elemento anterior era uma letra, significa que encontramos o proximo elemento da subsequencia que será descompactada, então concatenamos o seu valor na variavel 'ant'
                else {
                    strcpy(ant, strcat(ant, atual));
                    continue;
                }
            }
            // Se o elemento que esta sendo analisado é um caracter especial, somente guardamos seu valor como a fim de variavel de controle, sua presença é irrelevante
            else {
                t_ant = 'C';
                continue;
            }
        }
    }
    // Exibimos para o usuário a sequencia final descompactada
    printf("%s\n", sbDescompactado);

}

/**
 * Método que compacta elementos contíguos repetidos
 *
 * @method prog2
 * @param {char} sequencia[] - Um vetor de char (string), contendo a sequencia a ser compactada
 */
void prog2(char sequencia[]) {
    // Uma string que irá guardar a subsequencia
    char vetor[100] = " ";
    // Uma string que irá guardar o valor do primeiro elemento da subsequencia
    char prim_elem[100] = " ";
    // Uma string que guarda o elemento que será concatenado a subsequencia
    char elemen_dif[100] = " ";

    // Cria uma variavel que irá guardar a quantidade de vezes em que um elemento será repetido
    int qtd_repet;

    int pos = 0;
    // Quando a posição for menor que o tamanho Roda o while. 
    while (pos < TAM_STR) {

        // Se estiver na primeira posição vamos rodar o valor a fim de encontra a subsequencia a ser compactada
        if (pos == 0) {
            // Percorremos o vetor até encontrar um elemento que seja igual a ao primeiro elemento da subsequencia, ou seja um subsequencia termina nessa posição
            for (int i = 1; i < TAM_STR; i++) {
                if (i == 1) {
                    // Guardando o primeiro elemento e guarda no vetor de subsequencia
                    prim_elem[0] = sequencia[0];
                    strcpy(vetor, prim_elem);
                }

                // Enquanto o elemento analisado for diferente do primeiro elemento da subsequencia ele será concatenado
                if (prim_elem[0] != sequencia[i]) {
                    elemen_dif[0] = sequencia[i];
                    strcpy(vetor, strcat(vetor, elemen_dif));
                }
                // Guardamos a posição que foi encontrado o fim da subsequencia e forçamos a saida
                else {
                    pos = i;
                    i = TAM_STR;
                }
            }
            // Como a subsequencia foi encontrada significa que existe pelo menos um elemento
            qtd_repet = 1;
        } else {
            int i = 0;
            // Limpa o vetor para receber uma nova subsequencia
            strcpy(vetor, " ");
            // Verifica as demais subsequencias a partir da ultima posição encontrada
            for (i = pos; i < TAM_STR; i++) {
                // Define o primeiro elemento da nova subsequencia e guarda no vetor da nova subsequencia
                if (i == pos) {
                    prim_elem[0] = sequencia[pos];
                    strcpy(vetor, prim_elem);
                }
                // Enquanto o elemento analisado for diferente do primeiro elemento da subsequencia ele será concatenado
                if (prim_elem[0] != sequencia[i + 1]) {
                    elemen_dif[0] = sequencia[i + 1];
                    strcpy(vetor, strcat(vetor, elemen_dif));

                } else {
                    // Força saida do for
                    i = TAM_STR;
                }

            }
            // Nesse caso o numero de vezes que é repetido não é 1 pois essa subsequencia não inicia na primeira posição da sequencia original
            qtd_repet = 0;
        }

        // Define o tamanho da subsequencia
        int tam_vetor = strlen(vetor);

        // Verificar se a subsequencia está sendo realmente repetida
        int c = 0; //int c;

        int cont = 1;
        while (cont) {
            c = 0;
            // Rodo ate o fim da subsequencia
            for (int i = 0; i < tam_vetor; i++) {
                // Verifica se o elemento esta sendo repetido corretamente
                // Se for repetido o contador de verificação é somado um ao seu valor
                if (vetor[i] == sequencia[pos] && pos < TAM_STR) {
                    c++;
                    pos++;
                }
                // Se não for zera o contador de verificação, ou seja a sequencia não é correta, não se repete
                else {
                    cont = 0;
                    break;
                }
            }
            // Se a subsequencia foi repetida é somado um  a quantidade de vezes que foi repetida
            if (c == tam_vetor && cont == 1) {
                qtd_repet++;
            }
            // Se a subsequencia não foi repetida a sua posição é a partir do ponto em que parou de ser repetida, sendo definido então a posição de uma nova subsequencia
            else {
                pos = pos - c;
            }
        }
        printf("%s%i", vetor, qtd_repet);
        if (pos != TAM_STR) {
            printf("-");
        }
    }
}

int main(void) {

    while (1) {
        // Variaveis de controle usadas no menu, variavel que controla a opção digitada pelo usuário e a variavel que irá armazenar a sequencia que será compactada/descompactada
        int opc;
        char sequencia[800];

        //exibe o menu para o usuário e armazena a resposta
        printf("\n\n\n--------------- MENU ---------------");
        printf("\n\nQual algoritmo voce deseja utilizar?\n[0]SAIR\n[1]prog\n[2]desprog\n[3]prog2\nOpcao: ");
        scanf("%i", & opc);

        //Finaliza o programa
        if (opc == 0) {
            printf("\nObrigada! Ate' a proxima\n\n");
            break;
        }
        //chama o algoritmo 'prog'
        else if (opc == 1) {
            //instrui o usuário e armazena a sequencia na variavel de controle
            printf("\nDigite a sequencia com elementos conti'guos repetidos a ser compactada pelo algortimo 'prog':\n    Exemplo: aaaaaaabbbbbaaaaaaaaaa\n\nSequencia: ");
            scanf("%s", sequencia);
            //calcula o tamanho da sequencia inserida pelo usuário e armazena para ser usada pela função
            TAM_STR = strlen(sequencia);
            //chama a função 'prog'
            printf("Sai'da: ");
            prog(sequencia);
        }
        //chama o algoritmo 'desprog'
        else if (opc == 2) {
            // repete as ações ate que o usuário insira uma sequencia válida
            while (1) {
                //instrui o usuário e armazena a sequencia na variavel de controle
                printf("\nDigite a sequencia a ser descompactada pelo algoritmo 'desprog':\n    Exemplo: a7-bcd3-xy10 ou a7bcd3xy10\n\nSequencia: ");
                scanf("%s", sequencia);
                //calcula o tamanho da sequencia inserida pelo usuário e armazena para ser usada pela função
                TAM_STR = strlen(sequencia);
                //caso a sequencia inserida pelo usuário esteja correta (iniciando por uma letra) irá chamar a função 
                if (getType(sequencia[0]) == 'L') {
                    //chama a função 'desprog'
                    printf("Sai'da: ");
                    desprog(sequencia);
                    break;
                }
                //caso a sequencia inseridapelo usuário não esteja correta uma mensagem é exibida para o usuário de aviso
                else {
                    printf("\nVoce inseriu uma sequencia invalida\n");
                }
            }
        }
        //chama o algoritmo 'prog2'
        else if (opc == 3) {
            //instrui o usuário e armazena a sequencia na variavel de controle
            printf("\nDigite a sequencia com elementos conti'guos repetidos a ser compactada pelo algoritmo 'prog2':\n    Exemplo: abcabcabcabcxyxyxyccccccc\n\nSequencia: ");
            scanf("%s", sequencia);
            //calcula o tamanho da sequencia inserida pelo usuário e armazena para ser usada pela função
            TAM_STR = strlen(sequencia);
            //chama a função 'prog'
            printf("Sai'da: ");
            prog2(sequencia);
        }
        //Exibe um aviso de que a opção inserida no menu está invalida 
        else {
            printf("Digite uma opcao va'lida!\n");
        }
    }
    // Pausa o sistema para que o usuário possa ver os resultados no terminal, para sair pressione qualquer tecla
    system("pause");
    return 0;
}