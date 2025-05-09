#include "COM.hpp"
using namespace mavsdk;
/*

monitoring a port 
    - make a Mavsdk object and call member function add_any_connection()
Access to drone information, telemetry, and control objects are provided by a number of plugins
    1.#include <mavsdk/plugins/action/action.h>
    2.Create a connection to a System object (system)
    3. Create the plugin instance, specifying the System it is to be used with
        -auto action= Action{system};
    4. action.takeoff();
    - the action plug in is used to arm and takeoff and land
    - the telemetry can be used to query GPS status flightmode
    - a seperate plugin instance must be created for each system that needs it
    creating a plugin instance
        - auto action = Action{system};
    the pointer can then be used to invode actions on the specified system for example to takeoff you would call the api as 
        - action.takeoff();
Info Class


/*
Connection::Connection(const std::string &url, const int &baudrate){
    URL = url;
    BaudRate = baudrate;
    
    ConnectionResult Status = mav.add_any_connection(URL);
}

ConnectionResult Connection::get_status(){
    return Status;
}
void Iterate_Through_Systems(Mavsdk &mav){
    auto systems = mav.systems();
    for(auto system:systems){
        
    }
}

void Connection::Send_Command_To_Component(mavsdk::System&system,uint8_t target_component_id, uint16_t command_id, float param1, float param2, float param3, float param4, float param5, float param6, float param7){
    MavlinkPassthrough passthrough(system);
    mavlink_message_t msg;
    mavlink_command_long_t command{};
    command.target_system=system.get_system_id();
    command.target_component=target_component_id;
    command.command=command_id;
    command.confirmation = 0;
    command.param1 = param1;
    command.param2 = param2;
    command.param3=param3;
    command.param4 = param4;
    command.param5 = param5;
    command.param6=param6;
    command.param7 = param1;
    uint16_t ms= mavlink_msg_command_long_encode(system.get_system_id(),MAV_COMP_ID_ALL, &msg, &command);
  
}
*/