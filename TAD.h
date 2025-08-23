struct TpListaDp
{
	int info;
	struct TpListaDp *ant, *prox;
};
typedef struct TpListaDp listaDp;

struct TpDescritor
{
	listaDp *inicio, *fim;
};
typedef struct TpDescritor descritor;

void init(descritor **desc)
{
	(*desc)->inicio = (*desc)->fim = NULL;
}

char isEmpty(descritor *desc)
{
	return desc->inicio == NULL;
}

void inserirInicio(descritor *desc, int info)
{
	listaDp *novo = (listaDp*)malloc(sizeof(listaDp));
	novo->info = info;
	novo->ant = NULL;
	novo->prox = desc->inicio;
	if(isEmpty(desc))
		desc->inicio = desc->fim = novo;
	else
	{
		desc->inicio->ant = novo;
		desc->inicio = novo;
	}
}

void inserirFinal(descritor *desc, int info)
{
	listaDp *novo = (listaDp*)malloc(sizeof(listaDp));
	novo->info = info;
	novo->ant = desc->fim;
	novo->prox = NULL;
	if(isEmpty(desc)) //retorna se está vazio
		desc->inicio = desc->fim = novo;
	else
	{
		desc->fim->prox = novo;
		desc->fim = novo;
	}
}

listaDp *buscar(descritor *desc, int info)
{
	listaDp *aux = desc->inicio;
	
	while(aux != NULL && aux->info != info)
		aux = aux->prox;
		
	if(aux != NULL)
		return aux;
	else
		return NULL;
}

int exclui(descritor *desc, int info)
{
	listaDp *aux;
	
	if(!isEmpty(desc))
	{
		//buscar o elemento
		aux = buscar(desc,info);
		
		//verificar se achou
		if(aux != NULL)
		{
			if(desc->inicio == aux && desc->fim == aux) //unico elemento na lista
			{
				desc->inicio = NULL;
				desc->fim = NULL;
			}
			else
			if(desc->inicio == aux) //verifico se é no começo
			{
				desc->inicio = desc->inicio->prox;
				desc->inicio->ant = NULL;
			}
			else
			if(desc->fim == aux) //verifico se é no final
			{
				desc->fim = desc->fim->ant;
				desc->fim->prox = NULL;
			}
			else //verifico se é no meio
			{
				aux->ant->prox = aux->prox;
				aux->prox->ant = aux->ant;
			}
			free(aux);
		}
	}
}

void exibe(descritor *desc)
{
	listaDp *aux = desc->inicio;
	
	while(aux != NULL)
	{
		printf("%d\t",aux->info);
		aux = aux->prox;
	}
}
