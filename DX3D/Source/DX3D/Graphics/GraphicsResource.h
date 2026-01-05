#pragma once
#include <DX3D/Core/Base.h>
#include <d3d11.h>
#include <DX3D/Core/Common.h>

namespace dx3d
{
	struct GraphicsResourceDesc
	{
		BaseDesc base;
		ID3D11Device& m_device;
		IDXGIFactory& m_factory;
	};


	class GraphicsResource : public Base
	{
	public:
		explicit GraphicsResource(const GraphicsResourceDesc& desc) : Base(desc.base), m_device(desc.m_device), m_factory(desc.m_factory)
		{
		}
		

	protected:
		ID3D11Device& m_device;
		IDXGIFactory& m_factory;
	};
}


