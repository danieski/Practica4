#pragma once
typedef enum TipoCorriente {DC,AC};
typedef struct PuntoRecarga{
  TipoCorriente tipoCorriente;
  int potencia;
  int rodajaMinima;
  int nivel;
};
typedef PuntoRecarga ListaPuntosRecarga[20];
typedef enum TipoEstacion{Urbana,Ruta,Mixta};
typedef char String[21];
typedef struct Electrolinera{
  String nombre;
  int cargaRapida;
  int cargaMedia;
  int cargaLenta;
  TipoEstacion tipo;
  float latitud;
  float longitud;
  ListaPuntosRecarga puntosRecarga;
};
typedef Electrolinera ListaElectrolinera[10];
/*Procedimientos*/
void ImprimirMenu();
/*TipoEstacion SeleccionTipo(String tipo);*/
void EditarElectrolinera(ListaElectrolinera &listaElectrolinera);
void IntroducirDatosElectrolinera(ListaElectrolinera &listaElectrolinera);
void EditarPuntoDeRecarga(ListaElectrolinera &listaElectrolinera);
/*Funciones*/
bool MensajeConfirmacion();
