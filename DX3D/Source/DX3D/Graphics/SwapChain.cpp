#include <DX3D/Graphics/SwapChain.h>

dx3d::SwapChain::SwapChain()
{
	m_dxgiFactory->CreateSwapChain(
		m_dxgiDevice.Get(),
		&swapChainDesc,
		&m_dxgiSwapChain
	);
}

dx3d::SwapChain::SwapChain(const GraphicsResourceDesc)
{
}
