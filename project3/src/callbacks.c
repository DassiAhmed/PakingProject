#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "user.h"
#include "client.h"
#include "login.h"

int G[] = {0,0,0,0,0,0};
int G1[] = {0,0,0,0,0,0};
void
on_logout_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_deletA_clicked                      (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *espace_admin;
GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p;
        gchar*id ;
	espace_admin=lookup_widget(objet_graphique,"espace_admin");
        p=lookup_widget(espace_admin,"treeview_agent");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);
            if (id == NULL) {
        fprintf(stderr, "Error: id is NULL\n");
        return 0;
}
           supprimer_user(id);
        }
}


void
on_refershA_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *espace_admin;
GtkWidget *treeviewd;
espace_admin=lookup_widget(objet_graphique,"espace_admin");
treeviewd=lookup_widget(espace_admin,"treeview_agent");
afficher_USER(treeviewd);


}


void
on_editA_clicked                       (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *espace_admin;
GtkWidget *mod_agent;
GtkWidget *p;
int x;
gchar*id ;
gchar*name ;
gchar*surname ;
gchar*age ;
gint yx ;
gchar*gender ;
gchar*wl ;
gchar*skill ;
GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
espace_admin=lookup_widget(objet_graphique,"espace_admin");
mod_agent = create_mod_agent ();
 gtk_widget_show (mod_agent);

gtk_widget_hide(espace_admin);


p=lookup_widget(espace_admin,"treeview_agent");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,1,&name,2,&surname,3,&age,4,&gender,5,&wl,6,&yx,7,&skill,-1);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(mod_agent,"entrynamem")),name);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(mod_agent,"entrysurnamem")),surname);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(mod_agent,"entryagem")),age);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(mod_agent,"entryidm")),id);
gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(mod_agent,"spinbuttonymod")),yx);


		if(strcmp(wl,"North-parking-lot")==0) x=0;
                if(strcmp(wl,"East-parking-lot")==0) x=1;
		if(strcmp(wl,"West-parking-lot")==0) x=2;
		if(strcmp(wl,"Sout-parking-lot")==0) x=3;
		 gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(mod_agent,"comboboxentrywlm")),x);

}



}


void
on_addA_clicked                        (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *espace_admin;
GtkWidget *Add_agent;

espace_admin=lookup_widget(objet_graphique,"espace_admin");
Add_agent = create_Add_agent ();
gtk_widget_show (Add_agent);
gtk_widget_hide(espace_admin);
}


void
on_findA_clicked                       (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
char id[23];
GtkWidget *find;
GtkWidget *espace_admin;
GtkWidget *p1;
user p;
espace_admin=lookup_widget(objet_graphique,"espace_admin");
p1=lookup_widget(espace_admin,"treeview_agent");
find = lookup_widget(objet_graphique, "entryfindA") ;
strcpy(id,gtk_entry_get_text(GTK_ENTRY(find)));
rechercher_user(p1,id);

}


void
on_calendar1_day_selected_double_click (GtkCalendar     *objet_graphique,
                                        gpointer         user_data)
{
char buffer[256];
char yearr[20];
char monthh[10];
char dayy[10];
char yeardate[50];
GtkWidget *Add_agent;
guint year;
guint month;
guint day;
GtkWidget *Calendar;
GtkLabel *message;
user p;
Add_agent=lookup_widget(objet_graphique,"espace_admin");
Calendar=lookup_widget(objet_graphique,"calendar1");
gtk_calendar_get_date(GTK_CALENDAR(Calendar),&year,&month,&day);
sprintf(yearr,"%d",year);
sprintf(monthh,"%d",month+1);
sprintf(dayy,"%d",day);

strcat(yeardate,dayy);
strcat(yeardate,"/");
strcat(yeardate,monthh);
strcat(yeardate,"/");
strcat(yeardate,yearr);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(Add_agent,"entryfindu")),yeardate);
}


void
on_findu_clicked                       (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
char date[23];
GtkWidget *find;
GtkWidget *espace_admin;
GtkWidget *p1;
citoyen p;
espace_admin=lookup_widget(objet_graphique,"espace_admin");
p1=lookup_widget(espace_admin,"treeviewHuser");
find = lookup_widget(objet_graphique, "entryfindu") ;
strcpy(date,gtk_entry_get_text(GTK_ENTRY(find)));
rechercher_client(p1,date);
}


