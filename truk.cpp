#include "truk.h"


Truk::Truk()
{

}

void Truk::AddDelivery(){
    if(TimeDelivery == 0)
    NumberOfRequests++;
}

void Truk::SubtractGalons(int CantidadSolicitada,int PesoGalon){
    if(PesoGalon == 5){
        CapacityGalons5=CapacityGalons5-CantidadSolicitada;     //Ojo, el error que hay aqui, no ve el caso
    }                                                           //de tener capacidad negativa
    else if(PesoGalon == 15){                                   //Tampoco Comtempla el caso, de que ingrese un peso
        CapacityGalons15=CapacityGalons15-CantidadSolicitada;   // que no corresponda (5,15,45)
    }
    else if (PesoGalon == 45){
        CapacityGalons45=CapacityGalons45-CantidadSolicitada;
    }
}

void Truk::SetTimeDelivery(int time){
    AuxTimeDelivery=time;
    TimeDelivery=time;
}

void Truk::SumTimeOccupation(){
    TimeofOccupation=TimeofOccupation+AuxTimeDelivery;
}

int Truk::GetDeliveries(){
    return NumberOfDeliveries;
}

int Truk::GetGalons(int tipo){
    if (tipo == 5){
        return(CapacityGalons5);
    }
    else if(tipo ==15){
        return(CapacityGalons15);
    }
    else if(tipo == 45){
        return(CapacityGalons45);
    }
    else
        return (CapacityGalons5+CapacityGalons15+CapacityGalons45);
}

int Truk::GetRequests(){
    return(NumberOfRequests);
}

int Truk::GetTimeDelivery(){
    return (TimeDelivery);
}

int Truk::GetTimeOccupation(){
    return (TimeofOccupation);
}
