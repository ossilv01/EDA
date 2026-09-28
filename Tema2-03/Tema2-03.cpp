//Oscar Silva Urbina
//Caso Centinela
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std; 

bool RECParcialmente_ordenado(const vector<int> &v, int ini, int fin, int& min, int& max) {
    int n = fin - ini; 
    //Condiciones base
    if (n == 0) return false;
    if (ini == fin-1) return true;

    //Datos
    int mit = (ini + fin) / 2;
    int minizq = v[ini];
    int maxdcha = v[fin-1];
    int maxizq = v[mit-1];
    int mindcha = v[mit];

    //Recursión en ambos lados:
    bool izq = RECParcialmente_ordenado(v,ini,mit,minizq, maxizq);
    bool dcha = RECParcialmente_ordenado(v,mit,fin,mindcha, maxdcha);
    if (izq && dcha) {
        max = maxdcha;
        min = minizq;
        //Condición que rompe "vector semi ordenado" (6 > 1 && 2 > 1) 
        if (maxizq > mindcha &&  min > mindcha) return false;
        else return true; 
    }
    else return false; 
}

bool Parcialmente_ordenado(const vector<int> &v) {
    int min, max; 
    return RECParcialmente_ordenado(v, 0, v.size(), min, max);
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int a;
    cin >> a; 
    vector <int> v;
    while (a != 0) {
        v.push_back(a);
        cin >> a; 
    }
    //Caso último/Centinela
    if (v.empty()) return false; 

    bool resultado = Parcialmente_ordenado(v);
    if (resultado) cout << "SI";
    else cout << "NO";
    cout << endl;
    /*string sol = resolver(v);
    cout << sol << endl; */
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
