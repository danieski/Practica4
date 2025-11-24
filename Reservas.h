#pragma once
typedef struct Fecha{
  int dia;
  int mes;
  int anno;
};
typedef struct Hora{
  int horas;
  int minutos;
};
typedef struct Reserva{
  int nivel;
  Fecha fecha;
  Hora inicio;
  Hora final;
  int duracion;
};

void FuncionReservas();
