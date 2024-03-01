#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/*
 * Trabalho de Estrutura de Dados, Fatec Ourinhos, 3º Semestre ADS.
 * Autor: Dante Tokomoto.
 * Professora: Carolinne Roque e Faria.
 * Data de criação: 27/02/2024.
 * Data última atualização: 27/02/2024.
 */
 
void limparBuffer() {
    char temp[100];
    fgets(temp, sizeof(temp), stdin);
}

void loadingAnimation() {
    int i;
    for (i =  80; i <=  100; i++) {
        printf("\rProcessando Doação %d%%...", i);
        fflush(stdout); 
        usleep(200000); 
    }
    printf("\n100%%\n");
}
void loadingAnimation2() {
    int i;
    for (i =  80; i <=  100; i++) {
        printf("\n\n\rProcessando Informação %d%%...", i);
        fflush(stdout); 
        usleep(100000); 
    }
    printf("\n100%%\n");
}

typedef enum FormaPagamento {
  DINHEIRO,
  CARTAO_CREDITO,
  CARTAO_DEBITO,
  PIX
} FormaPagamento;

typedef struct Cliente {
  char nome[50];
  char cpf[14];
  char telefone[15];
  char email[50];
  int poltrona;
  FormaPagamento formaPagamento;
} Cliente;

typedef struct Passagem {
  int poltrona;
  char origem[50];
  char destino[50];
  char data[11];
  float valor;
} Passagem;

Cliente clientesQueCompraram[100];
int numClientesQueCompraram =  0; 

void adicionarClienteQueComprou(Cliente cliente) {
    clientesQueCompraram[numClientesQueCompraram] = cliente;
    numClientesQueCompraram++;
}

int validarCPF(char *cpf) {
  return  1;
}

int validarData(char *data) {
  return  1;
}

int apenasLetras(char *str) {
  for (int i =  0; str[i] != '\0'; i++) {
    if (!isalpha(str[i])) {
      return  0;
    }
  }
  return  1;
}

int apenasNumeros(char *str) {
  for (int i =  0; str[i] != '\0'; i++) {
    if (!isdigit(str[i])) {
      return  0;
    }
  }
  return  1;
}

int telefoneValido(char *str) {
  int temSinal =  0;
  for (int i =  0; str[i] != '\0'; i++) {
    if (!isdigit(str[i]) && str[i] != '+') {
      return  0;
    }
    if (str[i] == '+') {
      temSinal =  1;
    }
  }
  return temSinal;
}

int poltronaValida(int num) {
  return num >=  1 && num <=  54;
}

