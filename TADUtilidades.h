#pragma once
#include "TADFecha.h"
typedef enum TipoCorriente {DC,AC};
typedef enum TipoEstacion{Urbano,Ruta,Mixta};
typedef char string[20];
typedef struct TipoUtilidades{
  bool mensaje_confirmacion();
  TipoEstacion devolver_tipo_electrolinera(string tipo);
  TipoCorriente devolver_tipo_corriente(string tipoCorriente);
  int devolver_nivel_puntorecarga(int potencia);
  bool compatibilidad_fechas(TipoFecha fechaReserva,int duracion,TipoFecha fechaUsuario,int duracion);
  int aproximar_duracion(int duracion,int rodaja);
};
