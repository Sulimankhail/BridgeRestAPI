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
    auto addMemberDouble = [&obj, &doc](const char *key, double value)
    {
        using String = rapidjson::GenericStringRef<char>;
        obj.AddMember(String{key}, value, doc.GetAllocator());
    };

    auto addMember = [&obj, &doc](const char *key, const std::string &value)
    {
        using String = rapidjson::GenericStringRef<char>;
        obj.AddMember(String{key}, String{value.c_str()}, doc.GetAllocator());
    };
    addMember("t", deviceWithPs.t); //TODO: change the names
    obj.AddMember("id", deviceWithPs.id, doc.GetAllocator());
    addMember("t1", deviceWithPs.t1);
    addMember("t2", deviceWithPs.t2);
    addMember("n", deviceWithPs.n);
    addMemberDouble("method", deviceWithPs.method);
    addMember("name", deviceWithPs.name);
    addMember("type", deviceWithPs.type);
    addMemberDouble("length", deviceWithPs.length);
    addMemberDouble("strength", deviceWithPs.strength);
    addMemberDouble("ps_x", deviceWithPs.ps_x);
    addMemberDouble("ps_xp", deviceWithPs.ps_xp);
    addMemberDouble("ps_y", deviceWithPs.ps_y);
    addMemberDouble("ps_yp", deviceWithPs.ps_yp);
    addMemberDouble("ps_s", deviceWithPs.ps_s);
    addMemberDouble("ps_k", deviceWithPs.ps_k);
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
    deviceWithPS.t = getString("t");
    deviceWithPS.id = doc["id"].GetInt();
    deviceWithPS.t1 = getString("t1");
    deviceWithPS.t2 = getString("t2");
    deviceWithPS.n = getString("n");
    deviceWithPS.name = getString("name");
    deviceWithPS.type = getString("type");
    deviceWithPS.length = doc["length"].GetInt();
    deviceWithPS.strength = doc["strength"].GetDouble();
    deviceWithPS.ps_x = doc["ps_x"].GetDouble();
    deviceWithPS.ps_xp = doc["ps_xp"].GetDouble();
    deviceWithPS.ps_y = doc["ps_y"].GetDouble();
    deviceWithPS.ps_yp = doc["ps_yp"].GetDouble();
    deviceWithPS.ps_s = doc["ps_s"].GetDouble();
    deviceWithPS.ps_k = doc["ps_k"].GetDouble();
    return deviceWithPS;
}

} // namespace deviceWithPosition
