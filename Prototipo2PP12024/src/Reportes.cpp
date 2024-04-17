#include "Reportes.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

void sistema::menuPrincipal()  //Creación del constructor menuPrincipal
{
    int opcion;
	char x;
	do
    {
	system("cls"); //Limpia pantalla

    //Menú para el modificación e ingreso de Jugadores
	cout<<"\t\t\t---------------------------------"<<endl;
	cout<<"\t\t\t |   Menu para crear un sistema  |"<<endl;
	cout<<"\t\t\t---------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso sistema"<<endl;
	cout<<"\t\t\t 2. Despliegue sistema"<<endl;
	cout<<"\t\t\t 3. Modifica sistema"<<endl;
	cout<<"\t\t\t 4. Buscar sistema"<<endl;
	cout<<"\t\t\t 5. Borrar sistemas"<<endl;
	cout<<"\t\t\t 6. Salir del Menu"<<endl;

	cout<<"\t\t\t---------------------------------------"<<endl;

	cout<<"Ingresa una Opcion: ";
    cin>>opcion;

    //Elegir una opcion del Menu
    switch(opcion)
    {
    case 1:
        agregarDatos();
		break;
	case 2:
		mostrarDatos();
		break;
	case 3:
		modificarDatos();
		break;
	case 4:
		buscarDatos();
		break;
	case 5:
		borrarDatos();
		break;
	case 6:
		exit(0);
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		}
	getch();
    }while(opcion!= 6);

}

 void sistema::agregarDatos()      //Constructor de la clase Jugador, agregarDatos
{
	system("cls");      //limpia pantalla
	fstream file;       //creacion variable file de la libreria fstream
	cout<<"\n-----------------------------------------------------------------------------------------------";
	cout<<"\n------------------------------------------------- Agregar sistema ----------------------------"<<endl;
	//Ingreso de datos
	cout<<"\t\t\tIngresa ID del sistema     : ";
	cin>>id;
	cout<<"\t\t\tIngresa Nombre del sistema : ";
	cin>>nombre;
	cout<<"\t\t\tIngresa codigo sistema           : ";
	cin>>codigo;
	cout<<"\t\t\tIngresa la Contraseña      : ";
	cin>>contrasena;

	//Abre archivo y luego lo ve al final de la salida
	file.open("File.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< "id: "+id <<std::left<<std::setw(15)<<"Nombre: "+ nombre <<std::left<<std::setw(15)<<"Codigo: " + codigo <<std::left<<std::setw(15)<< "Contraseña: " +contrasena << "\n";
	file.close();   //Cierra el archivo
}

 void sistema::mostrarDatos()        //Creación del constructor de la clase Jugador, mostrarDatoses
{
	system("cls");  //limpia pantalla
	fstream file;   //crea
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de sistema -------------------------"<<endl;
	file.open("File.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> id >> nombre >> codigo >> contrasena;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Id del sistema: "<<id<<endl;
			cout<<"\t\t\t Nombre del sistema: "<<nombre<<endl;
			cout<<"\t\t\t codigo del sistema: "<<codigo<<endl;
			cout<<"\t\t\t Contraseña del sistema: "<<contrasena<<endl;
			file >> id >> nombre >> codigo >> contrasena;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay sistema...";
		}
	}
	file.close();
}

 void sistema::modificarDatos()  //Creacion de la clase Jugador, modificarDatoses
{
	system("cls");
	fstream file,file1;
	string jugador_id;
	int found=0;
	cout<<"\n------------------------- \"Modificacion Detalles sistema\" -------------------------"<<endl;
	file.open("File.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese ID del sistema que quiere modificar: ";
		cin>>jugador_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> id >> nombre >> codigo >> contrasena;
		while(!file.eof())
		{
			if(jugador_id!=id)
			{
			 file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< codigo <<std::left<<std::setw(15)<< contrasena << "\n";
			}
			else
			{
				cout<<"\t\t\tIngrese Id del sistema: ";
				cin>>id;
				cout<<"\t\t\tIngrese Nombre del sistema: ";
				cin>>nombre;
				cout<<"\t\t\tIngrese codigo del sistema: ";
				cin>>codigo;
				cout<<"\t\t\tIngrese la contraseña del sistema: ";
				cin>>contrasena;
                file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< codigo <<std::left<<std::setw(15)<< contrasena << "\n";
				found++;
			}
			file >> id >> nombre >> codigo >> contrasena;

		}
		file1.close();
		file.close();
		remove("File.txt");
		rename("Record.txt","File.txt");
	}
}

 void sistema::buscarDatos()       //Creacion de la clase , buscarDatos
{
	system("cls");
	fstream file;
	int found=0;
	file.open("File.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos del sistema buscado------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string jugador_id;
		cout<<"\n-------------------------Datos del sistema buscado------------------------"<<endl;
		cout<<"\nIngrese Id del sistema que quiere buscar: ";
		cin>>jugador_id;
		file >> id >> nombre >> codigo >> contrasena;
		while(!file.eof())
		{
			if(jugador_id==id)
			{
				cout<<"\n\n\t\t\t ID sistema: "<<id<<endl;
				cout<<"\t\t\t Nombre sistema: "<<nombre<<endl;
				cout<<"\t\t\t codigo sistema: "<<codigo<<endl;
				cout<<"\t\t\t Contraseña sistema: "<<contrasena<<endl;
				found++;
			}
			file >> id >> nombre >> codigo >> contrasena;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t sistema no encontrado...";
		}
		file.close();
	}
}

 void sistema::borrarDatos()       //Creacion constructor de la clase Jugador, borrarDatos
{
	system("cls");
	fstream file,file1;
	string jugador_id;
	int found=0;
	cout<<"\n-------------------------Detalles del sistema a Borrar-------------------------"<<endl;
	file.open("File.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id del sistema que quiere borrar: ";
		cin>>jugador_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> id >> nombre >> codigo >> contrasena;
		while(!file.eof())
		{
			if(jugador_id!= id)
			{
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< codigo <<std::left<<std::setw(15)<< contrasena << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado del sistema exitoso";
			}
			file >> id >> nombre >> codigo >> contrasena;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id del sistema no encontrado...";
		}
		file1.close();
		file.close();
		remove("File.txt");
		rename("Record.txt","File.txt");
	}
}

