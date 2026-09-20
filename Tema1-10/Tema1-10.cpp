// Oscar Silva Urbina 
////Coste O(n^2) Pues tenemos 2 for anidades que recorren de manera lineal
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std; 

// función que resuelve el problema
int resolver(vector<string> &v) {

    //Caso especial, vacio
    if (v.size() <= 0) return 0;

    int size = 0; 
    for (int i = 0; i < v.size(); i++) {
        bool repetido = false; 
        for (int j = 0; j < size; j++) {
            if (v[j] == v[i]) {
                repetido = true;
            }
        }
        if (!repetido) {
            v[size] = v[i];
            size++;
        }
    }       
    v.resize(size);

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

    resolver(v);
    for (string a : v) cout << a << " ";    
    cout << "\n";

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