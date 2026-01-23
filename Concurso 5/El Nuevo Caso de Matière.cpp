#include <bits/stdc++.h>
using namespace std;
#define ll long long // Ocupamos long long

// Estructura "Sospechoso"
struct Sospechoso{
    string nom; // Nombre
    ll p, a, c; // Participacion, Antecedentes, Conocimiento
    ll s, r; // Nivel Sospecha, Resultado Interrogatorio
    
    // Funcion leer datos
    void leer(){
        cin >> nom;
        cin >> p >> a >> c;
        s = (p*p + a) * c; // Calcular Nivel de Sospecha
        r = max((c*c*p), (p*p*c)); // Calcular Resultado de Interrogatorio
    }
};

// Ordenar por Nivel de Sospecha
struct OrdNivelsospecha{
    bool operator()(const Sospechoso& a, const Sospechoso& b) const {
        if(a.s != b.s) return a.s < b.s; // Mayor s = Mayor prioridad
        return a.nom > b.nom; // Menor nombre = Mayor prioridad
    }
};

// Ordenar por Resultado de Interrogatorio
struct OrdInterrogatorio{
    bool operator()(const Sospechoso& a, const Sospechoso& b) const {
        return a.r > b.r; // Menor resultado = Mayor prioridad
    }
};

// Imprimir los "cant" mayores resultados
string imprimir_mayores(priority_queue<Sospechoso, vector<Sospechoso>, OrdInterrogatorio> pq, int cant){
    deque<Sospechoso> res;  // Para guardar los "cant" mayores
    while(!pq.empty()){
        if(pq.size() <= cant) res.push_back(pq.top()); // Si es de los que buscamos, lo guardamos
        pq.pop(); // Eliminar
    }
    
    string str = ""; // Para guardar la respuesta
    while(!res.empty()){
        str += to_string(res.back().r); // Agregar al string
        if(res.size() > 1) str += " "; // Agregar espacio (solo si no es el ultimo)
        res.pop_back();
    }
    
    return str; // Retornar respuesta
}

// Encontrar al culpable
string encontrar_culpable(priority_queue<Sospechoso, vector<Sospechoso>, OrdInterrogatorio> pq, ll promedio){
    promedio /= 5; // Calcular promedio
    pair<string, ll> x = {"", 1e18}; // Almacenar mejor candidato
    
    while(!pq.empty()){
        // Si su abs() es menor, es mejor candidato
        if(abs(promedio - pq.top().r) < x.second){
            // Almacenar nuevo candidato
            x.first = pq.top().nom;
            x.second = abs(promedio - pq.top().r);
        }
        pq.pop();
    }
    
    return x.first; // Retornar culpable
}

// main
int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion entrada/salida

    int n; cin >> n;
    
    priority_queue<Sospechoso, vector<Sospechoso>, OrdNivelsospecha> lista; // pq ordenada por Nivel de Sospecha
    Sospechoso x;
    // Leer valores
    for(int i=0; i<n; i++){
        x.leer();
        lista.push(x);
    }
    
    priority_queue<Sospechoso, vector<Sospechoso>, OrdInterrogatorio> mayores; // pq ordenada por Res. de Interrogatorio
    string acc;
    ll promedio = 0; // Almacenar suma para luego sacar promedio
    while(cin >> acc){
        if(acc == "Interrogar"){
            cout << lista.top().nom << " " << lista.top().r << '\n';
            if(mayores.size() < 5){ // Si todavia no hay 5 guardados
                // Guardamos sin mas
                promedio += lista.top().r;
                mayores.push(lista.top());
            }else if(mayores.top().r < lista.top().r){ // Si el nuevo interrogado tiene "r" mayor
                // Borramos el menor y guardamos el nuevo candidato
                promedio -= mayores.top().r;
                promedio += lista.top().r;
                mayores.pop();
                mayores.push(lista.top());
            }
            lista.pop(); // Eliminar sospechoso
        }else if(acc == "Sospechoso"){
            // Ingresar nuevo sospechoso
            x.leer();
            lista.push(x);
        }else if(acc == "Informe"){
            // Imprimir primeros 3 mayores
            cout << imprimir_mayores(mayores, 3) << '\n';
        }
    }
    
    // Imprimir primeros 5 mayores
    cout << "Resultados mas altos: " << imprimir_mayores(mayores, 5) << '\n';
    // Encontrar culpable
    cout << encontrar_culpable(mayores, promedio) << " es el culpable!\n";

    return 0;
}