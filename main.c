
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct reg{
    int id;
    float value;
    float score;
} registro;

void troca(registro *dados, int posOrig, int novaPos){
    //printf("Troca \n");
    registro aux;
    aux.score = dados[posOrig].score;
    aux.value = dados[posOrig].value;
    aux.id = dados[posOrig].id;

    dados[posOrig].score = dados[novaPos].score;
    dados[posOrig].value = dados[novaPos].value;
    dados[posOrig].id = dados[novaPos].id;


    dados[novaPos].score = aux.score;
    dados[novaPos].value = aux.value;
    dados[novaPos].id
    = aux.id;
    //printf("Fim Troca \n");
}

//implementacao do algoritmo insertionsort, retorna o número de comparações feitas
int insertionSort(registro *dados, int qtdReg, int *numTrocas){
    printf("a");
}

//implementacao do algoritmo bubblesort, retorna o número de comparações feitas
int bubbleSort(registro *dados, int qtdReg, int *numTrocas){

}

//implementacao do algoritmo selectionsort, retorna o número de comparações feitas
int selectionSort(registro *dados, int qtdReg, int *numTrocas){

}

//implementacao do algoritmo selectionsort, retorna o número de comparações feitas
int shellSort(registro *dados, int qtdReg, int *numTrocas){
    printf("a");
}

void quickSort(registro *dados, int esq, int dir, int *qtdTrocas, int *qtdComparacoes){
    printf("a");
}

registro * leitura(int *qtdReg){
    FILE *arquivo;
    registro *dados;
    char nomearquivo[50];
    char buffer[2000];
    int cont;

    printf("Nome arquivo:\t");
    scanf(" %[^\n]s",nomearquivo);
    printf("Quantidade de registros no arquivo:\t");
    scanf("%d", &qtdReg[0]);

    dados = (registro *) malloc(qtdReg[0]*sizeof(registro));
    arquivo = fopen(nomearquivo,"r");

    if(arquivo == NULL){
        printf("Não foi possível abrir o arquivo \n");
        return NULL;
    }

    //leitura dos dados do arquivo
    for(cont = 0; cont<qtdReg[0]; cont++){
        fgets(buffer,2000, arquivo);
        sscanf(buffer,"%d\t%f\t%f\t",&dados[cont].id,dados[cont].value, dados[cont].score);
        //printf("codigo: %d ip %s\n",dados[cont].codigo, dados[cont].ip);
    }
    fclose(arquivo);
    return dados;
}

void merge(registro *v, registro *c, int i, int m, int f){
    int cont, contv = i, contc = m+1;
    //copia os dados para o vetor auxiliar
    for(cont = i; cont<=f; cont++){
        c[cont].score = v[cont].score;
        c[cont].value = v[cont].value;
        c[cont].id = v[cont].id;
        printf("%f,\t",c[cont].score);
    }
    cont = i;
    printf("\n MERGE \n");
    while(contv <= m && contc <= f){
        //o elemento da primeira partição é menor
        if(c[contv].score <= c[contc].score){
            v[cont].score = c[contv].score;
            v[cont].value = c[contv].value;
            v[cont].id = c[contv].id;
            printf("%f,\t",v[cont].score);
            cont++;
            contv++;
        }
        else{
            v[cont].score = c[contc].score;
            v[cont].value = c[contc].value;
            v[cont].id = c[contc].id;
            printf("%f,\t",v[cont].score);
            cont++;
            contc++;
        }

    }

    while(contv <= m){
        v[cont].score = c[contv].score;
        v[cont].value = c[contv].value;
        v[cont].id = c[contv].id;
        printf("%f,\t",v[cont].score);
        cont++;
        contv++;
    }

    while(contc <= f){
        v[cont].score = c[contc].score;
        v[cont].value = c[contc].value;
        v[cont].id = c[contc].id;
        printf("%f,\t",v[cont].score);
        cont++;
        contc++;
    }
    printf("\n\n");
}

void sort(registro *v, registro *c, int i, int f){
    if(i>=f)
        return;
    int m = (i+f)/2;
    sort(v,c,i,m);
    sort(v,c,(m+1),f);

    if(v[m].score <= v[m+1].score)
        return;
    merge(v,c,i,m,f);
}


void mergesort(registro *v, int n){
    registro *c = (registro *) malloc(sizeof(registro)*n);
    sort(v,c,0,n-1);
    free(c);
}




int main() {
    FILE *arquivo;
    registro *dados = NULL;
    char nomearquivo[50];
    int qtdReg;
    int cont, numeroTrocas = 0, numeroComparacoes = 0;
    int continuar=1;
    do
    {
        printf("\n\tMetodos de Ordenacao\n\n");
        printf("1. Leitura\n");
        printf("2. InsertionSort\n");
        printf("3. ShellSort\n");
        printf("4. QuickSort\n");
        printf("5. MergeSort\n");
        printf("6. Imprimir\n");
        printf("0. Sair\n");
        scanf("%d", &continuar);

        switch(continuar)
        {
            case 1:
                if(dados != NULL){
                    free(dados);
                }
                dados = leitura(&qtdReg);
                break;

            case 2:
                numeroComparacoes = insertionSort(dados, qtdReg, &numeroTrocas);
                printf("Numero Trocas %d\n Numero Comparações: %d\n", numeroTrocas, numeroComparacoes);
                break;

            case 3:
                numeroComparacoes = shellSort(dados, qtdReg, &numeroTrocas);
                printf("Numero Trocas %d\n Numero Comparações: %d\n", numeroTrocas, numeroComparacoes);
                break;
            case 4:
                numeroTrocas = 0;
                numeroComparacoes = 0;
                quickSort(dados, 0, (qtdReg-1), &numeroTrocas, &numeroComparacoes);
                printf("Numero Trocas %d\n Numero Comparações: %d\n", numeroTrocas, numeroComparacoes);
                break;
            case 5:
                mergesort(dados,qtdReg);
                break;
            case 6:
                for(cont = 0; cont< qtdReg; cont++){
                    printf("score: %f id %id\n",dados[cont].score, dados[cont].id);
                }
                break;
            case 0:
                exit(0);
                break;

            default:
                printf("Digite uma opcao valida\n");
        }
    } while(continuar);


    free(dados);
    return 0;
}