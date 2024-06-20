#include "hooks/TimerTriggerAction.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PATimerTriggerAction::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PATimerTriggerAction::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(InputStream& i_stream, PATimerTriggerAction& o_value) {
	i_stream.read(reinterpret_cast<char*>(&o_value), 32);
	VEC_SEPARATOR_I
	i_stream >> o_value.m_unkVecInt;
	VEC_SEPARATOR_I
}

inline void persistenceAPI::operator<<(OutputStream& o_stream, PATimerTriggerAction& i_value) {
	o_stream.write(reinterpret_cast<char*>(&i_value), 32);
	VEC_SEPARATOR_O
	o_stream << i_value.m_unkVecInt;
	VEC_SEPARATOR_O
}

#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
void PATimerTriggerAction::describe() {
	log::info("[PATimerTriggerAction - describe] pad_1: [{}]", hexStr(reinterpret_cast<unsigned char*>(this), 32));
	int l_size = m_unkVecInt.size();
	log::info("[PATimerTriggerAction - describe] m_unkVecInt.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PATimerTriggerAction - describe] m_unkVecInt[{}]: {}", i, m_unkVecInt[i]);
	}
}
#endif