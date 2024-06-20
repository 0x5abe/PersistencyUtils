#pragma once
#include "Geode/Geode.hpp"
#include "Geode/modify/CollisionTriggerAction.hpp"
#include "util/InputStream.hpp"
#include "util/OutputStream.hpp"
#include "import_export.hpp"

namespace persistenceAPI {
	class $modify(PACollisionTriggerAction, CollisionTriggerAction) {
	protected:
		friend void operator>>(persistenceAPI::InputStream& i_stream, PACollisionTriggerAction& o_value);
		friend void operator<<(persistenceAPI::OutputStream& o_stream, PACollisionTriggerAction& i_value);

	public:
		SABE_PU_DLL void load(persistenceAPI::InputStream& i_stream);
		SABE_PU_DLL void save(persistenceAPI::OutputStream& o_stream);

	#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
		SABE_PU_DLL void describe();
	#endif
	};
}