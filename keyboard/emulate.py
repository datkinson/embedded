#!/usr/bin/python
__author__ = 'datkinson'

import ctypes
import time

KEY_MAP = {}

SendInput = ctypes.windll.user32.SendInput

# C struct redefinitions
PUL = ctypes.POINTER(ctypes.c_ulong)
class KeyBdInput(ctypes.Structure):
    _fields_ = [("wVk", ctypes.c_ushort),
                ("wScan", ctypes.c_ushort),
                ("dwFlags", ctypes.c_ulong),
                ("time", ctypes.c_ulong),
                ("dwExtraInfo", PUL)]

class HardwareInput(ctypes.Structure):
    _fields_ = [("uMsg", ctypes.c_ulong),
                ("wParamL", ctypes.c_short),
                ("wParamH", ctypes.c_ushort)]

class MouseInput(ctypes.Structure):
    _fields_ = [("dx", ctypes.c_long),
                ("dy", ctypes.c_long),
                ("mouseData", ctypes.c_ulong),
                ("dwFlags", ctypes.c_ulong),
                ("time",ctypes.c_ulong),
                ("dwExtraInfo", PUL)]

class Input_I(ctypes.Union):
    _fields_ = [("ki", KeyBdInput),
                 ("mi", MouseInput),
                 ("hi", HardwareInput)]

class Input(ctypes.Structure):
    _fields_ = [("type", ctypes.c_ulong),
                ("ii", Input_I)]

def AssignKeys():
    global KEY_MAP
    KEY_MAP['space'] = 0x20
    KEY_MAP['up'] = 0x26
    KEY_MAP['down'] = 0x28
    KEY_MAP['left'] = 0x25
    KEY_MAP['right'] = 0x27
    KEY_MAP['0'] = 0x30
    KEY_MAP['1'] = 0x31
    KEY_MAP['2'] = 0x32
    KEY_MAP['3'] = 0x33
    KEY_MAP['4'] = 0x34
    KEY_MAP['5'] = 0x35
    KEY_MAP['6'] = 0x36
    KEY_MAP['7'] = 0x37
    KEY_MAP['8'] = 0x38
    KEY_MAP['9'] = 0x39
    KEY_MAP['a'] = 0x41
    KEY_MAP['b'] = 0x42
    KEY_MAP['c'] = 0x43
    KEY_MAP['d'] = 0x44
    KEY_MAP['e'] = 0x45
    KEY_MAP['f'] = 0x46
    KEY_MAP['g'] = 0x47
    KEY_MAP['h'] = 0x48
    KEY_MAP['i'] = 0x49
    KEY_MAP['j'] = 0x4A
    KEY_MAP['k'] = 0x4B
    KEY_MAP['l'] = 0x4C
    KEY_MAP['m'] = 0x4D
    KEY_MAP['n'] = 0x4E
    KEY_MAP['o'] = 0x4F
    KEY_MAP['p'] = 0x50
    KEY_MAP['q'] = 0x51
    KEY_MAP['r'] = 0x52
    KEY_MAP['s'] = 0x53
    KEY_MAP['t'] = 0x54
    KEY_MAP['u'] = 0x55
    KEY_MAP['v'] = 0x56
    KEY_MAP['w'] = 0x57
    KEY_MAP['x'] = 0x58
    KEY_MAP['y'] = 0x59
    KEY_MAP['z'] = 0x5A

def PressKey(hexKeyCode):
    '''
    Simulate keydown event
    '''
    extra = ctypes.c_ulong(0)
    ii_ = Input_I()
    ii_.ki = KeyBdInput( hexKeyCode, 0x48, 0, 0, ctypes.pointer(extra) )
    x = Input( ctypes.c_ulong(1), ii_ )
    ctypes.windll.user32.SendInput(1, ctypes.pointer(x), ctypes.sizeof(x))

def ReleaseKey(hexKeyCode):
    '''
    Simulate keyup event
    '''
    extra = ctypes.c_ulong(0)
    ii_ = Input_I()
    ii_.ki = KeyBdInput( hexKeyCode, 0x48, 0x0002, 0, ctypes.pointer(extra) )
    x = Input( ctypes.c_ulong(1), ii_ )
    ctypes.windll.user32.SendInput(1, ctypes.pointer(x), ctypes.sizeof(x))

def PrintString(stringToPrint):
    global KEY_MAP
    #characterlist = list(stringToPrint)
    for character in stringToPrint:
        if character == ' ':
            letterToPrint = 'space'
        else:
            letterToPrint = character
        PressKey(KEY_MAP[letterToPrint])
        ReleaseKey(KEY_MAP[letterToPrint])

if __name__ =="__main__":

    AssignKeys()
    time.sleep(2)
    PrintString('hello there')

