#include <stdio.h>
#include <string.h>
#include "TADElectrolinera.h"
#include "TADFecha.h"
/*
-------------------------Intentamos crear la reserva-------------------------
*/
int TipoElectrolinera::crear_reserva(int duracion,int nivel,TipoFecha fecha){
  int prSeleccionado=0;
  int prDisponible = -1;
  int rDisponible;
  bool prValido=false;

  /*Buscamos el primer pr con el nivel que buscamos*/

  for(int i=0;i<=MAX_NUMERO_PUNTOSRECARGA;i++){
      if(puntosRecarga[i].isActive && puntosRecarga[i].nivel==nivel){
        /*Encontramos el un PR activo con el mismo nivel*/
        for(int j=0;j<=MAX_NUMERO_RESERVAS;j++){
          /*Recorremos y econtramos una reserva inactiva*/
          if(!puntosRecarga[i].reservas[j].isActive){
            /*Si no se ha encontrado prValido todavia guardamos los datos de la reserva disponible*/
            if(!prValido){
              prValido=true;
              prDisponible=i;
              rDisponible=j;
            }
          }
        }
      }else{
        printf("\nNingun PR activo o Nivel no encontrado");
      }
  }
  if(prValido){
    puntosRecarga[prDisponible].reservas[rDisponible].isActive = true;
    puntosRecarga[prDisponible].reservas[rDisponible].fecha = fecha;
    puntosRecarga[prDisponible].reservas[rDisponible].duracion = util.aproximar_duracion(duracion,puntosRecarga[prDisponible].rodajaMinima);
    printf("\nHe encontrado disponibilidad en PR id: %i y Reserva id:%i",prDisponible,rDisponible);

  }else{
    printf("\nNo he encontrado reserva");
  }

  return prDisponible;
}
