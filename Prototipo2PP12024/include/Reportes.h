#ifndef REPORTES_H
#define REPORTES_H


#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>
using namespace std;

class sistema       //Clase Sistema
{
    public: //constructores para la clase
        void menuPrincipal();
        void agregarDatos();
        void mostrarDatos();
        void modificarDatos();
        void buscarDatos();
        void borrarDatos();
        bool login();
        bool buscarlogin(string user, string passw);




    protected:

    private:    //Atributos privados y protegidos
        string id;
        string nombre;
        string codigo;
        string contrasena;

};


#endif // REPORTES_H
