#include <iostream>
using namespace std;

// ambito global
const char *nombre_archivo = "archivo.dat";
struct Estudiante{
	int codigo;
	char nombres[50];
	char apellidos[50];
	int telefono;
};

// invocar a las funciones
void crear();
void leer();

// principal
main(){
	leer();
	crear();
	system("pause");
}

// funcion leer
void leer(){
	system("cls");
	FILE* archivo = fopen(nombre_archivo, "rb");
	// simbolo de negacion !
	if(!archivo){
		archivo = fopen(nombre_archivo, "w+b");
	}
	
	
	Estudiante estudiante;
	int id=0;
	// MOSTRANDO EL READ DEL , meterlo en esta escructura xd
	fread(&estudiante, sizeof(Estudiante), 1, archivo);
	
	do{
		// una sola linea
		cout<<id<<" , "<<estudiante.codigo<<" , "<<estudiante.nombres <<" , "<<estudiante.apellidos<<" , "<<estudiante.telefono<<endl;
		fread(&estudiante, sizeof(Estudiante), 1, archivo);
		id +=1;
		// identifica el final del archivo
	} while(feof(archivo)==0);
	
	fclose(archivo);
}

// funcion crear
void crear(){
	// solo acepta arreglos tipo puntero jajajajaja
	FILE* archivo = fopen(nombre_archivo, "a+b");
	
	// para ingresar datos
	char res;
	// instanciando al estudiante
	Estudiante estudiante;
	
	do{
		fflush(stdin);
		cout<<"Ingrese codigo: ";
		cin>>estudiante.codigo;
		// para ignorar el cin del getline
		cin.ignore();
		
		// 
		cout<<"Ingrese Nombres: ";
		cin.getline(estudiante.nombres, 50);
		
		
		cout<<"Ingrese apellidos: ";
		cin.getline(estudiante.apellidos, 50);
		
		cout<<"Ingrese Telefono: ";
		cin>>estudiante.telefono;
		
		fwrite(&estudiante, sizeof(Estudiante), 1, archivo); // (fwrite) para escritura; 0 para no hacer nada
		
		
		cout<<"Desea ingresar otro estudiante(s/n): ";
		cin>>res;
	}while(res=='s' || res=='S');
	
	fclose(archivo);
	
	leer();
	
	
}
