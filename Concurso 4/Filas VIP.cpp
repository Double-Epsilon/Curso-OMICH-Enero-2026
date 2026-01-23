#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion entrada/salida
    
    int n; cin >> n;
    vector<int> tams(n); // Guardar tamaño de cada fila
    for(int i=0; i<n; i++){
        cin >> tams[i];
    }

    vector<deque<int>> filas(n); // Vector de deque (permiten insertar adelante y atras)

    int q; cin >> q; // Numero de instrucciones
    string acc; // Accion
    int f, x; // Numero de fila, Persona
    while(q--){
        cin >> acc >> f;
        f--; // Mantener 0-indexado

        // "FORMAR"
        if(acc == "FORMAR"){
            cin >> x;
            // Si la fila en la posicion "f" alcanza su capacidad maxima
            if(filas[f].size() >= tams[f]) cout << "FILA LLENA\n";
            // Caso contrario, agregar al final
            else filas[f].push_back(x);
        
        // "VIP"
        }else if(acc == "VIP"){
            cin >> x;
            // Si la fila en la posicion "f" alcanza su capacidad maxima
            if(filas[f].size() >= tams[f]) cout << "FILA LLENA\n";
            // Caso contrario, agregar al principio
            else filas[f].push_front(x);
        
        // "ATIENDE"
        }else if(acc == "ATIENDE"){
            // Si la fila esta vacia
            if(filas[f].empty()) cout << "FILA VACIA\n";
            // Caso contrario, imprimir persona atendida y eliminar de la fila
            else{
                cout << filas[f].front() << '\n';
                filas[f].pop_front();
            }
        }
    }

    // Imprimir tamaño final de cada fila
    for(int i=0; i<n; i++){
        cout << filas[i].size() << " ";
    }
    
    return 0;
}