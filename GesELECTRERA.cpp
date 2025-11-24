#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GesELECTRERA.h"
void ImprimirMenu(){
    printf("GesELECTRERA: Gestion de electrolinearas\n\n");
    printf("\tEditar electrolinera\n");
    printf("\tEditar punto de recarga\n");
    printf("\tReservar punto de recarga\n");
    printf("\tListar reservas de electrolinera\n");
    printf("\tListar servicio mensual punto\n");
    printf("\tSalir\n\n");
    printf("Teclear una opcion valida (E|P|R|L|M|S)?\n");
}
bool MensajeConfirmacion(){
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
TipoEstacion SeleccionTipoElectrolinera(String tipo){
  if(strcmp(tipo,"Urbano") == 0){
    return Urbana;
  }else if(strcmp(tipo,"Ruta") == 0){
    return Ruta;
  }else if(strcmp(tipo,"Mixta") == 0){
    return Mixta;
  }else{
    printf("\nTipo no detectado");
    return Urbana;
  }
}
void EditarElectrolinera(ListaElectrolinera &listaElectrolinera){
  /*VARIABLES*/
    int identificador,cargaRapida,cargaMedia,cargaLenta;
    float latitud,longitud;
    char confirmar;
    String nombre;
    String tipo;
    /*TEXTO Y PREGUNTAS*/
    printf("Editar electrolinera:\n\n");
    printf("\n\tIdentificador(numero entre 1 y 10)?");
    scanf("%i",&identificador);
    fflush(stdin);
    printf("\tNombre(entre 1 y 20 caracteres)?");
    scanf("%s",&nombre);
    fflush(stdin);
    printf("\tNum. de puntos de carga RAPIDOS-Nivel3");
    scanf("%i",&cargaRapida);
    fflush(stdin);
    printf("\tNum. de puntos de carga SEMI-RAPIDOS-Nivel2");
    scanf("%i",&cargaMedia);
    printf("\tNum. de puntos de carga LENTOS-Nivel 1");
    scanf("%i",&cargaLenta);
    printf("\tTipo de Estacion(Urbana,Ruta,Mixta)");
    scanf("%s",&tipo);
    printf("\tLatitud (WGS84)");
    scanf("%f",&latitud);
    printf("\tLongitud (WGS84)");
    scanf("%f",&longitud);
    printf("\n\nIMPORTANTE: Esta opcion borra los datos anteriores.");
    printf("\nSon correctos los nuevos datos (S/N)?.");
   /*CONFIRMACION*/

    if(MensajeConfirmacion()){
      strcpy(listaElectrolinera[identificador].nombre,nombre);
      listaElectrolinera[identificador].cargaRapida = cargaRapida;
      listaElectrolinera[identificador].cargaMedia = cargaMedia;
      listaElectrolinera[identificador].cargaLenta = cargaLenta;
      listaElectrolinera[identificador].tipo = SeleccionTipoElectrolinera(tipo);
      listaElectrolinera[identificador].latitud = latitud;
      listaElectrolinera[identificador].longitud = longitud;
    }
}

/* No se puede hacer una funcion devuelva vector
ListaPuntosRecarga DevuelveListaPuntosRecarga(ListaElectrolinera listaElectrolinera,int identificador){
  return listaElectrolinera[identificador].puntosRecarga;
}*/
TipoCorriente SeleccionTipoCorriente(String tipoCorriente){
  if(strcmp(tipoCorriente,"DC") == 0){
    return DC;
  }else if(strcmp(tipoCorriente,"AC") == 0 ){
    return AC;
  }else{
    printf("Tipo Corriente No Econtrado");
    return DC;
  }
}
int SeleccionarNivelCarga(int potencia){
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
void EditarPuntoDeRecarga(ListaElectrolinera &listaElectrolinera){
  int identificadorElectrolinera,identificadorPuntoCarga,potencia,rodajaMinima;
  String tipoCorriente;
  bool esTipoCorrienteValida = false;
  bool esLimiteNivelValida = false;
  int limitePuntoSegunTipo;
  printf("Editar punto de carga:\n");
  printf("\tIdentificador electrolinera (numero entre 1 y 10)?");
  fflush(stdin);
  scanf("%i",&identificadorElectrolinera);
  printf("\n\tIdentificador punto de carga(numero entre 1 y 20)?");
  fflush(stdin);
  scanf("%i",&identificadorPuntoCarga);
  printf("\n\tTipo de corriente(DC/AC)?");
  fflush(stdin);
  scanf("%s",&tipoCorriente);
  printf("\n\tPotencia (kW)?");
  fflush(stdin);
  scanf("%i",&potencia);
  printf("\n\tRodaja minima de recarga (minutos)?");
  fflush(stdin);
  scanf("%i",&rodajaMinima);
  printf("\nSon correctos los nuevos datos(S/N)?");
  if(MensajeConfirmacion()){
    /*Comprobaciones de los datos introducidos*/
    /*Comprobacion tipo corriente*/
    if(SeleccionTipoCorriente(tipoCorriente)==DC){
      if(SeleccionarNivelCarga(potencia) == 3){
        esTipoCorrienteValida = true;
      }else{
        printf("\nerror: potencia con tipocorriente DC no puede si Nivel carga no es 3");
        esTipoCorrienteValida = false;
      }
    }else if(SeleccionTipoCorriente(tipoCorriente)==AC){
      if(SeleccionarNivelCarga(potencia) < 3){
        esTipoCorrienteValida = true;
      }else{
        printf("\nerror: potencia con tipocorriente AC no puede si Nivel carga no es 2 o menor");
        esTipoCorrienteValida = false;
      }
    };
    /*Comprobacion respeta limites de tipo corriente*/

    /*Cuantas TipoCorriente puedo ponner en esta lectrolinera?*/
    switch(SeleccionarNivelCarga(potencia)){
      case 1:
      limitePuntoSegunTipo = listaElectrolinera[identificadorElectrolinera].cargaLenta;
      break;
      case 2:
      limitePuntoSegunTipo = listaElectrolinera[identificadorElectrolinera].cargaMedia;
      break;
      case 3:
      limitePuntoSegunTipo = listaElectrolinera[identificadorElectrolinera].cargaRapida;
      break;
      default:
      printf("Error: limitede Carga de electrolinera no reconocido");
    };
    /*Cuantos TipoCorrientes hay ya puestos?*/
    for(int i=0;i<20;i++){
      /*Recorremos todos los puntos de recarga*/
      if(listaElectrolinera[identificadorElectrolinera].puntosRecarga[i].nivel == SeleccionarNivelCarga(potencia)){
        limitePuntoSegunTipo--;/*Si el punto de recarga leido coincide con el tipo seleccionado restamos*/
        /*printf("\nLimite Puntos Segun TIPO: %i", limitePuntoSegunTipo);*/
        /*NECESITAMOS AGREGAR MAS VARIABLES A CADA PUNTO DE RECARGA PARA NO ESTAR USANDO LAS FUNCIONES CONTINUAMENTE*/
      };
    }
    if(limitePuntoSegunTipo>0){
      esLimiteNivelValida=true;
    }else{
      esLimiteNivelValida=false;
      printf("\n error: Limite de Nivel alcanzado");
    }

    if(esTipoCorrienteValida && esLimiteNivelValida){

      listaElectrolinera[identificadorElectrolinera].puntosRecarga[identificadorPuntoCarga].nivel = SeleccionarNivelCarga(potencia);
      listaElectrolinera[identificadorElectrolinera].puntosRecarga[identificadorPuntoCarga].tipoCorriente = SeleccionTipoCorriente(tipoCorriente);
      listaElectrolinera[identificadorElectrolinera].puntosRecarga[identificadorPuntoCarga].potencia = potencia;
      listaElectrolinera[identificadorElectrolinera].puntosRecarga[identificadorPuntoCarga].rodajaMinima = rodajaMinima;
      printf("\n\t Configuracion correcta: Electrolinera: %i. Punto de carga: %i. Nivel%i\n",identificadorElectrolinera,identificadorPuntoCarga,listaElectrolinera[identificadorElectrolinera].puntosRecarga[identificadorPuntoCarga].nivel);
    };
  };
}
void IntroducirDatosElectrolinera(ListaElectrolinera &listaElectrolinera){
  strcpy(listaElectrolinera[0].nombre,"test");
  listaElectrolinera[0].cargaRapida = 1;
  listaElectrolinera[0].cargaMedia = 1;
  listaElectrolinera[0].cargaLenta = 1;
  listaElectrolinera[0].tipo = Urbana;
  listaElectrolinera[0].longitud = 12.12;
  listaElectrolinera[0].latitud = 12.12;
  strcpy(listaElectrolinera[1].nombre,"test2");
  listaElectrolinera[1].cargaRapida = 2;
  listaElectrolinera[1].cargaMedia = 2;
  listaElectrolinera[1].cargaLenta = 2;
  listaElectrolinera[1].tipo = Urbana;
  listaElectrolinera[1].longitud = 22.12;
  listaElectrolinera[1].latitud = 22.12;
  /*Punto carga*/
  listaElectrolinera[0].puntosRecarga[0].nivel=3;
  listaElectrolinera[0].puntosRecarga[0].potencia=75;
  listaElectrolinera[0].puntosRecarga[0].rodajaMinima=10;
  listaElectrolinera[0].puntosRecarga[0].tipoCorriente=DC;
  listaElectrolinera[0].puntosRecarga[1].nivel=1;
  listaElectrolinera[0].puntosRecarga[1].potencia=3;
  listaElectrolinera[0].puntosRecarga[1].rodajaMinima=10;
  listaElectrolinera[0].puntosRecarga[1].tipoCorriente=AC;
}

