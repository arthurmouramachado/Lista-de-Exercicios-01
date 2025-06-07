#ifndef EXERCICIOS_POO_CLASSES_H
#define EXERCICIOS_POO_CLASSES_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// 1.1 Calculadora Simples
class Calculadora {
public:
    double somar(double a, double b) { return a + b; }
    double subtrair(double a, double b) { return a - b; }
    double multiplicar(double a, double b) { return a * b; }
    double dividir(double a, double b) { return b != 0 ? a / b : 0; }
};

// 1.2 Verificador de Palíndromos
class VerificadorPalindromo {
public:
    bool ehPalindromo(string texto) {
        string limpo;
        for (char c : texto) {
            if (!isspace(c)) limpo += tolower(c);
        }
        string reverso = limpo;
        reverse(reverso.begin(), reverso.end());
        return limpo == reverso;
    }
};

// 1.3 Fatorial Recursivo
class Fatorial {
public:
    int calcular(int n) {
        if (n <= 1) return 1;
        return n * calcular(n - 1);
    }
};

// 1.4 Conversor de Temperaturas
class ConversorTemperatura {
public:
    double celsiusParaFahrenheit(double c) {
        return (c * 9.0 / 5.0) + 32;
    }
    double fahrenheitParaCelsius(double f) {
        return (f - 32) * 5.0 / 9.0;
    }
};

// 2.1 Maior e Menor Elemento em uma Matriz
class MatrizOperacoes {
public:
    pair<int, int> encontrarMaiorEMenor(const vector<vector<int>>& matriz) {
        int maior = matriz[0][0], menor = matriz[0][0];
        for (const auto& linha : matriz) {
            for (int valor : linha) {
                if (valor > maior) maior = valor;
                if (valor < menor) menor = valor;
            }
        }
        return {maior, menor};
    }
};

// 2.2 Soma das Diagonais de uma Matriz Quadrada
class MatrizDiagonal {
public:
    pair<int, int> somarDiagonais(const vector<vector<int>>& matriz) {
        int n = matriz.size(), somaPrincipal = 0, somaSecundaria = 0;
        for (int i = 0; i < n; i++) {
            somaPrincipal += matriz[i][i];
            somaSecundaria += matriz[i][n - 1 - i];
        }
        return {somaPrincipal, somaSecundaria};
    }
};

// 3.1 Manipulando Dados de um Objeto
class Numero {
public:
    int valor;
    void imprimirValor() {
        cout << "Valor: " << valor << endl;
        cout << "Endereco (hash): " << identityHashCode() << endl;
    }
    size_t identityHashCode() {
        return reinterpret_cast<size_t>(this);
    }
};

// 3.2 Trocando Valores entre Objetos
class ValorContainer {
public:
    int valor;
    static void trocarValores(ValorContainer& a, ValorContainer& b) {
        int temp = a.valor;
        a.valor = b.valor;
        b.valor = temp;
    }
};

// 4.1 Sistema de Gerenciamento de Funcionários
class Funcionario {
public:
    string nome;
    int id;
    double salario;
    string departamento;
};

class GerenciadorFuncionarios {
public:
    vector<Funcionario> funcionarios;

    void adicionarFuncionario(const Funcionario& f) {
        funcionarios.push_back(f);
    }

    double totalSalariosPorDepartamento(const string& depto) {
        double total = 0;
        for (const auto& f : funcionarios) {
            if (f.departamento == depto) {
                total += f.salario;
            }
        }
        return total;
    }

    void listarFuncionarios() {
        for (const auto& f : funcionarios) {
            cout << "Nome: " << f.nome << ", ID: " << f.id << ", Salario: " << f.salario << ", Departamento: " << f.departamento << endl;
        }
    }
};

// 4.2 Agenda de Contatos
class Contato {
public:
    string nome;
    string telefone;
    string email;
};

class AgendaContatos {
public:
    vector<Contato> contatos;

    void adicionarContato(const Contato& c) {
        if (contatos.size() < 10)
            contatos.push_back(c);
    }

    void listarContatos() {
        for (const auto& c : contatos) {
            cout << "Nome: " << c.nome << ", Telefone: " << c.telefone << ", Email: " << c.email << endl;
        }
    }

    void buscarContatoPorNome(const string& nomeBusca) {
        for (const auto& c : contatos) {
            if (c.nome == nomeBusca) {
                cout << "Telefone: " << c.telefone << ", Email: " << c.email << endl;
                return;
            }
        }
        cout << "Contato nao encontrado." << endl;
    }
};

#endif // EXERCICIOS_POO_CLASSES_H
