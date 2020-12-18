#pragma warning( disable:4996 )

/**
 *
 *  Author:         Alexander Emanuelsson
 *  Date:           2020-12-13
 *  Description:    The optimized version of Prog-Flight (First application I ever made)
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


/**
 *  Defines
 */

#define TOTAL_ROWS_OF_SEATS                         30
#define SEATS_PER_ROW                               6

#define AMOUNT_OF_ROWS_BUSINESS_CLASS_SPECIAL       2
#define AMOUNT_OF_ROWS_BUSINESS_CLASS_NORMAL        8
#define AMOUNT_OF_ROWS_ECONOMY_CLASS_SPECIAL        3
#define AMOUNT_ROWS_ECONOMY_CLASS_NORMAL            17

#define BUSINESS_CLASS_SPECIAL_START_ROW            0
#define BUSINESS_CLASS_NORMAL_START_ROW             2
#define ECONOMY_CLASS_SPECIAL_START_ROW             10
#define ECONOMY_CLASS_NORMAL_START_ROW              13

#define TOTAL_AMOUNT_OF_SEATS                       ( TOTAL_ROWS_OF_SEATS * SEATS_PER_ROW )

#define GENERATED_OCCUPIED_SEATS_PERCENTAGE         60  /* % */
#define FILE_NAME                                   "airplane.ap"

#define NUMBER_OF_STRING                            4
#define MAX_STRING_SIZE                             30
#define MAX_RESERVED_SEATS                          3


typedef enum
{
    WINDOW_LEFT = 0,
    MIDDLE_LEFT,
    AISLE_LEFT,
    AISLE_RIGHT,
    MIDDLE_RIGHT,
    WINDOW_RIGHT,

} TRowPlacement;

typedef enum
{
    BUSINESS_SPECIAL = 0,
    BUSINESS_NORMAL,
    ECONOMY_SPECIAL,
    ECONOMY_NORMAL,

} TSection;

typedef struct
{
    int row;
    int seatNumber;
    TRowPlacement placement;
    TSection section;

    bool isOccupied;

} TSeat;

typedef struct
{
    TSeat seats[ TOTAL_ROWS_OF_SEATS ][ SEATS_PER_ROW ];

} TAirplane;


/**
 *  User Defines
 */

typedef enum
{
    WINDOW = 0,
    AISLE,
    ANY,

} TPlacementRequirement;

typedef enum
{
    RESERVE_SEATS = 1,
    DISPLAY_SEATS,
    EXIT,

} TMenuItem;

typedef struct
{
    TSection planeSection;
    int numberOfSeats;
    TPlacementRequirement placement;

} TUserRequirements;

typedef struct
{
    TSeat seat[ MAX_RESERVED_SEATS ];

} TUserPlacement;


/**
 *  Public
 */

TAirplane airplane;

char sectionName[ NUMBER_OF_STRING ][ MAX_STRING_SIZE ] =
{
    "business class special",
    "business class normal",
    "economy class special",
    "economy class normal",

};

int sectionRowStart[] =
{
    BUSINESS_CLASS_SPECIAL_START_ROW,
    BUSINESS_CLASS_NORMAL_START_ROW,
    ECONOMY_CLASS_SPECIAL_START_ROW,
    ECONOMY_CLASS_NORMAL_START_ROW,

};

int amountOfRowsPerSection[] =
{
    AMOUNT_OF_ROWS_BUSINESS_CLASS_SPECIAL,
    AMOUNT_OF_ROWS_BUSINESS_CLASS_NORMAL,
    AMOUNT_OF_ROWS_ECONOMY_CLASS_SPECIAL,
    AMOUNT_ROWS_ECONOMY_CLASS_NORMAL,

};

int *seatPatterns[] =
{
    ( int[] ) { 0b100000, 0b000001, 0 },                                            /* 1 seat, window */
    ( int[] ) { 0b001000, 0b000100, 0 },                                            /* 1 seat, aisle */
    ( int[] ) { 0b100000, 0b010000, 0b001000, 0b000100, 0b000010, 0b000001, 0 },    /* 1 seat, any */

    ( int[] ) { 0b110000, 0b000011, 0 },                                            /* 2 seats, window */
    ( int[] ) { 0b011000, 0b001100, 0b000110, 0 },                                  /* 2 seats, aisle */
    ( int[] ) { 0b110000, 0b011000, 0b001100, 0b000110, 0b000011, 0 },              /* 2 seats, any */

    ( int[] ) { 0b111000, 0b000111, 0 },                                            /* 3 seats, window */
    ( int[] ) { 0b111000, 0b011100, 0b001110, 0b000111, 0 },                        /* 3 seats, aisle */
    ( int[] ) { 0b111000, 0b011100, 0b001110, 0b000111, 0 },                        /* 3 seats, any */
};

