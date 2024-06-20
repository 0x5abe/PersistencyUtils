#pragma once
#include "Geode/Geode.hpp"
#include "Geode/modify/FMODSoundState.hpp"
#include "util/InputStream.hpp"
#include "util/OutputStream.hpp"
#include "import_export.hpp"

namespace persistenceAPI {
	class $modify(PAFMODSoundState, FMODSoundState) {
	protected:
		friend void operator>>(persistenceAPI::InputStream& i_stream, PAFMODSoundState& o_value);
		friend void operator<<(persistenceAPI::OutputStream& o_stream, PAFMODSoundState& i_value);

	public:
		SABE_PU_DLL void load(persistenceAPI::InputStream& i_stream);
		SABE_PU_DLL void save(persistenceAPI::OutputStream& o_stream);
		
	#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
		SABE_PU_DLL void describe();
	#endif
	};
}