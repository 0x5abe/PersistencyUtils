#include "hooks/SFXTriggerInstance.hpp"
#include "Geode/binding/SFXTriggerGameObject.hpp"
#include "Geode/binding/PlayLayer.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceUtils;

void PUSFXTriggerInstance::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PUSFXTriggerInstance::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistenceUtils::operator>>(InputStream& i_stream, PUSFXTriggerInstance& o_value) {
	i_stream.read(reinterpret_cast<char*>(&o_value), 16);
	SEPARATOR_I
	int l_objectIndex;
	i_stream >> l_objectIndex;
	PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
	if (l_playLayer) o_value.m_sfxTriggerGameObject = static_cast<SFXTriggerGameObject*>(l_playLayer->getGameObject(l_objectIndex));
	SEPARATOR_I
}

inline void persistenceUtils::operator<<(OutputStream& o_stream, PUSFXTriggerInstance& i_value) {
	o_stream.write(reinterpret_cast<char*>(&i_value), 16);
	SEPARATOR_O
	int l_objectIndex = -1;
	PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(i_value.m_sfxTriggerGameObject);
	o_stream << l_objectIndex;
	SEPARATOR_O
}

#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
void PUSFXTriggerInstance::describe() {
	log::info("[PUSFXTriggerInstance - describe] pad_1: [{}]", hexStr(reinterpret_cast<unsigned char*>(this), 16));
	int l_objectIndex = -1;
	PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_sfxTriggerGameObject);
	log::info("[PUSFXTriggerInstance - describe] m_sfxTriggerGameObject l_objectIndex: {}", l_objectIndex);
}
#endif