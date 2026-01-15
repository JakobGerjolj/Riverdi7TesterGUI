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

    void setOut(int out_number);
    void resetOut(int out_number);

    pumpHandler();
private:

    void setOut1LS() {pumpValues.out1_LS = 1;}
    void resetOut1LS() {pumpValues.out1_LS = 0;}
    void setOut1HS() {pumpValues.out1_HS = 1;}
    void resetOut1HS() {pumpValues.out1_HS = 0;}
    void setOut2LS() {pumpValues.out2_LS = 1;}
    void resetOut2LS() {pumpValues.out2_LS = 0;}
    void setOut2HS() {pumpValues.out2_HS = 1;}
    void resetOut2HS() {pumpValues.out2_HS = 0;}
    void setOut3LS() {pumpValues.out3_LS = 1;}
    void resetOut3LS() {pumpValues.out3_LS = 0;}
    void setOut3HS() {pumpValues.out3_HS = 1;}
    void resetOut3HS() {pumpValues.out3_HS = 0;}
    void setOut4LS() {pumpValues.out4_LS = 1;}
    void resetOut4LS() {pumpValues.out4_LS = 0;}
    void setOut4HS() {pumpValues.out4_HS = 1;}
    void resetOut4HS() {pumpValues.out4_HS = 0;}
    void setOut5LS() {pumpValues.out5_LS = 1;}
    void resetOut5LS() {pumpValues.out5_LS = 0;}
    void setOut5HS() {pumpValues.out5_HS = 1;}
    void resetOut5HS() {pumpValues.out5_HS = 0;}
    void setOut6LS() {pumpValues.out6_LS = 1;}
    void resetOut6LS() {pumpValues.out6_LS = 0;}
    void setOut6HS() {pumpValues.out6_HS = 1;}
    void resetOut6HS() {pumpValues.out6_HS = 0;}
    void setOut7LS() {pumpValues.out7_LS = 1;}
    void resetOut7LS() {pumpValues.out7_LS = 0;}
    void setOut7HS() {pumpValues.out7_HS = 1;}
    void resetOut7HS() {pumpValues.out7_HS = 0;}
    void setOut8LS() {pumpValues.out8_LS = 1;}
    void resetOut8LS() {pumpValues.out8_LS = 0;}
    void setOut8HS() {pumpValues.out8_HS = 1;}
    void resetOut8HS() {pumpValues.out8_HS = 0;}
    void setOut9LS() {pumpValues.out9_LS = 1;}
    void resetOut9LS() {pumpValues.out9_LS = 0;}
    void setOut9HS() {pumpValues.out9_HS = 1;}
    void resetOut9HS() {pumpValues.out9_HS = 0;}
    void setOut10LS() {pumpValues.out10_LS = 1;}
    void resetOut10LS() {pumpValues.out10_LS = 0;}
    void setOut10HS() {pumpValues.out10_HS = 1;}
    void resetOut10HS() {pumpValues.out10_HS = 0;}

    outs_struct pumpValues{};
};

#endif // PUMPHANDLER_H
