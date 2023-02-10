#include "Graphics.h"


#include "Camera.h"
#include "Clipper.h"
#include "LightManager.h"
#include "MaterialManager.h"
#include "MatrixStack.h"
#include "PrimitivesManager.h"
#include "Viewport.h"

void Graphics::NewFrame()
{
	Camera::Get()->OnNewFrame();
	Clipper::Get()->OnNewFrame();
	LightManager::Get()->OnNewFrame();
	MaterialManager::Get()->OnNewFrame();
	MatrixStack::Get()->OnNewFrame();
	Viewport::Get()->OnNewFrame();
}