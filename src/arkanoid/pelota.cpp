#include "pelota.h"
#include<math.h>
#include<iostream>

using namespace std;

pelota::pelota(float x, float y, double vx, double vy):obj_dib("pelota")
{
    this->x = x;
    this->y = y;
    this->vx = vx;
    this->vy = vy;
    radius=5;
    this->x_size=(2*radius);
    this->y_size=(2*radius);
}
void pelota::dibujar() const {

    float angle;
    glPushMatrix();
    glColor3f((x/700)+0.0,1.0, (x/700)+0.0);
    glBegin(GL_POLYGON);
    for(unsigned int i = 0; i < 360; i+=5) {
        angle = M_PI*i/180;
        int xp = x + radius*cos(angle);
        int yp = y + radius*sin(angle);
        glVertex2i(xp, yp);
    }
    glEnd();
    glPopMatrix();
}
void pelota::mover(obj_dib* objetochocado,int & bloques_restantes,int &vidas){
    float x_obj=objetochocado->getX();
    float esta_X=(this->x-x_obj);


    string name = objetochocado->getName();
    if ( name == "pared" || name == "nave" || name == "ladrillo"){//el problema esta aqui
        int col_type;
        if(choque(objetochocado,col_type)!=false);
        switch (col_type){
        //right left collision
        case 2:

        case -2:

            vx=-vx;
            break;
            //top bottom collision
        case 1:

        case -1:
            vy=-vy;
            if(vx>0)
            {
                if((x-objetochocado->getX())<0)
                {
                    //frenar la pelota

                }
                else
                    ;//acelerar la pelota

            }
            else if(vx<0)
            {
                if((x-objetochocado->getX())<0)
                {

                    //acelerar la pelota

                }
                else


                    ; //frenar la pelota
            };
            break;
        }
        if(name=="ladrillo"&&col_type!=0)
        {
            objetochocado->setX(-100);
            bloques_restantes-=1;
            cout<<"Ha eliminado un ladrillo"<<endl;
            cout<<"Ladrillo restantes: "<<bloques_restantes<<endl;
        }
        if(name=="pared"&&col_type==1)
        {
            vidas-=1;
            cout<<"Le quedan "<<vidas<<" vidas"<<endl;
            this->x=400;
            this->y=80;
        }
    }
    y += vy/2;
    x +=vx/2;


}


