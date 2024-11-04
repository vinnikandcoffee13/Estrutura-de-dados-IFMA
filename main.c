#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char sexo;
    char nome[30];
    int idade;
} pessoas;

int main(){
    FILE* Arq = fopen("Entrada.txt", "rt");
    int contPessoas, contHomens = 0, contMulheres = 0, contIdade = 0;
    fscanf(Arq, "%d\n", &contPessoas);
    pessoas pess[contPessoas];
    for(int i = 0; !feof(Arq);i++){
        fscanf(Arq,"%c %s %d\n", &pess[i].sexo, &pess[i].nome, &pess[i].idade);
    }
    for(int i=0;i<contPessoas;i++){
        if(pess[i].sexo=='M'){
            contHomens++;
        }
        else if(pess[i].sexo=='F'){
            contMulheres++;
        }
        if(contIdade<pess[i].idade){
            contIdade=pess[i].idade;
        }
    }
   fclose(Arq);
    Arq=fopen("Saida.txt","w");
    fprintf(Arq,"Numero de Homens: %d\nNumero de Mulheres: %d\nA idade da pessoa mais velha: %d",contHomens,contMulheres,contIdade);
    fclose(Arq);
    return 0;
}