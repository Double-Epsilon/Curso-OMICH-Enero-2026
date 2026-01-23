#include <bits/stdc++.h>
using namespace std;

deque<char> datos; // Deque para almacenar la secuencia de datos

// Funcion para insertar
void insertar(int &n, char &lado){
    deque<char> dq; // Para guardar los datos a insertar
    char carac; // Caracter
    for(int i=0; i<n; i++){
        cin >> carac;
        dq.push_back(carac);
    }

    // Si es de tipo 'B', guardamos la mitad del otro lado (separar mitades)
    if(lado == 'B'){
        for(int i=0; i<n/2; i++){
            dq.push_back(dq.front());
            dq.pop_front();
        }
    }

    // Insertar los datos
    while(!dq.empty()){
        // Tipo "Izquierda"
        if(lado == 'L'){
            // Agregar al frente
            datos.push_front(dq.back());
            dq.pop_back();
        
        // Tipo "Derecha"
        }else if(lado == 'R'){
            // Agregar al final
            datos.push_back(dq.front());
            dq.pop_front();
        
        // Tipo "Ambos"
        }else if(lado == 'B'){
            // Agregamos la primera mitad al final
            if(dq.size() > n/2){
                datos.push_back(dq.front());
                dq.pop_front();
            // Agregamos la segunda mitad al principio
            }else{
                datos.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
}

// Funcion para eliminar
void eliminar(int &n, char &lado){
    while(n--){
        // Tipo "Izquierda" y "Ambos"
        if(lado == 'L' || lado == 'B') datos.pop_front(); // Eliminar al frente
        // Tipo "Derecha" y "Ambos"
        if(lado == 'R' || lado == 'B') datos.pop_back(); // Eliminar al final
    }
}


// Funcion para rotar
void rotar(int &n, char &lado){
    deque<char> cambio; // Almacenar una de las mitades (solo para tipo "Ambos")
    
    if(lado == 'B') n *= 2; // Si tipo "Ambos", ocupamos el doble de operaciones
    for(int i=0; i<n; i++){
        // Tipo "Izquierda"
        if(lado == 'L'){
            // Agregamos al final los datos de la izquierda
            datos.push_back(datos.front());
            datos.pop_front();
        
        // Tipo "Derecha"
        }else if(lado == 'R'){
            // Agregamos al inicio los datos de la derecha
            datos.push_front(datos.back());
            datos.pop_back();
        
        // Tipo "Ambos"
        }else if(lado == 'B'){
            // Guardamos la primera mitad en "cambio"
            if(i < n/2){
                cambio.push_back(datos.front());
                datos.pop_front();
            // Pasamos la segunda mitad al principio de "datos"
            }else{
                datos.push_front(datos.back());
                datos.pop_back();
            }
        }
    }

    // Agregamos la primera mitad al final de "datos" (solo tipo "Ambos")
    while(!cambio.empty()){
        datos.push_back(cambio.front());
        cambio.pop_front();
    }
}

// main()
int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion entrada/salida

    int q, segs; cin >> q >> segs; // Cantidad de operaciones, Cantidad de segmentos

    char carac; // Caracter
    for(int i=0; i<segs; i++){
        cin >> carac;
        datos.push_back(carac);
    }

    char acc, lado; // Accion, Lado (Tipo)
    int n; // Cantidad de elementos
    while(q--){
        cin >> acc >> lado >> n;
        
        // "Insertar"
        if(acc == 'I') insertar(n, lado);
        // "Eliminar"
        else if(acc == 'E') eliminar(n, lado);
        // "Rotar"
        else if(acc == 'R') rotar(n, lado);
    }

    // Imprimir secuencia final
    while(!datos.empty()){
        cout << datos.front() << " ";
        datos.pop_front();
    }

    return 0;
}