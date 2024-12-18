#ifndef __OUTPUT_DEVICE_HPP__
#define __OUTPUT_DEVICE_HPP__

#include "Team.hpp"

#include <print>
#include <unordered_map>


class OutputDevice{
    private:


    public:
        OutputDevice() = default;
        virtual ~OutputDevice() = default;

        virtual     void update(const std::unordered_map<std::string,Team> &teamMap) = 0;

};

class DummyOutputDevice : public OutputDevice{
    private:

    public:
        DummyOutputDevice() = default;
        virtual ~DummyOutputDevice() = default;

        virtual     void update(const std::unordered_map<std::string,Team> &teamMap) override;
};





#endif  /*  __OUTPUT_DEVICE_HPP__   */

