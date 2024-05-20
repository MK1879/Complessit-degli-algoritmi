#include <iostream>
#define MAX 1000
#include <ctime>
using namespace std;
//Prototipi funzioni
void menu();
void menu_ordinamento();
void menu_ricerca();


void stampa_vettore(int array[], int dim);
void caricaArray(int array[], int n);

void bubble_sort(int array[], int dim);
void selection_sort(int array[], int dim);
int ricerca_lineare(int array[], int d, int val);
int ricerca_binaria(int array[], int dim, int val);

int main(void) 
{
	//DIchiarazione ed inizializzazione del vettore
	int vett[MAX] = {0}, dim=0, scelta=0, scelta_ordinamento=0, scelta_ricerca=0, val=0;
	
	//Input del vettore e della relativa dimensione
	do
	{
		cout<<"Inserisci la dimensione del vettore (compresa tra 1 e 1000): ";
		cin>>dim;
		if(dim<1 || dim>1000)
		{
			cout<<"Hai inserito una dimensione non accettabile. Riprova!"<<endl;
		}
	}
	while(dim<1 || dim>1000);
	caricaArray(vett, dim);
	
	//Menù
	do
	{
		do
		{
			menu();
			cin>>scelta;
			switch (scelta)
			{
				case 1:
				do
				{
					menu_ordinamento();
					cin>>scelta_ordinamento;
					switch (scelta_ordinamento)
					{
						case 1:
						selection_sort(vett, dim);
						break;
						
						case 2:
						bubble_sort(vett, dim);
						break;
						
						default:
						cout<<"Hai inserito una scelta non accettabile. Riprova!"<<endl;
						break;
					}
				}
				while(scelta_ordinamento!=1 && scelta_ordinamento!=2);
				break;
				
				case 2:
				do
				{
					menu_ricerca();
					cin>>scelta_ricerca;
					//Input del valore da ricercare 
					cout<<"Inserisci il valore che vuoi ricercare nel vettore: ";
					cin>>val;
					switch (scelta_ricerca)
					{
						case 1:
						if(ricerca_lineare(vett, dim, val)==-1)
						{
							cout<<"Il valore non e' stato trovato nel vettore.";
						}
						else
						{
							cout<<"Il valore e' stato trovato e ha come indice "<<ricerca_lineare(vett, dim, val)<<endl;
						}				
						break;
						
						case 2:
						if(ricerca_binaria(vett, dim, val)==-1)
						{
							cout<<"Il valore non e' stato trovato nel vettore."<<endl;
						}
						else
						{
							cout<<"Il valore e' stato trovato e ha come indice "<<ricerca_binaria(vett, dim, val)<<endl;
						}	
						break;
						
						default:
						cout<<"Hai inserito una scelta non accettabile. Riprova!"<<endl;
						break;
					}
				}
				while(scelta_ricerca<1 || scelta_ricerca>2);
				break;
				
				case 3:
				stampa_vettore(vett, dim);
				break;
				
				case 4:
				cout<<"Arrivederci!";
				break;
				
				default:
				cout<<"Hai inserito una scelta non accettabile. Riprova!"<<endl;
				break;
			}
		}
		while(scelta<1 || scelta>4);
	}
	while(scelta!=4);
	return 0;
}

//////////////////////////////////////////////////////////////////////
void caricaArray(int array[], int n)
{
	srand(time(NULL)); // Inizializza il generatore di numeri casuali
	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % 1000; // Genera numeri casuali compresi tra 0 e 999
	}
}
void menu()
{
	cout<<"*****************MENU'*******************"<<endl;
	cout<<"1. Ordinamento del vettore."<<endl;
	cout<<"2. Ricerca di un valore nel vettore."<<endl;
	cout<<"3. Stampa del vettore."<<endl;
	cout<<"4. Esci dal programma."<<endl;
	cout<<"Inserisci qui la tua scelta: ";	
}
void menu_ordinamento()
{
	cout<<"Con quale algoritmo vuoi ordinare il tuo vettore?"<<endl;
	cout<<"1. Selection sort."<<endl;
	cout<<"2. Bubble sort."<<endl;
	cout<<"Inserisci qui la tua scelta: ";	
}
void menu_ricerca()
{
	cout<<"Con quale algoritmo vuoi ricercare un valore nel tuo vettore?"<<endl;
	cout<<"1. Ricerca Lineare."<<endl;
	cout<<"2. Ricerca Binaria."<<endl;
	cout<<"Inserisci qui la tua scelta: ";
}
void stampa_vettore(int array[], int dim)
{
	for(int i=0 ; i<dim ; i++)
	{
		cout<<i<<"' elemento del vettore: "<<array[i]<<endl;
	}
}
void selection_sort(int array[], int dim)
{
	int min_id=0, min=array[0], temp=0;
	for(int i=0 ; i<dim-1 ; i++)
	{
		min_id=i;
		min=array[i];
		for(int j=i+1 ; j<dim ; j++)
		{
			if(array[j]<min)
			{
				min_id=j;
				min=array[j];
			}	
		}
		if(i != min_id)
		{
		temp=array[i];
		array[i]=array[min_id];
		array[min_id]=temp;
		}
	}
}
void bubble_sort(int array[], int dim)
{
	int temp=0;
	for(int i = 0; i < dim - 1; i++)
	{
    	for(int j = 0; j < dim - 1; j++)
       	{
	        if(array[j] > array[j + 1])
	        {
	    		temp = array[j];
	          	array[j] = array[j + 1];
	          	array[j + 1] = temp;
	        }
		}
	}
}

int ricerca_lineare(int array[], int d, int val)
{
	for(int i=0 ; i<d ; i++)	
	{
		if(array[i]==val)
		{
			return i;
		}
	}
	return -1; 
}
            
int ricerca_binaria(int array[], int dim, int val)
{
    int inizio = 0, fine = dim - 1, centro=0, pos = -1; // Inizializzazione degli indici e variabile per la posizione del numero trovato

    // Ciclo di ricerca binaria
    do 
	{
        centro = (inizio + fine) / 2; // Calcolo dell'indice medio

        if (array[centro] == val)  // Se il numero è stato trovato
		{
            return centro; // ritorna l'indice del valore
        } 
		else if (array[centro] < val)  // Se il numero nella posizione media è minore di x, cerca nella metà superiore
		{ // Se il numero nella posizione media è minore di x, cerca nella metà superiore
            inizio = centro + 1;
        } 
		else
	    { // Se il numero nella posizione media è maggiore di x, cerca nella metà inferiore
            fine = centro - 1;
        }
    } 
	while (inizio <= fine); // Continua finché gli indici non si sovrappongono o il numero è stato trovato	
	return -1;
}          
   
            