// Oscar Silva Urbina
//Coste: 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std; 

// función que resuelve el problema
int ultimo(vector <int> &sec, int ini, int fin) {
    int mitad = (ini + fin) / 2;
    int n = fin - ini;
    //Caso base 1 elemento en vector
    if (n == 1) return sec[ini];
    int pivote = sec[ini];

    int der = ultimo(sec, ini, mitad);
    int izq = ultimo(sec, mitad, fin);

    return 0; 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n; 
    cin >> n; 
    vector <int> sec(n);
    for (int& a : sec)  cin >> a;
    for (int b : sec) cout << b << " ";
    cout << endl; 
    cout << ultimo(sec, 0, n) << endl; 
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