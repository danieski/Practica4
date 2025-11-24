#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GesELECTRERA.h"
#include "Reservas.h"
ListaElectrolinera listaElectrolinera;

int main(){
    bool fin = false;
    char eleccion;
    /*Datos test*/
    IntroducirDatosElectrolinera(listaElectrolinera);
    /*Bucle principal*/
    do{
    ImprimirMenu();
    scanf("%c", &eleccion);
    switch(eleccion){
      case 'E':
        EditarElectrolinera(listaElectrolinera);
        break;
      case 'P':
        EditarPuntoDeRecarga(listaElectrolinera);
        break;
      case 'S':
        fin = true;
        break;
      case 'R':
        FuncionReservas();
        break;
      default:
        printf("Error Seleccion");
      };
    }while(!fin);
    return 0;
}
