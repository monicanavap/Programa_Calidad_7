//
//  File.h
//  ProgramaLab7
//
//  Created by Monica Nava on 5/15/20.
//  Copyright © 2020 Monica Nava. All rights reserved.
//

//.b= 111
/* Matricula: A01570079
 nombre: Monica Nava
 Descripcion: Clase que lee el archivo, carga los datos y hacer los calculos para b0, b1, b2, b3 y zk*/
#ifndef File_h
#define File_h
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctype.h>
#include <cctype>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <numeric>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <locale>
using namespace std;
class File {
    private:
    //cant lineas
    double n, b0, b1, b2, b3; //.m
    double wk, yk, xk, zk; //.m
    double mat[4][5]; //.a
    //leer nombre archivo
    string archivo;
    vector<double> vectorX;
    vector<double> vectorY;
    //.a
    vector<double> vectorW;
    vector<double> vectorZ;
    
    //metodos
    public:
    File();
    //nombre = nombre de archivo de main
    void setFile(string nombre);
    string getFile ();
    
    //setters
    void setXk(double num);
    //.a
    void setWk(double num);
    void setYk(double num);
    void setB0(double num);
    void setB1(double num);
    void setB2(double num);
    void setB3(double num);
    void setZk(double num);
    
    //getters
    //d.=4
    double getB1();
    double getB0();
    double getN();
    //.a
    double getB2();
    double getB3();
    double getZk();
    double getWk();
    double getYk();
    double getXk();
    void cargarMatriz();
    void Calcular();
    //---
    string getNombre();
    
    //archivo funciones
    void leerArchivo();
    //func empty
    bool emptyFile();
    //func exist
    bool existsFile(const string& archivo);
    
    //vector
    double average(vector<double> vector);
    double sumXY(vector<double> x, vector<double> y);
    double sum(vector<double> vector,int power);
};
File:: File(){
    n = 0;
    xk = 0;
    b0 = 0;
    b1 = 0;
    yk = 0;
    //.a
    wk = 0;
    b2 = 0;
    b3 = 0;
    zk = 0;
    //-
    archivo = "";
}
void File:: setFile(string nombre){
    archivo = nombre;
}
string File:: getFile(){
    return archivo;
}
void File:: setXk(double num){
    xk = num;
}
double File :: getB1(){
    //.d= 4
    return b1;
}
double File :: getB0(){
    //.d=3
    return b0;
}
//.d=10
double File :: getN(){ //.m
    return n;
}
double File:: getXk(){
    return xk;
}

double File:: getYk(){
    //.d=1
    return yk;
}
//.a ---
//.i
double File:: getZk(){
    zk = getB0() + (getB1() * getWk()) + (getB2() * getXk()) + (getB3() * getYk());
    return zk;
}

double File:: getB2(){
    return b2;
}
double File:: getB3(){
    return b3;
}

