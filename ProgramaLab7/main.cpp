//
//  main.cpp
//  ProgramaLab7
//
//  Created by Monica Nava on 5/15/20.
//  Copyright © 2020 Monica Nava. All rights reserved.
//
/* Matricula: A01570079
nombre: Monica Nava
Descripcion: Clase que lee el archivo, carga los datos, y manda a llamar a la clase File*/
/* Descripcion programa: Calcule los siguientes datos
- La cantidad de cuádruplos leídos (N)
- Los parámetros de regresión múltiple β0, β1, β2 y β3
- Una predicción mejorada zk, donde zk = β0 + β1 wk + β2 xk + β3 yk */
//.b= 20
#include <iostream>
#include <string>
#include <fstream>
#include "File.h"
#include <ctype.h>
#include "Printer.h"
using namespace std;

int main(int argc, const char * argv[]) {
    // archivo
    string nombreArch;
    File archivo;
    Printer imprimir;
    
    cout << "teclea nombre del archivo: ";
    cin >> nombreArch;
    archivo.setFile(nombreArch);
    //validar que si exista el archivo agregar
    if (archivo.existsFile(nombreArch)) {
        //validar que no esté vacio
        if (archivo.emptyFile()){
            cout << "archivo vacio" << endl;
        }
        else {
            archivo.leerArchivo();
            //archivo.getXk();
            archivo.Calcular(); //.a
            imprimir.setData(archivo);
            //agregar if de checar negativos
            if (archivo.getWk() >= 0 && archivo.getYk() >= 0 && archivo.getXk() >= 0) { //.m
            imprimir.print();
                //imprimir.prueba();
            }
            else {
                cout << "Datos deben ser positivos" << endl;
            }
        }
    }
    else {
        cout << "archivo no existe" << endl;
    }
    return 0;
}
