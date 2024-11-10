#include <iostream>
#include <string>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>
#include <mysql_driver.h>

#include "ConnexioDB.hpp"

using namespace std;

void GestionUsuarios()
{
    ConnexioDB connexioDB;

    cout << "1. Gestió usuari" << "\n" <<
            "   1. Registre usuari" << "\n" <<
            "   2. Consulta usuari" << "\n" <<
            "   3. Modifica usuari" << "\n" <<
            "   4. Esborra usuari" << "\n" <<
            "   5. Tornar" << endl;
    int numGU;
    cout << "Escriba uno de los numero del menu Gestió usuari" << endl; 
    while (cin >> numGU && numGU != 5)
    {
        if (numGU == 1)
        {
            string sobrenom_usuari;
            string nom_usuari;
            string correu_electronic_usuari;

            cout << "Escriba el sobrenom del usuario: ";
            cin >> sobrenom_usuari;
            cout << "Escriba el nom del usuario: ";
            //el nombre del usuario puede tener espacios
            cin.ignore();
            getline(cin, nom_usuari);
            cout << "Escriba el correu electronic del usuario: ";
            cin >> correu_electronic_usuari;

            string sql = "INSERT INTO Usuari (sobrenom, nom, correu_electronic) VALUES ('" + sobrenom_usuari + 
            "', '" + nom_usuari + "', '" + correu_electronic_usuari + "')";
            try
            {
                connexioDB.procesarRegistroUsuario(sql);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        if (numGU == 2)
        {
            string sobrenom_usuari;
            cout << "Escriba el sobrenom del usuario: ";
            cin >> sobrenom_usuari;

            string sql = "SELECT * FROM Usuari WHERE sobrenom = '" + sobrenom_usuari + "'";
            try
            {
                connexioDB.cosnultarUsuario(sql);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        if (numGU == 3)
        {
            string sobrenom_usuari;
            cout << "Escriba el sobrenom del usuario: ";
            cin >> sobrenom_usuari;

            string sql = "SELECT * FROM Usuari WHERE sobrenom = '" + sobrenom_usuari + "'";

            try
            {
                connexioDB.modificaUsuario(sql);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        if (numGU == 4)
        {
            string sobrenom_usuari;
            cout << "Escriba el sobrenom del usuario: ";
            cin >> sobrenom_usuari;

            string sql = "DELETE FROM Usuari WHERE sobrenom = '" + sobrenom_usuari + "'";

            try
            {
                connexioDB.eliminarUsuario(sql);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        if (numGU > 5)
        {
            cout << "Ese numero no es valido." << endl;
        }
        cout << "1. Gestió usuari" << "\n" <<
                "   1. Registre usuari" << "\n" <<
                "   2. Consulta usuari" << "\n" <<
                "   3. Modifica usuari" << "\n" <<
                "   4. Esborra usuari" << "\n" <<
                "   5. Tornar" << endl;
        cout << "Escriba uno de los numero del menu Gestió usuari" << endl; 
    }
    cout << "-----------------------------" << endl;
    connexioDB.~ConnexioDB();
}

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
            GestionContenidos();
        }
        else if (num == 3)
        {
            Consultas();
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
