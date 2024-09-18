#include <iostream>
#include <string>

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
    cin >> numGU;
}
void GestionContenidos()
{
    cout << "2. Gestió continguts" << "\n" <<
            "   1. Gestió pel·lícules" << "\n" <<
            "   2. Gestió sèries" << "\n" <<
            "   3. Tornar" << endl;
    int numGC;
    cout << "Escriba uno de los numero del menu Gestió continguts" << endl; 
    cin >> numGC;    
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
    cin >> numC;
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
        cout << "Escriba uno de los numero del menu" << endl; 
    }
    cout << "Bye bye" << endl;
    return 0;
}
