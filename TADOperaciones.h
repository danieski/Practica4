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
  void editar_electrolinera();
  void editar_puntorecarga();
  void reservar_puntorecarga();
  void cargar_datos();
  void listar_reservas();
  void calendario_reservas();
};
