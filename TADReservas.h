#pragma once
#include "TADFecha.h"
typedef struct Hora{
  int horas;
  int minutos;
};
typedef struct TipoReserva{
  bool isActive;
  TipoFecha fecha;
  Hora inicio;
  Hora final;
  int duracion;
  void FuncionReservas();
};


