#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AgendaFuncao.cpp"

int main(){
	struct Agenda agenda;	
	iniciaAgenda(&agenda);
	int opcao;
	
	do {
		system("cls");
		interface();
		scanf("%d", &opcao);
		getchar();
		
	switch (opcao){
		
	case 1: 
		system("cls");
		inserir(&agenda);
		break;
	
	case 2:
		system("cls");
		procura(&agenda);
		break;
	
	case 3:
		system("cls");
		exibirAgenda(&agenda);
		break;
		
	case 4:
		system("cls");
		excluir(&agenda);
		break;
		
	case 5: 
		system("cls");
		alterar(&agenda);
		break;
	
	case 6:
		system("cls");
		estadoAgenda(&agenda);
		break;
		
	case 7:
		system("cls");
		printf("Progama encerrado!\n");
		break;
		
	default:
		system("cls");
		printf("OPCAO INVALIDA!\n");
		system("pause");
		break;
}
}while(opcao!= 7);
	return 0;
}

