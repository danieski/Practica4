#pragma once
#include "TADFecha.h"
typedef struct TipoReserva{
  int id;
  bool isActive;
  TipoFecha fechaInicio;
  TipoFecha fechaFinal;
  TipoHora horaInicio;
  TipoHora horaFinal;
  int duracion;
  bool esDisponible(TipoHora horaInicioEntrante,TipoFecha fechaEntrante,int duracionEntrante);
};


