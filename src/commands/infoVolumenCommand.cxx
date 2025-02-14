#include <bits/stdc++.h>
#include "commandManager.h"

using namespace std;

int dummyInfoVolumen(vector<string> argv)
{

  return 0;
}

Command CommandManager::infoVolumenCommand = *(
    new Command({"info_volumen",
                 1,
                 [](vector<string> args)
                 {
                   return dummyInfoVolumen(args);
                 }}));