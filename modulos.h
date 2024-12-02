#ifndef MODULOS_H
#define MODULOS_H
// Define a macro MODULOS_H para evitar múltiplas inclusões deste arquivo.

// Funções e procedimentos para o programa main.c, do sistema de gerenciamento da companhia aérea Vôo Tranquilo.

// Estruturas de Dados
typedef struct {
    int codigo; // Código do passageiro.
    char nome[100]; // Nome do passageiro.
    char endereco[200]; // Endereço do passageiro.
    char telefone[15]; // Telefone do passageiro.
    int fidelidade; // Indica se o passageiro participa do programa de fidelidade (1 - Sim, 0 - Não).
    int pontosFidelidade; // Pontos de fidelidade do passageiro.
} Passageiro;

typedef struct {
    int codigo; // Código do membro da tripulação.
    char nome[100]; // Nome do membro da tripulação.
    char telefone[15]; // Telefone do membro da tripulação.
    char cargo[20]; // Cargo do membro da tripulação (Piloto, Copiloto, Comissário).
} Tripulacao;

typedef struct {
    int codigo; // Código do voo.
    char data[11]; // Data do voo no formato DD/MM/AAAA.
    char hora[6]; // Hora do voo no formato HH:MM.
    char origem[50]; // Origem do voo.
    char destino[50]; // Destino do voo.
    int codigoAviao; // Código do avião.
    int codigoPiloto; // Código do piloto.
    int codigoCopiloto; // Código do copiloto.
    int codigoComissario; // Código do comissário.
    int status; // Status do voo (1 - Ativo, 0 - Inativo).
    float tarifa; // Tarifa do voo.
} Voo;

typedef struct {
    int numeroAssento; // Número do assento.
    int codigoVoo; // Código do voo.
    int status; // Status do assento (1 - Ocupado, 0 - Livre).
} Assento;

typedef struct {
    int codigoVoo; // Código do voo.
    int numeroAssento; // Número do assento.
    int codigoPassageiro; // Código do passageiro.
} Reserva;

// Funções
void exibirMenu() {
    // Exibe o menu principal do sistema.
    printf("\n--- Sistema de Gerenciamento de Voos ---\n");
    printf("1. Cadastrar Passageiro\n");
    printf("2. Cadastrar Tripulacao\n");
    printf("3. Cadastrar Voo\n");
    printf("4. Realizar Reserva\n");
    printf("5. Cancelar Reserva\n");
    printf("6. Listar Passageiros\n");
    printf("7. Listar Voos\n");
    printf("8. Buscar Passageiro\n");
    printf("9. Buscar Tripulacao\n");
    printf("10. Consultar Pontos de Fidelidade\n");
    printf("11. Sair\n");
    printf("Escolha uma opcao: ");
}

void cadastrarPassageiro() {
    // Cadastra um novo passageiro.
    Passageiro p;
    FILE *arquivo = fopen("passageiros.dat", "ab"); // Abre o arquivo de passageiros para adicionar dados.
    if (!arquivo) {
        printf("Erro ao abrir o arquivo de passageiros.\n");
        return;
    }
    printf("Digite o codigo do passageiro: ");
    scanf("%d", &p.codigo);
    getchar(); // Limpa o buffer do teclado.
    printf("Digite o nome: ");
    fgets(p.nome, 100, stdin);
    strtok(p.nome, "\n"); // Remove o caractere de nova linha.
    printf("Digite o endereco: ");
    fgets(p.endereco, 200, stdin);
    strtok(p.endereco, "\n");
    printf("Digite o telefone: ");
    fgets(p.telefone, 15, stdin);
    strtok(p.telefone, "\n");
    printf("O passageiro participa do programa de fidelidade? (1-Sim, 0-Nao): ");
    scanf("%d", &p.fidelidade);
    p.pontosFidelidade = 0; // Inicializa pontos de fidelidade.

    fwrite(&p, sizeof(Passageiro), 1, arquivo); // Escreve os dados do passageiro no arquivo.
    fclose(arquivo); // Fecha o arquivo.

    printf("Passageiro cadastrado com sucesso!\n");
}

