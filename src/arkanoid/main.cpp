#include<iostream>
#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<vector>
#include<fstream>
#include<string>

#include"obj_dib.h"
#include"pared.h"
#include"ladrillo.h"
#include"pelota.h"
#include"nave.h"
#include"misil.h"


using namespace std;

void borrado();
void dibujar_todo();
void inicializar_Mundo();
int menu_inicial();
int menu_dificultad();
void OnTimer(int value);
void guardarFichero();
void lecturaFichero();
void OnKeyboardDown(unsigned char key, int x, int y);
void raton(int x, int y);

bool check_rep(int n,int num[],int size)
{
    for(int i=0;i<size;i++)
        if(n==num[i])
            return true;
    return false;
}

/// Variables globales del programa. solo tenemos acceso al vector mundo en el main. las otras variables gestionan menús, vidas, bloques, y bonus.

/// @param mundo vector en el que se guardan todos los objetos dibujables.
vector<obj_dib*> mundo;

/// @param bloques_restantes son 8 por cada nivel (2 niveles)
int bloques_restantes=10;

/// @param vidas veces+1 que puedes chocar con la pared inferior y seguir en el juego
int vidas=3;
int nivel=1;
/// @param dificultad lo dificil que es pasarse alguna pantalla
int dificultad;
/// @param opcion la introduce el usuario. jugar, cargar o salir.
int opcion;
/// @param centinela QUE HAY ALGUN BONUS DISPONIBLE (una vez que utilizas uno, no puedes utilizar mas)
int centinela=1;
/// @param cen_long tiempo de barra mas larga
int cen_long=0;
/// @param numero de misiles iniciales
int contador_misiles=0;
   int truco=0;

int main(int argcp, char *argv[]){
//    for(int j=0;j<200;j++)
//    {
//    float i=rand()/RAND_MAX;

//}
/// Cargamos el menu inicial
    opcion=menu_inicial();

    if(opcion==49)
    {
        /// cargamos el menu de dificultad si no cargamos partida ni salimos
        dificultad=menu_dificultad();
        if(dificultad==51||dificultad==52)
        {
            vidas=6;
        }
    }

    /// abriendo fichero

    if(opcion==50)
    {
        lecturaFichero();
    }

    if(opcion!=51)
    {   /// Creacion de la pantalla GLUT. inspirado por el programa que nos pasó usted (Alberto Valero)
        atexit(borrado);
        glutInit(&argcp, argv);
        /// tamaño de la ventana glut
        glutInitWindowSize(800,600);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        /// nombre de la pantalla glut
        glutCreateWindow("Arkanoid");
        /// dibujamos todo con glut
        glutDisplayFunc(dibujar_todo);
        /// esperamos que tecleen algo
        glutKeyboardFunc(OnKeyboardDown);
        glutMotionFunc(raton);
        if(opcion==49){

            /// llenamos el mundo de los objetos dibujables

        inicializar_Mundo();}
/// La funcion mas importante del programa. Mueve todo los objetos

        glutTimerFunc(10,OnTimer,0);

        glutMainLoop();

        /// Nuestra marca registrada
        char copyright=169;
        cout<<"Roland y Daniel "<<copyright<<endl;


        return 0;
    }
}
/**
  @brief borramos pantalla y recorremos el mundo llamando a la funcion dibujar

  */


void dibujar_todo(void)
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);

    /// Borrado de la pantalla
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluOrtho2D(0,800,0,600);

    for(unsigned int i=0;i<mundo.size();i++)/// no cambiar por nada del mundo de mundo.size() a sizeof(mundo)
    {
        mundo[i]->dibujar();
    }

    glutSwapBuffers();

}

/**
  @brief recorremos mundo y borramos los vectores. muy importante la gestion de memoria. si no lo hiciesemos, nuestra memoria se colapsaria tarde o temprano

  */
void borrado()
{
    for(unsigned int i=0;i<mundo.size();i++)
    {
        delete mundo[i];
    }
}

/**
  @brief reservamos memoria dinamicamente y llamamos a los contructores de los distintos objetos que queremos crear
  */
