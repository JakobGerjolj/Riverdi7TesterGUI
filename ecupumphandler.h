#ifndef ECUPUMPHANDLER_H
#define ECUPUMPHANDLER_H

#include <array>
#include <cstdint>
struct ecuPumps{

    uint8_t out1_LS : 1;
    uint8_t out1_HS : 1;
    uint8_t out2_LS : 1;
    uint8_t out2_HS : 1;
    uint8_t out3_LS : 1;
    uint8_t out3_HS : 1;
    uint8_t out4_LS : 1;
    uint8_t out4_HS : 1;

    uint8_t out5_LS : 1;
    uint8_t out5_HS : 1;
    uint8_t out6_LS : 1;
    uint8_t out6_HS : 1;
    uint8_t out7_LS : 1;
    uint8_t out7_HS : 1;
    uint8_t out8_LS : 1;
    uint8_t out8_HS : 1;

    uint8_t out9_LS : 1;
    uint8_t out9_HS : 1;
    uint8_t out10_LS : 1;
    uint8_t out10_HS : 1;

};

class ecuPumpHandler
{
public:
    ecuPumpHandler();

    std::array<uint8_t, 3> getArray();

    void turnOnExternalPump();
    void turnOffExternalPump();

    void turnOnInternalPump();
    void turnOffInternalPump();


private:
    ecuPumps pumpStatus{};
};

#endif // ECUPUMPHANDLER_H
