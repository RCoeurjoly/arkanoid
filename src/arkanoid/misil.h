#ifndef MISIL_H
#define MISIL_H
#include"obj_dib.h"

class misil:public obj_dib
{
public:
    /**
    @brief Crea el misil a partir de los parametros que le pasas
    @note no necesitamos el ancho y el largo porque siempre es el mismo por defecto. Solo tiene velocidad vertical el misil
    @param x Posicion horizontal del misil
    @param y Posicion vertical del misil
    @param vy velocidad vertical del misil
    */
misil(int x, int y,double vy);

/**
@brief Dibuja el misil con los vertices hallados a partir de los parámetros del ladrillo
@note el color es siempre azul (0,0,1) segun el rgb
*/

void dibujar() const;

/**
@brief mueve el misil
@note es similar al mover de la pelota solo que solo incluye el choque inferior
@param objetochocado comprueba si se choca con ese objeto
@param bloques_restantes Resta un bloque si choca contra él
@param vidas nunca resta una vida. esta pensado para cuando la pelota choca contra la pared inferior
*/

void mover(obj_dib* objetochocado,int & bloques_restantes,int &vidas);

/**
@brief consigues la velocidad del misil
@return vy para comprobar que tiene velocidad
*/

double getVy(){return vy;}

/**
@brief modificas la velocidad del misil
@note se utiliza para parar el misil cuando choca contra algo
*/

virtual void setVy(double vy);

private:

/**
@brief velocidad del misil. no tiene vx
@param vy velocidad propia del misil
*/

double vy;

};

#endif // MISIL_H

