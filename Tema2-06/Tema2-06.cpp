//Oscar Silva Urbina
//Coste: O(nlogn) 


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
bool resolver(const vector<int>& v, int ini, int fin) {
    int n = fin - ini; 
    int mitad = ini + (fin - ini) / 2;
    //Caso vacio
    if (n == 0) return false; 
    //Caso 1 solo elemento, verifica si es 0
    if (ini == fin - 1 && v[ini] == 0)
        return true;
    //Resto casos: 
    if (v[fin - 1] != fin - 1) {
        fin--;
        return resolver(v, ini, fin);
    }
    else return true; 

    return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    vector<int> sec(n);
    for (int& e : sec) cin >> e;
    for (int a : sec) cout << a << " ";
    cout << endl; 
    cout << (resolver(sec, 0, n) ? "SI" : "NO") << endl;
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
    //system("PAUSE");
#endif

    return 0;
}
