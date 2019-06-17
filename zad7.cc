#include <omp.h>
#include <iostream>
#include <string>
using namespace std;

int main () {

string buf;
char c = 'a';

// Stworz i zainicjalizuj obiekt typu omp_lock_t
// Nastepnie zabezpiecz za jego pomoca
// operacje w sekcjach, na koniec 
// zwolnij zasoby obiektu omp_lock_t

#pragma omp parallel num_threads(2)
{
    #pragma omp sections nowait
    {
       #pragma omp section
       {
          buf += c++;
       }

       #pragma omp section
       {
          buf += c++;
       }
    }  
}  

cout << buf << endl;
}
