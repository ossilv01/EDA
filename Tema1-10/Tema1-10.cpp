// Oscar Silva Urbina 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std; 

// función que resuelve el problema
int resolver(vector<string> &v) {

    return 0; 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int nelems; 
    cin >> nelems; 
    vector<string> v(nelems); 
    for (int i = 0; i < v.size(); i++) {
        cin >> v[i];
    }
    for (string a : v) cout << a << " ";
    cout << "\n";

    //TipoSolucion sol = resolver(datos);
    // escribir sol
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