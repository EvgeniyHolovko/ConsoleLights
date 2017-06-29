#pragma once
class AbsDevice
{
public:
	AbsDevice();
	virtual ~AbsDevice();
	virtual void messageTick(void) = 0;
	virtual void messageKey(TCHAR tchar) const;
};

