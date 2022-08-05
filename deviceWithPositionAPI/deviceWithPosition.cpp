#include "deviceWithPosition.h"

#include <iostream>
#include <mutex>
#include <string>
#include <vector>

namespace deviceWithPosition
{

std::mutex g_dbMutex;
using DeviceWithPosition = std::vector<DeviceWithPS>;

DeviceWithPosition load()
{
    DeviceWithPosition db;
    db.emplace_back(fromJson(
        R"json({"title":"The Fantastic Four","issue":1,"writer":"Stan Lee","penciler":"Jack Kirby","inker":"George Klein","letterer":"Artie Simek","colorist":"Stan Goldberg"})json"));
    {
        DeviceWithPS deviceWithPs;
        deviceWithPs.title = "The Fantastic Four";
        deviceWithPs.issue = 3;
        deviceWithPs.writer = "Stan Lee";
        deviceWithPs.penciler = "Jack Kirby";
        deviceWithPs.inker = "Sol Brodsky";
        deviceWithPs.letterer = "Artie Simek";
        deviceWithPs.colorist = "Stan Goldberg";
        db.push_back(deviceWithPs);
    }
    return db;
}

bool validId(const DeviceWithPosition &db, std::size_t &id)
{
    return id < db.size() && db[id].issue != DeviceWithPS ::DELETED_ISSUE;
}

std::size_t calculateBeamPosition(DeviceWithPosition &db, DeviceWithPS &&deviceWithPs)
{
    if (deviceWithPs.title.empty() || deviceWithPs.issue < 1 ||
            deviceWithPs.writer.empty() || deviceWithPs.penciler.empty() ||
            deviceWithPs.inker.empty() || deviceWithPs.letterer.empty() ||
            deviceWithPs.colorist.empty())
    {
        throw std::runtime_error("Invalid deviceWithPosition");
    }

    std::unique_lock<std::mutex> lock(g_dbMutex);
    // ids are zero-based
    const std::size_t id = db.size();
    db.push_back(deviceWithPs);
    return id;
}

} // namespace deviceWithPosition
