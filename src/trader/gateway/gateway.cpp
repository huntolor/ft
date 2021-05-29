// Copyright [2020-2021] <Copyright Kevin, kevin.lau.gd@gmail.com>

#include "trader/gateway/gateway.h"

#include "trader/gateway/back_test/back_test_gateway.h"
#include "trader/gateway/ctp/ctp_gateway.h"
#include "trader/gateway/xtp/xtp_gateway.h"

namespace ft {

GatewayCtorMap& __GetGatewayCtorMap() {
  static GatewayCtorMap map;
  return map;
}

std::shared_ptr<Gateway> CreateGateway(const std::string& name) {
  auto& map = __GetGatewayCtorMap();
  auto it = map.find(name);
  if (it == map.end()) {
    return nullptr;
  } else {
    return (*it->second)();
  }
}

REGISTER_GATEWAY("ctp", CtpGateway);
REGISTER_GATEWAY("xtp", XtpGateway);
REGISTER_GATEWAY("backtest", BackTestGateway);

}  // namespace ft