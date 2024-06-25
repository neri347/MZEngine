#include "GraphicsProcess.h"

MZGraphics::I3DRenderer* CreateRenderer()
{
	return &MZGraphics::GraphicsProcess::Instance();
}

void ReleaseRenderer(MZGraphics::I3DRenderer* pRenderer)
{
	MZGraphics::GraphicsProcess::Release();
	pRenderer = nullptr;
}

namespace MZGraphics
{
	GraphicsProcess* GraphicsProcess::_instance = nullptr;

	GraphicsProcess::GraphicsProcess()
		: _hWnd(nullptr), _screenWidth(0), _screenHeight(0)
	{
	}

	GraphicsProcess::~GraphicsProcess()
	{
	}

	void GraphicsProcess::Initialize(HWND hWnd, UINT screenWidth, UINT screenHeight)
	{
	}

	void GraphicsProcess::Update(float deltaTime)
	{
	}

	void GraphicsProcess::Render()
	{
	}

	void GraphicsProcess::OnResize(UINT screenWidth, UINT screenHeight)
	{
	}

	void GraphicsProcess::Finalize()
	{
	}

	GraphicsProcess& GraphicsProcess::Instance()
	{
		if(_instance == nullptr)
		{
			_instance = new GraphicsProcess();
		}
		return *_instance;
	}

	void GraphicsProcess::Release()
	{
		delete _instance;
		_instance = nullptr;
	}

}