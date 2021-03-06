#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>

#include <algorithm>
#include <csignal>
#include <cstring>
#include <functional>
#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <utility>
#include <vector>

#include "cfg.hpp"
#include "gui.hpp"
#include "helpers.hpp"
#include "swarm.hpp"
#include "unused.hpp"

int main(int argc, char** argv) {
  Cfg* cfg = new Cfg(argc, argv);
  Gui* gui = new Gui(cfg);
  Swarm& swarm = Swarm::Singleton();
  swarm.Start(std::bind(&Gui::SwarmCallback, gui, std::placeholders::_1,
                        std::placeholders::_2));
  return gui->Run();
}
