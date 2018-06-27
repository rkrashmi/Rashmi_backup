###########################Built-in Libraries##################################
import time
import array
import sys
from ctypes import *
from Lib_Garuda_API import *
from Lib_General import *
##from Lib_VSA import *

##import time
##import array
##from ctypes import *
##from Lib_Garuda_API import *
##from Lib_Meter_EAT import *

#############################Global Variables##################################
ClsGeneral = General()
Alive_Cntr_164 = 0
Checksum_164 = 0
MTR_164_data = [0, 0, 0, 0, 0, 0, 0, 0]

Alive_Cntr_1A6 = 0
Checksum_1A6 = 0
MTR_1A6_data = [0, 0, 0, 0, 0, 0, 0, 0]

Alive_Cntr_294 = 0
Checksum_294 = 0
MTR_294_data = [0, 0, 0, 0, 0, 0, 0, 0]

Alive_Cntr_309 = 0
Checksum_309 = 0
MTR_309_data = [0, 0, 0, 0, 0, 0, 0, 0]

Alive_Cntr_374 = 0
Checksum_374 = 0
MTR_374_data = [0, 0, 0, 0, 0, 0, 0]

# EAT node Variables
Alive_Cntr_158 = 0
Checksum_158 = 0
EAT_158_data = [0, 0, 0, 0, 0, 0, 0, 0]

Alive_Cntr_188 = 0
Checksum_188 = 0
EAT_188_data = [0, 0, 0, 0, 0, 0]

###########################Function Defnitions#################################


def CalcAliveCntr164():
    flCntr = 0
    global Alive_Cntr_164
    flCntr = Alive_Cntr_164
    Alive_Cntr_164 += 1

    if Alive_Cntr_164 == 4:
        Alive_Cntr_164 = 0

    return flCntr


def CalcAliveCntr1A6():
    flCntr = 0
    global Alive_Cntr_1A6
    flCntr = Alive_Cntr_1A6
    Alive_Cntr_1A6 += 1

    if Alive_Cntr_1A6 == 4:
        Alive_Cntr_1A6 = 0

    return flCntr


def CalcAliveCntr294():
    flCntr = 0
    global Alive_Cntr_294

    flCntr = Alive_Cntr_294
    Alive_Cntr_294 += 1

    if Alive_Cntr_294 == 4:
        Alive_Cntr_294 = 0

    return flCntr


def CalcAliveCntr309():
    flCntr = 0
    global Alive_Cntr_309

    flCntr = Alive_Cntr_309
    Alive_Cntr_309 += 1

    if Alive_Cntr_309 == 4:
        Alive_Cntr_309 = 0

    return flCntr


def CalcAliveCntr374():
    flCntr = 0
    global Alive_Cntr_374

    flCntr = Alive_Cntr_374
    Alive_Cntr_374 += 1

    if Alive_Cntr_374 == 4:
        Alive_Cntr_374 = 0

    return flCntr


def CalcAliveCntr158():
    flCntr = 0
    global Alive_Cntr_158
    flCntr = Alive_Cntr_158
    Alive_Cntr_158 += 1

    if Alive_Cntr_158 == 4:
        Alive_Cntr_158 = 0

    return flCntr


def CalcAliveCntr188():
    flCntr = 0
    global Alive_Cntr_188
    flCntr = Alive_Cntr_188
    Alive_Cntr_188 += 1

    if Alive_Cntr_188 == 4:
        Alive_Cntr_188 = 0

    return flCntr


def Calc_Checksum_164():

    global Checksum_164
    global MTR_164_data
    cntr = CalcAliveCntr164()
    Checksum_164 = 0x10 - ((0x08 + 0x01 + 0x06 + 0x04 +
                            (MTR_164_data[0] & 0x0F) + ((MTR_164_data[0] & 0xF0) >> 4) +
                            (MTR_164_data[1] & 0x0F) + ((MTR_164_data[1] & 0xF0) >> 4) +
                            (MTR_164_data[2] & 0x0F) + ((MTR_164_data[2] & 0xF0) >> 4) +
                            (MTR_164_data[3] & 0x0F) + ((MTR_164_data[3] & 0xF0) >> 4) +
                            (MTR_164_data[4] & 0x0F) + ((MTR_164_data[4] & 0xF0) >> 4) +
                            (MTR_164_data[5] & 0x0F) + ((MTR_164_data[5] & 0xF0) >> 4) +
                            (MTR_164_data[6] & 0x0F) + ((MTR_164_data[6] & 0xF0) >> 4) +
                            ((MTR_164_data[7] & 0xC0) >> 4) + cntr) & 0x000F)

    temp = (cntr * 0x10) + Checksum_164
    MTR_164_data[7] = (MTR_164_data[7] & 0xC0) | temp
    return Checksum_164


