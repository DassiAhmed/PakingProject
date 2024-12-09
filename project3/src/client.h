#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
enum
{ ID1,
NIKNAME,
PARKA,
SLOTN,
SDATE,
DURATION,
NUM_COLUMNS
};
typedef struct client 
{
char nikname[50];
char parkingarea[50];
char startdate[50];
int duration;
char id1[50];
char slotn[50];
}citoyen;
void afficher_Client (GtkWidget *liste);
void rechercher_client(GtkWidget *liste,char*type);
int ajouter_client(citoyen x );
int countLines(const char *filename);
char* extractLastCharsFromSlotn(const char *filename, int *numChars);
