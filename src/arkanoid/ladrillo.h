#ifndef LADRILLO_H
#define LADRILLO_H
#include"obj_dib.h"

class ladrillo:public obj_dib
{
public:

    /**
    @brief Crea el ladrillo a partir de los parametros que le pasas
    @param x Posicion horizontal del ladrillo
    @param y Posicion vertical del ladrillo
    @param ancho Ancho del ladrillo
    @param largo Largo del ladrillo
    */

    ladrillo(int x,int y,int ancho,int altura);

    /**
    @brief Dibuja el ladrillo con los vertices hallados a partir de los parámetros del ladrillo
    @note el color depende de la coordenada horizontal (x)
    */

    void dibujar() const;
};

#endif // LADRILLO_H
