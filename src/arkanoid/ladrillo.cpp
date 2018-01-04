#include "ladrillo.h"
#include"obj_dib.h"

ladrillo::ladrillo(int x, int y,int ancho,int altura):obj_dib("ladrillo")
{
    this->x=x;
    this->y=y;
    this->setWidth(ancho);
    this->setHeight(altura);
}
void ladrillo::dibujar() const  {
    glPushMatrix();
    float xi,yi,xf,yf;

    getBoundaries(xi,yi,xf,yf);

    glColor3f((x/600)+0.9,(x/600)+0.0,0.0);
    glBegin( GL_QUADS );
    glVertex3f(xi,yi,1);
    glVertex3f(xi,yf,1);
    glVertex3f(xf,yf,1);
    glVertex3f(xf,yi,1);
    glEnd();
    glPopMatrix(); //End drawing map
}

