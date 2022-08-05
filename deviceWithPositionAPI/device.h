#pragma once

#include <string>

namespace deviceWithPosition
{

struct DeviceWithPS
{
    enum
    {
        DELETED_ISSUE = -1
    };
    std::string title; //TODO: change the fields as per mpole with a phase space
    int issue{DELETED_ISSUE};
    std::string writer;
    std::string penciler;
    std::string inker;
    std::string letterer;
    std::string colorist;
    std::string t; // this is the parameter t. Description:
    std::string t1; // this is the parameter t. Description:
    std::string t2; // this is the parameter t. Description:
    std::string n; // this is the parameter n. Description:
    int method; // this is the parameter t. Description:
    std::string name;
    double length;
    double strength;
    std::string type;
    double ps_x;
    double ps_xp;
    double ps_y;
    double ps_ps_tp;
    double ps_s;
    double ps_k;
};

std::string toJson(const DeviceWithPS &deviceWithPs);
DeviceWithPS fromJson(const std::string &json);

} // namespace deviceWithPosition
