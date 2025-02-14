#include <bits/stdc++.h>
#include "commandManager.h"

using namespace std;

int execution(vector<string> argv)
{

  // if (argv.size == 1)
  // { // Ayuda general
  // }
  // else
  // {
  //   string command = argv[1];


  // }

  return 0;
}

Command CommandManager::exitCommand = *(
    new Command({"help",
                 1,
                 [](vector<string> args)
                 {
                   return execution(args);
                 }}));