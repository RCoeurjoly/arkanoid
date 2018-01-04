#ifndef PELOTA_H
#define PELOTA_H
#include"obj_dib.h"

class pelota:public obj_dib
{
public:
    /**
    @brief Crea la pelota a partir de los parametros que le pasas
    @param x Posicion horizontal de la pelota
    @param y Posicion vertical de la pelota
    @param vx velocidad horizontal de la pelota
    @param vy velocidad vertical de la pelota
    @note no introduces el ancho ni la altura por que el radio de la pelota siempre es 5
    */
    pelota(float x,float y,double vx,double vy);

    /**
    @brief Dibuja la pelota en funcion del radio. creando vertices en su circunferencia mediante un for
    @note el color depende de la posicion vertical de la pelota
    */
    void dibujar() const;
    /**
    @brief mueve la pelota, detecta choques, quita vidas y destruye ladrillos si fuera necesario
    @param objetochocado objeto con el que comprueba si choca
    @param bloques_restantes resta bloques si hay choque
    @param vidas resta vida si choca con el fondo de la pantalla
    @note dentro llamas a las funciones getBoundaries(); y choque(). Es el mismo que nos paso Alberto Valero, salvo que varia el color en funcion de la posicion y
    */

    void mover(obj_dib* objetochocado,int & bloques_restantes, int & vidas);
    /**
    @brief sacas el valor de la velocidad en x. se utiliza para la pelota
    @return la vx
    */

    double getVx(){return vx;}
    /**
    @brief sacas el valor de la velocidad en y. se utiliza para la pelota
    @return la vy
    */
    double getVy(){return vy;}

private:
    /**
      @brief variables propias de la pelota
      @param vx componente horizontal de la velocidad
      @param vy componente vertical de la velocidad
      */
    double vx, vy;
    /**
      @brief variable propias de la pelota
      @param radius radio de la pelota
      */

    double radius;
};

#endif // PELOTA_H
