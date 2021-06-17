#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

class Parser
{
    public:
        Parser();
        Parser (string fileName );
        //virtual ~Parser();
        vector <vector<string>>  getParseInstructions ();


    private:
        void readFile (string fileName);
        void checker (vector <vector <string>> vecInst);
        vector <vector<string>> vecInstructions;
        vector <vector <string>> parseInstruction ;
        string str;

};

//Default constructor
Parser::Parser(){

}
//Constructor
Parser::Parser (string fileName){
readFile (fileName);

}

//Metodo para leer archivo
void Parser:: readFile (string fileName){

    ifstream myInputFile;
    myInputFile.open(fileName.data());
    if (myInputFile){
            while (getline (myInputFile,str )){
        vector <string> work;





        string temp= "";
        for (int i=0; i < str.size(); i++){


            if (str[i]== ' '){
                    if (str[i+1] == ' '){
                        //No hagas nada
                    }

                    else {

                work.push_back(temp);
                temp="";
                    }
            }
            else {
                temp.push_back(str[i]);

            }

        }

if (temp==""){
    //No metas nada al vector
    }
        else {
            work.push_back(temp);
        }

       vecInstructions.push_back(work);

}
checker (vecInstructions);


    }

    else {
        cout << "Imposible abrir el archivo " + fileName + "para lectura " << endl;
    }

}
//Metodo que verifica que los datos de entrada sean correctos para despues generar el vector de instrucciones correcto

void Parser:: checker (vector <vector <string>> vecInst){
/*
Opciones posibles
            A - 3 args, all numbers
            P - 2 args, all numbers
            L - 1 arg, number
            F - 0 args
            E - 0 args
            C - all comments
            */

for (int i= 0 ; i< vecInst.size(); i++){


        //Manejar todo los casos validos
        if (vecInst[i][0] == "A"){
                if (vecInst[i].size() < 4){
                    cout << "Numero de Argumentos invalido en la linea " << i+1 << endl;
                    cout << "No se ejecutara esta instruccion" << endl;
                }
                else {
                        parseInstruction.push_back(vecInst[i]);

                }

        }
        else if (vecInst[i][0] == "P"){
            if (vecInst[i].size() < 3){
                    cout << "Numero de Argumentos invalido en la linea " << i+1 << endl;
                    cout << "No se ejecutara esta instruccion" << endl;
                }
                else {
                        parseInstruction.push_back(vecInst[i]);

                }

        }
        else if (vecInst[i][0] == "L"){
                if (vecInst[i].size() < 2){
                    cout << "Numero de Argumentos invalido en la linea " << i+1 << endl;
                    cout << "No se ejecutara esta instruccion" << endl;
                }
                else {
                        parseInstruction.push_back(vecInst[i]);

                }

        }
        else if (vecInst[i][0] == "F"){

                        parseInstruction.push_back(vecInst[i]);



        }
        else if (vecInst[i][0] == "E"){
                parseInstruction.push_back(vecInst[i]);

        }
        else if (vecInst[i][0] == "C"){
                parseInstruction.push_back(vecInst[i]);

        }
        else {
            cout << "Error " << endl;
        }


}



}



//Regresa vector de instrucciones
vector <vector<string>> Parser::getParseInstructions (){

return parseInstruction;
}






