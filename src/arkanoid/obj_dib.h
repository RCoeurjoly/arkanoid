#ifndef OBJ_DIB_H
#define OBJ_DIB_H

#include <string>
#include <vector>
#include <GL/glut.h>

using namespace std;

class obj_dib
{
public:
    /**
    @brief inicias el objeto con el nombre asignado
    @param nombre el nombre en cuestion
    */

   obj_dib(string nombre)
    {
        this->name=nombre;
    }
   /**
   @brief funcion virtual pura. cada objeto se dibuja de su forma
   */

    virtual void dibujar() const=0;

   /**
   @brief calculas los limites izquierdo, derecho, superior, e inferior.
   @param x_izq limite izquierdo por referencia
   @param y_ab limite inferior por referencia
   @param x_der limite derecho por referencia
   @param y _arr limite superior por referencia

   */
    void getBoundaries(float  &x_izq, float &y_ab, float &x_der, float &y_arr) const;

    /**
    @brief funcion virtual de mover. se implementa para misil y pelota. el resto de casos no hace nada
    @param objetochocado no se utiliza
    @param bloques_restantes no se utiliza
    @param vidas no se utiliza
    */

    virtual void mover(obj_dib* objetochocado,int & bloques_restantes,int & vidas){}
    /**
    @brief funcion virtual de presionar botones. se implementa para nave. el resto de casos no hace nada
    @param c no se utiliza
    */

    virtual void pressedKey(unsigned char c){}
    ///Funciones set
    /**
    @brief funcion set de la x. se utiliza para cambiarla
    @param x el valor por el que se quiere cambiar
    */

    void setX(float x){this->x=x; }
    /**
    @brief funcion set de la y. se utiliza para cambiarla
    @param y el valor por el que se quiere cambiar
    */
    void setY(float y){this->y=y; }
    /**
    @brief funcion set de la x_size. se utiliza para cambiarla
    @param x_size el valor por el que se quiere cambiar
    */
    void setWidth(float w){x_size = w/2;}
    /**
    @brief funcion set de la y_size. se utiliza para cambiarla
    @param y_size el valor por el que se quiere cambiar
    */
    void setHeight(float h){y_size = h/2;}

    /**
    @brief sirve para cambiar la velocidad de la pelota o el misil fuera de sus clases
    @note se utiliza para el misil y la pelota
    */
    virtual void setVy(double vy){}

    //Funciones get

    /**
    @brief sacas el valor de la x
    @return la x
    */
    float getX(){return x;}
    /**
    @brief sacas el valor de la y
    @return la y
    */
    float getY(){return y;}
    /**
    @brief sacas el valor de la x_size (la mitad del ancho)
    @return la x_size
    */
    float getX_SIZE(){return x_size;}
    /**
    @brief sacas el valor de la y_size (la mitad de la altura)
    @return la y_size
    */
    float getY_SIZE(){return y_size;}

    /**
    @brief sacas el valor de la velocidad en x. se utiliza para la pelota
    @return la vx
    */
    virtual double getVx(){return 0;}
    /**
    @brief sacas el valor de la velocidad en . se utiliza para la pelota
    @return la vy
    */
    virtual double getVy(){return 0;}

    /**
    @brief ves si hay choque y devuelves el tipo de choque que se produce (inf, sup, izq, derecho) sobrecarga de funcion, porque tienen distintos parametros que les pasas
    @return 0 si no hay choque, 1 si lo hay
    */

    bool choque(obj_dib* obj, int & c);
    /**
    @brief ves si hay choque, llamas dentro a la anterior funcion y devuelves el tipo de choque que se produce (inf, sup, izq, derecho)
    @return 0 si no hay choque, 1 si lo hay
    */

    bool choque(obj_dib* obj);

    /**
    @brief consigues el nombre del objeto dibujable. muy util para comprobar que chocas con lo quieres. o que estas trabajando con el objeto requerido
    @return name
    */
    string getName();
protected:
    /**
    @brief nombre del objeto
    @param name nombre
    */
    string name;
    /**
    @brief coordenadas
    @param x horizontal
    @param y vertical

    */
    float x,y;
    /**
    @brief mitad del ancho y mitad de la altura
    @param x_size mitad ancho
    @param y_size mitad del alto
    */
    float x_size,y_size;
//  vector<obj_dib*>mundo;


};

#endif // OBJ_DIB_H
