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
		puts("\n\n\n");
	}
}

void imprima(elo *a){
	puts("----------------------");
	/*Esse while imprime até que o ponteiro a aponte 
	para o último link da LinkedList*/
	while(a != NULL){
		printf("%d ",a->dado);
		a = a->prox;
	}
	puts("\n----------------------");

}

void inserir(elo *a){
	if(a->dado == 0 && a->prox == NULL){
		int info;
		printf("Escreva um numero: ");
		scanf("%i", &info);
		a->dado = info;
	}else{
	
	int info;
	elo * b = a;
	/*	Criado um novo ponteiro para saber
		onde é o inicio
	*/	
		elo *nova = (struct elo *)malloc (sizeof(struct elo));
		printf("Escreva um número:");
		scanf("%i",&info);
		nova->dado = info;
		nova->prox = NULL;
		while(b->prox != NULL){
			b = b->prox;
		}
		b->prox= nova;
}}

void excluir(elo *a){
	/*Não arrumado ainda*/
	elo *del;
	del = a->prox;
	a->prox = del->prox;
	free(del);
}