void initAirplane( void );
bool setRandomOccupiedSeats( int percentage );
void writeAirplaneToFile( void );
void readAirplaneFromFile( void );
TMenuItem selectMenu( void );
void displaySeatMap( void );
void reserveSeats( void );
TUserRequirements getUserRequirements( void );
void findSeats( TUserRequirements requirements );
int matchRowMap( TUserRequirements requirements, int rowMap );
void announceUserSeats( TUserPlacement userPlacement );


/**
 *  Private
 */

static bool exists( const char *filename );


/*********************************************************************************
 *  Main
 ********************************************************************************/
int main( void )
{
    srand( (int) time( NULL ) );

    initAirplane();

    if ( exists( FILE_NAME ) )
    {
        readAirplaneFromFile();
    }
    else
    {
    setRandomOccupiedSeats( GENERATED_OCCUPIED_SEATS_PERCENTAGE );
    writeAirplaneToFile();
    }

    while ( true )
    {
        system( "cls" );
        printf( "###############################################\n" );
        printf( "##                                           ##\n" );
        printf( "##  Welcome to Prog-Flight booking program!  ##\n" );
        printf( "##                                           ##\n" );
        printf( "###############################################\n\n" );

        switch ( selectMenu() )
        {
        case RESERVE_SEATS:
            system( "cls" );
            reserveSeats();
            break;
        case DISPLAY_SEATS:
            system( "cls" );
            displaySeatMap();
            break;
        case EXIT:
            return 0;
        default:
            break;
        }
    }

    return 0;
}

/*********************************************************************************
 *  Initialize airplane sections
 ********************************************************************************/
void initAirplane( void )
{
    TRowPlacement placement;
    TSection section = BUSINESS_SPECIAL;
    int seatNumber = 1;
    int row, column;

    for ( row = 0; row < TOTAL_ROWS_OF_SEATS; row++ )
    {
        placement = WINDOW_LEFT; /* Always start from the left on new row */

        for ( column = 0; column < SEATS_PER_ROW; column++ )
        {
            airplane.seats[ row ][ column ].row = row + 1;
            airplane.seats[ row ][ column ].seatNumber = seatNumber;
            airplane.seats[ row ][ column ].placement = placement;
            airplane.seats[ row ][ column ].section = section;
            airplane.seats[ row ][ column ].isOccupied = false;
            seatNumber++;
            placement++;
        }

        /* Change the section */
        if ( ( row + 1 ) == BUSINESS_CLASS_NORMAL_START_ROW ||
             ( row + 1 ) == ECONOMY_CLASS_SPECIAL_START_ROW ||
             ( row + 1 ) == ECONOMY_CLASS_NORMAL_START_ROW )
        {
            section++;
        }
    }
}

/*********************************************************************************
 *  Sets random occupied seats depending on percentage (0-100 integer)
 ********************************************************************************/
bool setRandomOccupiedSeats( int percentage )
{
    int row, column;
    bool value;

    if ( percentage > 100 || percentage < 0 )
    {
        return false;
    }

    for ( row = 0; row < TOTAL_ROWS_OF_SEATS; row++ )
    {
        for ( column = 0; column < SEATS_PER_ROW; column++ )
        {
            value = ( ( rand() % 101 ) <= percentage ) ? true : false;
            airplane.seats[ row ][ column ].isOccupied = value;
        }
    }

    return true;
}

/*********************************************************************************
 *  Write the current airplane to file
 ********************************************************************************/
void writeAirplaneToFile( void )
{
    FILE * file;
    int row, column;

    file = fopen( FILE_NAME, "w" );

    for ( row = 0; row < TOTAL_ROWS_OF_SEATS; row++ )
    {
        for ( column = 0; column < SEATS_PER_ROW; column++ )
        {
            fprintf( file, "%d %d %d %d %d\n",
                airplane.seats[ row ][ column ].row,
                airplane.seats[ row ][ column ].seatNumber,
                airplane.seats[ row ][ column ].placement,
                airplane.seats[ row ][ column ].section,
                airplane.seats[ row ][ column ].isOccupied );
        }
    }
    fclose( file );
}

/*********************************************************************************
 *  Read airplane from file
 ********************************************************************************/
void readAirplaneFromFile( void )
{
    FILE * file;
    int row, column;

    file = fopen( FILE_NAME, "r" );

    for ( row = 0; row < TOTAL_ROWS_OF_SEATS; row++ )
    {
        for ( column = 0; column < SEATS_PER_ROW; column++ )
        {
            fscanf( file, "%d %d %d %d %d\n",
                &airplane.seats[ row ][ column ].row,
                &airplane.seats[ row ][ column ].seatNumber,
                &airplane.seats[ row ][ column ].placement,
                &airplane.seats[ row ][ column ].section,
                &airplane.seats[ row ][ column ].isOccupied );
        }
    }
    fclose( file );
}

