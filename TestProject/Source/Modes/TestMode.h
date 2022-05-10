#include "Objects/Mode/Mode.h"

class ATestMode : public AMode
{
public:
	explicit ATestMode();
public:
	virtual void BeginStart() override;
};