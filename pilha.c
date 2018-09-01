# include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct elo{
		int dado;
		struct elo *prox;
	}*temp,aux;
typedef struct elo elo;	
void imprima(elo *a);
void inserir(elo *a);
void excluir(elo *a);
	
int main(void){
	int a;
	setlocale(LC_ALL,"");
	elo *p;
	p = (struct elo *)malloc (sizeof(struct elo));
	p->prox = NULL;
	while(1){
		printf("Deseja fazer o que:\n 1-inserir\n 2-imprimir\n 3-excluir\n");
		scanf("%d",&a);
		if(a==1){
			inserir(p);
		}
		if(a==2){
			imprima(p);
		}
		if(a==3){
			excluir(p);
		}
	}
}

void imprima(elo *a){
	elo* i;
	for(i = a->prox; i!=NULL; i = i->prox){
		printf("%d\n",i->dado);
	}
}

void inserir(elo *a){
	int info;
	elo *nova;
	nova = (struct elo *)malloc (sizeof(struct elo));
	printf("Escreva um número:");
	scanf("%i",&info);
	nova->dado = info;
	nova->prox = a->prox;
	a->prox = nova;
}

void excluir(elo *a){
	elo *del;
	del = a->prox;
	a->prox = del->prox;
	free(del);
}
