#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADOperaciones.h"

int main(){
    TipoOperacion ops;
    bool fin = false;
    char eleccion;
    printf("Algunos datos de prueba cargados");
    ops.CargarDatos();
    do{
    printf("\nGesELECTRERA: Gestion de electrolinearas\n\n");
    printf("\tEditar electrolinera\n");
    printf("\tEditar punto de recarga\n");
    printf("\tReservar punto de recarga\n");
    printf("\tListar reservas de electrolinera\n");
    printf("\tListar servicio mensual punto\n");
    printf("\tSalir\n\n");
    printf("Teclear una opcion valida (E|P|R|L|M|S)?\n");
    scanf("%c",&eleccion);
    switch(eleccion){
      case 'E':
        ops.EditarElectrolinera();
        break;
      case 'P':
        ops.EditarPuntoRecarga();
        break;
      case 'R':
        ops.ReservarPuntoRecarga();
        break;
      case 'L':
        ops.ListarReservas();
        break;
      case 'M':
        ops.CalendarioReservas();
        break;
      case 'S':
        fin = true;
        break;
      default:
        printf("Error Seleccion");
      };
    }while(!fin);
    return 0;
}
