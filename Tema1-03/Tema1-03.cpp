// Oscar Silva Urbina
//numerosos casos

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(const vector <int> &v, int &p) {
    vector <int> menores;
    vector <int> mayores; 

    for (int i = 0; i < v.size(); i++) {
        if (v[i] <= v[p]) menores.push_back(v[i]);
        else mayores.push_back(v[i]);
    }
    
    for (int e : menores) std::cout << e << " ";
    cout << endl;
    for (int a : mayores) std::cout << a << " ";
        
    return 0; 

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

    int sol = resolver(vector, p);
    // escribir sol
    cout << endl; 


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