void inicializar_Mundo()
{

/// Paredes

    obj_dib* wall_left = new pared(10,300,20,600);
    mundo.push_back(wall_left);

    obj_dib* wall_right = new pared(790,300,20,600);
    mundo.push_back(wall_right);

    obj_dib* wall_top = new pared(400,590,800,20);
    mundo.push_back(wall_top);

    obj_dib* wall_bottom = new pared(400,10,800,20);
    mundo.push_back(wall_bottom);

/// LADRILLOS

//    obj_dib* ladrillo_1 = new ladrillo(640,440,80,20);
//    mundo.push_back(ladrillo_1);

//    obj_dib* ladrillo_2 = new ladrillo(560,420,80,20);
//    mundo.push_back(ladrillo_2);

//    obj_dib* ladrillo_3 = new ladrillo(480,400,80,20);
//    mundo.push_back(ladrillo_3);

//    obj_dib* ladrillo_4 = new ladrillo(400,380,80,20);
//    mundo.push_back(ladrillo_4);

//    obj_dib* ladrillo_5 = new ladrillo(320,360,80,20);
//    mundo.push_back(ladrillo_5);

//    obj_dib* ladrillo_6 = new ladrillo(240,340,80,20);
//    mundo.push_back(ladrillo_6);

//    obj_dib* ladrillo_7 = new ladrillo(160,320,80,20);
//    mundo.push_back(ladrillo_7);

//    obj_dib* ladrillo_8 = new ladrillo(80,300,80,20);
//    mundo.push_back(ladrillo_8);

////////////////////////////////////////////////////////////
///////////////INTENTO DE MATRIZ DE LADRILLOS///////////////
////////////////////////////////////////////////////////////


//    for()

        int size=10,n;    srand(time(NULL));
        int m_horiz[size],m_ver[size];
        //inicializar array
        for(int i=0;i<size;i++)
       {
           do
              n=1+rand()%size;
           while(check_rep(n,m_horiz,size));
           m_horiz[i]=n;
       }
        for(int i=0;i<size;i++)
        {
            do
               n=1+rand()%size;
            while(check_rep(n,m_ver,size));
            m_ver[i]=n;
        }
        for(int i=0,j=0;i<size&&j<size;i++,j++)
        {
            obj_dib* ladrillo_9 = new ladrillo(m_horiz[i]*80,m_ver[j]*20+300,80,20);
            mundo.push_back(ladrillo_9);
        }

    /// Pelotas

    double initvx = ((double(rand())/RAND_MAX*1))/2;
    double initvy = (double(rand())/RAND_MAX*1)/2;

    if(dificultad==50||dificultad==52)/// SE AUMENTA LA VELOCIDAD DE LA PELOTA EN DIFICULTADES 2 Y 4
    {
        initvx+=0.5;
        initvy+=0.5;
    }

    obj_dib* pelota_1 = new pelota(400,80,initvx,initvy);
    mundo.push_back(pelota_1);

    if(dificultad==51||dificultad==52)/// SE AÑADE OTRA PELOTA SI LA DIFICULTAD ES 3 o 4
    {

        double initvx = ((double(rand())/RAND_MAX*1))/2;/// CUIDADO ESTAS VARIABLES SON SOLO DEL IF
        double initvy = (double(rand())/RAND_MAX*1)/2;

        if(dificultad==52)/// SE AUMENTA LA VELOCIDAD DE LA PELOTA EN DIFICULTADES 2 Y 4
        {
            initvx+=0.5;
            initvy+=0.5;
        }

        obj_dib* pelota_1 = new pelota(400,80,initvx,initvy);
        mundo.push_back(pelota_1);
    }

    /// Misiles

    obj_dib* misil_1 = new misil(0,0,0);
    mundo.push_back(misil_1);


    /// la nave
    obj_dib* nave_1 = new nave(400,50);
    nave_1->setHeight(25);
    nave_1->setWidth(100);
    mundo.push_back(nave_1);


}
/**
  @brief recorremos mundo y llamamos a la funcion mover
  @note tambien incluimos subir de nivel y salir del programa cuando no queden vidas o bloques

  */

