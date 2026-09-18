// Oscar Silva Urbina
//Coste: O(n). Nos encontramos los recorridos lineales, tanto para rellenar los vectores la primera vez
//Luego a la hora de eliminar recorremos los vectores mientras que hacemos comparaciones
// Y por ulitmo dentro de ellos tenemos la funcion .erase() que tb es O(n) pues desplazamos todos los elementos siguientes al borrado para rellenar el hueco
//Utilizamos la función resize de O(1)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std; 

// función que resuelve el problema
int resolver(vector <string> &v) {
    if (v.size() <= 0) {
        return 0; 
    }
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
    v.resize(tam);
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
    for (string a : v) cout << a << " ";
    cout << "\n";
   // TipoSolucion sol = resolver(datos);
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