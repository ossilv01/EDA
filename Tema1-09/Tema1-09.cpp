// Oscar Silva Urbina
//Coste total: O(nlogn) 
// Por uso de metodo sort() que es el coste MAX entre
// el coste de O(n) por tanto los for de recorrido del vector
// como el metodo .erase() que tambien recorre el vector de forma lineal
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std; 

// función que resuelve el problema
int resolver(vector <string> &v) {
    if (v.size() <= 0) {
        return 0; 
    }
    sort(v.begin(), v.end());

    string izq = v[0];
    int tam = v.size();

    for (int i = 1; i < v.size();) {
        string dcha = v[i];
        if (izq == dcha) {
            v.erase(v.begin() + i);
            tam--;
        }
        else if (izq != dcha) {
            izq = dcha;
            i++;
        }
    }
    return 0; 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    int nelem;
    cin >> nelem;
    vector <string> v(nelem);
    for (int i = 0; i < v.size(); i++) {
        string text;
        cin >> text;
        v[i] = text;
    }
    resolver(v);

    // escribir sol
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