void obterDadosPassagem(Passagem *passagem) {
  int origem, destino;

  do {
    printf("\n\n\nEscolha a Origem, Digite 1, 2 ,3 ,4 ou 5:\n");
    printf("1 - Santa Cruz do Rio Pardo\n");
    printf("2 - Ourinhos\n");
    printf("3 - Bauru\n");
    printf("4 - Campinas\n");
    printf("5 - São Paulo\n");
    scanf("%d", &origem);
    limparBuffer();
    switch (origem) {
      case  1:
        strcpy(passagem->origem, "Santa Cruz do Rio Pardo");
        break;
      case  2:
        strcpy(passagem->origem, "Ourinhos");
        break;
      case  3:
        strcpy(passagem->origem, "Bauru");
        break;
      case  4:
        strcpy(passagem->origem, "Campinas");
        break;
      case  5:
        strcpy(passagem->origem, "São Paulo");
        break;
      default:
        printf("Opção Inválida.\n");
        continue;
    }

    do {
      printf("\n\n\nEscolha o Destino, Digite 1, 2 ,3 ,4 ou 5:\n");
      printf("1 - Santa Cruz do Rio Pardo\n");
      printf("2 - Ourinhos\n");
      printf("3 - Bauru\n");
      printf("4 - Campinas\n");
      printf("5 - São Paulo\n");
      scanf("%d", &destino);
      switch (destino) {
        case  1:
          strcpy(passagem->destino, "Santa Cruz do Rio Pardo");
          break;
        case  2:
          strcpy(passagem->destino, "Ourinhos");
          break;
        case  3:
          strcpy(passagem->destino, "Bauru");
          break;
        case  4:
          strcpy(passagem->destino, "Campinas");
          break;
        case  5:
          strcpy(passagem->destino, "São Paulo");
          break;
        default:
          printf("Opção Inválida.\n");
          continue;
      }

      if (strcmp(passagem->origem, passagem->destino) ==  0) {
        loadingAnimation2();
        printf("Origem e Destino Não Podem Ser Iguais. Por Favor, Escolha Novamente.\n");
        continue;
      }
    } while (strcmp(passagem->origem, passagem->destino) ==  0);
  } while (strcmp(passagem->origem, passagem->destino) ==  0);

  printf("\n\n\nDigite a data (DD/MM/AAAA): ");
  scanf(" %10s%*c", passagem->data);

  printf("\n\nEscolha o Valor Da Passagem Que Gostaria De Doar:\n");
  printf("1 - R$  50,00\n");
  printf("2 - R$  75,00\n");
  printf("3 - R$  150,00\n");
  printf("4 - R$  200,00\n");
  int valor;
  scanf("%d", &valor);
  switch (valor) {
    case  1:
      passagem->valor =  50.00;
      break;
    case  2:
      passagem->valor =  75.00;
      break;
    case  3:
      passagem->valor =  150.00;
      break;
    case  4:
      passagem->valor =  200.00;
      break;
    default:
      loadingAnimation2();
      printf("Opção Inválida.\n");
      return;
  }
}

void processarCompra(Cliente *cliente, Passagem *passagem, FormaPagamento formaPagamento) {
    loadingAnimation();
    printf("\n\nDoação processada com sucesso!\n");
    printf("Doador: %s\n", cliente->nome);
    printf("CPF: %s\n", cliente->cpf);
    printf("Telefone: %s\n", cliente->telefone);
    printf("Email: %s\n", cliente->email);
    printf("Origem: %s\n", passagem->origem);
    printf("Destino: %s\n", passagem->destino);
    printf("Data: %s\n", passagem->data);
    printf("Poltrona: %d\n", cliente->poltrona);
    printf("Valor: R$ %.2f\n", passagem->valor);
    printf("Forma de Doação: ");
    switch (formaPagamento) {
        case DINHEIRO:
            printf("Dinheiro\n");
            break;
        case CARTAO_CREDITO:
            printf("Cartão de Crédito\n");
            break;
        case CARTAO_DEBITO:
            printf("Cartão de Débito\n");
            break;
        case PIX:
            printf("PIX\n");
            break;
    }
     adicionarClienteQueComprou(*cliente);
}

void exibirMenuInicial() {
  printf("\n\n ______________________________________________________________");
  printf("\n|\t                                                      |");
  printf("\n| Aplicativo Ônibus Único Voluntário, Doe Quantos R$ Puder.   |");
  printf("\n|          E Adquira Uma Poltrona Para Viajar!!!              |\n|");
  printf("_____________________________________________________________|");
  printf("\n\nDigite 1, 2, 3 ou 4 Para Escolher Uma Das Opções:\n");
  printf("1 - Escolher Origem e Destino\n");
  printf("2 - Ver Poltronas Livres Para Doação\n");
  printf("3 - Ver Histórico De Quem Já Doou\n");
  printf("4 - Sair\n");
  printf("\n\nEscolha Uma Opção: \n");
}

