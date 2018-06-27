###############################################################################
# Test Case ID   :
# Discription    :
# Created Date   : 16-June-2016
# Author         : Ganesh Dixit
# Modified by    : -
# Modified Date  : -
###########################Built-in Libraries##################################
import threading
import time
import ctypes
import sys
from Lib_General import *
##########################Structure Defnitions#################################
ClsGeneral = General()


class PassThru_Msg(ctypes.Structure):
    '''
     ProtocolID = 0x05 (for CAN) or 0x06 (ISO 15765)
     RxStatus = 0( 11 bit ID) or 1 (29 bit ID)
     TxFlags  = 0( 11 bit ID) or 1 (29 bit ID)
     TimeStamp  (in MicroSeconds)
     DataSize (in Bytes including ID)
     Data = Array of Data Bytes
    '''
    _fields_ = [("ProtocolID", ctypes.c_ulong),
                ("RxStatus", ctypes.c_uint),
                ("TxFlags", ctypes.c_ulong),
                ("TimeStamp", ctypes.c_ulong),
                ("DataSize", ctypes.c_uint),
                ("ExtraDataIndex", ctypes.c_ulong),
                ("Data", ctypes.c_ubyte * 4128)]


class conversions:

    def __init__(self):
        pass

    def expand_Id(self, MsgId):
        Id = []
        for i in xrange(4):
            Id.insert(0, MsgId % 0x100)
            MsgId = int(MsgId / 0x100)
        return Id
    
    def expand_data(self, data):
        data_list = []
        for i in xrange(8):
            data_list.insert(0, data % 0x100)
            data = int(data / 0x100)        
        return data_list
    
    '''    
    def expand_data(self, data):
        data_list = []
##        var = 0x100000000000000
        for i in xrange(8):
            data_list.insert(0, (data >> 8 * (7 - i)) & 0xff)
        print "data in expand method",data_list
        return data_list
    '''
    
    def merge_id_data(self, pMsg):
        Id = 0
        data = 0
        for i in xrange(12):
            if i < 4:
                Id = Id * (0x100) + pMsg.Data[i]
            else:
                data = data * (0x100) + pMsg.Data[i]
##        print "Id in merge id\n",Id
##        print "Id in merge data\n",data
        return [Id, data]


class MyThread(threading.Thread):

    def __init__(self, Target=None, Time_period=0):
        threading.Thread.__init__(self)
        self.stop_msg = 0
        self.fun = Target
        self.period = Time_period / 1000.0

    def run(self):
        while not self.stop_msg:
            self.fun()
            time.sleep(self.period)

    def stop(self):
        '''
        Stops execution of thread
        '''
        self.stop_msg = 1


class Garuda():
    def __init__(self, dllpath, ProtocolId, Flags, BaudRate):
        '''
        Intialises the Garuda Device.
        \nIf already Connected provide DeviceID and ChannelId.
        \nElse __init__ will get DeviceID and ChannelId
        \ndllpath: Path of Garuda Dll to load
        \nProtocolId: Protocol to be used (For More details go through "J2534" \
        \nProtocol's "PassThruConnect()")
        \nFlags: For More details go through "J2534" Protocol's "PassThruConnect()"
        \nBaudRate: Baudrate of the Communication Channel

        '''
        self.DeviceId = ctypes.c_ulong()
        self.ChannelId = ctypes.c_ulong()
        self.ProtocolId = ProtocolId
        self.lib = ctypes.WinDLL(dllpath)
        self.obj_conversions = conversions()

        if not self.lib.PassThruOpen(None, ctypes.byref(self.DeviceId)):
            # pass
            ClsGeneral.logInfo("Garuda opened successfully")
        else:
            # print "Opening Garuda Failed"
            ClsGeneral.logInfo("Opening Garuda Failed")
            sys.exit(0)
# print "Flag : " + hex(Flags)
            ClsGeneral.logInfo("Flag : " + hex(Flags))

        if not self.lib.PassThruConnect(self.DeviceId, self.ProtocolId, Flags,
                                        BaudRate, ctypes.byref(self.ChannelId)):
            # pass
            ClsGeneral.logInfo("Device Connected successfully")
        else:
            # print "Connection Failed"
            ClsGeneral.logInfo("Device Connection is Failed")
            sys.exit(0)
