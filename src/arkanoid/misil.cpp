#include "misil.h"
#include"obj_dib.h"
#include<iostream>

misil::misil(int x, int y,double vy):obj_dib("misil")
{
    this->x=x;
    this->y=y;
    this->vy=vy;
    this->x_size=10/2;
    this->y_size=25/2;
}
void misil::dibujar() const  {
    glPushMatrix();
    //Draw SpaceShip
    float xi,yi,xf,yf;

    getBoundaries(xi,yi,xf,yf);

    glColor3f(0,0.0,1);
    glBegin( GL_QUADS );
    glVertex3f(xi,yi,1);
    glVertex3f(xi,yf,1);
    glVertex3f(xf,yf,1);
    glVertex3f(xf,yi,1);
    glEnd();
    glPopMatrix(); //End drawing map
}
void misil::mover(obj_dib* objetochocado,int & bloques_restantes,int &vidas)
{
    string nombre=objetochocado->getName();
    if ( nombre == "pared" || nombre == "nave" || nombre == "ladrillo"){//el problema esta aqui
        int col_type;
        if(choque(objetochocado,col_type)!=false){
            switch (col_type){
            //right left collision
            case 2:
                break;

            case -2:
                break;

            case 1:
                break;

            case -1:     //en principio solo tiene que haber colision superior
                cout<<"choque misil"<<endl;

                break;
            }
            if(nombre=="ladrillo"&&col_type!=0)
            {
                 objetochocado->setX(-100);
                 this->setX(0);
                 this->setY(0);
                 this->setVy(0);
                 bloques_restantes-=1;
                 cout<<"he eliminado un ladrillo"<<endl;

            }}

        }
    y+=vy;
}

void misil::setVy(double vy){
this->vy=vy;
}//necesario para los misiles