def Calc_Checksum_1A6():

    global Checksum_1A6
    global MTR_1A6_data
    cntr = CalcAliveCntr1A6()
    Checksum_1A6 = 0x10 - ((0x08 + 0x01 + 0x0A + 0x06 +
                            (MTR_1A6_data[0] & 0x0F) + ((MTR_1A6_data[0] & 0xF0) >> 4) +
                            (MTR_1A6_data[1] & 0x0F) + ((MTR_1A6_data[1] & 0xF0) >> 4) +
                            (MTR_1A6_data[2] & 0x0F) + ((MTR_1A6_data[2] & 0xF0) >> 4) +
                            (MTR_1A6_data[3] & 0x0F) + ((MTR_1A6_data[3] & 0xF0) >> 4) +
                            (MTR_1A6_data[4] & 0x0F) + ((MTR_1A6_data[4] & 0xF0) >> 4) +
                            (MTR_1A6_data[5] & 0x0F) + ((MTR_1A6_data[5] & 0xF0) >> 4) +
                            (MTR_1A6_data[6] & 0x0F) + ((MTR_1A6_data[6] & 0xF0) >> 4) +
                            ((MTR_1A6_data[7] & 0xC0) >> 4) + cntr) & 0x000F)

    temp = (cntr * 0x10) + Checksum_1A6
    MTR_1A6_data[7] = (MTR_1A6_data[7] & 0xC0) | temp

    return Checksum_1A6


def Calc_Checksum_294():

    global Checksum_294
    global MTR_294_data
    cntr = CalcAliveCntr294()

    Checksum_294 = 0x10 - ((0x08 + 0x02 + 0x09 + 0x04 +
                            (MTR_294_data[0] & 0x0F) + ((MTR_294_data[0] & 0xF0) >> 4) +
                            (MTR_294_data[1] & 0x0F) + ((MTR_294_data[1] & 0xF0) >> 4) +
                            (MTR_294_data[2] & 0x0F) + ((MTR_294_data[2] & 0xF0) >> 4) +
                            (MTR_294_data[3] & 0x0F) + ((MTR_294_data[3] & 0xF0) >> 4) +
                            (MTR_294_data[4] & 0x0F) + ((MTR_294_data[4] & 0xF0) >> 4) +
                            (MTR_294_data[5] & 0x0F) + ((MTR_294_data[5] & 0xF0) >> 4) +
                            (MTR_294_data[6] & 0x0F) + ((MTR_294_data[6] & 0xF0) >> 4) +
                            ((MTR_294_data[7] & 0xC0) >> 4) + cntr) & 0x000F)

    temp = (cntr * 0x10) + Checksum_294
    MTR_294_data[7] = (MTR_294_data[7] & 0xC0) | temp

    return Checksum_294


def Calc_Checksum_309():

    global Checksum_309
    global MTR_309_data
    cntr = CalcAliveCntr309()

    Checksum_309 = 0x10 - ((0x08 + 0x03 + 0x00 + 0x09 +
                            (MTR_309_data[0] & 0x0F) + ((MTR_309_data[0] & 0xF0) >> 4) +
                            (MTR_309_data[1] & 0x0F) + ((MTR_309_data[1] & 0xF0) >> 4) +
                            (MTR_309_data[2] & 0x0F) + ((MTR_309_data[2] & 0xF0) >> 4) +
                            (MTR_309_data[3] & 0x0F) + ((MTR_309_data[3] & 0xF0) >> 4) +
                            (MTR_309_data[4] & 0x0F) + ((MTR_309_data[4] & 0xF0) >> 4) +
                            (MTR_309_data[5] & 0x0F) + ((MTR_309_data[5] & 0xF0) >> 4) +
                            (MTR_309_data[6] & 0x0F) + ((MTR_309_data[6] & 0xF0) >> 4) +
                            ((MTR_309_data[7] & 0xC0) >> 4) + cntr) & 0x000F)

    temp = (cntr * 0x10) + Checksum_309
    MTR_309_data[7] = (MTR_309_data[7] & 0xC0) | temp

    return Checksum_309


def Calc_Checksum_374():

    global Checksum_374
    global MTR_374_data
    cntr = CalcAliveCntr374()

    Checksum_374 = 0x10 - ((0x08 + 0x03 + 0x07 + 0x04 +
                            (MTR_374_data[0] & 0x0F) + ((MTR_374_data[0] & 0xF0) >> 4) +
                            (MTR_374_data[1] & 0x0F) + ((MTR_374_data[1] & 0xF0) >> 4) +
                            (MTR_374_data[2] & 0x0F) + ((MTR_374_data[2] & 0xF0) >> 4) +
                            (MTR_374_data[3] & 0x0F) + ((MTR_374_data[3] & 0xF0) >> 4) +
                            (MTR_374_data[4] & 0x0F) + ((MTR_374_data[4] & 0xF0) >> 4) +
                            (MTR_374_data[5] & 0x0F) + ((MTR_374_data[5] & 0xF0) >> 4) +
                            ((MTR_374_data[6] & 0xC0) >> 4) + cntr) & 0x000F)

    temp = (cntr * 0x10) + Checksum_374
    MTR_374_data[6] = (MTR_374_data[6] & 0xC0) | temp

    return Checksum_374


