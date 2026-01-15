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

    void turnOnExternal2Pump();
    void turnOffExternal2Pump();

    void turnOnInternal2Pump();
    void turnOffInternal2Pump();

    void setOut(int out_number);
    void resetOut(int out_number);


private:

    void setOut1LS() {pumpStatus.out1_LS = 1;}
    void resetOut1LS() {pumpStatus.out1_LS = 0;}
    void setOut1HS() {pumpStatus.out1_HS = 1;}
    void resetOut1HS() {pumpStatus.out1_HS = 0;}
    void setOut2LS() {pumpStatus.out2_LS = 1;}
    void resetOut2LS() {pumpStatus.out2_LS = 0;}
    void setOut2HS() {pumpStatus.out2_HS = 1;}
    void resetOut2HS() {pumpStatus.out2_HS = 0;}
    void setOut3LS() {pumpStatus.out3_LS = 1;}
    void resetOut3LS() {pumpStatus.out3_LS = 0;}
    void setOut3HS() {pumpStatus.out3_HS = 1;}
    void resetOut3HS() {pumpStatus.out3_HS = 0;}
    void setOut4LS() {pumpStatus.out4_LS = 1;}
    void resetOut4LS() {pumpStatus.out4_LS = 0;}
    void setOut4HS() {pumpStatus.out4_HS = 1;}
    void resetOut4HS() {pumpStatus.out4_HS = 0;}
    void setOut5LS() {pumpStatus.out5_LS = 1;}
    void resetOut5LS() {pumpStatus.out5_LS = 0;}
    void setOut5HS() {pumpStatus.out5_HS = 1;}
    void resetOut5HS() {pumpStatus.out5_HS = 0;}
    void setOut6LS() {pumpStatus.out6_LS = 1;}
    void resetOut6LS() {pumpStatus.out6_LS = 0;}
    void setOut6HS() {pumpStatus.out6_HS = 1;}
    void resetOut6HS() {pumpStatus.out6_HS = 0;}
    void setOut7LS() {pumpStatus.out7_LS = 1;}
    void resetOut7LS() {pumpStatus.out7_LS = 0;}
    void setOut7HS() {pumpStatus.out7_HS = 1;}
    void resetOut7HS() {pumpStatus.out7_HS = 0;}
    void setOut8LS() {pumpStatus.out8_LS = 1;}
    void resetOut8LS() {pumpStatus.out8_LS = 0;}
    void setOut8HS() {pumpStatus.out8_HS = 1;}
    void resetOut8HS() {pumpStatus.out8_HS = 0;}
    void setOut9LS() {pumpStatus.out9_LS = 1;}
    void resetOut9LS() {pumpStatus.out9_LS = 0;}
    void setOut9HS() {pumpStatus.out9_HS = 1;}
    void resetOut9HS() {pumpStatus.out9_HS = 0;}
    void setOut10LS() {pumpStatus.out10_LS = 1;}
    void resetOut10LS() {pumpStatus.out10_LS = 0;}
    void setOut10HS() {pumpStatus.out10_HS = 1;}
    void resetOut10HS() {pumpStatus.out10_HS = 0;}

    ecuPumps pumpStatus{};
};

#endif // ECUPUMPHANDLER_H
