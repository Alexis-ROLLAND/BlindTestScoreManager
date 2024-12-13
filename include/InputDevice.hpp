#ifndef __INPUT_DEVICE_HPP__
#define __INPUT_DEVICE_HPP__

#include <iostream>
#include <thread>
#include <netinet/in.h>
#include <print>

#include "ScoreManager.hpp"

class InputDevice{
    private:

    protected:
        ScoreManager    Manager{};

    public:
        InputDevice() = delete;     /* No default Ctor */
        virtual ~InputDevice() = default;

        InputDevice(ScoreManager &manager):Manager{manager}{};

        virtual     void    Start() = 0;


};
//----------------------------------------------------------------------------
constexpr   uint16_t    defaultUdpPort = 6666;
constexpr   int         MAXLINE = 80;

class   NetworkException : public std::runtime_error{
    public:
        explicit NetworkException(const std::string& what_arg):std::runtime_error(what_arg){};
} ;

class udp_server_InputDevice : public InputDevice{
    private:
        uint16_t    udpPort{};
        std::jthread    udpServerThread;
        void    _serverThread();
        uint16_t    getUdpPort(){return this->udpPort;};
    public:
        udp_server_InputDevice() = delete;
        virtual ~udp_server_InputDevice() = default;

        udp_server_InputDevice(ScoreManager &manager, uint16_t udpPort = defaultUdpPort):InputDevice{manager},udpPort{udpPort}{};

        virtual     void    Start() override;
};
//----------------------------------------------------------------------------






#endif  /*  __INPUT_DEVICE_HPP__    */