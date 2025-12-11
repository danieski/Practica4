#include <stdio.h>
#include <string.h>
#include "TADElectrolinera.h"
#include "TADFecha.h"
/*
-------------------------Intentamos crear la reserva-------------------------
*/

int TipoElectrolinera::crear_reserva(int duracion,TipoHora horaInicio,int nivel,TipoFecha fecha,int ultimoIdReserva){
  int prSeleccionado=0;
  int prDisponible = -1;
  int rDisponible;
  bool prValido=false;
  bool check = true;

  /*Buscamos el primer pr con el nivel que buscamos*/

  for(int i=0;i<=MAX_NUMERO_PUNTOSRECARGA;i++){
      if(puntosRecarga[i].isActive && puntosRecarga[i].nivel==nivel){

        /*Si encuentro un pr activo con el nuvel que busco*/
        /*Encontramos el un PR activo con el mismo nivel*/
        /*compruebo la disponibilidad de todos los que cumplan el anterior criterio hasta que me de true*/
        for(int j=0;j<=MAX_NUMERO_RESERVAS;j++){

          /*Recorremos y econtramos una reserva activa*/
          if(puntosRecarga[i].reservas[j].isActive){

            /*comprobamos que esta reserva no solape la nuestra*/
            /*En este punto compruebo que NINGUNA reserva solape a la mia con que 1 sola reserva lo haga devolvemos false y no se guarda*/
            check = puntosRecarga[i].reservas[j].esDisponible(horaInicio,fecha,duracion/*Aqui metemos los datos de la reserva que queremos hacer y tiene que dar check*/);
            /*Si no se ha encontrado prValido todavia guardamos los datos de la reserva disponible*/
            if(!prValido){

              /*Esto evita que se guarde varias veces despues de haber entontrado un hueco*/
              prValido=true;
              prDisponible=i;
              rDisponible=j;

            }

          }

        }

      }

    }

  if(prValido && check){
    puntosRecarga[prDisponible].reservas[rDisponible].isActive = true;
    puntosRecarga[prDisponible].reservas[rDisponible].fechaInicio = fecha;
    puntosRecarga[prDisponible].reservas[rDisponible].duracion = util.aproximar_duracion(duracion,puntosRecarga[prDisponible].rodajaMinima);
    puntosRecarga[prDisponible].reservas[rDisponible].id = ultimoIdReserva +1;
    /*printf("\nHe encontrado disponibilidad en PR id: %i y Reserva id:%i",prDisponible,rDisponible);*/

  }else{
    printf("\nNo he encontrado reserva");
  }

  return prDisponible;
}
