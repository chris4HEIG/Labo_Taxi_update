/*
-----------------------------------------------------------------------------------
Nom du fichier : TP2_GrpC_CourseTaxi.cpp
Auteur(s) : Timothé Antille, Valentin Bonzon
Date creation : 06.10.2022
Modification  : 11.10.2022
Description : Ce programme à pour but d'afficher le prix d'une course de taxi
              en fonction :
              - du prix de base de la prise en charge
              - du nombre de bagage
              - de la durée du trajet
              - du type de trajet (jour/nuit)
Remarque(s) : Les erreurs de saisie ne sont pas gérée
              Les valeurs incorrectes provoquent l'arrêt du programme et affiche
              un message d'alerte

Compilateur : Mingw-w64 g++ 11.1.0
-----------------------------------------------------------------------------------
*/



//-------------------------------------------------------------------
//                       Ajout des librairies
//-------------------------------------------------------------------

#include <iostream> // Ajoute les opérateurs de flux
#include <limits>   // Pour le buffer
#include <iomanip>  // Permet de setw pour la mise en page


using namespace std;
int main() {

    //-------------------------------------------------------------------
    //                       Déclaration de variables
    //-------------------------------------------------------------------

    //Déclaration des constantes
    const float PRIX_BASE   = 5.0f;
    const float PRIX_BAGAGE = 2.6f;
    const float PRIX_JOUR   = 1.0f;
    const float PRIX_NUIT   = 1.6f;
    const int   DEBUT_JOUR  = 8;
    const int   FIN_JOUR    = 20;

    //Constantes des intervalles pour les tests
    const int MAX_BAGAGE    = 4;
    const int MAX_KM        = 500;
    const int JOUR_MIN      = 8;
    const int JOUR_MAX      = 20;
    const int MAX_HEURE     = 23;
    const int MAX_VITESSE   = 120;
    const int MIN_VITESSE   = 50;

    //Déclaration des variables
    int     nbrBagage;
    int     heureDepart;
    double  distance;
    int     vitesse;
    double  temps;
    double  totalBagage;
    double  totalCourse;
    double  total;

    //Constantes pour l'affichage
    const int PRECISION = 2;
    const int ESPACE    = 6;

    //Création d'une instruction pré-processeur qui quitte le programme
#define TERMINER_PROGRAMME cout << "Presser ENTER pour quitter le programme" << endl; \
                               cin.ignore(numeric_limits<streamsize>::max(), '\n'); return 3


    //-------------------------------------------------------------------
    //                             Bienvenue
    //-------------------------------------------------------------------


    //Message de bienvenue
    cout << "Bienvenue dans le programme CourseTaxi ! "                    << endl
         << "Vous pouvez choisir les options de votre course et nous "
            "feront le calcul pour vous."                                  << endl
         << endl;
    cout << fixed << setprecision(PRECISION); // choix du nombre de chiffres après la virgule

    //Affichage des options
    cout << "Voici les options disponibles     : "                         << endl;
    cout << "==================================="                          << endl;
    cout << " - prise en charge    : " << setw(ESPACE) << PRIX_BASE     << endl;
    cout << " - supp par bagage    : " << setw(ESPACE) << PRIX_BAGAGE   << endl;
    cout << " - tarif/min (jour)   : " << setw(ESPACE) << PRIX_JOUR     << endl;
    cout << " - tarif/min (nuit)   : " << setw(ESPACE) << PRIX_NUIT     << endl;
    cout << " - heures de jour     :"  << setw(ESPACE-3)  // Corriger un problème d'affichage
         << "[" << JOUR_MIN           << "-" << JOUR_MAX << "]"            << endl;


    //-------------------------------------------------------------------
    //                       Saisie des informations
    //-------------------------------------------------------------------


    //Saisie du nombre de bagage
    cout << "Combien de bagages transportez-vous ? (MAX 4):";
    cin >> nbrBagage;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //Contrôle du nombre de bagage
    if(nbrBagage > MAX_BAGAGE or nbrBagage < 0){

        cout << "Veuillez saisir entre 0 et " << MAX_BAGAGE << " bagages au maximum" <<
             endl;
        TERMINER_PROGRAMME;

    }

    //Saisie de la distance
    cout << "Quelle distance[km] allez-vous parcourir ? (MAX 500):";
    cin >> distance;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //Contrôle de la distance
    if(distance > MAX_KM or distance < 0){

        cout << "Veuillez saisir une distance entre 0 et " << MAX_KM << "km"<< endl;
        TERMINER_PROGRAMME;
    }

    //Saisie de la vitesse
    cout << "A quelle vitesse[km/h] allez-vous voyager ? (50 - 120):";
    cin >> vitesse;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //Contrôle de la vitesse
    if(vitesse >= MIN_VITESSE and vitesse <= MAX_VITESSE){

        //Calculer le temps en minutes
        temps = distance / vitesse * 60;

    }else{
        cout << "Veuillez saisir une vitesse entre " << MIN_VITESSE << " et " << MAX_VITESSE << "km/h" << endl;
        TERMINER_PROGRAMME;
    }

    //Saisie de l'heure de départ
    cout << "Quelle est l'heure de votre depart ? (MAX 23):";
    cin >> heureDepart;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //Contrôle de l'heure de départ
    if(heureDepart > MAX_HEURE or heureDepart < 0){

        cout << "Veuillez saisir une heure de depart correcte" << endl;
        TERMINER_PROGRAMME;
    }

    //-------------------------------------------------------------------
    //                       Affichage de la commande
    //-------------------------------------------------------------------
    cout <<                                                                  endl;
    cout << "Votre commande"                                              << endl;
    cout << "==================================="                         << endl;
    cout << " - nbre de bagage     : " << setw(ESPACE) << nbrBagage    << endl;
    //Caster la distance (double) pour ne pas afficher les décimales
    cout << " - distance [km]      : " << setw(ESPACE) << int(distance)<< endl;
    cout << " - vitesse [km/h]     : " << setw(ESPACE) << vitesse      << endl;
    cout << " - h. de depart       : " << setw(ESPACE) << heureDepart  << endl;



    //-------------------------------------------------------------------
    //                       Calcul du tarif
    //-------------------------------------------------------------------

    //Vérifier si c'est un tarif de jour ou de nuit
    if(heureDepart >= DEBUT_JOUR and heureDepart <= FIN_JOUR){

        totalCourse = PRIX_JOUR * temps;

    }else{

        totalCourse = PRIX_NUIT * temps;

    }

    //Calcul du total
    totalBagage = nbrBagage * PRIX_BAGAGE;
    total = PRIX_BASE + totalBagage + totalCourse;

    //-------------------------------------------------------------------
    //                       Affichage final
    //-------------------------------------------------------------------
    cout <<                                                                  endl;
    cout << "Votre ticket :"                                              << endl;
    cout << "==================================="                         << endl;
    cout << " - prise en charge    : " << setw(ESPACE) << PRIX_BASE    << endl;
    cout << " - supp bagages       : " << setw(ESPACE) << totalBagage  << endl;
    cout << " - prix de la course  : " << setw(ESPACE) << totalCourse  << endl;
    cout << " - TOTAL  : "             << setw(ESPACE) << total        << endl;

    TERMINER_PROGRAMME;
}
