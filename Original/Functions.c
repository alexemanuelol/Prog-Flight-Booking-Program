#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Functions.h"

void introBanner()                                                                                                                                // giveInstructions
{
	printf("#########################################################\n##                                                     ##\n");
	printf("##  Hej och välkommen till ProgFlygs bokningsprogram!  ##\n##                                                     ##\n");
	printf("#########################################################\n\n");
}

seats randomizeSeats()                                                                                                                                   // randomizeSeats
{
	seats matrisDelar;
	FILE * seat;
	srand((int)time(NULL));
	seat = fopen("PrintPlatser.txt", "w"); fclose(seat);    // FILEN SKAPAS
	seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "             Bussiness Class:\n              Special Seats\n"); fclose(seat);

	/* SPECIAL SEATS BUSSINESS */
	int count = 1, rowNum = 1, platsNum = 1;
	for (int r = 0; r < 2; r++)
	{
		for (int c = 0; c < 6; c++)
		{
			matrisDelar.bussinessS[r][c] = (rand() % (upptagen - ledig + 1)) + ledig;    //SLUMPMÄSSIGA TAL (1 eller 0) skickas till matrisen i "seats" för varje sektion i planet.
			if (platsNum < 10)
				seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "(  %d) ", platsNum); fclose(seat);       // Platsnummer printas ut till .txt filen.
			if (platsNum >= 10)
				seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "( %d) ", platsNum); fclose(seat);
			if (platsNum >= 100)
				seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "(%d) ", platsNum); fclose(seat);
			if (c == 2)
				seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "\t"); fclose(seat);
			if (c == 5) {
				seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "   Rad %d", rowNum); fclose(seat); rowNum++;
			}
			matrisDelar.bussiS[r][c] = count++;
			platsNum++;
		}
		seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "\n"); fclose(seat);
	}
	seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "               Normal Seats\n"); fclose(seat);
	/* SEATS BUSSINESS */
	count = 1; rowNum = 1, platsNum = 1;
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 6; c++)
		{
			matrisDelar.bussiness[r][c] = (rand() % (upptagen - ledig + 1)) + ledig;  //SLUMPMÄSSIGA TAL (1 eller 0) skickas till matrisen i "seats" för varje sektion i planet.
			if (platsNum < 10)
				seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "(  %d) ", platsNum); fclose(seat);   // Platsnummer printas ut till .txt filen.
			if (platsNum >= 10)
				seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "( %d) ", platsNum); fclose(seat);
			if (platsNum >= 100)
				seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "(%d) ", platsNum); fclose(seat);
			if (c == 2)
				seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "\t"); fclose(seat);
			if (c == 5) {
				seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "   Rad %d", rowNum); fclose(seat); rowNum++;
			}
			matrisDelar.bussi[r][c] = count++;
			platsNum++;
		}
		seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "\n"); fclose(seat);
	}
	seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "\n======================================\n\n              Economy Class:  \n              Special Seats\n"); fclose(seat);
	/* SPECIAL SEATS ECONOMY */
	count = 1, rowNum = 1, platsNum = 1;
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 6; c++)
		{
			matrisDelar.economyS[r][c] = (rand() % (upptagen - ledig + 1)) + ledig;    //SLUMPMÄSSIGA TAL (1 eller 0) skickas till matrisen i "seats" för varje sektion i planet.
			if (platsNum < 10)
				seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "(  %d) ", platsNum); fclose(seat);   // Platsnummer printas ut till .txt filen.
			if (platsNum >= 10)
				seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "( %d) ", platsNum); fclose(seat);
			if (platsNum >= 100)
				seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "(%d) ", platsNum); fclose(seat);
			if (c == 2)
				seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "\t"); fclose(seat);
			if (c == 5) {
				seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "   Rad %d", rowNum); fclose(seat); rowNum++;
			}
			matrisDelar.ecoS[r][c] = count++;
			platsNum++;
		}
		seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "\n"); fclose(seat);
	}
	seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "               Normal Seats\n"); fclose(seat);
	/* SEATS ECONOMY */
	count = 1, rowNum = 1, platsNum = 1;
	for (int r = 0; r < 17; r++)
	{
		for (int c = 0; c < 6; c++)
		{
			matrisDelar.economy[r][c] = (rand() % (upptagen - ledig + 1)) + ledig;     //SLUMPMÄSSIGA TAL (1 eller 0) skickas till matrisen i "seats" för varje sektion i planet.
			if (platsNum < 10)
				seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "(  %d) ", platsNum); fclose(seat);   // Platsnummer printas ut till .txt filen.
			if ((platsNum >= 10) && (platsNum < 100))
				seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "( %d) ", platsNum); fclose(seat);
			if (platsNum >= 100)
				seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "(%d) ", platsNum); fclose(seat);
			if (c == 2)
				seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "\t"); fclose(seat);
			if (c == 5) {
				seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "   Rad %d", rowNum); fclose(seat); rowNum++;
			}
			matrisDelar.eco[r][c] = count++;
			platsNum++;
		}
		seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "\n"); fclose(seat);
	}
	seat = fopen("PrintPlatser.txt", "a"); fprintf(seat, "\n   1     2     3           4     5     6"); fclose(seat);
	return matrisDelar;          // Informationen returneras till main funktionen
}
int mainMenu()                               // HUVUDMENY                                                                                                       // mainMenu
{
	int Val;
	printf("         Huvudmeny\n         =========\n\n");
	printf("Vänligen välj vad som önskas: \n\n");
	printf("(1) Reservera plats \n(2) Överblick på lediga platser \n(3) Avsluta \n\nAlternativ: ");
	fflush(stdin);
	scanf("%d", &Val);

	while (1)
	{
		if (Val == 1)
			break;
		if (Val == 2)
			break;
		if (Val == 3)
			break;
		else
		{
			printf("Ogiltig inmatning!\nVal: ");
			fflush(stdin);
			scanf("%d", &Val);
		}
	}
	system("cls");
	return Val;
}

