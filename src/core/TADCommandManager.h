/**
 * @file TADCommandManager.h
 * @brief Gestión de comandos para un sistema de procesamiento.
 *
 * Este archivo contiene la definición de las clases Command y CommandManager,
 * que permiten la ejecución y administración de comandos dentro de un sistema.
 */

#ifndef TADCOMMANDMANAGER_H
#define TADCOMMANDMANAGER_H

#include <bits/stdc++.h>

#include "TADComando.h"
#include "TADMemoria.h"

/**
 * @class CommandManager
 * @brief Administra y ejecuta los comandos disponibles en el sistema.
 */
class CommandManager
{
private:
  std::vector<Comando> comandos; ///< Lista de comandos disponibles

  /**
   * @brief Encuentra un comando por su nombre.
   * @param name Nombre del comando a buscar.
   * @return Puntero al comando encontrado, o nullptr si no existe.
   */
  Comando *encontrarComando(std::string name);

  static Comando salirCommand;              ///< Comando para salir del sistema
  static Comando ayudaCommand;              ///< Comando para mostrar ayuda
  static Comando cargarImagenCommand;       ///< Comando para cargar una imagen
  static Comando cargarVolumenCommand;      ///< Comando para cargar un volumen
  static Comando infoImagenCommand;         ///< Comando para obtener información de una imagen
  static Comando infoVolumenCommand;        ///< Comando para obtener información de un volumen
  static Comando proyeccion2DCommand;       ///< Comando para realizar proyecciones 2D
  static Comando codificarImagenCommand;    ///< Comando para codificar una imagen
  static Comando decodificarArchivoCommand; ///< Comando para decodificar un archivo
  static Comando segmentarCommand;          ///< Comando para segmentar una imagen o volumen

public:
  /**
   * @brief Obtiene la siguiente línea de entrada del usuario.
   * @return Vector con los argumentos de la línea ingresada.
   */
  std::vector<std::string> getNextLine();

  /**
   * @brief Ejecuta un comando a partir de una lista de argumentos.
   * @param argv Lista de argumentos que representan el comando a ejecutar.
   * @return Código de retorno del comando ejecutado.
   */
  int ejecutarComando(std::vector<std::string> argv, Memoria memoria);

  /**
   * @brief Constructor de CommandManager. Inicializa los comandos disponibles.
   */
  CommandManager()
  {
    this->comandos.push_back(salirCommand);
    this->comandos.push_back(ayudaCommand);
    this->comandos.push_back(cargarImagenCommand);
    this->comandos.push_back(cargarVolumenCommand);
    this->comandos.push_back(infoImagenCommand);
    this->comandos.push_back(infoVolumenCommand);
    this->comandos.push_back(proyeccion2DCommand);
    this->comandos.push_back(codificarImagenCommand);
    this->comandos.push_back(decodificarArchivoCommand);
    this->comandos.push_back(segmentarCommand);
  }
};

#endif