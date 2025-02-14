#include <bits/stdc++.h>
#include "commandManager.h"

using namespace std;

int dummySegmentar(vector<string> argv)
{

  return 0;
}

Command CommandManager::segmentarCommand = *(
    new Command({"segmentar",
                 5,
                 [](vector<string> args)
                 {
                   return dummySegmentar(args);
                 }}));