#ifndef PUMPHANDLER_H
#define PUMPHANDLER_H

#include <cstdint>
#include <array>
struct outs_struct
{
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

class pumpHandler
{
public:

    std::array<uint8_t, 3> getArray();

    void turnOnExternalPump();
    void turnOffExternalPump();
    void turnOnInternalPump();
    void turnOffInternalPump();
    void turnOnCoolingValve();
    void turnOffCoolingValve();
    void turnOnHeatingValve();
    void turnOffHeatingValve();
    void turnOnHeater();
    void turnOffHeater();
    void turnOnHeatExchange();
    void turnOffHeatExchange();

    pumpHandler();
private:
    outs_struct pumpValues{};
};

#endif // PUMPHANDLER_H
