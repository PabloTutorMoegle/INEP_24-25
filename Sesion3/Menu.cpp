#include <iostream>
#include <string>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>
#include <mysql_driver.h>

#include "CapaDePresentacio.hpp"

using namespace std;

void GestionUsuarios()
{
    cout << "1. Gestió usuari" << "\n" <<
            "   1. Registre usuari" << "\n" <<
            "   2. Consulta usuari" << "\n" <<
            "   3. Modifica usuari" << "\n" <<
            "   4. Esborra usuari" << "\n" <<
            "   5. Tornar" << endl;
    int numGU;
    cout << "Escriba uno de los numero del menu Gestió usuari" << endl; 
    cout << "-----------------------------" << endl;

    cin >> numGU;

    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    
    switch (numGU)
    {
    case 1:
        presentacio.registraUsuari();
        break;
    case 2:
        presentacio.consultaUsuari();
        break;
    case 3:
        presentacio.modificaUsuari();
        break;
    case 4:
        presentacio.eliminarUsuari();
        break;
    case 5:
        break;
    default:
        cout << "Ese numero no es valido." << endl;
        break;
    }
    cout << "1. Gestió usuari" << "\n" <<
            "   1. Registre usuari" << "\n" <<
            "   2. Consulta usuari" << "\n" <<
            "   3. Modifica usuari" << "\n" <<
            "   4. Esborra usuari" << "\n" <<
            "   5. Tornar" << endl;
    cout << "Escriba uno de los numero del menu Gestió usuari" << endl; 
    cout << "-----------------------------" << endl;
}

int main()
{
    string entrada;
    int num;

    cout << "1. Gestió usuaris" << "\n" <<
            "2. Gestió continguts" << "\n" <<
            "3. Consultes" << "\n" <<
            "4. Sortir" << endl;
    
    cout << "Escriba uno de los numero del menu" << endl; 

    while (cin >> num && num != 4)
    {    
        if(num == 1)
        {
            GestionUsuarios();  
        }
        else if (num == 2)
        {
            //GestionContenidos();
            cout << "GestionContenidos" << endl;
        }
        else if (num == 3)
        {
            //Consultas();
            cout << "Consultas" << endl;
        }
        else
        {
            cout << "Numero no valido" << endl;
        }
        cout << "-----------------------------" << endl;
        cout << "1. Gestió usuaris" << "\n" <<
                "2. Gestió continguts" << "\n" <<
                "3. Consultes" << "\n" <<
                "4. Sortir" << endl;
        
        cout << "Escriba uno de los numero del menu" << endl; 
    }
    cout << "Bye bye" << endl;
    return 0;
}


/*
void GestionContenidos()
{
    cout << "2. Gestió continguts" << "\n" <<
            "   1. Gestió pel·lícules" << "\n" <<
            "   2. Gestió sèries" << "\n" <<
            "   3. Tornar" << endl;
    int numGC;
    cout << "Escriba uno de los numero del menu Gestió continguts" << endl; 
    while (cin >> numGC && numGC != 3)
    {
        if (numGC > 3)
        {
            cout << "Ese numero no es valido." << endl;
        }
        else 
        {
            cout << "Algo pasa al clickar el " << numGC << endl;
        }
        cout << "2. Gestió continguts" << "\n" <<
                "   1. Gestió pel·lícules" << "\n" <<
                "   2. Gestió sèries" << "\n" <<
                "   3. Tornar" << endl;
        cout << "Escriba uno de los numero del menu Gestió continguts" << endl; 
    }
    cout << "-----------------------------" << endl;
}

void Consultas()
{
    cout << "3. Consultes" << "\n" <<
            "   1. Consulta per qualificació d'edat" << "\n" <<
            "   2. Últimes novetats" << "\n" <<
            "   3. Pròximes estrenes" << "\n" <<
            "   4. Tornar" << endl;
    int numC;
    cout << "Escriba uno de los numero del menu Consultes" << endl; 
    while (cin >> numC && numC != 4)
    {
        if (numC > 4)
        {
            cout << "Ese numero no es valido." << endl;
        }
        else 
        {
            cout << "Algo pasa al clickar el " << numC << endl;
        }
        cout << "3. Consultes" << "\n" <<
                "   1. Consulta per qualificació d'edat" << "\n" <<
                "   2. Últimes novetats" << "\n" <<
                "   3. Pròximes estrenes" << "\n" <<
                "   4. Tornar" << endl;

        cout << "Escriba uno de los numero del menu Consultes" << endl; 
    }
    cout << "-----------------------------" << endl;
}
*/