#include "TADOperaciones.h"
#include <stdio.h>
#include <string.h>
/*---------------Introduce unos datos inciales en el programa*/
void TipoOperacion::CargarDatos(){

  TipoFecha fechaDia1;
  TipoFecha fechaDia2;
  TipoFecha fechaDia3;
  TipoFecha fechaDia4;
  TipoHora hora1;
  TipoHora hora2;
  TipoHora hora3;

  TipoHora hora1f;
  TipoHora hora2f;
  TipoHora hora3f;

  hora1.minutos = 10;
  hora1.horas = 10;
  hora2.minutos = 30;
  hora2.horas = 12;
  hora3.minutos = 50;
  hora3.horas = 23;


  hora1f.minutos = 20;
  hora1f.horas = 10;
  hora2f.minutos = 40;
  hora2f.horas = 12;
  hora3f.minutos = 00;
  hora3f.horas = 00;


  fechaDia1.dia=1;
  fechaDia1.mes=1;
  fechaDia1.anno=1900;

  fechaDia2.dia=2;
  fechaDia2.mes=1;
  fechaDia2.anno=1900;

  fechaDia3.dia=4;
  fechaDia3.mes=2;
  fechaDia3.anno=1900;

  fechaDia4.dia=1;
  fechaDia4.mes=1;
  fechaDia4.anno=2000;

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
  electrolineras[0].id = 1;
  electrolineras[0].cargaRapida = 7;
  electrolineras[0].cargaMedia = 7;
  electrolineras[0].cargaLenta = 6;
  strcpy(electrolineras[0].nombre,"ES Nueva Carga");

  for(int i= 0;i<MAX_NUMERO_PUNTOSRECARGA;i++){
    electrolineras[0].puntosRecarga[i].isActive=true;
    electrolineras[0].puntosRecarga[i].id=i+1;
    electrolineras[0].puntosRecarga[i].rodajaMinima=10;
  }

  for(int i=0;i<electrolineras[0].cargaLenta;i++){
    electrolineras[0].puntosRecarga[i].nivel=1;
    electrolineras[0].puntosRecarga[i].potencia=3;
  }
  for(int i=electrolineras[0].cargaLenta;i<(electrolineras[0].cargaLenta+electrolineras[0].cargaMedia);i++){
    electrolineras[0].puntosRecarga[i].nivel=2;
    electrolineras[0].puntosRecarga[i].potencia=24;
  }
  for(int i=electrolineras[0].cargaMedia;i<(electrolineras[0].cargaLenta+electrolineras[0].cargaMedia+electrolineras[0].cargaRapida);i++){
    electrolineras[0].puntosRecarga[i].nivel=3;
    electrolineras[0].puntosRecarga[i].potencia=300;
  }

  electrolineras[0].puntosRecarga[0].reservas[0].isActive = true;
  electrolineras[0].puntosRecarga[0].reservas[0].duracion = 30;
  electrolineras[0].puntosRecarga[0].reservas[0].fechaInicio = fechaDia1;
  electrolineras[0].puntosRecarga[0].reservas[0].fechaFinal = fechaDia1;
  electrolineras[0].puntosRecarga[0].reservas[0].horaInicio = hora1;
  electrolineras[0].puntosRecarga[0].reservas[0].horaFinal = hora1f;
  electrolineras[0].puntosRecarga[0].reservas[0].id = 1;

  electrolineras[0].puntosRecarga[0].reservas[1].isActive = true;
  electrolineras[0].puntosRecarga[0].reservas[1].duracion = 60;
  electrolineras[0].puntosRecarga[0].reservas[1].fechaInicio = fechaDia1;
  electrolineras[0].puntosRecarga[0].reservas[1].fechaFinal = fechaDia1;
  electrolineras[0].puntosRecarga[0].reservas[1].horaInicio = hora2;
  electrolineras[0].puntosRecarga[0].reservas[1].horaFinal = hora2f;
  electrolineras[0].puntosRecarga[0].reservas[1].id = 2;

  electrolineras[0].puntosRecarga[0].reservas[2].isActive = true;
  electrolineras[0].puntosRecarga[0].reservas[2].duracion = 200;
  electrolineras[0].puntosRecarga[0].reservas[2].fechaInicio = fechaDia2;
  electrolineras[0].puntosRecarga[0].reservas[2].fechaFinal = fechaDia2;
  electrolineras[0].puntosRecarga[0].reservas[2].horaInicio = hora3;
  electrolineras[0].puntosRecarga[0].reservas[2].horaFinal = hora3f;
  electrolineras[0].puntosRecarga[0].reservas[2].id = 3;

  electrolineras[0].puntosRecarga[6].reservas[0].isActive = true;
  electrolineras[0].puntosRecarga[6].reservas[0].duracion = 30;
  electrolineras[0].puntosRecarga[6].reservas[0].fechaInicio = fechaDia2;
  electrolineras[0].puntosRecarga[6].reservas[0].fechaFinal = fechaDia2;
  electrolineras[0].puntosRecarga[6].reservas[0].horaInicio = hora1;
  electrolineras[0].puntosRecarga[6].reservas[0].horaFinal = hora1f;
  electrolineras[0].puntosRecarga[6].reservas[0].id = 4;

  electrolineras[0].puntosRecarga[13].reservas[0].isActive = true;
  electrolineras[0].puntosRecarga[13].reservas[0].duracion = 30;
  electrolineras[0].puntosRecarga[13].reservas[0].fechaInicio = fechaDia3;
  electrolineras[0].puntosRecarga[13].reservas[0].fechaFinal = fechaDia3;
  electrolineras[0].puntosRecarga[13].reservas[0].horaInicio = hora1;
  electrolineras[0].puntosRecarga[13].reservas[0].horaFinal = hora1f;
  electrolineras[0].puntosRecarga[13].reservas[0].id = 5;

  electrolineras[0].puntosRecarga[14].reservas[0].isActive = true;
  electrolineras[0].puntosRecarga[14].reservas[0].duracion = 30;
  electrolineras[0].puntosRecarga[14].reservas[0].fechaInicio = fechaDia4;
  electrolineras[0].puntosRecarga[14].reservas[0].fechaFinal = fechaDia4;
  electrolineras[0].puntosRecarga[14].reservas[0].horaInicio = hora1;
  electrolineras[0].puntosRecarga[14].reservas[0].horaFinal = hora1f;
  electrolineras[0].puntosRecarga[14].reservas[0].id = 5;
  electrolineras[0].ultimoIdReserva=7;

  electrolineras[0].CrearReserva(10,hora1,1,fechaDia1);
}
/*-----Procedimiento que edita una electrolinera existente o no------*/
void TipoOperacion::EditarElectrolinera(){

    int identificador,cargaRapida,cargaMedia,cargaLenta;
    float latitud,longitud;
    char confirmar;
    bool comprobaciones=true;
    bool darBaja=false;
    string nombre,tipo;

    printf("Editar electrolinera:\n\n");
    printf("\n\tIdentificador(numero entre 1 y 10)?");
    scanf("%i",&identificador);
    fflush(stdin);
    identificador--;
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
   if(identificador>MAX_NUMERO_ELECTROLINERAS || identificador<=0 ||cargaRapida+cargaMedia+cargaLenta>MAX_NUMERO_PUNTOSRECARGA){
     comprobaciones=false;
   }
   if(cargaRapida+cargaMedia+cargaLenta==0){
     darBaja=true;
   }
   /*GUARDAMOS*/
    if(util.MensajeConfirmacion()&&comprobaciones && !darBaja){
      electrolineras[identificador].id = identificador +1;
      electrolineras[identificador].isActive = true;
      strcpy(electrolineras[identificador].nombre,nombre);
      electrolineras[identificador].cargaRapida = cargaRapida;
      electrolineras[identificador].cargaMedia = cargaMedia;
      electrolineras[identificador].cargaLenta = cargaLenta;
      electrolineras[identificador].tipo = util.DevolverTipoElectrolinera(tipo);
      electrolineras[identificador].latitud = latitud;
      electrolineras[identificador].longitud = longitud;
      electrolineras[identificador].ultimoIdReserva = 0;
    }else if(darBaja){
      electrolineras[identificador].isActive = false;
      printf("\nElectrolinera ID = %i dada de baja", identificador+1);
    }

}
/*-----Procedimiento que edita un punto de carga existente o no------*/
void TipoOperacion::EditarPuntoRecarga(){

  /*VARIABLES*/
  int identificadorElectrolinera,identificadorPuntoCarga,potencia,rodajaMinima;
  string tipoCorriente;
  bool esTipoCorrienteValida = false;
  bool esLimiteNivelValida = false;
  int limitePuntoSegunTipo;

  /*DATOS DEL USUARIO*/
  printf("Editar punto de carga:\n");
  printf("\tIdentificador electrolinera (numero entre 1 y 10)?");
  scanf("%i",&identificadorElectrolinera);
  fflush(stdin);
  identificadorElectrolinera--;
  printf("\n\tIdentificador punto de carga(numero entre 1 y 20)?");
  scanf("%i",&identificadorPuntoCarga);
  identificadorPuntoCarga--;
  fflush(stdin);
  printf("\n\tTipo de corriente(DC/AC)?");
  scanf("%s",&tipoCorriente);
  fflush(stdin);
  printf("\n\tPotencia (kW)?");
  scanf("%i",&potencia);
  fflush(stdin);
  printf("\n\tRodaja minima de recarga (minutos)?");
  scanf("%i",&rodajaMinima);
  fflush(stdin);
  printf("\nSon correctos los nuevos datos(S/N)?");

  /*COMPROBACIONES*/
  if(util.MensajeConfirmacion()){
    /*COMPROBACION tipo corriente*/
    if(util.DevolverTipoCorriente(tipoCorriente)==DC){
      if(util.DevolverNivelPuntoRecarga(potencia) == 3){
        esTipoCorrienteValida = true;
      }else{
        printf("\nerror: potencia con tipocorriente DC no puede si Nivel carga no es 3");
        esTipoCorrienteValida = false;
      }
    }else if(util.DevolverTipoCorriente(tipoCorriente)==AC){
      if(util.DevolverNivelPuntoRecarga(potencia) < 3){
        esTipoCorrienteValida = true;
      }else{
        printf("\nerror: potencia con tipocorriente AC no puede si Nivel carga no es 2 o menor");
        esTipoCorrienteValida = false;
      }
    };
    /*COMPROBACION segun la potencia que nivel de carga tiene*/
    switch(util.DevolverNivelPuntoRecarga(potencia)){
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
      if(electrolineras[identificadorElectrolinera].puntosRecarga[i].nivel == util.DevolverNivelPuntoRecarga(potencia)){
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
      electrolineras[identificadorElectrolinera].puntosRecarga[identificadorPuntoCarga].id = identificadorPuntoCarga +1;
      electrolineras[identificadorElectrolinera].puntosRecarga[identificadorPuntoCarga].nivel = util.DevolverNivelPuntoRecarga(potencia);
      electrolineras[identificadorElectrolinera].puntosRecarga[identificadorPuntoCarga].tipoCorriente = util.DevolverTipoCorriente(tipoCorriente);
      electrolineras[identificadorElectrolinera].puntosRecarga[identificadorPuntoCarga].potencia = potencia;
      electrolineras[identificadorElectrolinera].puntosRecarga[identificadorPuntoCarga].rodajaMinima = rodajaMinima;
      electrolineras[identificadorElectrolinera].puntosRecarga[identificadorPuntoCarga].isActive = true;
      printf("\n\t Configuracion correcta: Electrolinera: %i. Punto de carga: %i. Nivel%i\n",identificadorElectrolinera+1,identificadorPuntoCarga+1,electrolineras[identificadorElectrolinera].puntosRecarga[identificadorPuntoCarga].nivel);
    };
  };
}
/*---------------------Funcion que reserva un Punto de recarga-------------*/
void TipoOperacion::ReservarPuntoRecarga(){

  TipoFecha fechaUsuario;
  TipoHora horaUsuario;
  int identificadorElectrolinera,duracion,nivel,prSeleccionado;
  bool esCorrecto = true;

  printf("Reservar punto de recarga:\n");
  printf("\tIdentificador de electrolinera?");
  scanf("%i",&identificadorElectrolinera);
  identificadorElectrolinera--;
  fflush(stdin);
  printf("\tTipo de punto de recarga (Nivel1/Nivel2/Nivel3)? N");
  scanf("%i",&nivel);
  fflush(stdin);
  printf("\tDatos reserva: Dia?");
  scanf("%i",&fechaUsuario.dia);
  fflush(stdin);
  printf("\tDatos reserva: Mes?");
  scanf("%i",&fechaUsuario.mes);
  fflush(stdin);
  printf("\tDatos reserva: Anno?");
  scanf("%i",&fechaUsuario.anno);
  fflush(stdin);
  printf("\tDatos reserva: Hora?");
  scanf("%i",&horaUsuario.horas);
  fflush(stdin);
  printf("\tDatos reserva: Minuto?");
  scanf("%i",&horaUsuario.minutos);
  fflush(stdin);
  printf("\tDatos reserva: Duracion?");
  scanf("%i",&duracion);
  fflush(stdin);



  printf("\n\t\t Datos de la Reserva:\n");
  printf("\n\tE/S: %s (Id=%i)",electrolineras[identificadorElectrolinera].nombre,electrolineras[identificadorElectrolinera].id);
  printf("\n\tFecha reserva: %02d-%02d-%04d",fechaUsuario.dia,fechaUsuario.mes,fechaUsuario.anno);
  printf("\n\tHora reserva: %02d:%02d",horaUsuario.horas,horaUsuario.minutos);
  printf("\n\tDuracion: %02d minutos",duracion);
  printf("\nSon correctos los datos de la reserva (S/N)?");

  if(util.MensajeConfirmacion()){
    /*Se intenta crear una reserva devolviendonos el Puntos de Recarga selelccionado*/
    prSeleccionado = electrolineras[identificadorElectrolinera].CrearReserva(duracion,horaUsuario,nivel,fechaUsuario);
    if(prSeleccionado != -1){
      printf("\n\tReserva correcta.");
      /*electrolineras[identificadorElectrolinera].ultimoIdReserva++;*/
      printf("\n\t\tIdentificador: Punto de carga N%i-%i-%04d-%02d-%02d",nivel,prSeleccionado+1,electrolineras[identificadorElectrolinera].ultimoIdReserva,fechaUsuario.mes,fechaUsuario.anno);
      printf("\n\t\tFecha y hora: %02d-%02d-%02d %02d:%02d",fechaUsuario.dia,fechaUsuario.mes,fechaUsuario.anno,horaUsuario.horas,horaUsuario.minutos);
      printf("\n\t\tTiempo %02d minutos RODAJAS %i ",util.AproximarDuracion(duracion,electrolineras[identificadorElectrolinera].puntosRecarga[prSeleccionado].rodajaMinima),electrolineras[identificadorElectrolinera].puntosRecarga[prSeleccionado].rodajaMinima);
    }else{
      printf("\n %02d/%02d/%02d %02d:%02d - La reserva no puede realizarse",fechaUsuario.dia,fechaUsuario.mes,fechaUsuario.anno,horaUsuario.horas,horaUsuario.minutos);
    };
  }
}

/*-----------Procedimento que lista las reserves segun nivel-----------*/
/*TODO:
          Ordenamos segun fecha y hora
*/

void TipoOperacion::ListarReservas(){

  int idElectrolinera,mesReserva,annoReserva; /*Datos introducidos por el usuario*/
  bool esPrimerResultado=true; /*Imprime enunciado de Nivel*/
  bool esVacio=true; /*Comprueba si no hay resultados */

  printf("\nListar reservas de electrolinera:");
  printf("\n\tIndetificador de la electrolinera?");
  scanf("%i",&idElectrolinera);
  idElectrolinera--;
  fflush(stdin);
  printf("\n\tMes Reservas?");
  scanf("%i",&mesReserva);
  fflush(stdin);
  printf("\n\tAnno Reservas?");
  scanf("%i",&annoReserva);
  fflush(stdin);

  /*Asumir que existe alguna reserva*/

  /*Por cada nivel recorro los puntos de recarga imprimiendo sus reservas*/

  for(int nivel=1;nivel<=3;nivel++){
    esPrimerResultado = true;
    for(int i=0;i<MAX_NUMERO_PUNTOSRECARGA;i++){
      if(electrolineras[idElectrolinera].puntosRecarga[i].isActive && electrolineras[idElectrolinera].puntosRecarga[i].nivel == nivel){
        if(esPrimerResultado){
         if(esVacio){
          printf("\n La electrolinera %c %s %c tiene la siguientes reservas para el mes %02d del anno %04d",'"',electrolineras[idElectrolinera].nombre,'"',mesReserva,annoReserva);
         }
         esVacio=false;
         printf("\n\n\tNivel: %i\n",electrolineras[idElectrolinera].puntosRecarga[i].nivel);
         esPrimerResultado = false;
        }
        for(int j=0;j<MAX_NUMERO_RESERVAS;j++){
          if(electrolineras[idElectrolinera].puntosRecarga[i].reservas[j].isActive && electrolineras[idElectrolinera].puntosRecarga[i].reservas[j].fechaInicio.mes == mesReserva && electrolineras[idElectrolinera].puntosRecarga[i].reservas[j].fechaInicio.anno == annoReserva){
            printf("\n\tPunto de recarga %i-%04d-%i-%i Fecha: %02d/%02d/%04d Hora: %02d:%02d Duracion: %02d min.",electrolineras[idElectrolinera].puntosRecarga[i].id,electrolineras[idElectrolinera].puntosRecarga[i].reservas[j].id,electrolineras[idElectrolinera].puntosRecarga[i].reservas[j].fechaInicio.mes,electrolineras[idElectrolinera].puntosRecarga[i].reservas[j].fechaInicio.anno,electrolineras[idElectrolinera].puntosRecarga[i].reservas[j].fechaInicio.dia,electrolineras[idElectrolinera].puntosRecarga[i].reservas[j].fechaInicio.mes,electrolineras[idElectrolinera].puntosRecarga[i].reservas[j].fechaInicio.anno,electrolineras[idElectrolinera].puntosRecarga[i].reservas[j].horaInicio.horas,electrolineras[idElectrolinera].puntosRecarga[i].reservas[j].horaInicio.minutos,electrolineras[idElectrolinera].puntosRecarga[i].reservas[j].duracion);
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
/*------Despliega un calendario con el nivel de demanda de cada dia del mes----*/
void TipoOperacion::CalendarioReservas(){

  int mes,anio,idElectrolinera,idPR;
  int maxCapacidad = 0;
  VectorDias dias;
  do{
  printf("\nReservas Mensuales Punto de Recarga: ");
  printf("\nIdentificador de la electrolinera? ");
  scanf("%i", &idElectrolinera);
  idElectrolinera--;
  fflush(stdin);
  printf("Numero de punto de recarga? ");
  scanf("%i", &idPR);
  idPR--;
  fflush(stdin);
  printf("Seleccion Mes? ");
  scanf("%i", &mes);
  fflush(stdin);
  printf("Seleccion anio? ");
  scanf("%i", &anio);

  /*Iniciaizo el arrary*/
  for (int i= 0; i<=31; i++){
    dias[i]=0;
  }
  /*Recorro el mes de reservas en el PuntodeRecarga seleccionado*/
  for(int i=0;i<MAX_NUMERO_RESERVAS;i++){
    if(electrolineras[idElectrolinera].puntosRecarga[idPR].reservas[i].isActive && electrolineras[idElectrolinera].puntosRecarga[idPR].reservas[i].fechaInicio.mes == mes){
      /*Cada espacio del array corresponde a un dia del mes que va a guardar la duracion de cada dia reservado en cada PR*/
      dias[electrolineras[idElectrolinera].puntosRecarga[idPR].reservas[i].fechaInicio.dia] = dias[electrolineras[idElectrolinera].puntosRecarga[idPR].reservas[i].fechaInicio.dia] + electrolineras[idElectrolinera].puntosRecarga[idPR].reservas[i].duracion;
      /*Para averguar el dia de max capacidad se guarda el valor del array con mas horas guardadas*/
      if(maxCapacidad < dias[electrolineras[idElectrolinera].puntosRecarga[idPR].reservas[i].fechaInicio.dia]){
        maxCapacidad = electrolineras[idElectrolinera].puntosRecarga[idPR].reservas[i].fechaInicio.dia;
      }
      /*printf("\nEl mes %i esta ocupado el dia: %i",mes,electrolineras[idElectrolinera].puntosRecarga[idPR].reservas[i].fecha.dia);*/
      /*printf("\nArray: %i tiene estas horas: %i",electrolineras[idElectrolinera].puntosRecarga[idPR].reservas[i].fecha.dia,dias[electrolineras[idElectrolinera].puntosRecarga[idPR].reservas[i].fecha.dia]);*/
      /*Numero de horas que es ocupado cada dia*/
    }
  }
  /*Obtenemos un array de porcentajes*/
  printf("\n\t\t Ocupacion Punto de Recarga %i", electrolineras[idElectrolinera].puntosRecarga[idPR].id);
  printf("\n\t\t Electrolinera: %s\n", electrolineras[idElectrolinera].nombre);
  /*Pasamos el array para poder interpretarlo en el calendario*/
  PintarCalendario(mes,anio,dias);
  printf("\nPunto de Carga %i - N%i",electrolineras[idElectrolinera].puntosRecarga[idPR].id,electrolineras[idElectrolinera].puntosRecarga[idPR].nivel);
  printf("\nDia de maxima ocupacion %i/%i/%i (%i%c)",maxCapacidad,mes,anio,util.DevolverPorcentajeOcupacion(dias[maxCapacidad]),'%');
  printf("\n\nMostrar otro mes (S/N)?");
  }while(util.MensajeConfirmacion());
}
