#include "ecupumphandler.h"

ecuPumpHandler::ecuPumpHandler() {}

std::array<uint8_t, 3> ecuPumpHandler::getArray()
{

    uint8_t op_ctrl_1 = 0;
    uint8_t op_ctrl_2 = 0;
    uint8_t op_ctrl_3 = 0;

    if(pumpStatus.out1_LS){op_ctrl_1 |= 0x01;}
    if(pumpStatus.out1_HS){op_ctrl_1 |= 0x02;}
    if(pumpStatus.out2_LS){op_ctrl_1 |= 0x04;}
    if(pumpStatus.out2_HS){op_ctrl_1 |= 0x08;}
    if(pumpStatus.out3_LS){op_ctrl_1 |= 0x10;}
    if(pumpStatus.out3_HS){op_ctrl_1 |= 0x20;}
    if(pumpStatus.out4_LS){op_ctrl_1 |= 0x40;}
    if(pumpStatus.out4_HS){op_ctrl_1 |= 0x80;}

    if(pumpStatus.out5_LS){op_ctrl_2 |= 0x01;}
    if(pumpStatus.out5_HS){op_ctrl_2 |= 0x02;}
    if(pumpStatus.out6_LS){op_ctrl_2 |= 0x04;}
    if(pumpStatus.out6_HS){op_ctrl_2 |= 0x08;}
    if(pumpStatus.out7_LS){op_ctrl_2 |= 0x10;}
    if(pumpStatus.out7_HS){op_ctrl_2 |= 0x20;}
    if(pumpStatus.out8_LS){op_ctrl_2 |= 0x40;}
    if(pumpStatus.out8_HS){op_ctrl_2 |= 0x80;}

    if(pumpStatus.out9_LS){op_ctrl_3 |= 0x01;}
    if(pumpStatus.out9_HS){op_ctrl_3 |= 0x02;}
    if(pumpStatus.out10_LS){op_ctrl_3 |= 0x04;}
    if(pumpStatus.out10_HS){op_ctrl_3 |= 0x08;}

    return std::array<uint8_t, 3>{op_ctrl_1, op_ctrl_2, op_ctrl_3};

}

void ecuPumpHandler::turnOnExternalPump()
{
    pumpStatus.out4_HS = 1;
}

void ecuPumpHandler::turnOffExternalPump()
{
    pumpStatus.out4_HS = 0;
}

void ecuPumpHandler::turnOnInternalPump()
{

    pumpStatus.out2_HS = 1;//fill when we know what out

}

void ecuPumpHandler::turnOffInternalPump()
{

    pumpStatus.out2_HS = 0;//fill when we know what out

}
