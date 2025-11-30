#pragma once
#include "TADElectrolinera.h"
#include "TADUtilidades.h"
#include "TADFecha.h"
typedef TipoElectrolinera TipoElectrolineras[5];
typedef struct TipoOperacion{
  TipoUtilidades util;
  TipoElectrolineras electrolineras;
  /*Funciones*/
  void editar_electrolinera();
  void editar_puntorecarga();
  void reservar_puntorecarga();
  void cargar_datos();
};
