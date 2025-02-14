#include <bits/stdc++.h>
#include "commandManager.h"

using namespace std;

int dummyAyuda(vector<string> argv)
{

  if (argv.size() == 1)
  { // Ayuda general

    cout << "v0.0.1" << endl;
    cout << "Usa `ayuda` para ver esta lista" << endl;
    cout << "Usa `ayuda comando` para encontrar mas informacion sobre `comando`" << endl
         << endl;

    cout << "cargar_imagen [imagen.pgm]" << endl;
    cout << "cargar_volumen [nombre_base] [n_im]" << endl;
    cout << "info_imagen" << endl;
    cout << "info_volumen" << endl;
    cout << "proyeccion2D [direccion] [criterio] [imagen.pgm]" << endl;
    cout << "codificar_imagen [archivo.huf]" << endl;
    cout << "decodificar_imagen [archivo.huf] [imagen.pgm]" << endl;
    cout << "segmentar [imagen.pgm] [sx1 sy1 sl1 ... sxn syn sln]" << endl;
    cout << "salir" << endl;
  }
  else
  {
    string command = argv[1];

    if(command == "cargar_imagen") {

      cout << "USO: " << endl;
      cout << "     + Carga en memoria la imagen identificada por nombre_imagen.pgm. " << endl;
      cout << "     + Solo es posible cargar una única imagen por sesión." << endl;
      cout << "     + Si se ejecuta nuevamente con otro archivo, la nueva imagen reemplazará a la anterior." << endl << endl;
      cout << "SALIDA: " << endl;
      cout << "     Exito: La imagen nombre_imagen.pgm ha sido cargada." << endl;
      cout << "     Salida: La imagen nombre_imagen.pgm no ha podido ser cargada." << endl << endl;

    }else if(command == "cargar_volumen") {

      cout << "USO: " << endl;
      cout << "     + Carga en memoria una serie ordenada de imágenes con el nombre base nombre_base y un tamaño de n_im imágenes."; << endl;
      cout << "     + Las imágenes de la serie deben estar nombradas como nombre_baseXX.pgm, donde XX es un número de dos dígitos indicando la posición en la serie."; << endl;
      cout << "     + Solo es posible cargar un único volumen por sesión; si se ejecuta nuevamente con otro nombre, el volumen anterior será reemplazado."; << endl << endl;
      cout << "SALIDA: " << endl;
      cout << "     Exito: El volumen nombre_base ha sido cargado." << endl;
      cout << "     Error: El volumen nombre_base no ha podido ser cargado." << endl << endl;

    } else if(command == "info_imagen"){

      cout << "USO: info_imagen" << endl;
      cout << "     Muestra información básica de la imagen cargada en memoria." << endl << endl;
      cout << "SALIDA: " << endl;
      cout << "     Exito: Imagen cargada en memoria: nombre_imagen.pgm, ancho: W, alto: H." << endl;
      cout << "     Error: No hay imagen cargada en memoria." << endl << endl;
    } else if (command == "info_volumen") {

      cout << "USO: info_volumen" << endl;
      cout << "     Muestra información básica del volumen cargado en memoria." << endl << endl;
      cout << "SALIDA: " << endl;
      cout << "     Exito: Volumen cargado en memoria: nombre_base, tamaño: n_im, ancho: W, alto: H." << endl;
      cout << "     Error: No hay volumen cargado en memoria." << endl << endl;

    } else if (command == "proyeccion2D"){

      cout << "USO: proyeccion2D direccion criterio nombre_archivo.pgm" << endl;
      cout << "     Genera una imagen 2D a partir de la serie de imágenes cargada en memoria." << endl;
      cout << "     La dirección puede ser:" << endl;
      cout << "         x: columnas" << endl;
      cout << "         y: filas" << endl;
      cout << "         z: profundidad" << endl;
      cout << "     El criterio puede ser:" << endl;
      cout << "         minimo" << endl;
      cout << "         maximo" << endl;
      cout << "         promedio" << endl;
      cout << "         mediana" << endl;
      cout << "     La imagen generada se guarda en nombre_archivo.pgm." << endl;
      cout << "     Este comando solo funciona si hay un volumen cargado." << endl << endl;
  
      cout << "SALIDA: " << endl;
      cout << "     Exito: La proyección 2D del volumen en memoria ha sido generada y almacenada en el archivo nombre_archivo.pgm." << endl;
      cout << "     Error:" << endl;
      cout << "         El volumen no ha sido cargado en memoria." << endl;
      cout << "         La proyección 2D no pudo ser generada." << endl << endl;

    } else if (command == "codificar_imagen"){

      cout << "USO: codificar_imagen nombre_archivo.huf" << endl;
      cout << "     Aplica codificación de Huffman a la imagen cargada en memoria y almacena el resultado en nombre_archivo.huf." << endl << endl;
      cout << "SALIDA: " << endl;
      cout << "     Exito: La imagen en memoria ha sido codificada y almacenada en nombre_archivo.huf." << endl;
      cout << "     Error: No hay una imagen cargada en memoria." << endl << endl;
    } else if (command == "decodificar_archivo"){

      cout << "USO: decodificar_archivo nombre_archivo.huf nombre_imagen.pgm" << endl;
    cout << "     Decodifica el archivo nombre_archivo.huf y genera la imagen resultante en formato PGM como nombre_imagen.pgm." << endl << endl;

    cout << "SALIDA: " << endl;
    cout << "     Exito: El archivo nombre_archivo.huf ha sido decodificado exitosamente y almacenado en nombre_imagen.pgm." << endl;
    cout << "     Error: El archivo nombre_archivo.huf no pudo ser decodificado." << endl << endl;
    } else if(command == "segmentar"){
      cout << "USO: segmentar salida_imagen.pgm sx1 sy1 sl1 sx2 sy2 sl2 ..." << endl;
      cout << "     Realiza la segmentación de la imagen cargada en memoria usando un conjunto de semillas." << endl;
      cout << "     Se pueden ingresar hasta 5 semillas en el comando." << endl;
      cout << "     La imagen segmentada se guarda en salida_imagen.pgm." << endl << endl;
  
      cout << "SALIDA: " << endl;
      cout << "     Exito: La imagen en memoria fue segmentada correctamente y almacenada en salida_imagen.pgm." << endl;
      cout << "     Error:" << endl;
      cout << "         No hay imagen cargada en memoria." << endl;
      cout << "         La segmentación no pudo ser realizada." << endl << endl;

    }else {
      cout << "Este comando no existe" << endl;
    }
  }

  return 0;
}

Command CommandManager::ayudaCommand = *(
    new Command({"ayuda",
                 2,
                 [](vector<string> args)
                 {
                   return dummyAyuda(args);
                 }}));