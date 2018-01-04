#ifndef PARED_H
#define PARED_H
#include"obj_dib.h"

class pared: public obj_dib
{
public:

    /**
    @brief Crea el pared a partir de los parametros que le pasas
    @param x Posicion horizontal del pared
    @param y Posicion vertical del pared
    @param ancho Ancho del pared
    @param altura Largo del pared
    */
    pared(float x,float y,float ancho,float altura);

    /**
    @brief Dibuja la pared con los vertices hallados a partir de los parámetros del ladrillo
    @note el color siempre es blanco
    */
    void dibujar() const;
};

#endif // PARED_H