def Calc_Checksum_158():

    global Checksum_158
    global EAT_158_data
    cntr = CalcAliveCntr158()

    Checksum_158 = 0x10 - ((0x08 + 0x01 + 0x05 + 0x08 +
                            (EAT_158_data[0] & 0x0F) + ((EAT_158_data[0] & 0xF0) >> 4) +
                            (EAT_158_data[1] & 0x0F) + ((EAT_158_data[1] & 0xF0) >> 4) +
                            (EAT_158_data[2] & 0x0F) + ((EAT_158_data[2] & 0xF0) >> 4) +
                            (EAT_158_data[3] & 0x0F) + ((EAT_158_data[3] & 0xF0) >> 4) +
                            (EAT_158_data[4] & 0x0F) + ((EAT_158_data[4] & 0xF0) >> 4) +
                            (EAT_158_data[5] & 0x0F) + ((EAT_158_data[5] & 0xF0) >> 4) +
                            (EAT_158_data[6] & 0x0F) + ((EAT_158_data[6] & 0xF0) >> 4) +
                            ((EAT_158_data[7] & 0xC0) >> 4) + cntr) & 0x000F)

    temp = (cntr * 0x10) + Checksum_158
    EAT_158_data[7] = (EAT_158_data[7] & 0xC0) | temp

    return Checksum_158


def Calc_Checksum_188():

    global Checksum_188
    global EAT_188_data
    cntr = CalcAliveCntr188()

    Checksum_188 = 0x10 - ((0x08 + 0x01 + 0x08 + 0x08 +
                            (EAT_188_data[0] & 0x0F) + ((EAT_188_data[0] & 0xF0) >> 4) +
                            (EAT_188_data[1] & 0x0F) + ((EAT_188_data[1] & 0xF0) >> 4) +
                            (EAT_188_data[2] & 0x0F) + ((EAT_188_data[2] & 0xF0) >> 4) +
                            (EAT_188_data[3] & 0x0F) + ((EAT_188_data[3] & 0xF0) >> 4) +
                            (EAT_188_data[4] & 0x0F) + ((EAT_188_data[4] & 0xF0) >> 4) +
                            ((EAT_188_data[5] & 0xC0) >> 4) + cntr) & 0x000F)

    temp = (cntr * 0x10) + Checksum_188
    EAT_188_data[5] = (EAT_188_data[5] & 0xC0) | temp

    return Checksum_188


def Send_Msg_164():
    global MTR_164_data
    Calc_Checksum_164()
    data_id = [0x00, 0x00, 0x01, 0x64]
    data_id.extend(MTR_164_data)
    byte_arr = bytearray(data_id)
    data_bytes = (c_ubyte * 4128)(*(byte_arr))
    pMsg = PassThru_Msg(0x05, 0, 0, 0, 12, 12, data_bytes)
    NumMsgs = c_ulong(1)
    Timeout = 0
    ret_value = dev.lib.PassThruWriteMsgs(dev.ChannelId, byref(pMsg),
                                          byref(NumMsgs), Timeout)
    if(not ret_value):
        pass
#            print "Message is sent"
    else:
        print "Message 164 not sent ", ret_value
        sys.exit(0)

    return

##x = raw_input("Enter to Continue")
def Send_Msg_1A6():
    global MTR_1A6_data
    Calc_Checksum_1A6()
    data_id = [0x00, 0x00, 0x01, 0xA6]
    data_id.extend(MTR_1A6_data)
    byte_arr = bytearray(data_id)
    data_bytes = (c_ubyte * 4128)(*(byte_arr))
    pMsg = PassThru_Msg(0x05, 0, 0, 0, 12, 12, data_bytes)
    NumMsgs = c_ulong(1)
    Timeout = 0
    ret_value = dev.lib.PassThruWriteMsgs(dev.ChannelId, byref(pMsg),
                                          byref(NumMsgs), Timeout)
    if(not ret_value):
        pass
#            print "Message is sent"
    else:
        print "Message 1A6 not sent ", ret_value
        sys.exit(0)

    return