void verPoltronas(int poltronas[]) {
    printf("\n\n");
    printf("\t        1º Andar        \n");
    printf("\t   ______________________ \n");
    printf("\t   |[Motorista]         | \n");
    printf("\t   |____________________| \n");
    printf("\t   |                \n");
    printf("\t 0||[%s][%s]            ||0\n", (poltronas[1] ==  1) ? "XX" : "01", (poltronas[2] ==  1) ? "XX" : "02");
    printf("\t   |==---==             | \n");
    printf("\t   |                    | \n");
    printf("\t   |[%s][%s]    [%s][%s]|\n", (poltronas[3] ==  1) ? "XX" : "03", (poltronas[4] ==  1) ? "XX" : "04", (poltronas[5] ==  1) ? "XX" : "05", (poltronas[6] ==  1) ? "XX" : "06");
    printf("\t   |==---==      ==---==| \n");
    printf("\t   |                    | \n");
    printf("\t   |[Escada]    [%s][%s]|\n", (poltronas[7] ==  1) ? "XX" : "07", (poltronas[8] ==  1) ? "XX" : "08");
    printf("\t   |  |=|        ==---==| \n");
    printf("\t   |                    | \n");
    printf("\t   |_________---________|\n");
    printf("\t   |        |[Banheiro] |\n");
    printf("\t   |[Motor] |           |\n");
    printf("\t   |        |           |\n");
    printf("\t   |        |           |\n");
    printf("\t   |        |           |\n");
    printf("\t   |        |           |\n");
    printf("\t   |        |___________|\n");
    printf("\t   |        |           |\n");
    printf("\t   |        |           |\n");
    printf("\t   |        |           |\n");
    printf("\t   |        |           |\n");
    printf("\t 0||        |           ||0\n");
    printf("\t 0||        |[Bagagens] ||0\n");
    printf("\t   |____________________|\n");
    printf("\n\n");
    printf("\t          2º Andar        \n");
    printf("\t   ______________________ \n");
    printf("\t   |[%s][%s]    [%s][%s]| \n", (poltronas[9] ==   1) ? "XX" : "09", (poltronas[10] ==   1) ? "XX" : "10", (poltronas[11] ==   1) ? "XX" : "11", (poltronas[12] ==   1) ? "XX" : "12");
    printf("\t   |==---==      ==---==| \n");
    printf("\t   |                    | \n");
    printf("\t 0||[%s][%s]    [%s][%s]||0 \n", (poltronas[13] ==   1) ? "XX" : "13", (poltronas[14] ==   1) ? "XX" : "14", (poltronas[15] ==   1) ? "XX" : "15", (poltronas[16] ==   1) ? "XX" : "16");
    printf("\t   |==---==      ==---==| \n");
    printf("\t   |                    | \n");
    printf("\t   |[%s][%s]    [%s][%s]| \n", (poltronas[17] ==   1) ? "XX" : "17", (poltronas[18] ==   1) ? "XX" : "18", (poltronas[19] ==   1) ? "XX" : "19", (poltronas[20] ==   1) ? "XX" : "20");
    printf("\t   |==---==      ==---==| \n");
    printf("\t   |                    | \n");
    printf("\t   |[%s][%s]    [%s][%s]| \n", (poltronas[21] ==   1) ? "XX" : "21", (poltronas[22] ==   1) ? "XX" : "22", (poltronas[23] ==   1) ? "XX" : "23", (poltronas[24] ==   1) ? "XX" : "24");
    printf("\t   |==---==      ==---==| \n");
    printf("\t   |                    | \n");
    printf("\t   |[%s][%s]    [%s][%s]| \n", (poltronas[25] ==   1) ? "XX" : "25", (poltronas[26] ==   1) ? "XX" : "26", (poltronas[27] ==   1) ? "XX" : "27", (poltronas[28] ==   1) ? "XX" : "28");
    printf("\t   |==---==      ==---==| \n");
    printf("\t   |                    | \n");
    printf("\t   |[%s][%s]    [%s][%s]| \n", (poltronas[29] ==   1) ? "XX" : "29", (poltronas[30] ==   1) ? "XX" : "30", (poltronas[31] ==   1) ? "XX" : "31", (poltronas[32] ==   1) ? "XX" : "32");
    printf("\t   |==---==      ==---==| \n");
    printf("\t   |                    | \n");
    printf("\t   |[%s][%s]    [%s][%s]| \n", (poltronas[33] ==   1) ? "XX" : "33", (poltronas[34] ==   1) ? "XX" : "34", (poltronas[35] ==   1) ? "XX" : "35", (poltronas[36] ==   1) ? "XX" : "36");
    printf("\t   |==---==      ==---==| \n");
    printf("\t   |                    | \n");
    printf("\t   |[%s][%s]    [%s][%s]| \n", (poltronas[37] ==   1) ? "XX" : "37", (poltronas[38] ==   1) ? "XX" : "38", (poltronas[39] ==   1) ? "XX" : "39", (poltronas[40] ==   1) ? "XX" : "40");
    printf("\t   |==---==      ==---==| \n");
    printf("\t   |                    | \n");
    printf("\t   |[%s][%s]    [%s][%s]| \n", (poltronas[41] ==   1) ? "XX" : "41", (poltronas[42] ==   1) ? "XX" : "42", (poltronas[43] ==   1) ? "XX" : "43", (poltronas[44] ==   1) ? "XX" : "44");
    printf("\t   |==---==      ==---==| \n");
    printf("\t   |                    | \n");
    printf("\t   |[%s][%s]    [%s][%s]| \n", (poltronas[45] ==   1) ? "XX" : "45", (poltronas[46] ==   1) ? "XX" : "46", (poltronas[47] ==   1) ? "XX" : "47", (poltronas[48] ==   1) ? "XX" : "48");
    printf("\t   |==---==      ==---==| \n");
    printf("\t   |                    | \n");
    printf("\t   |[%s][%s]    [%s][%s]| \n", (poltronas[49] ==   1) ? "XX" : "49", (poltronas[50] ==   1) ? "XX" : "50", (poltronas[51] ==   1) ? "XX" : "51", (poltronas[52] ==   1) ? "XX" : "52");
    printf("\t   |==---==      ==---==| \n");
    printf("\t   |                    | \n");
    printf("\t   |[%s][%s] ___________|\n", (poltronas[53] ==   1) ? "XX" : "53", (poltronas[54] ==   1) ? "XX" : "54");
    printf("\t   |==---== |           |\n");
    printf("\t 0||        |           ||0\n");
    printf("\t 0||        |[Banheiro] ||0\n");
    printf("\t   |____________________|\n");
}

