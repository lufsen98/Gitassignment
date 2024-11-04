
#include <iostream>

using namespace std;

//pointers.
int main()
{    // deklarerar och intierar variabler och pekare.
     int k=15, n;
     // deklarerar variablerna med pekare av typen int.
     int *pi, *pi2;
     //pi pekar på adressen till k
     pi = &k;
     //pi2 pekar på adressen till n
     pi2 = &n;
     //det som pi2 pekar på får värdet som pi pekar på.
     *pi2 = *pi;
     
     //pi2 pekar nu på samma adress som pi.
     pi2 = pi;
     //skriver ut adressens som pi2 pekar på
     cout << pi2 << '\n';
     //skriver ut vilket värde pi2 innehåller.
     cout << *pi2 << '\n';

     
}