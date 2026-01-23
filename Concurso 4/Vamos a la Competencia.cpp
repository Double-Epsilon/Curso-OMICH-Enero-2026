#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion entrada/salida

    int q; cin >> q; // Cantidad de instrucciones
    queue<string> principal; // Fila principal (tamaño maximo de 10)
    queue<string> espera; // Fila de espera
    
    char acc; // Accion
    string nom; // Nombre de la persona
    while(q--){
        cin >> acc;
        
        // "Formar"
        if(acc == 'F'){
            cin >> nom;
            // Si la fila principal esta llena, formar en la de espera
            if(principal.size() >= 10) espera.push(nom);
            // Caso contrario, formar en la principal
            else principal.push(nom);
        
        // "Subir"
        }else if(acc == 'S'){
            // Si la fila principal esta vacia, nadie se sube
            if(principal.empty()) cout << "No hay personas Pipipi :(\n";
            // Caso contrario...
            else{
                cout << principal.front() << '\n';
                principal.pop(); // Eliminar de la fila principal
                if(!espera.empty()){ // Si hay gente en la fila de espera
                    // Formamos al primero en la fila principal 
                    principal.push(espera.front());
                    espera.pop();
                }
            }
        
        // "Cantidad"
        }else if(acc == 'C'){
            // Si no hay gente en la fila
            if(principal.empty()) cout << "No hay personas Pipipi :(\n";
            // Caso contrario, imprimir tamaño de la fila
            else cout << principal.size() << '\n';
        
        // "Espera"
        }else if(acc == 'P'){
            // Si no hay gente en la fila
            if(espera.empty()) cout << "Que buen servicio :)\n";
            // Caso contrario, imprimir tamaño de la fila
            else cout << espera.size() << '\n';
        }
    }
    
    // Si quedo gente en la fila principal...
    if(!principal.empty()){
        cout << "No pudieron subir :(\n";
        // Imprimir cada persona faltante en la fila principal
        while(!principal.empty()){
            cout << principal.front() << '\n';
            principal.pop();
        }
        // Imprimir cada persona faltante en la fila de espera
        while(!espera.empty()){
            cout << espera.front() << '\n';
            espera.pop();
        }
    // Si no hay gente en la fila principal
    }else cout << "Todos pudieron subir :)\n";
    
    return 0;
}