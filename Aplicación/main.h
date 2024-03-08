#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>


using namespace std; 


/* Carácteres para generar la contraseña aleatoriamente */
const string CARACTERES = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789*!{}[]()@#<>-_";

/* Calcular Entropia de la contraseña */
const double ENTROPIA_DEBIL = 40.0;
const double ENTROPIA_MEDIA = 60.0;

string generarContrasena(int longitud)
{
    string contrasena = "";
    
    for (int i = 0; i < longitud; i++)
    {
        contrasena += CARACTERES[rand() % CARACTERES.size()];
    }
    
    return contrasena;
}

double calcularEntropia(string contrasena)
{
    return contrasena.length() * log2(CARACTERES.size() );
}

string clasificarContrasena(double entropia)
{
    if (entropia <= ENTROPIA_DEBIL)
    {
        return "Débil";
    } else if (entropia <= ENTROPIA_MEDIA)
    {
        return "Media";
    } else 
    {
        return "Fuerte";
    }
}


/* Copiar la contraseña al portapapeles: WINDOWS + MAC + LINUX */
void copiarAlPortapapeles(string contrasena) 
{
    string comando;
    
    
    #if defined(_WIN32)
        comando = "echo " + contrasena + " | clip";
    #else
        comando = "echo '" + contrasena + "' | pbcopy";
    #endif
    
    
    if (!system(comando.c_str() ) )
        {
            cout << "\n[*] Contraseña copiada al portapapeles.\n";
        } else 
        {
            cerr << "[!]Error: al copiar la contraseña al portapapeles.\n";
        }
}