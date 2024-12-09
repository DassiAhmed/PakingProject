#include "client.h"
#include <ctype.h>
#include <stdbool.h>


void afficher_Client (GtkWidget *liste)
{
GtkCellRenderer *renderer ;
GtkTreeViewColumn *column ;
GtkTreeIter iter ;
GtkListStore *store ;

citoyen p ;
 

char nikname[50];
char parkingarea[50];
char startdate[50];
int duration;
char id1[50];
char slotn[50];

store=NULL;

FILE *f ;



store=gtk_tree_view_get_model(liste);
if (store == NULL)
{
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("ID",renderer,"text",ID1,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Username",renderer,"text",NIKNAME,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Parking_Location",renderer,"text",PARKA,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Slot_Number",renderer,"text",SLOTN,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Starting_date",renderer,"text",SDATE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

 	    renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Duration",renderer,"text",DURATION,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
             

	     
}


	    store = gtk_list_store_new(NUM_COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_INT);




            f=fopen("client.txt","r");
            if (f!=NULL){
		while (fscanf(f,"%s %s %s %s %s %d",id1,nikname,parkingarea,slotn,startdate,&duration)!=EOF) {
		printf("id1: %s, nikname: %s, parkingarea: %s, slotn: %s, startdate: %s, duration: %d\n",
      			id1, nikname, parkingarea, slotn, startdate, duration);
            gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter,
                           ID1, id1,
                           NIKNAME, nikname,
                           PARKA, parkingarea,
                           SLOTN, slotn,
                           SDATE, startdate,
                           DURATION, duration,
                           -1);
		}
		
		fclose(f);
}
            gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
            g_object_unref(store);
}


void rechercher_client(GtkWidget *liste,char*type)
{
GtkCellRenderer *renderer ;
GtkTreeViewColumn *column ;
GtkTreeIter iter ;
GtkListStore *store ;

citoyen p ;

char nikname[50];
char parkingarea[50];
char startdate[50];
int duration;
char id1[50];
char slotn[50];

store=NULL;

FILE *f ;


store=gtk_tree_view_get_model(liste);
if (store == NULL)
{
                      renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("ID",renderer,"text",ID1,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Username",renderer,"text",NIKNAME,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Parking_Location",renderer,"text",PARKA,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Slot_Number",renderer,"text",SLOTN,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Starting_date",renderer,"text",SDATE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

 	    renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Duration",renderer,"text",DURATION,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
             

	     
}


	    store = gtk_list_store_new(NUM_COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING , G_TYPE_INT);



           f=fopen("client.txt","r");
            if (f!=NULL){
		while (fscanf(f,"%s %s %s %s %s %d",id1,nikname,parkingarea,slotn,startdate,&duration)!=EOF)  {
            if(strcmp(type,startdate)==0){
            gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter,
                           ID1, id1,
                           NIKNAME, nikname,
                           PARKA, parkingarea,
                           SLOTN, slotn,
                           SDATE, startdate,
                           DURATION, duration,
                           -1);
		}
		}
		fclose(f);
}
            gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
            g_object_unref(store);


}
int ajouter_client(citoyen x )
{
    FILE * f=fopen("client.txt", "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s %s %d",x.id1,x.nikname,x.parkingarea,x.slotn,x.startdate,x.duration);
        fclose(f);
        return 1;
    }
    else return 0;
}
int verifierr(char slot[])
{
char nikname[50];
char parkingarea[50];
char startdate[50];
int duration;
char id1[50];
char slotn[50];

int r=0;
citoyen x;
FILE *f;


f=fopen("client.txt","r") ;
if (f!= NULL)
{

while (fscanf(f,"%s %s %s %s %s %d",id1,nikname,parkingarea,slotn,startdate,&duration)!=EOF) 
{

if (strcmp(x.slotn,slot)==0 )
{
	r=1;
        break;


}

}

fclose(f);
}

return r;

}

int countLines(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    int lineCount = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            lineCount++;
        }
    }

    fclose(file);
    return lineCount;
}


char* processSlotnAndExtractLastChars(const char *filename, int *numChars) {



char nikname[50];
char parkingarea[50];
char startdate[50];
int duration;
char id1[50];
char slotn[50];   
 FILE *f= fopen(filename, "r");
   

    
    int capacity = 10; // Initial capacity for the array
    char *result = malloc(capacity * sizeof(char));
    *numChars = 0;

    while (fscanf(f,"%s %s %s %s %s %d",id1,nikname,parkingarea,slotn,startdate,&duration)!=EOF) {
        size_t len = strlen(slotn);
        if (len > 1) { // Ensure there are at least two characters
            char beforeLast = slotn[len - 2];
            char last = slotn[len - 1];
            char processed[10];

            if (beforeLast == 'A') {
                snprintf(processed, sizeof(processed), "%c", last);
            } else if (beforeLast == 'B') {
                int num = atoi(&last) + 8;
                snprintf(processed, sizeof(processed), "%d", num);
            } else if (beforeLast == 'C') {
                int num = atoi(&last) + 16;
                snprintf(processed, sizeof(processed), "%d", num);
            } else {
                continue; // Skip this slotn if it doesn't match A, B, or C
            }

            // Add the processed character to the result array
            if (*numChars >= capacity) {
                capacity *= 2;
                result = realloc(result, capacity * sizeof(char));
            }
            result[*numChars] = processed[0]; // Take the first character of processed
            (*numChars)++;
        }
    }

    fclose(f);
    return result;
}




