/*********************************************************************************
 *  Select a menu item
 ********************************************************************************/
TMenuItem selectMenu( void )
{
    TMenuItem choice;

    printf( "Please select an action:\n\n" );
    printf( "(%d) Reserve a seat.\n", RESERVE_SEATS );
    printf( "(%d) Display seat map.\n", DISPLAY_SEATS );
    printf( "(%d) Exit application.\n\n", EXIT );

    while ( true )
    {
        fflush( stdin );
        scanf( "%d", &choice );

        if ( choice == RESERVE_SEATS || choice == DISPLAY_SEATS || choice == EXIT )
        {
            return choice;
        }
        else
        {
            printf( "Invalid input, try again.\n" );
        }
    }
}

/*********************************************************************************
 *  Displays the seat map for the airplane
 ********************************************************************************/
void displaySeatMap( void )
{
    int row, column;

    for ( row = 0; row < TOTAL_ROWS_OF_SEATS; row++ )
    {
        switch ( row )
        {
        case BUSINESS_CLASS_SPECIAL_START_ROW:
            printf( "      Business Class:\n       Special Seats\n" );
            break;
        case ECONOMY_CLASS_SPECIAL_START_ROW:
            printf( "\n===========================\n\n       Economy Class:  \n       Special Seats\n" );
            break;
        case BUSINESS_CLASS_NORMAL_START_ROW:
        case ECONOMY_CLASS_NORMAL_START_ROW:
            printf( "        Normal Seats\n" );
            break;
        default:
            break;
        }

        for ( column = 0; column < SEATS_PER_ROW; column++ )
        {
            printf( "(%d) ", airplane.seats[ row ][ column ].isOccupied );
            if ( column == ( ( SEATS_PER_ROW - 1 ) / 2 ) )
            {
                printf( "\t" );
            }
            if ( column == ( SEATS_PER_ROW - 1 ) )
            {
                printf( "\tRow %d\n", airplane.seats[ row ][ column ].row );
            }
        }
    }
    printf( "\n 1   2   3       4   5   6\n\n" );
    system( "pause" );
}

/*********************************************************************************
 *  Reserve seats on the airplane
 ********************************************************************************/
void reserveSeats( void )
{
    TUserRequirements requirements;

    requirements = getUserRequirements();

    findSeats( requirements );
}

/*********************************************************************************
 *  Get the user requirements
 ********************************************************************************/
TUserRequirements getUserRequirements( void )
{
    TUserRequirements requirements;
    int selection;

    /* Airplane section selection */
    printf( "Select which section of the airplane you want to be placed:\n\n" );
    printf( "\t(%d) Business class special section\n", ( BUSINESS_SPECIAL + 1 ) );
    printf( "\t(%d) Business class normal section\n", ( BUSINESS_NORMAL + 1 ) );
    printf( "\t(%d) Economy class special section\n", ( ECONOMY_SPECIAL + 1 ) );
    printf( "\t(%d) Economy class normal section\n\n", ( ECONOMY_NORMAL + 1 ) );

    while ( true )
    {
        fflush( stdin );
        scanf( "%d", &selection );
        if ( selection == ( BUSINESS_SPECIAL + 1 ) ||
             selection == ( BUSINESS_NORMAL + 1 ) ||
             selection == ( ECONOMY_SPECIAL + 1 ) ||
             selection == ( ECONOMY_NORMAL + 1 ) )
        {
            requirements.planeSection = selection - 1;
            break;
        }
        else
        {
            printf( "Invalid input, please try again.\n" );
        }
    }
    printf( "========================================\n\n" );

    /* Airplane number of seats selection */
    printf( "How many seats do you want? (1-3): " );

    while ( true )
    {
        fflush( stdin );
        scanf( "%d", &selection );
        if ( selection <= 3 && selection >= 1 )
        {
            requirements.numberOfSeats = selection;
            break;
        }
        else
        {
            printf( "Invalid input, please try again.\n" );
        }
    }
    printf( "\n========================================\n" );

    /* Row placement selection */
    printf( "Would you like window or aisle seat?\n\n" );
    printf( "\t(%d) Window seat\n", ( WINDOW + 1 ) );
    printf( "\t(%d) Aisle seat\n", ( AISLE + 1 ) );
    printf( "\t(%d) Doesn't matter\n\n", ( ANY + 1 ) );

    while ( true )
    {
        fflush( stdin );
        scanf( "%d", &selection );
        if ( selection == ( WINDOW + 1 ) ||
             selection == ( AISLE + 1 ) ||
             selection == ( ANY + 1 ) )
        {
            requirements.placement = selection - 1;
            break;
        }
        else
        {
            printf( "Invalid input, please try again.\n" );
        }
    }

    return requirements;
}

