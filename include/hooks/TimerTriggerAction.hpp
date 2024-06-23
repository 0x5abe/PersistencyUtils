#pragma once
#include "Geode/Geode.hpp"
#include "Geode/modify/TimerTriggerAction.hpp"
#include "util/InputStream.hpp"
#include "util/OutputStream.hpp"
#include "import_export.hpp"

namespace persistenceAPI {
	class $modify(PATimerTriggerAction, TimerTriggerAction) {
	protected:
		friend void operator>>(persistenceAPI::InputStream& i_stream, PATimerTriggerAction& o_value);
		friend void operator<<(persistenceAPI::OutputStream& o_stream, PATimerTriggerAction& i_value);

	public:
		SABE_PA_DLL void load(persistenceAPI::InputStream& i_stream);
		SABE_PA_DLL void save(persistenceAPI::OutputStream& o_stream);

	#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
		SABE_PA_DLL void describe();
	#endif
	};
}