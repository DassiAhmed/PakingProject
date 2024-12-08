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
char duration[50];
char id1[50];
int slotn;

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


	    store = gtk_list_store_new(NUM_COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING);




            f=fopen("client.txt","r");
            if (f!=NULL){
		while (fscanf(f,"%s %s %s %d %s %s",id1,nikname,parkingarea,&slotn,startdate,duration)!=EOF) {
		printf("id1: %s, nikname: %s, parkingarea: %s, slotn: %d, startdate: %s, duration: %s\n",
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
char duration[50];
char id1[50];
int slotn;
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


	    store = gtk_list_store_new(NUM_COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING);



           f=fopen("client.txt","r");
            if (f!=NULL){
		while (fscanf(f,"%s %s %s %d %s %s",id1,nikname,parkingarea,&slotn,startdate,duration)!=EOF)  {
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






































