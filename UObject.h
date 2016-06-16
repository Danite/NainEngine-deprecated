#ifndef _UOBJECT_H
#define _UOBEJCT_H

//Additional include files
#ifndef _CONTEXT_H
	#include "context.h"
#endif

#ifndef _STRING_H
	#include "string.h"
#endif

class UObject
{
public:

	UObject();
	UObject(const std::tstring& name);
	virtual ~UObject();

	//void* operator new(size_t size);
	//void operator delete(void* pdelete);

	virtual bool Initialize()								{ m_bIsInitualized = true; return true; }
	virtual bool PostInitialize()							{ m_bIsPostInitialized = true; return true; }
	virtual bool LoadContent()								{ m_bIsContentLoaded = true; return true; }
	virtual bool PostLoadContent()							{ m_bIsPostContentLoaded = true; return true; }
	virtual bool Update(Context& context)					{ return true; }
	//virtual bool LateUpdate(Context& context)				{ return true; }
	virtual bool Draw(Context& context)						{ return true; }
	virtual bool DrawUI(Context& context)					{ return true; }
	virtual bool ShutDown()									{ return true; }

	virtual void Reset();

	void SetName(const std::tstring& name) { m_Name = name; }
	std::tstring& GetName() { return m_Name; }

	bool IsInitialized() const { return m_bIsInitualized; }
	bool IsPostInitialized() const { return m_bIsPostInitialized; }
	bool IsContentLoaded() const { return m_bIsContentLoaded; }
	bool IsPostContentLoaded() const { return m_bIsPostContentLoaded; }

	void SetCanTick(bool canTick) { m_bCanTick = canTick; }
	bool CanTick() const { return m_bCanTick; }
	void SetCanDraw(bool canDraw) { m_bCanDraw = canDraw; }
	bool CanDraw() const { return m_bCanDraw; }

	void Destroy() { m_bIsDestroyed = true; }
	bool IsDestroyed() const { return m_bIsDestroyed; }

	void Activate() { m_bIsActivated = true; }
	void DeActivate() { m_bIsActivated = true; }
	bool IsActivated() { return m_bIsActivated; }

protected:

	static int m_objectAmount;
	int m_ID;

	bool m_bIsInitualized;
	bool m_bIsPostInitialized;
	
	bool m_bIsContentLoaded;
	bool m_bIsPostContentLoaded;

	std::tstring m_Name;

private:

	bool m_bIsActivated;
	bool m_bIsDestroyed;

	bool m_bCanTick;
	bool m_bCanDraw;

};

#endif
