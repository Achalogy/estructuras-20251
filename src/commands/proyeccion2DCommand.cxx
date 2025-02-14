#include <bits/stdc++.h>
#include "commandManager.h"

using namespace std;

int dummyProyeccion2D(vector<string> argv)
{

  return 0;
}

Command CommandManager::proyeccion2DCommand = *(
    new Command({"proyeccion2D",
                 4,
                 [](vector<string> args)
                 {
                   return dummyProyeccion2D(args);
                 }}));