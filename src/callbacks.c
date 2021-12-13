#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#define _GNU_SOURCE
 
#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "callbacks.h"
#include "interface.h"
#include "utilisateur.h"
#include "support.h"




int x;
int t[3]={0,0,0};

void
on_button_ajouter_utilisateurFK_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Bienvenue;
Bienvenue=create_Ajouter_utilisateur();
gtk_widget_show (Bienvenue);
}


void
on_button_rechercher_utilisateur_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Bienvenue;
Bienvenue=create_Rechercher_utilisateur();
gtk_widget_show (Bienvenue);
}


void
on_button_supprimer_utilisateur_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Bienvenue;
Bienvenue=create_Supprimer_utilisateur();
gtk_widget_show (Bienvenue);
}


void
on_button_modifier_utilisateurFK_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Bienvenue;
Bienvenue=create_Modifer_utilisateur();
gtk_widget_show (Bienvenue);
}


void
on_checkbutton1FK_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
	{t[0]=1;}
}


void
on_checkbutton2FK_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
	{t[1]=1;}
}


void
on_checkbutton3FK_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
	{t[2]=1;}
}


void
on_radiobutton1FK_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
	{x=1;}
}

void
on_radiobutton2FK_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
	{x=2;}
}


void
on_button_valider1FK_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
FILE *f=NULL;
GtkWidget *Id, *Age,*Cin, *Niveau, *Nom, *Prenom, * Sexe, *Role ,*Ajouter_utilisateur ;


/*char id;
int age;
char cin;
int niveau;
char niv[50];
char nom[100];
char prenom [100];
char sexe[20]="Male";
char role[50]="";*/
char niv[50];

User U;

Ajouter_utilisateur = lookup_widget(objet_graphique,"Ajouter_utilisateur");
if(x==1)
strcpy(U.Sexe,"Male");
else
if(x==2)
strcpy(U.Sexe,"Femelle");

if(t[0]==1) 
strcpy(U.Role,"Etudiant");
if(t[1]==1) 
strcpy(U.Role,"Enseignant");
if(t[2]==1) 
strcpy(U.Role,"Agent");



Id=lookup_widget(objet_graphique,"entry1FK");
Nom=lookup_widget(objet_graphique,"entry2FK");
Prenom=lookup_widget(objet_graphique,"entry3FK");
Cin=lookup_widget(objet_graphique,"entry4FK");
Niveau=lookup_widget(objet_graphique,"combobox1FK");
Age=lookup_widget(objet_graphique,"spinbutton1FK");

strcpy(U.Id,gtk_entry_get_text(GTK_ENTRY(Id)));
strcpy(U.Nom,gtk_entry_get_text(GTK_ENTRY(Nom)));
strcpy(U.Prenom,gtk_entry_get_text(GTK_ENTRY(Prenom)));
strcpy(U.Cin,gtk_entry_get_text(GTK_ENTRY(Cin)));
strcpy(niv, gtk_combo_box_get_active_text(GTK_COMBO_BOX(Niveau)));
U.Niveau=atoi(niv);
U.Age=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Age)) ;



//f=fopen("Utilisateur.txt","r+");
/*if (f!=NULL)
{
fprintf (f,"%d ;%d ;%d ;%d ;%s ;%s ;%s;%s \n",User.Id,User.Age,User.Cin,User.Niveau,User.Nom,User.Prenom,User.Role,User.Sexe);
fclose(f);

}
else 
printf("\n not found");*/

AjouterUtilisateur(U);

	
}



void
on_button_retourner1FK_activate        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Ajouter_utilisateur;
Ajouter_utilisateur=create_Bienvenue();
gtk_widget_show (Ajouter_utilisateur);
}


void
on_button_retourner2FK_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Afficher_utilisatuer;
Afficher_utilisatuer=create_Bienvenue();
gtk_widget_show (Afficher_utilisatuer);
}


void
on_radiobutton3FK_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
	{x=1;}
}


void
on_radiobutton4FK_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
	{x=2;}
}


void
on_checkbutton4FK_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
	{t[0]=1;}
}


