#pragma once

#include <memory>
#include <string>

#include "envoy/common/pure.h"

namespace Ssl {

/**
 * SSL Context is used as a template for SSL connection configuration.
 */
class Context {
public:
  virtual ~Context() {}

  /**
   * @return the number of days in this context until the next certificate will expire
   */
  virtual size_t daysUntilFirstCertExpires() PURE;

  /**
   * @return a string of ca certificate path, certificate serial number and days until certificate
   * expiration
   */
  virtual std::string getCaCertInformation() PURE;

  /**
   * @return a string of cert chain certificate path, certificate serial number and days until
   * certificate expiration
   */
  virtual std::string getCertChainInformation() PURE;
};

class ClientContext : public virtual Context {};
typedef std::unique_ptr<ClientContext> ClientContextPtr;

class ServerContext : public virtual Context {};
typedef std::unique_ptr<ServerContext> ServerContextPtr;

} // SSL
