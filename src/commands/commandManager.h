/**
 * @file commandManager.h
 * @brief Gestión de comandos para un sistema de procesamiento.
 *
 * Este archivo contiene la definición de las clases Command y CommandManager,
 * que permiten la ejecución y administración de comandos dentro de un sistema.
 */

#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H

#include <unordered_map>
#include <iostream>
#include <vector>
#include <functional>

/**
 * @class Command
 * @brief Representa un comando con su nombre, número mínimo de argumentos y su función asociada.
 */
class Command
{
public:
  std::string name;                                      ///< Nombre del comando
  int minArgs;                                           ///< Número mínimo de argumentos requeridos
  std::function<int(std::vector<std::string>)> function; ///< Función que ejecuta el comando

public:
  /**
   * @brief Constructor parametrizado.
   * @param n Nombre del comando
   * @param nA Número mínimo de argumentos
   * @param f Función asociada al comando
   */
  Command(std::string n, int nA, std::function<int(std::vector<std::string>)> f)
  {
    this->name = n;
    this->minArgs = nA;
    this->function = f;
  }
};

/**
 * @class CommandManager
 * @brief Administra y ejecuta los comandos disponibles en el sistema.
 */
class CommandManager
{
private:
  std::vector<Command> comandos; ///< Lista de comandos disponibles

  /**
   * @brief Encuentra un comando por su nombre.
   * @param name Nombre del comando a buscar.
   * @return Puntero al comando encontrado, o nullptr si no existe.
   */
  Command *encontrarComando(std::string name);

  static Command salirCommand;              ///< Comando para salir del sistema
  static Command ayudaCommand;              ///< Comando para mostrar ayuda
  static Command cargarImagenCommand;       ///< Comando para cargar una imagen
  static Command cargarVolumenCommand;      ///< Comando para cargar un volumen
  static Command infoImagenCommand;         ///< Comando para obtener información de una imagen
  static Command infoVolumenCommand;        ///< Comando para obtener información de un volumen
  static Command proyeccion2DCommand;       ///< Comando para realizar proyecciones 2D
  static Command codificarImagenCommand;    ///< Comando para codificar una imagen
  static Command decodificarArchivoCommand; ///< Comando para decodificar un archivo
  static Command segmentarCommand;          ///< Comando para segmentar una imagen o volumen

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
  int ejecutarComando(std::vector<std::string> argv);

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