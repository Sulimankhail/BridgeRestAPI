add_executable(deviceWithPositionService
        deviceWithPositionService.cpp
        deviceWithPosition.cpp
        deviceWithPosition.h
        device.h
        device.cpp
         )
target_link_libraries(deviceWithPositionService PRIVATE pistache::pistache rapidjson)
set_property(TARGET deviceWithPositionService PROPERTY CXX_STANDARD "17")
