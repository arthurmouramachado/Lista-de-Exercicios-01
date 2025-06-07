#include "exercicios_poo_classes.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main() {
    // 1.1 Calculadora Simples
    Calculadora calc;
    cout << "\n--- Calculadora Simples ---" << endl;
    cout << "Soma: " << calc.somar(10, 5) << endl;
    cout << "Subtracao: " << calc.subtrair(10, 5) << endl;
    cout << "Multiplicacao: " << calc.multiplicar(10, 5) << endl;
    cout << "Divisao: " << calc.dividir(10, 5) << endl;

    // 1.2 Verificador de Palindromos
    VerificadorPalindromo verificador;
    string palavra = "Ana";
    cout << "\n--- Verificador de Palindromos ---" << endl;
    cout << palavra << (verificador.ehPalindromo(palavra) ? " eh " : " nao eh ") << "palindromo" << endl;

    // 1.3 Fatorial Recursivo
    Fatorial fat;
    int n = 5;
    cout << "\n--- Fatorial Recursivo ---" << endl;
    cout << "Fatorial de " << n << " = " << fat.calcular(n) << endl;

    // 1.4 Conversor de Temperaturas
    ConversorTemperatura conv;
    cout << "\n--- Conversor de Temperaturas ---" << endl;
    cout << "25 Celsius para Fahrenheit: " << conv.celsiusParaFahrenheit(25) << endl;
    cout << "77 Fahrenheit para Celsius: " << conv.fahrenheitParaCelsius(77) << endl;

    // 2.1 Maior e Menor em Matriz
    MatrizOperacoes opMatriz;
    vector<vector<int>> matriz = {{1, 2}, {9, 4}};
    auto [maior, menor] = opMatriz.encontrarMaiorEMenor(matriz);
    cout << "\n--- Maior e Menor em Matriz ---" << endl;
    cout << "Maior: " << maior << ", Menor: " << menor << endl;

    // 2.2 Soma das Diagonais
    MatrizDiagonal diag;
    vector<vector<int>> matrizQuad = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto [dp, ds] = diag.somarDiagonais(matrizQuad);
    cout << "\n--- Soma das Diagonais ---" << endl;
    cout << "Principal: " << dp << ", Secundaria: " << ds << endl;

    // 3.1 Manipulando Dados de um Objeto
    Numero num;
    num.valor = 42;
    cout << "\n--- Manipulando Objeto Numero ---" << endl;
    num.imprimirValor();

    // 3.2 Trocando Valores entre Objetos
    ValorContainer objA, objB;
    objA.valor = 10;
    objB.valor = 20;
    cout << "\n--- Antes da troca ---" << endl;
    cout << "A: " << objA.valor << ", B: " << objB.valor << endl;
    ValorContainer::trocarValores(objA, objB);
    cout << "Depois da troca - A: " << objA.valor << ", B: " << objB.valor << endl;

    // 4.1 Gerenciador de Funcionarios
    GerenciadorFuncionarios gestor;
    gestor.adicionarFuncionario({"Joao", 1, 3000.0, "TI"});
    gestor.adicionarFuncionario({"Maria", 2, 3200.0, "TI"});
    gestor.adicionarFuncionario({"Carlos", 3, 2500.0, "RH"});
    cout << "\n--- Lista de Funcionarios ---" << endl;
    gestor.listarFuncionarios();
    cout << "Total salarios TI: " << gestor.totalSalariosPorDepartamento("TI") << endl;

    // 4.2 Agenda de Contatos
    AgendaContatos agenda;
    agenda.adicionarContato({"Ana", "1111-1111", "ana@email.com"});
    agenda.adicionarContato({"Bruno", "2222-2222", "bruno@email.com"});
    cout << "\n--- Contatos ---" << endl;
    agenda.listarContatos();
    cout << "\nBuscar contato Ana:" << endl;
    agenda.buscarContatoPorNome("Ana");

    return 0;
}
