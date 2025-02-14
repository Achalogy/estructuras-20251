#include <bits/stdc++.h>
#include "commandManager.h"

using namespace std;

int dummySalir(vector<string> argv)
{
  exit(1);
  return 0;
}

Command CommandManager::salirCommand = *(
    new Command({"salir",
                 1,
                 [](vector<string> args)
                 {
                   return dummySalir(args);
                 }}));