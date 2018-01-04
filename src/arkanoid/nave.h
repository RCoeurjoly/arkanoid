#ifndef NAVE_H
#define NAVE_H

#include "nave.h"
#include "obj_dib.h"

class nave : public obj_dib
{
public:

    /**
    @brief creas la nave
    @note el ancho el siempre el mismo y el largo solo se modifica con el bonus de alargar nave
    */
         nave(float x,float y);

         /**
         @brief destructor de la nave
         @note no lo utilizamos en ningun momento, porque no es posible conocer la posicion en el mundo en la que esta tal y como hemos hecho el codigo
         */
         virtual ~nave(){}

         /**
         @brief mueves la nave cuando pulsas (a) o (d)
         @note se mueve siempre entre unos limites
         */

         void pressedKey(unsigned char c);

         /**
         @brief dibujas la nave en funcion de sus parametros
         */

         void dibujar() const ;

};

#endif // SPACESHIP_H
