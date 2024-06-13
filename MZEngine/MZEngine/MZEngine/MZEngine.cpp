#include "MZEngine.h"

MZEngine* MZEngine::_instance = nullptr;

IMZEngine* CreateEngine()
{
	MZEngine::_instance = new MZEngine();
	return MZEngine::_instance;
}

void ReleaseEngine(IMZEngine* engine)
{
	engine = nullptr;
	_instance
}

MZEngine::MZEngine()
{

}

MZEngine::~MZEngine()
{
	delete _instance;
}

MZEngine& MZEngine::Instance()
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