void
on_checkbutton5FK_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
	{t[1]=1;}
}


void
on_checkbutton6FK_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
	{t[2]=1;}
}


void
on_button_retourner3FK_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Modifer_utilisateur;
Modifer_utilisateur=create_Bienvenue();
gtk_widget_show (Modifer_utilisateur);
}


void
on_button_valider2FK_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Id, *Age,*Cin, *Niveau, *Nom, *Prenom, * Sexe, *Role ,*Modifer_utilisateur ;


char niv[50];

User U;

Modifer_utilisateur = lookup_widget(objet_graphique,"Modifer_utilisateur");
if(x==1)
strcpy(U.Sexe,"Male");
else
if(x==2)
strcpy(U.Sexe,"Femelle");

if(t[0]==1) 
strcpy(U.Role,"Etudiant");
if(t[1]==1) 
strcpy(U.Role,"Enseignant");
if(t[2]==1) 
strcpy(U.Role,"Agent");



Id=lookup_widget(objet_graphique,"entry5");
Nom=lookup_widget(objet_graphique,"entry6");
Prenom=lookup_widget(objet_graphique,"entry7");
Cin=lookup_widget(objet_graphique,"entry8");
Niveau=lookup_widget(objet_graphique,"combobox2");
Age=lookup_widget(objet_graphique,"spinbutton2");

strcpy(U.Id,gtk_entry_get_text(GTK_ENTRY(Id)));
printf("%s \n",Id);
strcpy(U.Nom,gtk_entry_get_text(GTK_ENTRY(Nom)));
strcpy(U.Prenom,gtk_entry_get_text(GTK_ENTRY(Prenom)));
strcpy(U.Cin,gtk_entry_get_text(GTK_ENTRY(Cin)));
strcpy(niv, gtk_combo_box_get_active_text(GTK_COMBO_BOX(Niveau)));
U.Niveau=atoi(niv);
U.Age=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Age)) ;



ModifierUtilisateur(U);

	
}


void
on_button_retourner4FK_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Rechercher_utilisateur;
Rechercher_utilisateur=create_Bienvenue();
gtk_widget_show (Rechercher_utilisateur);
}


void
on_button_okFK_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget* output, *IdR , *Id, *Age,*Cin, *Niveau, *Nom, *Prenom, * Sexe, *Role;
User U;
char idr[30];

char message[500];
char texte1[100];
char texte2[100];


IdR=lookup_widget(button,"entry9");
strcpy(idr,gtk_entry_get_text(GTK_ENTRY(IdR)));
Recherche(idr);

sprintf(texte1, "%d", U.Age);
sprintf(texte2, "%d", U.Niveau); 

strcat(message,"l'id:");
strcat(message," ");
strcat(message,U.Id);
strcat(message," age");
strcat(message,":");
strcat(message,texte1 );
strcat(message,"ans");
strcat (message," // ");
strcat(message,"cin:");
strcat(message,"  ");
strcat(message,U.Cin);
strcat (message," // ");
strcat(message,"niveau:");
strcat(message," ");
strcat(message,texte2);
strcat (message," // ");
strcat(message,"Nom:");
strcat(message," ");
strcat(message,U.Nom);
strcat(message,"prenom:");
strcat(message," ");
strcat(message,U.Prenom);
strcat(message," Sexe");
strcat(message,":");
strcat(message,U.Sexe );
strcat (message," // ");
strcat(message,"Role:");
strcat(message,"  ");
strcat(message,U.Role);



output = lookup_widget(button,"label31");
gtk_label_set_text(GTK_LABEL(output),message);   

}


void
on_button_valider3FK_clicked           (GtkWidget      *objet_graphique,
                                        gpointer         user_data)

{ 
char code[50];

FILE *f=NULL;
GtkWidget *Code ;

GtkWidget *Supprimer_utilisateur;


Supprimer_utilisateur=lookup_widget(objet_graphique,"Supprimer_utilisateur");

Code = lookup_widget(objet_graphique, "entry10") ;
strcpy(code,gtk_entry_get_text(GTK_ENTRY(Code)));
printf("%s \n",code);     

SupprimerUtilisateur(code);


Supprimer_utilisateur=create_confirmation();
gtk_widget_show (Supprimer_utilisateur);

}


