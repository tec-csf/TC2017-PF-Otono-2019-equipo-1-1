#include<iostream>
#include<list>
//#inlude<stdlib.h>
#include<iterator>
#include<string>
#include <time.h>


using namespace std;

struct parada{
	int numEtapa;
	string salida;
	string llegada;
	int km;
	bool descanso;
};

struct ciclista{
	int num;
	double tiempo;
	int puntos;
	double kmRecorridos;
};

void tour(parada infoParadas[], ciclista infoCiclistas[], int numCiclistas, int numParadas){
//Vars here
clock_t t;
int i=0, j=0, z=0, numGanador=0, puntosGanadorFinal=0;
double velocidad = 0, tiempoCarreraPasada=0, tiempoGanador=0;

t = clock();
	for(i= 0; i<numParadas; i++){
		numGanador = 0;
		tiempoGanador = 1000000;
		//Se asigna el tiempo a los ciclistas para cada kilometro, la velocidad es un valor random entre 15 km/h y 105 km/h, estos límites se pusieron buscando los promedios reales
		for(j=0; j<numCiclistas; j++){
			tiempoCarreraPasada=0;
			for(z=0; z<infoParadas[i].km; z++){
				//Imprevisto en la carrera
				if(1==(rand()%50)){
					infoCiclistas[j].tiempo+=(rand()%1000)/3600;				
				}
				velocidad = 15 + rand()%90;
				infoCiclistas[j].tiempo += 1/velocidad;
				tiempoCarreraPasada += 1/velocidad;
			}//Tiempo por km
			if(tiempoCarreraPasada < tiempoGanador){
				numGanador = j;
				tiempoGanador = tiempoCarreraPasada;
			}
		cout<<"Llego el ciclista "<<infoCiclistas[j].num<< " con un tiempo total de:"<<infoCiclistas[j].tiempo<<endl;
		}//Ciclistas
		infoCiclistas[numGanador].puntos+=1;
		cout<<"El ganador de la carrera fue el ciclista numero "<<infoCiclistas[numGanador].num<<" con un tiempo de "<<tiempoGanador<<endl;
	}//Paradas
	
	puntosGanadorFinal = infoCiclistas[0].puntos;
	for(i=0; i<numCiclistas; i++){
		if(puntosGanadorFinal<infoCiclistas[i].puntos){
			puntosGanadorFinal= infoCiclistas[i].puntos;
		}
	}//End of for

	for(i=0; i<numCiclistas; i++){
		if(puntosGanadorFinal==infoCiclistas[i].puntos){
			cout<<"El ganador TOTAL de la carrera fue el ciclista "<<infoCiclistas[i].num<<" con un tiempo de "<<infoCiclistas[i].tiempo<<" y "<<infoCiclistas[i].puntos<<"puntos"<<endl;
		}
	}


	t = clock()-t;
	cout<<"Tiempo: "<<(float(t)/CLOCKS_PER_SEC)*1000<<" mili segundos"<<endl;
}//End of tour

int main(){
//Vars here
int numCiclistas = 0;

//Creando un vector con la información de las paradas
/*
//Pruebas
struct parada e1 = {1, "Niza", "Niza", 3, false};
struct parada e2 = {2, "Niza", "Niza", 2, false};
struct parada e3 = {3, "Niza", "Sisteron", 1, false};

parada infoParadas[3];
infoParadas[0] = e1;
infoParadas[1] = e2;
infoParadas[2] = e3;*/


struct parada e1 = {1, "Niza", "Niza", 156, false};
struct parada e2 = {2, "Niza", "Niza", 187, false};
struct parada e3 = {3, "Niza", "Sisteron", 198, false};
struct parada e4 = {4, "Sisteron", "Orcieres-Merlette", 157, false};
struct parada e5 = {5, "Gap","Privas" , 183, false};
struct parada e6 = {6, "Le Teil", "Mont Aigoual", 191, false};
struct parada e7 = {7, "Millau", "Lavur", 168, false};
struct parada e8 = {8, "Cazeres-sur-Garonne", "Loudenvielle", 140, false};
struct parada e9 = {9, "Pau", "Laruns", 154, true};
struct parada e10 = {10, "Ile d Oleron", "Ile de Re", 170, false};
struct parada e11 = {11, "Chatelaillon-Plage", "Poitiers", 167, false};
struct parada e12 = {12, "Chauvigny", "Sarran", 218, false};
struct parada e13 = {13, "Chatel-Guyon", "Puy Mary", 191, false};
struct parada e14 = {14, "Clairmont Ferrand", "lyon", 197, false};
struct parada e15 = {15, "Lyon", "Grand Colombier", 175, true};
struct parada e16 = {16, "La Tour-du-Pin", "Villard-de-Lans", 164, false};
struct parada e17 = {17, "Grenoble", "Meribel", 168, false};
struct parada e18 = {18, "Meribel", "La Roche-sur-Foron", 168, false};
struct parada e19 = {19, "Bourg-en-Bresse", "Champagnole", 160, false};
struct parada e20 = {20, "Lure", "Planche des Belles Filles", 36, false};
struct parada e21 = {21, "Mantes-la-Jolie", "Paris", 122, true};



parada infoParadas[21];
infoParadas[0] = e1;
infoParadas[1] = e2;
infoParadas[2] = e3;
infoParadas[3] = e4;
infoParadas[4] = e5;
infoParadas[5] = e6;
infoParadas[6] = e7;
infoParadas[7] = e8;
infoParadas[8] = e9;
infoParadas[9] = e10;
infoParadas[10] = e11;
infoParadas[11] = e12;
infoParadas[12] = e13;
infoParadas[13] = e14;
infoParadas[14] = e15;
infoParadas[15] = e16;
infoParadas[16] = e17;
infoParadas[17] = e18;
infoParadas[18] = e19;
infoParadas[19] = e20;
infoParadas[20] = e21;

cout<<"Favor de ingresar la cantidad de ciclistas de la competencia: "<<endl;
cin>>numCiclistas;
ciclista infoCiclistas [numCiclistas];

for(int i= 0; i<numCiclistas; i++){
	struct ciclista competidor = {i+1, 0.0, 0, 0.0};
	infoCiclistas[i] = competidor; 
}

tour(infoParadas, infoCiclistas, numCiclistas, 21);

}//End of main
