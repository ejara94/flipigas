#ifndef TRUK_H
#define TRUK_H


class Truk
{
public:
    Truk();
    Truk(char Tipo,int capacidad5,int capacidad15,int capacidad45);
    int CapacityGalons5;    //Capacidad camion
    int CapacityGalons15;
    int CapacityGalons45;
    char type;              //Tipo de camion
    int NumberOfRequests;   //Numero de solicitudes
    int NumberOfDeliveries; //Numero de entregas
    int TimeDelivery;       //Tiempo de entrega, que deberia ser timpo time
    int TimeofOccupation;   //Tiempo total de ocupacion

    //Logics

    void SubtractGalons(char T,int );   // Restar Solicitud
    void AddDelivery();      // Sumar N° entregas
    void SumTimeOccupation();// Tiempo de ocupacion

    //Getters

    int GetRequests();      // Obtener solicitudes
    int GetDeliveries();    //   "     N° entregas
    int GetGalons();        //   "     N° Galones
    int GetTimeDelivery();  //Tiempo de entrega
    int GetTimeOccupation();//Tiempo de ocupacion


signals:

public slots:
};

#endif // TRUK_H