double File:: getWk(){
    return wk;
}
void File:: setWk(double num){
    wk = num;
}
void File:: setYk(double num){
    yk = num;
}
void File:: setB0(double num){
    b0 = num;
}
void File:: setB1(double num){
    b1 = num;
}
void File:: setB2(double num){
    b2 = num;
}
void File:: setB3(double num){
    b3 = num;
}
void File:: setZk(double num){
    zk = num;
}
//.a-----
//.i
/* funcion: verifica si el archivo tecelado esta vacio
parametro: ninguno
valor de retorno: booleano */
bool File :: emptyFile() {
    ifstream archivoLeer(archivo,std::ios::ate);
    if (archivoLeer.tellg() == 0){
        return true;
    }
    else
        return false;
}
//.i
/* funcion: verifica si el archivo tecleado existe
parametro: ninguno
valor de retorno: bool */
bool File :: existsFile(const string& archivo){
    ifstream arch(archivo.c_str());
    return (bool)arch;
}
//.i
/* funcion: lee todo el archivo que se tecleó, asigna valores a wk, xk, yk. Tambien lee todos los cuadruplos para cargarlos a los vectores, y calcula N
parametro: ninguno
valor de retorno: ninguno */
void File:: leerArchivo(){
    ifstream archivoLeer(archivo);
    string line;
    //archivoLeer.open(archivo);
    //int cont = 0;
    string primeraLinea; //.m
    //cout << "hola" << endl;
    // lee primera linea
    getline(archivoLeer,primeraLinea);
    //.a
    vector<string> valoresConK;
    stringstream s_stream(primeraLinea); //create string stream from the string
      while(s_stream.good()) {
         string substr;
         getline(s_stream, substr, ','); //get first string delimited by comma
         valoresConK.push_back(substr);
      }
    string wkString = valoresConK[0];
    string xkString = valoresConK[1];
    string ykString = valoresConK[2];
    //cout << "lee primera linea" << endl;
    //cout << xkstring << endl;
    //xk = stoi(xkstring); //prob
    setWk(stof(wkString));//.m
    //.a
    setYk(stof(ykString));
    setXk(stof(xkString));
    //las demas
    while (!archivoLeer.eof()){
        getline(archivoLeer,line);
        //.d= 2
        //getline(cin, line);
        //checa lque no sea lineas blancas
        if(line.length()!=0){
            long coma = line.find(","); //.m
            double w, x, y, z; //.m
            //.d = 4
            //.a
            w = stod(line.substr(0, coma));
            line = line.substr(coma+1);
            coma = line.find(",");
            x = stod(line.substr(0,coma));
            line = line.substr(coma+1);
            coma = line.find(",");
            y= stod(line.substr(0,coma));
            z = stod(line.substr(coma+1));
            //.a--
            if (w >= 0  && x>= 0 && y >= 0  && z >= 0){
                //.a
                vectorW.push_back(w);
                vectorZ.push_back(z);
                //.a---
                vectorX.push_back(x);
                vectorY.push_back(y);
                n++;
            }
            //son numeros negativos
            /*else {
                cout << "datos deben ser positivos" << endl;
                //archivoLeer.close();
                break;
            }*/
        }
    }
}
//.d=5
//.i
/* funcion: calcular la sumatoria de un vector a cierta potencia
parametro: vector, entero que es la potencia deseada a calcular para la suma
valor de retorno: double */
double File:: sum(vector<double> vector, int power){
    double sumx = 0;
    for (auto item: vector){
        sumx += pow(item, power);
    }
    return sumx;
}
/* funcion: calcular la suma producto de dos vectores
parametro: vector, vector
valor de retorno: double */
//.i
double File:: sumXY(vector<double> x, vector<double> y){
    double sumxy = 0;
    for (int i= 0; i < x.size(); i++){
        sumxy += x[i] * y[i];
    }
    return sumxy;
}
//.a
//.i
/* funcion: Guarda los datos de la matriz, haciendo en cada casilla los calculos designados usando los metodos anteriores
parametro: ninguno
valor de retorno: ninguna */
void File:: cargarMatriz(){
    mat[0][0]= getN();
    mat[0][1]= sum(vectorW, 1);
    mat[0][2]= sum(vectorX, 1);
    mat[0][3]= sum(vectorY, 1);
    mat[0][4]= sum(vectorZ, 1);
    
    mat[1][0]= sum(vectorW, 1);
    mat[1][1]= sum(vectorW, 2);
    mat[1][2]= sumXY(vectorW, vectorX);
    mat[1][3]= sumXY(vectorW, vectorY);
    mat[1][4]= sumXY(vectorW, vectorZ);
    
    mat[2][0]= sum(vectorX, 1);
    mat[2][1]= sumXY(vectorW, vectorX);
    mat[2][2]= sum(vectorX, 2);
    mat[2][3]= sumXY(vectorX, vectorY);
    mat[2][4]= sumXY(vectorX, vectorZ);
    
    mat[3][0]= sum(vectorY, 1);
    mat[3][1]= sumXY(vectorW, vectorY);
    mat[3][2]= sumXY(vectorX, vectorY);
    mat[3][3]= sum(vectorY, 2);
    mat[3][4]= sumXY(vectorY, vectorZ);
   
}
//.i
/* funcion: Aqui se hace la eliminacion gaussiana, y despues se despeja para beta, y se guardan en los atributos. 
parametro: ninguno
valor de retorno: ninguno*/
void File:: Calcular(){
    cargarMatriz();
    int i, j, k;
    int n = 4;
    double beta[n];
    for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
        if (abs(mat[i][i]) < abs(mat[j][i])){
            for (k = 0; k < n + 1; k++)
            {
                //pivote
                mat[i][k] = mat[i][k] + mat[j][k];
                mat[j][k] = mat[i][k] - mat[j][k];
                mat[i][k] = mat[i][k] - mat[j][k];
            }
        }
    }
}
// elimincion de gauss
    for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
        double f = mat[j][i] / mat[i][i];
        for (k = 0; k < n + 1; k++) {
            mat[j][k] = mat[j][k] - f * mat[i][k];
            }
        }
    }
// despeje
    for (i = n - 1; i >= 0; i--){
        //despeja la beta
        beta[i] = mat[i][n];
        for (j = i + 1; j < n; j++) {
        if (i != j) {
            beta[i] = beta[i] - mat[i][j] * beta[j];
            }
        }
        beta[i] = beta[i] / mat[i][i];
        setB3(beta[3]);
        setB2(beta[2]);
        setB1(beta[1]);
        setB0(beta[0]);
    }

}
#endif /* File_h */
