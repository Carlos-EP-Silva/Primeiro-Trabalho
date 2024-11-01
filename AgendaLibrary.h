#define MAX_contatos 100
struct telefone{
	int Celular;
	int Residencial;
};
struct Contato{
	char nome[50];
	struct telefone fone;
};
struct Agenda{
	Contato contato[MAX_contatos];
	int tam;
};

void iniciaAgenda(Agenda* agenda);
void inserir(Agenda *agenda);
void procura(Agenda *agenda);
void excluir(Agenda *agenda);
void exibirAgenda(Agenda *agenda);
