#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
enum
{ ID,
NAME,
SUR,
AGE,
GENDER,
WL,
YX,
SKILL,
COLUMNS
};
typedef struct agents 
{
char name[50];
char surname[50];
char gender[50];
char wl[50];
char skill[50];
char age[50];
char id[50];
int yx;
}user;
int ajouter_user(user p );
void afficher_USER (GtkWidget *liste);
int supprimer_user( char *l);
void rechercher_user(GtkWidget *liste,char*type);
int modifier_user( char *id, user nouv );