def Send_Msg_294():
    global MTR_294_data
    Calc_Checksum_294()
    data_id = [0x00, 0x00, 0x02, 0x94]
    data_id.extend(MTR_294_data)
    byte_arr = bytearray(data_id)
    data_bytes = (c_ubyte * 4128)(*(byte_arr))
    pMsg = PassThru_Msg(0x05, 0, 0, 0, 12, 12, data_bytes)
    NumMsgs = c_ulong(1)
    Timeout = 0
    ret_value = dev.lib.PassThruWriteMsgs(dev.ChannelId, byref(pMsg),
                                          byref(NumMsgs), Timeout)
    if(not ret_value):
        pass
#            print "Message is sent"
    else:
        print "Message 294 not sent ", ret_value
        sys.exit(0)
    return


def Send_Msg_309():
    global MTR_309_data
    Calc_Checksum_309()
    data_id = [0x00, 0x00, 0x03, 0x09]
    data_id.extend(MTR_309_data)
    byte_arr = bytearray(data_id)
    data_bytes = (c_ubyte * 4128)(*(byte_arr))
    pMsg = PassThru_Msg(0x05, 0, 0, 0, 12, 12, data_bytes)
    NumMsgs = c_ulong(1)
    Timeout = 0
    ret_value = dev.lib.PassThruWriteMsgs(dev.ChannelId, byref(pMsg),
                                          byref(NumMsgs), Timeout)
    if(not ret_value):
        pass
#            print "Message is sent"
    else:
        print "Message 309 not sent ", ret_value
        sys.exit(0)
    return


def Send_Msg_374():
    global MTR_374_data
    Calc_Checksum_374()
    data_id = [0x00, 0x00, 0x03, 0x74]
    data_id.extend(MTR_374_data)
    byte_arr = bytearray(data_id)
    data_bytes = (c_ubyte * 4128)(*(byte_arr))
    pMsg = PassThru_Msg(0x05, 0, 0, 0, 11, 11, data_bytes)
    NumMsgs = c_ulong(1)
    Timeout = 0
    ret_value = dev.lib.PassThruWriteMsgs(dev.ChannelId, byref(pMsg),
                                          byref(NumMsgs), Timeout)
    if(not ret_value):
        pass
#            print "Message is sent"

    else:
        print "Message 374 not sent ", ret_value
        sys.exit(0)

    return


def Send_Msg_158():
    global EAT_158_data
    Calc_Checksum_158()
    data_id = [0x00, 0x00, 0x01, 0x58]
    data_id.extend(EAT_158_data)
    byte_arr = bytearray(data_id)
    data_bytes = (c_ubyte * 4128)(*(byte_arr))
    pMsg = PassThru_Msg(0x05, 0, 0, 0, 12, 12, data_bytes)
    NumMsgs = c_ulong(1)
    Timeout = 0
    ret_value = dev.lib.PassThruWriteMsgs(dev.ChannelId, byref(pMsg),
                                          byref(NumMsgs), Timeout)
    if(not ret_value):
        pass
#            print "Message is sent"

    else:
        print "Message 158 not sent ", ret_value
        sys.exit(0)

    return


def Send_Msg_188():
    global EAT_188_data
    Calc_Checksum_188()
    data_id = [0x00, 0x00, 0x01, 0x88]
    data_id.extend(EAT_188_data)
    byte_arr = bytearray(data_id)
    data_bytes = (c_ubyte * 4128)(*(byte_arr))
    pMsg = PassThru_Msg(0x05, 0, 0, 0, 10, 10, data_bytes)
    NumMsgs = c_ulong(1)
    Timeout = 0
    ret_value = dev.lib.PassThruWriteMsgs(dev.ChannelId, byref(pMsg),
                                          byref(NumMsgs), Timeout)
    if(not ret_value):
        pass
#            print "Message is sent"

    else:
        print "Message 188 not sent ", ret_value
        sys.exit(0)

    return


def set_speed(speed):
    ##    ClsGeneral.logInfo("Required speed for this test is: " + str(speed))
    global EAT_158_data
    global MTR_309_data
    print "set_speed"
    speed = speed / 0.01
    EAT_158_data[5] = int(speed % 0x100)
    MTR_309_data[5] = int(speed % 0x100)
    EAT_158_data[4] = int(speed / 0x100)
    MTR_309_data[4] = int(speed / 0x100)


def set_indicator(side):
    '''
    This Function Will set the Indicator signal Values based on:
    side = 0 : Both Indicators Off
    side = 1 : Right Indicator On
    side = 2 : Left Indicator On
    side = 3 : Both Indicator On
    '''
    global MTR_294_data
    if not side:
        MTR_294_data[0] = 0x00
    elif side == 0x1:
        MTR_294_data[0] = 0x40
    elif side == 0x2:
        MTR_294_data[0] = 0x20
    elif side == 0x3:
        MTR_294_data[0] = 0x60


