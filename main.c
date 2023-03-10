#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1 - creer une fonction qui prend la variable solution, et la variable tableauJoueur (par exemple) : un tableau rempli de 0, cette fonction doit copier certaines valeurs (grace au rand() % N) 
// de solution dans tableauJoueur afin d'initialiser une grille jouable ( car solution est bel est bien la solution, donc pas jouable par définition. ).
// un parametre doit permettre de verifier la condition de victoire en un seul coup (proposer votre façon de faire :) ) 

int generer(int solution[8][8], int grille[8][8], int percent) {
    int count = 64;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((rand()%percent) > 0) {
                grille[i][j] = solution[i][j];
                count--;
            }
        }
    }
    return count;
}


// 2- une fonction saisir qui demande au joueur de saisir 3 informations: i, j , et v qui permettront de placer la valeur v aux coordonnées (i,j)

int saisir(int tab[8][8]) {

    int i, j, v;

    int saisie = 0;
    printf("Veuillez saisir un Y\n");
    scanf("%d", &saisie);
    int saisieX = saisie;
    printf("Veuillez saisir un X\n");
    scanf("%d", &saisie);
    int saisieY = saisie;

    if(tab[saisieX][saisieY] == 2){
        printf("Quelle valeur souhaitez vous inserer ?\n");
        scanf("%d", &saisie);
        int saisieVal = saisie;
        tab[saisieX][saisieY] = saisieVal;
        return 1;
    } 
    else {
        printf("Cette case est deja remplie Reessayez\n");
        return 0;
    }
}

// 3- apres chaque coordonnées il faut verifier les regles du sudoku sur le tableauJoueur donc : 

    // - la fonction verifierLigneColonne ( qui verifie les lignes et les colonnes  sur lesquelles sont la nouvelle valeur)
    // - la fonction verifierGrille (qui fait ceci pour toute la grille et permet de definir la condition de victoire)


int verifierLigneColonne(int tab[8][8], int ligne, int ligneOrCol){
    int result = 0;
    int choices[8];
    int zero = 0;
    int un = 0;
    int next;

    if(ligneOrCol){
        for(int i = 0; i <8; i++){
            int numero = tab[ligne][i];
            choices[i] = numero;
        }
    } 
    else {
        for(int i = 0; i <8; i++){
            int numero = tab[i][ligne];
            choices[i] = numero;
            
        }
    }

    for(int v = 0; v < 5; v++){
        if(choices[v] == choices[v+1] == choices[v+2]){
            next = 0;
        }
        next = 1;

        if(next){
            for(int i = 0; i< 8; i++){
                if(choices[i] == 1 ){
                    un++;
                }
                else{
                    zero++;
                }
            }
        } 
    }

    if(un == zero && zero != 0){
        return 1;
    }
        return 0;
}


int verifierGrille(int tab[8][8]){
    int gagne = 0;
    for(int i = 0; i < 8; i++){
        int verifCol = verifierLigneColonne(tab, i, 0);
        // printf("\n%d", verifCol);
        int verifLigne = verifierLigneColonne(tab, i, 1);
        // printf("\n%d", verifLigne);
        if(verifCol == 1 && verifLigne == 1){
            gagne++;
        }
    }
    if(gagne==8){
        return 1;
    }
    else{
        return 0;
    }
}


// 4 - Ecrire le code principal qui permet de jouer au joueur :  le programme prend fin quand on gagne 

int main(){
    // Ne pas toucher le code entre les commentaires
    srand( time( NULL ) );


    int i, j, k;
    printf("SOLUTION");  
    printf("\n");  
    printf("---------------------------------");  
    printf("\n");  

    int solution[8][8] = {
        {1,1,0,1, 0,1,0,0},
        {0,0,1,0, 1,0,1,1},
        {0,1,0,0, 1,1,0,1},
        {1,0,1,1, 0,0,1,0},
    
        {1,0,1,0, 0,1,1,0},
        {0,1,0,1, 1,0,0,1},
        {1,1,0,0, 1,0,1,0},
        {0,0,1,1, 0,1,0,1}
    };


    for(i=0;i<8; ++i) 
    {
    for(j=0; j<8; ++j)
        printf("%d ", solution[i][j]);
    printf("\n");  
    }
    printf("---------------------------------");  
    printf("\n");  
    //toucher le code entre les commentaires 

    int percent = 2;

    int grille[8][8] = {
        {2,2,2,2, 2,2,2,2},
        {2,2,2,2, 2,2,2,2},
        {2,2,2,2, 2,2,2,2},
        {2,2,2,2, 2,2,2,2},
    
        {2,2,2,2, 2,2,2,2},
        {2,2,2,2, 2,2,2,2},
        {2,2,2,2, 2,2,2,2},
        {2,2,2,2, 2,2,2,2}
    };

    int count = generer(solution, grille, percent);

    while(count >= 1){
        printf("\n");
        for(int i =0; i<8; i++){
            for(int j =0; j<8; j++){
                if(grille[i][j] == 2){
                    printf("  ");
                }
                else{
                    printf("%d ", grille[i][j]);
                }

            }
            printf("\n");
        }
        printf("\nil y a %d cases a remplire\n", count);
        int good = saisir(grille);
        if(good == 1){
            count--;
        }
    }

    int win = 0;
    win = verifierGrille(grille);
    if(win == 1){
        printf("\ngagne !\n");
    }
    else{
        printf("\nperdu :/\n");
    }


    //Ne pas toucher au code ci dessous
    system("pause");
    return 0;
}

