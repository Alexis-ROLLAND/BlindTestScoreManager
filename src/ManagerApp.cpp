#include "InputDevice.hpp"


int main(){

    ScoreManager    Manager{};
    udp_server_InputDevice indev{Manager};

    indev.Start();
    



}

