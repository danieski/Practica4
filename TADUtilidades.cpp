#include "TADUtilidades.h"
#include <stdio.h>
#include <string.h>

/*Espera a que el usuario presione S*/
bool TipoUtilidades::MensajeConfirmacion(){
  char eleccion;
  fflush(stdin);
  scanf("%c",&eleccion);
  fflush(stdin);
  if(eleccion == 'S'){
    return true;
  }else{
    return false;
  };
}

/*Recibe un string y devuelve el tipo enum de electrolinera que corresponde*/

TipoEstacion TipoUtilidades::DevolverTipoElectrolinera(string tipo){
  if(strcmp(tipo,"Urbana") == 0){
    return Urbano;
  }else if(strcmp(tipo,"Ruta") == 0){
    return Ruta;
  }else if(strcmp(tipo,"Mixta") == 0){
    return Mixta;
  }else{
    printf("\nTipo no detectado");
    return Urbano;
  }
}
/*-------------Devuelve el tipo de corriente segun el string introducido------------------*/
TipoCorriente TipoUtilidades::DevolverTipoCorriente(string tipoCorriente){
  if(strcmp(tipoCorriente,"DC") == 0){
    return DC;
  }else if(strcmp(tipoCorriente,"AC") == 0 ){
    return AC;
  }else{
    printf("Tipo Corriente No Econtrado");
    return DC;
  }
}
/*------------Devuelve el nivel del punto de recarga dependiendo de la potencia------------*/
int TipoUtilidades::DevolverNivelPuntoRecarga(int potencia){
  if(potencia<=4&&potencia>=2){
      return 1;
  }else if(potencia>=11&&potencia<=22){
    return 2;
  }else if(potencia>=50&&potencia<=300){
    return 3;
  }else{
    printf("potencia no valida");
    return 1;
  }

}
/*----Aproxima la duracion del usuario a la rodaja----*/
int TipoUtilidades::AproximarDuracion(int duracion,int rodajaMinima){
  return ((duracion + rodajaMinima - 1) / rodajaMinima) * rodajaMinima;
}

/*---Obtener porcentaje de ocupacion-----*/
int TipoUtilidades::DevolverPorcentajeOcupacion(int duracion){
    double horas = duracion / 60.0;       // conversión precisa
    double porcentaje = (horas / 24.0) * 100.0;
    return int(porcentaje);               // o redondear si quieres
}
int TipoUtilidades::CompararFechas(TipoFecha date1, TipoFecha date2) {
    /*  +1 = date1>date2    */
    /*  -1 = date1<date2    */
    /*  0 = date1=date2     */

    /*Primero se compara los años*/
    if (date1.anno > date2.anno) {
        return 1;
    } else if (date1.anno < date2.anno) {
        return -1;
    }

    /*Si los años coinciden, compara los meses*/
    if (date1.mes > date2.mes) {
        return 1;
    } else if (date1.mes < date2.mes) {
        return -1;
    }

    /*Si los meses coinciden, compara los días*/
    if (date1.dia > date2.dia) {
        return 1;
    } else if (date1.dia < date2.dia) {
        return -1;
    }

    /*Si el año, mes y día son iguales*/
    return 0;
}






/*
    Se va a sumar la duracion a la fecha inicial para dar lugar a una fecha inal y una hora final
*/
void TipoUtilidades::CalcularFechaHoraFinal(TipoFecha fechaInicio, TipoHora horaInicio, int duracion, TipoFecha &fechaFinal,TipoHora &horaFinal){
    int minutosIniciales,minutosTotales,diasExtra;

    // Copiamos fecha inicial

    fechaFinal = fechaInicio;

    // Convertir hora inicial a minutos totales
    minutosIniciales = horaInicio.horas * 60 + horaInicio.minutos;
    minutosTotales = minutosIniciales + duracion;

    // Calcular hora final
    horaFinal.horas = (minutosTotales / 60) % 24;
    horaFinal.minutos = minutosTotales % 60;

    // Si supera 24h, sumar días
    diasExtra = minutosTotales / (24 * 60);
    fechaFinal.dia = fechaFinal.dia + diasExtra;

    // Opcional: controlar cambio de mes/año (si lo necesitas)
}