void
on_button_retourner5FK_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Supprimer_utilisateur;
Supprimer_utilisateur=create_Bienvenue();
gtk_widget_show (Supprimer_utilisateur);
}


/*void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gint* Id;
    	gint* Age;
    	gint* Cin;
    	gint* Niveau;
    	gchar* Nom;
    	gchar* Prenom;
    	gchar* Role;
	gchar* Sexe;
	 User U;
	
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter , path))
	{
		gtk_tree_model_get (GTK_LIST_STORE(model), Id , 0, &Nom, 1, Prenom, 2, Cin , 3,&Age, 4,Niveau, 5 ,Role ,6 ,Sexe ,-1);
	
		strcpy(U.Id,Id);
		strcpy(U.Nom,Nom);
		strcpy(U.Prenom,Prenom);
		strcpy(U.Cin,Cin);
		strcpy(U.Age,Age);
		strcpy(U.Niveau,Niveau);
		strcpy(U.Role,Role);
		strcpy(U.Sexe,Sexe);


		AfficherTt(treeview);
		
	}
}

*/
void
on_button_afficher_utilisateurFK_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Bienvenue;
GtkWidget *treeview1;
User U;
GtkWidget *Afficher_utilisatuer;

Bienvenue=lookup_widget(button,"Bienvenue");
gtk_widget_destroy (Bienvenue);

Afficher_utilisatuer=lookup_widget(button,"Afficher_utilisatuer");
Afficher_utilisatuer=create_Afficher_utilisatuer();
gtk_widget_show (Afficher_utilisatuer);

treeview1=lookup_widget(Afficher_utilisatuer,"treeview1");
AfficherTt(treeview1);
}


void
on_button_calculer_niveauFK_clicked    (GtkWidget       *button,
                                        gpointer         user_data)
{
/*GtkWidget *output1, *output2, *output3, *output4,*output5;
GtkWidget *Bienvenue;
char message1[500];
char message2[500];
char message3[500];
char message4[500];
char message5[500];


char num1[10];
char num2[10];
char num3[10];
char num4[10];
char num5[10];

FILE *f;
f=fopen("etudiant.txt","w+");
output1 = lookup_widget(button,"label1annerFK");
output2 = lookup_widget(button,"label2annerFK");
output3 = lookup_widget(button,"label3annerFK");
output4 = lookup_widget(button,"label4annerFK");
output5 = lookup_widget(button,"label5annerFK");

strcpy(message1,"");
strcpy(message2,"");
strcpy(message3,"");
strcpy(message4,"");
strcpy(message5,"");

nbEtudiant();

f=fopen("etudiant.txt","r+");
fscanf(f,"%s %s %s %s %s",num1,num2,num3,num4,num5);
fclose(f);



strcat(message1,"1ere_annee:");
strcat(message1," ");
strcat(message1,num1);

strcat(message2,"2eme_annee:");
strcat(message2," ");
strcat(message2,num2);

strcat(message3,"3eme_annee:");
strcat(message3,"  ");
strcat(message3,num3);

strcat(message4,"4eme_annee:");
strcat(message4," ");
strcat(message4,num4);

strcat(message5,"5eme_annee:");
strcat(message5," ");
strcat(message5,num5);


gtk_label_set_text(GTK_LABEL(output1),message1);


gtk_label_set_text(GTK_LABEL(output2),message2);


gtk_label_set_text(GTK_LABEL(output3),message3);


gtk_label_set_text(GTK_LABEL(output4),message4);


gtk_label_set_text(GTK_LABEL(output5),message5);



Bienvenue=create_nbr_niveau();
gtk_widget_show (Bienvenue);
*/
}

void
on_button_retourner10FK_clicked        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Bienv;
Bienv=create_Bienvenue();
gtk_widget_show (Bienv);
}

