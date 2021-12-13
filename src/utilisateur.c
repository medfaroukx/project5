#ifdef HAVE_CONFIG_H
# include <config.h>
#endif


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utilisateur.h"
#include "callbacks.h"
#include <gtk/gtk.h>



enum 
{
	EID,
	EAGE,
	ECIN,
	ENIVEAU,
	ENOM,
	EPRENOM,
	EROLE,
	ESEXE,
	COLUMNS,
};




int rech(char Idrech)

{
User U;
    FILE *F;
    F=fopen("Utilisateur.txt","r");
    do
    {
       fscanf(F,"%s %d %s %d %s %s %s %s \n",U.Id,&U.Age,U.Cin,&U.Niveau,U.Nom,U.Prenom,U.Role,U.Sexe);
       fflush(stdin);
       if (strcmp(Idrech,U.Id)==0)
       {
           fclose(F);
           return 1;
       }
    } while (!feof(F));

    fclose(F);
    return -1;
    
}


void AjouterUtilisateur(User U)
{
    FILE *F;
    F=fopen("Utilisateur.txt","a+");
if (F!=NULL)
{
   
    fprintf(F,"%s %d %s %d %s %s %s %s \n",U.Id,U.Age,U.Cin,U.Niveau,U.Nom,U.Prenom,U.Role,U.Sexe);

    fclose(F);
}
}


void Recherche(char IdR[])
{
User U;
char texte1[200];
   
	fscanf("%s",IdR);
    FILE *F;
    F=fopen("Utilisateur.txt","r");
    do
    {
        fscanf(F,"%s %d %s %d %s %s %s %s  \n",U.Id,&U.Age,U.Cin,&U.Niveau,U.Nom,U.Prenom,U.Role,U.Sexe);
        if (strcmp(U.Id,IdR)==0)
        {
		return;
        }
    } while (!feof(F));
    fclose(F);
 
}



void SupprimerUtilisateur(char code[50])
{
    FILE *f=NULL;
    FILE *g=NULL;
    User U;
    f=fopen("Utilisateur.txt","r");
    g=fopen("Utilisateur2.txt","a");
    if(f==NULL || g==NULL)
        return;
    else{
        while(fscanf(f,"%s %d %s %d %s %s %s %s \n",U.Id,&U.Age,U.Cin,&U.Niveau,U.Nom,U.Prenom,U.Role,U.Sexe)!=EOF)
    {
        if (strcmp(code,U.Id)!=0 )
            {fprintf(g,"%s %d %s %d %s %s %s %s \n",U.Id,U.Age,U.Cin,U.Niveau,U.Nom,U.Prenom,U.Role,U.Sexe);}
    }
    fclose(f);
    fclose(g);
    remove("Utilisateur.txt");
    rename("Utilisateur2.txt","Utilisateur.txt");
    }

 
}

/*void nbEtudiant()
{
int n1=0;
int n2=0;
int n3=0;
int n4=0;
int n5=0;
 	FILE *f=NULL;
	FILE *g=NULL;
	User U;

	f=fopen("Utilisateur.txt","r");
	if(f==NULL)
        	return;
	else{
        	while(fscanf(f,"%s %d %s %d %s %s %s %s \n",U.Id,&U.Age,U.Cin,&U.Niveau,U.Nom,U.Prenom,U.Role,U.Sexe)!=EOF)
    {
        if ((U.Niveau)==1 )
	{
           n1++;
	}
	else if ((U.Niveau)==2 )
	{
           n2++;
	}
	else if ((U.Niveau)==3 )
	{
           n3++;
	}
	else if ((U.Niveau)==4 )
	{
           n4++;
	}
	else if ((U.Niveau)==5 )
	{
           n5++;
	}

    fclose(f);
    }
g=fopen("etudiant.txt","w+");
fprintf(g,"%d %d %d %d %d",n1,n2,n3,n4,n5); 
fclose(g);
}*/