void cadastrarTripulacao() {
    // Cadastra um novo membro da tripulação.
    Tripulacao t;
    FILE *arquivo = fopen("tripulacao.dat", "ab"); // Abre o arquivo de tripulação para adicionar dados.
    if (!arquivo) {
        printf("Erro ao abrir o arquivo de tripulacao.\n");
        return;
    }
    printf("Digite o codigo do membro da tripulacao: ");
    scanf("%d", &t.codigo);
    getchar(); // Limpa o buffer do teclado.
    printf("Digite o nome: ");
    fgets(t.nome, 100, stdin);
    strtok(t.nome, "\n"); // Remove o caractere de nova linha.
    printf("Digite o telefone: ");
    fgets(t.telefone, 15, stdin);
    strtok(t.telefone, "\n");
    printf("Digite o cargo (Piloto, Copiloto, Comissario): ");
    fgets(t.cargo, 20, stdin);
    strtok(t.cargo, "\n");

    fwrite(&t, sizeof(Tripulacao), 1, arquivo); // Escreve os dados do membro da tripulação no arquivo.
    fclose(arquivo); // Fecha o arquivo.

    printf("Membro da tripulacao cadastrado com sucesso!\n");
}

void cadastrarVoo() {
    // Cadastra um novo voo.
    Voo v;
    FILE *arquivo = fopen("voos.dat", "ab"); // Abre o arquivo de voos para adicionar dados.
    FILE *arquivoAssentos = fopen("assentos.dat", "ab"); // Abre o arquivo de assentos para adicionar dados.
    if (!arquivo || !arquivoAssentos) {
        printf("Erro ao abrir os arquivos de voos ou assentos.\n");
        if (arquivo) fclose(arquivo);
        if (arquivoAssentos) fclose(arquivoAssentos);
        return;
    }
    // Cadastro dos dados do voo
    printf("Digite o codigo do voo: ");
    scanf("%d", &v.codigo);
    getchar(); // Limpa o buffer do teclado.

    printf("Digite a data (DD/MM/AAAA): ");
    fgets(v.data, 11, stdin);
    strtok(v.data, "\n"); // Remove o caractere de nova linha.

    printf("Digite a hora (HH:MM): ");
    fgets(v.hora, 6, stdin);
    strtok(v.hora, "\n");

    printf("Digite a origem: ");
    fgets(v.origem, 50, stdin);
    strtok(v.origem, "\n");

    printf("Digite o destino: ");
    fgets(v.destino, 50, stdin);
    strtok(v.destino, "\n");

    printf("Digite o codigo do aviao: ");
    scanf("%d", &v.codigoAviao);

    printf("Digite o codigo do piloto: ");
    scanf("%d", &v.codigoPiloto);

    printf("Digite o codigo do copiloto: ");
    scanf("%d", &v.codigoCopiloto);

    printf("Digite o codigo do comissario: ");
    scanf("%d", &v.codigoComissario);

    printf("Digite a tarifa: ");
    scanf("%f", &v.tarifa);
    v.status = 1; // Define o voo como ativo.

    // Salvando informações do voo
    fwrite(&v, sizeof(Voo), 1, arquivo); // Escreve os dados do voo no arquivo.

    // Cadastro e gravação dos assentos
    int numAssentos;
    printf("Digite o numero de assentos disponveis para este voo: ");
    scanf("%d", &numAssentos);

    for (int i = 1; i <= numAssentos; i++) {
        Assento a;
        a.codigoVoo = v.codigo;
        a.numeroAssento = i;
        a.status = 0; // Assento inicialmente livre
        fwrite(&a, sizeof(Assento), 1, arquivoAssentos); // Escreve os dados do assento no arquivo.
    }

    fclose(arquivo); // Fecha o arquivo de voos.
    fclose(arquivoAssentos); // Fecha o arquivo de assentos.

    printf("Voo cadastrado com sucesso!\n");
    printf("%d assentos registrados com sucesso para o voo %d.\n", numAssentos, v.codigo);
}

