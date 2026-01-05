#include <DX3D/Graphics/RenderSystem.h>
#include <DX3D/Graphics/GraphicsLogUtils.h>

dx3d::RenderSystem::RenderSystem(const RenderSystemDesc& desc) : Base(desc.base)
{
	D3D_FEATURE_LEVEL featureLevel{};
	UINT createDeviceFlags{};

#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	DX3DGraphicsLogError(D3D11CreateDevice(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, NULL,
		0, D3D11_SDK_VERSION, &m_d3dDevice, &featureLevel, &m_d3dContext), "Direct3D initialization failed.");

	DX3DGraphicsLogError(m_d3dDevice->QueryInterface(IID_PPV_ARGS(&m_dxgiDevice)),"QueryInterface failed to retrieve IDXGIDevice.");

	DX3DGraphicsLogError(m_dxgiDevice->GetParent(IID_PPV_ARGS(& m_dxgiAdapter)), "Get Parent failed to retrieve IDXGIAdapter.");

	DX3DGraphicsLogError(m_dxgiAdapter->GetParent(IID_PPV_ARGS(& m_dxgiFactory)), "Get Parent failed to retrieve IDXGIFactory.");

	
}




dx3d::RenderSystem::~RenderSystem()
{
}
