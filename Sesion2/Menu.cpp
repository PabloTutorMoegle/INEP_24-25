#include <iostream>
#include <string>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>
#include <mysql_driver.h>

using namespace std;

void procesarRegistroUsuario()
{
    string alias, nombre;
    cout << "Escriba su alias: ";
    cin >> alias;
    cout << "Escriba su nombre completo: ";
    cin >> nombre;

    if (alias.empty() || nombre.empty())
    {
        cout << "Usuario no registrado por falta de datos." << endl;
    }
    else
    {
        cout << "El registre de l'usuari " << nombre << " (" << alias << ") " << 
            "s'ha processat correctament" << endl;
    }
}

void cosnultarUsuario()
{
    sql::mysql::MySQL_Driver *driver = NULL;
    sql::Connection *con = NULL;
    sql::Statement *stmt = NULL;

    try
    {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("ubiwan.epsevg.upc.edu:3306", "inep11", "gahKaek6choo2a");
        con->setSchema("inep11");
        stmt = con->createStatement();

        string sobrenom_usuari;
        cout << "Escriba el sobrenom del usuario: ";
        cin >> sobrenom_usuari;

        string sql = "SELECT * FROM Usuari WHERE sobrenom = 'sobrenom_usuari'";
        sql::ResultSet *res = stmt->executeQuery(sql);

        if (res->next())
        {
            cout << "----------" << "\n"
            << "Sobrenom: " << res->getString("sobrenom") << "\n"
            << "Nom: " << res->getString("nom") << "\n"
            << "Correu electronic: " << res->getString("correu_electronic") 
            << endl;
        }
        else
        {
            cout << "----------" << "\n"
            << "No s'ha trobat cap usuari amb aquest sobrenom." << endl;
        }
        cout << "----------" << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "SQL Error: " << e.what() << endl;
        if(con != NULL) con->close();
    }    
}

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
    while (cin >> numGU && numGU != 5)
    {
        if (numGU == 1)
        {
            procesarRegistroUsuario();
        }
        if (numGU == 2)
        {
            cosnultarUsuario();
        }
        else if (numGU > 5)
        {
            cout << "Ese numero no es valido." << endl;
        }
        else 
        {
            cout << "Algo pasa al clickar el " << numGU << endl;
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
// editado por Guillem-Sancho