FormaPagamento obterDadosCliente(Cliente *cliente, int poltronas[]) {
  char temp[50];
  int pagamento;
  FormaPagamento formaPagamento;

  do {
      printf("Digite Seu Nome: ");
      fgets(temp, sizeof(temp), stdin);
      temp[strcspn(temp, "\n")] = '\0';
      if (!apenasLetras(temp)) {
          loadingAnimation2();
          printf("\n\n\nNome Inválido. Apenas Letras São Permitidas.\n");
          printf("Pressione [Enter] Para Informar Novamente.\n");
          limparBuffer();
          continue;
      }
      strcpy(cliente->nome, temp);
      break;
  } while (1);

  do {
      printf("Digite seu CPF: ");
      fgets(temp, sizeof(temp), stdin);
      temp[strcspn(temp, "\n")] = '\0';
      if (!apenasNumeros(temp)) {
          loadingAnimation2();
          printf("\n\n\nCPF Inválido. Apenas Números São Permitidos.\n");
          printf("Pressione [Enter] Para Informar Novamente.\n");
          limparBuffer();
          continue;
      }
      strcpy(cliente->cpf, temp);
      break;
  } while (1);

  do {
      printf("Digite Seu Telefone: ");
      fgets(temp, sizeof(temp), stdin);
      temp[strcspn(temp, "\n")] = '\0';
      if (!telefoneValido(temp)) {
          loadingAnimation2();
          printf("\n\n\nTelefone Inválido. Formato Esperado: +XX XX XXXXXXXXX ou XXXXXXXXXX.\n");
          printf("Pressione [Enter] Para Informar Novamente.\n");
          limparBuffer();
          continue;
      }
      strcpy(cliente->telefone, temp);
      break;
  } while (1);

  do {
    printf("Digite Seu E-mail: ");
    fgets(cliente->email, sizeof(cliente->email), stdin);
    cliente->email[strcspn(cliente->email, "\n")] = '\0';
    break;
  } while (1);

  Passagem passagem;
  

  do {
    verPoltronas(poltronas);
    printf("\n\n\nEscolha o Número Da Poltrona Disponivel Conforme Imagem Acima: ");
    scanf("%d", &cliente->poltrona);
    limparBuffer();
    if (!poltronaValida(cliente->poltrona) || poltronas[cliente->poltrona] ==   1) {
      loadingAnimation2();
      printf("Poltrona Inválida ou Já Reservada. O Número da Poltrona Deve Estar Entre 1 e 54 e Não Pode Estar Reservada com [XX].\n");
      continue;
    }
    poltronas[cliente->poltrona] =   1;
    break;
  } while (1);

  do {
    printf("\n\n\nEscolha a Forma De Doação:\n");
    printf("1 - Dinheiro\n");
    printf("2 - Cartão de Crédito\n");
    printf("3 - Cartão de Débito\n");
    printf("4 - PIX\n");
    scanf("%d", &pagamento);
    limparBuffer();
    switch (pagamento) {
      case   1:
        formaPagamento = DINHEIRO;
        break;
      case   2:
        formaPagamento = CARTAO_CREDITO;
        break;
      case   3:
        formaPagamento = CARTAO_DEBITO;
        break;
      case   4:
                formaPagamento = PIX;
        break;
      default:
        loadingAnimation2();
        printf("Opção de Doação Inválida. Escolha Uma Opção Válida.\n");
        continue;
    }
    break;
  } while (1);

  return formaPagamento;
}

