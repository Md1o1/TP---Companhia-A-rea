/*********************************************************************************
 * objetivo: Sistema para gerenciar a companhia aérea Vôo Tranquilo.
 * autores: Hugo Tavares Dutra - 859506, Kelvin Gustavo Fernandes Mendes - 845594.
 * versão: 1.0
 ********************************************************************************/

//Inclusão de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "modulos.h"

// declaração das funções
void cadastrarPassageiro();
void cadastrarTripulacao();
void cadastrarVoo();
void realizarReserva();
void cancelarReserva();
void listarPassageiros();
void listarVoos();
void buscarPassageiroPorCodigo();
void buscarTripulacaoPorCodigo();
void calcularPontosFidelidade();
void exibirMenu();

//programa principal
int main() {
    int opcao;
    do {
        exibirMenu();
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer
        switch (opcao) {
            case 1:
                cadastrarPassageiro();
                break;
            case 2:
                cadastrarTripulacao();
                break;
            case 3:
                cadastrarVoo();
                break;
            case 4:
                realizarReserva();
                break;
            case 5:
                cancelarReserva();
                break;
            case 6:
                listarPassageiros();
                break;
            case 7:
                listarVoos();
                break;
            case 8:
                buscarPassageiroPorCodigo();
                break;
            case 9:
                buscarTripulacaoPorCodigo();
                break;
            case 10:
                calcularPontosFidelidade();
                break;
            case 11:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 11);

    return 0;
}
