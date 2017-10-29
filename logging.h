#define LOG(t, x)                                                              \
  std::cout << t << "(" << __FILE__ << ":" << __LINE__ << "):" << x << std::endl
#define DEBUG(x) LOG("DEBUG", x)
#define ERROR(x) LOG("ERROR", x)
