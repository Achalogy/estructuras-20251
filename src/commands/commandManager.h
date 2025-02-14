#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H

#include <unordered_map>
#include <iostream>
#include <vector>
#include <functional>

class Command
{
public:
  std::string name;
  int minArgs;
  std::function<int(std::vector<std::string>)> function;

public:
  Command() {
    
  }
  Command(std::string n, int nA, std::function<int(std::vector<std::string>)> f)
  {
    this->name = n;
    this->minArgs = nA;
    this->function = f;
  }
};

class CommandManager
{
private:
  std::vector<Command> comandos;
  Command *encontrarComando(std::string name);

  static Command salirCommand;
  static Command ayudaCommand;

public:
  std::vector<std::string> getNextLine();
  int ejecutarComando(std::vector<std::string> argv);

  CommandManager()
  {
    this->comandos.push_back(salirCommand);
    this->comandos.push_back(ayudaCommand);
  }
};

#endif