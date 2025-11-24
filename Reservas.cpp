#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Reservas.h"
#include "GesELECTRERA.h"

void FuncionReservas(){
  int identificadorElectrolinera,dia,mes,anno,hora,minuto,duracion,nivel;
  bool esCorrecto = true;
  printf("Reservar punto de recarga:\n");
  printf("\tIdentificador de electrolinera?");
  scanf("%i",&identificadorElectrolinera);
  fflush(stdin);
  printf("\tTipo de punto de recarga (Nivel1/Nivel2/Nivel3)? N");
  scanf("%i",&nivel);
  fflush(stdin);
  printf("\tDatos reserva: Dia?");
  scanf("%i",&dia);
  fflush(stdin);
  printf("\tDatos reserva: Mes?");
  scanf("%i",&mes);
  fflush(stdin);
  printf("\tDatos reserva: Anno?");
  scanf("%i",&anno);
  fflush(stdin);
  printf("\tDatos reserva: Hora?");
  scanf("%i",&hora);
  fflush(stdin);
  printf("\tDatos reserva: Minuto?");
  scanf("%i",&minuto);
  fflush(stdin);
  printf("\tDatos reserva: Duracion?");
  scanf("%i",&duracion);
  fflush(stdin);
  printf("\n\t\t Datos de la Reserva:");
  printf("\n\tE/S: %s (Id=%i)","NOMBRE ELECTROLINERA",identificadorElectrolinera);
  printf("\n\tFecha reserva: %i-%i-%i",dia,mes,anno);
  printf("\n\tHora reserva: %i:%i",hora,minuto);
  printf("\n\tDuracion: %i minutos",duracion);
  printf("\nSon correctos los datos de la reserva (S/N)?");
  if(MensajeConfirmacion() && esCorrecto){
    printf("\n\tReserva correcta.");
    printf("\n\t\tIdentificador: Punto de carga N%i-PuntoCarga-NumeroReserva-%i-%i",nivel,mes,anno);
    printf("\n\tFecha y hora: %i-%i-%i %i:%i",dia,mes,anno,hora,minuto);
    printf("\n\tTiempo %i minutos RODAJAS",duracion);
  };

}
