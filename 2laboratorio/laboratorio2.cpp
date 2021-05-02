// laboratorio2 - Robin Gonzalez Ricz
//g++ 9.3.0 corriendo en ubuntu 20.04

#include <iostream> //leer datos de terminal
#include <string> //usar strings
#include <math.h> //usar operaciones matematicas como raiz y cuadrado
using namespace std; //abreviar escritura

//variables globales
int cantidad = 0; //cantidad de puntos
int contador = 0; //contador de puntos ingresados
string texto = ""; //texto leido de terminal
string separador = ","; //separador de numeros
bool puntoValido = false; //indica si el punto es valido
bool invalido = true; //indica so el paro es invalido
float dmin,dmax; //valores maximos y minimos

//funcion que calcula distancia entre puntos
float distanciaPuntos(float x[],float y[], int punto1, int punto2){
  float temp = pow(x[punto2]-x[punto1],2) + pow(y[punto2]-y[punto1],2);
  return sqrt(temp);
}


int main(){

    while (invalido){
      cout << "\nIngrese la cantidad de puntos: ";
      getline(cin, texto); //leemos string
      try{
        cantidad = stoi(texto); //convertimos a entero

      if(cantidad < 2){ //si es menor a 2 no es valido
        cout << "ERROR. La cantidad no puede ser menor a 2" << endl;
        invalido = true;
        }
      else{
          invalido = false; // indica que hay que terminar lectura
        }
      }
      catch ( ... ) {//si no se convierte a entero hay error
        cout << "ERROR. Intente nuevamente con una cantidad valida" << endl;
        texto = "";
      }
    }

  float x[cantidad],y[cantidad]; //arreglos para guardar los puntos

  while(cantidad > contador){// leer puntos mientras no se acaben
    cout << "\nDigite un par ordenado de la forma x,y: " << endl;


      getline(cin, texto); //leer string

      size_t posicion = 0;
      string token;

      puntoValido = false;//indicar punto no valido aun

      while ((posicion = texto.find(separador)) != string::npos && texto != "") {

        token = texto.substr(0, posicion);//obtener string antes del separador

        puntoValido = true;
        try {
          x[contador] = stof(token);//convertir primer numero a float

          texto.erase(0, posicion + separador.length());
          y[contador] = stof(texto);//convertir segundo numero a float

          contador+=1;
          //cout <<"Punto aceptado correctamente"<<  endl;
        }

        catch ( ... ) {//si hubo error al convertir
          if(contador > 0)--contador;//si no es primer numero decrementar
          cout << "ERROR: los valores ingresados no son numeros validos, reintentar" << endl;
          texto = "";
        }

      }
      //si hay algun otro error en el punto ingresado diferente de que no sean numeros
      if(!puntoValido)cout << "ERROR: el punto ingresado no es valido, reintentar" << endl;
    }

    cout << "\n==>>> Puntos recibidos: " << endl;
    for(int c = 0; c < cantidad;c++)//imprimir puntos ingresados
      cout << "Punto " << c << ": " << x[c] <<  "," << y[c] << endl;
    cout << endl;

    dmin = distanciaPuntos( x, y, 0,1 );//obtener primer valor como referencia
    dmax = dmin;
    int cantidadDistancias = cantidad*(cantidad-1)/2;//distancias a calcular
    int iteradorTabla = 0;

    float tablaDistanciasPuntos[3][cantidadDistancias];//tabla para guardar distancias
    //en primer fila, puntos en segunda y tercera
    float dist;

    for(int cantPuntos = 0; cantPuntos < cantidad; cantPuntos++){//calcular distancias

      for(int otrosPuntos = cantPuntos;otrosPuntos<cantidad-1;otrosPuntos++){

          dist = distanciaPuntos( x, y, cantPuntos,otrosPuntos+1);//calcualr distancais
          //le pasamos los arreglos y las entradas a usar (numero de puntos)

          //si se desea ver la distancia de cada par de puntos
          //cout << "distancia : " << dist<< endl;
          //cout << cantPuntos << " con: " << otrosPuntos+1<< endl;

          //actualizar valores maximos y minimos
          if (dist <= dmin){
            dmin = dist;
          }
          if (dist >= dmax){
            dmax = dist;
          }

          ///llenar tabla con distancias y puntos respectivos
          tablaDistanciasPuntos[0][iteradorTabla] = dist;
          tablaDistanciasPuntos[1][iteradorTabla] = cantPuntos;
          tablaDistanciasPuntos[2][iteradorTabla] = otrosPuntos+1;

          iteradorTabla++;
        }
    }

    if(cantidad == 2){//si solo hay dos puntos
      cout << "Distancia entre los dos puntos: " << dist<< endl;

    }
    else{//si hay mas de dos puntos ingresados

      //recorrer la tabla y al encontrar la dist max, imprimir los puntos
    cout << "\ndistancia Maxima: " << dmax<< " Se da entre los puntos:"<<  endl;

    for(int i = 0; i < cantidadDistancias; i++){
      if(tablaDistanciasPuntos[0][i] == dmax){
         cout << tablaDistanciasPuntos[1][i]  << " y " << tablaDistanciasPuntos[2][i]  << endl;
        }
      }

      //recorrer la tabla y al encontrar la dist min, imprimir los puntos
    cout << "\ndistancia Minima: " << dmin<< " Se da entre los puntos:"<<  endl;

    for(int i = 0; i < cantidadDistancias; i++){
      if(tablaDistanciasPuntos[0][i] == dmin){
         cout << tablaDistanciasPuntos[1][i]  << " y " << tablaDistanciasPuntos[2][i]  << endl;
        }
      }

    }


//si se desea ver la tabla
/*
cout << "\ntabla\n" << endl;
for(int f = 0;f <3;f++){
    for(int c = 0;c <cantidadDistancias;c++){

        cout << tablaDistanciasPuntos[f][c] << "\t";

    }
    cout << endl;
    }
    */

}
