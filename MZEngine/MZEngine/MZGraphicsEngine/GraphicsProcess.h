#pragma once
#include <windows.h>
#include "../MZGraphicsInterface/I3DRenderer.h"

namespace MZGraphics
{
	class GraphicsProcess : public I3DRenderer
	{
	public:
		virtual ~GraphicsProcess();
		virtual void Initialize(HWND hWnd, UINT screenWidth, UINT screenHeight) override;
		virtual void Update(float deltaTime) override;
		virtual void Render() override;
		virtual void OnResize(UINT screenWidth, UINT screenHeight) override;
		virtual void Finalize() override;

		static GraphicsProcess& Instance();
		static void Release();

	private:
		GraphicsProcess();

	private:
		static GraphicsProcess* _instance;
		HWND _hWnd;
		UINT _screenWidth;
		UINT _screenHeight;
	};
}