choice reserveSeats()                                  // ANVÄNDARENS KRAV/ KRITERIER FÖR ÖNSKAD PLATS                                                                                                       // reserveSeats
{
	choice kriterier;
	printf("========================================\nVill du åka i Affärsklass eller Ekonomiklass? \n\n(1) Affärsklass\n(2) Ekonomiklass\n\nVal: ");
	fflush(stdin);
	scanf("%d", &kriterier.bussinessOrEconomy);
	while (1) {
		if (kriterier.bussinessOrEconomy == 1)
			break;
		else if (kriterier.bussinessOrEconomy == 2)
			break;
		else
		{
			printf("Ogiltig inmatning, försök igen.\n");
			fflush(stdin);
			scanf("%d", &kriterier.bussinessOrEconomy);
		}
	}
	printf("========================================\nHur många platser önskas? (1-3): ");
	fflush(stdin);
	scanf("%d", &kriterier.numOfSeats);
	while (1) {
		if (kriterier.numOfSeats == 1)
			break;
		else if (kriterier.numOfSeats == 2)
			break;
		else if (kriterier.numOfSeats == 3)
			break;
		else {
			printf("Ogiltig inmatning, försök igen.\n");
			fflush(stdin);
			scanf("%d", &kriterier.numOfSeats);
		}
	}
	printf("========================================\nÖnskas fönsterplats eller gångplats?\n\n(1) Fönsterplats\n(2) Gångplats\n(3) Spelar ingen roll\n\nVal: ");
	fflush(stdin);
	scanf("%d", &kriterier.windowOrMiddle);
	while (1) {
		if (kriterier.windowOrMiddle == 1)
			break;
		else if (kriterier.windowOrMiddle == 2)
			break;
		else if (kriterier.windowOrMiddle == 3)
			break;
		else {
			printf("Ogiltig inmatning, försök igen.\n");
			fflush(stdin);
			scanf("%d", &kriterier.windowOrMiddle);
		}
	}
	printf("========================================\nÖnskas specialplatser? (y/n)\n(INFO: Rörelsehinder, barn, plats för extra utrymme):  ");
	fflush(stdin);
	scanf("%c", &kriterier.special);
	while (1) {
		if (kriterier.special == 'y')
			break;
		else if (kriterier.special == 'n')
			break;
		else {
			printf("Ogiltig inmatning, försök igen.\n");
			fflush(stdin);
			scanf("%c", &kriterier.special);
		}
	}
	printf("Vill du fortsätta? (y/n): ");
	fflush(stdin);
	scanf("%c", &kriterier.fortsatta);
	while (1) {
		if (kriterier.fortsatta == 'y')
			break;
		else if (kriterier.fortsatta == 'n')
			break;
		else {
			printf("Ogiltig inmatning, försök igen.\n");
			fflush(stdin);
			scanf("%c", &kriterier.special);
		}
	}
	system("cls");
	return kriterier;  // Inmatningen av användaren samlas i structen kriterier som skickas till main funktionen.
}

int seeSeats(seats randomSeats)                 // Visar överblick över lediga/ upptagna platser.                                                                                                          // seeSeats
{
	printf("      Bussiness Class:\n       Special Seats\n");
	/* SPECIAL SEATS BUSSINESS */
	int count = 1, rowNum = 1;
	for (int r = 0; r < 2; r++)
	{
		for (int c = 0; c < 6; c++)
		{
			printf("(%d) ", randomSeats.bussinessS[r][c]);
			if (c == 2)
				printf("\t");
			if (c == 5) {
				printf("   Rad %d", rowNum); rowNum++;
			}
		}
		printf("\n");
	}
	printf("        Normal Seats\n");
	/* SEATS BUSSINESS */
	count = 1; rowNum = 1;
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 6; c++)
		{
			printf("(%d) ", randomSeats.bussiness[r][c]);
			if (c == 2)
				printf("\t");
			if (c == 5) {
				printf("   Rad %d", rowNum); rowNum++;
			}
		}
		printf("\n");
	}
	printf("\n===========================\n\n       Economy Class:  \n       Special Seats\n");
	/* SPECIAL SEATS ECONOMY */
	count = 1; rowNum = 1;
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 6; c++)
		{
			printf("(%d) ", randomSeats.economyS[r][c]);
			if (c == 2)
				printf("\t");
			if (c == 5) {
				printf("   Rad %d", rowNum); rowNum++;
			}
		}
		printf("\n");
	}
	printf("        Normal Seats\n");
	/* SEATS ECONOMY */
	count = 1; rowNum = 1;
	for (int r = 0; r < 17; r++)
	{
		for (int c = 0; c < 6; c++)
		{
			printf("(%d) ", randomSeats.economy[r][c]);
			if (c == 2)
				printf("\t");
			if (c == 5) {
				printf("   Rad %d", rowNum); rowNum++;
			}
		}
		printf("\n");
	}
	printf("\n 1   2   3       4   5   6\n\n");
	system("pause");
	return 0;
}


