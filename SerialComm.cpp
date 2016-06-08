#include "StdAfx.h"
#include "SerialComm.h"


SerialComm::SerialComm(void)
{
	
}

// find available ports
array<Object^>^  SerialComm::findPorts(){
	array<Object^>^ objectArray = SerialPort::GetPortNames();
	return objectArray;
}

bool SerialComm::openPort(SerialPort^ _serialPort ,String^ name, String^ rate){
	try{
		
					   // make sure port isn't open	
					if(!_serialPort->IsOpen){
						_serialPort->PortName = name;
					 //this->textBox1->Text=this->comboBox1->Text;
						_serialPort->BaudRate=Int32::Parse(rate);
					 //open serial port 
						_serialPort->Open();
						return true;
					}
					else
						System::Windows::Forms::MessageBox::Show("Port isn't opened!!!");
					return false;
					}
					catch(UnauthorizedAccessException^){
						System::Windows::Forms::MessageBox::Show("UnauthorizedAccess!!!");
						return false;
					}
}

String^ SerialComm::readFromPort(SerialPort^ _serialPort){
	

	try
            {
                String^ message = _serialPort->ReadLine();
				return message;
            }
            catch (TimeoutException ^) {
				return String::Empty;
			}
}
void SerialComm::sendDataToPort(SerialPort^ _serialPort, String^ command){
		// add sender name
		 String^ name = _serialPort->PortName;
	
			 //Write to Serial port
			 if(_serialPort->IsOpen){
				_serialPort->WriteLine(command);
				Sleep(700);		 
			 }
				else{
					System::Windows::Forms::MessageBox::Show("Port not Opened!!!");
				}
}

bool SerialComm::closePort(SerialPort^ _serialPort){

	_serialPort->Close();
	return true;
}
