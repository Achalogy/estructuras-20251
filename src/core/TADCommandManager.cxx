/**
 * @file TADCommandManager.cxx
 * @brief Implementaciones de commandManager.h
 *
 * Gestión de comandos para un sistema de procesamiento.
 *
 * Este archivo contiene la definición de las clases Command y CommandManager,
 * que permiten la ejecución y administración de comandos dentro de un sistema.
 */

#include <bits/stdc++.h>
#include "TADCommandManager.h"

using namespace std;

vector<string> CommandManager::getNextLine()
{
  vector<string> argv;

  string line;
  char comando[10000];

  cout << "$ ";
  getline(cin, line);

  if (line.size() >= 10000)
  {
    cout << "Max Input Size Reached" << endl;
    return vector<string>();
  }

  if (line.size() == 0)
  {
    return vector<string>();
  }

  strcpy(comando, line.c_str());

  char *token = strtok(comando, " ");
  while (token != NULL)
  {
    argv.push_back(token);
    token = strtok(NULL, " ");
  }

  return argv;
}

Comando *CommandManager::encontrarComando(string name)
{
  for (Comando &c : this->comandos)
  {
    if (c.name == name)
    {
      return &c;
    }
  }
  return nullptr;
}

int CommandManager::ejecutarComando(vector<string> argv, Imagen * imagenEnMemoria)
{
  if (argv.size() == 0)
    return 0;
  Comando *command = this->encontrarComando(argv[0]);

  // Buscar comando

  if (command == nullptr)
  {
    cout << "Comando " << argv[0] << " no encontrado, puedes usar help para saber que comandos estan disponibles" << endl;
    return 1;
  }

  if (argv.size() < command->minArgs)
  {
    cout << "Argumentos insuficientes" << endl;
    return 1;
  }

  int execCode = command->function(argv, imagenEnMemoria);

  return execCode;
}