def stop_Meter_EAT():

    set_speed(00)
    set_indicator(0)
    time.sleep(1.5)

    MTR_164.stop()
    MTR_1A6.stop()
    MTR_294.stop()
    MTR_309.stop()
    MTR_374.stop()

    EAT_158.stop()
    EAT_188.stop()

print "in METER EAT"

dllpath = "F:\\Rahul\\Garuda40432.dll"
dev = Garuda(dllpath, ProtocolId=0x05, Flags=1 << 11 | 1 << 8, BaudRate=500000)
##time.sleep (10)
dev.clear_buffer([7, 8, 9])

set_speed(0)
set_indicator(0)
##sys.exit(0)

MTR_164 = dev.send_periodic_msg(Send_Msg_164, 10)
MTR_1A6 = dev.send_periodic_msg(Send_Msg_1A6, 20)
MTR_294 = dev.send_periodic_msg(Send_Msg_294, 40)
MTR_309 = dev.send_periodic_msg(Send_Msg_309, 100)
MTR_374 = dev.send_periodic_msg(Send_Msg_374, 100)
EAT_158 = dev.send_periodic_msg(Send_Msg_158, 10)
EAT_188 = dev.send_periodic_msg(Send_Msg_188, 10)


'''
additional code
'''




###########################Built-in Libraries##################################
##import time
##import array
##from ctypes import *
##from Lib_Garuda_API import *
##from Lib_Meter_EAT import *

#############################Global Variables##################################

Alive_Cntr_091 = 0
Checksum_091 = 0
VSA_091_data = [0, 0, 0, 0, 0, 0, 0, 0]

Alive_Cntr_1A4 = 0
Checksum_1A4 = 0
VSA_1A4_data = [0, 0, 0, 0, 0, 0, 0, 0]

Alive_Cntr_1B0 = 0
Checksum_1B0 = 0
VSA_1B0_data = [0, 0, 0, 0, 0, 0, 0, 0]

Alive_Cntr_1D0 = 0
Checksum_1D0 = 0
VSA_1D0_data = [0, 0, 0, 0, 0, 0, 0, 0]

Alive_Cntr_1AA = 0
Checksum_1AA = 0
VSA_1AA_data = [0, 0, 0, 0, 0, 0, 0, 0]

# STR node variables

Alive_Cntr_156 = 0
ChkSumVal_156 = 0
STR_156_data = [0, 0, 0, 0, 0, 0, 0, 0]

print "test in VSA"
###########################Function Defnitions#################################

def CalcAliveCntr091():
    flCntr = 0
# print "test3"
    global Alive_Cntr_091
# print "test4"
    flCntr = Alive_Cntr_091
    Alive_Cntr_091 += 1

    if Alive_Cntr_091 == 4:
        Alive_Cntr_091 = 0

    return flCntr


def CalcAliveCntr1A4():
    flCntr = 0
    global Alive_Cntr_1A4
    flCntr = Alive_Cntr_1A4
    Alive_Cntr_1A4 += 1

    if Alive_Cntr_1A4 == 4:
        Alive_Cntr_1A4 = 0

    return flCntr


def CalcAliveCntr1B0():
    flCntr = 0
    global Alive_Cntr_1B0
    flCntr = Alive_Cntr_1B0
    Alive_Cntr_1B0 += 1

    if Alive_Cntr_1B0 == 4:
        Alive_Cntr_1B0 = 0

    return flCntr


def CalcAliveCntr1D0():
    flCntr = 0
    global Alive_Cntr_1D0
    flCntr = Alive_Cntr_1D0
    Alive_Cntr_091 += 1

    if Alive_Cntr_1D0 == 4:
        Alive_Cntr_1D0 = 0

    return flCntr


def CalcAliveCntr1AA():
    flCntr = 0
    global Alive_Cntr_1AA
    flCntr = Alive_Cntr_1AA
    Alive_Cntr_1AA += 1

    if Alive_Cntr_1AA == 4:
        Alive_Cntr_1AA = 0

    return flCntr


def CalcAliveCntr156():
    flCntr = 0
    global Alive_Cntr_156
    flCntr = Alive_Cntr_156
    Alive_Cntr_156 += 1

    if Alive_Cntr_156 == 4:
        Alive_Cntr_156 = 0

    return flCntr


def Calc_Checksum_091():

    global Checksum_091
    global VSA_091_data
# print "test2"
    cntr = CalcAliveCntr091()
