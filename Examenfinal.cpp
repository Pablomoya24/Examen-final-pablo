/* LAVACAR */

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h> // Necesario para la función gotoxy
// voy a crear un programa que me permita ingresa los datos de un aeropuerto donde voy a registrar los nombres de los viajeros, el id del viajero asi como su salida y entrada de los diveros lugares.
//tambien van a ver graficos que me muestren los porcentajes de cada entrada y salida de viajeros. 
int continuar;

//prototipos de funciones y procedimientos
void menu();
void ingresarDatosViajeros();
void RegistroIngreso();
void Estadisticaviajeros();
void EstadisticaIngreso();

void gotoxy(int x, int y);
void cuadro(int x1, int x2, int y1, int y2);

 //procedimiento para realizar un cuadro
 void cuadro(int x1, int x2, int y1, int y2)
 {
 		int i;
 	
 	for(i=x1;i<=x2; i++)
 	{
 		gotoxy(i,y1); printf("%c",205);
 		gotoxy(i,y2); printf("%c",205);
	 }
	
		for(i=y1;i<=y2; i++)
 	{
 		gotoxy(x1,i); printf("%c",186);
 		gotoxy(x2,i); printf("%c",186);
	 } 
	   	gotoxy(x1,y1); printf("%c",201);
	   	gotoxy(x1,y2); printf("%c",200);
	   	gotoxy(x2,y1); printf("%c",187);
	   	gotoxy(x2,y2); printf("%c",188);
}
//procedimiento gotoxy es un procedimiento para direccionar o posicionar un texto o el cursor en la pantalla
void gotoxy(int x, int y)
{
	COORD cordenada;
	
	cordenada.X=x;
	cordenada.Y=y;
	
	SetConsoleCursorPosition(GetStdHandle (STD_OUTPUT_HANDLE),cordenada);
}

struct Viajero {
	int idviajeros;
	char nombre;
	char direccion;
	int numeropasaporte;
	int vencimiento;
} viajeros;

void ingresarDatosViajeros() {
	
	
    int idviajeros;
	char nombre;
	char direccion;
	int numeropasaporte;
	int vencimiento;

    do {
        system("cls");
        system("color f5");

        cuadro(7, 40, 0, 2);
        gotoxy(10, 1); printf("INGRESE EL NOMBRE:");
        scanf ("%s",&nombre);

        cuadro(7, 77, 3, 19);
        gotoxy(10, 4); printf("INGRESE EL ID DEL VIAJERO:");
        scanf ("%i",&idviajeros);

        gotoxy(10, 6); printf("INGRESE LA DIRECCION: ");
       scanf ("%s",&direccion);

        gotoxy(10, 8); printf("INGRESE EL NUMERO DE PASAPORTE: ");
        scanf ("%i",&numeropasaporte);
		
		gotoxy(10, 10); printf("INGRESE EL AÑO DE VENCIMIENTO: ");
        scanf ("%i",&vencimiento);
	    
        gotoxy(10, 16); printf("Desea Continuar S/N: ");
        do {
            continuar = getch();
		}while(toupper(continuar) != 'S' && toupper(continuar) != 'N');
		
	}while(toupper(continuar) == 'S');
	
}

struct Ingreso{
	
	int idviajerosa;
	char fechasalida;
	char lugaringreso;
} ingreso;


void RegistroIngreso() {
	
	
    int idviajeros;
	char fechasalida;
	char lugaringreso;

    do {
        system("cls");
        system("color f5");

        cuadro(7, 77, 3, 19);
        gotoxy(10, 4); printf("INGRESE EL ID DEL VIAJERO:");
        scanf ("%i",&ingreso.idviajerosa);

        gotoxy(10, 6); printf("INGRESE EL MES DE SALIDA: ");
       scanf ("%s",&ingreso.fechasalida);

        gotoxy(10, 8); printf("INGRESE EL LUAGR DE INGRESO: ");
        scanf ("%i",&ingreso.lugaringreso);
		
	
	    
        gotoxy(10, 16); printf("Desea Continuar S/N: ");
        do {
            continuar = getch();
		}while(toupper(continuar) != 'S' && toupper(continuar) != 'N');
		
	}while(toupper(continuar) == 'S');
	
}
void Estadisticaviajeros(){
	system("cls");
	system("color f5");
	
	cuadro(7,60,1,3);
	gotoxy(10,2); printf("**** Reporte de los viajeros ****");
	cuadro(7,70,4,16);
	gotoxy(10,5); printf("NOMBRE DEL VIAJERO: %s",viajeros.nombre);
	gotoxy(10,7); printf("ID DEL VIAJERO:%i",viajeros.idviajeros);
	gotoxy(10,9); printf("DIRECCION DEL VIAJERO: %s",viajeros.direccion);
	gotoxy(10,11); printf("NUMERO DE PASAPORTE DEL VIAJERO: %i",viajeros.numeropasaporte);
	gotoxy(10,13); printf("AÑO DE VENCIMINETO DEL PASAPORTE: %i",viajeros.vencimiento);
	cuadro(7,40,17,19);
	gotoxy(10,18); printf("<Pulse tecla para Abandonar>");
	getch();
}

void EstadisticaIngreso(){
	system("cls");
	system("color f5");
	
	cuadro(4,50,1,3);
	gotoxy(5,2); printf("**** INGRESO DE VIAJEROS ****");
	cuadro(4,78,4,12);
	gotoxy(5,5); printf("ID DEL VIAJERO: %i",ingreso.idviajerosa);
	gotoxy(5,7); printf("MES DE SALIDA:%s",ingreso.fechasalida);
	gotoxy(5,9); printf("LUGAR DE INGRESO:%i",ingreso.lugaringreso);

	gotoxy(5,14); printf("<Pulse tecla para Abandonar>");
	getch();
}





void menu() {
    char opcion;

    do {
        system("cls");
        system("color f5");

        cuadro(7, 50, 1, 3);
        gotoxy(10, 2); printf("**** M e n u   P r i n c i p a l ****");

        cuadro(7, 70, 4, 16);
        gotoxy(10, 5); printf("1- Ingresar Datos del Viajero");
        gotoxy(10, 7); printf("2- Registar ");
        gotoxy(10, 9); printf("3- Ver Estadisticas del Viajero");
        gotoxy(10, 11); printf("4- Estadisticas de Ingreso");
        gotoxy(10, 13); printf("5- GRAFICO");
        gotoxy(10, 15); printf("6- Salir");
        cuadro(7, 50, 17, 19);
        gotoxy(10, 18); printf("Ingrese su opcion ----> ");

        opcion = getch();

        switch (opcion) {
            case '1':
                ingresarDatosViajeros();
                break;
            case '2':
                RegistroIngreso();
                break;
            case '3':
                Estadisticaviajeros();
                break;
            case '4':
            	EstadisticaIngreso();
            	break;
            case '6':
                break;
            default:
                gotoxy(10, 19); printf("Error: opcion incorrecta...!");
                Sleep(3000);
                break;
        }
    } while (opcion != '6');
}

// Cuerpo principal del programa
int main() {
    menu();
    return 0;
}
