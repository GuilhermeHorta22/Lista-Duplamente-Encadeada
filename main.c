#include<stdio.h>
#include<conio2.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#include "TAD.h"


//menu para executar o programa
char menu()
{
	printf("### MENU ###\n");
	printf("\n[A] - Inicializar lista");
	printf("\n[B] - Inserir no inicio");
	printf("\n[C] - Buscar elemento");
	printf("\n[D] - Excluir elemento");
	printf("\n[E] - Verifica se esta vazia");
	printf("\n[ESC] - Sair");
	printf("\nOpcao: ");
	return toupper(getche());
}

int main()
{
	descritor *desc;
	listaDp *aux;
	
	char op;
	int num, flag;
	
	do
	{
		system("cls");
		op = menu();
		switch(op)
		{
			case 'A':
				printf("*** INICIALIZAR LISTA ***\n");
				
				init(&desc);
				
				break;
				
			case 'B':
				printf("*** INSERIR NO INICIO ***\n");
				
				printf("\nNumero: ");
				scanf("%d",&num);
				
				inserirInicio(&desc,num);
				
				break;
				
			case 'C':
				printf("*** INSERIR NO FINAL ***\n");
				
				printf("\nNumero: ");
				scanf("%d",&num);
				
				inserirFinal(&desc,num);
				
				break;
				
			case 'D':
				printf("*** BUSCAR NUMERO ***\n");
				
				printf("\nNumero: ");
				scanf("%d",&num);
				
				aux = buscar(lista,num);
				
				if(aux == NULL)
					printf("\nNao foi encontrado o numero!");
				else
					printf("\nNumero encontrado! Posicao: %u",&aux); //tenho que ver se é isso mesmo
				
				break;
				
			case 'E':
				printf("*** EXCLUI NUMERO ***\n");
				
				printf("\nNumero: ");
				scanf("%d",&num);
				
				flag = exclui(lista,num);
				
				if(flag == 1) //deu certo
					printf("\nNumero excluido!");
				else
					printf("\nNumero nao foi excluido!");
					
				break;
				
			case 27:
				printf("*** PROGRAMA ENCERRADO ***");
				
				break;
				
			getch();
		}
	}while(op != 27);
}