# print "test1"
    Checksum_091 = 0x10 - ((0x08 + 0x09 + 0x01 +
                            (VSA_091_data[0] & 0x0F) + ((VSA_091_data[0] & 0xF0) >> 4) +
                            (VSA_091_data[1] & 0x0F) + ((VSA_091_data[1] & 0xF0) >> 4) +
                            (VSA_091_data[2] & 0x0F) + ((VSA_091_data[2] & 0xF0) >> 4) +
                            (VSA_091_data[3] & 0x0F) + ((VSA_091_data[3] & 0xF0) >> 4) +
                            (VSA_091_data[4] & 0x0F) + ((VSA_091_data[4] & 0xF0) >> 4) +
                            (VSA_091_data[5] & 0x0F) + ((VSA_091_data[5] & 0xF0) >> 4) +
                            (VSA_091_data[6] & 0x0F) + ((VSA_091_data[6] & 0xF0) >> 4) +
                            ((VSA_091_data[7] & 0xC0) >> 4) + cntr) & 0x000F)

    temp = (cntr * 0x10) + Checksum_091
    VSA_091_data[7] = (VSA_091_data[7] & 0xC0) | temp
    return Checksum_091


def Calc_Checksum_1A4():

    global Checksum_1A4
    global VSA_1A4_data
    cntr = CalcAliveCntr1A4()
    Checksum_1A4 = 0x10 - ((0x08 + 0x01 + 0x0A + 0x04 +
                            (VSA_1A4_data[0] & 0x0F) + ((VSA_1A4_data[0] & 0xF0) >> 4) +
                            (VSA_1A4_data[1] & 0x0F) + ((VSA_1A4_data[1] & 0xF0) >> 4) +
                            (VSA_1A4_data[2] & 0x0F) + ((VSA_1A4_data[2] & 0xF0) >> 4) +
                            (VSA_1A4_data[3] & 0x0F) + ((VSA_1A4_data[3] & 0xF0) >> 4) +
                            (VSA_1A4_data[4] & 0x0F) + ((VSA_1A4_data[4] & 0xF0) >> 4) +
                            (VSA_1A4_data[5] & 0x0F) + ((VSA_1A4_data[5] & 0xF0) >> 4) +
                            (VSA_1A4_data[6] & 0x0F) + ((VSA_1A4_data[6] & 0xF0) >> 4) +
                            ((VSA_1A4_data[7] & 0xC0) >> 4) + cntr) & 0x000F)

    temp = (cntr * 0x10) + Checksum_1A4
    VSA_1A4_data[7] = (VSA_1A4_data[7] & 0xC0) | temp
    return Checksum_1A4


def Calc_Checksum_1B0():

    global Checksum_1B0
    global VSA_1B0_data
    cntr = CalcAliveCntr1B0()
    Checksum_1B0 = 0x10 - ((0x08 + 0x01 + 0x0B + 0x00 +
                            (VSA_1B0_data[0] & 0x0F) + ((VSA_1B0_data[0] & 0xF0) >> 4) +
                            (VSA_1B0_data[1] & 0x0F) + ((VSA_1B0_data[1] & 0xF0) >> 4) +
                            (VSA_1B0_data[2] & 0x0F) + ((VSA_1B0_data[2] & 0xF0) >> 4) +
                            (VSA_1B0_data[3] & 0x0F) + ((VSA_1B0_data[3] & 0xF0) >> 4) +
                            (VSA_1B0_data[4] & 0x0F) + ((VSA_1B0_data[4] & 0xF0) >> 4) +
                            (VSA_1B0_data[5] & 0x0F) + ((VSA_1B0_data[5] & 0xF0) >> 4) +
                            ((VSA_1B0_data[6] & 0xC0) >> 4) + cntr) & 0x000F)

    temp = (cntr * 0x10) + Checksum_1B0
    VSA_1B0_data[6] = (VSA_1B0_data[6] & 0xC0) | temp
    return Checksum_1B0


def Calc_Checksum_1D0():

    global Checksum_1D0
    global VSA_1D0_data
##    cntr = CalcAliveCntr1D0()
    Checksum_1D0 = 0x10 - ((0x08 + 0x01 + 0x0D + 0x00 +
                            (VSA_1D0_data[0] & 0x0F) + ((VSA_1D0_data[0] & 0xF0) >> 4) +
                            (VSA_1D0_data[1] & 0x0F) + ((VSA_1D0_data[1] & 0xF0) >> 4) +
                            (VSA_1D0_data[2] & 0x0F) + ((VSA_1D0_data[2] & 0xF0) >> 4) +
                            (VSA_1D0_data[3] & 0x0F) + ((VSA_1D0_data[3] & 0xF0) >> 4) +
                            (VSA_1D0_data[4] & 0x0F) + ((VSA_1D0_data[4] & 0xF0) >> 4) +
                            (VSA_1D0_data[5] & 0x0F) + ((VSA_1D0_data[5] & 0xF0) >> 4) +
                            (VSA_1D0_data[6] & 0x0F) + ((VSA_1D0_data[6] & 0xF0) >> 4) +
                            (VSA_1D0_data[7] & 0xF0) >> 4) & 0x000F)

