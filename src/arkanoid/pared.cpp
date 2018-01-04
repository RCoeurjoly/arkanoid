#include "pared.h"
#include"obj_dib.h"


pared::pared(float x,float y,float ancho,float altura):obj_dib("pared")
{
    this->x=x;
    this->y=y;
    this->setWidth(ancho);
    this->setHeight(altura);
}
void pared::dibujar() const  {
    glPushMatrix();
    //Draw SpaceShip
    //  int xi=10,yi=100,xf=20,yf=200;
    float xi,yi,xf,yf;

    getBoundaries(xi,yi,xf,yf);

    glColor3f(1.0,1.0,1.0);
    glBegin( GL_QUADS );
    glVertex3f(xi,yi,1.0);
    glVertex3f(xi,yf,1.0);
    glVertex3f(xf,yf,1.0);
    glVertex3f(xf,yi,1.0);
    glEnd();
    glPopMatrix(); //End drawing map
}
