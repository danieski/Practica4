#pragma once
#include "TADElectrolinera.h"
#include "TADUtilidades.h"
#include "TADFecha.h"
#include "TADCalendarioMes.h"
typedef TipoElectrolinera TipoElectrolineras[MAX_NUMERO_ELECTROLINERAS];
typedef int VectorDias[31];

typedef struct TipoOperacion{
  TipoUtilidades util;
  TipoElectrolineras electrolineras;
  /*Funciones*/
  void EditarElectrolinera();
  void EditarPuntoRecarga();
  void ReservarPuntoRecarga();
  void CargarDatos();
  void ListarReservas();
  void CalendarioReservas();
};
