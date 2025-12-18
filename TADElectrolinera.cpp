#include <stdio.h>
#include <string.h>
#include "TADElectrolinera.h"
#include "TADFecha.h"
/*
-------------------------Intentamos crear la reserva-------------------------
*/

int TipoElectrolinera::CrearReserva(int duracion,TipoHora horaInicio,int nivel,TipoFecha fecha){
  int prSeleccionado=0;
  int rLibre=-1;
  bool encontradoReservaLibre=false;
  bool solapa = false;
  TipoFecha fechaFinal;
  TipoHora horaFinal;

  /*Comprobamos de los PR del nivel que buscamos */

  for(int i=0;i<MAX_NUMERO_PUNTOSRECARGA;i++){

      if(puntosRecarga[i].isActive && puntosRecarga[i].nivel==nivel){
        solapa = false;
        rLibre = -1;
        util.CalcularFechaHoraFinal(fecha,horaInicio,util.AproximarDuracion(duracion,puntosRecarga[i].rodajaMinima),fechaFinal,horaFinal);
        /* Recorremos todas sus reservas*/
        for(int j=0;j<MAX_NUMERO_RESERVAS;j++){

          /* Guardamos la primera que este libre*/
          if(!puntosRecarga[i].reservas[j].isActive && rLibre == -1){
            rLibre=j;
          }
          /* Todas las que esten activas se revisa si solapan*/
          if(puntosRecarga[i].reservas[j].isActive){
            if(!puntosRecarga[i].reservas[j].esDisponible(fecha,horaInicio,horaFinal)){
              solapa = true;
            }
          }

        }

      }
    if(!solapa && rLibre!= -1){
        ultimoIdReserva++;
        puntosRecarga[i].reservas[rLibre].isActive = true;
        puntosRecarga[i].reservas[rLibre].fechaInicio = fecha;
        puntosRecarga[i].reservas[rLibre].duracion = util.AproximarDuracion(duracion,puntosRecarga[i].rodajaMinima);
        puntosRecarga[i].reservas[rLibre].id = ultimoIdReserva;
        puntosRecarga[i].reservas[rLibre].horaInicio = horaInicio;
        puntosRecarga[i].reservas[rLibre].horaFinal = horaFinal;
        puntosRecarga[i].reservas[rLibre].fechaFinal = fechaFinal;
        return i;
        }
  }

  printf("\nNo he encontrado reserva");
  return -1;
}
