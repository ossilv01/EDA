// Oscar Silva Urbina 
//Coste actual O(n). Time Limit
//Coste deseado O(log n) 
//Problema = uso de vectores 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

//No duplicar vector, sino coger por referencia. Y constnate para no poder modificar
int resolver(const vector <int>& v, int&npicos, int&nvalles) {
    
    //margen de -2 por patron o potra encontrada
    //ahora da 3 vueltas en vez de 5. 
    for (int i = 0; i < v.size()-2; i++) {
        int izq = v[i];
        int medio = 0;
        if (i + 1 < v.size()) {
            medio = v[i + 1];
        }
        int dcha = 0;
        if (i + 2 < v.size()) {
            dcha = v[i + 2];
        }

        if (izq < medio && medio > dcha) npicos++;
        if (izq > medio && medio < dcha) nvalles++;
    }
    return 0;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

void resuelveCaso() {
    // leer los datos de la entrada y creamos lista con huecos x
    int ntemperaturas;
    cin >> ntemperaturas;
    vector <int> lista(ntemperaturas);

    //variables que cambiaremos por referencia en metodo solucion
    int npicos = 0;
    int nvalles = 0; 

    //metemos los valores que vamos leyendo a su posición exacta de lista
    for (int i = 0; i < lista.size(); i++) {
        int elem;
        cin >> elem; 
        lista[i] = elem;
    }
    
    resolver(lista, npicos, nvalles);
    cout << npicos << " " << nvalles;

    //for (int e : lista) {
    //    cout << e << " ";
    //}
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