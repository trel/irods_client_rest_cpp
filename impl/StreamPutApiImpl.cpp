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

#include "StreamPutApiImpl.h"

namespace io {
namespace swagger {
namespace server {
namespace api {

using namespace io::swagger::server::model;

StreamPutApiImpl::StreamPutApiImpl(Pistache::Address addr)
    : StreamPutApi(addr)
    { }

void StreamPutApiImpl::stream(const Pistache::Http::Header::Collection& headers, const std::string body, const Pistache::Optional<std::string> &path, const Pistache::Optional<std::string> &offset, const Pistache::Optional<std::string> &limit, Pistache::Http::ResponseWriter &response) {
    MACRO_IRODS_STREAM_API_IMPLEMENTATION
}

}
}
}
}
