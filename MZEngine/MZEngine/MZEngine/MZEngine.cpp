#include "MZEngine.h"

IMZEngine* CreateEngine()
{
	return &MZCore::MZEngine::Instance();
}

void ReleaseEngine(IMZEngine* engine)
{
	MZCore::MZEngine::Instance().Release();
	engine = nullptr;
}

namespace MZCore
{

	MZEngine::MZEngine()
	{

	}

	MZEngine::~MZEngine()
	{

	}

	void MZEngine::Initialize(HWND hWnd, UINT screenWidth, UINT screenHeight)
	{

	}

	void MZEngine::Run()
	{

	}

	void MZEngine::Finalize()
	{

	}

}
