//Oscar Silva Urbina
//Caso Centinela
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std; 

string resolver(vector<int> const &v) {

    int l = v.size();
    int tam = l / 2;
    if (v.size() / 2 == 0) return "nvalores tiene que ser potencia de 2";

    //Creamos sub-vectores con rangos
    vector<int> izq(v.begin(), v.end() - tam);
    vector<int> dcha(v.begin() + tam, v.end());

    int minizq = izq[0];
    int maxdcha = dcha[0];    

    //Busqueda de min lado izq
    for (int i = 0; i < izq.size(); i++) {
        if (izq[i] < minizq) minizq = izq[i];
    }
    //Busqueda de max lado dcha
    for (int j = 0; j < dcha.size(); j++) {
        if (dcha[j] > maxdcha) maxdcha = dcha[j];
    }

    //Algoritmo de busqueda para verificar condiciones
    //Vector Parcialmente Ordenado
    bool F_cond1 = false; 
    bool F_cond2 = false; 

    int i = 0; 
    int j = 0;
    while (i<izq.size() && !F_cond1) {
        if (izq[i] > maxdcha) F_cond1 = true;
        else i++;
    }
    
    while (j < dcha.size() && !F_cond2) {
        if (dcha[j] < minizq) F_cond2 = true;
        else j++;
    }
    
    if (!F_cond1 && !F_cond2) return "SI";
    else return "NO";
}

bool RECParcialmente_ordenado(const vector<int> &v, int ini, int fin, int& min, int& max) {
    int n = fin - ini; 
    //Condiciones base
    if (n == 0) return false;
    if (ini == fin-1) return true;

    //Condicion parada
    //Datos
    int mit = (ini + fin) / 2;
    int minizq = v[ini];
    int maxdcha = v[fin-1];
    int maxizq = v[mit-1];
    int mindcha = v[mit];

    ////Busqueda de min lado izq
    //for (int i = 0; i < mit; i++) {
    //    if (v[i] < minizq) minizq = v[i];
    //}

    ////Busqueda max lado izq
    //for (int i = 0; i < mit; i++) {
    //    if (v[i] < minizq) minizq = v[i];
    //}

    ////Busqueda de max lado dcha
    //for (int j = fin; j > mit; j--) {
    //    if (v[j] > maxdcha) maxdcha = v[j];
    //}

    ////Busqueda min lado dcha
    //for (int j = fin; j > mit; j--) {
    //    if (v[j] > mindcha) mindcha = v[j];
    //}


    //Recursión en ambos lados:
    bool izq = RECParcialmente_ordenado(v,ini,mit,minizq, maxizq);
    bool dcha = RECParcialmente_ordenado(v,mit,fin,mindcha, maxdcha);
    if (izq && dcha) {
        max = maxdcha;
        min = minizq;
        
        return true;
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