void ModifierUtilisateur(User U)
{

    FILE *Fich,*F;
    char id;
	int i;
    
    if(rech(id)==1)
    {
     
            F=fopen("Utilisateur.txt","r");
            Fich=fopen("TempUtilisateur.txt","a");
            do
            {
                fscanf(F,"%s %d %s %d %s %s %s %s \n",U.Id,&U.Age,U.Cin,&U.Niveau,U.Nom,U.Prenom,U.Role,U.Sexe);
                if (strcmp(U.Id,id)==0)
               fprintf(F,"%s %d %s %d %s %s %s %s \n",U.Id,U.Age,U.Cin,U.Niveau,U.Nom,U.Prenom,U.Role,U.Sexe);
            } while (!feof(F));
            fclose(Fich);
            fclose(F);
            remove("Utilisateur.txt");
            rename("TempUtilisateur.txt","Utilisateur.txt");
           
            
         }

}



void AfficherTt(GtkWidget *liste)
{

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;


	char Id[50];
    	int Age;
    	char Cin[50];
    	int Niveau;
    	char Nom[100];
    	char Prenom [100];
    	char Role [50];
	char Sexe [20];
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);


	if (store==NULL)
	{
	
	  renderer = gtk_cell_renderer_text_new ();
	  column = gtk_tree_view_column_new_with_attributes("Id" , renderer ,"text" ,EID, NULL);
	  gtk_tree_view_append_column (GTK_TREE_VIEW (liste) , column);

	  renderer = gtk_cell_renderer_text_new ();
	  column = gtk_tree_view_column_new_with_attributes("Age" , renderer ,"text" ,EAGE, NULL);
	  gtk_tree_view_append_column (GTK_TREE_VIEW (liste) , column);

	  renderer = gtk_cell_renderer_text_new ();
	  column = gtk_tree_view_column_new_with_attributes("Cin" , renderer ,"text" ,ECIN, NULL);
	  gtk_tree_view_append_column (GTK_TREE_VIEW (liste) , column);

	  renderer = gtk_cell_renderer_text_new ();
	  column = gtk_tree_view_column_new_with_attributes("Niveau" , renderer ,"text" ,ENIVEAU, NULL);
	  gtk_tree_view_append_column (GTK_TREE_VIEW (liste) , column);

	  renderer = gtk_cell_renderer_text_new ();
	  column = gtk_tree_view_column_new_with_attributes("Nom" , renderer ,"text" ,ENOM, NULL);
	  gtk_tree_view_append_column (GTK_TREE_VIEW (liste) , column);

	  renderer = gtk_cell_renderer_text_new ();
	  column = gtk_tree_view_column_new_with_attributes("Prenom" , renderer ,"text" ,EPRENOM, NULL);
	  gtk_tree_view_append_column (GTK_TREE_VIEW (liste) , column);

	  renderer = gtk_cell_renderer_text_new ();
	  column = gtk_tree_view_column_new_with_attributes("Role" , renderer ,"text" ,EROLE, NULL);
	  gtk_tree_view_append_column (GTK_TREE_VIEW (liste) , column);

	  renderer = gtk_cell_renderer_text_new ();
	  column = gtk_tree_view_column_new_with_attributes("Sexe" , renderer ,"text" ,ESEXE, NULL);
	  gtk_tree_view_append_column (GTK_TREE_VIEW (liste) , column);
	
	}

	store=gtk_list_store_new (COLUMNS , G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);


	f=fopen("Utilisateur.txt","r");
	if(f==NULL)
	  {
		return;
	  }
	else
	{
		f=fopen("Utilisateur.txt","a+");
		while (fscanf(f,"%s %d %s %d %s %s %s %s \n",Id,&Age,Cin,&Niveau,Nom,Prenom,Role,Sexe)!=EOF)
		{
			gtk_list_store_append (store,&iter);
			gtk_list_store_set (store, &iter, EID, Id, EAGE, Age, ECIN, Cin, ENIVEAU, Niveau, ENOM, Nom, EPRENOM, Prenom, EROLE, Role ,ESEXE, Sexe,-1);
		}
		
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
		fclose(f);

	}
}

