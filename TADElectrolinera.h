#pragma once
#include "TADUtilidades.h"
#include "TADReservas.h"
typedef char string[20];
const int MAX_NUMERO_PUNTOSRECARGA=20;
const int MAX_NUMERO_RESERVAS=5;
typedef TipoReserva TipoReservas[MAX_NUMERO_RESERVAS];

typedef struct TipoPuntoRecarga{
  bool isActive;
  int id;
  void EditarPuntoDeRecarga();
  void AgregarPuntoDeRecraga();
  TipoCorriente tipoCorriente;
  int potencia;
  int rodajaMinima;
  int nivel;
  TipoReservas reservas;
};

typedef TipoPuntoRecarga TipoPuntosRecarga[MAX_NUMERO_PUNTOSRECARGA];

typedef struct TipoElectrolinera{
  TipoUtilidades util;
  /*Funciones*/
  bool crear_reserva(int duracion,int nivel,TipoFecha fecha);
  /*Variables*/
  int cargaRapida,cargaMedia,cargaLenta;
  float longitud,latitud;
  TipoEstacion tipo;
  string nombre;
  /*Arrays*/
  TipoPuntosRecarga puntosRecarga;
};


