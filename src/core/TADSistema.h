/**
 * @file TADSistema.h
 * @brief Definición del TAD Sistema
 */

#ifndef SISTEMA_H
#define SISTEMA_H

#include <bits/stdc++.h>

#include "TADMemoria.h"
#include "TADCommandManager.h"

/**
 * @class Sistema
 * @brief Contiene toda la lógica del proyecto
 */

class Sistema
{
private:
  Memoria memoria;
  CommandManager cm;

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
};

#endif