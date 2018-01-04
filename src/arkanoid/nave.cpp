#include "nave.h"

nave::nave(float x, float y):obj_dib("nave")
{
         this->x=x;
         this->y=y;
}

void nave::dibujar() const {
         glPushMatrix();
         //Draw SpaceShip
         float xi,yi,xf,yf;
         this->getBoundaries(xi,yi,xf,yf);
         glColor3f(0+(x/800),0+(x/800),0.5);
                 glBegin( GL_QUADS );
                 glVertex3f(xi,yi,1.0);
                 glVertex3f(xi,yf,1.0);
                 glVertex3f(xf,yf,1.0);
                 glVertex3f(xf,yi,1.0);
                 glEnd();

         glPopMatrix(); //End drawing map


}


void nave::pressedKey(unsigned char c){

         int former_x = x;
         int former_y = y;
         switch(c){
         case 'a':
             if((x-x_size)>20)
                  x-=20;
                  break;
         case 'd':
              if((x+x_size)<780)
                  x+=20;
                  break;
         }

         //Check for collisions with walls

         //hacer algo
}
