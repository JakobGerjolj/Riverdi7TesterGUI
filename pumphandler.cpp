#include "pumphandler.h"

pumpHandler::pumpHandler() {}

void pumpHandler::turnOnInternalPump(){

    pumpValues.out8_HS = 1;

}

void pumpHandler::turnOffInternalPump(){

    pumpValues.out8_HS = 0;

}

void pumpHandler::turnOnExternalPump(){

    pumpValues.out2_HS = 1;

}

void pumpHandler::turnOffExternalPump(){

    pumpValues.out2_HS = 0;

}

void pumpHandler::turnOnCoolingValve(){

    pumpValues.out1_HS = 1;

}

void pumpHandler::turnOffCoolingValve(){

    pumpValues.out1_HS = 0;

}

void pumpHandler::turnOnHeatingValve(){

    pumpValues.out5_HS = 1;

}

void pumpHandler::turnOffHeatingValve(){

    pumpValues.out5_HS = 0;

}

void pumpHandler::turnOnHeater(){

    pumpValues.out7_HS = 1;

}

void pumpHandler::turnOffHeater(){

    pumpValues.out7_HS = 0;

}

void pumpHandler::turnOnHeatExchange(){

    //We do not know yet

}

void pumpHandler::turnOffHeatExchange(){

    //We do not know yet

}

std::array<uint8_t,3> pumpHandler::getArray(){

    uint8_t op_ctrl_1 = 0;
    uint8_t op_ctrl_2 = 0;
    uint8_t op_ctrl_3 = 0;

    if(pumpValues.out1_LS){op_ctrl_1 |= 0x01;}
    if(pumpValues.out1_HS){op_ctrl_1 |= 0x02;}
    if(pumpValues.out2_LS){op_ctrl_1 |= 0x04;}
    if(pumpValues.out2_HS){op_ctrl_1 |= 0x08;}
    if(pumpValues.out3_LS){op_ctrl_1 |= 0x10;}
    if(pumpValues.out3_HS){op_ctrl_1 |= 0x20;}
    if(pumpValues.out4_LS){op_ctrl_1 |= 0x40;}
    if(pumpValues.out4_HS){op_ctrl_1 |= 0x80;}

    if(pumpValues.out5_LS){op_ctrl_2 |= 0x01;}
    if(pumpValues.out5_HS){op_ctrl_2 |= 0x02;}
    if(pumpValues.out6_LS){op_ctrl_2 |= 0x04;}
    if(pumpValues.out6_HS){op_ctrl_2 |= 0x08;}
    if(pumpValues.out7_LS){op_ctrl_2 |= 0x10;}
    if(pumpValues.out7_HS){op_ctrl_2 |= 0x20;}
    if(pumpValues.out8_LS){op_ctrl_2 |= 0x40;}
    if(pumpValues.out8_HS){op_ctrl_2 |= 0x80;}

    if(pumpValues.out9_LS){op_ctrl_3 |= 0x01;}
    if(pumpValues.out9_HS){op_ctrl_3 |= 0x02;}
    if(pumpValues.out10_LS){op_ctrl_3 |= 0x04;}
    if(pumpValues.out10_HS){op_ctrl_3 |= 0x08;}

    return std::array<uint8_t, 3>{op_ctrl_1, op_ctrl_2, op_ctrl_3};

}

