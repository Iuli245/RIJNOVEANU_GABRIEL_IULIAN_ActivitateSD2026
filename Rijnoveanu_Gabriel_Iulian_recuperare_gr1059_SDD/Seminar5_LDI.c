//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//
//
//struct StructuraMasina {
//	int id;
//	int nrUsi;
//	float pret;
//	char* model;
//	char* numeSofer;
//	unsigned char serie;
//};
//typedef struct StructuraMasina Masina;
//
////creare structura pentru un nod dintr-o lista dublu inlantuita
//
//struct Nod {
//	struct Nod* prev;
//	struct Nod* next;
//	Masina info;
//};
//typedef struct Nod Nod;
////creare structura pentru Lista Dubla 
//
//struct ListaDubla {
//	Nod* first;
//	Nod* last;
//};
//typedef struct ListaDubla ListaDubla;
//
//Masina citireMasinaDinFisier(FILE* file) {
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//	char* aux;
//	Masina m1;
//	aux = strtok(buffer, sep);
//	m1.id = atoi(aux);
//	m1.nrUsi = atoi(strtok(NULL, sep));
//	m1.pret = atof(strtok(NULL, sep));
//	aux = strtok(NULL, sep);
//	m1.model = malloc(strlen(aux) + 1);
//	strcpy_s(m1.model, strlen(aux) + 1, aux);
//
//	aux = strtok(NULL, sep);
//	m1.numeSofer = malloc(strlen(aux) + 1);
//	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);
//
//	m1.serie = *strtok(NULL, sep);
//	return m1;
//}
//
//void afisareMasina(Masina masina) {
//	printf("Id: %d\n", masina.id);
//	printf("Nr. usi : %d\n", masina.nrUsi);
//	printf("Pret: %.2f\n", masina.pret);
//	printf("Model: %s\n", masina.model);
//	printf("Nume sofer: %s\n", masina.numeSofer);
//	printf("Serie: %c\n\n", masina.serie);
//}
//
//void afisareListaMasini(/*lista dubla de masini*/  ListaDubla listaDubla) {
//	//afiseaza toate elemente de tip masina din lista dublu inlantuita
//	//prin apelarea functiei afisareMasina()
//
//	Nod* aux;
//	aux = listaDubla.first;
//	while (aux) {
//		afisareMasina(aux->info);
//		aux = aux->next;
//	}
//}
//
//void afisareListaMasiniDeLaFinal(ListaDubla listaDubla) {
//	Nod* aux;
//	aux = listaDubla.last;
//	while (aux) {
//		afisareMasina(aux->info);
//		aux = aux->prev;
//	}
//
//}
//
//void adaugaMasinaInLista(/*lista dubla de masini*/ ListaDubla* listaDubla, Masina masinaNoua) {
//	//adauga la final in lista primita o noua masina pe care o primim ca parametru
//
//	Nod* nou;
//	nou = malloc(sizeof(Nod*));
//	nou->info = masinaNoua;
//	nou->next = NULL;
//	nou->prev = listaDubla->last;
//	if (listaDubla->last) {
//		listaDubla->last->next = nou;
//	}
//	else {
//		listaDubla->first = nou;
//	}
//	listaDubla->last = nou;
//
//
//}
//
//void adaugaLaInceputInLista(/*lista dubla de masini*/ListaDubla* listaDubla, Masina masinaNoua) {
//	//adauga la inceputul listei dublu inlantuite o noua masina pe care o primim ca parametru
//
//	Nod* nou;
//	nou = malloc(sizeof(Nod*));
//	nou->info = masinaNoua;
//	nou->prev = NULL;
//	nou->next = listaDubla->first;
//	if (listaDubla->first) {
//		listaDubla->first->prev = nou;
//	}
//	else {
//		listaDubla->last = nou;
//	}
//	listaDubla->first = nou;
//
//
//}
//
//ListaDubla citireLDMasiniDinFisier(const char* numeFisier) {
//	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
//	//prin apelul repetat al functiei citireMasinaDinFisier()
//	//ATENTIE - la final inchidem fisierul/stream-ul
//
//	FILE* fisier = fopen(numeFisier, "r");
//	Masina  masina;
//	ListaDubla listaMasini;
//	listaMasini.first = NULL;
//	listaMasini.last = NULL;
//	while (!feof(fisier)) {
//		masina = citireMasinaDinFisier(fisier);
//		adaugaMasinaInLista(&listaMasini, masina);
//	}
//	fclose(fisier);
//	return listaMasini;
//}
//
//void dezalocareLDMasini(/*lista dubla de masini*/ListaDubla* listaMasini) {
//	//sunt dezalocate toate masinile si lista dublu inlantuita de elemente
//	Nod* aux;
//	if (listaMasini->first) {
//		if (listaMasini->first->next) {
//			aux = listaMasini->first->next;
//			while (aux) {
//				free((aux->prev->info).model);
//				free((aux->prev->info).numeSofer);
//				free(aux->prev);
//				aux = aux->next;
//			}
//		}
//			free((listaMasini->first->info).model);
//			free((listaMasini->first->info).numeSofer);
//			free(listaMasini->first);
//			listaMasini->first = NULL;
//			listaMasini->last = NULL;
//
//	}
//	
//	
//}
//
//float calculeazaPretMediu(/*lista de masini*/ListaDubla listaMasini) {
//	Nod* masina = listaMasini.first;
//	float Suma = 0;
//		int nr = 0;
//
//	while (masina) {
//		nr++;
//		Suma += masina->info.pret;
//		masina = masina->next;
//	}
//	if (nr != 0) {
//		return Suma / nr;
//
//	}
//
//	//calculeaza pretul mediu al masinilor din lista.
//	return 0;
//}
//
//void stergeMasinaDupaID(/*lista masini*/ int id) {
//	//sterge masina cu id-ul primit.
//	//tratati situatia ca masina se afla si pe prima pozitie, si pe ultima pozitie
//}
//
//char* getNumeSoferMasinaScumpa(/*lista dublu inlantuita*/) {
//	//cauta masina cea mai scumpa si 
//	//returneaza numele soferului acestei maasini.
//	return NULL;
//}
//
//int main() {
//
//
//	ListaDubla listamasini = citireLDMasiniDinFisier("masini.txt");
//	afisareListaMasini(listamasini);
//
//	printf("medie: %2f", calculeazaPretMediu(listamasini));
//
//	dezalocareLDMasini(&listamasini);
//
//
//	return 0;
//}