#include <bits/stdc++.h>
#include "commandManager.h"

using namespace std;

int execution(vector<string> argv)
{
  exit(1);
  return 0;
}

Command CommandManager::exitCommand = *(
    new Command({"exit",
                 1,
                 [](vector<string> args)
                 {
                   return execution(args);
                 }}));