#using <System.dll>
#include <Windows.h>

using namespace System;
using namespace System::IO::Ports;
using namespace System::Threading;


#pragma once
ref class SerialComm
{
	private:
    static bool _continue;
   // SerialPort^ _serialPort;

public:
	SerialComm(void);
	array<Object^>^ findPorts();
	String^ readFromPort(SerialPort^ _serialPort);
	bool openPort(SerialPort^ _serialPort, String^ name, String^ rate);
	void sendDataToPort(SerialPort^ _serialPort, String^ command);
	bool closePort (SerialPort^ _serialPort);
};

