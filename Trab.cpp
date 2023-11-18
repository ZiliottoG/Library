#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 100
#define MAX_STRING 100


typedef struct Livro {
	char titulo[MAX_STRING], autor[MAX_STRING];
	int id, ano, atividade;
}TLivro;

void exibe_menu(){
		//Exibir as opções do menu
	
		printf("\nBem Vindo\n\n");
		printf("Escolha uma opcao:\n");
		printf("1. Adicionar Livro\n2. Apresentar Livros\n3. Pesquisar Livros\n4. Atualizar Livros\n5. Remover Livros\n6. Sair\n");
}
void exibe_menurep(){
		
		
		printf("\n\nOpcao Invalida!\n\n");
		printf("Escolha uma opcao valida:\n");
		printf("1. Adicionar Livro\n2. Apresentar Livros\n3. Pesquisar Livros\n4. Atualizar Livros\n5. Remover Livros\n6. Sair\n");
}
void cadastrar_livro(TLivro livros[], int apontadora){
	
	
	printf("Entre com o nome do autor:\n");
	fgets(livros[apontadora].autor, MAX_STRING-1, stdin);
	
	printf("Entre com o ano de lançamento do livro:\n");
	scanf("%d", &livros[apontadora].ano);
	getchar();
	
	printf("Entre com o titulo do livro:\n");
	fgets(livros[apontadora].titulo, MAX_STRING-1, stdin);
	
	
	//Definição de ID e Atividade 
	livros[apontadora].id = apontadora + 1;
	livros[apontadora].atividade = 1;
	
	printf("Cadastrado com sucesso!\nID:  0%d\n\n\n\n", livros[apontadora].id);
	
	apontadora++;
	
	}	
