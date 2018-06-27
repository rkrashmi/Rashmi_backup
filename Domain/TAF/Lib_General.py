#!/usr/bin/env python
# -*- coding: utf-8 -*-
######################################################################
# Library        : Lib_general
# Discription    : In this file contains following methods
#                  1. Messagebox to display info [infomessagebox()]
#                  2. Logger[logInfo()] for test cases
# Created Date   : 1-06-2016
# Author         : Prasanna Yelsangikar
# Modified by    : -
# Modified Date  : -
######################## built-in libs ################################
import sys
import time
import os
import logging
import datetime
from ConfigParser import SafeConfigParser
if sys.version_info < (3, 0):
    from Tkinter import *

######################## Main Program ################################


class Constant:
    parser = SafeConfigParser()
    try:

        parser.read(os.path.join(os.path.dirname(__file__), 'config.ini'))
        ScriptDirPath = parser.get('Tools', 'ScriptDir')
        ToolDir = parser.get('Tools', 'ToolPath')
        BlankExePath = parser.get('Tools', 'BlankScreenPath')
        MoveBlankScreenPath = parser.get('Tools', 'MoveBlankScreenPath')
        ImagePath = parser.get('Tools', 'ImagePath')
        ImageExePath = parser.get('Tools', 'ImageMovePath')
        ImageC1Path = parser.get('Tools', 'ImageC1Path')
        ImageC3Path = parser.get('Tools', 'ImageC3Path')
        Image3Path = parser.get('Tools', 'Image3Path')
        LeftRightCrossingPath = parser.get('Tools', 'LeftRightCrossingPath')
##        FCWPath = parser.get('Tools', 'FCWPath')
        MovePath = parser.get('Tools', 'MovePath')
        LaneMovePath = parser.get('Tools', 'LaneMove')
        LibPath = parser.get('Libs', 'LibsPath')
        RobotLogPath = parser.get('RobotLog', 'Logging')
        
        
    except:
        print "Config file not found"


class General:
    """
       General class contains User Messagebox and Logging the test case(s)

    """

    def infomessagebox(self, infomessage, Interval=3000):
        """
            This method used displaying the user message on Screen for perticular intervals of time
            Usage : infomessagebox(self,<Any Message is apear on message box>, Interval = <integer>)

        """

        root = Tk()
        root.title("Information Window")
        root.geometry("500x75")

        logo = PhotoImage( \
            file=os.path.join( \
                os.path.dirname(__file__),'icon.gif'), width=50, height=50) 
        w1 = Label(root, image=logo).pack(side="left")

        F = Frame(root)
        F.pack(fill=BOTH, expand=True)

        infoLabel = Label(F, text="Info : " + infomessage, font="Verdana 10 ")
        infoLabel.pack(fill=BOTH)

        okbtn = Button(F, text="Ok", command=root.destroy)
        okbtn.after(Interval, root.destroy)
        okbtn.pack(side=BOTTOM)

        x = (root.winfo_screenwidth() - root.winfo_reqwidth()) / 2
        y = (root.winfo_screenheight() - root.winfo_reqheight()) / 2

        root.geometry("+%d+%d" % (x, y))
        root.mainloop()

    def logInfo(self, infotext):
        """
            logInfo() function is used for logging the test case
            Usage : logInfo("Log will dump in info.log file")

        """
        ClsConstant = Constant()
        foldername = os.path.dirname(sys.argv[0]).split("\\")[-1]
        scriptDir = os.path.dirname(sys.argv[0])
        if os.path.exists(os.path.join(scriptDir, "Logs")):
            pass
        else:
            os.mkdir(os.path.join(scriptDir, "Logs"))
        interval = str((datetime.datetime.now()).isoformat().replace(
            '.', ':')).replace('T', ' ').replace(":", "-")
        logging.basicConfig(level=logging.DEBUG,
                            format='%(asctime)s %(levelname)s %(message)s',
                            filename=os.path.join(ClsConstant.RobotLogPath,
                                                  scriptDir, "Logs", foldername +
                                                  " " + interval + '.log'),
                            filemode='w')
        print ":" + infotext
        logging.info(":" + infotext)


# For Testing Enable main()

if __name__ == '__main__':
    #    pass
    ClsGeneral = General()  # Object creation
    ClsGeneral.infomessagebox("video is playing")
    ClsGeneral.logInfo("video is playing")
    time.sleep(3)
    ClsGeneral.infomessagebox("video Finished")
    ClsGeneral.logInfo("video Finished")

    ClsConstant = Constant()

    try:
        print ClsConstant.ScriptDirPath
        print ClsConstant.ToolDir
        print ClsConstant.BlankExePath
        print ClsConstant.MoveBlankScreenPath
        print ClsConstant.ImagePath
        print ClsConstant.ImageC1Path
        print ClsConstant.ImageC3Path
        print ClsConstant.Image3Path
        print ClsConstant.LeftRightCrossingPath
        print ClsConstant.MovePath
        print ClsConstant.RobotLogPath
##        print "2",ClsConstant.OneMoreExe
        print ClsConstant.ImageExePath
        print ClsConstant.FCW_Path
    except:
        pass













'''
    Additional code for excel sheet extract
'''
##
###!/usr/bin/env python
##
##import xlrd
##
###from Lib_General import *
###ClsGeneral = General()
###----------------------------------------------------------------------
##input_dict = {}
##def input_file(testcase):        
##    path = "F:\Rahul\Src\Libs" + "\\read_excelfile.xls "
##    global input_dict 
##    """
##    Open and read an Excel file
##    """
##    book = xlrd.open_workbook(path)
##    
##    # print number of sheets
##    first_sheet = book.sheet_by_index(0)
##
##    # read a cell
##    row = first_sheet.nrows
##    print "row",row
##    column = first_sheet.ncols 
##    print row
##    for i in range(row):
##        print i
##        cell = first_sheet.cell(i,0 )
##        cell.value = str(cell.value)
##        print cell.value
##        if testcase == cell.value:
##                        print "Equal"
##                        print row
##                        print "i",i
##                        cell = first_sheet.cell(i,1)
##                        list1 = (cell.value).split('\n')
##                        print list1
##                        for j in list1:
##                                if j == str(''):
##                                    pass
##                                print "j",j
##                                j = str(j)
##                                list2  =  j.split(':')
##                                list2[1] = list2[1].replace("kmph","")
##                                list2[0] = list2[0].strip(' ')
##                                list2[1] = list2[1].strip(' ')
##                                if list2[1].isdigit():
##                                        list2[1] = int(list2[1])
##                                        input_dict.update({list2[0]:list2[1]})
##                                                                                    
##                        
##    print "\n",input_dict
##    return input_dict
##
####testcase = "LDW_App72"
####input_file(testcase)
###----------------------------------------------------------------------
##'''if __name__ == "__main__":
##
##    testcase = "LDW_App02"
##    open_file(testcase)
##'''
