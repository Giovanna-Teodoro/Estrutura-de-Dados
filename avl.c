#include <stdio.h>


struct no
{
	char chave;
	struct no * esq, dir;
	int bal;
	
};
typedef struct no no;

no* crie_no (char c){

	no * novo;
	novo = (no*) malloc(sizeof(no));
	novo->chave = c;
	novo->esq = NULL;
	novo->dir = NULL;
	novo->bal = 0;

	return novo;

}


no *inserir_nn (no *raiz, char x, int *cresceu){
	if(raiz == NULL){
		*cresceu = 1;
		return crie_no(x);
	}

	if(x < raiz->chave){
		raiz->esq = inserir_nn(raiz->esq, x, cresceu);
		if(cresceu==1){
			raiz->bal -= 1;
			if(raiz->bal == 0){
				cresceu = 0;
			}
		}
	}
	else if(x > raiz->dir){
		raiz->dir = inserir_nn(raiz->dir, x, cresceu);
		if(cresceu == 1){
			raiz->bal += 1;
			if(raiz->bal == 0){
				cresceu = 0;
			}
		}
	}
 
	return raiz;
}

no* inserir(no *raiz, char x){
	int cresceu = 0;

	inserir_nn(raiz, x, &cresceu);
}


int main(){

	return 0;
}