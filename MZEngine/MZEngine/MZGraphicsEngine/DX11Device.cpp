#include "DX11Device.h"

namespace MZGraphics
{

	DX11Device::DX11Device(HWND hWnd, UINT screenWidth, UINT screenHeight)
	{
		UINT createDeviceFlags = 0;
#ifdef _DEBUG
		createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif
		DXGI_SWAP_CHAIN_DESC swapchainDesc;
		ZeroMemory(&swapchainDesc, sizeof(swapchainDesc));
		swapchainDesc.BufferDesc.Width = screenWidth;
		swapchainDesc.BufferDesc.Height = screenHeight;
		swapchainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		swapchainDesc.BufferDesc.RefreshRate.Numerator = 0;
		swapchainDesc.BufferDesc.RefreshRate.Denominator = 0;
		swapchainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
		swapchainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		swapchainDesc.SampleDesc.Count = 1;
		swapchainDesc.SampleDesc.Quality = 0;
		swapchainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapchainDesc.BufferCount = 1;
		swapchainDesc.OutputWindow = hWnd;
		swapchainDesc.Windowed = TRUE;
		swapchainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		swapchainDesc.Flags = 0;


	}

	DX11Device::~DX11Device()
	{

	}

	ID3D11Device* DX11Device::GetDevice() const
	{
		return _device.Get();
	}

	ID3D11DeviceContext* DX11Device::GetDeviceContext() const
	{
		return _deviceContext.Get();
	}

	void DX11Device::ResizeBackbuffer(UINT width, UINT height)
	{

	}

	void DX11Device::ClearBackbuffer(const float color[4])
	{

	}

}