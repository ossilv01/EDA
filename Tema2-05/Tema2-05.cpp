//Oscar Silva Urbina
//caso centinela cuando n = 0; 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


bool RECcaucasico(vector<int>& v, int ini, int fin, int& resultado) {
    ini = v[0];
    fin = v[v.size() - 1];
    cout << ini << " " << fin << " ";
    return false; 
}

bool caucasico(vector<int>& v) {
    int resultado;
    return RECcaucasico(v, 0, v.size(), resultado);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0) return false;
    vector<int> sec(n);
    for (int& e : sec) cin >> e;

    //imprimir datos
    for (int a : sec) cout << a << " ";
    cout << endl;

    //resultado
    cout << (caucasico(sec) ? "SI" : "NO") << endl;
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
    //system("PAUSE");
#endif

    return 0;
}