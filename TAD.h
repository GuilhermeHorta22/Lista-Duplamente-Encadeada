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
	if(desc->inicio == NULL)
		desc->inicio = desc->fim = novo;
	else
	{
		desc->inicio->ant = novo;
		desc->inicio = novo;
	}
}

void inserirFinal(descritor *descritor, int info)
{
	listaDp *novo = (listaDp*)malloc(sizeof(listaDp));
	novo->info = info;
	novo->ant = desc->fim;
	novo->prox = NULL;
	if(desc->inicio == NULL)
		desc->inicio = desc->fim = novo;
	else
	{
		desc->fim->prox = novo;
		desc->fim = novo;
	}
}

listaDp *buscar(descritor *descritor, int info)
{
	
}

int exclui(descritor *desc, int info)
{
	
}


