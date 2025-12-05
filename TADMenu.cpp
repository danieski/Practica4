#include "TADMenu.h"
#include <stdio.h>

void TipoMenu::Inicializar(){
    bool fin = false;
    char eleccion;
    printf("Algunos datos de prueba cargados");
    ops.cargar_datos();
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
        ops.editar_electrolinera();
        break;
      case 'P':
        ops.editar_puntorecarga();
        break;
      case 'R':
        ops.reservar_puntorecarga();
        break;
      case 'L':
        ops.listar_reservas();
        break;
      case 'M':
        ops.calendario_reservas();
        break;
      case 'S':
        fin = true;
        break;
      default:
        printf("Error Seleccion");
      };
    }while(!fin);
}
