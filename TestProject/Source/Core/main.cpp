#include "MinimalCore.h"
#include "Modes/TestMode.h"

extern GarbageCollector* GC;
extern SEngine* Engine;

int main()
{
	ATestMode* Mode = new ATestMode();
	Engine->SetMode(Mode);
	Engine->StartupEngine();
	delete Mode;
	return 0;
}