#include "main.h"


int main(int argc, char const *argv[])
{
    
    // Argumentos del terminal
    if (argc != 2) 
    {
        std::cerr << "[!]Uso: " << argv[0] << " <Longitud de la contraseña>\n";
        return 1;
    }
    
    //Inicializar el generador de números aleatorios
    srand(time(0) );
    
    // Comprobar rango de entrada 32 bits
    int longitud = stoi(argv[1]);
    
    if (longitud <= 0 || longitud >= 2147483646)
    {
        std::cerr << "[!]Error: la longitud debe ser mayor que 0 o menor que 2147483646\n";
        return 1;
    }
    
    // Llamadas a funciones
    string contrasena = generarContrasena(longitud);
    double entropia = calcularEntropia(contrasena);
    string clasificacion = clasificarContrasena(entropia);
    
    // Mensaje al usuario por terminal 
    cout << "-------------------------------"  << endl;
    cout << " Generador de Passwords v1.2"     << endl;
    cout << "-------------------------------"  << endl;
    std::cout << "Contraseña: " << contrasena  << "\n";
    std::cout << "Entropía: " << entropia      << "\n";
    std::cout << "Robustez: " << clasificacion << "\n";
    
    // Copiar contraseña al portapapeles
    copiarAlPortapapeles(contrasena);
    

    return 0;
}
