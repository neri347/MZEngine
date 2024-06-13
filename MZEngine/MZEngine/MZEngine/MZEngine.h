#pragma once
#include "IMZEngine.h"

class MZEngine : public IMZEngine
{
	friend IMZEngine* CreateEngine();

public:
	MZEngine();
	virtual ~MZEngine();

	static MZEngine& Instance();

	virtual void Initialize(HWND hWnd, UINT screenWidth, UINT screenHeight) override;
	virtual void Run() override;
	virtual void Finalize() override;

private:
	static MZEngine* _instance;

};