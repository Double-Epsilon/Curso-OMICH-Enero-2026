#include <bits/stdc++.h>
using namespace std;

// Comparador
struct cmp{
    bool operator()(const pair<int, string> &a, const pair<int, string> &b){
        if(a.first != b.first) return a.first < b.first; // Por Cantidad (mayor a menor)
        return a.second > b.second; // Por Nombre (menor a mayor)
    }
};

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion entrada/salida

    int q, max; cin >> q >> max; // Cantidad de instrucciones, Maxima cantidad de atendidos

    // Para guardar cada persona y ordenarlas conforme la cantidad de articulos (pair<Cantidad, Nombre>)
    priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> fila;
    int cantVend = 0; // Cantidad total de articulos vendidos

    char acc; // Accion
    string nom; // Nombre
    int x; // Cantidad de articulos

    // Mientras falten instrucciones Y falte gente por atender
    while(q-- && max > 0){
        cin >> acc;

        // Formar "F"
        if(acc == 'F'){
            cin >> nom >> x;
            // Agregamos a la fila la cantidad y nombre
            fila.push(make_pair(x, nom));
        
        // Retirar "R"
        }else if(acc == 'R'){
            // Imprimir el primer elemento
            cout << fila.top().second << " se retiro :(\n";
            fila.pop(); // Eliminar primer elemento

        // Atender "A"
        }else if(acc == 'A'){
            // Imprimir el primer elemento
            cout << fila.top().second << " compro " << fila.top().first << " productos :D\n";
            cantVend += fila.top().first; // Sumar a la cantidad total vendida
            max--; // Una persona menos para atender
            fila.pop(); // Eliminar primer elemento
        }
    }
    cout << "Se vendieron " << cantVend << " productos\n";

    return 0;
}