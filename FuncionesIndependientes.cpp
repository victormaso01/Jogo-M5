#include <stdlib.h>
#include <time.h>
#include <iostream>

//Atributos del Enemigo
using namespace std;
int enemy1HP = 1000;
int enemyDamage = 0;
string enemy1Name = "Malo";
bool enemyAlive = true;

//Atributos Enemigo2
int enemy2HP = 900;
int enemy2Damage;
string enemy2Name = "Malvado";
bool enemy2Alive = true;

//Atributos del Héroe
string heroName;
int heroHP = 2500;
bool heroAlive = true;
int puntosDeMagia = 1500;
int costeTormenta = 450;
int costeBola = 600;
int danoTormenta = 350;
int danoPatadon = 250;
int danoEspadazo = 400;
int danoBolaFuego = 400;
int ataqueUsado;
string enemySelected;
string bolaFuego = " una bola de fuego ";
string patadon = " un patadon ";
string espadazo = " un espadazo ";
string tormenta = " una tormenta magica ";

static void inisio() {
    std::cout << "Los enemigos " << enemy1Name << " y " << enemy2Name << " acaba de aparecer y tienen " << enemy1HP << " y " << enemy2HP << " puntos de vida, respectivamente\n";
    cout << "Inserta el nombre del heroe que lo va a derrotar\n";
    cin >> heroName;
    cout << "El nombre del heroe es " << heroName << " con ataques de: bola de fuego, tormenta magica, espadazo y el legendario patadon\n";
    cout << "Los ataques TORMENTA MAGICA y BOLA DE FUEGO consumen " << costeTormenta << " y " << costeBola << " respectivmente.\n";
    cout << "Nuestro heroe inicia con " << puntosDeMagia << " que iran disminuyendo por cada ataque magico.\n";
}

static int enemySelection() {
    if (enemy2Alive && enemyAlive) {
        cout << "Escoge un enemigo al que atacar: enemigo " << enemy1Name << " con " << enemy1HP << " o al enemigo " << enemy2Name << " con " << enemy2HP << " puntos de vida.\n";
        cin >> enemySelected;
        if ((enemySelected == "Malvado") || (enemySelected == "malvado")) {
            return 1;
        }
        else if ((enemySelected == "Malo") || (enemySelected == "malo")) {
            return 1;
        }
        else {
            cout << "Ningun enemigo seleccionado. \n";
        }
    }
    else {
        if (enemy2Alive) {
            enemySelected = "Malvado";
            return 2;
        }
        else if (enemyAlive) {
            enemySelected = "Malo";
            return 1;
        }
    }
}

static void heroAttack(string attackSelected, string enemyName, int danoAtaque, int enemyHP ) {
    cout << "Nuestro heroe " << heroName << " ha atizado a " << enemyName << " con " << attackSelected << ", provocando la friolera de " << danoAtaque << " puntos de dano sobre el enemigo " << enemyName << "\n";
    enemyHP = enemyHP - danoAtaque;
}

bool checkStatus(string enemyName, string attackSelected, int enemyHP) {
    if (enemyHP <= 0) {
        cout << "El enemigo " << enemyName << " ha sido brutalmente humillado de " << attackSelected << " y ha fallecido.\n";
        enemyHP = 0;
        return false;
    }
    else {
        cout << "Al enemigo " << enemyName << " le quedan " << enemyHP << " puntos de vida.\n";
        return true;
    }
}

static void manaCheck(int& costeMana) {
    puntosDeMagia = puntosDeMagia - costeMana;
    cout << "Este ataque te ha consumido " << costeMana << " puntos de magia. Te quedan " << puntosDeMagia << ".\n";
}

static bool enemyAttack() {
    cout << "El enemigo se dispone a devoler el golpe.\n";
    enemyDamage = (rand() % 1500) + 1;
    heroHP = heroHP - enemyDamage;
    if (heroHP <= 0) {
        cout << enemy1Name << " te ha humillado y has sido brutalmente asesinado. \n";
        return false;
    }
    else {
        cout << enemy1Name << " ha golpeado a " << heroName << " , haciendo " << enemyDamage << " y dejandolo a " << heroHP << " puntos de vida. \n";
        return true;
    }
}

static void choosingAttack() {
    cout << "Selecciona el ataque que vas a usar: \n";
    cout << "[1] PATADON \n";
    cout << "[2] ESPADAZO \n";
    cout << "[3] BOLA DE FUEGO \n";
    cout << "[4] TORMENTA MAGICA \n";
    cin >> ataqueUsado;
}

int main() {
    srand(time(0));
    inisio();

    do {
        choosingAttack();
        switch (ataqueUsado) {
        case 1:
            if (enemySelection() == 1) {
                heroAttack(patadon, enemy1Name, danoPatadon, enemy1HP);
                enemyAlive = checkStatus(enemy1Name, patadon, enemy1HP);
                heroAlive = enemyAttack();
            }
            else {
                heroAttack(patadon, enemy2Name, danoPatadon, enemy2HP);
                enemyAlive = checkStatus(enemy2Name, patadon, enemy2HP);
                heroAlive = enemyAttack();
            }
            break;

        case 2:
            if (enemySelection() == 1) {
                heroAttack(espadazo, enemy1Name, danoEspadazo, enemy1HP);
                enemyAlive = checkStatus(enemy1Name, espadazo, enemy1HP);
                heroAlive = enemyAttack();
            }
            else {
                heroAttack(espadazo, enemy2Name, danoEspadazo, enemy2HP);
                enemyAlive = checkStatus(enemy2Name, espadazo, enemy2HP);
                heroAlive = enemyAttack();
            }
            break;

        case 3:
            if (puntosDeMagia >= costeBola) {
                if (enemySelection() == 1) {
                    heroAttack(bolaFuego, enemy1Name, danoBolaFuego, enemy1HP);
                    enemyAlive = checkStatus(enemy1Name, bolaFuego, enemy1HP);
                    manaCheck(costeBola);
                    heroAlive = enemyAttack();
                }
                else {
                    heroAttack(bolaFuego, enemy2Name, danoBolaFuego, enemy2HP);
                    enemyAlive = checkStatus(enemy2Name, bolaFuego, enemy2HP);
                    manaCheck(costeBola);
                    heroAlive = enemyAttack();
                }
            }
            else {
                cout << "No dispones de los puntos de magia necesarios para este ataque.\n";
            }
            break;

        case 4:
            if (puntosDeMagia >= costeTormenta) {
                if (enemySelection() == 1) {
                    heroAttack(tormenta, enemy1Name, danoTormenta, enemy1HP);
                    enemyAlive = checkStatus(enemy1Name, tormenta, enemy1HP);
                    manaCheck(costeTormenta);
                    heroAlive = enemyAttack();
                }
                else {
                    heroAttack(tormenta, enemy2Name, danoTormenta, enemy2HP);
                    enemyAlive = checkStatus(enemy2Name, tormenta, enemy2HP);
                    manaCheck(costeTormenta);
                    heroAlive = enemyAttack();
                }
            }
            else {
                cout << "No dispones de los puntos de magia necesarios para este ataque. \n";
            }
            break;
        }

    } while (((enemyAlive == true) || (enemy2Alive == true)) && (heroAlive == true));
}