#include "device.h"

#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

namespace deviceWithPosition
{

std::string toJson(const DeviceWithPS &deviceWithPs)

{
    rapidjson::Document doc;
    rapidjson::Value &obj = doc.SetObject();
    auto addMember = [&obj, &doc](const char *key, const std::string &value)
    {
        using String = rapidjson::GenericStringRef<char>;
        obj.AddMember(String{key}, String{value.c_str()}, doc.GetAllocator());
    };
    addMember("title", deviceWithPs.title); //TODO: change the names
    obj.AddMember("issue", deviceWithPs.issue, doc.GetAllocator());
    addMember("writer", deviceWithPs.writer);
    addMember("penciler", deviceWithPs.penciler);
    addMember("inker", deviceWithPs.inker);
    addMember("letterer", deviceWithPs.letterer);
    addMember("colorist", deviceWithPs.colorist);
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    doc.Accept(writer);
    return buffer.GetString();
}

DeviceWithPS fromJson(const std::string &json)
{
    rapidjson::Document doc;
    doc.Parse(json.c_str());
    DeviceWithPS deviceWithPS{};
    auto getString = [&doc](const char *key) { return doc[key].GetString(); };
    deviceWithPS.title = getString("title");
    deviceWithPS.issue = doc["issue"].GetInt();
    deviceWithPS.writer = getString("writer");
    deviceWithPS.penciler = getString("penciler");
    deviceWithPS.inker = getString("inker");
    deviceWithPS.letterer = getString("letterer");
    deviceWithPS.colorist = getString("colorist");
    return deviceWithPS;
}

} // namespace deviceWithPosition
