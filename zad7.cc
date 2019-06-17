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

#pragma omp init_lock(omp_lock_t *lock)    
#pragma omp parallel num_threads(2)
{
    #pragma omp sections nowait
    { 
       #pragma omp section
       #pragma omp set_lock(omp_lock_t *lock)
       {
          buf += c++;
       }
       #pragma omp unset_lock(omp_lock_t *lock) 
       #pragma omp section
       #pragma omp set_lock(omp_lock_t *lock)
       {
          buf += c++;
       }
       #pragma omp unset_lock(omp_lock_t *lock)
    }  
}  

cout << buf << endl;
}
