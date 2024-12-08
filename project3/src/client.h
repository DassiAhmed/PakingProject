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
char duration[50];
char id1[50];
int slotn;
}citoyen;
void afficher_Client (GtkWidget *liste);
void rechercher_client(GtkWidget *liste,char*type);