##     temp = (cntr * 0x10 ) + Checksum_1D0
    VSA_1D0_data[7] = (VSA_1D0_data[7] & 0xC0)
    return Checksum_1D0


def Calc_Checksum_1AA():

    global Checksum_1AA
    global VSA_1AA_data
    cntr = CalcAliveCntr1AA()
    Checksum_1AA = 0x10 - ((0x08 + 0x01 + 0x0A + 0x0A +
                            (VSA_1AA_data[0] & 0x0F) + ((VSA_1AA_data[0] & 0xF0) >> 4) +
                            (VSA_1AA_data[1] & 0x0F) + ((VSA_1AA_data[1] & 0xF0) >> 4) +
                            (VSA_1AA_data[2] & 0x0F) + ((VSA_1AA_data[2] & 0xF0) >> 4) +
                            (VSA_1AA_data[3] & 0x0F) + ((VSA_1AA_data[3] & 0xF0) >> 4) +
                            (VSA_1AA_data[4] & 0x0F) + ((VSA_1AA_data[4] & 0xF0) >> 4) +
                            (VSA_1AA_data[5] & 0x0F) + ((VSA_1AA_data[5] & 0xF0) >> 4) +
                            (VSA_1AA_data[6] & 0x0F) + ((VSA_1AA_data[6] & 0xF0) >> 4) +
                            ((VSA_1AA_data[7] & 0xC0) >> 4) + cntr) & 0x000F)

    temp = (cntr * 0x10) + Checksum_1AA
    VSA_1AA_data[7] = (VSA_1AA_data[7] & 0xC0) | temp
    return Checksum_1AA


def Calc_Checksum_156():

    global Checksum_156
    global STR_156_data
    cntr = CalcAliveCntr156()
    Checksum_156 = 0x10 - ((0x08 + 0x01 + 0x05 + 0x06 +
                            (STR_156_data[0] & 0x0F) + ((STR_156_data[0] & 0xF0) >> 4) +
                            (STR_156_data[1] & 0x0F) + ((STR_156_data[1] & 0xF0) >> 4) +
                            (STR_156_data[2] & 0x0F) + ((STR_156_data[2] & 0xF0) >> 4) +
                            (STR_156_data[3] & 0x0F) + ((STR_156_data[3] & 0xF0) >> 4) +
                            (STR_156_data[4] & 0x0F) + ((STR_156_data[4] & 0xF0) >> 4) +
                            ((STR_156_data[5] & 0xC0) + cntr) & 0x000F))

    temp = (cntr * 0x10) + Checksum_091
    VSA_091_data[7] = (STR_156_data[5] & 0xC0) | temp
    return Checksum_156


def Send_Msg_091():
    global VSA_091_data
# print "test"
    Calc_Checksum_091()
# print "test"
    data_id = [0x00, 0x00, 0x00, 0x91]
    data_id.extend(VSA_091_data)
    byte_arr = bytearray(data_id)
    data_bytes = (c_ubyte * 4128)(*(byte_arr))
    pMsg = PassThru_Msg(0x05, 0, 0, 0, 12, 12, data_bytes)
    NumMsgs = c_ulong(1)
    Timeout = 0
    ret_value = dev.lib.PassThruWriteMsgs(dev.ChannelId, byref(pMsg),
                                          byref(NumMsgs), Timeout)
    if(not ret_value):
        pass
#            print "Message is sent"
    else:
        print "Message 091 not sent ", ret_value
        sys.exit(0)


def Send_Msg_1A4():
    global VSA_1A4_data
##    sys.exit(0)
    Calc_Checksum_1A4()
    data_id = [0x00, 0x00, 0x01, 0xA4]
    data_id.extend(VSA_1A4_data)
    byte_arr = bytearray(data_id)
    data_bytes = (c_ubyte * 4128)(*(byte_arr))
    pMsg = PassThru_Msg(0x05, 0, 0, 0, 12, 12, data_bytes)
##    print pMsg
    NumMsgs = c_ulong(1)
    Timeout = 0
    ret_value = dev.lib.PassThruWriteMsgs(dev.ChannelId, byref(pMsg),
                                          byref(NumMsgs), Timeout)
    if(not ret_value):
        pass
##        print "Message is sent"
    else:
        print "Message 1A4 not sent ", ret_value
        sys.exit(0)


def Send_Msg_1B0():
    global VSA_1B0_data
    Calc_Checksum_1B0()
    data_id = [0x00, 0x00, 0x01, 0xB0]
    data_id.extend(VSA_1B0_data)
    byte_arr = bytearray(data_id)
    data_bytes = (c_ubyte * 4128)(*(byte_arr))
    pMsg = PassThru_Msg(0x05, 0, 0, 0, 11, 11, data_bytes)
    NumMsgs = c_ulong(1)
    Timeout = 0
    ret_value = dev.lib.PassThruWriteMsgs(dev.ChannelId, byref(pMsg),
                                          byref(NumMsgs), Timeout)
    if(not ret_value):
        pass
