#pragma once
#include "TADFecha.h"
typedef int TipoFechas[12];
const TipoFechas DAYS_IN_MONTH = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const TipoFechas DAYS_IN_MONTH_LEAP = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
typedef enum TipoCorriente {DC,AC};
typedef enum TipoEstacion{Urbano,Ruta,Mixta};
typedef char string[20];
typedef struct TipoUtilidades{
  bool MensajeConfirmacion();
  TipoEstacion DevolverTipoElectrolinera(string tipo);
  TipoCorriente DevolverTipoCorriente(string tipoCorriente);
  int DevolverNivelPuntoRecarga(int potencia);
  bool CompatibilidadFechas(TipoFecha fechaReserva,int duracion,TipoFecha fechaUsuario,int duracion);
  int AproximarDuracion(int duracion,int rodaja);
  int DevolverPorcentajeOcupacion(int duracion);
  bool FechaEnRango(TipoFecha initial_date, TipoFecha date, TipoFecha final_date);
  void CalcularFechaHoraFinal(TipoFecha fechaInicio, TipoHora horaInicio, int duracion, TipoFecha &fechaFinal,TipoHora &horaFinal);
  int CompararFechas(TipoFecha date1, TipoFecha date2);
};
