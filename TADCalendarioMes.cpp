#include <stdio.h>
#include "TADCalendarioMes.h"
typedef enum TipoMes {
  Enero, Febrero, Marzo, Abril, Mayo, Junio,
  Julio, Agosto, Septiembre, Octubre, Noviembre, Diciembre
};

void EscribirMes(int mes){
  switch(mes){
    case 1:  printf("ENERO     "); break;
    case 2:  printf("FEBRERO   "); break;
    case 3:  printf("MARZO     "); break;
    case 4:  printf("ABRIL     "); break;
    case 5:  printf("MAYO      "); break;
    case 6:  printf("JUNIO     "); break;
    case 7:  printf("JULIO     "); break;
    case 8:  printf("AGOSTO    "); break;
    case 9:  printf("SEPTIEMBRE"); break;
    case 10: printf("OCTUBRE   "); break;
    case 11: printf("NOVIEMBRE "); break;
    case 12: printf("DICIEMBRE "); break;
  }
}

int zeller(int dia, int mes, int anio) {
    int h, q, m, k, j;
    q = dia;
    if (mes == 1) { mes = 13; anio--; }
    else if (mes == 2) { mes = 14; anio--; }
    m = mes;
    k = anio % 100;
    j = anio / 100;
    h = (q + (13 * (m + 1)) / 5 + k + (k / 4) + (j / 4) + 5 * j) % 7;
    return h;
}

int PuntosPorDibujarDelante(int zeller){
  // Ajuste para lunes=0, ..., domingo=6
  switch(zeller){
    case 0:
      return 5;
      break; // sábado
    case 1:
      return 6;
      break;// domingo
    case 2:
      return 0;
      break; // lunes
    case 3:
      return 1;
      break; // martes
    case 4:
      return 2;
      break; // miércoles
    case 5:
      return 3;
      break; // jueves
    case 6:
      return 4;
      break; // viernes
  }
  return 0;
}

int UltimoDiaDelMes(int mes,bool esBisiesto){
  switch(mes){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    return 31;
    break;
    case 4:
    case 6:
    case 9:
    case 11:
    return 30;
    break;
    default:
      if(esBisiesto){
        return 29;
      }else{
      return 28;
    }
  }
}


bool EsBisiesto(int anno) {
  return (anno % 4 == 0 && (anno % 100 != 0 || anno % 400 == 0));
}

void palabra(int horas){

  if(horas>0 && horas<=6){
    printf("Ba");
  }else if(horas>=6 && horas<=12){
    printf("Me");
  }else if(horas>=12){
    printf("Al");
  }else{
    printf("00");
  }

}

int pintar_calendario(int mes,int anio,const int dias[]) {
    int ultimoDiaDelMes,primerDia;
    int index;
    int dia = 1;
    bool filaVacia = true;
    bool hayDiasEnFila = false;
    bool esBisiesto;
   /* printf("Desde TADCalendario accedo a : %s", electrolineeras[0].nombre);*/
/*
    for (int i=0;i<30;i++){
      printf("\nEl dia: %i tiene %i horas",i,dias[i]);
    }*/
    if(anio<1601 || anio >3000){
      printf("Error fecha superada");
    }
    esBisiesto = EsBisiesto(anio);
    ultimoDiaDelMes = UltimoDiaDelMes(mes, esBisiesto);
    primerDia = PuntosPorDibujarDelante(zeller(1, mes, anio));

    printf("\n");
    EscribirMes(mes);
    printf("%17i", anio);
    printf("\n===========================\n");
    printf("LU  MA  MI  JU  VI | SA  DO\n");
    printf("===========================\n");
for (int fila = 0; fila < 6; fila++) {
    for (int col = 0; col < 7; col++) {
        index = fila * 7 + col;

        if (index < primerDia) {
            printf("%2s", ".");
        } else if (dia <= ultimoDiaDelMes) {
            /*printf("%2d", dia);*/
            palabra(dias[dia]);
            dia++;
        } else {
            printf("%2s", ".");
        }

        if (col == 4){
            printf(" | ");
        }
        else if (col < 6)
        {
            printf("  ");
        }
    }

    printf("\n");

    // Si ya imprimimos todos los días del mes, salimos del bucle
    if (dia > ultimoDiaDelMes){
        return 0;
    }
}


return 0;




}
