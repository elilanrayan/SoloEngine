#include <DX3D/Graphics/ShaderBinary.h>
#include <DX3D/Graphics/GraphicsUtils.h>
#include <d3dcompiler.h>

dx3d::ShaderBinary::ShaderBinary(const ShaderCompileDesc& desc,const GraphicsResourceDesc& gDesc) : GraphicsResource(gDesc)
{
	if (!desc.shaderSourceName) DX3DLogThrowinvalidArg(" No shader source name provided.");
	if (!desc.shaderSourceCode) DX3DLogThrowinvalidArg(" No shader source code provided.");
	if (!desc.shaderSourceCodeSize) DX3DLogThrowinvalidArg(" No shader source size provided.");
	if (!desc.shaderEntryPoint) DX3DLogThrowinvalidArg(" No shader entry point provided.");


	UINT compileFlags{};

#ifdef _DEBUG
	compileFlags |= D3DCOMPILE_DEBUG;
#endif
	
	Microsoft::WRL::ComPtr<ID3DBlob> errorBlob{};
	DX3DGraphicsCheckShaderCompile(
		D3DCompile(
			desc.shaderSourceCode,
			desc.shaderSourceCodeSize,
			desc.shaderSourceName,
			nullptr,
			nullptr,
			desc.shaderEntryPoint,
			dx3d::GraphicsUtils::GetShaderModelTarget(desc.shaderType),
			compileFlags,
			0,
			&m_blob,
			&errorBlob
		), errorBlob.Get());

	
}
