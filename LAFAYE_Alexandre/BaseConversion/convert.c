/* Fichier : convert.c
 * Auteur  : Alexandre Lafaye
 * Date    : 01.10.2015
 *
 * But     :  Convertir les valeurs non-signées dans des bases entre 16 et 2.
 *
 *
 * Remarque(s) : Le code est loin d'est optimal, mais il s'agissait en partie de se 'dérouiller' avec les structures de controles et les formats.
 *
 *
 * Compilateur : g++
 */
//To uncomment for windows
//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

//Définitions de types plus 'naturels'
typedef int bool;
#define true 1
#define false 0

//Fonction pour remplacer les valeurs calculées sous forme d'int en char et remplacer les valeurs > 10 par leur lettres habotuelles de l'alphabet.
char characterize(int a)
{
    char out;
    switch(a)
    {
	case 10:
	    out = 'A';
	    break;
	case 11:
	    out = 'B';
	    break;
	case 12:
	    out = 'C';
	    break;
	case 13:
	    out = 'D';
	    break;
	case 14:
	    out = 'E';
	    break;
	case 15:
	    out = 'F';
	    break;
	default:
	    out = a + '0';
    }
    return out;
}

int main(void)
{
    printf ("Programme convertissant en n'importe quelle base de 2 à 16 un nombre en base décimal compris entre 0 et 255.\n");

    int num, base, tempres;

    //Phase d'entrée des données utilisateur
    printf("Entrez une valeur entière     [0-255] :");
    scanf("%d", &num);
    printf("Entrer une base de conversion [2-16] :");
    scanf("%d", &base);

    if((base>16) || (base<2))
    {
	printf("La base %d n'est pas dans les valeurs comprises!", base);
	return 1;
    }

    //Determination du nombre exact de digits nécessaires à la représentation dans la nouvelle base.
    int digit = 0;
    bool enoughdigit = false;
    while(enoughdigit==false)
    {
	digit++;
	enoughdigit = pow(base, digit) > (double)num;
    }

    //La boucle principale qui change les nombre de base en utilisant des modulos pour générer les restes et ensuite on calcule le résultat de la division arrondie à l'entier du dessous pour recommencer ensuite.
    int resultint[digit];
    char resultchar[digit];
    int i = 0;
    while(num>0)
    {
	tempres = num % base;

	resultint[i] = (char)tempres;
	num = floor((double)num/(double)base);

	i++;
    }

    //Sortie finale des données mise en forme.
    printf("En base %d: ", base);
    for(int j=0; j<digit; j++)
    {
	printf("%c", characterize(resultint[j]));
    }
    printf("\n");

    printf("Presser RETURN pour continuer...");
    getchar();
    return 0;
}