bool sistema::login()
{
    string usuario, contra;
    int contador=0;
    bool ingresa=false;
    do{
        system("cls");
        cout<<"--------------------------"<<endl;
        cout<<"AUTENTICACION DE USUARIOS "<<endl;
        cout<<"--------------------------"<<endl;
        cout<<"Codigo de usuario: ";
        getline(cin, usuario);
        cout<<"\ncontrasena: ";
        char caracter;
        caracter= getch();
        contra="";
        while (caracter !=13)
        {
            if(caracter !=8)
            {
                contra.push_back(caracter);
                cout<<"*";
            } else
            {
                if (contra.length() > 0)
                {
                    cout<<"\b \b";
                    contra = contra.substr(0, contra.length()-1);
                }
            }
            caracter = getch();
        }

        if (buscarlogin(usuario, contra)){
            ingresa=true;
        } else {
            cout<<"\nEl usuario y/o contrasena son incorrectos"<<endl;
            cin.get();
            contador++;
        }
    } while (ingresa==false && contador<3);
    if (ingresa==false){
        cout<<"\nLo siento, no puede ingresar al sistema, sus credenciales son invalidas o agoto intentos"<<endl;
        cin.get();
    } else {
        cout<<"\n=== Bienvenido al Sistema ==="<<endl;
        cin.get();
    }
    return ingresa;
}

bool sistema::buscarlogin(string user, string passw)
{
    system ("cls");
    fstream file;
    int found=0;
    file.open("File.txt", ios::in);
    if (!file)
    {
        cout<<"\n---------------------------Datos del sistema buscado----------------------"<<endl;
        cout<<"\n\t\t\tNo hay informacion...";

         file.close();
            file.open("File.txt", ios::out);
            if (file.is_open()) {
                file << "usuario: admin\n";
                file << "contraseña: 123\n";
                cout << "Archivo creado con éxito.\n";


            } else {
                cout << "No se pudo crear el archivo.\n";
            }

    }
    else
    {
        file >> id >> nombre >> codigo >> contrasena;
        while(!file.eof())
        {
            if(user==nombre)
            {
                if (passw == contrasena)
                {
                    found++;
                }
            }
            file >> id >> nombre >> codigo >> contrasena;
        }
        if(found==0)
        {
            return false;
        }
        else
            return true;

        file.close();}
}
