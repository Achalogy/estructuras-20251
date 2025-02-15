#include <bits/stdc++.h>
#include "commandManager.h"

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
  
  if(line.size() == 0) {
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

Command *CommandManager::encontrarComando(string name)
{
  for (Command &c : this->comandos)
  {
    if (c.name == name)
    {
      return &c;
    }
  }
  return nullptr;
}

int CommandManager::ejecutarComando(vector<string> argv)
{
  if(argv.size() == 0) return 0;
  Command *command = this->encontrarComando(argv[0]);

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

  int execCode = command->function(argv);

  return execCode;
}