#include "main.h"


/* Menú principal */
int main(int argc, char const *argv[])
{

    /* Inicializar el generador de números aleatorios */
    srand (time(NULL));

    /* variable que almacenará la contraseña aleatoria */
    string password;

    /* Varible que almacenará la longitud de la contraseña */
    size_t size_password = (rand() % 40) + 20;


    for (size_t i = 0; i < size_password; i++)
    {
        /* Generamos aleatoriamente la contraseña */
        password += data_password[rand() % total_caracteres];
    }


    /* Mostrar resultado */
    cout << "-------------------------------" << endl;
    cout << " Generador de Passwords " << endl;
    cout << "-------------------------------" << endl;
    cout << "Password: " << password << endl;
    cout << "Longitud: " << password.length() << endl;
    cout << "Robustez: Muy fuerte" << endl;
    cout.precision(3);
    cout << "Entropia de Shannon: " << entropia(password) << endl; 
    cout << "-------------------------------" << endl;

    return 0;
}
