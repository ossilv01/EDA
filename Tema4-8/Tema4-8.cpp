//Oscar Silva Urbina
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Set.h"
using namespace std;
//Coste: O(n * log(m), donde n es el numero de elemenetos de set1 y m el de set2
//Se trata de un O(n) por que recorremos todos los elementos del primer set
//Y luego al llamar al contains, se utiliza una busqueda binaria, derivando en un coste de O(log(m))


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, e;
    Set<int> set1, set2;

    cin >> n;
    if (!cin) return false;

    for (int i = 0; i < n; i++) {
        cin >> e; set1.add(e);
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> e; set2.add(e);
    }

    cout << (set1 - set2) << endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso())
        ;

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}