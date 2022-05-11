#include <iostream> // printf, NULL 
#include <cstdlib>  // srand, rand 
#include <ctime>    // time 
#include <cmath>    //log2
#include <set>      //entropia
#include <vector>   //entropia


using namespace std; 


/* Carácteres para generar la contraseña aleatoriamente */
const string data_password =    "abcdefghijklmnopqrstuvwxyz"
                                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                "1234567890"
                                "!#$%&'()*+,-./:;<=>?@[]^_`{|}~";  


/* Total de caracteres "data_password" */
const size_t total_caracteres = data_password.length();


/* Calcular Entropia de Shannon*/ 
double entropia(string& st) 
{
    vector<char> stvec(st.begin(), st.end());
    set<char> alphabet(stvec.begin(), stvec.end());
    vector<double> freqs;
    for (set<char>::iterator c = alphabet.begin(); c != alphabet.end(); ++c) 
    {
        int ctr = 0;
        for (vector<char>::iterator s = stvec.begin(); s != stvec.end(); ++s) 
        {
            if (*s == *c) 
            {
                ++ctr;
            }
        }
        freqs.push_back((double)ctr / (double)stvec.size());
    }
    double ent = 0;
    double ln2 = log(2);
    for (vector<double>::iterator f = freqs.begin(); f != freqs.end(); ++f) 
    {
        ent += *f * log(*f)/ln2;
    }
    ent = -ent;
    return ent;
}
