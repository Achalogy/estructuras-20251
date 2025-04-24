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
#include "TADMemoria.h"
#include "../colors/colors.h"

#define ull unsigned long long

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
  for (Comando &c : comandos)
  {
    if (c.name == name)
    {
      return &c;
    }
  }
  return nullptr;
}

int CommandManager::ejecutarComando(vector<string> argv, Memoria &memoria)
{
  bool showTime = false;

  if (argv.size() == 0)
    return 0;

  if (argv.size() >= 2 && strcmp(argv[0].c_str(), "time") == 0)
  {
    argv = vector<string>(argv.begin() + 1, argv.begin() + argv.size());
    showTime = true;
  }

  // Buscar comando
  
  Comando *command = encontrarComando(argv[0]);

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

  ull startTime = std::chrono::duration_cast<std::chrono::milliseconds>(
                      std::chrono::system_clock::now().time_since_epoch())
                      .count();
  int execCode = command->function(argv, memoria);
  ull endTime = std::chrono::duration_cast<std::chrono::milliseconds>(
                    std::chrono::system_clock::now().time_since_epoch())
                    .count();

  ull time = endTime - startTime;

  if(showTime) {
    if(time > 10000) {
      cout << endl << "Ejecutado en: " << time / 1000 << "s" << endl;
    }else {
      cout << endl << "Ejecutado en: " << time << "ms" << endl;
    }
  }

  return execCode;
}