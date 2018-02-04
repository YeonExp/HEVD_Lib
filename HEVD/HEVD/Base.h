#pragma once
#include "BaseImpl.h"

class BaseIoctlImpl;
class BaseIoctl
{
public:
	BaseIoctl();
	~BaseIoctl();
	HANDLE OpenDevice();
	void CloseDevice() const;
	BOOL sendData(std::string& payload, DWORD code);
private:
	std::tr1::shared_ptr<BaseIoctlImpl> newIoctl;
};