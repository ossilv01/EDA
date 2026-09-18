// Oscar Silva Urbina
// Coste O(n) 
//numerosos casos
//Observaciones: A lo mejor se puede meter todo en el mismo for inicial
//al menos para crear los 2 vectores y a lo mejor no es necesario
// el primer vector creado si no mas bien ir cogiendo cin >> 
// y procesarlo al momento

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// función que resuelve el problema
string resolver(const vector <int> &v, int &p) {
   /* vector <int> menores;
    vector <int> mayores; */
    //Creo 2 sub-vectores distintos, uno conteniendo los elementos 
    //hasta p, y otro conteniendo los elementos de la derecha de p
    /*for (int i = 0; i < v.size(); i++) {
        if (i <= p) menores.push_back(v[i]);
        else mayores.push_back(v[i]);
    }*/

    //casos especiales donde vector menores o mayores vacio
    if ( p <0 || p>=v.size() - 1) {
        return "SI";
    }
    
    int mayorMenores = v[0];
    for (int i = 0; i <= p; i++) {
        if (v[i] > mayorMenores) mayorMenores = v[i];
    }
    int menorMayores = v[p+1];

    for (int i = p + 2; i < v.size(); i++) {
        if (v[i] < menorMayores) menorMayores = v[i];
    }

    //casos especiales
    //vector menores o mayores vacio
    /*if (menores.size() == 0 || mayores.size() == 0) {
        a = "SI";
        return a;
    }*/
    ////vector mayores vacio
    //if (mayores.size() ==0) {
    //    a = "SI";
    //    return a;
    //}

   

    //buscamos el elemento mas grande de vector menores
    //for (int num : menores) {
    //    if (num > mayorMenores)
    //        mayorMenores = num;
    //}

    ////buscamos el eleemento mas pequeño de vector mayores
    //for (int num : mayores) {
    //    if (num < menorMayores)
    //        menorMayores = num;
    //}
    //
    //for (int e : menores) std::cout << e << " ";
    //cout << endl;
    //for (int a : mayores) std::cout << a << " ";
    //
    //cout << endl;
    //Damos veredicto
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