void
on_monitoring_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
system("cheese"); //if not solved 
//vlc com.mp4 
}


void
on_calendar2_day_selected_double_click (GtkCalendar     *objet_graphique,
                                        gpointer         user_data)
{
char buffer[256];
char yearr[20];
char monthh[10];
char dayy[10];
char yeardate[50];
GtkWidget *Add_agent;
guint year;
guint month;
guint day;
GtkWidget *Calendar;
GtkLabel *message;
user p;
Add_agent=lookup_widget(objet_graphique,"Add_agent");
Calendar=lookup_widget(objet_graphique,"calendar2");
gtk_calendar_get_date(GTK_CALENDAR(Calendar),&year,&month,&day);
sprintf(yearr,"%d",year);
sprintf(monthh,"%d",month+1);
sprintf(dayy,"%d",day);

strcat(yeardate,dayy);
strcat(yeardate,"/");
strcat(yeardate,monthh);
strcat(yeardate,"/");
strcat(yeardate,yearr);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(Add_agent,"entryage")),yeardate);

}


void
on_radiobuttonmaleadd_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
G[0] = 1;
else
G[0] = 0;

}


void
on_radiobuttonfemaleadd_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
G[1] = 1;
else
G[1] = 0;

}


void
on_checkbuttonvadd_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
G[2] = 1;
else
G[2] = 0;

}


void
on_checkbuttoncadd_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
G[3] = 1;
else
G[3] = 0;

}


void
on_checkbuttonsadd_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
G[4] = 1;
else
G[4] = 0;

}


void
on_checkbuttonfadd_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
G[5] = 1;
else
G[5] = 0;

}


void
on_addag_clicked                       (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*ID;
GtkWidget*name;
GtkWidget*surname;
GtkWidget *combobox;
GtkWidget *agentad;
GtkWidget*age;
user p;
agentad=lookup_widget(objet_graphique,"Add-agent");
name = lookup_widget(objet_graphique, "entryname") ;
surname = lookup_widget(objet_graphique, "entrysurname") ;
ID = lookup_widget(objet_graphique, "entryid") ;
age = lookup_widget(objet_graphique, "entryage") ;
strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(ID)));
strcpy(p.name,gtk_entry_get_text(GTK_ENTRY(name)));
strcpy(p.surname,gtk_entry_get_text(GTK_ENTRY(surname)));
strcpy(p.age,gtk_entry_get_text(GTK_ENTRY(age)));
combobox=lookup_widget(objet_graphique,"comboboxentrywladd");
strcpy(p.wl,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));
p.yx=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(objet_graphique,"spinbuttonyadd")));
if (G[0]==1)
{
strcpy(p.gender,"Male");
}
else if (G[1]==1)
{
strcpy(p.gender,"Female");
}

if (G[2]==1)
{
strcpy(p.skill,"vehicle_maintenance ");}
else if (G[3]==1){
strcpy(p.skill,"customer_service");}
else if (G[4]==1){
strcpy(p.skill,"security");}
else if (G[5]==1){
strcpy(p.skill,"First_Aide ");}
ajouter_user(p);
}


void
on_backadd_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *espace_admin;
GtkWidget *Add_agent;

Add_agent=lookup_widget(objet_graphique,"Add_agent");
espace_admin = create_espace_admin ();
gtk_widget_show (espace_admin);
gtk_widget_hide(Add_agent);

}


void
on_calendar3_day_selected_double_click (GtkCalendar     *objet_graphique,
                                        gpointer         user_data)
{
char buffer[256];
char yearr[20];
char monthh[10];
char dayy[10];
char yeardate[50];
GtkWidget *mod_agent;
guint year;
guint month;
guint day;
GtkWidget *Calendar;
GtkLabel *message;
user p;
mod_agent=lookup_widget(objet_graphique,"mod_agent");
Calendar=lookup_widget(objet_graphique,"calendar3");
gtk_calendar_get_date(GTK_CALENDAR(Calendar),&year,&month,&day);
sprintf(yearr,"%d",year);
sprintf(monthh,"%d",month+1);
sprintf(dayy,"%d",day);

strcat(yeardate,dayy);
strcat(yeardate,"/");
strcat(yeardate,monthh);
strcat(yeardate,"/");
strcat(yeardate,yearr);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(mod_agent,"entryagem")),yeardate);
}


