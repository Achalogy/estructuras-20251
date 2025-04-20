/**
 * @file ayudaCommand.cxx
 * @brief Implementación del sistema de ayuda para los comandos disponibles.
 *
 * Este archivo contiene la implementación de la función `handlerAyuda`,
 * que proporciona información sobre los comandos del programa.
 */

#include <bits/stdc++.h>
#include "../core/TADCommandManager.h"
#include "../core/TADImagen.h"
#include "../colors/colors.h"

using namespace std;

/**
 * @brief Muestra información sobre los comandos disponibles en el programa.
 *
 * Dependiendo de los argumentos, esta función imprime una lista general de comandos
 * o una descripción detallada de un comando específico.
 *
 * @param argv Vector de strings que contiene los argumentos del usuario.
 *        - `argv[0]`: Nombre del programa (ignorado).
 *        - `argv[1]`: (Opcional) Nombre del comando para obtener más detalles.
 *
 * @return 0 si la ejecución fue exitosa.
 */

int handlerAyuda(vector<string> argv, Memoria &memoria)
{

     if (argv.size() == 1)
     { // Ayuda general

          cout << __COLOR_BLUE << "v2.5.2 release candidate" << __COLOR_RESET << endl;
          cout << "Usa `" << __COLOR_GREEN << "ayuda" << __COLOR_RESET << "` para ver esta lista" << endl;
          cout << "Usa `" << __COLOR_GREEN << "ayuda" << __COLOR_RESET << "` <comando>` para encontrar mas informacion sobre el comando <comando>" << endl
               << endl;

          cout << __COLOR_GREEN << "cargar_imagen" << __COLOR_RESET << " [nombre_imagen.pgm]" << endl;
          cout << __COLOR_GREEN << "cargar_volumen" << __COLOR_RESET << " [nombre_base] [n_im]" << endl;
          cout << __COLOR_GREEN << "info_imagen" << __COLOR_RESET << endl;
          cout << __COLOR_GREEN << "info_volumen" << __COLOR_RESET << endl;
          cout << __COLOR_GREEN << "proyeccion2D" << __COLOR_RESET << " [direccion] [criterio] [nombre_archivo.pgm]" << endl;
          cout << __COLOR_GREEN << "codificar_imagen" << __COLOR_RESET << " [nombre_archivo.huf]" << endl;
          cout << __COLOR_GREEN << "decodificar_archivo" << __COLOR_RESET << " [nombre_archivo.huf] [nombre_imagen.pgm]" << endl;
          cout << __COLOR_GREEN << "segmentar" << __COLOR_RESET << " [imagen.pgm] [salida_imagen.pgm] [sx1 sy1 sl1] ..." << endl;
          cout << __COLOR_GREEN << "salir" << __COLOR_RESET << endl;
     }
     else
     {
          string command = argv[1];

          if (command == "cargar_imagen")
          {

               cout << __COLOR_GREEN << "SYNOPSIS:" << __COLOR_RESET << endl;
               cout << "    cargar_imagen [nombre_imagen.pgm]" << endl;
               cout << __COLOR_GREEN << "USO:" << __COLOR_RESET << endl;
               cout << "     + Carga en memoria la imagen identificada por nombre_imagen.pgm. " << endl;
               cout << "     + Solo es posible cargar una unica imagen por sesion." << endl;
               cout << "     + Si se ejecuta nuevamente con otro archivo, la nueva imagen reemplazara a la anterior." << endl
                    << endl;
               cout << __COLOR_GREEN << "SALIDA" << __COLOR_RESET << endl;
               cout << "     Exito: La imagen nombre_imagen.pgm ha sido cargada." << endl;
               cout << "     Salida: La imagen nombre_imagen.pgm no ha podido ser cargada." << endl
                    << endl;
          }
          else if (command == "cargar_volumen")
          {

               cout << __COLOR_GREEN << "SYNOPSIS:" << __COLOR_RESET << endl;
               cout << "    cargar_volumen [nombre_base] [n_im]" << endl;
               cout << __COLOR_GREEN << "USO:" << __COLOR_RESET << endl;
               cout << "     + Carga en memoria una serie ordenada de imagenes con el nombre base nombre_base y un tamaño de n_im imagenes." << endl;
               cout << "     + Las imagenes de la serie deben estar nombradas como nombre_baseXX.pgm, donde XX es un numero de dos digitos indicando la posicion en la serie." << endl;
               cout << "     + Solo es posible cargar un unico volumen por sesion; si se ejecuta nuevamente con otro nombre, el volumen anterior sera reemplazado." << endl
                    << endl;
               cout << __COLOR_GREEN << "SALIDA" << __COLOR_RESET << endl;
               cout << "     Exito: El volumen nombre_base ha sido cargado." << endl;
               cout << "     Error: El volumen nombre_base no ha podido ser cargado." << endl
                    << endl;
          }
          else if (command == "info_imagen")
          {

               cout << __COLOR_GREEN << "SYNOPSIS:" << __COLOR_RESET << endl;
               cout << "    info_imagen" << endl;
               cout << __COLOR_GREEN << "USO:" << __COLOR_RESET << endl;
               cout << "     Muestra informacion basica de la imagen cargada en memoria." << endl
                    << endl;
               cout << __COLOR_GREEN << "SALIDA" << __COLOR_RESET << endl;
               cout << "     Exito: Imagen cargada en memoria: nombre_imagen.pgm, ancho: W, alto: H." << endl;
               cout << "     Error: No hay imagen cargada en memoria." << endl
                    << endl;
          }
          else if (command == "info_volumen")
          {

               cout << __COLOR_GREEN << "SYNOPSIS:" << __COLOR_RESET << endl;
               cout << "    info_volumen" << endl;
               cout << __COLOR_GREEN << "USO:" << __COLOR_RESET << endl;
               cout << "     Muestra informacion basica del volumen cargado en memoria." << endl
                    << endl;
               cout << __COLOR_GREEN << "SALIDA" << __COLOR_RESET << endl;
               cout << "     Exito: Volumen cargado en memoria: nombre_base, tamaño: n_im, ancho: W, alto: H." << endl;
               cout << "     Error: No hay volumen cargado en memoria." << endl
                    << endl;
          }
          else if (command == "proyeccion2D")
          {

               cout << __COLOR_GREEN << "SYNOPSIS:" << __COLOR_RESET << endl;
               cout << "    proyeccion2D [direccion] [criterio] [nombre_archivo.pgm]" << endl;
               cout << __COLOR_GREEN << "USO:" << __COLOR_RESET << endl;
               cout << "     Genera una imagen 2D a partir de la serie de imagenes cargada en memoria." << endl;
               cout << "     La direccion puede ser:" << endl;
               cout << "         x: columnas" << endl;
               cout << "         y: filas" << endl;
               cout << "         z: profundidad" << endl;
               cout << "     El criterio puede ser:" << endl;
               cout << "         minimo" << endl;
               cout << "         maximo" << endl;
               cout << "         promedio" << endl;
               cout << "         mediana" << endl;
               cout << "     La imagen generada se guarda en nombre_archivo.pgm." << endl;
               cout << "     Este comando solo funciona si hay un volumen cargado." << endl
                    << endl;

               cout << __COLOR_GREEN << "SALIDA" << __COLOR_RESET << endl;
               cout << "     Exito: La proyeccion 2D del volumen en memoria ha sido generada y almacenada en el archivo nombre_archivo.pgm." << endl;
               cout << "     Error:" << endl;
               cout << "         El volumen no ha sido cargado en memoria." << endl;
               cout << "         La proyeccion 2D no pudo ser generada." << endl
                    << endl;
          }
          else if (command == "codificar_imagen")
          {

               cout << __COLOR_GREEN << "SYNOPSIS:" << __COLOR_RESET << endl;
               cout << "    codificar_imagen [nombre_archivo.huf]" << endl;
               cout << __COLOR_GREEN << "USO:" << __COLOR_RESET << endl;
               cout << "     Aplica codificacion de Huffman a la imagen cargada en memoria y almacena el resultado en nombre_archivo.huf." << endl
                    << endl;
               cout << __COLOR_GREEN << "SALIDA" << __COLOR_RESET << endl;
               cout << "     Exito: La imagen en memoria ha sido codificada y almacenada en nombre_archivo.huf." << endl;
               cout << "     Error: No hay una imagen cargada en memoria." << endl
                    << endl;
          }
          else if (command == "decodificar_archivo")
          {

               cout << __COLOR_GREEN << "SYNOPSIS:" << __COLOR_RESET << endl;
               cout << "    decodificar_archivo [nombre_archivo.huf] [nombre_imagen.pgm]" << endl;
               cout << __COLOR_GREEN << "USO:" << __COLOR_RESET << endl;
               cout << "     Decodifica el archivo nombre_archivo.huf y genera la imagen resultante en formato PGM como nombre_imagen.pgm." << endl
                    << endl;

               cout << __COLOR_GREEN << "SALIDA" << __COLOR_RESET << endl;
               cout << "     Exito: El archivo nombre_archivo.huf ha sido decodificado exitosamente y almacenado en nombre_imagen.pgm." << endl;
               cout << "     Error: El archivo nombre_archivo.huf no pudo ser decodificado." << endl
                    << endl;
          }
          else if (command == "segmentar")
          {
               cout << __COLOR_GREEN << "SYNOPSIS:" << __COLOR_RESET << endl;
               cout << "    segmentar [salida_imagen.pgm] [sx1 sy1 sl1] ..." << endl;
               cout << __COLOR_GREEN << "USO:" << __COLOR_RESET << endl;
               cout << "     Realiza la segmentacion de la imagen cargada en memoria usando un conjunto de semillas." << endl;
               cout << "     Se pueden ingresar hasta 5 semillas en el comando." << endl;
               cout << "     La imagen segmentada se guarda en salida_imagen.pgm." << endl
                    << endl;

               cout << __COLOR_GREEN << "SALIDA" << __COLOR_RESET << endl;
               cout << "     Exito: La imagen en memoria fue segmentada correctamente y almacenada en salida_imagen.pgm." << endl;
               cout << "     Error:" << endl;
               cout << "         No hay imagen cargada en memoria." << endl;
               cout << "         La segmentacion no pudo ser realizada." << endl
                    << endl;
          }
          else
          {
               cout << "Este comando no existe" << endl;
          }
     }

     return 0;
}

/**
 * @brief Define el comando `ayuda` en CommandManager.
 *
 * Asocia el comando `ayuda` con la función `handlerAyuda`.
 */
Comando CommandManager::ayudaCommand = *(
    new Comando({"ayuda",
                 1,
                 [](vector<string> args, Memoria &memoria)
                 {
                      return handlerAyuda(args, memoria);
                 }}));