/*********************************************************************************
 *  Allocate seat(s) that matches the users requirements
 ********************************************************************************/
void findSeats( TUserRequirements requirements )
{
    TUserPlacement userPlacement;
    TUserRequirements OrigRequirements = requirements;
    int i, row, column, firstSeat, seat;
    int rowMap = 0;
    int rowMapCheck = 0;
    bool placementReqChanged;

    for ( i = 0; i < MAX_RESERVED_SEATS; i++ )
    {
        userPlacement.seat[ i ].isOccupied = false;
    }

    for ( i = 0; i < sizeof( TSection ); i++ )
    {
        placementReqChanged = false;
        requirements.placement = OrigRequirements.placement;

        while ( true )
        {
            for ( row = sectionRowStart[ requirements.planeSection ];
                    row < ( sectionRowStart[ requirements.planeSection ] +
                    amountOfRowsPerSection[ requirements.planeSection ] );
                    row++ )
            {
                rowMap = 0;
                /* Get the current row map */
                for ( column = 0; column < SEATS_PER_ROW; column++ )
                {
                    rowMap |= airplane.seats[ row ][ column ].isOccupied << ( ( SEATS_PER_ROW - 1 ) - column );
                }

                rowMapCheck = matchRowMap( requirements, rowMap );
                if ( rowMapCheck )
                {
                    /* Find the first seat */
                    for ( firstSeat = 0; firstSeat < SEATS_PER_ROW; firstSeat++ )
                    {
                        if ( ( rowMapCheck >> ( ( SEATS_PER_ROW - 1 ) - firstSeat ) ) & 1 )
                        {
                            break;
                        }
                    }

                    for ( seat = 0; seat < requirements.numberOfSeats; seat++ )
                    {
                        userPlacement.seat[ seat ].row = row;
                        userPlacement.seat[ seat ].seatNumber = airplane.seats[ row ][ firstSeat + seat ].seatNumber;
                        userPlacement.seat[ seat ].placement = firstSeat + seat;
                        userPlacement.seat[ seat ].section = requirements.planeSection;
                        userPlacement.seat[ seat ].isOccupied = true;
                    }

                    announceUserSeats( userPlacement );
                    return;
                }
            }

            if ( placementReqChanged )
            {
                break;
            }
            else
            {
                requirements.placement = ANY;
                placementReqChanged = true;
            }
        }
        requirements.planeSection = ( requirements.planeSection + 1 ) % 4;
    }
    printf( "Unfortunatly there were no seats available on this flight for your company.\n\n" );
    system( "pause" );
}

/*********************************************************************************
 *  Match the rowMap against the requirements in seatPatterns
 ********************************************************************************/
int matchRowMap( TUserRequirements requirements, int rowMap )
{
    int patternSectionIndex = 0;
    int result;
    int i;

    switch ( requirements.numberOfSeats )
    {
    case 1:
        patternSectionIndex = 0;
        break;
    case 2:
        patternSectionIndex = 3;
        break;
    case 3:
        patternSectionIndex = 6;
        break;
    default:
        break;
    }

    patternSectionIndex += requirements.placement;

    for ( i = 0; seatPatterns[ patternSectionIndex ][ i ] != 0; i++ )
    {
        result = rowMap & seatPatterns[ patternSectionIndex ][ i ];
        if ( result == 0 )
        {
            return seatPatterns[ patternSectionIndex ][ i ];
        }
    }

    return 0;
}

/*********************************************************************************
 *  Announce the given seat(s) to the user
 ********************************************************************************/
void announceUserSeats( TUserPlacement userPlacement )
{
    int seat;

    system( "cls" );
    printf( "The following seats have been assigned to you:\n\n" );

    for ( seat = 0; seat < MAX_RESERVED_SEATS; seat++ )
    {
        if ( userPlacement.seat[ seat ].isOccupied )
        {
            printf( "Seat number %d on row %d in %s section.\n",
            userPlacement.seat[ seat ].seatNumber,
            userPlacement.seat[ seat ].row + 1,
            sectionName[ userPlacement.seat[ seat ].section ] );
            airplane.seats[ userPlacement.seat[ seat ].row ][ userPlacement.seat[ seat ].placement ].isOccupied = true;
        }
    }
    writeAirplaneToFile();

    printf( "\n" );
    system( "pause" );
}

/**
 *  Private
 */

/*********************************************************************************
 *  Returns true if file exists else false
 ********************************************************************************/
static bool exists( const char *filename )
{
    FILE * file;
    if ( file = fopen( filename, "r" ) )
    {
        fclose( file );
        return true;
    }
    return false;
}
