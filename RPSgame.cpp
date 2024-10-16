#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

/*
Program: Sten, Sax, Påse

1. Be användaren att välja mellan "sten", "sax" eller "påse".
   - Använd cin för att läsa in användarens picks.
   - Hantera stora och små bokstäver om användaren skriver in pickset.

2. Generera ett slumpmässigt picks för datorn.
   - Använd srand och rand för att skapa ett slumpmässigt tal.
   - Associera talen med "sten", "sax" eller "påse".

3. Jämför användarens picks med datorns picks.
   - Om användaren och datorn har samma picks, är det oavgjort.
   - Sten slår sax, sax slår påse, påse slår sten.
   - Avgör vinnaren baserat på dessa regler.

4. Visa resultatet av spelet.
   - Skriv ut användarens picks och datorns picks.
   - Skriv ut vem som vinner, eller om det blev oavgjort.
*/






void stringtolower(char * pointer);

enum MOVES{
    STEN = 0,
    SAX = 1,
    PÅSE = 2,
};

int main()

{   
    srand(time(NULL));
    int computerchoice = 0;
    int user_score = 0, computer_score = 0;
    char userchoice[128];
    int total_plays = 0, user_wins = 0, computer_wins = 0;
    int computerpicks[3] = {0}, userpicks[3] = {0}; 
    const char * picks[3] = {"sten","sax","påse"};
    
    while(1)
    {   int programchoice;
        cout << "Skriv in 0 för att starta spelet: \n"
           << "Skriv in 1 för att visa statistik: \n"
           << "Skriv in 2 för att avsluta spelet: \n";
        cin >> programchoice;

        if (programchoice == 0)
        {
            while (1)
            {
                cout << "Välj mellan Sten Sax eller Påse: \n";
                cin >> userchoice; cout <<"\n";

                stringtolower(userchoice);

                cout << userchoice << "\n";

                computerchoice = rand()%3;
                cout << picks[computerchoice] << "\n";
                int playerchoice = -1;
            
            if (strcmp(userchoice, picks[0]) == 0)
            {
                playerchoice = 0;
            }   
            else if (strcmp(userchoice, picks[1]) == 0)
            {      
                playerchoice = 1;
            }
            else if (strcmp(userchoice, picks[2]) == 0)
            {
                    playerchoice = 2;
            }        
            else
            {
                cout << "Du matade in fel" << "\n";
            }
            
            computerpicks[computerchoice] ++ ;
            userpicks[playerchoice] ++ ;

            if (playerchoice == computerchoice)
            {
                cout << "Oavgjort"<< "\n";
            }

            else
            {   
                int winner = (3 + playerchoice - computerchoice) % 3;

                    if (winner == 1)
                    {
                        user_score ++;
                    }
                    else if (winner == 2)
                    {  
                        computer_score ++;
                    
                    }

                /*if (playerchoice == STEN && computerchoice == SAX)
                {
                    user_score ++;
                }
                if (playerchoice == STEN && computerchoice == PÅSE)
                {
                    computer_score ++;
                }
                if (playerchoice == SAX && computerchoice == PÅSE)
                {
                    user_score ++;
                }
                if (playerchoice == SAX && computerchoice == STEN)
                {
                    computer_score ++;
                }
                if (playerchoice == PÅSE && computerchoice == SAX)
                {
                    computer_score ++;
                }
                if (playerchoice == PÅSE && computerchoice == STEN)
                {
                    user_score ++;
                }*/

            }

                if (user_score >= 3 || computer_score >= 3 )
                {
                    if (user_score > computer_score)
                    { 
                        cout << "Spelaren vann med: " << user_score << "Poäng"<< "\n";
                        user_wins ++;
                    }
                    else
                    {
                        cout << "Datorn vann med: " << computer_score << "Poäng"<< "\n";
                        computer_wins ++ ;
                    }
                    break;
                }

            }
        }
        else if (programchoice == 1)
        {   
            cout <<"Här är statistiken för spelaren\n"
                 << "********************************\n"
                 << "Vinster:  " << user_wins << "\n";

            for (int j = 0; j < 3; j++)
            {   
                cout << picks[j] << ' ' << userpicks[j] << "\n";
            }

            cout <<"Här är statistiken för dator\n"
                 << "********************************\n"
                 << "Vinster:  " << computer_wins << "\n";

            for (int j = 0; j < 3; j++)
            {   
                cout << picks[j] << ' ' << computerpicks[j] << "\n";
            }
        }
        else
        {
            break;
        }
    }


}





void stringtolower(char * pointer)
{   int length;
    length = strlen(pointer);

    for (int i = 0; i < length; i++)
    {
        char c = pointer[i];
        if ( c >= 'A' && c <= 'Z')
            pointer[i] += 32;

        



    }
}

//En funktion som kör rockpaper siccor spelet.

//Funktion computer choice

//funktion för statsitk: hur många gånger har datorn pickst x hur många gånger har användaren pickst x. hur många poäng.
//hur många gånger datorn har vunnit hur många gånger spelaren har vunnit. 

//En funktion för vem som vann.

