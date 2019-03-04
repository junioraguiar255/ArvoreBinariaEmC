#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
int CODIGO = 1;

typedef struct Aluno {
	char nome[50];
	int idade;
	int matricula;
	char naturalidade[20];
	int id;
	struct Aluno * prox;

} aluno;
typedef struct arvore {
	aluno *p;
	struct arvore * esq;
	struct arvore * dir;
} arv;


arv * criaNoArv() {//Metodo para criar N� dinamicamente
	arv * novo = (arv * ) malloc (sizeof(arv));
	return novo;
}
aluno * criaNoAluno() {//Metodo para criar N� dinamicamente
	aluno * novo = (aluno * ) malloc (sizeof(aluno));
	return novo;
}

void alterarCadastro(aluno * cabeca, int idaux) { //metodo para alterar cadastro
	char nomee,naturalidadee;
	int idade,matricula;
	aluno * aux = cabeca;
	while(aux != NULL && aux->id != idaux) {
		aux = aux->prox;
	}
	if(aux != NULL) {
		printf("\n Digite o novo nome do id %d : \n", idaux);
		scanf("%s", &nomee);
		strcpy(aux->nome,nomee);
		
        printf("\n Digite a nova naturalidade do id %d : \n", idaux);
		scanf("%s", &naturalidadee);
		strcpy(aux->naturalidade,naturalidadee);
		
		printf("\n Digite a nova idade do id %d : \n", idaux);
		scanf("%d",&idade);
		aux->idade=idade;
		printf("\n Digite a nova matricula do id %d : \n", idaux);
		scanf("%d",&matricula);
		aux->idade=idade;
		printf("\n =>  Dados alterados com sucesso");
		getch();
	} else {
		printf("\n Imovel nao encontrado");
	}
	
	printf("\n Pressione qualquer tecla para continuar");
}



 

aluno* removeDado(aluno* Cabeca, int dado){ // FUN��O PARA REMOVER UM DADO
	aluno *ptr,*anterior; // PRECISAMOS DE UM PTR PARA ARMAZENAR O ENDERE�O
	// DO N� ANTERIOR DEST� DADO REMOVIDO
	if(Cabeca==NULL){ // PRECISAMOS VERIFICAR SE EXISTE LISTA
		return 0; // SE N EXISTIR LISTA RETORNA 0
	} else // SE EXISTIR A LISTA
	{
		ptr=Cabeca; // PTR RECEBE O ENDERE�O DA NOSSA CABECA
		anterior=NULL; // ESTE PTR SERVIR� PARA ARMAZENAR O ENDERE�O DO N� ANTERIOR
		while(ptr != NULL){ // ENQUANTO PTR FOR DIFERENTE DE NULO
			if(ptr->id==dado){ // SE O VALOR DESTE PTR FOR = AO DADO
				if(ptr==anterior){// VERIFICA SE ESTA ARMAZENADO NO CABECA
					
					Cabeca = Cabeca->prox;// NOSSO CABECA SER� O ENDERE�O DO 2� NO
					free(ptr); // REMOVEMOS NOSSO CABECA DA MEMORIA
                    return 2; // RETORNA 2 � O CABE�A E REMOVE
				}else // SE N�O FOR NOSSO CABECA
				{
					anterior->prox = ptr->prox; // O ANTERIOR NESTE LOOP SEMPRE ARMAZENA O 
					// ENDERE�O DO NOSSO NO ANTERIOR, AQUI ELE RECEBE O ENDERE�O DO N� APOS
					// O N� QUE VAI SER EXCLUIDO.
					free(ptr); // REMOVEMOS ESTE N�
					return 1; // N�O � NOSSO CABE�A E RETORNA 1
				}
				
			}else // ENTRAR� NESTE LOOP AT� ENCONTRAR O VALOR ENVIADO POR PAR�METRO
			{
				anterior = ptr; // ANTERIOR SEMPRE RECEBE O ENDERE�O DO NO ANTERIOR
				ptr = ptr->prox; // RECEBE O VALOR DO PROXIMO N�
			}
			
		} return 0;
	}
	
}

