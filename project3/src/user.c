#include "user.h"
#include <ctype.h>
#include <stdbool.h>
int ajouter_user(user p )
{
    FILE * f=fopen("point.txt", "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s %s %s %d %s\n",p.id,p.name,p.surname,p.age,p.gender,p.wl,p.yx,p.skill);
        fclose(f);
        return 1;
    }
    else return 0;
}

void afficher_USER (GtkWidget *liste)
{
GtkCellRenderer *renderer ;
GtkTreeViewColumn *column ;
GtkTreeIter iter ;
GtkListStore *store ;

user p ;
 

char name[50];
char surname[50];
char gender[50];
char wl[50];
char skill[50];
char age[50];
char id[50];
int yx;

store=NULL;

FILE *f ;


store=gtk_tree_view_get_model(liste);
if (store == NULL)
{
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("ID",renderer,"text",ID,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Name",renderer,"text",NAME,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Surname",renderer,"text",SUR,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Age",renderer,"text",AGE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Gender",renderer,"text",GENDER,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

 	    renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("work-location",renderer,"text",WL,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

 	    renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Years-of-experience",renderer,"text",YX,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    	    renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Skills",renderer,"text",SKILL,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	    
             

	     
}


	    store =gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING);



            f=fopen("point.txt","r");
            if (f!=NULL){
		while (fscanf(f,"%s %s %s %s %s %s %d %s",id,name,surname,age,gender,wl,&yx,skill)!=EOF) {
            gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,ID,id,NAME,name,SUR,surname,AGE,age,GENDER,gender,WL,wl,YX,yx,SKILL,skill,-1);
		}
		
		fclose(f);
}
            gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
            g_object_unref(store);
}

int modifier_user( char *id, user nouv )
{
    
    user p;
    FILE * f=fopen("point.txt", "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
        while(fscanf(f,"%s %s %s %s %s %s %d %s\n",p.id,p.name,p.surname,p.age,p.gender,p.wl,&p.yx,p.skill)!=EOF)
        {
            if(strcmp(p.id,id)!=0)
            {



                fprintf(f2,"%s %s %s %s %s %s %d %s\n",p.id,p.name,p.surname,p.age,p.gender,p.wl,p.yx,p.skill);
                
            }
            else
{

                fprintf(f2,"%s %s %s %s %s %s  %d %s\n",nouv.id,nouv.name,nouv.surname,nouv.age,nouv.gender,nouv.wl,nouv.yx,nouv.skill);

        }
    }
}
    fclose(f);
    fclose(f2);
    remove("point.txt");
    rename("nouv.txt", "point.txt");
    return 1;

}
int supprimer_user( char *l)
{
    
    user p;  
    FILE * f=fopen("point.txt", "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f==NULL || f2==NULL)
 return 0;
else
   {
        while(fscanf(f,"%s %s %s %s %s %s %d %s\n",p.id,p.name,p.surname,p.age,p.gender,p.wl,&p.yx,p.skill)!=EOF)
        {
            if(strcmp(p.id,l)!=0)
               
                fprintf(f2,"%s %s %s %s %s %s %d %s\n",p.id,p.name,p.surname,p.age,p.gender,p.wl,p.yx,p.skill);
        }
    }
    fclose(f);
    fclose(f2);
    remove("point.txt");
    rename("nouv.txt", "point.txt");
   
}
void rechercher_user(GtkWidget *liste,char*type)
{
GtkCellRenderer *renderer ;
GtkTreeViewColumn *column ;
GtkTreeIter iter ;
GtkListStore *store ;

user p ;
 

char name[50];
char surname[50];
char gender[50];
char wl[50];
char skill[50];
char age[50];
char id[50];
int yx;

store=NULL;

FILE *f ;


store=gtk_tree_view_get_model(liste);
if (store == NULL)
{
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("ID",renderer,"text",ID,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Name",renderer,"text",NAME,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Surname",renderer,"text",SUR,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Age",renderer,"text",AGE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Gender",renderer,"text",GENDER,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

 	    renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("work-location",renderer,"text",WL,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

 	    renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Years-of-experience",renderer,"text",YX,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    	    renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("Skills",renderer,"text",SKILL,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
             

	     
}


	    store =gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING);



           f=fopen("point.txt","r");
            if (f!=NULL){
		while (fscanf(f,"%s %s %s %s %s %s %d %s",id,name,surname,age,gender,wl,&yx,skill)!=EOF) {
            if(strcmp(type,id)==0){
            gtk_list_store_append(store,&iter);
            gtk_list_store_set(store,&iter,ID,id,NAME,name,SUR,surname,AGE,age,GENDER,gender,WL,wl,YX,yx,SKILL,skill,-1);
		}
		}
		fclose(f);
}
            gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
            g_object_unref(store);
}