#        print self.DeviceId, self.ChannelId, self.ProtocolId

    def destroy(self):

        if not self.lib.PassThruDisconnect(self.ChannelId):
            # print "Disconnecing Garuda successfull"
            ClsGeneral.logInfo("Disconnecing Garuda successfull")
        else:
            # print "Unable to Disconnect from Garuda"
            ClsGeneral.logInfo("Unable to Disconnect from Garuda")

        if not self.lib.PassThruClose(self.DeviceId):
            # print "Closing Garuda Successfull"
            ClsGeneral.logInfo("Closing Garuda Successfull")

        else:
            # print "Unable to Close Garuda"
            ClsGeneral.logInfo("Unable to Close Garuda")

    def add_pass_filter(self, MsgId):

        byte_arr = bytearray([0xFF, 0xFF, 0xFF, 0xFF])
        data_bytes = (ctypes.c_ubyte * 4128)(*(byte_arr))
        pMaskMsg = PassThru_Msg(self.ProtocolId, 0, 0, 0, 4, 0, data_bytes)

        byte_arr = bytearray(self.obj_conversions.expand_Id(MsgId))
        data_bytes = (ctypes.c_ubyte * 4128)(*(byte_arr))
        pPaternMsg = PassThru_Msg(self.ProtocolId, 0, 0, 0, 4, 0, data_bytes)

        pFilterID = ctypes.c_ulong(0)

        if not self.lib.PassThruStartMsgFilter(self.ChannelId,
                                               ctypes.c_ulong(1),
                                               ctypes.byref(pMaskMsg),
                                               ctypes.byref(pPaternMsg), None,
                                               ctypes.byref(pFilterID)):

            print "Pass Filter for %s Added" %(hex(MsgId))
            ClsGeneral.logInfo("Pass Filter Added for : " + (hex(MsgId)))
        else:
            print "Pass Filter for %s Not Added" %(hex(MsgId))
            ClsGeneral.logInfo("Pass Filter Not Added for : " + (hex(MsgId)))

    def add_block_filter(self, MsgId):

        byte_arr = bytearray([0xFF, 0xFF, 0xFF, 0xFF])
        data_bytes = (ctypes.c_ubyte * 4128)(*(byte_arr))
        pMaskMsg = PassThru_Msg(self.ProtocolId, 0, 0, 0, 4, 0, data_bytes)

        byte_arr = bytearray(self.obj_conversions.expand_Id(MsgId))
        data_bytes = (ctypes.c_ubyte * 4128)(*(byte_arr))
        pPaternMsg = PassThru_Msg(self.ProtocolId, 0, 0, 0, 4, 0, data_bytes)

        pFilterID = ctypes.c_ulong(0)

        if not self.lib.PassThruStartMsgFilter(self.ChannelId,
                                               ctypes.c_ulong(2),
                                               ctypes.byref(pMaskMsg),
                                               ctypes.byref(pPaternMsg), None,
                                               ctypes.byref(pFilterID)):
            print "Block Filter for %s Added" %(hex(MsgId))
            ClsGeneral.logInfo("Block Filter Added for : " + (hex(MsgId)))
        else:
            print "Block Filter for %s Not Added" %(hex(MsgId))
            ClsGeneral.logInfo("Block Filter Not Added for : " + (hex(MsgId)))

    def send_msg(self, MsgId, Data, Dlen=8, Timeout=0):
        data = self.obj_conversions.expand_data(Data)
##        data = 0x042EA91800000000
        Id = self.obj_conversions.expand_Id(MsgId)
        Id.extend(data)
##        print "Id in merge id========\n",Id
        
        tx_flag = 0
##        print "messag id ",MsgId
        if MsgId > 0x7ff:
            tx_flag = (1 << 8) | 0x40

        byte_arr = bytearray(Id)
        #compute data length
        Dlen = len(byte_arr)
        #copying databytes
        data_bytes = (ctypes.c_ubyte * 4128)(*(byte_arr))
        
##        print "in send msg ..",data_bytes[5]
##        print "Length: ", len(byte_arr)
        pMsg = PassThru_Msg(self.ProtocolId, 0, tx_flag, 0, Dlen, Dlen,
                            data_bytes)
        ret_val = self.lib.PassThruWriteMsgs(self.ChannelId, ctypes.byref(pMsg),
                                             ctypes.byref(ctypes.c_ulong(1)), Timeout)
        
##        print "return value ",ret_val
        if ret_val:
            # print "Message not sent ", ret_val
            ClsGeneral.logInfo(
                "Message not sent " +
                "Return Sts" +
                hex(ret_val) +
                "    ID: " +
                hex(MsgId))
            sys.exit(0)
        else:
            ClsGeneral.logInfo(
                "Message sent " +
                "Return Sts: " +
                hex(ret_val) +
                "    ID: " +
                hex(MsgId))

    def read_msg(self, Timeout, flag_extended=1, return_list=1):
        rx_flag = 0
        if flag_extended:
            rx_flag = 1 << 8

        byte_arr = bytearray(self.obj_conversions.expand_Id(0x0))
        data_bytes = (ctypes.c_ubyte * 4128)(*(byte_arr))

        pMsg = PassThru_Msg(self.ProtocolId, rx_flag, 0, 0, 12, 0, data_bytes)
        #print "Protocol==>",pMsg.Id
        
        ret_val = self.lib.PassThruReadMsgs(self.ChannelId, ctypes.byref(pMsg),
                                            ctypes.byref(ctypes.c_ulong(1)), Timeout)
       # print "Protocol==>",pMsg.ProtocolId
        
##        print "In read message --- ",data_bytes[7]
##        if(ret_val != STATUS_NOERROR) :
##            print "passThruReadMsg failed\n"
        if ret_val:
            # print "Message not recieved ", ret_val
            ClsGeneral.logInfo("Message not recieved :: " + hex(ret_val))
            #ClsGeneral.logInfo("Message not recieved :: " + self.lib.ERR_FAILED)
            sys.exit(0)
            if return_list:
                return [-1, ret_val]
            else:
                return None
        else:
            if return_list:
                return self.obj_conversions.merge_id_data(pMsg)
            else:
                return pMsg

    def clear_buffer(self, Id_list):
        for Id in Id_list:
            if not self.lib.PassThruIoctl(self.ChannelId, ctypes.c_ulong(Id),
                                          None, None):
                # print 'Buffer is cleared', Id
                ClsGeneral.logInfo("Buffer is cleared : " + hex(Id))
            else:
                # print 'Buffer not cleared', Id
                ClsGeneral.logInfo("Buffer not cleared : " + hex(Id))

    def send_periodic_msg(self, func, period):
        Handler = MyThread(Target=func, Time_period=period)
        Handler.start()
        return Handler


garudaDevice = Garuda("C:\Windows\System32\Garuda40432.dll",5,0,500000)
garudaDevice.send_msg(0x7E0,0x013EFFFFFFFFFFFF)