/* TESTAR */
seats suggest(choice kriterier, seats randomSeats)        // SÖKER EFTER RÄTT KOMBINATION AV KRITERIER
{
	int rowPlus = 1, noSeats = 0;
	while (1)
	{
		if (kriterier.bussinessOrEconomy == 1)
		{
			/* HAR ANVÄNDAREN VALT ATT ÅKA I AFFÄRSKLASS FORTSÄTTER PROGRAMMET IN I DENNA IF SATS */
			if (kriterier.special == 'y')
			{
				if (kriterier.numOfSeats == 1)
				{
					if (kriterier.windowOrMiddle == 1)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 0; columnLeft == 0; columnLeft++)
						{
							for (int row = 0; row <= 1; row++)
							{
								if (randomSeats.bussinessS[row][columnLeft] == 0)
								{
									rowPlus += row;
									printf("Du har blivit placerad på rad %d på plats %d i affärsklass special avdelningen.\n", rowPlus, randomSeats.bussiS[row][columnLeft]);
									randomSeats.bussinessS[row][columnLeft] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						rowPlus = 1;
						for (int columnRight = 5; columnRight == 5; columnRight++)
						{
							for (int row = 0; row <= 1; row++)
							{
								if (randomSeats.bussinessS[row][columnRight] == 0)
								{
									rowPlus += row;
									printf("Du har blivit placerad på rad %d på plats %d i affärsklass special avdelningen.\n", rowPlus, randomSeats.bussiS[row][columnRight]);
									randomSeats.bussinessS[row][columnRight] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga fönsterplatser för dig i affärs special avdelningen!\n"); rowPlus = 1;
						kriterier.windowOrMiddle = 3;
					}
					if (kriterier.windowOrMiddle == 2)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 2; columnLeft <= 3; columnLeft++)
						{
							for (int row = 0; row <= 1; row++)
							{
								if (randomSeats.bussinessS[row][columnLeft] == 0)
								{
									rowPlus += row;
									printf("Du har blivit placerad på rad %d på plats %d i affärsklass special avdelningen.\n", rowPlus, randomSeats.bussiS[row][columnLeft]);
									randomSeats.bussinessS[row][columnLeft] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga mittgångsplatser för dig i affärsklass special avdelningen!\n"); rowPlus = 1;
						kriterier.windowOrMiddle = 3;
					}
					if (kriterier.windowOrMiddle == 3)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 0; columnLeft <= 5; columnLeft++)
						{
							for (int row = 0; row <= 1; row++)
							{
								if (randomSeats.bussinessS[row][columnLeft] == 0)
								{
									rowPlus += row;
									printf("Du har blivit placerad rad %d på plats %d i affärsklass special avdelningen.\n", rowPlus, randomSeats.bussiS[row][columnLeft]);
									randomSeats.bussinessS[row][columnLeft] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns ingen ledig plats för dig i affärsklass special avdelningen!\n"); rowPlus = 1;
						kriterier.special = 'n';
					}
				}
				if (kriterier.numOfSeats == 2)
				{
					if (kriterier.windowOrMiddle == 1)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 0; columnLeft == 0; columnLeft++)
						{
							for (int row = 0; row <= 1; row++)
							{
								if ((randomSeats.bussinessS[row][columnLeft] == 0) && (randomSeats.bussinessS[row][columnLeft + 1] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d och %d i affärsklass special avdelningen.\n", rowPlus, randomSeats.bussiS[row][columnLeft], randomSeats.bussiS[row][columnLeft + 1]);
									randomSeats.bussinessS[row][columnLeft] = 1; randomSeats.bussinessS[row][columnLeft + 1] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						rowPlus = 1;
						for (int columnRight = 4; columnRight == 4; columnRight++)
						{
							for (int row = 0; row <= 1; row++)
							{
								if ((randomSeats.bussinessS[row][columnRight] == 0) && (randomSeats.bussinessS[row][columnRight + 1] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d och %d i affärsklass special avdelningen.\n", rowPlus, randomSeats.bussiS[row][columnRight], randomSeats.bussiS[row][columnRight + 1]);
									randomSeats.bussinessS[row][columnRight] = 1; randomSeats.bussinessS[row][columnRight + 1] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga fönsterplatser för er i affärsklass special avdelningen!\n"); rowPlus = 1;
						kriterier.windowOrMiddle = 3;
					}
					if (kriterier.windowOrMiddle == 2)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 1; columnLeft <= 3; columnLeft++)
						{
							for (int row = 0; row <= 1; row++)
							{
								if ((randomSeats.bussinessS[row][columnLeft] == 0) && (randomSeats.bussinessS[row][columnLeft + 1] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d och %d i affärsklass special avdelningen.\n", rowPlus, randomSeats.bussiS[row][columnLeft], randomSeats.bussiS[row][columnLeft + 1]);
									randomSeats.bussinessS[row][columnLeft] = 1; randomSeats.bussinessS[row][columnLeft + 1] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga mittgångsplatser för er i affärsklass special avdelningen!\n"); rowPlus = 1;
						kriterier.windowOrMiddle = 3;
					}
					if (kriterier.windowOrMiddle == 3)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 0; columnLeft <= 5; columnLeft++)
						{
							for (int row = 0; row <= 1; row++)
							{
								if ((randomSeats.bussinessS[row][columnLeft] == 0) && (randomSeats.bussinessS[row][columnLeft + 1] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d och %d i affärsklass special avdelningen.\n", rowPlus, randomSeats.bussiS[row][columnLeft], randomSeats.bussiS[row][columnLeft + 1]);
									randomSeats.bussinessS[row][columnLeft] = 1; randomSeats.bussinessS[row][columnLeft + 1] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga platser för er i affärsklass special avdelningen!\n"); rowPlus = 1;
						kriterier.special = 'n';
					}
				}
				if (kriterier.numOfSeats == 3)
				{
					if (kriterier.windowOrMiddle == 1)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 0; columnLeft == 0; columnLeft++)
						{
							for (int row = 0; row <= 1; row++)
							{
								if ((randomSeats.bussinessS[row][columnLeft] == 0) && (randomSeats.bussinessS[row][columnLeft + 1] == 0) && (randomSeats.bussinessS[row][columnLeft + 2] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d, %d och %d i affärsklass special avdelningen.\n", rowPlus, randomSeats.bussiS[row][columnLeft], randomSeats.bussiS[row][columnLeft + 1], randomSeats.bussiS[row][columnLeft + 2]);
									randomSeats.bussinessS[row][columnLeft] = 1; randomSeats.bussinessS[row][columnLeft + 1] = 1; randomSeats.bussinessS[row][columnLeft + 2] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						rowPlus = 1;
						for (int columnRight = 3; columnRight == 3; columnRight++)
						{
							for (int row = 0; row <= 1; row++)
							{
								if ((randomSeats.bussinessS[row][columnRight] == 0) && (randomSeats.bussinessS[row][columnRight + 1] == 0) && (randomSeats.bussinessS[row][columnRight + 2] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d, %d och %d i affärsklass special avdelningen.\n", rowPlus, randomSeats.bussiS[row][columnRight], randomSeats.bussiS[row][columnRight + 1], randomSeats.bussiS[row][columnRight + 2]);
									randomSeats.bussinessS[row][columnRight] = 1; randomSeats.bussinessS[row][columnRight + 1] = 1; randomSeats.bussinessS[row][columnRight + 2] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga fönsterplatser för er i affärsklass special avdelningen!\n"); rowPlus = 1;
						kriterier.windowOrMiddle = 3;
					}
					if (kriterier.windowOrMiddle == 2)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 0; columnLeft <= 3; columnLeft++)
						{
							for (int row = 0; row <= 1; row++)
							{
								if ((randomSeats.bussinessS[row][columnLeft] == 0) && (randomSeats.bussinessS[row][columnLeft + 1] == 0) && (randomSeats.bussinessS[row][columnLeft + 2] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d, %d och %d i affärsklass special avdelningen.\n", rowPlus, randomSeats.bussiS[row][columnLeft], randomSeats.bussiS[row][columnLeft + 1], randomSeats.bussiS[row][columnLeft + 2]);
									randomSeats.bussinessS[row][columnLeft] = 1; randomSeats.bussinessS[row][columnLeft + 1] = 1; randomSeats.bussinessS[row][columnLeft + 2] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga mittgångsplatser för er i affärsklass special avdelningen!\n"); rowPlus = 1;
						kriterier.windowOrMiddle = 3;
					}
					if (kriterier.windowOrMiddle == 3)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 0; columnLeft <= 3; columnLeft++)
						{
							for (int row = 0; row <= 1; row++)
							{
								if ((randomSeats.bussinessS[row][columnLeft] == 0) && (randomSeats.bussinessS[row][columnLeft + 1] == 0) && (randomSeats.bussinessS[row][columnLeft + 2] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d, %d och %d i affärsklass special avdelningen.\n", rowPlus, randomSeats.bussiS[row][columnLeft], randomSeats.bussiS[row][columnLeft + 1], randomSeats.bussiS[row][columnLeft + 2]);
									randomSeats.bussinessS[row][columnLeft] = 1; randomSeats.bussinessS[row][columnLeft + 1] = 1; randomSeats.bussinessS[row][columnLeft + 2] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga platser för er i affärsklass special avdelningen!\n"); rowPlus = 1;
						kriterier.special = 'n';
					}
				}
			}
			/* =============================================================================================================== */
			if (kriterier.special == 'n')
			{
				if (kriterier.numOfSeats == 1)
				{
					if (kriterier.windowOrMiddle == 1)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 0; columnLeft == 0; columnLeft++)
						{
							for (int row = 0; row <= 7; row++)
							{
								if (randomSeats.bussiness[row][columnLeft] == 0)
								{
									rowPlus += row;
									printf("Du har blivit placerad på rad %d på plats %d i affärsklass avdelningen.\n", rowPlus, randomSeats.bussi[row][columnLeft]);
									randomSeats.bussiness[row][columnLeft] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						rowPlus = 1;
						for (int columnRight = 5; columnRight == 5; columnRight++)
						{
							for (int row = 0; row <= 7; row++)
							{
								if (randomSeats.bussiness[row][columnRight] == 0)
								{
									rowPlus += row;
									printf("Du har blivit placerad på rad %d på plats %d i affärsklass avdelningen.\n", rowPlus, randomSeats.bussi[row][columnRight]);
									randomSeats.bussiness[row][columnRight] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns ingen lediga fönsterplatser för dig i affärsklass avdelningen!\n"); rowPlus = 1;
						kriterier.windowOrMiddle = 3;
					}
					if (kriterier.windowOrMiddle == 2)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 2; columnLeft <= 3; columnLeft++)
						{
							for (int row = 0; row <= 7; row++)
							{
								if (randomSeats.bussiness[row][columnLeft] == 0)
								{
									rowPlus += row;
									printf("Du har blivit placerad på rad %d på plats %d i affärsklass avdelningen.\n", rowPlus, randomSeats.bussi[row][columnLeft]);
									randomSeats.bussiness[row][columnLeft] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns ingen lediga mittgångsplatser för dig i affärsklass avdelningen!\n"); rowPlus = 1;
						kriterier.windowOrMiddle = 3;
					}
					if (kriterier.windowOrMiddle == 3)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 0; columnLeft <= 5; columnLeft++)
						{
							for (int row = 0; row <= 7; row++)
							{
								if (randomSeats.bussiness[row][columnLeft] == 0)
								{
									rowPlus += row;
									printf("Du har blivit placerad på rad %d på plats %d i affärsklass avdelningen.\n", rowPlus, randomSeats.bussi[row][columnLeft]);
									randomSeats.bussiness[row][columnLeft] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns ingen lediga platser för dig i affärsklass avdelningen!\n"); rowPlus = 1;
						kriterier.bussinessOrEconomy = 2;
					}
				}
				if (kriterier.numOfSeats == 2)
				{
					if (kriterier.windowOrMiddle == 1)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 0; columnLeft == 0; columnLeft++)
						{
							for (int row = 0; row <= 7; row++)
							{
								if ((randomSeats.bussiness[row][columnLeft] == 0) && (randomSeats.bussiness[row][columnLeft + 1] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d och %d i affärsklass avdelningen.\n", rowPlus, randomSeats.bussi[row][columnLeft], randomSeats.bussi[row][columnLeft + 1]);
									randomSeats.bussiness[row][columnLeft] = 1; randomSeats.bussiness[row][columnLeft + 1] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						rowPlus = 1;
						for (int columnRight = 4; columnRight == 4; columnRight++)
						{
							for (int row = 0; row <= 7; row++)
							{
								if ((randomSeats.bussiness[row][columnRight] == 0) && (randomSeats.bussiness[row][columnRight + 1] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d och %d i affärsklass avdelningen.\n", rowPlus, randomSeats.bussi[row][columnRight], randomSeats.bussi[row][columnRight + 1]);
									randomSeats.bussiness[row][columnRight] = 1; randomSeats.bussiness[row][columnRight + 1] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga fönsterplatser för er i affärsklass avdelningen!\n"); rowPlus = 1;
						kriterier.windowOrMiddle = 3;
					}
					if (kriterier.windowOrMiddle == 2)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 1; columnLeft <= 3; columnLeft++)
						{
							for (int row = 0; row <= 7; row++)
							{
								if ((randomSeats.bussiness[row][columnLeft] == 0) && (randomSeats.bussiness[row][columnLeft + 1] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d och %d i affärsklass avdelningen.\n", rowPlus, randomSeats.bussi[row][columnLeft], randomSeats.bussi[row][columnLeft + 1]);
									randomSeats.bussiness[row][columnLeft] = 1; randomSeats.bussiness[row][columnLeft + 1] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga mittgångsplatser för er i affärsklass avdelningen!\n"); rowPlus = 1;
						kriterier.windowOrMiddle = 3;
					}
					if (kriterier.windowOrMiddle == 3)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 0; columnLeft <= 4; columnLeft++)
						{
							for (int row = 0; row <= 7; row++)
							{
								if ((randomSeats.bussiness[row][columnLeft] == 0) && (randomSeats.bussiness[row][columnLeft + 1] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d och %d i affärsklass avdelningen.\n", rowPlus, randomSeats.bussi[row][columnLeft], randomSeats.bussi[row][columnLeft + 1]);
									randomSeats.bussiness[row][columnLeft] = 1; randomSeats.bussiness[row][columnLeft + 1] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga platser för er i affärsklass avdelningen!\n"); rowPlus = 1;
						kriterier.bussinessOrEconomy = 2;
					}
				}
				if (kriterier.numOfSeats == 3)
				{
					if (kriterier.windowOrMiddle == 1)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 0; columnLeft == 0; columnLeft++)
						{
							for (int row = 0; row <= 7; row++)
							{
								if ((randomSeats.bussiness[row][columnLeft] == 0) && (randomSeats.bussiness[row][columnLeft + 1] == 0) && (randomSeats.bussiness[row][columnLeft + 2] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d, %d och %d i affärsklass avdelningen.\n", rowPlus, randomSeats.bussi[row][columnLeft], randomSeats.bussi[row][columnLeft + 1], randomSeats.bussi[row][columnLeft + 2]);
									randomSeats.bussiness[row][columnLeft] = 1; randomSeats.bussiness[row][columnLeft + 1] = 1; randomSeats.bussiness[row][columnLeft + 2] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						rowPlus = 1;
						for (int columnRight = 3; columnRight == 3; columnRight++)
						{
							for (int row = 0; row <= 7; row++)
							{
								if ((randomSeats.bussiness[row][columnRight] == 0) && (randomSeats.bussiness[row][columnRight + 1] == 0) && (randomSeats.bussiness[row][columnRight + 2] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d, %d och %d i affärsklass special avdelningen.\n", rowPlus, randomSeats.bussi[row][columnRight], randomSeats.bussi[row][columnRight + 1], randomSeats.bussi[row][columnRight + 2]);
									randomSeats.bussiness[row][columnRight] = 1; randomSeats.bussiness[row][columnRight + 1] = 1; randomSeats.bussiness[row][columnRight + 2] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga fönsterplatser för er i affärsklass avdelningen!\n"); rowPlus = 1;
						kriterier.windowOrMiddle = 3;
					}
					if (kriterier.windowOrMiddle == 2)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 0; columnLeft <= 3; columnLeft++)
						{
							for (int row = 0; row <= 7; row++)
							{
								if ((randomSeats.bussiness[row][columnLeft] == 0) && (randomSeats.bussiness[row][columnLeft + 1] == 0) && (randomSeats.bussiness[row][columnLeft + 2] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d, %d och %d i affärsklass avdelningen.\n", rowPlus, randomSeats.bussi[row][columnLeft], randomSeats.bussi[row][columnLeft + 1], randomSeats.bussi[row][columnLeft + 2]);
									randomSeats.bussiness[row][columnLeft] = 1; randomSeats.bussiness[row][columnLeft + 1] = 1; randomSeats.bussiness[row][columnLeft + 2] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga mittgångsplatser för er i affärsklass avdelningen!\n"); rowPlus = 1;
						kriterier.windowOrMiddle = 3;
					}
					if (kriterier.windowOrMiddle == 3)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 0; columnLeft <= 3; columnLeft++)
						{
							for (int row = 0; row <= 7; row++)
							{
								if ((randomSeats.bussiness[row][columnLeft] == 0) && (randomSeats.bussiness[row][columnLeft + 1] == 0) && (randomSeats.bussiness[row][columnLeft + 2] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d, %d och %d i affärsklass avdelningen.\n", rowPlus, randomSeats.bussi[row][columnLeft], randomSeats.bussi[row][columnLeft + 1], randomSeats.bussi[row][columnLeft + 2]);
									randomSeats.bussiness[row][columnLeft] = 1; randomSeats.bussiness[row][columnLeft + 1] = 1; randomSeats.bussiness[row][columnLeft + 2] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga platser för er i affärsklass avdelningen!\n"); rowPlus = 1;
						kriterier.bussinessOrEconomy = 2;
					}
				}
			}
		}
		/* ================================================================================================================================ */
		/* ================================================================================================================================ */
		if (kriterier.bussinessOrEconomy == 2)
		{
			/* HAR ANVÄNDAREN VALT ATT ÅKA I EKONOMIKLASS FORTSÄTTER PROGRAMMET IN I DENNA IF SATS */
			if (kriterier.special == 'y')
			{
				if (kriterier.numOfSeats == 1)
				{
					if (kriterier.windowOrMiddle == 1)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 0; columnLeft == 0; columnLeft++)
						{
							for (int row = 0; row <= 2; row++)
							{
								if (randomSeats.economyS[row][columnLeft] == 0)
								{
									rowPlus += row;
									printf("Du har blivit placerad på rad %d på plats %d i ekonomiklass special avdelningen.\n", rowPlus, randomSeats.ecoS[row][columnLeft]);
									randomSeats.economyS[row][columnLeft] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						rowPlus = 1;
						for (int columnRight = 5; columnRight == 5; columnRight++)
						{
							for (int row = 0; row <= 2; row++)
							{
								if (randomSeats.economyS[row][columnRight] == 0)
								{
									rowPlus += row;
									printf("Du har blivit placerad på rad %d på plats %d i ekonomiklass special avdelningen.\n", rowPlus, randomSeats.ecoS[row][columnRight]);
									randomSeats.economyS[row][columnRight] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga fönsterplatser för dig i ekonomiklass special avdelningen!\n"); rowPlus = 1;
						kriterier.windowOrMiddle = 3;
					}
					if (kriterier.windowOrMiddle == 2)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 2; columnLeft <= 3; columnLeft++)
						{
							for (int row = 0; row <= 2; row++)
							{
								if (randomSeats.economyS[row][columnLeft] == 0)
								{
									rowPlus += row;
									printf("Du har blivit placerad på rad %d på plats %d i ekonomiklass special avdelningen.\n", rowPlus, randomSeats.ecoS[row][columnLeft]);
									randomSeats.economyS[row][columnLeft] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga mittgångsplatser för dig i ekonomiklass special avdelningen!\n"); rowPlus = 1;
						kriterier.windowOrMiddle = 3;
					}
					if (kriterier.windowOrMiddle == 3)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 0; columnLeft <= 5; columnLeft++)
						{
							for (int row = 0; row <= 2; row++)
							{
								if (randomSeats.economyS[row][columnLeft] == 0)
								{
									rowPlus += row;
									printf("Du har blivit placerad på rad %d på plats %d i ekonomiklass special avdelningen.\n", rowPlus, randomSeats.ecoS[row][columnLeft]);
									randomSeats.economyS[row][columnLeft] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga platser för dig i ekonomiklass special avdelningen!\n"); rowPlus = 1;
						kriterier.special = 'n';
					}
				}
				if (kriterier.numOfSeats == 2)
				{
					if (kriterier.windowOrMiddle == 1)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 0; columnLeft == 0; columnLeft++)
						{
							for (int row = 0; row <= 2; row++)
							{
								if ((randomSeats.economyS[row][columnLeft] == 0) && (randomSeats.economyS[row][columnLeft + 1] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d och %d i ekonomiklass special avdelningen.\n", rowPlus, randomSeats.ecoS[row][columnLeft], randomSeats.ecoS[row][columnLeft + 1]);
									randomSeats.economyS[row][columnLeft] = 1; randomSeats.economyS[row][columnLeft + 1] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						rowPlus = 1;
						for (int columnRight = 4; columnRight == 4; columnRight++)
						{
							for (int row = 0; row <= 2; row++)
							{
								if ((randomSeats.economyS[row][columnRight] == 0) && (randomSeats.economyS[row][columnRight + 1] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d och %d i ekonomiklass special avdelningen.\n", rowPlus, randomSeats.ecoS[row][columnRight], randomSeats.ecoS[row][columnRight + 1]);
									randomSeats.economyS[row][columnRight] = 1; randomSeats.economyS[row][columnRight + 1] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga fönsterplatser för er i ekonomiklass special avdelningen!\n"); rowPlus = 1;
						kriterier.windowOrMiddle = 3;
					}
					if (kriterier.windowOrMiddle == 2)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 1; columnLeft <= 3; columnLeft++)
						{
							for (int row = 0; row <= 2; row++)
							{
								if ((randomSeats.economyS[row][columnLeft] == 0) && (randomSeats.economyS[row][columnLeft + 1] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d och %d i ekonomiklass special avdelningen.\n", rowPlus, randomSeats.ecoS[row][columnLeft], randomSeats.ecoS[row][columnLeft + 1]);
									randomSeats.economyS[row][columnLeft] = 1; randomSeats.economyS[row][columnLeft + 1] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga mittgångsplatser för er i ekonomiklass special avdelningen!\n"); rowPlus = 1;
						kriterier.windowOrMiddle = 3;
					}
					if (kriterier.windowOrMiddle == 3)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 0; columnLeft <= 4; columnLeft++)
						{
							for (int row = 0; row <= 2; row++)
							{
								if ((randomSeats.economyS[row][columnLeft] == 0) && (randomSeats.economyS[row][columnLeft + 1] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d och %d i ekonomiklass special avdelningen.\n", rowPlus, randomSeats.ecoS[row][columnLeft], randomSeats.ecoS[row][columnLeft + 1]);
									randomSeats.economyS[row][columnLeft] = 1; randomSeats.economyS[row][columnLeft + 1] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga platser för er i ekonomiklass special avdelningen!\n"); rowPlus = 1;
						kriterier.special = 'n';
					}
				}
				if (kriterier.numOfSeats == 3)
				{
					if (kriterier.windowOrMiddle == 1)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 0; columnLeft == 0; columnLeft++)
						{
							for (int row = 0; row <= 2; row++)
							{
								if ((randomSeats.economyS[row][columnLeft] == 0) && (randomSeats.economyS[row][columnLeft + 1] == 0) && (randomSeats.economyS[row][columnLeft + 2] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d, %d och %d i ekonomiklass special avdelningen.\n", rowPlus, randomSeats.ecoS[row][columnLeft], randomSeats.ecoS[row][columnLeft + 1], randomSeats.ecoS[row][columnLeft + 2]);
									randomSeats.economyS[row][columnLeft] = 1; randomSeats.economyS[row][columnLeft + 1] = 1; randomSeats.economyS[row][columnLeft + 2] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						rowPlus = 1;
						for (int columnRight = 3; columnRight == 3; columnRight++)
						{
							for (int row = 0; row <= 2; row++)
							{
								if ((randomSeats.economyS[row][columnRight] == 0) && (randomSeats.economyS[row][columnRight + 1] == 0) && (randomSeats.economyS[row][columnRight + 2] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d, %d och %d i ekonomiklass special avdelningen.\n", rowPlus, randomSeats.ecoS[row][columnRight], randomSeats.ecoS[row][columnRight + 1], randomSeats.ecoS[row][columnRight + 2]);
									randomSeats.economyS[row][columnRight] = 1; randomSeats.economyS[row][columnRight + 1] = 1; randomSeats.economyS[row][columnRight + 2] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga fönsterplatser för er i ekonomiklass special avdelningen!\n"); rowPlus = 1;
						kriterier.windowOrMiddle = 3;
					}
					if (kriterier.windowOrMiddle == 2)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 0; columnLeft <= 3; columnLeft++)
						{
							for (int row = 0; row <= 2; row++)
							{
								if ((randomSeats.economyS[row][columnLeft] == 0) && (randomSeats.economyS[row][columnLeft + 1] == 0) && (randomSeats.economyS[row][columnLeft + 2] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d, %d och %d i ekonomiklass special avdelningen.\n", rowPlus, randomSeats.ecoS[row][columnLeft], randomSeats.ecoS[row][columnLeft + 1], randomSeats.ecoS[row][columnLeft + 2]);
									randomSeats.economyS[row][columnLeft] = 1; randomSeats.economyS[row][columnLeft + 1] = 1; randomSeats.economyS[row][columnLeft + 2] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga mittgångsplatser för er i ekonomiklass special avdelningen!\n"); rowPlus = 1;
						kriterier.windowOrMiddle = 3;
					}
					if (kriterier.windowOrMiddle == 3)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 0; columnLeft <= 3; columnLeft++)
						{
							for (int row = 0; row <= 2; row++)
							{
								if ((randomSeats.economyS[row][columnLeft] == 0) && (randomSeats.economyS[row][columnLeft + 1] == 0) && (randomSeats.economyS[row][columnLeft + 2] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d, %d och %d i ekonomiklass special avdelningen.\n", rowPlus, randomSeats.ecoS[row][columnLeft], randomSeats.ecoS[row][columnLeft + 1], randomSeats.ecoS[row][columnLeft + 2]);
									randomSeats.economyS[row][columnLeft] = 1; randomSeats.economyS[row][columnLeft + 1] = 1; randomSeats.economyS[row][columnLeft + 2] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga platser för er i ekonomiklass special avdelningen!\n"); rowPlus = 1;
						kriterier.special = 'n';
					}
				}
			}

			if (kriterier.special == 'n')
			{
				if (kriterier.numOfSeats == 1)
				{
					if (kriterier.windowOrMiddle == 1)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 0; columnLeft == 0; columnLeft++)
						{
							for (int row = 0; row <= 16; row++)
							{
								if (randomSeats.economy[row][columnLeft] == 0)
								{
									rowPlus += row;
									printf("Du har blivit placerad rad %d på plats %d i ekonomiklass avdelningen.\n", rowPlus, randomSeats.eco[row][columnLeft]);
									randomSeats.economy[row][columnLeft] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						rowPlus = 1;
						for (int columnRight = 5; columnRight == 5; columnRight++)
						{
							for (int row = 0; row <= 16; row++)
							{
								if (randomSeats.economy[row][columnRight] == 0)
								{
									rowPlus += row;
									printf("Du har blivit placerad rad %d på plats %d i ekonomiklass avdelningen.\n", rowPlus, randomSeats.eco[row][columnRight]);
									randomSeats.economy[row][columnRight] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga fönsterplatser för dig i ekonomiklass avdelningen!\n"); rowPlus = 1;
						kriterier.windowOrMiddle = 3;
					}
					if (kriterier.windowOrMiddle == 2)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 2; columnLeft <= 3; columnLeft++)
						{
							for (int row = 0; row <= 16; row++)
							{
								if (randomSeats.economy[row][columnLeft] == 0)
								{
									rowPlus += row;
									printf("Du har blivit placerad rad %d på plats %d i ekonomiklass avdelningen.\n", rowPlus, randomSeats.eco[row][columnLeft]);
									randomSeats.economy[row][columnLeft] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga mittgångsplatser för dig i ekonomiklass avdelningen!\n"); rowPlus = 1;
						kriterier.windowOrMiddle = 3;
					}
					if (kriterier.windowOrMiddle == 3)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 0; columnLeft <= 5; columnLeft++)
						{
							for (int row = 0; row <= 16; row++)
							{
								if (randomSeats.economy[row][columnLeft] == 0)
								{
									rowPlus += row;
									printf("Du har blivit placerad rad %d på plats %d i ekonomiklass avdelningen.\n", rowPlus, randomSeats.eco[row][columnLeft]);
									randomSeats.economy[row][columnLeft] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga platser för dig i ekonomiklass avdelningen!\n"); rowPlus = 1;
						kriterier.bussinessOrEconomy = 1;
					}
				}
				if (kriterier.numOfSeats == 2)
				{
					if (kriterier.windowOrMiddle == 1)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 0; columnLeft == 0; columnLeft++)
						{
							for (int row = 0; row <= 16; row++)
							{
								if ((randomSeats.economy[row][columnLeft] == 0) && (randomSeats.economy[row][columnLeft + 1] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d och %d i ekonomiklass avdelningen.\n", rowPlus, randomSeats.eco[row][columnLeft], randomSeats.eco[row][columnLeft + 1]);
									randomSeats.economy[row][columnLeft] = 1; randomSeats.economy[row][columnLeft + 1] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						rowPlus = 1;
						for (int columnRight = 4; columnRight == 4; columnRight++)
						{
							for (int row = 0; row <= 16; row++)
							{
								if ((randomSeats.economy[row][columnRight] == 0) && (randomSeats.economy[row][columnRight + 1] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d och %d i ekonomiklass avdelningen.\n", rowPlus, randomSeats.eco[row][columnRight], randomSeats.eco[row][columnRight + 1]);
									randomSeats.economy[row][columnRight] = 1; randomSeats.economy[row][columnRight + 1] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga fönsterplatser för er i ekonomiklass avdelningen!\n"); rowPlus = 1;
						kriterier.windowOrMiddle = 3;
					}
					if (kriterier.windowOrMiddle == 2)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 1; columnLeft <= 3; columnLeft++)
						{
							for (int row = 0; row <= 16; row++)
							{
								if ((randomSeats.economy[row][columnLeft] == 0) && (randomSeats.economy[row][columnLeft + 1] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d och %d i ekonomiklass avdelningen.\n", rowPlus, randomSeats.eco[row][columnLeft], randomSeats.eco[row][columnLeft + 1]);
									randomSeats.economy[row][columnLeft] = 1; randomSeats.economy[row][columnLeft + 1] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga mittgångsplatser för er i ekonomiklass avdelningen!\n"); rowPlus = 1;
						kriterier.windowOrMiddle = 3;
					}
					if (kriterier.windowOrMiddle == 3)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 0; columnLeft <= 4; columnLeft++)
						{
							for (int row = 0; row <= 16; row++)
							{
								if ((randomSeats.economy[row][columnLeft] == 0) && (randomSeats.economy[row][columnLeft + 1] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d och %d i ekonomiklass avdelningen.\n", rowPlus, randomSeats.eco[row][columnLeft], randomSeats.eco[row][columnLeft + 1]);
									randomSeats.economy[row][columnLeft] = 1; randomSeats.economy[row][columnLeft + 1] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga platser för er i ekonomiklass avdelningen!\n"); rowPlus = 1;
						kriterier.bussinessOrEconomy = 1;
					}
				}
				if (kriterier.numOfSeats == 3)
				{
					if (kriterier.windowOrMiddle == 1)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 0; columnLeft == 0; columnLeft++)
						{
							for (int row = 0; row <= 16; row++)
							{
								if ((randomSeats.economy[row][columnLeft] == 0) && (randomSeats.economy[row][columnLeft + 1] == 0) && (randomSeats.economy[row][columnLeft + 2] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d, %d och %d i ekonomiklass avdelningen.\n", rowPlus, randomSeats.eco[row][columnLeft], randomSeats.eco[row][columnLeft + 1], randomSeats.eco[row][columnLeft + 2]);
									randomSeats.economy[row][columnLeft] = 1; randomSeats.economy[row][columnLeft + 1] = 1; randomSeats.economy[row][columnLeft + 2] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						rowPlus = 1;
						for (int columnRight = 3; columnRight == 3; columnRight++)
						{
							for (int row = 0; row <= 16; row++)
							{
								if ((randomSeats.economy[row][columnRight] == 0) && (randomSeats.economy[row][columnRight + 1] == 0) && (randomSeats.economy[row][columnRight + 2] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d, %d och %d i ekonomiklass avdelningen.\n", rowPlus, randomSeats.eco[row][columnRight], randomSeats.eco[row][columnRight + 1], randomSeats.eco[row][columnRight + 2]);
									randomSeats.economy[row][columnRight] = 1; randomSeats.economy[row][columnRight + 1] = 1; randomSeats.economy[row][columnRight + 2] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga fönsterplatser för er i ekonomiklass avdelningen!\n"); rowPlus = 1;
						kriterier.windowOrMiddle = 3;
					}
					if (kriterier.windowOrMiddle == 2)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 0; columnLeft <= 3; columnLeft++)
						{
							for (int row = 0; row <= 16; row++)
							{
								if ((randomSeats.economy[row][columnLeft] == 0) && (randomSeats.economy[row][columnLeft + 1] == 0) && (randomSeats.economy[row][columnLeft + 2] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d, %d och %d i ekonomiklass avdelningen.\n", rowPlus, randomSeats.eco[row][columnLeft], randomSeats.eco[row][columnLeft + 1], randomSeats.eco[row][columnLeft + 2]);
									randomSeats.economy[row][columnLeft] = 1; randomSeats.economy[row][columnLeft + 1] = 1; randomSeats.economy[row][columnLeft + 2] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga mittgångsplatser för er i ekonomiklass avdelningen!\n"); rowPlus = 1;
						kriterier.windowOrMiddle = 3;
					}
					if (kriterier.windowOrMiddle == 3)
					{ /* =============================== */
						rowPlus = 1;
						for (int columnLeft = 0; columnLeft <= 3; columnLeft++)
						{
							for (int row = 0; row <= 16; row++)
							{
								if ((randomSeats.economy[row][columnLeft] == 0) && (randomSeats.economy[row][columnLeft + 1] == 0) && (randomSeats.economy[row][columnLeft + 2] == 0))
								{
									rowPlus += row;
									printf("Ni har blivit placerade på rad %d på platserna %d, %d och %d i ekonomiklass avdelningen.\n", rowPlus, randomSeats.eco[row][columnLeft], randomSeats.eco[row][columnLeft + 1], randomSeats.eco[row][columnLeft + 2]);
									randomSeats.economy[row][columnLeft] = 1; randomSeats.economy[row][columnLeft + 1] = 1; randomSeats.economy[row][columnLeft + 2] = 1;
									system("pause");  return randomSeats;
								}
							}
						}
						printf("Det fanns inga lediga platser för er i ekonomiklass avdelningen!\n"); rowPlus = 1;
						kriterier.bussinessOrEconomy = 1;
					}
				}
			}
		}
		noSeats++;
		if (noSeats == 180) // NÅR LOOPEN noSeats == 180 SÅ FINNS DET INGA PLATSER I PLANET.
		{
			system("cls");
			printf("Det finns inga lediga platser kvar på detta flyg!\n");
			system("pause"); exit(0);
		}
	}
}