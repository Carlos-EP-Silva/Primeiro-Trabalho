#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "AgendaLibrary.h"

void iniciaAgenda(Agenda* agenda) {
    agenda->tam = 0;
}

void interface(){
  printf(" AGENDA TELEFONICA\n\n");
  printf("1 - INSERIR CONTATO \n");
  printf("2 - PROCURAR CONTATO \n");
  printf("3 - EXIBIR CONTATOS\n");
  printf("4 - APAGAR CONTATO\n");
  printf("5 - ALTERAR CONTATO\n");
  printf("6 - ESTADO DA AGENDA\n");
  printf("7 - ENCERRAR PROGAMA\n");
  printf("  OPCAO ESCOLHIDA:");
}

int verificaContatoDuplicado(Agenda *agenda, char *nomeNovoContato) {
  for (int i = 0; i < agenda->tam; i++) {
    if (strcmp(agenda->contato[i].nome, nomeNovoContato) == 0) {
      return 1; 
    }
  }
  return 0; 
}

void inserir(Agenda* agenda){
  if (agenda->tam < MAX_contatos) {
    printf(" Digite o Nome do Contato: ");
    fgets(agenda->contato[agenda->tam].nome, 50, stdin);
    agenda->contato[agenda->tam].nome[strcspn(agenda->contato[agenda->tam].nome, "\n")] = '\0';

    int contatoDuplicado = verificaContatoDuplicado(agenda, agenda->contato[agenda->tam].nome);
    if (contatoDuplicado) {
      printf(" Contato ja existente! \n");
      system("pause");
      return;
    }

    printf(" Digite o Telefone Celular: ");
    scanf("%d", &agenda->contato[agenda->tam].fone.Celular);
    printf(" Digite o Telefone Residencial: ");
    scanf("%d", &agenda->contato[agenda->tam].fone.Residencial);
    getchar();
    agenda->tam++;
    system("pause");
    return;
  } else {
    printf(" Agenda cheia!\n");
    system("pause");
  }
}

void procura(Agenda *agenda){
  char proc[50];
  int encontrado = 0;
  if (agenda->tam == 0) {
    printf(" Agenda vazia!\n");
    system("pause");
    return;
  }
  if (agenda->tam == MAX_contatos) {
    printf("Agenda cheia!\n");
    system("pause");
    return;
  }

  printf(" Digite o nome do contato que deseja encontrar (pode ser so uma parte do nome)\n Nome: ");
  fgets(proc, 50, stdin);
  proc[strcspn(proc, "\n")] = '\0';
  system("cls");

  for (int i = 0; i < agenda->tam; i++) {
    if (strstr(agenda->contato[i].nome, proc) != NULL) {
      printf(" CONTATO ENCONTRADO!\n\n");
      printf(" NOME: %s\n", agenda->contato[i].nome);
      printf(" TELEFONE CELULAR: %d\n", agenda->contato[i].fone.Celular);
      printf(" TELEFONE RESIDENCIAL: %d\n", agenda->contato[i].fone.Residencial);
      encontrado = 1;
      system("pause");
      break;
    }
  }

  if (encontrado == 0) {
    printf(" Contato não encontrado!\n");
    system("pause");
  }
}

void excluir(Agenda *agenda){
	char proc[50];
	int encontrado = 0;
	int ctz;
	
	if (agenda->tam == 0) {
        printf(" Agenda vazia!\n");
        system("pause");
        return;
    }if (agenda->tam == MAX_contatos) {
        printf(" Agenda cheia!\n");
        system("pause");
        return;
    }
	printf(" Digite o nome do contato que deseja excluir: ");
	fgets(proc,50,stdin);
	proc[strcspn(proc, "\n")] = '\0';
	
	system("cls");
	for(int i=0; i <agenda->tam; i++){
	if(strcmp(agenda->contato[i].nome, proc) == 0){
		printf(" CONTATO ENCONTRADO\n");
		printf(" NOME: %s\n", agenda->contato[i].nome);
		printf(" TELEFONE CELULAR: %d\n", agenda->contato[i].fone.Celular);
		printf(" TELEFONE RESIDENCIAL: %d\n", agenda->contato[i].fone.Residencial);
		printf(" Tem certeza que deseja excluir o contato? ( 1 ) sim \\ ( 2 )nao: ");
		scanf("%d", &ctz);
		getchar();
		encontrado = 1;
		if (ctz==1){
			system("cls");
			for (int j = i; j < agenda->tam - 1; j++) {
                agenda->contato[j] = agenda->contato[j + 1];
            }
            agenda->tam--;
            printf(" Contato excluido com sucesso!\n");
            system("pause");
		}
		
		break;
	}
	}
	if(encontrado==0){
		printf(" Contato Nao Encontrado!\n");
		system("pause");
	}
}

