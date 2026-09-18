// Oscar Silva Urbina
// Coste O(n) 


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// función que resuelve el problema
string resolver(const vector <int> &v, int &p) {
    //casos especiales donde vector menores o mayores vacio
    if ( p <0 || p>=v.size() - 1) {
        return "SI";
    }

    //buscamos el elemento mas grande de vector menores
    int mayorMenores = v[0];
    for (int i = 0; i <= p; i++) {
        if (v[i] > mayorMenores) mayorMenores = v[i];
    }

    //buscamos el eleemento mas pequeño de vector mayores
    int menorMayores = v[p+1];
    for (int i = p + 2; i < v.size(); i++) {
        if (v[i] < menorMayores) menorMayores = v[i];
    }
    if (mayorMenores < menorMayores) return "SI";
    else return "NO";

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tamvec;
    cin >> tamvec;
    vector <int> vector(tamvec);
    //punto
    int p;
    cin >> p; 
    //creamos vector de elementos con cada uno en dicha posicion
    for (int i = 0; i < vector.size(); i++) {
        int elem;
        cin >> elem; 
        vector[i] = elem;
    }

    string sol = resolver(vector, p);
    // escribir sol
    cout << sol << "\n";


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