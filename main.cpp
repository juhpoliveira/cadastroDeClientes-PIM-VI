#include <windows.h>
#include <fstream>
#include <unistd.h>

using namespace std;

struct cliente {
	char nome[100];
	char sobrenome[100];
	char cpf[100];
	char dataNascimento[100];
	char telefone[100];
	char celular[100];
	char email[100];
	char endereco[100];
	char bairro[100];
	char complemento[100];
	char cidade[100];
	char estado[100];
	char cep[100];
} CLIENTE2;

int qntCliente(1);

cliente array[1000];

void cadastrarClientes() {
	printf("Nome: ");
	scanf("%s",&array[qntCliente].nome);
	printf("Sobrenome: ");
	scanf("%s",&array[qntCliente].sobrenome);
	printf("CPF: ");
	scanf("%s",&array[qntCliente].cpf);
	printf("Data de nascimento: ");
	scanf("%s",&array[qntCliente].dataNascimento);
	printf("Telefone: ");
	scanf("%s",&array[qntCliente].telefone);
	printf("Celular: ");
	scanf("%s",&array[qntCliente].celular);
	printf("Email: ");
	scanf("%s",&array[qntCliente].email);
	printf("Endereco: ");
	scanf("%s",&array[qntCliente].endereco);
	printf("Bairro: ");
	scanf("%s",&array[qntCliente].bairro);
	printf("Complemento: ");
	scanf("%s",&array[qntCliente].complemento);
	printf("Cidade: ");
	scanf("%s",&array[qntCliente].cidade);
	printf("Estado: ");
	scanf("%s",&array[qntCliente].estado);
	printf("cep: ");
	scanf("%s",&array[qntCliente].cep);
	qntCliente += 1;
	
}

void mostrarClientes() {
	int i;
	printf("\n");
	for (i = 1; i <= qntCliente - 1; i++) {
		printf("\n-- ======================================== --\n");
		printf("\nNome: %s",array[i].nome); 
		printf("\nSobrenome: %s",array[i].sobrenome);
		printf("\nCPF: %s\n\n",array[i].cpf);
		printf("\nData de nascimento: %s",array[i].dataNascimento);
		printf("\nTelefone: %s",array[i].telefone);
		printf("\nCelular: %s",array[i].celular);
		printf("\nEmail: %s",array[i].email);
		printf("\nEndereco: %s",array[i].endereco);
		printf("\nBairro: %s",array[i].bairro);
		printf("\nComplemento: %s",array[i].complemento);
		printf("\nCidade: %s",array[i].cidade);
		printf("\nEstado: %s",array[i].estado);
		printf("\nCEP: %s\n\n",array[i].cep);
		printf("-- ========================================= --\n");

	}
}

void ClearScreen()
  {
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );
  }

void salvarArquivo() {
	ofstream file_;
	int i;
	file_.open("cadastros.txt");
	
	for (i = 1; i <= qntCliente - 1; i++) {
		file_ << "\n\nNome: " << array[i].nome;
		file_ << "\nSobrenome: " << array[i].sobrenome;
		file_ << "\nCPF: " << array[i].cpf;
		file_ << "\nData de nascimento: " << array[i].dataNascimento;
		file_ << "\nTelefone: " << array[i].telefone;
		file_ << "\nCelular: " << array[i].celular;
		file_ << "\nEmail: " << array[i].email;
		file_ << "\nEndereco: " << array[i].endereco;
		file_ << "\nBairro: " << array[i].bairro;
		file_ << "\nComplemento: " << array[i].complemento;
		file_ << "\nCidade: " << array[i].cidade;
		file_ << "\nEstado: " << array[i].estado;
		file_ << "\nCEP: " << array[i].cep;
		printf("\n-- =============================================== --\n");
		printf("\nNome: %s",array[i].nome); 
		printf("\nSobrenome: %s",array[i].sobrenome);
		printf("\nCPF: %s",array[i].cpf);
		printf("\nData de nascimento: %s",array[i].dataNascimento);
		printf("\nTelefone: %s",array[i].telefone);
		printf("\nCelular: %s",array[i].celular);
		printf("\nEmail: %s",array[i].email);
		printf("\nEndereco: %s",array[i].endereco);
		printf("\nBairro: %s",array[i].bairro);
		printf("\nComplemento: %s",array[i].complemento);
		printf("\nCidade: %s",array[i].cidade);
		printf("\nEstado: %s",array[i].estado);
		printf("\nCEP: %s\n\n",array[i].cep);
		printf("-- =================================================== --\n");
		usleep(0.2 * 1000000);
		ClearScreen();
	}
	
	file_.close();
}

int main() {
	
	setlocale(LC_ALL,"Portuguese");
	int command;
	
	printf("-- ===================================================== --\n");
	printf("-- PAINEL DE CADASTRO ================================= --\n");
	printf("-- ===================================================== --\n");
	printf("\n\n\n\n\n");
	
	while(1) {
		printf("Digite um comando.\n 1 - Cadastrar cliente\n 2 - Mostrar clientes cadastrados\n 3 - Salvar arquivo de clientes\n 4 - Encerrar\n\n");
		scanf("%d",&command);
		printf("\n\n");
		ClearScreen();
		switch (command) {
			case 1:
				cadastrarClientes();
				ClearScreen();
				printf("\nCliente cadastrado com sucesso! \n")	;
				printf("\nNome: %s",array[qntCliente-1].nome);
				printf("\nSobrenome: %s",array[qntCliente-1].sobrenome);
				printf("\nNome: %s",array[qntCliente-1].nome); 
				printf("\nSobrenome: %s",array[qntCliente-1].sobrenome);
				printf("\nCPF: %s",array[qntCliente-1].cpf);
				printf("\nData de nascimento: %s",array[qntCliente-1].dataNascimento);
				printf("\nTelefone: %s",array[qntCliente-1].telefone);
				printf("\nCelular: %s",array[qntCliente-1].celular);
				printf("\nEmail: %s",array[qntCliente-1].email);
				printf("\nEndereco: %s",array[qntCliente-1].endereco);
				printf("\nBairro: %s",array[qntCliente-1].bairro);
				printf("\nComplemento: %s",array[qntCliente-1].complemento);
				printf("\nCidade: %s",array[qntCliente-1].cidade);
				printf("\nEstado: %s",array[qntCliente-1].estado);
				printf("\nCEP: %s",array[qntCliente-1].cep);
				break;
			
			case 2:
				ClearScreen();
				mostrarClientes();
				break;
				
			case 3:
				salvarArquivo();
				break;
				
			case 4:
				return 0;
				break;
				
			default:
				printf("Comando Inválido");
				break;
		}
		printf("\n\n");
	}

	return 0;
}
