#ifndef _Functions_h
#define _Functions_h

#define ledig 0
#define upptagen 1

typedef struct {
	int bussinessS[2][6];  // Matris för lagring av lediga/ upptagna platser i Affärsklass Special
	int bussiness[8][6];   // Matris för lagring av lediga/ upptagna platser i Affärsklass
	int economyS[3][6];    // Matris för lagring av lediga/ upptagna platser i Ekonomiklass Special
	int economy[17][6];    // Matris för lagring av lediga/ upptagna platser i Ekonomiklass
	int bussiS[2][6];   // Lagras numrering av platserna i Affärsklass Special
	int bussi[8][6];    // Lagras numrering av platserna i Affärsklass
	int ecoS[3][6];     // Lagras numrering av platserna i Ekonomiklass Special
	int eco[17][6];     // Lagras numrering av platserna i Ekonomiklass

} seats;

typedef struct {
	int bussinessOrEconomy;            // I "bussinessOrEconomy", "numOfSeats", "windowOrMiddle" och "special" lagras användarens inmatning
	int numOfSeats;
	int windowOrMiddle;
	char special;
	char fortsatta;          // Alternativet av om man vill fortsätta till sökningen lagras här
} choice;

void introBanner();    // Introduktions banner till boknings programmet
seats randomizeSeats();   // .txt fil skapas med överblick av planet. Slumptal samt platsnummer skickas till structen "seats"
int mainMenu();             // Meny för de tre valen ("Reservera plats", "Överblick på lediga platser" och "Avsluta"
choice reserveSeats();      // Här matas användarens kriterier in
int seeSeats(seats randomSeats);        // Överblick över vilka platser som är lediga och vilka som är upptagna
seats suggest(choice kriterier, seats a);   // "sökningsfunktionen" Söker lediga platser beroende på användarens kriterier.

#endif