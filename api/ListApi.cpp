/**
* iRODS REST API
* This is the iRODS REST API
*
* OpenAPI spec version: 1.0.0
* Contact: info@irods.org
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/swagger-api/swagger-codegen.git
* Do not edit the class manually.
*/

#include "ListApi.h"

namespace io {
namespace swagger {
namespace server {
namespace api {

using namespace io::swagger::server::model;

ListApi::ListApi(Pistache::Address addr)
    : httpEndpoint(std::make_shared<Pistache::Http::Endpoint>(addr))
{ };

void ListApi::init(size_t thr = 2) {
    auto opts = Pistache::Http::Endpoint::options()
        .threads(thr);
    httpEndpoint->init(opts);
    setupRoutes();
}

void ListApi::start() {
    httpEndpoint->setHandler(router.handler());
    httpEndpoint->serve();
}

void ListApi::shutdown() {
    httpEndpoint->shutdown();
}

void ListApi::setupRoutes() {
    using namespace Pistache::Rest;

    Routes::Get(router, base + "/list", Routes::bind(&ListApi::stream_handler, this));

    // Default handler, called when a route is not found
    router.addCustomHandler(Routes::bind(&ListApi::list_api_default_handler, this));
}

void ListApi::stream_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {

    // Getting the query params
    auto path = request.query().get("path");
    auto stat = request.query().get("stat");
    auto permissions = request.query().get("permissions");
    auto metadata = request.query().get("metadata");
    auto offset = request.query().get("offset");
    auto limit = request.query().get("limit");
    
    try {
      this->stream(request.headers(), request.body(), path, stat, permissions, metadata, offset, limit, response);
    } catch (std::runtime_error & e) {
      //send a 400 error
      response.send(Pistache::Http::Code::Bad_Request, e.what());
      return;
    }

}

void ListApi::list_api_default_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
    response.send(Pistache::Http::Code::Not_Found, "The requested method does not exist");
}

}
}
}
}

