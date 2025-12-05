#include "TADUtilidades.h"
#include <stdio.h>
#include <string.h>

/*Espera a que el usuario presione S*/
bool TipoUtilidades::mensaje_confirmacion(){
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

TipoEstacion TipoUtilidades::devolver_tipo_electrolinera(string tipo){
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
TipoCorriente TipoUtilidades::devolver_tipo_corriente(string tipoCorriente){
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
int TipoUtilidades::devolver_nivel_puntorecarga(int potencia){
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
int TipoUtilidades::aproximar_duracion(int duracion,int rodajaMinima){
  return ((duracion + rodajaMinima - 1) / rodajaMinima) * rodajaMinima;
}
bool TipoUtilidades::compatibilidad_fechas(TipoFecha fechaReserva,int duracionReserva,TipoFecha fechaUsuario,int duracionUsuario){
  return true;
}