void
on_radiobuttonmalem_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
G1[0] = 1;
else
G1[0] = 0;
}


void
on_radiobuttonfemalem_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
G1[1] = 1;
else
G1[1] = 0;
}


void
on_checkbuttonfmod_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
G1[2] = 1;
else
G1[2] = 0;

}


void
on_checkbuttonvmod_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
G1[3] = 1;
else
G1[3] = 0;
}


void
on_checkbuttonsmod_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
G1[4] = 1;
else
G1[4] = 0;
}


void
on_checkbuttoncmod_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
G1[5] = 1;
else
G1[5] = 0;
}


void
on_backmod_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *espace_admin;
GtkWidget *mod_agent;

mod_agent=lookup_widget(objet_graphique,"mod_agent");
espace_admin = create_espace_admin ();
gtk_widget_show (espace_admin);
gtk_widget_hide(mod_agent);

}


void
on_modag_clicked                       (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget*ID;
GtkWidget*name;
GtkWidget*surname;
GtkWidget *combobox;
GtkWidget *l;
GtkWidget*age;
user p;
l=lookup_widget(objet_graphique,"mod_agent");
name = lookup_widget(objet_graphique, "entrynamem") ;
surname = lookup_widget(objet_graphique, "entrysurnamem") ;
ID = lookup_widget(objet_graphique, "entryidm") ;
age = lookup_widget(objet_graphique, "entryagem") ;
strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(ID)));
strcpy(p.name,gtk_entry_get_text(GTK_ENTRY(name)));
strcpy(p.surname,gtk_entry_get_text(GTK_ENTRY(surname)));
strcpy(p.age,gtk_entry_get_text(GTK_ENTRY(age)));
combobox=lookup_widget(objet_graphique,"comboboxentrywlm");
strcpy(p.wl,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));
p.yx=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(objet_graphique,"spinbuttonymod")));
if (G1[0]==1)
{
strcpy(p.gender,"Male");
}
else if (G1[1]==1)
{
strcpy(p.gender,"Female");
}

if (G1[2]==1)
{
strcpy(p.skill,"vehicle_maintenance ");}
else if (G1[3]==1){
strcpy(p.skill,"customer_service");}
else if (G1[4]==1){
strcpy(p.skill,"security");}
else if (G1[5]==1){
strcpy(p.skill,"First_Aide ");}
modifier_user(p.id,p);
}


void
on_arc_clicked                         (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *espace_admin;
GtkWidget *treeviewd;
espace_admin=lookup_widget(objet_graphique,"espace_admin");
treeviewd=lookup_widget(espace_admin,"treeviewHuser");
afficher_Client(treeviewd);
}


void
on_calendarclient_day_selected_double_click
                                        (GtkCalendar     *calendar,
                                        gpointer         user_data)
{

}


void
on_1_toggled                           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_2_toggled                           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_3_toggled                           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_4_toggled                           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_5_toggled                           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_6_toggled                           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_7_toggled                           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_8_toggled                           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_9_toggled                           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_10_toggled                          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_11_toggled                          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_12_toggled                          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_13_toggled                          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_14_toggled                          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_15_toggled                          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_16_toggled                          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_17_toggled                          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_18_toggled                          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_19_toggled                          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_20_toggled                          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_21_toggled                          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_22_toggled                          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_23_toggled                          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_24_toggled                          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_buttonrefrc_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttoncr_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_lougoutclient_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button3_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
int x;
GtkWidget*w;
GtkWidget*log1;
GtkWidget*pass;
GtkWidget *treeviewd1;
GtkWidget *client;
char password[23];
char log[23];
GtkWidget *espace_admin;
espace_admin = create_espace_admin ();
log1= lookup_widget(objet_graphique, "entryuserl") ;
pass= lookup_widget(objet_graphique, "entrypasswordl") ;
strcpy(password,gtk_entry_get_text(GTK_ENTRY(pass)));
strcpy(log,gtk_entry_get_text(GTK_ENTRY(log1)));
w=lookup_widget(objet_graphique,"window1");
x=verifier(log,password);
client= create_client ();
switch(x)
{
case 1:gtk_widget_show (espace_admin);
gtk_widget_hide(w);
case 2:gtk_widget_show (client);
gtk_widget_hide(w);
  break;
}

}
