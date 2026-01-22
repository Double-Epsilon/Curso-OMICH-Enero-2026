#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion entrada/salida

    float c, w; cin >> c >> w; // Capacidad, Criterio

    vector<float> guardados; // Archivos guardados
    float ocupado = 0.0f; // Capacidad ocupada

    int k; // Tamaño del paquete
    while(cin >> k){
        int cant = 0; // Cantidad de archivos tomados de este paquete
        pair<float, float> archivo; // Valor, Peso
        for(int i=0; i<k; i++){
            cin >> archivo.first >> archivo.second;
            if(cant == k/2) continue; // Si ya tomamos la mitad, ignoramos los demas
            // Calcular "x"
            float x = (archivo.first*(2*k-i)) / (archivo.second + 1.0);
            // Si se cumple el criterio minimo...
            if(x >= w){
                // Si el archivo excede la capacidad de almacenamiento...
                if(ocupado + archivo.second >= c){
                    // Si el archivo todavia cabe en el 10% extra...
                    if(ocupado + archivo.second <= c + (10*c/100)){
                        // Agregar archivo
                        guardados.push_back(archivo.first);
                        ocupado += archivo.second;
                        cant++;
                    }
                    // Imprimir resultados
                    cout << guardados.size() << '\n';
                    for(float f : guardados){
                        // Resultados a 2 decimales
                        cout << fixed << setprecision(2) << f << '\n';
                    }
                    return 0; // Finalizar programa
                }

                // Agregar archivo
                guardados.push_back(archivo.first);
                ocupado += archivo.second;
                cant++;
            }
        }
    }

    return 0;
}