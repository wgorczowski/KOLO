#include <omp.h>
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void fun( int t ) {
  this_thread::sleep_for(chrono::milliseconds(t));
}

int main () {

    // Dopisz ponizej linie mierzace czas wykonania petli
    // i wypisz wynik na koncu

    omp_set_num_threads(8);

    // tu poczatek pomiaru

    #pragma omp for 
      for (int i=0; i<20; ++i) fun(i);

    // tu koniec pomiaru
    // wypisz czas trwania cout << 

}

