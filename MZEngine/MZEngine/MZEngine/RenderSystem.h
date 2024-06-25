#pragma once
#include <windows.h>
#include "Singleton.h"
#include <memory>
#include "../MZGraphicsInterface/I3DRenderer.h"

namespace MZCore
{
	class RenderSystem : public Singleton<RenderSystem>
	{
	public:
		friend Singleton<RenderSystem>;
		virtual ~RenderSystem();
		virtual void Initialize(HWND hWnd, UINT screenWidth, UINT screenHeight) = 0;
		virtual void Update(float deltaTime) = 0;
		virtual void Render() = 0;
		virtual void OnResize(UINT screenWidth, UINT screenHeight) = 0;
		virtual void Finalize() = 0;

	private:
		RenderSystem();
		std::unique_ptr<MZGraphics::I3DRenderer> _renderer;
	};
}