void realizarReserva() {
    // Realiza uma nova reserva.
    Reserva r;
    FILE *reservas = fopen("reservas.dat", "ab"); // Abre o arquivo de reservas para adicionar dados.
    FILE *assentos = fopen("assentos.dat", "rb+"); // Abre o arquivo de assentos para leitura e escrita.
    if (!reservas || !assentos) {
        printf("Erro ao abrir arquivos de reservas ou assentos.\n");
        return;
    }
    printf("Digite o codigo do voo: ");
    scanf("%d", &r.codigoVoo);
    printf("Digite o numero do assento: ");
    scanf("%d", &r.numeroAssento);
    printf("Digite o codigo do passageiro: ");
    scanf("%d", &r.codigoPassageiro);

    // Validar se o assento está livre
    Assento a;
    int encontrado = 0;
    while (fread(&a, sizeof(Assento), 1, assentos)) {
        if (a.codigoVoo == r.codigoVoo && a.numeroAssento == r.numeroAssento) {
            encontrado = 1;
            if (a.status == 0) { // Assento livre
                a.status = 1; // Ocupa o assento
                fseek(assentos, -sizeof(Assento), SEEK_CUR); // Move o ponteiro do arquivo para a posição correta.
                fwrite(&a, sizeof(Assento), 1, assentos); // Atualiza o status do assento no arquivo.
                fwrite(&r, sizeof(Reserva), 1, reservas); // Escreve os dados da reserva no arquivo.
                printf("Reserva realizada com sucesso!\n");
            } else {
                printf("Erro: Assento ja ocupado.\n");
            }
            break;
        }
    }

    if (!encontrado) {
        printf("Erro: Assento nao encontrado.\n");
    }

    fclose(reservas); // Fecha o arquivo de reservas.
    fclose(assentos); // Fecha o arquivo de assentos.
}

void cancelarReserva() {
    // Cancela uma reserva existente.
    int codigoVoo, numeroAssento;
    FILE *reservas = fopen("reservas.dat", "rb"); // Abre o arquivo de reservas para leitura.
    FILE *assentos = fopen("assentos.dat", "rb+"); // Abre o arquivo de assentos para leitura e escrita.
    FILE *temp = fopen("temp.dat", "wb"); // Abre um arquivo temporário para escrita.

    if (!reservas || !assentos || !temp) {
        printf("Erro ao abrir arquivos necessarios.\n");
        return;
    }

    printf("Digite o codigo do voo: ");
    scanf("%d", &codigoVoo);
    printf("Digite o numero do assento: ");
    scanf("%d", &numeroAssento);

    Reserva r;
    int encontrado = 0;

    while (fread(&r, sizeof(Reserva), 1, reservas)) {
        if (r.codigoVoo == codigoVoo && r.numeroAssento == numeroAssento) {
            encontrado = 1;
        } else {
            fwrite(&r, sizeof(Reserva), 1, temp); // Escreve os dados da reserva no arquivo temporário.
        }
    }

    fclose(reservas); // Fecha o arquivo de reservas.
    fclose(temp); // Fecha o arquivo temporário.

    if (!encontrado) {
        printf("Reserva nao encontrada.\n");
        remove("temp.dat"); // Remove o arquivo temporário.
        return;
    }

    remove("reservas.dat"); // Remove o arquivo de reservas original.
    rename("temp.dat", "reservas.dat"); // Renomeia o arquivo temporário para o nome do arquivo de reservas.

    Assento a;
    while (fread(&a, sizeof(Assento), 1, assentos)) {
        if (a.codigoVoo == codigoVoo && a.numeroAssento == numeroAssento) {
            a.status = 0; // Livre
            fseek(assentos, -sizeof(Assento), SEEK_CUR); // Move o ponteiro do arquivo para a posição correta.
            fwrite(&a, sizeof(Assento), 1, assentos); // Atualiza o status do assento no arquivo.
            printf("Reserva cancelada e assento liberado com sucesso.\n");
            break;
        }
    }

    fclose(assentos); // Fecha o arquivo de assentos.
}

void listarPassageiros() {
    // Lista todos os passageiros cadastrados.
    FILE *arquivo = fopen("passageiros.dat", "rb"); // Abre o arquivo de passageiros para leitura.
    if (!arquivo) {
        printf("Erro ao abrir o arquivo de passageiros.\n");
        return;
    }

    Passageiro p;
    printf("\n--- Lista de Passageiros ---\n");
    while (fread(&p, sizeof(Passageiro), 1, arquivo)) {
        printf("Código: %d | Nome: %s | Endereço: %s | Telefone: %s | Fidelidade: %s | Pontos: %d\n",
               p.codigo, p.nome, p.endereco, p.telefone, (p.fidelidade ? "Sim" : "Não"), p.pontosFidelidade);
    }

    fclose(arquivo); // Fecha o arquivo de passageiros.
}

