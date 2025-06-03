#ifdef DEBUG
#define DEBUG_MSG(str)              \
  do {                              \
    cout << "\e[34m" << "[DEBUG] "; \
    cout << str << endl;            \
    cout << "\e[0m";                \
  } while (false)
#define DEBUG_EXEC(statement)              \
  do {                                     \
    cout << "\e[34m" << "[DEBUG]" << endl; \
    statement;                             \
    cout << "\e[0m";                       \
  } while (false)
#else
#define DEBUG_MSG(str) ((void)0)
#define DEBUG_EXEC(str) ((void)0)
#endif