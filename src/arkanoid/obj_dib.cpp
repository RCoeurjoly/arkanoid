#include "obj_dib.h"
#include<string>
#include"obj_dib.h"



void obj_dib::getBoundaries(float  &x_izq, float &y_ab, float &x_der, float &y_arr) const {
    x_izq = x - x_size;
    y_ab = y - y_size;
    x_der = x + x_size;
    y_arr = y + y_size;
}

bool obj_dib::choque(obj_dib *obj){
         int aux;
         return choque(obj,aux);
}
bool obj_dib::choque(obj_dib *obj, int &c){
         c=0;

         float xi,yi,xf,yf; getBoundaries(xi,yi,xf,yf);
         float xxi,yyi,xxf,yyf; obj->getBoundaries(xxi,yyi,xxf,yyf);

         //left collision
         if ( (xi < xxf) && (xf > xxf) && (yi < yyf) && (yf > yyi) ){
                  c=2; return true;
         }

         //right collision
         if ( (xf > xxi) && (xi < xxi) && (yi < yyf) && (yf > yyi) ){
                  c=-2; return true;
         }

         //down collision
         if ( (yi < yyf) && (yf > yyf) && (xi < xxf) && (xf > xxi) ){
                  c=1; return true;
         }

         //top collision
         if ( (yf > yyi) && (yi < yyi) && (xi < xxf) && (xf > xxi) ){
                  c=-1; return true;
         }

         //choques en las esquinas

         if ( (yf > yyi) && (yi < yyi) && (xi < xxf) && (xf > xxi) ){
                  c=-1; return true;
         }

         return false;
}
string obj_dib::getName()
{
    return this->name;
}