void verClientesQueCompraram() {
    printf("\nClientes Que já Doaram:\n");
    for (int i =  0; i < numClientesQueCompraram; i++) {
        loadingAnimation2();
        printf("\n\n\nCliente %d - Passagem Para Poltrona %d\n", i +  1, clientesQueCompraram[i].poltrona);
    }
}

int main() {
  Cliente cliente;
  Passagem passagem;
  FormaPagamento formaPagamento;
  int opcao;
  int poltronas[55];

  for (int i =   1; i <=   54; i++) {
    poltronas[i] = i;
  }
  do {
      exibirMenuInicial();
      scanf("%d", &opcao);
      limparBuffer();
      switch (opcao) {
        case   1:
          formaPagamento = obterDadosCliente(&cliente, poltronas);
          obterDadosPassagem(&passagem);
          if (cliente.poltrona >=   1 && cliente.poltrona <=   54) {
              poltronas[cliente.poltrona] =   1;
          } else {
              loadingAnimation2();
              printf("Poltrona Inválida. O Número da Poltrona Deve Estar Entre 1 e 54.\n");
              continue;
          }
          if (validarCPF(cliente.cpf) && validarData(passagem.data)) {
            processarCompra(&cliente, &passagem, formaPagamento);
          } else {
            loadingAnimation2();
            printf("Erro na Validação Dos Dados.\n");
          }
          break;
        case   2:
          verPoltronas(poltronas);
          break;
        case   3:
          verClientesQueCompraram();
          break;
        case   4:
          loadingAnimation2();
          printf("\nSaindo...\n");
          break;
        default:
          loadingAnimation2();
          printf("Opção Inválida. Tente Novamente.\n");
      }
  } while (opcao !=   4);

  return   0;
}


