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
	printf("\n[C] - Inserir no final");
	printf("\n[D] - Buscar elemento");
	printf("\n[E] - Excluir elemento");
	printf("\n[F] - Verifica se esta vazia");
	printf("\n[G] - Exibe lista");
	printf("\n[ESC] - Sair");
	printf("\nOpcao: ");
	return toupper(getche());
}

int main()
{
	descritor *desc = (descritor*)malloc(sizeof(descritor)); //alocando caixinha na memoria
	listaDp *aux;
	
	char op;
	int num, flag;
	
	do
	{
		op = menu();
		printf("\n\n");
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
				
				inserirInicio(desc,num);
				
				break;
				
			case 'C':
				printf("*** INSERIR NO FINAL ***\n");
				
				printf("\nNumero: ");
				scanf("%d",&num);
				
				inserirFinal(desc,num);
				
				break;
				
			case 'D':
				printf("*** BUSCAR NUMERO ***\n");
				
				printf("\nNumero: ");
				scanf("%d",&num);
				
				aux = buscar(desc,num);
				
				if(aux == NULL)
					printf("\nNao foi encontrado o numero!");
				else
					printf("\nNumero encontrado! Posicao: %u",&aux); //tenho que ver se é isso mesmo
				
				break;
				
			case 'E':
				printf("*** EXCLUI NUMERO ***\n");
				
				printf("\nNumero: ");
				scanf("%d",&num);
				
				flag = exclui(desc,num);
				
				if(flag == 1) //deu certo
					printf("\nNumero excluido!");
				else
					printf("\nNumero nao foi excluido!");
					
				break;
				
			case 'F':
				printf("*** VERIFICA SE ESTA VAZIA ***\n");
				
				op = isEmpty(desc);
				
				if(op == 1)
					printf("\nEsta vazia!");
				else
					printf("\nNao esta vazia!");
				
				break;
				
			case 'G':
				printf("*** EXIBE LISTA ***\n");
				
				exibe(desc);
				
				break;
				
			case 27:
				printf("*** PROGRAMA ENCERRADO ***");
				
				break;
				
		}
		getch();
		system("cls");
	}while(op != 27);
}
