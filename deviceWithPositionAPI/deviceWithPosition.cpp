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
    return db;
}

DeviceWithPS calculateBeamPosition(DeviceWithPosition  &db, DeviceWithPS &&deviceWithPs)
{
    if (deviceWithPs.length< 0.0 || deviceWithPs.id < 1 )
    {
        throw std::runtime_error("Invalid deviceWithPosition");
    }
    //todo: call the thor_scsi calculate beam position here
    // delete be bellow code after the call to thor_scsi is made
            deviceWithPs.
                    name = "Mpole name goes here QR12345";
            deviceWithPs.
            type = "quadrupole";
            deviceWithPs.
            id = 1;
            deviceWithPs.
            t = "TTT";
            deviceWithPs.
            t1 = "Jack Kirby";
            deviceWithPs.
            t2 = "Sol Brodsky";
            deviceWithPs.
            n = "Artie Simek";
            deviceWithPs.
            length = 1;
            deviceWithPs.
            strength = 1;
            deviceWithPs.
            ps_xp = 1;
            deviceWithPs.
            ps_x = 1;
            deviceWithPs.
            ps_y = 1;
            deviceWithPs.
            ps_yp = 1;
            deviceWithPs.
            ps_s = 1;
            deviceWithPs.
            ps_k = 1;
//    std::unique_lock<std::mutex> lock(g_dbMutex);
    // ids are zero-based
//    const std::size_t id = db.size();
//    db.push_back(deviceWithPs);
//    return id;

    return deviceWithPs;
}

} // namespace deviceWithPosition
