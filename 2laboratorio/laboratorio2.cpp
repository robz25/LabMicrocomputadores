// laboratorio2 - Robin Gonzalez
//g++ 9.3.0 corriendo en ubuntu 20.04
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int cantidad ,contador;
float punto;
string texto;

int main(){
  cout << "\nIngrese la cantidad de puntos: " << endl;
  cin >> cantidad;
  cout << "\nIngresado: " << cantidad << "\n" << endl;
  float x[cantidad],y[cantidad];

  //cout << "Cantidad ingresada: " << puntos << "\n"  ;
  while(cantidad > contador){
    cout << "\nDigite un par ordenado de la forma x,y: " << endl;
    getline(cin, texto);
    //cout << "\nIngresado: " << cantidad << "\n";
    cout << "\nIterando: " << contador << endl;

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
    contador++;

    }
}
