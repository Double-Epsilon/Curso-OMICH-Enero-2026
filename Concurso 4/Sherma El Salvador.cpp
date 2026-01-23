#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(); cout.tie(0); // Optimizacion entrada/salida

    int a, c, r; cin >> a >> c >> r; // Alimento, Curativos, Rosarios
    int actA = a, actC = c, actR = r; // Cantidades actuales
    queue<int> alim, cur, fe; // Filas Alimento, Curacion, Fe
    int fAct = 1; // Fila actual
    
    int q; cin >> q; // Cantidad de acciones
    string acc; // Accion
    int x; // Bicho nuevo
    while(q--){
        cin >> acc;

        // "Sherma" (atender fila / ir en busca de suministros)
        if(acc == "Sherma"){
            // Si estamos en la fila 1...
            if(fAct == 1){
                // Si NO esta vacia...
                if(!alim.empty()){
                    // Si tenemos comida suficiente...
                    if(actA >= alim.front()){
                        // Restar comida y eliminar bicho
                        actA -= alim.front();
                        alim.pop();
                        cout << "Alimento\n";
                    // Si no tenemos comida suficiente, avanzamos de fila
                    }else fAct++;
                // Si la fila esta vacia, avanzamos de fila
                }else fAct++;
            }

            // Si estamos en la fila 2...
            if(fAct == 2){
                // Si NO esta vacia...
                if(!cur.empty()){
                    // Si tenemos curativos suficientes...
                    if(actC >= cur.front()){
                        // Restar curativos y eliminar bicho
                        actC -= cur.front();
                        cur.pop();
                        cout << "Curacion\n";
                    // Si no tenemos curativos suficientes, avanzamos de fila
                    }else fAct++;
                // Si la fila esta vacia, avanzamos de fila
                }else fAct++;
            }

            // Si estamos en la fila 3...
            if(fAct == 3){
                // Si NO esta vacia...
                if(!fe.empty()){
                    // Si tenemos rosarios suficientes...
                    if(actR >= fe.front()){
                        // Restar rosarios y eliminar bicho
                        actR -= fe.front();
                        fe.pop();
                        cout << "Fe\n";
                    // Si no tenemos rosarios suficientes, avanzamos de fila
                    }else fAct++;
                // Si la fila esta vacia, avanzamos de fila
                }else fAct++;
            }

            // Si estamos en la fila 4 (ir de viaje)...
            if(fAct == 4){
                cout << "Viaje: ";

                // Si falta gente en la fila de Alimento...
                if(!alim.empty()){
                    // Si ocupamos traer comida...
                    if(actA < alim.front()){
                        // Agregamos comida
                        cout << "Comida ";
                        actA += a;
                    }
                }

                // Si falta gente en la fila de Curacion...
                if(!cur.empty()){
                    // Si ocupamos traer curativos...
                    if(actC < cur.front()){
                        // Agregamos curativos
                        cout << "Curativos ";
                        actC += c;
                    }
                }

                // Si falta gente en la fila de Fe...
                if(!fe.empty()){
                    // Si ocupamos traer rosarios...
                    if(actR < fe.front()){
                        // Agregamos rosarios
                        cout << "Rosarios";
                        actR += r;
                    }
                }

                cout << '\n';
                fAct = 1; // Regresamos a la fila 1 nuevamente
            }
        
        // "Alimento", "Curacion", "Fe" (Formar en fila)
        }else{
            cin >> x;

            // Agregamos el bicho "x" a la fila correspondiente
            if(acc == "Alimento") alim.push(x);
            else if(acc == "Curacion") cur.push(x);
            else if(acc == "Fe") fe.push(x);
        }
    }

    // Al finalizar, imprimimos recursos sobrantes
    cout << actA << " " << actC << " " << actR;

    return 0;
}