#            print "Message is sent"
    else:
        print "Message 1B0 not sent ", ret_value
        sys.exit(0)


def Send_Msg_1D0():
    global VSA_1D0_data
    Calc_Checksum_1D0()
    data_id = [0x00, 0x00, 0x01, 0xD0]
    data_id.extend(VSA_1D0_data)
    byte_arr = bytearray(data_id)
    data_bytes = (c_ubyte * 4128)(*(byte_arr))
    pMsg = PassThru_Msg(0x05, 0, 0, 0, 12, 12, data_bytes)
    NumMsgs = c_ulong(1)
    Timeout = 0
    ret_value = dev.lib.PassThruWriteMsgs(dev.ChannelId, byref(pMsg),
                                          byref(NumMsgs), Timeout)
    if(not ret_value):
        pass
#            print "Message is sent"
    else:
        print "Message 1D0 not sent ", ret_value
        sys.exit(0)


def Send_Msg_1AA():
    global VSA_1AA_data
    Calc_Checksum_1AA()
    data_id = [0x00, 0x00, 0x01, 0xAA]
    data_id.extend(VSA_1AA_data)
    byte_arr = bytearray(data_id)
    data_bytes = (c_ubyte * 4128)(*(byte_arr))
    pMsg = PassThru_Msg(0x05, 0, 0, 0, 12, 12, data_bytes)
    NumMsgs = c_ulong(1)
    Timeout = 0
    ret_value = dev.lib.PassThruWriteMsgs(dev.ChannelId, byref(pMsg),
                                          byref(NumMsgs), Timeout)
    if(not ret_value):
        pass
#            print "Message is sent"
    else:
        print "Message 1AA not sent ", ret_value
        sys.exit(0)


def Send_Msg_156():
    global STR_156_data
    Calc_Checksum_156()
    data_id = [0x00, 0x00, 0x01, 0x56]
    data_id.extend(STR_156_data)
    byte_arr = bytearray(data_id)
    data_bytes = (c_ubyte * 4128)(*(byte_arr))
    pMsg = PassThru_Msg(0x05, 0, 0, 0, 10, 10, data_bytes)
    NumMsgs = c_ulong(1)
    Timeout = 0
    ret_value = dev.lib.PassThruWriteMsgs(dev.ChannelId, byref(pMsg),
                                          byref(NumMsgs), Timeout)
    if(not ret_value):
        pass
#            print "Message is sent"
    else:
        print "Message 156 not sent ", ret_value
        sys.exit(0)
        


def set_cylinder_pressure(pressure):
    global VSA_1A4_data
##    pressure = int(pressure)
    pressure *= 24
    VSA_1A4_data[4] = (VSA_1A4_data[4] & 0xF0) | (pressure & 0x0F)
    VSA_1A4_data[5] = (pressure >> 4) & 0xFF
##    print "data[4],data[5]\n", VSA_1A4_data[4], VSA_1A4_data[5]

# def set_cylinder_pressure(pressure):
##    global VSA_1A4_data
##    pressure = int(pressure)



def set_brake_pressure(brake_pressure):
    global VSA_1A4_data
    VSA_1A4_data[6] = brake_pressure
    
def set_VSA_VSA_TCS_ACT(bit) :
    global VSA_1A4_data
    print "bef VSA_1A4_data[6] = ",VSA_1A4_data[2]
    VSA_1A4_data[2] |= bit
    print "aftr VSA_1A4_data[6] = ",VSA_1A4_data[2]
    
def set_angle(angle):
    global STR_156_data
    VSA_1A4_data[5] = int (angle)
    VSA_1A4_data[6] = int (angle)
    print "angle set"



def stop_VSA_STR():

    set_cylinder_pressure (00)
    set_angle(0)
    time.sleep(1.5)

    VSA_091.stop()
    VSA_1A4.stop()
    VSA_1B0.stop()
    VSA_1D0.stop()
    VSA_1AA.stop()
    STR_156.stop()


VSA_091 = dev.send_periodic_msg(Send_Msg_091, 10)
VSA_1A4 = dev.send_periodic_msg(Send_Msg_1A4, 20)
VSA_1B0 = dev.send_periodic_msg(Send_Msg_1B0, 20)
VSA_1D0 = dev.send_periodic_msg(Send_Msg_1D0, 20)
VSA_1AA = dev.send_periodic_msg(Send_Msg_1AA, 20)
STR_156 = dev.send_periodic_msg(Send_Msg_156, 10)

