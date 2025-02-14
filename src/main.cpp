#include <bits/stdc++.h>
#include "commands/commandManager.h"

using namespace std;

int main()
{
  CommandManager *cm = new CommandManager();
  vector<string> argv;

  while(true)
  {
    argv = cm->getNextLine();

    // cout << "Comando " << argv[0] << " ejecutado" << endl;
    cm->ejecutarComando(argv);
  }
}