#pragma once
#include "TADUtilidades.h"
#include "TADElectrolinera.h"
#include "TADOperaciones.h"
typedef struct TipoMenu{
  TipoElectrolinera electrolinera;
  TipoUtilidades util;
  TipoOperacion ops;
  void Inicializar();
};
