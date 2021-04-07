//Implementar uma pilha com dez posições de elementos inteiros;

#include <stdio.h>

#define TAMANHO 10

int topo = 0; //variaveis globais
int pilha [TAMANHO]; //variaveis globais

void Push_Pilha(int valor)
{
    if (topo < TAMANHO){
        pilha[topo] = valor;
        topo++;
        printf("\nInsercao completo\n");
    }
    else
        printf("\nERRO : Pilha cheia\n");
}

int Pop_Pilha()
{
    if (topo == 0)
    {
        printf("\nERRO : Pilha atualmente vazia\n");
        return 0;
    }
    else{
        topo--;
        return pilha[topo];
    }
    
}

int Size_Pilha()
{
    return topo;
}

int Peek_Pilha()
{
    if (topo == 0)
    {
        printf("\n\nPilha ainda sem valores\n\n");
        return 0;
    }
    else
        return pilha[topo-1];
}

void Clear_Pilha()
{
    topo = 0;
}

void List_Pilha()
{
    int i;
    printf("\n\nValor dentro da pilha: \n");
    for (i = topo-1; i > -1; i--)
    {
        printf("O valor na posicao %i e : %i\n", i+1, pilha[i]);
    }
}

void main()
{
    char op;
    int aux;

    printf("Bem vindo ao sistema!\n\n");

    while (op != 'X')
    {
        printf("A - Adicionar um elemento na pilha\n");
        printf("R - Remover um elemento da pilha\n");
        printf("S - Verificar o tamanho atual da pilha\n");
        printf("L - Lista toda a lista\n");
        printf("P - Examinar o ultimo elemento da pilha\n");
        printf("C - limpa todos os elementos da pilha\n");
        printf("X - Para sair\n");
        fflush(stdin);
        scanf("%c", &op);
        if(op == 'A' || op == 'a')
        {
            printf("Digite o valor a ser inserido: ");
            scanf("%i", &aux);
            Push_Pilha(aux);
        }
        else if(op == 'R' || op == 'r')
            printf("Valor removido eh: %i\n\n",Pop_Pilha());
        else if(op == 'S' || op == 's')
            printf("O tamanho e : %i\n",Size_Pilha());
        else if(op == 'L' || op == 'l')
            List_Pilha();
        else if(op == 'P' || op == 'p')
            printf("Valor examinado na ultima posicao : %i\n", Peek_Pilha());
        else if(op == 'C' || op == 'c')
            Clear_Pilha();
        else
            printf("ERRO : Operacao nao definida");
        
    }
    

}