void OnTimer(int value)
{
    glutTimerFunc(10,OnTimer,0);

    if(cen_long!=0)
    {
    for(unsigned int i=0;i<mundo.size();i++)
    {
        string nombre=mundo[i]->getName();
        int ancho=mundo[i]->getX_SIZE();
        if(nombre=="nave"&&centinela==0&&ancho==100&&cen_long<500&&cen_long>0)
        {
            cout<<"tiempo restante: "<<500-cen_long<<endl;
            cen_long++;
        }
        else if(nombre=="nave"&&centinela==0&&ancho==100&&cen_long==500)
            mundo[i]->setWidth(100);

    }}

    if((vidas<=0))
    {
        exit(0);
    }
    if(bloques_restantes==0)
        nivel=3;
    /// con el centinela evitas que puedas conseguir mas de un bonus en una partida
    for(unsigned int i=0;i<mundo.size();i++)
    {
        for(unsigned int j=0;j<mundo.size();j++)
        {
            string nombre=mundo[i]->getName();
            mundo[i]->mover(mundo[j],bloques_restantes,vidas);
            if(nombre=="ladrillo")
            {
                int x,y;
                x=mundo[i]->getX();
                y=mundo[i]->getY();


                /// implementacion de bonus

                /// VIDA EXTRA

                if(x==-100&&y==440&&centinela==1)
                {
                    vidas++;
                    /// con el centinela evitas que puedas conseguir mas de un bonus en una partida
                    centinela=0;
                    cout<<"vida extra"<<endl<<"nº vidas: "<<vidas<<endl;
                }

                /// BARRA MAS LARGA

                if(x==-100&&y==380&&centinela==1)
                {
                    string nombre_1=mundo[j]->getName();
                    if(nombre_1=="nave")
                    {
                        mundo[j]->setWidth(200);
                        centinela=0;
                        cen_long++;/// centinela pa q no se vuelva a meter
                    }
                }

                /// MISIL

                if(x==-100&&y==400&&centinela==1)
                 {
                     contador_misiles=3;
                     cout<<"Tiene misilies disponibles"<<endl;
                 centinela=0;/// centinela pa q no se vuelva a meter
                 }
            }

        }

    }

    // INTENTANDO REPOSICIONAR LOS LADRILLOS PARA TENER NIVELES INFINITOS

//    if(nivel==2)
//    {
//        int j=1;
//        for(unsigned int i=0;i<mundo.size();i++)
//        {   string nombre;
//            nombre=mundo[i]->getName();
//            if(nombre=="ladrillo")
//            {

//                int size=8,n;    srand(time(NULL));
//                int m_horiz[size],m_ver[size];
//                //inicializar array
//                int j,k;
//                for(j=0;j<size;j++)
//                {
//                    do
//                        n=1+rand()%size;
//                    while(check_rep(n,m_horiz,size));
//                    m_horiz[j]=n;
//                }
//                for(k=0;k<size;k++)
//                {
//                    do
//                        n=1+rand()%size;
//                    while(check_rep(n,m_ver,size));
//                    m_ver[k]=n;
//                }
//                mundo[i]->setX(m_horiz[j]*80);
//                mundo[i]->setY(m_ver[k]*20+300);
//                j++;
//            }
//            if(nombre=="pelota")
//            {
//                mundo[i]->setX(400);
//                mundo[i]->setY(80);
//            }
//            if(nombre=="nave")
//            {
//                mundo[i]->setX(400);
//                mundo[i]->setY(50);
//            }
//        }
//        nivel++;
//    }
    if(nivel==2)
        {
            int j=1;
            for(unsigned int i=0;i<mundo.size();i++)
            {   string nombre;
                nombre=mundo[i]->getName();
                if(nombre=="ladrillo")
                {
                    mundo[i]->setX(80*j);
                    mundo[i]->setY(300);
                    j++;
                }
                if(nombre=="pelota")
                {
                    mundo[i]->setX(400);
                    mundo[i]->setY(80);
                }
                if(nombre=="nave")
                {
                    mundo[i]->setX(400);
                    mundo[i]->setY(50);
                }
            }
        }

    /// hacemos doble for para comparar coordenadas de cada obj_dib con todos los demas
    glutPostRedisplay();
}

/**
  @brief lo principal es recorrer mundo y llamar a la funcion pressedKey, la cual solo esta implementada para la nave
  @note Tambien guardamos las posiciones y velocidades de los objetos si se presiona la tecla 'g'
  @note Si tienes el bonus de los misiles activados y se presiona la barra espaciadora, se disparan los misiles. Solo hay un misil. Por lo tanto si se presiona la barra cuando un misil esta en el aire, este será reposicionado en el centro de la barra y empezara a subir
  */
