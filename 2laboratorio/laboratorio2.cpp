// laboratorio2 - Robin Gonzalez
//g++ 9.3.0 corriendo en ubuntu 20.04
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <list>
//#include <sstream>
#include <math.h>
using namespace std;

int cantidad = 0;
int contador = 0;
//float punto;
string texto = "";
string separador = ",";
bool puntoValido = false;
bool invalido = true;
float dmin,dmax;
list<int> puntosmin;
list<int> puntosmax;

float distanciaPuntos(float x[],float y[], int punto1, int punto2){
  float temp = pow(x[punto2]-x[punto1],2) + pow(y[punto2]-y[punto1],2);
  return sqrt(temp);
}

int main(){

    while (invalido){
      cout << "\nIngrese la cantidad de puntos: ";
      getline(cin, texto);
      try{
        cantidad = stoi(texto);
      //cin >> cantidad;
      if(cantidad < 2){
        cout << "ERROR. La cantidad no puede ser menor a 2" << endl;
        invalido = true;
        }
      else{
          invalido = false;
        }
      }
      catch ( ... ) {

        cout << "ERROR. Intente nuevamente con una cantidad valida" << endl;
        texto = "";
      }

      //cout << "\nIntente nuevamente con una cantidad valida " << endl;
      //cout << "\nIngrese la cantidad de puntos: ";
      //cin >> cantidad;
      }

  //cout << "\nIngresado: " << cantidad << "\n" << endl;
  float x[cantidad],y[cantidad];

  //cout << "Cantidad ingresada: " << puntos << "\n"  ;
  //getline(cin, texto);

  while(cantidad > contador){
    cout << "\nDigite un par ordenado de la forma x,y: " << endl;

  //  while (texto.length() < 2){
      getline(cin, texto);
//    }
    //cout << "texto: " << texto << endl;
    //if(texto 1=){
      size_t posicion = 0;
      string token;
      int XoY = 0;
      puntoValido = false;

      while ((posicion = texto.find(separador)) != string::npos && texto != "") {

        token = texto.substr(0, posicion);
        //cout << token <<  endl;

        puntoValido = true;
        try {
          x[contador] = stof(token);
      /*    if(XoY = 0){
            cout << "Asigno X: "  << endl;
            X[contador] = stof(token);
            //XoY = 1;
          }
          if(XoY = 1){
            cout << "Asigno Y: " << endl;
            y[contador] = stof(token);
            //XoY = 0;
          }
          XoY++;*/
          texto.erase(0, posicion + separador.length());
          y[contador] = stof(texto);

          contador+=1;
          //cout <<"Punto aceptado correctamente"<<  endl;
        }

        catch ( ... ) {
          if(contador > 0)--contador;
          cout << "ERROR: los valores ingresados no son numeros validos, reintentar" << endl;
          texto = "";
        }

        //  cout << token << endl;

      }
      if(!puntoValido)cout << "ERROR: el punto ingresado no es valido, reintentar" << endl;

  //  cout << texto << endl;

    //cout << "\nIngresado: " << cantidad << "\n";
/*    cout << "\nIterando: " << contador << endl;

    //string entrada  = texto;
//    string bla(texto);
    stringstream s_stream(texto);
    vector<string> tokens;//???
    while(s_stream.good()){

      string substr;
      getline(s_stream, substr, ',');
      tokens.push_back(substr);
}
      for(int i = 0; i < tokens.size(); i++){

        stringstream numeros(tokens.at(i));
        if ( i == 0)numeros >> x[contador];
        if ( i == 1)numeros >> y[contador];
        if( 0 == x[contador] || y[contador] == 0){
          cout << "Error, el par ordenado no contiene numeros validos" << endl;
          --contador;
        }

        cout << "\n  Tokens " << i << ": " << tokens.at(i) << endl;
}
cout << "\n " << x[contador] << endl;
cout << "\n " << y[contador] << endl;
*/

    /*for (string numero; getline(split, numero, ','); tokens.push_back(numero)){
    cout << "resultante" << numero ;

   // now use `tokens`
}*/


/*
    cout << "String: " << texto;

    cin >> punto;
  //  cout << punto << "\n";
    //getline(cin,punto);
    x[contador] = int(punto);
    punto = punto - int(punto);
    while(punto- int(punto) != 0){
      punto *= 10;
    }
    y[contador] = int(punto);

    cout << x[contador] << "\n";
    cout << y[contador] << "\n";
    */

      //  }
      }
    //x[0] = 999;
    //y[0] = 666;
    cout << "\n Puntos recibidos: " << endl;
    //cout << "___________________" << endl;
    for(int c = 0; c < cantidad;c++)
    cout << c << ": " << x[c] <<  "," << y[c] << endl;
    cout << endl;
    dmin = distanciaPuntos( x, y, 0,1 );
    dmax = dmin;
    int cantidadDistancias = cantidad*(cantidad-1)/2;
    int iteradorTabla = 0;

    float tablaDistanciasPuntos[3][cantidadDistancias-1];
    float dist;

    for(int cantPuntos = 0; cantPuntos < cantidad; cantPuntos++){

      for(int otrosPuntos = cantPuntos;otrosPuntos<cantidad-1;otrosPuntos++){

          dist = distanciaPuntos( x, y, cantPuntos,otrosPuntos+1);
          cout << "distancia : " << dist<< endl;

          cout << cantPuntos << " con: " << otrosPuntos+1<< endl;

          if (dist <= dmin){
            dmin = dist;
            //puntosmin
          }

          if (dist >= dmax){
            dmax = dist;
            //puntosmax
          }

          tablaDistanciasPuntos[0][iteradorTabla] = dist;
          tablaDistanciasPuntos[1][iteradorTabla] = cantPuntos;
          tablaDistanciasPuntos[2][iteradorTabla] = otrosPuntos+1;

          iteradorTabla++;
        }
    }

    if(cantidad == 2){
      cout << "Distancia entre los dos puntos: " << dist<< endl;

    }
    else{

    cout << "\ndistancia Maxima: " << dmax<< " Se da entre los puntos:"<<  endl;

    for(int i = 0; i < cantidadDistancias; i++){
      if(tablaDistanciasPuntos[0][i] == dmax){
         cout << tablaDistanciasPuntos[1][i]  << " y " << tablaDistanciasPuntos[2][i]  << endl;
        }
      }

    cout << "\ndistancia Minima: " << dmin<< " Se da entre los puntos:"<<  endl;

    for(int i = 0; i < cantidadDistancias; i++){
      if(tablaDistanciasPuntos[0][i] == dmin){
         cout << tablaDistanciasPuntos[1][i]  << " y " << tablaDistanciasPuntos[2][i]  << endl;
        }
      }

    }

cout << "\ntabla\n" << endl;

for(int f = 0;f <3;f++){
    for(int c = 0;c <cantidadDistancias;c++){

        cout << tablaDistanciasPuntos[f][c] << "\t";

    }
    cout << endl;
    }

}