void exibirAgenda(Agenda *agenda){
	if (agenda->tam == 0) {
        printf(" A agenda esta vazia!\n");
        system("pause");
        return;
    }

    for (int i = 0; i < agenda->tam - 1; i++) {
        for (int j = 0; j < agenda->tam - 1 - i; j++) {
            if (strcmp(agenda->contato[j].nome, agenda->contato[j + 1].nome) > 0) {
                Contato temp = agenda->contato[j];
                agenda->contato[j] = agenda->contato[j + 1];
                agenda->contato[j + 1] = temp;
            }
        }
    }

    printf(" CONTATOS ORDENADOS POR ORDEM ALFABETICA:\n\n");
    for (int i = 0; i < agenda->tam; i++) {
        printf(" NOME: %s\n", agenda->contato[i].nome);
        printf(" TELEFONE CELULAR: %d\n", agenda->contato[i].fone.Celular);
        printf(" TELEFONE RESIDENCIAL: %d\n", agenda->contato[i].fone.Residencial);
        printf("\n");
    }
    system("pause");
}

void alterar(Agenda *agenda){
	char proc[50];
	int encontrado = 0;
	int ctz;
	
	if (agenda->tam == 0) {
        printf(" A agenda esta vazia!\n");
        system("pause");
        return;
    }
	printf(" Digite o nome do contato que deseja alterar: ");
	fgets(proc,50,stdin);
	proc[strcspn(proc, "\n")] = '\0';
	
	system("cls");
	for(int i=0; i <agenda->tam; i++){
	if(strcmp(agenda->contato[i].nome, proc) == 0){
		printf(" CONTATO ENCONTRADO!\n\n");
		printf(" NOME: %s\n", agenda->contato[i].nome);
		printf(" TELEFONE CELULAR: %d\n", agenda->contato[i].fone.Celular);
		printf(" TELEFONE RESIDENCIAL: %d\n", agenda->contato[i].fone.Residencial);
		printf(" Tem certeza que deseja alterar o contato? ( 1 ) sim \\ ( 2 )nao: ");
		scanf("%d", &ctz);
		getchar();
		encontrado = 1;
		system("cls");
		
		if (ctz==1){
        printf(" Digite o Novo Nome do Contato: ");
        fgets(agenda->contato[i].nome, 50, stdin);
        agenda->contato[i].nome[strcspn(agenda->contato[i].nome, "\n")] = '\0';
        printf(" Digite o Novo Telefone Celular: ");
        scanf("%d", &agenda->contato[i].fone.Celular);
        printf(" Digite o Novo Telefone Residencial: ");
        scanf("%d", &agenda->contato[i].fone.Residencial);
        getchar(); 
        printf(" Contato alterado com sucesso.\n");
        system("pause");
		}
	}
}

if(encontrado==0){
		printf(" Contato Nao Encontrado!\n");
		system("pause");
	}
}

void estadoAgenda(Agenda *agenda){
	if (agenda->tam == 0) {
        printf(" Agenda vazia!\n");
        system("pause");
        return;
    }if (agenda->tam == MAX_contatos) {
        printf(" Agenda cheia!\n");
        system("pause");
        return;
    }else{
    	printf(" Tamanho Atual da Agenda: %d\n", agenda->tam);
    	printf(" Espaco livre na Agenda: %d\n", MAX_contatos - agenda->tam);
		system("pause");
	}   
}
