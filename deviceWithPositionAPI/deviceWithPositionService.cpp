#include "device.h"
#include "deviceWithPosition.h"

#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/mime.h>
#include <pistache/net.h>
#include <pistache/router.h>

#include <memory>
#include <string>
#include <thread>

namespace deviceWithPositionService
{

class Service
{
    // portNumber
    // host: it can be localhost or over an ip
public:
    Service(uint16_t portNum = 8080, unsigned int numThreads = std::thread::hardware_concurrency())
        : m_portNum(portNum),
        m_numThreads(numThreads),
        m_address("localhost", portNum),
        m_endPoint(std::make_shared<Pistache::Http::Endpoint>(m_address)),
        m_db(deviceWithPosition::load())
    {
    }

    void run();

private:
    void configureRoutes();

    using Request = Pistache::Rest::Request;
    using Response = Pistache::Http::ResponseWriter;
    std::basic_string<char> calculateBeamPosition(const Request &request, Response response);

    uint16_t m_portNum;
    unsigned int m_numThreads;
    Pistache::Address m_address;
    std::shared_ptr<Pistache::Http::Endpoint> m_endPoint;
    Pistache::Rest::Router m_router;
    deviceWithPosition::DeviceWithPosition m_db;
};

void Service::configureRoutes()
{
    Pistache::Rest::Routes::Put(m_router, "/calculate", Pistache::Rest::Routes::bind(&Service::calculateBeamPosition, this));
    Pistache::Rest::Routes::Post(m_router, "/calculate", Pistache::Rest::Routes::bind(&Service::calculateBeamPosition, this));
}

std::basic_string<char> Service::calculateBeamPosition(const Request &request, Response response)
{
    try
    {
        const std::string json = request.body();
        deviceWithPosition::DeviceWithPS deviceWithPs = deviceWithPosition::calculateBeamPosition(deviceWithPosition::fromJson(json));
        return toJson(deviceWithPs);
    }
    catch (const std::runtime_error &bang)
    {
        response.send(Pistache::Http::Code::Not_Found, bang.what(), MIME(Text, Plain));
    }
    catch (...)
    {
        response.send(Pistache::Http::Code::Internal_Server_Error, "Internal error", MIME(Text, Plain));
    }
}

void Service::run()
{
    std::cout << "Starting on port " << m_portNum << " with " << m_numThreads << " threads.\n";
    m_endPoint->init(Pistache::Http::Endpoint::options().threads(m_numThreads));
    configureRoutes();
    m_endPoint->setHandler(m_router.handler());
    m_endPoint->serve();
}

} // namespace deviceWithPositionService

int main()
{
    try
    {
        deviceWithPositionService::Service service;
        service.run();
    }
    catch (const std::exception &bang)
    {
        std::cerr << bang.what() << '\n';
        return 1;
    }
    catch (...)
    {
        return 1;
    }

    return 0;
}
