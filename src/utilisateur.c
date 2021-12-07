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



int rech(int Idrech)

{
User U;
    FILE *F;
    F=fopen("Utilisateur.txt","r");
    do
    {
       fscanf(F,"%s %d %s %d %s %s %s %s \n",U.Id,&U.Age,U.Cin,&U.Niveau,U.Nom,U.Prenom,U.Role,U.Sexe);
       fflush(stdin);
       if (U.Id==Idrech)
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


void Recherche()
{
User U;
    char IdR;
    printf("Entrer le Id d'Utilisateur à rechrcher\n");
    scanf("%d",&IdR);
    FILE *F;
    F=fopen("Utilisateur.txt","r");
    do
    {
        fscanf(F,"%s ;%d ;%s ;%d ;%s ;%s ;%s;%s \n",U.Id,&U.Age,U.Cin,&U.Niveau,U.Nom,U.Prenom,U.Role,U.Sexe);
        if (IdR == U.Id)
        {
            printf("------ Information sur l'Utilisateur :------\n \n");
            printf("Id\t: %s \n",U.Id);
            printf("Age\t: %d \n",U.Age);
            printf("Cin\t: %s \n",U.Cin);
            printf("Niveau\t: %d \n",U.Niveau);
            printf("Nom :\t%s\n",U.Nom);
            printf("Prenom :\t%s\n",U.Prenom);
            printf("Role :\t%s\n",U.Role);
	    printf("Sexe :\t%s\n",U.Sexe);

        }
    } while (!feof(F));
    fclose(F);
    
}



void SupprimerUtilisateur(User U)
{

    char rep;
    char IdRech;
    printf("Enter le Id d'Utilisateur a supprimer:");
    scanf("%s",IdRech);
    fflush(stdin);
    if (rech(IdRech)==1)
    {
        printf("\n voulez vous le supprimer o/n ?");
        scanf("%c",&rep);
        fflush(stdin);
        if (rep=='o'|| rep =='O')
        {
            FILE *Fich,*F;
            F=fopen("Utilisateur.txt","r");
            Fich=fopen("TempUtilisateur.txt","a");
            do
            {
                fscanf(F,"%s ;%d ;%s ;%d ;%s ;%s ;%s;%s \n",U.Id,&U.Age,U.Cin,&U.Niveau,U.Nom,U.Prenom,U.Role,U.Sexe);
                if ( strcmp(IdRech,U.Id)!=0)
                {
                   fprintf(F,"%s ;%d ;%s ;%d ;%s ;%s ;%s;%s \n",U.Id,U.Age,U.Cin,U.Niveau,U.Nom,U.Prenom,U.Role,U.Sexe);
                }
                
            } while (!feof(F));
            
            fclose(Fich);
            fclose(F);
            remove("Utilisateur.txt");
            rename("TempUtilisateur.txt","Utilisateur.txt");
            printf("suppression avec succees");
        }
    }
    else
    {
        printf("\n Ce Id d'Utilisateur n'exixte pas");
    }
}




void ModifierUtilisateur()
{
User U;
    FILE *Fich,*F;
    char id;
	int i;
    char rep='n';
    printf("\n Entrer le Id de l'Utilisateur a modifier :");
    scanf("%s",id);
    fflush(stdin);
    if(rech(id)==1)
    {
        printf("\n voulez vous vraiment modifier o/n ?");
        scanf("%c",&rep);
        fflush(stdin);
        printf("%c",rep);

        if (rep=='o'|| rep =='O')
        {
            F=fopen("Utilisateur.txt","r");
            Fich=fopen("TempUtilisateur.txt","a");
            do
            {
                fscanf(F,"%s ;%d ;%s ;%d ;%s ;%s ;%s;%s \n",U.Id,&U.Age,U.Cin,&U.Niveau,U.Nom,U.Prenom,U.Role,U.Sexe);
                if (strcmp(U.Id,id)==0)
                {
                  
                   printf("\n Entrer le nouveau Nom:");
                   gets(U.Nom);
                   printf("\n Entrer le nouveau Age:");
                   gets(U.Age);
                   printf("\n Entrer le nouveau numero Cin:");
                   gets(U.Cin);
                   printf("\n Entrer le nouveau Niveau:");
                   gets(U.Niveau);
                   printf("\n Entrer le nouveau Prenom:");
                   gets(U.Prenom);
                   printf("\n Entrer la nouvelle Role:");
                   gets(U.Role);
		   printf("\n Entrer le nouveau Sexe:");
                   gets(U.Role);
                }
                fprintf(F,"%s ;%d ;%s ;%d ;%s ;%s ;%s;%s \n",U.Id,U.Age,U.Cin,U.Niveau,U.Nom,U.Prenom,U.Role,U.Sexe);
            } while (!feof(F));
            fclose(Fich);
            fclose(F);
            remove("Utilisateur.txt");
            rename("TempUtilisateur.txt","Utilisateur.txt");
            printf("la modification à reussi");
            
        }
        else
        {
            printf("\n la modification est annule\n");
        }
    }
    else
    {
        printf("\n Ce Id d'Utilisateur n'existe pas \n");
    }

}



void AfficherTt(GtkWidget *liste)
{

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;


	char Id;
    	int Age;
    	char Cin;
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
		while (fscanf(f,"%s %d %s %d %s %s %s %s \n",Id,Age,Cin,Niveau,Nom,Prenom,Role,Sexe)!=EOF)
		{
			gtk_list_store_append (store,&iter);
			gtk_list_store_set (store, &iter, EID, Id, EAGE, Age, ECIN, Cin, ENIVEAU, Niveau, ENOM, Nom, EPRENOM, Prenom, EROLE, Role ,ESEXE, Sexe,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}


    
}