void OnKeyboardDown(unsigned char key, int x, int y)
{

    if(key=='k')
    {
        for(unsigned int i=0;i<mundo.size();i++)/// Recorremos mundo para encontrar la x de la nave
        {
            /// recorres el mundo para encontrar la nave y su x

            string nombre=mundo[i]->getName();

            if(nombre=="nave"&&truco==0)
            {
                mundo[i]->setWidth(400);
                truco=1;
                break;
            }
            if(nombre=="nave"&&truco==1)
            {
                mundo[i]->setWidth(100);
                truco=0;
                break;
            }
        }

    }




    if(key==32&&centinela==0&&contador_misiles<=3&&contador_misiles>0)
    {   /// Variable bloqueadora. Se activa para que solo dispares un misil cada vez que pulses la barra
        int bloq=1;
        cout<<"Has pulsado la barra espaciadora"<<endl;
        int x_nave;

        for(unsigned int i=0;i<mundo.size();i++)/// Recorremos mundo para encontrar la x de la nave
        {
            /// recorres el mundo para encontrar la nave y su x

            string nombre=mundo[i]->getName();

            if(nombre=="nave")
            {
                x_nave=mundo[i]->getX();
            }
        }


        for(unsigned int i=0;i<mundo.size();i++)
        {   string nombre=mundo[i]->getName();

            /// Recorres mundo para encontrar el misil y cambiarle sus parametros para que se dispare

            if(nombre=="misil"&&bloq==1)
            {
                 mundo[i]->setX(x_nave);
                mundo[i]->setY(50);
                mundo[i]->setVy(0.5);
                bloq=0;
            }
        }
       /// queda un misil menos
        contador_misiles--;
    }
    if(key=='g'){
        guardarFichero();
         atexit(borrado);

    }


    for (unsigned int i=0;i<mundo.size();i++){
        mundo[i]->pressedKey(key);
    }

    glutPostRedisplay();
}
void raton(int x, int y){
        if(x<=730&&x>=70)
        {
            for(unsigned int i=0;i<mundo.size();i++)/// Recorremos mundo para encontrar la x de la nave
            {
                /// recorres el mundo para encontrar la nave y su x

                string nombre=mundo[i]->getName();

                if(nombre=="nave")
                {
                    mundo[i]->setX(x);
//                    mundo[i]->setY(-y+600);

                }
            }
        }

}


/// Menu inicial. Devuelve la opcion siempre que se haya introducido una opcion valida. Para que acepte letras, hemos mirado en el codigo ASCII que numero decimal corresponde al 1,2,3 y 4. Son 49...52
int menu_inicial()
{
    char i;
    do{
        cout<<"Introduzca la opción que quieres realizar"<<endl;
        cout<<"1:Nueva partida"<<endl<<"2:Cargar partida"<<endl<<"3:Salir del programa"<<endl;
        cin>>i;
        switch (i){
        case 49:
            break;
        case 50:
            break;
        case 51:
                break;}

    }while  (i!=49&&i!=50&&i!=51);/// Corresponden al 1, 2 y 3 en ASCII
    return i;
}

/// Menu de la dificultad. Recibe un entero y lo devuelve siempre que este entre 1 y 4. Para que acepte letras, hemos mirado en el codigo ASCII que numero decimal corresponde al 1,2,3 y 4. Son 49...52
/**
  @brief menu de la dificultad


  */

int menu_dificultad()
{
char i; /// para que no se bloquee, la dificultad sera un char
    do{
        cout<<"Introduzca la dificultad:"<<endl;
        cout<<"• Nivel entero: 1 pelota lenta."<<endl;
        cout<<"• Nivel caracter: 1 pelota rápida."<<endl;
        cout<<"• Nivel vector: 2 pelotas lentas."<<endl;
        cout<<"• Nivel puntero: 2 pelotas rápidas."<<endl;
        cout<<"Recuerde que en cualquier momento puede pulsar la tecla 'g' (guardar) y así salvaguardar la partida"<<endl;
        cin>>i;}
        while (i!=49&&i!=50&&i!=51&i!=52); /// Corresponden al 1, 2,3 y 4 en ASCII

    return i;
}
/**
  @brief recorremos el fichero y seleccionamos el objeto, sus parametros y las consntantes que nos interesan para cargar exactamente la misma situacion en la que se guardó

  */

