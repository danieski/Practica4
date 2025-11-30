#include "TADOperaciones.h"
#include <stdio.h>
#include <string.h>
void TipoOperacion::cargar_datos(){
  TipoFecha fechaPrueba;
  fechaPrueba.dia=1;
  fechaPrueba.mes=1;
  fechaPrueba.anno=1900;
  for(int i=0;i<5;i++){
    electrolineras[i].cargaRapida = 1;
    electrolineras[i].cargaMedia = 1;
    electrolineras[i].cargaLenta = 1;
    strcpy(electrolineras[i].nombre,"test");
    printf("\nElectrolinera %i",i);
    for(int j=0;j<=3;j++){
      electrolineras[i].puntosRecarga[j].isActive=true;
      electrolineras[i].puntosRecarga[j].potencia=3;
      electrolineras[i].puntosRecarga[j].tipoCorriente=AC;
      electrolineras[i].puntosRecarga[j].nivel=1;
      printf("\n\tPunto Recarga: %i",j);
      for(int h=0;h<=3;h++){
        electrolineras[i].puntosRecarga[j].reservas[h].isActive=true;
        electrolineras[i].puntosRecarga[j].reservas[h].fecha=fechaPrueba;
        electrolineras[i].puntosRecarga[j].reservas[h].duracion=3;
        printf("\n\tReserva: %i",h);

      }
    }
  }
}
void TipoOperacion::editar_electrolinera(){
    /*VARIABLES*/
    int identificador,cargaRapida,cargaMedia,cargaLenta;
    float latitud,longitud;
    char confirmar;
    string nombre,tipo;
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

    if(util.mensaje_confirmacion()){
      strcpy(electrolineras[identificador].nombre,nombre);
      electrolineras[identificador].cargaRapida = cargaRapida;
      electrolineras[identificador].cargaMedia = cargaMedia;
      electrolineras[identificador].cargaLenta = cargaLenta;
      electrolineras[identificador].tipo = util.devolver_tipo_electrolinera(tipo);
      electrolineras[identificador].latitud = latitud;
      electrolineras[identificador].longitud = longitud;
      for(int i=0;i<=MAX_NUMERO_PUNTOSRECARGA;i++){
        electrolineras[identificador].puntosRecarga[i].id=0;
      }

    }

}
void TipoOperacion::editar_puntorecarga(){
  /*Variables*/
  int identificadorElectrolinera,identificadorPuntoCarga,potencia,rodajaMinima;
  string tipoCorriente;
  bool esTipoCorrienteValida = false;
  bool esLimiteNivelValida = false;
  int limitePuntoSegunTipo;
  /*Menu*/
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
  if(util.mensaje_confirmacion()){
    /*Comprobaciones de los datos introducidos*/
    /*Comprobacion tipo corriente*/
    if(util.devolver_tipo_corriente(tipoCorriente)==DC){
      if(util.devolver_nivel_puntorecarga(potencia) == 3){
        esTipoCorrienteValida = true;
      }else{
        printf("\nerror: potencia con tipocorriente DC no puede si Nivel carga no es 3");
        esTipoCorrienteValida = false;
      }
    }else if(util.devolver_tipo_corriente(tipoCorriente)==AC){
      if(util.devolver_nivel_puntorecarga(potencia) < 3){
        esTipoCorrienteValida = true;
      }else{
        printf("\nerror: potencia con tipocorriente AC no puede si Nivel carga no es 2 o menor");
        esTipoCorrienteValida = false;
      }
    };
    /*Comprobacion respeta limites de tipo corriente*/

    /*Cuantas TipoCorriente puedo ponner en esta lectrolinera?*/
    switch(util.devolver_nivel_puntorecarga(potencia)){
      case 1:
      limitePuntoSegunTipo = electrolineras[identificadorElectrolinera].cargaLenta;
      break;
      case 2:
      limitePuntoSegunTipo = electrolineras[identificadorElectrolinera].cargaMedia;
      break;
      case 3:
      limitePuntoSegunTipo = electrolineras[identificadorElectrolinera].cargaRapida;
      break;
      default:
      printf("Error: limitede Carga de electrolinera no reconocido");
    };
    /*Confirmamo no superar el limite de puntos de recarga de ese nivel*/
    for(int i=0;i<=20;i++){
      /*Recorremos todos los puntos de recarga*/
      if(electrolineras[identificadorElectrolinera].puntosRecarga[i].nivel == util.devolver_nivel_puntorecarga(potencia)){
        limitePuntoSegunTipo--;/*Si el punto de recarga leido coincide con el tipo seleccionado restamos*/
      };
    }
    if(limitePuntoSegunTipo>0){
      esLimiteNivelValida=true;
    }else{
      esLimiteNivelValida=false;
      printf("\n error: Limite de Nivel alcanzado");
    }

    if(esTipoCorrienteValida && esLimiteNivelValida){

      electrolineras[identificadorElectrolinera].puntosRecarga[identificadorPuntoCarga].nivel = util.devolver_nivel_puntorecarga(potencia);
      electrolineras[identificadorElectrolinera].puntosRecarga[identificadorPuntoCarga].tipoCorriente = util.devolver_tipo_corriente(tipoCorriente);
      electrolineras[identificadorElectrolinera].puntosRecarga[identificadorPuntoCarga].potencia = potencia;
      electrolineras[identificadorElectrolinera].puntosRecarga[identificadorPuntoCarga].rodajaMinima = rodajaMinima;
      electrolineras[identificadorElectrolinera].puntosRecarga[identificadorPuntoCarga].isActive = true;
      printf("\n\t Configuracion correcta: Electrolinera: %i. Punto de carga: %i. Nivel%i\n",identificadorElectrolinera,identificadorPuntoCarga,electrolineras[identificadorElectrolinera].puntosRecarga[identificadorPuntoCarga].nivel);
    };
  };
}
void TipoOperacion::reservar_puntorecarga(){
  /*Variables*/
  TipoFecha fechausuario;
  int identificadorElectrolinera,dia,mes,anno,hora,minuto,duracion,nivel;
  bool esCorrecto = true;
  /*Menu*/
  printf("Reservar punto de recarga:\n");
  printf("\tIdentificador de electrolinera?");
  scanf("%i",&identificadorElectrolinera);
  fflush(stdin);
  printf("\tTipo de punto de recarga (Nivel1/Nivel2/Nivel3)? N");
  scanf("%i",&nivel);
  fflush(stdin);
  printf("\tDatos reserva: Dia?");
  scanf("%i",&dia);
  fflush(stdin);
  printf("\tDatos reserva: Mes?");
  scanf("%i",&mes);
  fflush(stdin);
  printf("\tDatos reserva: Anno?");
  scanf("%i",&anno);
  fflush(stdin);
  printf("\tDatos reserva: Hora?");
  scanf("%i",&hora);
  fflush(stdin);
  printf("\tDatos reserva: Minuto?");
  scanf("%i",&minuto);
  fflush(stdin);
  printf("\tDatos reserva: Duracion?");
  scanf("%i",&duracion);
  fflush(stdin);
  printf("\n\t\t Datos de la Reserva:");
  printf("\n\tE/S: %s (Id=%i)","NOMBRE ELECTROLINERA",identificadorElectrolinera);
  printf("\n\tFecha reserva: %i-%i-%i",dia,mes,anno);
  printf("\n\tHora reserva: %i:%i",hora,minuto);
  printf("\n\tDuracion: %i minutos",duracion);
  printf("\nSon correctos los datos de la reserva (S/N)?");
  /*Confirmaciones*/
    /*Referencia a la electrolinera*/

    fechausuario.dia=dia;
    fechausuario.mes=mes;
    fechausuario.anno=anno;

    /*Buscamos el primer Punto Recarga de ese nivel*/
    /*Dentro de su lista de reservas comprobamos que no hay reserva en la duracion introducida*/
  if(util.mensaje_confirmacion() && electrolineras[identificadorElectrolinera].crear_reserva(duracion,nivel,fechausuario)){
    printf("\n\tReserva correcta.");
    printf("\n\t\tIdentificador: Punto de carga N%i-PuntoCarga-NumeroReserva-%i-%i",nivel,mes,anno);
    printf("\n\tFecha y hora: %i-%i-%i %i:%i",dia,mes,anno,hora,minuto);
    printf("\n\tTiempo %i minutos RODAJAS",duracion);
  };
}
