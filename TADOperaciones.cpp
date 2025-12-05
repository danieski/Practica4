#include "TADOperaciones.h"
#include <stdio.h>
#include <string.h>
/*---------------Introduce unos datos inciales en el programa*/
void TipoOperacion::cargar_datos(){
  TipoFecha fechaDia1;
  TipoFecha fechaDia2;
  fechaDia1.dia=1;
  fechaDia1.mes=1;
  fechaDia1.anno=1900;
  fechaDia2.dia=2;
  fechaDia2.mes=1;
  fechaDia2.anno=1900;

  /*Inicializar arrays false*/
  for(int idElectrolineras = 0;idElectrolineras<MAX_NUMERO_ELECTROLINERAS;idElectrolineras++){
    /*printf("\nidElectrolinera: %i",idElectrolineras);*/
    for(int idPR = 0; idPR<MAX_NUMERO_PUNTOSRECARGA;idPR++){
      electrolineras[idElectrolineras].puntosRecarga[idPR].isActive=false;
      /*printf("\n\tidPR: %i",idPR);*/
      for(int idR = 0; idR<MAX_NUMERO_RESERVAS; idR++){
        electrolineras[idElectrolineras].puntosRecarga[idPR].reservas[idR].isActive=false;
        /*printf("\n\t\tidR: %i Active?: %i", idR, electrolineras[idElectrolineras].puntosRecarga[idPR].reservas[idR].isActive);*/
      }
    }
  }

  electrolineras[0].cargaRapida = 1;
  electrolineras[0].cargaMedia = 1;
  electrolineras[0].cargaLenta = 1;
  strcpy(electrolineras[0].nombre,"ES Nueva Carga");

  electrolineras[0].puntosRecarga[0].isActive=true;
  electrolineras[0].puntosRecarga[0].id=1;
  electrolineras[0].puntosRecarga[0].nivel=2;
  electrolineras[0].puntosRecarga[0].rodajaMinima=10;

  electrolineras[0].puntosRecarga[0].reservas[0].isActive=true;
  electrolineras[0].puntosRecarga[0].reservas[0].fecha = fechaDia1;
  electrolineras[0].puntosRecarga[0].reservas[0].duracion = 1;

  electrolineras[0].puntosRecarga[0].reservas[1].isActive=true;
  electrolineras[0].puntosRecarga[0].reservas[1].fecha = fechaDia1;
  electrolineras[0].puntosRecarga[0].reservas[1].duracion = 1;

  electrolineras[0].puntosRecarga[0].reservas[2].isActive=true;
  electrolineras[0].puntosRecarga[0].reservas[2].fecha = fechaDia2;
  electrolineras[0].puntosRecarga[0].reservas[2].duracion = 1;

  electrolineras[0].puntosRecarga[1].isActive=true;
  electrolineras[0].puntosRecarga[1].id=2;
  electrolineras[0].puntosRecarga[1].nivel=2;
  electrolineras[0].puntosRecarga[1].rodajaMinima=10;

  electrolineras[0].puntosRecarga[1].reservas[0].isActive=true;
  electrolineras[0].puntosRecarga[1].reservas[1].isActive=true;
  electrolineras[0].puntosRecarga[1].reservas[2].isActive=true;

  electrolineras[0].puntosRecarga[2].isActive=true;
  electrolineras[0].puntosRecarga[2].nivel=3;
  electrolineras[0].puntosRecarga[2].id=3;
  electrolineras[0].puntosRecarga[2].rodajaMinima=10;

  electrolineras[0].puntosRecarga[2].reservas[0].isActive=true;
  electrolineras[0].puntosRecarga[2].reservas[1].isActive=true;
  electrolineras[0].puntosRecarga[2].reservas[2].isActive=true;

}
/*-----Procedimiento que edita una electrolinera existente o no------*/
void TipoOperacion::editar_electrolinera(){

    int identificador,cargaRapida,cargaMedia,cargaLenta;
    float latitud,longitud;
    char confirmar;
    bool comprobaciones=true;
    string nombre,tipo;

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
   if(identificador>MAX_NUMERO_ELECTROLINERAS || identificador<=0){
     comprobaciones=false;
   }
   /*GUARDAMOS*/
    if(util.mensaje_confirmacion()&&comprobaciones){
      strcpy(electrolineras[identificador-1].nombre,nombre);
      electrolineras[identificador-1].cargaRapida = cargaRapida;
      electrolineras[identificador-1].cargaMedia = cargaMedia;
      electrolineras[identificador-1].cargaLenta = cargaLenta;
      electrolineras[identificador-1].tipo = util.devolver_tipo_electrolinera(tipo);
      electrolineras[identificador-1].latitud = latitud;
      electrolineras[identificador-1].longitud = longitud;
      for(int i=0;i<=MAX_NUMERO_PUNTOSRECARGA;i++){
        electrolineras[identificador-1].puntosRecarga[i].isActive=false;
      }

    }else{
      printf("\nERROR: Comprobaciones electrolineras");
    }

}
/*-----Procedimiento que edita un punto de carga existente o no------*/
void TipoOperacion::editar_puntorecarga(){

  /*VARIABLES*/
  int identificadorElectrolinera,identificadorPuntoCarga,potencia,rodajaMinima;
  string tipoCorriente;
  bool esTipoCorrienteValida = false;
  bool esLimiteNivelValida = false;
  int limitePuntoSegunTipo;

  /*DATOS DEL USUARIO*/
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

  /*COMPROBACIONES*/
  if(util.mensaje_confirmacion()){
    /*COMPROBACION tipo corriente*/
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
    /*COMPROBACION segun la potencia que nivel de carga tiene*/
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
    /*COMPROBACION no superar el limite de puntos de recarga de ese nivel*/
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
    /*GUARDAMOS datos si comprobaciones = true*/
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
/*---------------------Funcion que reserva un Punto de recarga-------------*/
/*
  TODO:
  Tiempo %i minutos RODAJAS %i X??? (ARREGLAR)
*/
void TipoOperacion::reservar_puntorecarga(){

  TipoFecha fechausuario;
  int identificadorElectrolinera,dia,mes,anno,hora,minuto,duracion,nivel,prSeleccionado;
  bool esCorrecto = true;

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
  if(util.mensaje_confirmacion()){
    prSeleccionado = electrolineras[identificadorElectrolinera].crear_reserva(duracion,nivel,fechausuario);
    if(prSeleccionado != -1){
      printf("\n\tReserva correcta.");
      printf("\n\t\tIdentificador: Punto de carga N%i-PuntoCarga-NumeroReserva-%i-%i",nivel,mes,anno);
      printf("\n\tFecha y hora: %i-%i-%i %i:%i",dia,mes,anno,hora,minuto);
      printf("\n\tTiempo %i minutos RODAJAS %i X???",util.aproximar_duracion(duracion,electrolineras[identificadorElectrolinera].puntosRecarga[prSeleccionado].rodajaMinima),electrolineras[identificadorElectrolinera].puntosRecarga[prSeleccionado].rodajaMinima);
    }else{
      printf("\nError PR= -1");
    };
  }
}

/*-----------Procedimento que lista las reserves segun nivel-----------*/
/*TODO:
          Ordenamos segun fecha y hora
*/

void TipoOperacion::listar_reservas(){

  int idElectrolinera,mesReserva,annoReserva; /*Datos introducidos por el usuario*/
  bool esPrimerResultado=true; /*Imprime enunciado de Nivel*/
  bool esVacio=true; /*Comprueba si no hay resultados */

  printf("\nListar reservas de electrolinera:");
  printf("\n\tIndetificador de la electrolinera?");
  scanf("%i",&idElectrolinera);
  fflush(stdin);
  printf("\n\tMes Reservas?");
  scanf("%i",&mesReserva);
  fflush(stdin);
  printf("\n\tAnno Reservas?");
  scanf("%i",&annoReserva);
  fflush(stdin);

  /*Por cada nivel recorro los puntos de recarga imprimiendo sus reservas*/
  for(int nivel=1;nivel<=3;nivel++){
    esPrimerResultado = true;
    for(int i=0;i<=MAX_NUMERO_PUNTOSRECARGA;i++){
      if(electrolineras[idElectrolinera].puntosRecarga[i].isActive && electrolineras[idElectrolinera].puntosRecarga[i].nivel == nivel){
        if(esPrimerResultado){
         if(esVacio){
          printf("\n La electrolinera %c %s %c tiene la siguientes reservas para el mes %i del anno %i",'"',electrolineras[idElectrolinera].nombre,'"',mesReserva,annoReserva);
         }
         esVacio=false;
         printf("\n\n\tNivel: %i\n",electrolineras[idElectrolinera].puntosRecarga[i].nivel);
         esPrimerResultado = false;
        }
        for(int j=0;j<=MAX_NUMERO_RESERVAS;j++){
          if(electrolineras[idElectrolinera].puntosRecarga[i].reservas[j].isActive){
            printf("\n\tPunto de recarga: %i Fecha: %i/%i/%i Hora: %i:%i Duracion: %i min.",electrolineras[idElectrolinera].puntosRecarga[i].id,electrolineras[idElectrolinera].puntosRecarga[i].reservas[j].fecha.dia,electrolineras[idElectrolinera].puntosRecarga[i].reservas[j].fecha.mes,electrolineras[idElectrolinera].puntosRecarga[i].reservas[j].fecha.anno,electrolineras[idElectrolinera].puntosRecarga[i].reservas[j].inicio.horas,electrolineras[idElectrolinera].puntosRecarga[i].reservas[j].inicio.minutos,electrolineras[idElectrolinera].puntosRecarga[i].reservas[j].duracion);
          }
        }
      }
    }
  }
  /*COMPROBACION no se han impreso resultados*/
  if(esVacio){
    printf("\nLa electrolinera %c%s%c no tiene reservas para el mes %i del año %i.",'"',electrolineras[idElectrolinera].nombre,'"',mesReserva,annoReserva);
  }
}
void TipoOperacion::calendario_reservas(){

  int mes,anio,idElectrolinera,idPR;
  VectorDias dias;
  printf("¿idElectrolinera? ");
  scanf("%i", &idElectrolinera);
  fflush(stdin);
  printf("¿idPR? ");
  scanf("%i", &idPR);
  fflush(stdin);
  printf("¿Mes (1..12)? ");
  scanf("%i", &mes);
  fflush(stdin);
  printf("¿Año (1601..3000)? ");
  scanf("%i", &anio);

  /*Iniciaizo el arrary*/
  for (int i= 0; i<=31; i++){
    dias[i]=0;
  }

  for(int i=0;i<MAX_NUMERO_RESERVAS;i++){
    if(electrolineras[idElectrolinera].puntosRecarga[idPR].reservas[i].isActive && electrolineras[idElectrolinera].puntosRecarga[idPR].reservas[i].fecha.mes == mes){
      dias[electrolineras[idElectrolinera].puntosRecarga[idPR].reservas[i].fecha.dia] = dias[electrolineras[idElectrolinera].puntosRecarga[idPR].reservas[i].fecha.dia] + electrolineras[idElectrolinera].puntosRecarga[idPR].reservas[i].duracion;
      printf("\nEl mes %i esta ocupado el dia: %i",mes,electrolineras[idElectrolinera].puntosRecarga[idPR].reservas[i].fecha.dia);
      printf("\nArray: %i tiene estas horas: %i",electrolineras[idElectrolinera].puntosRecarga[idPR].reservas[i].fecha.dia,dias[electrolineras[idElectrolinera].puntosRecarga[idPR].reservas[i].fecha.dia]);
      /*Numero de horas que es ocupado cada dia*/
    }
  }
  /*Obtenemos un array de porcentajes*/

  pintar_calendario(mes,anio,dias);
}
