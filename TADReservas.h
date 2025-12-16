#pragma once
#include "TADFecha.h"
#include "TADUtilidades.h"
typedef struct TipoReserva{
  TipoUtilidades util;
  int id;
  bool isActive;
  TipoFecha fechaInicio;
  TipoFecha fechaFinal;
  TipoHora horaInicio;
  TipoHora horaFinal;
  int duracion;
  bool esDisponible(TipoFecha fechaEntrante, TipoHora horaInicioEntrante, TipoHora horaFinalEntrante);

};


