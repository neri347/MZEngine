#pragma once
#include "IMZEngine.h"
#include "Singleton.h"

namespace MZGraphics
{
	class I3DRenderer;
}

namespace MZCore
{

	class MZEngine : public IMZEngine, public Singleton<MZEngine>
	{
	public:
		friend class Singleton<MZEngine>;
		virtual ~MZEngine();
		virtual void Initialize(HWND hWnd, UINT screenWidth, UINT screenHeight) override;
		virtual void Run() override;
		virtual void Finalize() override;

	private:
		MZEngine();
		MZGraphics::I3DRenderer* _renderer;
	};

}