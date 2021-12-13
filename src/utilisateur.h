#include<gtk/gtk.h>
typedef struct 
{
    char Id[50];
    int Age;
    char Cin[50];
    int Niveau;
    char Nom[100];
    char Prenom [100];
    char Role [50];
    char Sexe[20];
}User;

int rech(char Idrech);
void AjouterUtilisateur(User U);
void Recherche(char IdR[]);
void SupprimerUtilisateur(char code [50]);
void ModifierUtilisateur(User U);
void AfficherTt(GtkWidget *liste);
//void nbEtudiant();

