#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADReservas.h"
bool TipoReserva::esDisponible(TipoFecha fechaEntrante, TipoHora horaInicioEntrante, TipoHora horaFinalEntrante){

    int startNew,startOld,endNew,endOld;
    bool seSolapan;
    // Si las fechas NO coinciden → no puede haber solape
    if (fechaEntrante.dia  != fechaInicio.dia ||
        fechaEntrante.mes  != fechaInicio.mes ||
        fechaEntrante.anno != fechaInicio.anno)
    {
        return true;   // Libre
    }

    // Convertir horas a minutos para comparar fácilmente
    startNew = horaInicioEntrante.horas * 60 + horaInicioEntrante.minutos;
    endNew   = horaFinalEntrante.horas   * 60 + horaFinalEntrante.minutos;

    startOld = horaInicio.horas * 60 + horaInicio.minutos;
    endOld   = horaFinal.horas   * 60 + horaFinal.minutos;

    // Comprobar solapamiento
    seSolapan = (startNew < endOld) && (startOld < endNew);

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