arv * retira(arv * head, int valor) { // fun��o para remover um elemento da nossa arvore
	if(head == NULL) { // verifica se nossa arvore est� vazia
		return NULL; // se estiver vazia, a nossa fun��o retorna NULL
	} else if(head->p.id > valor) { // se o numero que queremos excluir for menor que nossa cabeca, entao procuraremos o valor na esquerda
		head->esq = retira(head->esq, valor); // chamada recursica da fun��o, ir� executar at� encontrar o valor
	} else if(head->p.id < valor) { // se o numero que queremos excluir for maior que nossa cabeca, entao procuraremos o valor na direita
		head->dir = retira(head->dir, valor); // chamada recursiva da fun��o, vamos procurar at� encontrar o valor
	} else { // aqui ja encontramos o valor
		if(head->esq == NULL && head->dir == NULL) { // verificaremos se est� no que contem o valor, tem valores na esq e direita
			free(head); // se n�o tiver valores , s� precisamos remover este n�
			head = NULL;
		} else if (head->esq == NULL) {// se somente a esq do n� for null, ent�o temos que subir o n� da direita

			arv * aux = head; // ponteiro auxiliar para guardar o endere�o do n� a ser excluido
			//	printf("\nValor do no aux %d \n",aux->valor);
			//	printf(" \n Valor do HEAD �%d \n",head->valor);
			head = head->dir; // pegamos o endere�o do n� direito
			//	printf("\n novo valor do head %d \n",head->valor);
			//	printf("Valor do aux %d removido",aux->valor);
			free(aux); // excluimos o no da esquerda.
		} else if (head->dir == NULL) {
			arv * aux = head;
			head = head->esq;
			free(aux);
		}
	}
	return head;
}

aluno * insere(aluno * cabeca, char * nomee, int idadee, int matriculaa, char * naturalidadee) { // metodo para inserir
	aluno * novo = criaNoAluno();
	strcpy(novo->nome, nomee);
	novo->idade = idadee;
	strcpy(novo->naturalidade, naturalidadee);
	novo->matricula = matriculaa;
	novo->id = CODIGO;
	CODIGO += CODIGO;
	if(cabeca == NULL) {
		novo->prox = NULL;
		cabeca = novo;
		return cabeca;
	} else {
		aluno * aux = cabeca;
		while(aux->prox != NULL) {
			aux = aux->prox;
		}
		novo->prox = NULL;

		aux->prox = novo;

	}
	return cabeca;

}

void inserirArv(arv * * cabecaArv, aluno * Lista) { // metodo para inserir

	if( * cabecaArv == NULL) {
		arv * novo = criaNoArv();
		novo->p.id = Lista->id;
		strcpy(novo->p.nome, Lista->nome);
		strcpy(novo->p.naturalidade, Lista->naturalidade);
		novo->p.idade = Lista->idade;
		novo->p.matricula = Lista->matricula;
		novo->esq = NULL;
		novo->dir = NULL;
		* cabecaArv = novo;
		return;

	}
	if(Lista->id < ( * cabecaArv)->p.id) {
		inserirArv( & (*cabecaArv)->esq,Lista);
		return;
	}
	if(Lista->id > ( * cabecaArv)->p.id) {
		inserirArv( & (*cabecaArv)->dir,Lista);
		return;
	}
} 
int estaVazia(arv * cabeca) { 
	if(cabeca == NULL) {
		return 1;
	}
	return 0;
}
int numerosNos(arv * cabeca) {
	if(cabeca == NULL) {
		return 0;
	} else {
		return(numerosNos(cabeca->dir)
			   + 1 + numerosNos(cabeca->esq));
	}
}


// void rotacaoDireita(arv **raiz){
// 	arv *aux;
// 	aux = (*raiz)->dir;
// 	
// }


int consulta(arv * cabeca,int n){ //metodo para consulta na arvore
	if(cabeca==NULL){
		return 0;
	}
	arv *aux=cabeca;
	while(aux != NULL){
		if(n==aux->p.id){
			return 1;
		}
		if(n > aux->p.id){
			aux=aux->dir;
		}else{ 
			aux = aux->esq;
		}
	}
return 0;
}

int numFolhas(arv * cabeca) {// numero de folhas
	if(cabeca == NULL) {
		return 0;
	} else if(cabeca->esq == cabeca->dir) {
		return 1;
	} else {
		return numFolhas(cabeca->esq) + numFolhas(cabeca->dir);
	}
}

int alturaArvore(arv * cabeca) { // altura da arvore
	if(estaVazia(cabeca) == 1) {
		return 0;
	}
	int altEsq = alturaArvore(cabeca->esq);
	int altdir = alturaArvore(cabeca->dir);
	if(altEsq > altdir) {
		return (altEsq + 1);

	} else {
		return (altdir + 1);
	}
}

void imprimirEmOrdem(arv * cabeca) { // metodo para imprimir em ordem nossa arvore, modo crescente. Primeiro os valores da esquerda, depois n
//nosso head, depois a parte direita

	if(cabeca != NULL) {
		imprimirEmOrdem(cabeca->esq);
		printf("%d ", cabeca->p.id);
		imprimirEmOrdem(cabeca->dir);
	}
}


int main() {
	aluno * cadastro = NULL;
  

	return 0;
}
