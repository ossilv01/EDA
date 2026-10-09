//Oscar Silva Urbina
//Coste: 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int minimo(const vector<int>& sec, int ini, int fin) {
    int n = fin - ini; 
    //caso solo 1 elemento + recursion
    if (n == 1) return sec[ini];
    int mitad = (ini + fin) / 2;

    //caso de que el de la mitad justamente sea el elemento mas pequeño
    if (sec[mitad] < sec[mitad +1] && sec[mitad] < sec[mitad -1]) return sec[mitad];

    //CUIDADO LLAMA AL METODO
    if (sec[mitad] > sec[fin-1]) {
         return (sec, ini, mitad);
    }
    else return minimo(sec, mitad, fin);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    vector<int> sec(n);
    for (int& e : sec) cin >> e;
    //for (int& b : sec) cout << b << " ";
    //cout << endl;
    cout << minimo(sec, 0, n) << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}