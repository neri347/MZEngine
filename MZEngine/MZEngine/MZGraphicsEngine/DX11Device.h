#pragma once
#include <d3d11.h>
#include <wrl.h>
#include <memory>

namespace MZGraphics
{
	class DX11DeviceContext;

	class DX11Device
	{
	public:
		DX11Device(HWND hWnd, UINT screenWidth, UINT screenHeight);
		~DX11Device();

		ID3D11Device* GetDevice() const;
		ID3D11DeviceContext* GetDeviceContext() const;

		void ResizeBackbuffer(UINT width, UINT height);
		void ClearBackbuffer(const float color[4]);

	private:
		Microsoft::WRL::ComPtr<ID3D11Device> _device;
		Microsoft::WRL::ComPtr<IDXGISwapChain> _swapChain;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> _deviceContext;
		Microsoft::WRL::ComPtr<ID3D11Texture2D> _backbuffer;
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> _backbufferRTV;
	};
}