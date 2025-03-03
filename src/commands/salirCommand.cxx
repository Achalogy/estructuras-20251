#include <bits/stdc++.h>
#include "../core/TADCommandManager.h"

using namespace std;

int dummySalir(vector<string> argv)
{
  exit(0);
  return 0;
}

Command CommandManager::salirCommand = *(
    new Command({"salir",
                 1,
                 [](vector<string> args)
                 {
                   return dummySalir(args);
                 }}));