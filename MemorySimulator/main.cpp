//Hugo Garza A01177091
//Roberto Cantu A01196704
//Daniel Pardo A00822263

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Parser.h"
#include "Insturctions.h"
#include <string>



using namespace std;

//Objeto con clase de instrucciones con los metodos A,P,L,F,E, Y C
Insturctions instructionsObj;
//Funcion que convierte de String a Int
int strtoInt (string instruction){
    stringstream stringconverter (instruction);
    int x;
    stringconverter >> x;
    return x;

}

int main()
{
    bool lru;
    cout<<"Ponga 1 para elegir FIFO, ponga 0 para elegir LRU "<<endl;

    cin>>lru;


vector <vector <string>> instructions;

// Inicializa archivo de texto
Parser parser ("ArchivoTrabajo.txt");


//Vector con instrucciones
instructions = parser.getParseInstructions();






/*
Opciones posibles
            A - 3 args, all numbers  ---- Lee y modifica direcciones de procesos
            P - 2 args, all numbers ---- Asigna procesos a memoria real
            L - 1 arg, number ---- Libera procesos
            F - 0 args ---- Reporte de resultados
            E - 0 args ---- Termina ejecucion
            C - all comments ---- Agrega comentarios
            */


for (int i=0; i < instructions.size(); i++){

    if (instructions[i][0] == "A"){ 

        instructionsObj.instA(strtoInt(instructions[i][1]), strtoInt(instructions[i][2]), strtoInt(instructions[i][3]));
        }

        else if (instructions[i][0] == "P"){

        instructionsObj.instP(strtoInt(instructions[i][1]), strtoInt(instructions[i][2]), lru);
        // Metodo para instuccion
        }

        else if (instructions[i][0] == "L"){
        instructionsObj.instL(strtoInt(instructions[i][1]));
        // Metodo para instuccion
        }


        else if (instructions[i][0] == "F"){
            instructionsObj.instF();
        // Metodo para instuccion
        }

        else if (instructions[i][0] == "E"){
            cout<<"Se termino el programa "<<endl;
            return 0;
        }

        else if (instructions[i][0] == "C"){
            for(int j = 0; j<instructions[i].size(); j++){
                 cout<<instructions[i][j]<<" ";
            }
            cout<<endl;
        }

        else {

            cout << "Error" << endl;
            return 0;
        }
}

    return 0;
}
