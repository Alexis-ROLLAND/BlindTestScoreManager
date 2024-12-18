#include "InputDevice.hpp"
#include "outputDevice.hpp"

int main(){

    DummyOutputDevice   Screen{};
    ScoreManager    Manager{Screen};
    udp_server_InputDevice indev{Manager};
    


    

    indev.Start();
    



}

