// Oscar Silva Urbina
//numerosos casos

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
TipoSolucion resolver(TipoDatos datos) {


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tamvec;
    cin >> tamvec;
    vector <int> vector(tamvec);
    //posición (pivote)
    int p;
    cin >> p; 
    //creamos vector de elementos con cada uno en dicha posicion
    for (int i = 0; i < vector.size(); i++) {
        int elem;
        cin >> elem; 
        vector[i] = elem;
    }

    TipoSolucion sol = resolver(datos);
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