#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADReservas.h"
bool TipoReserva::esDisponible(TipoFecha fechaEntrante, TipoHora horaInicioEntrante, TipoHora horaFinalEntrante){

    int inicioEntrante,inicioActual,finalEntrante,finalActual;
    bool seSolapan;
    // Si las fechas NO coinciden → no puede haber solape
    if (fechaEntrante.dia  != fechaInicio.dia || fechaEntrante.mes  != fechaInicio.mes || fechaEntrante.anno != fechaInicio.anno)
    {
        return true;   // Libre
    }

    // Convertir horas a minutos para comparar fácilmente
    inicioEntrante = horaInicioEntrante.horas * 60 + horaInicioEntrante.minutos;
    finalEntrante   = horaFinalEntrante.horas   * 60 + horaFinalEntrante.minutos;

    inicioActual = horaInicio.horas * 60 + horaInicio.minutos;
    finalActual   = horaFinal.horas   * 60 + horaFinal.minutos;

    // Comprobar solapamiento
    seSolapan = (inicioEntrante < finalActual) && (inicioActual < finalEntrante);

    // DEBUG opcional
    printf("\nComparando con reserva %d:", id);
    printf("\nEntrante %02d:%02d - %02d:%02d",
           horaInicioEntrante.horas, horaInicioEntrante.minutos,
           horaFinalEntrante.horas, horaFinalEntrante.minutos);
    printf("\nExistente %02d:%02d - %02d:%02d\n",
           horaInicio.horas, horaInicio.minutos,
           horaFinal.horas, horaFinal.minutos);

    return !seSolapan; // true = disponible, false = ocupado
}
