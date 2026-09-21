//Oscar Silva Urbina
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std; 

// función que resuelve el problema
string resolver(vector <int> &v) {
    bool creciente = true;
    bool decreciente = true; 

    for (int i = 1; i < v.size(); i++) {
        if (v[i - 1] <= v[i]) decreciente = false; 
        if (v[i - 1] >= v[i]) creciente = false; 
    }
    if (creciente || decreciente) return "DALTON";
    else return "DESCONOCIDOS";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nelems; 
    cin >> nelems; 
    if (nelems ==0) return false;
    
    vector <int> v(nelems);
    for (int i = 0; i < v.size(); i++) {
        int elem;
        cin >> elem; 
        v[i] = elem; 
    }
    string sol = resolver(v);
    cout << sol << endl; 
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
    system("PAUSE");
#endif

    return 0;
}