void listarVoos() {
    // Lista todos os voos cadastrados.
    FILE *arquivo = fopen("voos.dat", "rb"); // Abre o arquivo de voos para leitura.
    if (!arquivo) {
        printf("Erro ao abrir o arquivo de voos.\n");
        return;
    }

    Voo v;
    printf("\n--- Lista de Voos ---\n");
    while (fread(&v, sizeof(Voo), 1, arquivo)) {
        printf("Código: %d | Data: %s | Hora: %s | Origem: %s | Destino: %s | Status: %s | Tarifa: %.2f\n",
               v.codigo, v.data, v.hora, v.origem, v.destino, (v.status == 1) ? "Ativo" : "Inativo", v.tarifa);
    }

    fclose(arquivo); // Fecha o arquivo de voos.
}

void buscarPassageiroPorCodigo() {
    // Busca um passageiro pelo código.
    int codigo;
    printf("Digite o codigo do passageiro: ");
    scanf("%d", &codigo);

    FILE *arquivo = fopen("passageiros.dat", "rb"); // Abre o arquivo de passageiros para leitura.
    if (!arquivo) {
        printf("Erro ao abrir o arquivo de passageiros.\n");
        return;
    }

    Passageiro p;
    int encontrado = 0;

    while (fread(&p, sizeof(Passageiro), 1, arquivo)) {
        if (p.codigo == codigo) {
            printf("\n--- Passageiro Encontrado ---\n");
            printf("Código: %d\nNome: %s\nEndereço: %s\nTelefone: %s\nFidelidade: %s\nPontos: %d\n",
                   p.codigo, p.nome, p.endereco, p.telefone, (p.fidelidade ? "Sim" : "Nao"), p.pontosFidelidade);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Passageiro com código %d nao encontrado.\n", codigo);
    }

    fclose(arquivo); // Fecha o arquivo de passageiros.
}

void buscarTripulacaoPorCodigo() {
    // Busca um membro da tripulação pelo código.
    int codigo;
    printf("Digite o codigo do membro da tripulacao: ");
    scanf("%d", &codigo);

    FILE *arquivo = fopen("tripulacao.dat", "rb"); // Abre o arquivo de tripulação para leitura.
    if (!arquivo) {
        printf("Erro ao abrir o arquivo de tripulacao.\n");
        return;
    }

    Tripulacao t;
    int encontrado = 0;

    while (fread(&t, sizeof(Tripulacao), 1, arquivo)) {
        if (t.codigo == codigo) {
            printf("\n--- Membro da Tripulacao Encontrado ---\n");
            printf("Código: %d\nNome: %s\nTelefone: %s\nCargo: %s\n",
                   t.codigo, t.nome, t.telefone,
                   (t.cargo == 0 ? "Piloto" : (t.cargo == 1 ? "Copiloto" : "Comissario")));
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Membro da tripulacao com codigo %d nao encontrado.\n", codigo);
    }

    fclose(arquivo); // Fecha o arquivo de tripulação.
}

void calcularPontosFidelidade() {
    // Calcula os pontos de fidelidade de um passageiro.
    int codigoPassageiro;
    printf("Digite o codigo do passageiro: ");
    scanf("%d", &codigoPassageiro);

    FILE *arquivo = fopen("passageiros.dat", "rb"); // Abre o arquivo de passageiros para leitura.
    if (!arquivo) {
        printf("Erro ao abrir o arquivo de passageiros.\n");
        return;
    }

    Passageiro p;
    int encontrado = 0;

    while (fread(&p, sizeof(Passageiro), 1, arquivo)) {
        if (p.codigo == codigoPassageiro) {
            printf("Passageiro: %s\n", p.nome);
            printf("Pontos de fidelidade: %d\n", p.pontosFidelidade);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Passageiro não encontrado.\n");
    }

    fclose(arquivo); // Fecha o arquivo de passageiros.
}

#endif
// Fim da definição do arquivo de cabeçalho.