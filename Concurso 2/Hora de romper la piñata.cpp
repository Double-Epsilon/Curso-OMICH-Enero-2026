#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

// Estructura "Persona"
struct Persona{
    string nom; // Nombre
    int ed, frz; // Edad, fuerza

    // Funcion para leer datos
    void leer(){
        cin >> nom >> ed >> frz;
    }

    // Funcion para imprimir datos
    void imprimir(){
        cout << nom << " " << ed << " " << frz << '\n';
    }

    // Sobrecarga de operador "<"
    bool operator<(const Persona& p) const {
        if(ed != p.ed) return ed < p.ed; // Por Edad
        if(frz != p.frz) return frz < p.frz; // Por Fuerza
        return nom < p.nom; // Por Nombre
    }
};

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion entrada/salida

    int n, d; cin >> n >> d;
    vector<Persona> people(n); // Vector de "Persona"
    for(int i=0; i<n; i++){
        people[i].leer();
    }
    sort(all(people)); // Ordenamos las personas

    for(int i=0; i<n; i++){
        people[i].imprimir(); // Imprimir los datos de la "i"-esima persona
        d -= people[i].frz; // Restar dureza a la piñata
        if(d <= 0){ // Si la piñata murio
            cout << "Vamos por los dulces"; 
            return 0; // Terminar programa
        }
    }
    // Nunca se rompio
    cout << "Son debiles les falta odio";

    return 0;
}