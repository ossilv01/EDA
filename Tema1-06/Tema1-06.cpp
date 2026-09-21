//Oscar Silva Urbina 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
void comparaListados(vector<string> const& eda, vector<string> const& tpv,
    vector<string>& comunes, vector<string>& soloEda, vector<string>& soloTpv) {

    //Versión 1 aunque hago otro doble recorrido de forma bruta: 

    //for (int i = 0; i < eda.size(); i++) {
    //    string a = eda[i];
    //    bool found = false; 
    //    for (int j = 0; j < tpv.size(); j++) {
    //        string b = tpv[j];
    //        if (a == b) {
    //            comunes.push_back(a);
    //            found = true; 
    //        }
    //    }
    //    if (!found) {
    //        soloEda.push_back(a);
    //    }
    //}

    //for (int i = 0; i < tpv.size(); i++) {
    //    string c = tpv[i];
    //    bool found = false; 
    //    for (int j = 0; j < comunes.size(); j++) {
    //        if (c != comunes[j]) found = true;
    //    }
    //    if (!found) soloTpv.push_back(c);
    //}

    //Versión 2 más limpia y menos reciclaje de codigo: 
    int i = 0; 
    int j = 0; 
    //El && es necesario porque asi se detiene cuando uno de los vectores 
    //se queda sin elementos
    //Si se utiliza el || (OR). en el ejemplo 1, llega un momento
    //donde la primera condición se vuelve en falsa (6 !<6)
    //pero como la otra sigue siendo true (5 < 6) se mete dentro del bucle while
    // y no hay elementos para "eda[6]", pues ya esta vacio. Da ERROR
    while (i < eda.size() && j <tpv.size()) {
        if (eda[i] == tpv[j]) {
            comunes.push_back(eda[i]);
            i++;
            j++;
        }

        //Como estan en orden alfabetico, si que se pueden comparar asi los strings
        // devuelve un  true, si eda[i] va antes que tpv[j] en el diccionario
        //Nota aparte: si una cadena es el inicio de la otra, la cadena corta es menor
        else if (eda[i] < tpv[j]) {
            soloEda.push_back(eda[i]);
            i++;
        }
        else {
            soloTpv.push_back(tpv[j]);
            j++;
        }
    }
    //por si el el tamaño de TPV se acabo y todavia entonces quedan
    //elementos en EDA, los cuales todos esos, sabiendo que estan ordenados,
    //pues seran exclusivos para eda
    while (i < eda.size()) {
        soloEda.push_back(eda[i]);
        i++;
    }

    //por si el el tamaño de EDA se acabo y todavia entonces quedan
     //elementos en TPV, los cuales todos esos, sabiendo que estan ordenados,
     //pues seran exclusivos para TPV
    while (j < tpv.size()) {
        soloTpv.push_back(tpv[j]);
        j++;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    vector<string> eda(n);
    vector<string> comunes;
    vector<string> soloEda;
    vector<string> soloTpv;
    for (string& e : eda) cin >> e;
    cin >> n;
    vector<string> tpv(n);
    for (string& e : tpv) cin >> e;
    comparaListados(eda, tpv, comunes, soloEda, soloTpv);
    for (string& e : comunes) cout << e << " ";
    cout << endl;
    for (string& e : soloEda) cout << e << " ";
    cout << endl;
    for (string& e : soloTpv) cout << e << " ";
    cout << endl;
}


//#define DOMJUDGE
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
    //system("PAUSE");
#endif

    return 0;
}
