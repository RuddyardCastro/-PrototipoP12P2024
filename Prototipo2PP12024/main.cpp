#include <Reportes.h>
#include <iostream>
#include <unistd.h>


using namespace std;

int main()
{


    bool accesoUsuario;
    sistema usuarioRegistrado;
    accesoUsuario = usuarioRegistrado.login();
    if (accesoUsuario)
        {
    int opciones;
    bool repetir = true;
    do
    {
        //Limpia pantalla
        system("cls");
        //imprime en pantalla
        cout << "\n\n\t\t\-------Menu Ruddyard Eduardo Castro Chavez 9959-23-1409------" << endl;
        cout << "\t\t-------------------"<< endl;

        cout << "\t\t1. Ingresar Sistema" << endl;
        cout << "\t\t2. Salir del sistema" << endl;
        cout << "\n\t\tIngrese una opcion: ";
        cin >> opciones;
        //Un switch para crear el meno tipo do while
        switch (opciones)
        {
            //Si opciones es igual a 1 entonces
        case 1:
            {
                sistema usuario;
                usuario.menuPrincipal();

                //Se crea una pausa
                system("pause");
                break;
            }
            //si opciones es igual a 2  entonces
        case 2 :repetir = false;



            break;



        }
    } while (repetir);
    }
    system("cls");      //Limpia la pantalla

    return 0;
}

