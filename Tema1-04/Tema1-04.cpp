// Oscar Silva Urbina 
//Coste O(n^2)
// TIME LIMIT
//no utilizar funcion erase, pues coste O(n^2)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std; 

// función que resuelve el problema
int resolver(vector <int> &v) {
    int tam = v.size(); 
    for (int i = 0; i < v.size();) {
        if (v[i] % 2 != 0) {
            v.erase(v.begin() + i);
            tam--;
        }
        //se avanza cuando no se tiene que borrar
        //porque o sino estariamos avanzando de más
       else i++;
    }
    v.resize(tam);
    return 0; 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tamvec; 
    cin >> tamvec; 
    vector <int> v(tamvec);
    for (int i = 0; i < v.size(); i++) {
        int elem; 
        cin >> elem; 
        v[i] = elem; 
    }

   // escribir sol
   resolver(v);
   for (int a : v) cout << a << " ";
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