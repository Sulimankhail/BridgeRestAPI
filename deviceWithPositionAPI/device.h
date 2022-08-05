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
    std::string title;
    int issue{DELETED_ISSUE};
    std::string writer;
    std::string penciler;
    std::string inker;
    std::string letterer;
    std::string colorist;
};

std::string toJson(const DeviceWithPS &deviceWithPs);
DeviceWithPS fromJson(const std::string &json);

} // namespace deviceWithPosition