void lecturaFichero()
{
    /// @param fin variable ifstream (stream de entrada desde fichero) lee datos desde el fichero. La llamamos fin por analogia con el cin. Abrimos fichero
    ifstream fin("juego_arkanoid.txt");

    /// si no existe un fichero, sale del programa
    if(!fin){
        cout<<"No existe ningun fichero que contenga datos del juego"<<endl;
        exit(0);

    }
    /// @param nombre a b c d variables en las que se guarda lo que se lee
    string nombre;
    double a,b,c,d;
    /// @param n_paredes n_bloques n_pelotas sirven para la creacion de varios objetos dibujables del mismo tipo
    while(!fin.eof())/// recorres el fichero hasta que termine y vas machacando los datos y metiendolos en mundo
    {
        /// guardas en las variables creadas lo que lees del fichero
    fin>>nombre>>a>>b>>c>>d;

    /// luego esas variables las metes a su vez en variables del programa en funcion del nombre que tengan antes
    if(nombre=="vidas")
    {
        vidas=a;
    }
    if(nombre=="bloquesrestantes")
    {
        bloques_restantes=a;
    }
    if(nombre=="auxiliares")
    {
        centinela=a;
        cen_long=b;
        contador_misiles=c;

    }

    /// luego esas variables las metes a su vez en parametros de los objetos dibujables en funcion del nombre que tengan antes


    if(nombre=="pared")  /// LEYENDO las paredes
    {
            obj_dib* wall = new pared(a,b,c,d);
            mundo.push_back(wall);
    }
    if(nombre=="ladrillo")  /// LEYENDO los ladrillos
    {
            obj_dib* ladrillo_1 = new ladrillo(a,b,c,d);
            mundo.push_back(ladrillo_1);
    }

    /// LEYENDO LA PELOTA

    if(nombre=="pelota")
    {
            obj_dib* pelota_1 = new pelota(a,b,c,d);
            mundo.push_back(pelota_1);
    }

    /// LEYENDO LA NAVE

    if(nombre=="nave")
    {
        obj_dib* nave_1 = new nave(a,b);
        nave_1->setWidth(c);
        nave_1->setHeight(d);

        mundo.push_back(nave_1);
    }
    if(nombre=="misil")
    {
        obj_dib* misil_1 = new misil(a,b,c);
        mundo.push_back(misil_1);
    }

    }

}

/**
  @brief las variables globales (las vidas, bloques restantes, bonus) y los parametros importantes de los objetos dibujables los guarda en el fichero

  */
void guardarFichero()
{
    /// se crea el fichero de salida. si ya exitia, se machacan sus datos. por analogia con el cout de iostream, se llama fout al fichero
    ofstream fout("juego_arkanoid.txt");

    /// guardando fichero


    for(unsigned int i=0;i<mundo.size();i++)
    {
        string nombre=mundo[i]->getName();
        double x=mundo[i]->getX();
        double y=mundo[i]->getY();
        double c;
        double d;
        if(nombre=="pelota")
        {
            double x_size=mundo[i]->getVx();
            double y_size=mundo[i]->getVy();
            c=x_size;
            d=y_size;
        }
        else{
        if(nombre=="misil")
        {
            double y_size=mundo[i]->getVy();
            c=y_size;
            d=0;
        }

        else{
        double x_size=mundo[i]->getX_SIZE()*2;
        double y_size=mundo[i]->getY_SIZE()*2;
        c=x_size;
        d=y_size;}}

        fout<< nombre<<" ";
        fout<< x << " ";
        fout<< y <<" ";
        fout<< c <<" ";
        fout<< d <<endl;
    }

    /// guardado de vidas y de numero de bloques MUY IMPORTANTE

    fout<< "vidas"<<" "<<vidas<<" "<<0<<" "<<0<<" "<<0<<endl;
    fout<<"bloquesrestantes"<<" "<<bloques_restantes<<" "<<0<<" "<<0<<" "<<0<<endl;
    fout<< "auxiliares"<<" "<<centinela<<" "<<cen_long<<" "<<contador_misiles<<" "<<0<<endl;

/// imprescindible cerrar el fout
    fout.close();
    exit(0);
}

