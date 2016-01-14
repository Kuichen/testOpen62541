#include <stdio.h>
#include "ua_types.h"
#include "ua_server.h"
#include "logger_stdout.h"
#include "networklayer_tcp.h"

UA_Boolean running;
int main(void)
{
  UA_Server *server = UA_Server_new(UA_ServerConfig_standard);
  UA_Server_addNetworkLayer(server, ServerNetworkLayerTCP_new(UA_ConnectionConfig_standard, 16664));
  running = UA_TRUE;
  UA_Server_run(server, 1, &running);
  UA_Server_delete(server);

  return 0;
}
