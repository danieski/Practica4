#include <stdio.h>
#include <string.h>
#include "TADElectrolinera.h"
#include "TADFecha.h"
bool TipoElectrolinera::crear_reserva(int duracion,int nivel,TipoFecha fecha){
  int prSeleccionado=0;
  int prDisponible,rDisponible;
  bool prValido=false;
  /*buscamos el primer pr con el nivel que buscamos*/

  for(int i=0;i<=MAX_NUMERO_PUNTOSRECARGA;i++){
      if(puntosRecarga[i].isActive && puntosRecarga[i].nivel==nivel){
        /*compruebo si hay una reserva el dia que estamos pidiendo en ese punto*/
        for(int j=0;j<=MAX_NUMERO_RESERVAS;j++){
          if(puntosRecarga[i].reservas[j].isActive && util.compatibilidad_fechas(puntosRecarga[j].reservas[i].fecha,puntosRecarga[j].reservas[i].duracion,fecha,duracion)){
            if(!prValido){/*Si no ha encontrado todavia*/
              prValido=true;
              prDisponible=i;
              rDisponible=j;
            /*Cabe en esta fecha la duracion que pide?*/
          }
        }
      }
    }
  }
  if(prValido){
    printf("He encontrado disponibilidad en PR id: %i y Reserva id:%i",prDisponible,rDisponible);
  }else{
    printf("\nNo he encontrado reserva");
  }

  return true;
}
