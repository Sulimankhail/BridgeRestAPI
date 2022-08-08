#pragma once

#include "device.h"

#include <cstddef>
#include <vector>

namespace deviceWithPosition
{

using DeviceWithPosition = std::vector<DeviceWithPS>;

DeviceWithPosition load();

DeviceWithPS calculateBeamPosition(DeviceWithPosition &db, DeviceWithPS &&deviceWithPs);

} // namespace deviceWithPosition
