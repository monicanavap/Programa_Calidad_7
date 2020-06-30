//
//  Printer.h
//  ProgramaLab7
//
//  Created by Monica Nava on 5/15/20.
//  Copyright © 2020 Monica Nava. All rights reserved.
//
//.b= 18
/* Matricula: A01570079
nombre: Monica Nava
Descripcion: Clase que imprime los calculos para b0, b1, b2, b3 y zk*/
#ifndef Printer_h
#define Printer_h
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <cctype>
#include "File.h"
using namespace std;
class Printer {
    private:
    File archivo;
    public:
    void setData(File arch);
    void print();
};
void Printer:: setData(File arch){
    archivo = arch;
}
//.i
/* funcion: imprime formato requerido
parametro: ninguno
valor de retorno: ninguno */
void Printer:: print(){
    cout << "N = " << archivo.getN() << endl;
    cout<<fixed<<setprecision(5);
    cout << "wk = " << archivo.getWk() << endl; //.a
    cout << "xk = " << archivo.getXk() << endl;
    cout << "yk = " << archivo.getYk() << endl;
    cout << "-------------------------------" << endl; //.a
    //.d=2
    cout << "b0 = " << archivo.getB0() << endl;
    cout << "b1 = " << archivo.getB1() << endl;
    cout << "b2 = " << archivo.getB2() << endl; //.a
    cout << "b3 = " << archivo.getB3() << endl; //.a
    cout << "-------------------------------" << endl; //.a
    cout << "zk = " << archivo.getZk() << endl; //.a
}

#endif /* Printer_h */

