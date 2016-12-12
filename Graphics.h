#ifndef _GRAPHICS_H
#define _GRAPHICS_H

//C runtime header files

//Additional header files

#include "System.h"

//#ifndef _LOGGER_H
//	#include "Logger.h"
//#endif
#ifndef _2DUTILL_H
	#include "d2dutill.h"
#endif

//Forward declaration
class Window;

//Struct
struct GraphicsData : SystemData {

public:

	GraphicsData(Window* wnd = nullptr);

	Window* pWnd;
};

class Graphics : public System
{
	friend class Engine;

public:

	HRESULT OnResize(UINT width, UINT height);

	ID2D1HwndRenderTarget* GetRenderTarget() { return m_pRenderTarget; }
	IWICImagingFactory* GetImageFactory() { return m_pImageFactory; }
	ID2D1SolidColorBrush* GetColorBrush() { return m_pColorBrush; }
	ID2D1Factory* GetD2DFactory() { return m_pD2DFactory; }

protected:

	Graphics(const GraphicsData& data);
	virtual ~Graphics();

	//Copy constructor & Default Assigment Operator
	Graphics(const Graphics& other);
	Graphics& operator = (const Graphics& tref);

	bool Initialize();
	bool ShutDown();

private:

	//void* operator new(size_t size);
	//void operator delete(void* pdelete);

	HRESULT CreateDeviceIndependentResources();
	HRESULT CreateDeviceDependentResources();

	void DiscardDeviceResources();

	void BeginDraw();
	HRESULT EndDraw();

	ID2D1HwndRenderTarget* m_pRenderTarget;
	IWICImagingFactory* m_pImageFactory;
	ID2D1SolidColorBrush* m_pColorBrush;
	ID2D1Factory* m_pD2DFactory;

	Window* m_pWindow;
};

#endif