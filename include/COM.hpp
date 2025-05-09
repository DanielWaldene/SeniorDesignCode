#pragma once
#include <iostream>
#include <mavsdk/mavsdk.h>
#include <mavsdk/connection_result.h>
#include <mavsdk/plugins/telemetry/telemetry.h>
#include <mavsdk/plugins/action/action.h>
#include <mavsdk/plugins/offboard/offboard.h>
#include <mavsdk/plugins/info/info.h>
#include <mavsdk/plugins/winch/winch.h>
#include <mavsdk/system.h>
#include <mavsdk/plugins/mavlink_passthrough/mavlink_passthrough.h>
#include <mavsdk/plugins/param/param.h>
/*
class Connection{
    public:
        
        Connection(const std::string &url, const int &baudrate);
        
        mavsdk::ConnectionResult get_status();
        void Send_Command_To_Component(mavsdk::System&system,uint8_t target_component_id, uint16_t command_id, float param1, float param2, float param3, float param4, float param5, float param6, float param7);
    private:
        mavsdk::ConnectionResult Status;
        std::string URL;
        int BaudRate;
        mavsdk::Mavsdk mav;
};*/