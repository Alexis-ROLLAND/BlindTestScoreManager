#include "InputDevice.hpp"

//----------------------------------------------------------------------------
/**     concrete input device   */
//----------------------------------------------------------------------------
void    udp_server_InputDevice::_serverThread(){
    int sockfd;
    sockaddr_in     servaddr{};
    sockaddr_in     cliaddr{};
    char buffer[MAXLINE];

    std::println(std::clog,"UDP Server starting (port : {0:d})",static_cast<int>(this->getUdpPort()));
    // Creating socket file descriptor
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) throw NetworkException("Error while creating socket.");

    // Filling server information
    servaddr.sin_family = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(this->getUdpPort());

    // Bind the socket with the server address
    if ( bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 ) throw NetworkException("Error while binding the socket.");
    socklen_t len = sizeof(cliaddr); //len is value/result;

    int n{0};

    while(true){
        n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, ( struct sockaddr *) &cliaddr, &len);
        buffer[n] = '\0';
        std::string stmp{buffer};
        std::println(std::clog,"Message received = {0:}",stmp);
    }
}


void    udp_server_InputDevice::Start(){
    this->udpServerThread = std::jthread(&udp_server_InputDevice::_serverThread,this);
}

