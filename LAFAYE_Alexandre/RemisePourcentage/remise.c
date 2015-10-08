/* Fichier : remise.c
 * Auteur  : Alexandre Lafaye
 * Date    : 01.10.2015
 *
 * But     :  Calculer la valeur d'une remise en fonction de la somme.
 *
 *
 * Remarque(s) : 
 *
 *
 * Compilateur : g++
 */
//To uncomment for windows
//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    printf("Programme calculant et affichant une remise en fonction de somme initiale.\n");

    int remise, ini_sum;
    double deduc, fin_sum, fin_sum_arr;

    //Entrée de données utilisateurs
    printf("Programme remise\n");
    printf("Donnez la somme initiale: ");
    scanf("%d", &ini_sum);
    printf("Donnez le %c de remise (ex: 4 pour 4%c): ", 0x25, 0x25);
    scanf("%d", &remise);

    //Calcul de la deduction en francs puis de la somme finale
    deduc = ((double)ini_sum * ((double)remise/100));
    fin_sum = ini_sum - deduc;

    fin_sum_arr = floor(fin_sum);

    //Finalement output du calcul
    if(abs(deduc)<=1.)
	printf("La remise et de %.2f franc\n", deduc);
    else
	printf("La remise et de %.2f francs\n", deduc);

    if(abs(fin_sum)<=1.)
	printf("    Il vous reste donc à payer %.2f.- franc arrondi à: %.0f.-\n", fin_sum, fin_sum_arr);
    else
	printf("    Il vous reste donc à payer %.2f.- francs arrondi à: %.0f.-\n", fin_sum, fin_sum_arr);

    getchar();
    return 0;
}
