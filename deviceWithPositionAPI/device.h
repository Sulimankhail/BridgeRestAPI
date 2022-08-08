#pragma once

#include <string>

namespace deviceWithPosition
{

struct DeviceWithPS
{
    enum
    {
        DELETED_ID= -1
    };
    int id{DELETED_ID};
    std::string t; // this is the parameter t. Description:
    std::string t1; // this is the parameter t. Description:
    std::string t2; // this is the parameter t. Description:
    std::string n; // this is the parameter n. Description:
    std::int32_t method; // this is the parameter t. Description:
    std::string name;
    double length;
    double strength;
    std::string type;
    double ps_x;
    double ps_xp;
    double ps_y;
    double ps_yp;
    double ps_s;
    double ps_k;
};

std::string toJson(const DeviceWithPS &deviceWithPs);
DeviceWithPS fromJson(const std::string &json);

} // namespace deviceWithPosition
