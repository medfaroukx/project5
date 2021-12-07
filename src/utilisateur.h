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

int rech(int Idrech);
void AjouterUtilisateur(User U);
void Recherche();
void SupprimerUtilisateur(User U);
void ModifierUtilisateur();
void AfficherTt(GtkWidget *liste);

