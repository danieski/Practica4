#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADReservas.h"
bool TipoReserva::esDisponible(TipoHora horaInicioEntrante,TipoFecha fechaEntrante,int duracionEntrante){


    printf("\nFecha entrante: %02d/%02d/%04d %02d:%02d  Mi reserva %i: %02d/%02d/%04d %02d:%02d.",fechaEntrante.dia,fechaEntrante.mes,fechaEntrante.anno,horaInicioEntrante.horas,horaInicioEntrante.minutos,id,fechaInicio.dia,fechaInicio.mes,fechaInicio.anno,horaInicio.horas,horaInicio.minutos);
    /*Aqui tenemos que hacer una formula que coja la fecha de Entrada y la fecha de Reserva
     y diga False en caso de que se solape de 1 de las 4 formas que tiene de solaparse*/

    return true;
}
