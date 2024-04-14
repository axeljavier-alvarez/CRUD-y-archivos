#include <iostream>
using namespace std;

// nombre del archivo no cambia en la variable
// forma dinamica no sera tamaño fijo sino puntero

const char * nombre_archivo = "archivo.dat";

struct Estudiante{
	int codigo;
	char nombres[50];
	char apellidos[50];
	int telefono;
};

// metodo de leer
void Leer();
// metodo
void Crear();

void Actualizar();

void Borrar();

main(){
	
	Leer();
	Crear();
	
	Actualizar();
	
	Borrar();
	// archivos binarios
	// almacenarlo en archivos	
	system("pause");
}

void Leer(){
	system("cls");
		// rb abre fichero para lectura
	FILE * archivo = fopen(nombre_archivo, "rb");
	
	if(!archivo){
		archivo = fopen(nombre_archivo, "w+b");
	}
	
	Estudiante estudiante;
	// Determinan el indice o la posicion donde esta el registro
	int id=0;
	// leer lo que esta en el archivo
	fread(&estudiante,sizeof(Estudiante), 1, archivo);
	cout<<"___________________________"<<endl;
	cout<<"ID"<<"|"<<"Codigo"<<"|"<<"   Nombres   "<<"|"<<"     Apellidos   "
	<<"|"<<"      Telefono      "<<endl;
	do{
		
	    cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos
		<<"|"<<estudiante.telefono<<endl;
		// ir aumentando con este operador xd
		
		// IR CAMBIANDO DE REGISTRO
		fread(&estudiante,sizeof(Estudiante), 1, archivo);

		id+=1;
				// feof hasta el final del registro de los archivos

	}while(feof(archivo)==0);
	
	// cerrar ese archivo de lectura xd
	fclose(archivo);
}

void Crear(){
	// abre o crear un fichero binario
	// abrir el archivo
	FILE * archivo = fopen(nombre_archivo, "a+b");
	char res;
	// declarar
	Estudiante estudiante;
		
	do{
		// Limpiar el flujo del archivo
		fflush(stdin);
		cout<<"Ingrese Codigo: ";
		cin>>estudiante.codigo;
		cin.ignore();
		
		// necesitamos el get de todo
		cout<<"Ingrese Nombres: ";
		cin.getline(estudiante.nombres, 50);
		
		cout<<"Ingrese Apellidos: ";
		cin.getline(estudiante.apellidos, 50);
		
		cout<<"Ingrese Telefono: ";
		cin>>estudiante.telefono;
		
		// tenemos que escribir los registros
		// bandera default 1
		fwrite(&estudiante,sizeof(Estudiante), 1, archivo);
		
		cout<<"Desea ingresar otro estudiante(s/n): ";
		cin>>res;
		
	}while(res=='s' || res=='S');
	// cerrar el archivo
	fclose(archivo);
	
	
	// mandar a llamar a leer
	Leer();
}

void Actualizar(){
	// r+b abre fichero para escritura, actualizar crea y borra
	FILE * archivo = fopen(nombre_archivo, "r+b");
	// declarar
	Estudiante estudiante;
	
	// preguntarle por el id
	int id=0;
	
	cout<<"Ingrese el ID que desea Modificar: ";
	cin>>id;
	// posicionar mi puntero fseek para posicionar puntero en una determinada posicion
	
	// BUSCAR POR EL ID
	fseek(archivo,id * sizeof(Estudiante), SEEK_SET);
	
		cout<<"Ingrese Codigo: ";
		cin>>estudiante.codigo;
		cin.ignore();
		
		// Crear(); y actualizar();
		
		// necesitamos el get de todo
		cout<<"Ingrese Nombres: ";
		cin.getline(estudiante.nombres, 50);
		
		cout<<"Ingrese Apellidos: ";
		cin.getline(estudiante.apellidos, 50);
		
		cout<<"Ingrese Telefono: ";
		cin>>estudiante.telefono;
		
		// tenemos que escribir los registros
		// bandera default 1
		fwrite(&estudiante,sizeof(Estudiante), 1, archivo);
	// cerrar el archivo
	fclose(archivo);	
	// mandar a llamar a leer
	Leer();
}

void Borrar(){
	const char * nombre_archivo_temp = "archivo_temp.dat";
	FILE * archivo = fopen(nombre_archivo, "rb");
	FILE * archivo_temp = fopen(nombre_archivo_temp, "w+b");
	
	Estudiante estudiante;
	
	int id=0, id_n=0;
	
	cout<<"Ingrese el ID a eliminar:";
	cin>>id;
	
	// recorrer el archivo principal
	while(fread(&estudiante,sizeof(Estudiante), 1, archivo)){
		
	// en el archivo nuevo agrego todos
	// menos el que quiero que se elimine
		if(id_n != id){
		    fwrite(&estudiante,sizeof(Estudiante), 1, archivo_temp);

		}
	// se incrementa
		id_n++;
	}
	
    // archivo extra para eliminar algun dato
	fclose(archivo);
	fclose(archivo_temp);
	
	// tiene los datos que quiero en el original
	archivo_temp = fopen(nombre_archivo_temp, "rb");
	// luego escribir dentro del archivo permanente
	archivo = fopen(nombre_archivo, "wb");
	
	// recorrido a archivo_temp
	while(fread(&estudiante,sizeof(Estudiante), 1, archivo_temp)){
		
		// escribo en mi archivo
		    fwrite(&estudiante,sizeof(Estudiante), 1, archivo);
}

    fclose(archivo);
	fclose(archivo_temp);
	
	
	Leer(); 

}