void exibe_cadastros(TLivro livros[], int apontadora){
	int i;
	
	for (i=0; i<apontadora; i++) {
	
		printf("--------------------------------------------------------------");
		printf("\nDados do livro %d:\n", livros[i].id);
		printf("Titulo = %s", livros[i].titulo);
		printf("Autor = %s\n", livros[i].autor);
		printf("Ano de publicacao = %d", livros[i].ano);
		printf("\nID = %d\n", livros[i].id);
	
		if(livros[i].atividade == 1){
			printf("Situacao: Em estoque\n");
		}
		else{
			printf("Situacao: Estoque vazio\n");
		}
		printf("-------------------------------------------------------------\n");
	}
}
void pesquisa_cadastro(TLivro livros[], int apontadora){
	
	int numid = 0;	
	
o
	
	while(numid <= 0 || numid > apontadora){

		printf("Digite o ID do livro desejado:\n");
		scanf("%d", &numid);
	
		if(numid <= 0 || numid > apontadora){
			printf("ID invalido ou nao encontrado.\nTente Novamente\n");
		}	
	}
	

	
	numid = numid-1;
	
	printf("--------------------------------------------------------------\n");
	printf("\nDados do livro %d:\n", livros[numid].id);
	printf("Titulo = %s", livros[numid].titulo);
	printf("Autor = %s\n", livros[numid].autor);
	printf("Ano de publicacao = %d", livros[numid].ano);
	printf("\nID = %d\n", livros[numid].id);
	
	if(livros[numid].atividade == 1){
		printf("Situacao: Em estoque\n");
	}
	else{
		printf("Situacao: Estoque vazio\n");
	}
	printf("--------------------------------------------------------------\n");
	
}
void atualiza_cadastro(TLivro livros[], int apontadora){
	
	int numid, op;
	op = 0;
	numid = 0;
	
	//repetição para selecionar ID do aluno
	while(numid <= 0 || numid > apontadora ){
		printf("Digite o ID do cadastro que quer atualizar:\n");
		scanf("%d", &numid);
	
			if(numid <= 0 || numid > apontadora){
				printf("ID invalido ou nao encontrado.\nTente Novamente\n");
			}		
	}	
	
	//ID - 1 para ser selecionado corretamente na struct
	numid = numid - 1;
	
	printf("--------------------------------------------------------------\n");
	printf("\nDados do livro %d:\n", livros[numid].id);
	printf("Titulo = %s", livros[numid].titulo);
	printf("Autor = %s\n", livros[numid].autor);
	printf("Ano de publicacao = %d", livros[numid].ano);
	printf("\nID = %d\n", livros[numid].id);
	
	if(livros[numid].atividade == 1){
		printf("Situacao: Em estoque\n");
	}
	else{
		printf("Situacao: Estoque vazio\n");
	}
	printf("--------------------------------------------------------------\n");
	
	//menu para a mudança do cadastro
	while(op <= 0 || op > 3){
		printf("O que deseja alterar nesse cadastro?\n\n");
	
		printf("1. Titulo\n2. Ano de publicação\n3. Autor\n");
		scanf("%d", &op);
		
		if(op <= 0 || op > 3){
			printf("Opcao invalida!\n");
		}
	
	}
	
	
	
	switch(op){
		
		case 1:
			getchar();
			printf("Entre com o titulo:\n");
			fgets(livros[numid].titulo, MAX_STRING-1, stdin);
		
		break;
		
		case 2:
			printf("Entre com o ano de publicação:\n");
			scanf("%d", &livros[numid].ano);
		
		break;
		
		case 3:
			getchar();
			printf("Entre com o autor do livro:\n");
			fgets(livros[numid].autor, MAX_STRING-1, stdin);
		
		break;
		
		default:
			printf("opcao invalida!\n");
		
		break;
	}
	
	printf("Operacao realizada com sucesso!\n");
	
	
}
int remove_cadastro (TLivro livros[], int apontadora){


	int op, numid;
	
	op = 0;
	
	numid = 0;
	
	while (op != 1){
	
		while (numid <= 0 || numid > apontadora){
		
			printf("Digite o ID do livro que Deseja remover:\n");
			scanf("%d", &numid);
		
			if (numid <= 0 || numid > apontadora) {
				printf("ID invalido ou nao encontrado.\nTente Novamente\n");
			}	
		}
	
		numid = numid - 1;
	
		printf("--------------------------------------------------------------\n");
		printf("\nDados do livro %d:\n", livros[numid].id);
		printf("Titulo = %s", livros[numid].titulo);
		printf("Autor = %s\n", livros[numid].autor);
		printf("Ano de publicacao = %d", livros[numid].ano);
		printf("\nID = %d\n", livros[numid].id);
		
		if(livros[numid].atividade == 1){
			printf("Situacao: Em estoque\n");
		}
		else{
			printf("Situacao: Estoque vazio\n");
		}
		printf("--------------------------------------------------------------\n");;
	
		printf("\n\nDeseja inativar esse cadastro?\n");
		printf("1. Para sim\n2. Para nao\n");
		scanf("%d", &op);
	}
		if(op == 1){
		
			livros[numid].atividade = 0;
		}
		else if(op == 2){
			return 0;
		}
	
	printf("--------------------------------------");
	printf("\nOperacao realizada com sucesso!\n");
	printf("--------------------------------------\n");
}

int main(){
	
	TLivro livros[TAM];
	
	int opcao, num_livros, apontadora;
	
	apontadora = 0;
	opcao = 0;
	
	while(opcao != 6){	
	
		exibe_menu();
		
		scanf("%d", &opcao);
	
		if(opcao > 6 || opcao <=0){
			
			exibe_menurep();
		}
		
		switch (opcao){
		
			case 1: 
				getchar();
				cadastrar_livro(livros, apontadora);
				apontadora++;
			break;
		
			case 2:
				exibe_cadastros(livros, apontadora);
						
			break;
		
			case 3:
				pesquisa_cadastro(livros, apontadora);
			
			break;
		
			case 4:
				atualiza_cadastro(livros, apontadora);
			
			break;
		
			case 5:
				remove_cadastro(livros, apontadora);
			
			break;
			
			case 6:
				printf("\nEncerrando...\n");
			break;
		
		}
	}
}
