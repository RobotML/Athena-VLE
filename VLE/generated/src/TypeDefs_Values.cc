// 
// Includes ----------------------------------------------------------------------
// 

#include <sstream>
#include <iomanip>
#include <boost/lexical_cast.hpp>
#include <iostream>
#include <vle/utils/Tools.hpp>

#include "TypeDefs_Values.h"

using namespace std;

//
namespace generated
{

//  
// Data type implementations ----------------------------------------------------------
//

// -------------------------------------------------------- Pointer
// basic type Pointer
value::Value* Pointer_toValue(const Pointer& _val) {
	value::Value* val = value::Integer::create((int)_val);
	return val;
}

Pointer Pointer_fromValue(const value::Value* _node, const Pointer& _initialValue) {
	if(_node != NULL)
		return (Pointer)_node->toInteger().value();
	else
		return _initialValue;		
}
		
// -------------------------------------------------------- String
// basic type String
value::Value* String_toValue(const String& _val) {
	value::Value* val = value::String::create(_val);
	return val;
}

String String_fromValue(const value::Value* _node, const String& _initialValue) {
	if(_node != NULL)
		return _node->toString().value();
	else
		return _initialValue;		
}
		
// -------------------------------------------------------- Logical
// basic type Logical
value::Value* Logical_toValue(const Logical& _val) {
	value::Value* val = value::Boolean::create(_val);
	return val;
}

Logical Logical_fromValue(const value::Value* _node, const Logical& _initialValue) {
	if(_node != NULL)
		return _node->toBoolean().value();
	else
		return _initialValue;		
}
		
// -------------------------------------------------------- Int
// basic type Int
value::Value* Int_toValue(const Int& _val) {
	value::Value* val = value::Integer::create(_val);
	return val;
}

Int Int_fromValue(const value::Value* _node, const Int& _initialValue) {
	if(_node != NULL)
		return _node->toInteger().value();
	else
		return _initialValue;		
}
		
// -------------------------------------------------------- Long
// basic type Long
value::Value* Long_toValue(const Long& _val) {
	value::Value* val = value::Integer::create(_val);
	return val;
}

Long Long_fromValue(const value::Value* _node, const Long& _initialValue) {
	if(_node != NULL)
		return _node->toInteger().value();
	else
		return _initialValue;		
}
		
// -------------------------------------------------------- Real
// basic type Real
value::Value* Real_toValue(const Real& _val) {
	value::Value* val = value::Double::create(_val);
	return val;
}

Real Real_fromValue(const value::Value* _node, const Real& _initialValue) {
	if(_node != NULL)
		return _node->toDouble().value();
	else
		return _initialValue;		
}
		
// -------------------------------------------------------- Vec3
// Vec3 is an array of Real
value::Value* Vec3_toValue(const Vec3& _val) {	
	value::Set* set = value::Set::create();
	if(set != NULL) 
	{
		for(unsigned int i = 0; i < 3; i++) 
		{
			set->add(Real_toValue(_val[i])) ;
		}
	}
	return set;
}

void Vec3_fromValue(const value::Value* _node,Vec3& _val) {
	const value::Set& set = _node->toSet();
	for(unsigned int i = 0; i < 3; i++) {
		_val[i] = Real_fromValue(set.get(i)) ;
	}

}

		
// -------------------------------------------------------- Vec5
// Vec5 is an array of Real
value::Value* Vec5_toValue(const Vec5& _val) {	
	value::Set* set = value::Set::create();
	if(set != NULL) 
	{
		for(unsigned int i = 0; i < 5; i++) 
		{
			set->add(Real_toValue(_val[i])) ;
		}
	}
	return set;
}

void Vec5_fromValue(const value::Value* _node,Vec5& _val) {
	const value::Set& set = _node->toSet();
	for(unsigned int i = 0; i < 5; i++) {
		_val[i] = Real_fromValue(set.get(i)) ;
	}

}

		
// -------------------------------------------------------- VecX
// VecX is an array of Real
value::Value* VecX_toValue(const VecX& _val) {	
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		for(unsigned int cpt = 0; cpt < 2; cpt ++)
		{
			value::Set* set = value::Set::create();
			if(set != NULL)
			{
				for(unsigned int index = 0; index < _val->num_elements(); index ++)
				{
					set->add(Real_toValue((*_val)[cpt][index])) ;
				}
				map->add(utils::toString(cpt), set);
			}
		}
	}
	return map;
}

void VecX_fromValue(const value::Value* _node,VecX& _val) {
	const value::Map& map = _node->toMap();
	for(unsigned int cpt = 0; cpt < 2; cpt ++)
	{
		std::string key = utils::toString(cpt);
		if(map.exist(key))
		{
			const value::Set& set = map.get(key)->toSet();
			for(unsigned int index = 0; index < _val->num_elements(); index ++) {
				(*_val)[cpt][index] = Real_fromValue(set.get(index)) ;
			}
		}
	}

}

		
// -------------------------------------------------------- gisement
// gisement is a Real
value::Value* gisement_toValue(const gisement& _val) {
	return Real_toValue(_val);
}
gisement gisement_fromValue(const value::Value* _node) {
	return Real_fromValue(_node);
}

		
// -------------------------------------------------------- site
// site is a Real
value::Value* site_toValue(const site& _val) {
	return Real_toValue(_val);
}
site site_fromValue(const value::Value* _node) {
	return Real_fromValue(_node);
}

		
// -------------------------------------------------------- VecOne
// VecOne is an array of gisement
value::Value* VecOne_toValue(const VecOne& _val) {	
	value::Set* set = value::Set::create();
	if(set != NULL) 
	{
		for(unsigned int i = 0; i < _val->num_elements(); i++) 
		{
			set->add(Real_toValue((*_val)[i])) ;
		}
	}
	return set;
}

void VecOne_fromValue(const value::Value* _node,VecOne& _val) {
	const value::Set& set = _node->toSet();
	for(unsigned int i = 0; i < _val->num_elements(); i++) {
		(*_val)[i] = Real_fromValue(set.get(i)) ;
	}

}

		
// -------------------------------------------------------- VecY
// VecY is an array of gisement
value::Value* VecY_toValue(const VecY& _val) {	
	value::Set* set = value::Set::create();
	if(set != NULL) 
	{
		for(unsigned int i = 0; i < 3; i++) 
		{
			set->add(Real_toValue(_val[i])) ;
		}
	}
	return set;
}

void VecY_fromValue(const value::Value* _node,VecY& _val) {
	const value::Set& set = _node->toSet();
	for(unsigned int i = 0; i < 3; i++) {
		_val[i] = Real_fromValue(set.get(i)) ;
	}

}

		
// -------------------------------------------------------- test3
// test3 is a structure
value::Value* test3_toValue(const test3& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("hello",Real_toValue(_val.hello));
		map->add("g",gisement_toValue(_val.g));
	}
	return map;
}

void test3_fromValue(const value::Value* _node, test3& _val) {
	const value::Map& map = _node->toMap();
	_val.hello = Real_fromValue(map.get("hello"));
	_val.g = Real_fromValue(map.get("g"));
}
		
// -------------------------------------------------------- Ints
// Ints is a vector of Int
value::Value* Ints_toValue(const Ints& _val) {
	value::Set* set = value::Set::create();
	if(set != NULL)
	{
		Ints::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			set->add(Int_toValue(*it)) ;
		}
	}
	return set;
}

void Ints_fromValue(const value::Value* _node, Ints& vect) {
	vect.clear();
	const value::Set& set = _node->toSet();
	for (unsigned int i = 0; i < set.size(); i++) {
		const value::Value* val = set.get(i);
		Int _val;
		Int_fromValue(val, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- Longs
// Longs is a vector of Long
value::Value* Longs_toValue(const Longs& _val) {
	value::Set* set = value::Set::create();
	if(set != NULL)
	{
		Longs::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			set->add(Long_toValue(*it)) ;
		}
	}
	return set;
}

void Longs_fromValue(const value::Value* _node, Longs& vect) {
	vect.clear();
	const value::Set& set = _node->toSet();
	for (unsigned int i = 0; i < set.size(); i++) {
		const value::Value* val = set.get(i);
		Long _val;
		Long_fromValue(val, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- Reals
// Reals is a vector of Real
value::Value* Reals_toValue(const Reals& _val) {
	value::Set* set = value::Set::create();
	if(set != NULL)
	{
		Reals::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			set->add(Real_toValue(*it)) ;
		}
	}
	return set;
}

void Reals_fromValue(const value::Value* _node, Reals& vect) {
	vect.clear();
	const value::Set& set = _node->toSet();
	for (unsigned int i = 0; i < set.size(); i++) {
		const value::Value* val = set.get(i);
		Real _val;
		Real_fromValue(val, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- EntityType
// basic type EntityType
value::Value* EntityType_toValue(const EntityType& _val) {
	value::Value* val = value::Integer::create(_val);
	return val;
}

EntityType EntityType_fromValue(const value::Value* _node, const EntityType& _initialValue) {
	if(_node != NULL)
		return static_cast<EntityType>(_node->toInteger().value());
	else
		return _initialValue;		
}
		
// -------------------------------------------------------- NetworkID
// basic type NetworkID
value::Value* NetworkID_toValue(const NetworkID& _val) {
	value::Value* val = value::Integer::create(_val);
	return val;
}

NetworkID NetworkID_fromValue(const value::Value* _node, const NetworkID& _initialValue) {
	if(_node != NULL)
		return static_cast<NetworkID>(_node->toInteger().value());
	else
		return _initialValue;		
}
		
// -------------------------------------------------------- SensorType
// basic type SensorType
value::Value* SensorType_toValue(const SensorType& _val) {
	value::Value* val = value::Integer::create(_val);
	return val;
}

SensorType SensorType_fromValue(const value::Value* _node, const SensorType& _initialValue) {
	if(_node != NULL)
		return static_cast<SensorType>(_node->toInteger().value());
	else
		return _initialValue;		
}
		
// -------------------------------------------------------- SensorFunction
// basic type SensorFunction
value::Value* SensorFunction_toValue(const SensorFunction& _val) {
	value::Value* val = value::Integer::create(_val);
	return val;
}

SensorFunction SensorFunction_fromValue(const value::Value* _node, const SensorFunction& _initialValue) {
	if(_node != NULL)
		return static_cast<SensorFunction>(_node->toInteger().value());
	else
		return _initialValue;		
}
		
// -------------------------------------------------------- EquipmentType
// basic type EquipmentType
value::Value* EquipmentType_toValue(const EquipmentType& _val) {
	value::Value* val = value::Integer::create(_val);
	return val;
}

EquipmentType EquipmentType_fromValue(const value::Value* _node, const EquipmentType& _initialValue) {
	if(_node != NULL)
		return static_cast<EquipmentType>(_node->toInteger().value());
	else
		return _initialValue;		
}
		
// -------------------------------------------------------- EquipmentStatus
// EquipmentStatus is a structure
value::Value* EquipmentStatus_toValue(const EquipmentStatus& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("type",Long_toValue(_val.type));
		map->add("id",Long_toValue(_val.id));
		map->add("available",Long_toValue(_val.available));
		map->add("enabled",Long_toValue(_val.enabled));
	}
	return map;
}

void EquipmentStatus_fromValue(const value::Value* _node, EquipmentStatus& _val) {
	const value::Map& map = _node->toMap();
	_val.type = Long_fromValue(map.get("type"));
	_val.id = Long_fromValue(map.get("id"));
	_val.available = Long_fromValue(map.get("available"), 100);
	_val.enabled = Long_fromValue(map.get("enabled"), 0);
}
		
// -------------------------------------------------------- EquipmentStatusList
// EquipmentStatusList is a map with key type Long and value type EquipmentStatus
value::Value* EquipmentStatusList_toValue(const EquipmentStatusList& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		EquipmentStatusList::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			const std::string& key = boost::lexical_cast<std::string>((*it).first);
			const value::Value& val = *EquipmentStatus_toValue((*it).second);
			map->add(key, val);
		}
	}
	return map;

}

void EquipmentStatusList_fromValue(const value::Value* _node, EquipmentStatusList& _map) {
	const value::Map& map = _node->toMap();
	for (value::Map::const_iterator it = map.begin(); it != map.end(); it++) {
		const Long& key = static_cast<Long>(map.getInt((*it).first));
		const value::Value* val = (*it).second;

		EquipmentStatus_fromValue(val, _map[key]);
	}
}


		
// -------------------------------------------------------- ExternalInput
// ExternalInput is a structure
value::Value* ExternalInput_toValue(const ExternalInput& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("id",Long_toValue(_val.id));
		map->add("duration",Long_toValue(_val.duration));
		map->add("available_during",Long_toValue(_val.available_during));
		map->add("available_after",Long_toValue(_val.available_after));
	}
	return map;
}

void ExternalInput_fromValue(const value::Value* _node, ExternalInput& _val) {
	const value::Map& map = _node->toMap();
	_val.id = Long_fromValue(map.get("id"));
	_val.duration = Long_fromValue(map.get("duration"));
	_val.available_during = Long_fromValue(map.get("available_during"));
	_val.available_after = Long_fromValue(map.get("available_after"));
}
		
// -------------------------------------------------------- vExternalInput
// vExternalInput is a vector of ExternalInput
value::Value* vExternalInput_toValue(const vExternalInput& _val) {
	value::Set* set = value::Set::create();
	if(set != NULL)
	{
		vExternalInput::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			set->add(ExternalInput_toValue(*it)) ;
		}
	}
	return set;
}

void vExternalInput_fromValue(const value::Value* _node, vExternalInput& vect) {
	vect.clear();
	const value::Set& set = _node->toSet();
	for (unsigned int i = 0; i < set.size(); i++) {
		const value::Value* val = set.get(i);
		ExternalInput _val;
		ExternalInput_fromValue(val, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- ExternalInputListForOneTypeOfEquipment
// ExternalInputListForOneTypeOfEquipment is a map with key type EquipmentType and value type vExternalInput
value::Value* ExternalInputListForOneTypeOfEquipment_toValue(const ExternalInputListForOneTypeOfEquipment& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		ExternalInputListForOneTypeOfEquipment::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			const std::string& key = boost::lexical_cast<std::string>((*it).first);
			const value::Value& val = *vExternalInput_toValue((*it).second);
			map->add(key, val);
		}
	}
	return map;

}

void ExternalInputListForOneTypeOfEquipment_fromValue(const value::Value* _node, ExternalInputListForOneTypeOfEquipment& _map) {
	const value::Map& map = _node->toMap();
	for (value::Map::const_iterator it = map.begin(); it != map.end(); it++) {
		const EquipmentType& key = static_cast<EquipmentType>(map.getInt((*it).first));
		const value::Value* val = (*it).second;

		vExternalInput_fromValue(val, _map[key]);
	}
}


		
// -------------------------------------------------------- ExternalInputList
// ExternalInputList is a map with key type Long and value type ExternalInputListForOneTypeOfEquipment
value::Value* ExternalInputList_toValue(const ExternalInputList& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		ExternalInputList::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			const std::string& key = boost::lexical_cast<std::string>((*it).first);
			const value::Value& val = *ExternalInputListForOneTypeOfEquipment_toValue((*it).second);
			map->add(key, val);
		}
	}
	return map;

}

void ExternalInputList_fromValue(const value::Value* _node, ExternalInputList& _map) {
	const value::Map& map = _node->toMap();
	for (value::Map::const_iterator it = map.begin(); it != map.end(); it++) {
		const Long& key = static_cast<Long>(map.getInt((*it).first));
		const value::Value* val = (*it).second;

		ExternalInputListForOneTypeOfEquipment_fromValue(val, _map[key]);
	}
}


		
// -------------------------------------------------------- EntityState
// EntityState is a structure
value::Value* EntityState_toValue(const EntityState& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("time",Long_toValue(_val.time));
		map->add("id",Long_toValue(_val.id));
		map->add("side",Long_toValue(_val.side));
		map->add("type",EntityType_toValue(_val.type));
		map->add("subtype",Long_toValue(_val.subtype));
		map->add("subsubtype",Long_toValue(_val.subsubtype));
		map->add("position",Vec3_toValue(_val.position));
		map->add("speed",Vec3_toValue(_val.speed));
		map->add("attitudes",Vec3_toValue(_val.attitudes));
	}
	return map;
}

void EntityState_fromValue(const value::Value* _node, EntityState& _val) {
	const value::Map& map = _node->toMap();
	_val.time = Long_fromValue(map.get("time"));
	_val.id = Long_fromValue(map.get("id"));
	_val.side = Long_fromValue(map.get("side"));
	_val.type = EntityType_fromValue(map.get("type"));
	_val.subtype = Long_fromValue(map.get("subtype"));
	_val.subsubtype = Long_fromValue(map.get("subsubtype"));
	Vec3_fromValue(map.get("position"), _val.position);
	Vec3_fromValue(map.get("speed"), _val.speed);
	Vec3_fromValue(map.get("attitudes"), _val.attitudes);
}
		
// -------------------------------------------------------- EntityStates
// EntityStates is a map with key type Long and value type EntityState
value::Value* EntityStates_toValue(const EntityStates& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		EntityStates::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			const std::string& key = boost::lexical_cast<std::string>((*it).first);
			const value::Value& val = *EntityState_toValue((*it).second);
			map->add(key, val);
		}
	}
	return map;

}

void EntityStates_fromValue(const value::Value* _node, EntityStates& _map) {
	const value::Map& map = _node->toMap();
	for (value::Map::const_iterator it = map.begin(); it != map.end(); it++) {
		const Long& key = static_cast<Long>(map.getInt((*it).first));
		const value::Value* val = (*it).second;

		EntityState_fromValue(val, _map[key]);
	}
}


		
// -------------------------------------------------------- EmitterBeam
// EmitterBeam is a structure
value::Value* EmitterBeam_toValue(const EmitterBeam& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("elevation",Real_toValue(_val.elevation));
		map->add("azimut",Real_toValue(_val.azimut));
		map->add("elevationAperture",Real_toValue(_val.elevationAperture));
		map->add("azimutAperture",Real_toValue(_val.azimutAperture));
		map->add("targets",Longs_toValue(_val.targets));
	}
	return map;
}

void EmitterBeam_fromValue(const value::Value* _node, EmitterBeam& _val) {
	const value::Map& map = _node->toMap();
	_val.elevation = Real_fromValue(map.get("elevation"));
	_val.azimut = Real_fromValue(map.get("azimut"));
	_val.elevationAperture = Real_fromValue(map.get("elevationAperture"));
	_val.azimutAperture = Real_fromValue(map.get("azimutAperture"));
	Longs_fromValue(map.get("targets"), _val.targets);
}
		
// -------------------------------------------------------- Beams
// Beams is a vector of EmitterBeam
value::Value* Beams_toValue(const Beams& _val) {
	value::Set* set = value::Set::create();
	if(set != NULL)
	{
		Beams::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			set->add(EmitterBeam_toValue(*it)) ;
		}
	}
	return set;
}

void Beams_fromValue(const value::Value* _node, Beams& vect) {
	vect.clear();
	const value::Set& set = _node->toSet();
	for (unsigned int i = 0; i < set.size(); i++) {
		const value::Value* val = set.get(i);
		EmitterBeam _val;
		EmitterBeam_fromValue(val, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- EmitterState
// EmitterState is a structure
value::Value* EmitterState_toValue(const EmitterState& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("time",Long_toValue(_val.time));
		map->add("entityID",Long_toValue(_val.entityID));
		map->add("type",SensorType_toValue(_val.type));
		map->add("techno",Long_toValue(_val.techno));
		map->add("dist1m2",Real_toValue(_val.dist1m2));
		map->add("beams",Beams_toValue(_val.beams));
	}
	return map;
}

void EmitterState_fromValue(const value::Value* _node, EmitterState& _val) {
	const value::Map& map = _node->toMap();
	_val.time = Long_fromValue(map.get("time"));
	_val.entityID = Long_fromValue(map.get("entityID"));
	_val.type = SensorType_fromValue(map.get("type"));
	_val.techno = Long_fromValue(map.get("techno"));
	_val.dist1m2 = Real_fromValue(map.get("dist1m2"));
	Beams_fromValue(map.get("beams"), _val.beams);
}
		
// -------------------------------------------------------- EmitterStates
// EmitterStates is a vector of EmitterState
value::Value* EmitterStates_toValue(const EmitterStates& _val) {
	value::Set* set = value::Set::create();
	if(set != NULL)
	{
		EmitterStates::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			set->add(EmitterState_toValue(*it)) ;
		}
	}
	return set;
}

void EmitterStates_fromValue(const value::Value* _node, EmitterStates& vect) {
	vect.clear();
	const value::Set& set = _node->toSet();
	for (unsigned int i = 0; i < set.size(); i++) {
		const value::Value* val = set.get(i);
		EmitterState _val;
		EmitterState_fromValue(val, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- JammerState
// JammerState is a structure
value::Value* JammerState_toValue(const JammerState& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("time",Long_toValue(_val.time));
		map->add("entityID",Long_toValue(_val.entityID));
		map->add("type",Long_toValue(_val.type));
		map->add("techno",Long_toValue(_val.techno));
		map->add("elevation",Real_toValue(_val.elevation));
		map->add("azimut",Real_toValue(_val.azimut));
		map->add("apertureEl",Real_toValue(_val.apertureEl));
		map->add("apertureAz",Real_toValue(_val.apertureAz));
		map->add("powerOrDistance",Real_toValue(_val.powerOrDistance));
	}
	return map;
}

void JammerState_fromValue(const value::Value* _node, JammerState& _val) {
	const value::Map& map = _node->toMap();
	_val.time = Long_fromValue(map.get("time"));
	_val.entityID = Long_fromValue(map.get("entityID"));
	_val.type = Long_fromValue(map.get("type"));
	_val.techno = Long_fromValue(map.get("techno"));
	_val.elevation = Real_fromValue(map.get("elevation"));
	_val.azimut = Real_fromValue(map.get("azimut"));
	_val.apertureEl = Real_fromValue(map.get("apertureEl"));
	_val.apertureAz = Real_fromValue(map.get("apertureAz"));
	_val.powerOrDistance = Real_fromValue(map.get("powerOrDistance"));
}
		
// -------------------------------------------------------- JammerStates
// JammerStates is a vector of JammerState
value::Value* JammerStates_toValue(const JammerStates& _val) {
	value::Set* set = value::Set::create();
	if(set != NULL)
	{
		JammerStates::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			set->add(JammerState_toValue(*it)) ;
		}
	}
	return set;
}

void JammerStates_fromValue(const value::Value* _node, JammerStates& vect) {
	vect.clear();
	const value::Set& set = _node->toSet();
	for (unsigned int i = 0; i < set.size(); i++) {
		const value::Value* val = set.get(i);
		JammerState _val;
		JammerState_fromValue(val, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- Detonation
// Detonation is a structure
value::Value* Detonation_toValue(const Detonation& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("time",Long_toValue(_val.time));
		map->add("shooterID",Long_toValue(_val.shooterID));
		map->add("weaponType",Long_toValue(_val.weaponType));
		map->add("targets",Longs_toValue(_val.targets));
		map->add("position",Vec3_toValue(_val.position));
	}
	return map;
}

void Detonation_fromValue(const value::Value* _node, Detonation& _val) {
	const value::Map& map = _node->toMap();
	_val.time = Long_fromValue(map.get("time"));
	_val.shooterID = Long_fromValue(map.get("shooterID"));
	_val.weaponType = Long_fromValue(map.get("weaponType"));
	Longs_fromValue(map.get("targets"), _val.targets);
	Vec3_fromValue(map.get("position"), _val.position);
}
		
// -------------------------------------------------------- Detonations
// Detonations is a map with key type Long and value type Detonation
value::Value* Detonations_toValue(const Detonations& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		Detonations::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			const std::string& key = boost::lexical_cast<std::string>((*it).first);
			const value::Value& val = *Detonation_toValue((*it).second);
			map->add(key, val);
		}
	}
	return map;

}

void Detonations_fromValue(const value::Value* _node, Detonations& _map) {
	const value::Map& map = _node->toMap();
	for (value::Map::const_iterator it = map.begin(); it != map.end(); it++) {
		const Long& key = static_cast<Long>(map.getInt((*it).first));
		const value::Value* val = (*it).second;

		Detonation_fromValue(val, _map[key]);
	}
}


		
// -------------------------------------------------------- EnvironmentInteractions
// EnvironmentInteractions is a structure
value::Value* EnvironmentInteractions_toValue(const EnvironmentInteractions& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("entities",EntityStates_toValue(_val.entities));
		map->add("emitters",EmitterStates_toValue(_val.emitters));
		map->add("jammers",JammerStates_toValue(_val.jammers));
		map->add("detonations",Detonations_toValue(_val.detonations));
	}
	return map;
}

void EnvironmentInteractions_fromValue(const value::Value* _node, EnvironmentInteractions& _val) {
	const value::Map& map = _node->toMap();
	EntityStates_fromValue(map.get("entities"), _val.entities);
	EmitterStates_fromValue(map.get("emitters"), _val.emitters);
	JammerStates_fromValue(map.get("jammers"), _val.jammers);
	Detonations_fromValue(map.get("detonations"), _val.detonations);
}
		
// -------------------------------------------------------- AngularBounds
// AngularBounds is a structure
value::Value* AngularBounds_toValue(const AngularBounds& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("symetric",Long_toValue(_val.symetric));
		map->add("elevationMin",Real_toValue(_val.elevationMin));
		map->add("elevationMax",Real_toValue(_val.elevationMax));
		map->add("azimutMin",Real_toValue(_val.azimutMin));
		map->add("azimutMax",Real_toValue(_val.azimutMax));
	}
	return map;
}

void AngularBounds_fromValue(const value::Value* _node, AngularBounds& _val) {
	const value::Map& map = _node->toMap();
	_val.symetric = Long_fromValue(map.get("symetric"));
	_val.elevationMin = Real_fromValue(map.get("elevationMin"));
	_val.elevationMax = Real_fromValue(map.get("elevationMax"));
	_val.azimutMin = Real_fromValue(map.get("azimutMin"));
	_val.azimutMax = Real_fromValue(map.get("azimutMax"));
}
		
// -------------------------------------------------------- AngularDelta
// AngularDelta is a structure
value::Value* AngularDelta_toValue(const AngularDelta& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("deltaElevation",Real_toValue(_val.deltaElevation));
		map->add("deltaAzimut",Real_toValue(_val.deltaAzimut));
	}
	return map;
}

void AngularDelta_fromValue(const value::Value* _node, AngularDelta& _val) {
	const value::Map& map = _node->toMap();
	_val.deltaElevation = Real_fromValue(map.get("deltaElevation"));
	_val.deltaAzimut = Real_fromValue(map.get("deltaAzimut"));
}
		
// -------------------------------------------------------- SensorAngularBounds
// SensorAngularBounds is a vector of AngularBounds
value::Value* SensorAngularBounds_toValue(const SensorAngularBounds& _val) {
	value::Set* set = value::Set::create();
	if(set != NULL)
	{
		SensorAngularBounds::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			set->add(AngularBounds_toValue(*it)) ;
		}
	}
	return set;
}

void SensorAngularBounds_fromValue(const value::Value* _node, SensorAngularBounds& vect) {
	vect.clear();
	const value::Set& set = _node->toSet();
	for (unsigned int i = 0; i < set.size(); i++) {
		const value::Value* val = set.get(i);
		AngularBounds _val;
		AngularBounds_fromValue(val, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- SensorAngularDelta
// SensorAngularDelta is a vector of AngularDelta
value::Value* SensorAngularDelta_toValue(const SensorAngularDelta& _val) {
	value::Set* set = value::Set::create();
	if(set != NULL)
	{
		SensorAngularDelta::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			set->add(AngularDelta_toValue(*it)) ;
		}
	}
	return set;
}

void SensorAngularDelta_fromValue(const value::Value* _node, SensorAngularDelta& vect) {
	vect.clear();
	const value::Set& set = _node->toSet();
	for (unsigned int i = 0; i < set.size(); i++) {
		const value::Value* val = set.get(i);
		AngularDelta _val;
		AngularDelta_fromValue(val, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- JammerDefinition
// JammerDefinition is a structure
value::Value* JammerDefinition_toValue(const JammerDefinition& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("id",Long_toValue(_val.id));
		map->add("domainId",Long_toValue(_val.domainId));
		map->add("type",Long_toValue(_val.type));
		map->add("techno",Long_toValue(_val.techno));
		map->add("maxPowerAllocation",Real_toValue(_val.maxPowerAllocation));
		map->add("bounds",AngularBounds_toValue(_val.bounds));
		map->add("maxTargetNumber",Long_toValue(_val.maxTargetNumber));
		map->add("apertureEl",Real_toValue(_val.apertureEl));
		map->add("apertureAz",Real_toValue(_val.apertureAz));
	}
	return map;
}

void JammerDefinition_fromValue(const value::Value* _node, JammerDefinition& _val) {
	const value::Map& map = _node->toMap();
	_val.id = Long_fromValue(map.get("id"));
	_val.domainId = Long_fromValue(map.get("domainId"));
	_val.type = Long_fromValue(map.get("type"));
	_val.techno = Long_fromValue(map.get("techno"));
	_val.maxPowerAllocation = Real_fromValue(map.get("maxPowerAllocation"));
	AngularBounds_fromValue(map.get("bounds"), _val.bounds);
	_val.maxTargetNumber = Long_fromValue(map.get("maxTargetNumber"));
	_val.apertureEl = Real_fromValue(map.get("apertureEl"));
	_val.apertureAz = Real_fromValue(map.get("apertureAz"));
}
		
// -------------------------------------------------------- EmitterJammed
// EmitterJammed is a structure
value::Value* EmitterJammed_toValue(const EmitterJammed& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("entityID",Long_toValue(_val.entityID));
		map->add("powerAllocation",Real_toValue(_val.powerAllocation));
	}
	return map;
}

void EmitterJammed_fromValue(const value::Value* _node, EmitterJammed& _val) {
	const value::Map& map = _node->toMap();
	_val.entityID = Long_fromValue(map.get("entityID"));
	_val.powerAllocation = Real_fromValue(map.get("powerAllocation"));
}
		
// -------------------------------------------------------- EmitterJammList
// EmitterJammList is a vector of EmitterJammed
value::Value* EmitterJammList_toValue(const EmitterJammList& _val) {
	value::Set* set = value::Set::create();
	if(set != NULL)
	{
		EmitterJammList::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			set->add(EmitterJammed_toValue(*it)) ;
		}
	}
	return set;
}

void EmitterJammList_fromValue(const value::Value* _node, EmitterJammList& vect) {
	vect.clear();
	const value::Set& set = _node->toSet();
	for (unsigned int i = 0; i < set.size(); i++) {
		const value::Value* val = set.get(i);
		EmitterJammed _val;
		EmitterJammed_fromValue(val, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- JammerStatus
// JammerStatus is a structure
value::Value* JammerStatus_toValue(const JammerStatus& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("lastUpdateDate",Long_toValue(_val.lastUpdateDate));
		map->add("id",Long_toValue(_val.id));
		map->add("type",Long_toValue(_val.type));
		map->add("techno",Long_toValue(_val.techno));
		map->add("available",Long_toValue(_val.available));
		map->add("endOfOrderId",Long_toValue(_val.endOfOrderId));
		map->add("doingOrderId",Long_toValue(_val.doingOrderId));
		map->add("doingOrderDuration",Long_toValue(_val.doingOrderDuration));
		map->add("errorFlag",Long_toValue(_val.errorFlag));
		map->add("nbrOfJammOps",Long_toValue(_val.nbrOfJammOps));
	}
	return map;
}

void JammerStatus_fromValue(const value::Value* _node, JammerStatus& _val) {
	const value::Map& map = _node->toMap();
	_val.lastUpdateDate = Long_fromValue(map.get("lastUpdateDate"));
	_val.id = Long_fromValue(map.get("id"));
	_val.type = Long_fromValue(map.get("type"));
	_val.techno = Long_fromValue(map.get("techno"));
	_val.available = Long_fromValue(map.get("available"));
	_val.endOfOrderId = Long_fromValue(map.get("endOfOrderId"));
	_val.doingOrderId = Long_fromValue(map.get("doingOrderId"));
	_val.doingOrderDuration = Long_fromValue(map.get("doingOrderDuration"));
	_val.errorFlag = Long_fromValue(map.get("errorFlag"));
	_val.nbrOfJammOps = Long_fromValue(map.get("nbrOfJammOps"));
}
		
// -------------------------------------------------------- JammersStatus
// JammersStatus is a map with key type Long and value type JammerStatus
value::Value* JammersStatus_toValue(const JammersStatus& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		JammersStatus::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			const std::string& key = boost::lexical_cast<std::string>((*it).first);
			const value::Value& val = *JammerStatus_toValue((*it).second);
			map->add(key, val);
		}
	}
	return map;

}

void JammersStatus_fromValue(const value::Value* _node, JammersStatus& _map) {
	const value::Map& map = _node->toMap();
	for (value::Map::const_iterator it = map.begin(); it != map.end(); it++) {
		const Long& key = static_cast<Long>(map.getInt((*it).first));
		const value::Value* val = (*it).second;

		JammerStatus_fromValue(val, _map[key]);
	}
}


		
// -------------------------------------------------------- JammOp
// JammOp is a structure
value::Value* JammOp_toValue(const JammOp& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("target_id",Long_toValue(_val.target_id));
		map->add("azimut",Real_toValue(_val.azimut));
		map->add("elevation",Real_toValue(_val.elevation));
	}
	return map;
}

void JammOp_fromValue(const value::Value* _node, JammOp& _val) {
	const value::Map& map = _node->toMap();
	_val.target_id = Long_fromValue(map.get("target_id"));
	_val.azimut = Real_fromValue(map.get("azimut"));
	_val.elevation = Real_fromValue(map.get("elevation"));
}
		
// -------------------------------------------------------- JammOperationList
// JammOperationList is a vector of JammOp
value::Value* JammOperationList_toValue(const JammOperationList& _val) {
	value::Set* set = value::Set::create();
	if(set != NULL)
	{
		JammOperationList::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			set->add(JammOp_toValue(*it)) ;
		}
	}
	return set;
}

void JammOperationList_fromValue(const value::Value* _node, JammOperationList& vect) {
	vect.clear();
	const value::Set& set = _node->toSet();
	for (unsigned int i = 0; i < set.size(); i++) {
		const value::Value* val = set.get(i);
		JammOp _val;
		JammOp_fromValue(val, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- JammerOrder
// JammerOrder is a structure
value::Value* JammerOrder_toValue(const JammerOrder& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("orderId",Long_toValue(_val.orderId));
		map->add("jammerId",Long_toValue(_val.jammerId));
		map->add("func",Long_toValue(_val.func));
		map->add("duration",Long_toValue(_val.duration));
		map->add("jammList",JammOperationList_toValue(_val.jammList));
	}
	return map;
}

void JammerOrder_fromValue(const value::Value* _node, JammerOrder& _val) {
	const value::Map& map = _node->toMap();
	_val.orderId = Long_fromValue(map.get("orderId"));
	_val.jammerId = Long_fromValue(map.get("jammerId"));
	_val.func = Long_fromValue(map.get("func"));
	_val.duration = Long_fromValue(map.get("duration"));
	JammOperationList_fromValue(map.get("jammList"), _val.jammList);
}
		
// -------------------------------------------------------- JammersOrders
// JammersOrders is a map with key type Long and value type JammerOrder
value::Value* JammersOrders_toValue(const JammersOrders& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		JammersOrders::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			const std::string& key = boost::lexical_cast<std::string>((*it).first);
			const value::Value& val = *JammerOrder_toValue((*it).second);
			map->add(key, val);
		}
	}
	return map;

}

void JammersOrders_fromValue(const value::Value* _node, JammersOrders& _map) {
	const value::Map& map = _node->toMap();
	for (value::Map::const_iterator it = map.begin(); it != map.end(); it++) {
		const Long& key = static_cast<Long>(map.getInt((*it).first));
		const value::Value* val = (*it).second;

		JammerOrder_fromValue(val, _map[key]);
	}
}


		
// -------------------------------------------------------- JammerDefinitions
// JammerDefinitions is a map with key type Long and value type JammerDefinition
value::Value* JammerDefinitions_toValue(const JammerDefinitions& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		JammerDefinitions::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			const std::string& key = boost::lexical_cast<std::string>((*it).first);
			const value::Value& val = *JammerDefinition_toValue((*it).second);
			map->add(key, val);
		}
	}
	return map;

}

void JammerDefinitions_fromValue(const value::Value* _node, JammerDefinitions& _map) {
	const value::Map& map = _node->toMap();
	for (value::Map::const_iterator it = map.begin(); it != map.end(); it++) {
		const Long& key = static_cast<Long>(map.getInt((*it).first));
		const value::Value* val = (*it).second;

		JammerDefinition_fromValue(val, _map[key]);
	}
}


		
// -------------------------------------------------------- LocalisationInit
// LocalisationInit is a structure
value::Value* LocalisationInit_toValue(const LocalisationInit& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("pos",Vec3_toValue(_val.pos));
		map->add("heading",Real_toValue(_val.heading));
		map->add("mach",Real_toValue(_val.mach));
		map->add("v",Real_toValue(_val.v));
	}
	return map;
}

void LocalisationInit_fromValue(const value::Value* _node, LocalisationInit& _val) {
	const value::Map& map = _node->toMap();
	Vec3_fromValue(map.get("pos"), _val.pos);
	_val.heading = Real_fromValue(map.get("heading"));
	_val.mach = Real_fromValue(map.get("mach"));
	_val.v = Real_fromValue(map.get("v"), 0.);
}
		
// -------------------------------------------------------- LocalisationConst
// LocalisationConst is a structure
value::Value* LocalisationConst_toValue(const LocalisationConst& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("irs_deriv",Real_toValue(_val.irs_deriv));
		map->add("ralt_factor",Real_toValue(_val.ralt_factor));
		map->add("max_dxy_gps",Real_toValue(_val.max_dxy_gps));
		map->add("max_dz_gps",Real_toValue(_val.max_dz_gps));
		map->add("max_dxy_ter",Real_toValue(_val.max_dxy_ter));
		map->add("max_dz_ter",Real_toValue(_val.max_dz_ter));
	}
	return map;
}

void LocalisationConst_fromValue(const value::Value* _node, LocalisationConst& _val) {
	const value::Map& map = _node->toMap();
	_val.irs_deriv = Real_fromValue(map.get("irs_deriv"));
	_val.ralt_factor = Real_fromValue(map.get("ralt_factor"));
	_val.max_dxy_gps = Real_fromValue(map.get("max_dxy_gps"));
	_val.max_dz_gps = Real_fromValue(map.get("max_dz_gps"));
	_val.max_dxy_ter = Real_fromValue(map.get("max_dxy_ter"));
	_val.max_dz_ter = Real_fromValue(map.get("max_dz_ter"));
}
		
// -------------------------------------------------------- LocalisationState
// LocalisationState is a structure
value::Value* LocalisationState_toValue(const LocalisationState& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("isValid",Long_toValue(_val.isValid));
		map->add("mach",Real_toValue(_val.mach));
		map->add("position",Vec3_toValue(_val.position));
		map->add("attitudes",Vec3_toValue(_val.attitudes));
		map->add("speed",Vec3_toValue(_val.speed));
		map->add("alt_ralt",Real_toValue(_val.alt_ralt));
	}
	return map;
}

void LocalisationState_fromValue(const value::Value* _node, LocalisationState& _val) {
	const value::Map& map = _node->toMap();
	_val.isValid = Long_fromValue(map.get("isValid"));
	_val.mach = Real_fromValue(map.get("mach"));
	Vec3_fromValue(map.get("position"), _val.position);
	Vec3_fromValue(map.get("attitudes"), _val.attitudes);
	Vec3_fromValue(map.get("speed"), _val.speed);
	_val.alt_ralt = Real_fromValue(map.get("alt_ralt"));
}
		
// -------------------------------------------------------- LocalisationError
// LocalisationError is a structure
value::Value* LocalisationError_toValue(const LocalisationError& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("incertitude_dxy",Real_toValue(_val.incertitude_dxy));
		map->add("incertitude_dz",Real_toValue(_val.incertitude_dz));
		map->add("incertitude_ralt",Real_toValue(_val.incertitude_ralt));
	}
	return map;
}

void LocalisationError_fromValue(const value::Value* _node, LocalisationError& _val) {
	const value::Map& map = _node->toMap();
	_val.incertitude_dxy = Real_fromValue(map.get("incertitude_dxy"));
	_val.incertitude_dz = Real_fromValue(map.get("incertitude_dz"));
	_val.incertitude_ralt = Real_fromValue(map.get("incertitude_ralt"));
}
		
// -------------------------------------------------------- LocalisationEquipmentState
// LocalisationEquipmentState is a structure
value::Value* LocalisationEquipmentState_toValue(const LocalisationEquipmentState& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("gps_available",Long_toValue(_val.gps_available));
		map->add("irs_available",Long_toValue(_val.irs_available));
		map->add("ralt_available",Long_toValue(_val.ralt_available));
		map->add("ternum_available",Long_toValue(_val.ternum_available));
	}
	return map;
}

void LocalisationEquipmentState_fromValue(const value::Value* _node, LocalisationEquipmentState& _val) {
	const value::Map& map = _node->toMap();
	_val.gps_available = Long_fromValue(map.get("gps_available"));
	_val.irs_available = Long_fromValue(map.get("irs_available"));
	_val.ralt_available = Long_fromValue(map.get("ralt_available"));
	_val.ternum_available = Long_fromValue(map.get("ternum_available"));
}
		
// -------------------------------------------------------- LocDefinitions
// LocDefinitions is a map with key type Long and value type LocalisationConst
value::Value* LocDefinitions_toValue(const LocDefinitions& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		LocDefinitions::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			const std::string& key = boost::lexical_cast<std::string>((*it).first);
			const value::Value& val = *LocalisationConst_toValue((*it).second);
			map->add(key, val);
		}
	}
	return map;

}

void LocDefinitions_fromValue(const value::Value* _node, LocDefinitions& _map) {
	const value::Map& map = _node->toMap();
	for (value::Map::const_iterator it = map.begin(); it != map.end(); it++) {
		const Long& key = static_cast<Long>(map.getInt((*it).first));
		const value::Value* val = (*it).second;

		LocalisationConst_fromValue(val, _map[key]);
	}
}


		
// -------------------------------------------------------- Waypoint
// Waypoint is a structure
value::Value* Waypoint_toValue(const Waypoint& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("id",Long_toValue(_val.id));
		map->add("g",Real_toValue(_val.g));
		map->add("heading",Real_toValue(_val.heading));
		map->add("mode",Long_toValue(_val.mode));
		map->add("position",Vec3_toValue(_val.position));
		map->add("pmax",Real_toValue(_val.pmax));
		map->add("t",Long_toValue(_val.t));
		map->add("dt",Long_toValue(_val.dt));
		map->add("v",Real_toValue(_val.v));
		map->add("mach",Real_toValue(_val.mach));
		map->add("vmin",Real_toValue(_val.vmin));
		map->add("vmax",Real_toValue(_val.vmax));
		map->add("dv",Real_toValue(_val.dv));
	}
	return map;
}

void Waypoint_fromValue(const value::Value* _node, Waypoint& _val) {
	const value::Map& map = _node->toMap();
	_val.id = Long_fromValue(map.get("id"));
	_val.g = Real_fromValue(map.get("g"), 2.);
	_val.heading = Real_fromValue(map.get("heading"));
	_val.mode = Long_fromValue(map.get("mode"), 1);
	Vec3_fromValue(map.get("position"), _val.position);
	_val.pmax = Real_fromValue(map.get("pmax"), 10.);
	_val.t = Long_fromValue(map.get("t"), 0);
	_val.dt = Long_fromValue(map.get("dt"), 20);
	_val.v = Real_fromValue(map.get("v"), 0.);
	_val.mach = Real_fromValue(map.get("mach"), 0.7);
	_val.vmin = Real_fromValue(map.get("vmin"), 100.);
	_val.vmax = Real_fromValue(map.get("vmax"), 200.);
	_val.dv = Real_fromValue(map.get("dv"), 30.);
}
		
// -------------------------------------------------------- NavigationPts
// NavigationPts is a vector of Waypoint
value::Value* NavigationPts_toValue(const NavigationPts& _val) {
	value::Set* set = value::Set::create();
	if(set != NULL)
	{
		NavigationPts::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			set->add(Waypoint_toValue(*it)) ;
		}
	}
	return set;
}

void NavigationPts_fromValue(const value::Value* _node, NavigationPts& vect) {
	vect.clear();
	const value::Set& set = _node->toSet();
	for (unsigned int i = 0; i < set.size(); i++) {
		const value::Value* val = set.get(i);
		Waypoint _val;
		Waypoint_fromValue(val, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- FlightConfig
// FlightConfig is a structure
value::Value* FlightConfig_toValue(const FlightConfig& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("emptyWeight",Real_toValue(_val.emptyWeight));
		map->add("payloadWeight",Real_toValue(_val.payloadWeight));
		map->add("fuelWeight",Real_toValue(_val.fuelWeight));
		map->add("min_speed",Real_toValue(_val.min_speed));
		map->add("max_speed",Real_toValue(_val.max_speed));
		map->add("dv",Real_toValue(_val.dv));
		map->add("dt",Long_toValue(_val.dt));
		map->add("altMin",Real_toValue(_val.altMin));
		map->add("altMax",Real_toValue(_val.altMax));
	}
	return map;
}

void FlightConfig_fromValue(const value::Value* _node, FlightConfig& _val) {
	const value::Map& map = _node->toMap();
	_val.emptyWeight = Real_fromValue(map.get("emptyWeight"));
	_val.payloadWeight = Real_fromValue(map.get("payloadWeight"));
	_val.fuelWeight = Real_fromValue(map.get("fuelWeight"));
	_val.min_speed = Real_fromValue(map.get("min_speed"));
	_val.max_speed = Real_fromValue(map.get("max_speed"));
	_val.dv = Real_fromValue(map.get("dv"));
	_val.dt = Long_fromValue(map.get("dt"));
	_val.altMin = Real_fromValue(map.get("altMin"));
	_val.altMax = Real_fromValue(map.get("altMax"));
}
		
// -------------------------------------------------------- NavigationUpdate
// NavigationUpdate is a structure
value::Value* NavigationUpdate_toValue(const NavigationUpdate& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("updated",Long_toValue(_val.updated));
		map->add("initialIndex",Long_toValue(_val.initialIndex));
		map->add("nav",NavigationPts_toValue(_val.nav));
	}
	return map;
}

void NavigationUpdate_fromValue(const value::Value* _node, NavigationUpdate& _val) {
	const value::Map& map = _node->toMap();
	_val.updated = Long_fromValue(map.get("updated"));
	_val.initialIndex = Long_fromValue(map.get("initialIndex"));
	NavigationPts_fromValue(map.get("nav"), _val.nav);
}
		
// -------------------------------------------------------- NavigationState
// NavigationState is a structure
value::Value* NavigationState_toValue(const NavigationState& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("nav_updated",Long_toValue(_val.nav_updated));
		map->add("oldNavIndex",Long_toValue(_val.oldNavIndex));
		map->add("navIndex",Long_toValue(_val.navIndex));
		map->add("wpId",Long_toValue(_val.wpId));
		map->add("distToNextWaypoint",Real_toValue(_val.distToNextWaypoint));
		map->add("nav",NavigationPts_toValue(_val.nav));
	}
	return map;
}

void NavigationState_fromValue(const value::Value* _node, NavigationState& _val) {
	const value::Map& map = _node->toMap();
	_val.nav_updated = Long_fromValue(map.get("nav_updated"));
	_val.oldNavIndex = Long_fromValue(map.get("oldNavIndex"));
	_val.navIndex = Long_fromValue(map.get("navIndex"));
	_val.wpId = Long_fromValue(map.get("wpId"));
	_val.distToNextWaypoint = Real_fromValue(map.get("distToNextWaypoint"));
	NavigationPts_fromValue(map.get("nav"), _val.nav);
}
		
// -------------------------------------------------------- SStateVector
// SStateVector is a structure
value::Value* SStateVector_toValue(const SStateVector& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("isValid",Long_toValue(_val.isValid));
		map->add("Id",Long_toValue(_val.Id));
		map->add("mode",Long_toValue(_val.mode));
		map->add("Latitude",Real_toValue(_val.Latitude));
		map->add("Longitude",Real_toValue(_val.Longitude));
		map->add("Altitude",Real_toValue(_val.Altitude));
		map->add("SpeedN",Real_toValue(_val.SpeedN));
		map->add("SpeedE",Real_toValue(_val.SpeedE));
		map->add("SpeedD",Real_toValue(_val.SpeedD));
		map->add("Heading",Real_toValue(_val.Heading));
		map->add("Pitch",Real_toValue(_val.Pitch));
		map->add("Roll",Real_toValue(_val.Roll));
		map->add("Mach",Real_toValue(_val.Mach));
		map->add("CAS",Real_toValue(_val.CAS));
		map->add("wpID",Long_toValue(_val.wpID));
		map->add("wpDist",Real_toValue(_val.wpDist));
	}
	return map;
}

void SStateVector_fromValue(const value::Value* _node, SStateVector& _val) {
	const value::Map& map = _node->toMap();
	_val.isValid = Long_fromValue(map.get("isValid"));
	_val.Id = Long_fromValue(map.get("Id"));
	_val.mode = Long_fromValue(map.get("mode"));
	_val.Latitude = Real_fromValue(map.get("Latitude"));
	_val.Longitude = Real_fromValue(map.get("Longitude"));
	_val.Altitude = Real_fromValue(map.get("Altitude"));
	_val.SpeedN = Real_fromValue(map.get("SpeedN"));
	_val.SpeedE = Real_fromValue(map.get("SpeedE"));
	_val.SpeedD = Real_fromValue(map.get("SpeedD"));
	_val.Heading = Real_fromValue(map.get("Heading"));
	_val.Pitch = Real_fromValue(map.get("Pitch"));
	_val.Roll = Real_fromValue(map.get("Roll"));
	_val.Mach = Real_fromValue(map.get("Mach"));
	_val.CAS = Real_fromValue(map.get("CAS"));
	_val.wpID = Long_fromValue(map.get("wpID"));
	_val.wpDist = Real_fromValue(map.get("wpDist"));
}
		
// -------------------------------------------------------- SensorTechno
// SensorTechno is a structure
value::Value* SensorTechno_toValue(const SensorTechno& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("id",Long_toValue(_val.id));
		map->add("range",Real_toValue(_val.range));
	}
	return map;
}

void SensorTechno_fromValue(const value::Value* _node, SensorTechno& _val) {
	const value::Map& map = _node->toMap();
	_val.id = Long_fromValue(map.get("id"));
	_val.range = Real_fromValue(map.get("range"));
}
		
// -------------------------------------------------------- SensorTechnos
// SensorTechnos is a vector of SensorTechno
value::Value* SensorTechnos_toValue(const SensorTechnos& _val) {
	value::Set* set = value::Set::create();
	if(set != NULL)
	{
		SensorTechnos::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			set->add(SensorTechno_toValue(*it)) ;
		}
	}
	return set;
}

void SensorTechnos_fromValue(const value::Value* _node, SensorTechnos& vect) {
	vect.clear();
	const value::Set& set = _node->toSet();
	for (unsigned int i = 0; i < set.size(); i++) {
		const value::Value* val = set.get(i);
		SensorTechno _val;
		SensorTechno_fromValue(val, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- SensorDefinition
// SensorDefinition is a structure
value::Value* SensorDefinition_toValue(const SensorDefinition& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("id",Long_toValue(_val.id));
		map->add("type",SensorType_toValue(_val.type));
		map->add("worksWithEntities",Long_toValue(_val.worksWithEntities));
		map->add("worksWithEntityTypes",Longs_toValue(_val.worksWithEntityTypes));
		map->add("technos",SensorTechnos_toValue(_val.technos));
		map->add("usesLineOfSight",Long_toValue(_val.usesLineOfSight));
		map->add("fieldOfRegard",SensorAngularBounds_toValue(_val.fieldOfRegard));
		map->add("fieldOfView",SensorAngularDelta_toValue(_val.fieldOfView));
		map->add("intervisiType",Long_toValue(_val.intervisiType));
		map->add("resolution",Vec3_toValue(_val.resolution));
		map->add("toBeAcquiredDuration",Long_toValue(_val.toBeAcquiredDuration));
		map->add("toBeLostDuration",Long_toValue(_val.toBeLostDuration));
		map->add("canBeJammed",Long_toValue(_val.canBeJammed));
		map->add("historyLenght",Long_toValue(_val.historyLenght));
		map->add("isEmitter",Long_toValue(_val.isEmitter));
	}
	return map;
}

void SensorDefinition_fromValue(const value::Value* _node, SensorDefinition& _val) {
	const value::Map& map = _node->toMap();
	_val.id = Long_fromValue(map.get("id"));
	_val.type = SensorType_fromValue(map.get("type"));
	_val.worksWithEntities = Long_fromValue(map.get("worksWithEntities"));
	Longs_fromValue(map.get("worksWithEntityTypes"), _val.worksWithEntityTypes);
	SensorTechnos_fromValue(map.get("technos"), _val.technos);
	_val.usesLineOfSight = Long_fromValue(map.get("usesLineOfSight"));
	SensorAngularBounds_fromValue(map.get("fieldOfRegard"), _val.fieldOfRegard);
	SensorAngularDelta_fromValue(map.get("fieldOfView"), _val.fieldOfView);
	_val.intervisiType = Long_fromValue(map.get("intervisiType"));
	Vec3_fromValue(map.get("resolution"), _val.resolution);
	_val.toBeAcquiredDuration = Long_fromValue(map.get("toBeAcquiredDuration"));
	_val.toBeLostDuration = Long_fromValue(map.get("toBeLostDuration"));
	_val.canBeJammed = Long_fromValue(map.get("canBeJammed"));
	_val.historyLenght = Long_fromValue(map.get("historyLenght"));
	_val.isEmitter = Long_fromValue(map.get("isEmitter"));
}
		
// -------------------------------------------------------- RadarDefinition
// RadarDefinition is a structure
value::Value* RadarDefinition_toValue(const RadarDefinition& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("bandID",Long_toValue(_val.bandID));
		map->add("range",Real_toValue(_val.range));
		map->add("fov_deltaElevation",Real_toValue(_val.fov_deltaElevation));
		map->add("fov_deltaAzimut",Real_toValue(_val.fov_deltaAzimut));
		map->add("for_elevationMin",Real_toValue(_val.for_elevationMin));
		map->add("for_elevationMax",Real_toValue(_val.for_elevationMax));
		map->add("for_azimutMin",Real_toValue(_val.for_azimutMin));
		map->add("for_azimutMax",Real_toValue(_val.for_azimutMax));
		map->add("toBeAcquiredDuration",Long_toValue(_val.toBeAcquiredDuration));
		map->add("toBeLostDuration",Long_toValue(_val.toBeLostDuration));
	}
	return map;
}

void RadarDefinition_fromValue(const value::Value* _node, RadarDefinition& _val) {
	const value::Map& map = _node->toMap();
	_val.bandID = Long_fromValue(map.get("bandID"));
	_val.range = Real_fromValue(map.get("range"));
	_val.fov_deltaElevation = Real_fromValue(map.get("fov_deltaElevation"));
	_val.fov_deltaAzimut = Real_fromValue(map.get("fov_deltaAzimut"));
	_val.for_elevationMin = Real_fromValue(map.get("for_elevationMin"));
	_val.for_elevationMax = Real_fromValue(map.get("for_elevationMax"));
	_val.for_azimutMin = Real_fromValue(map.get("for_azimutMin"));
	_val.for_azimutMax = Real_fromValue(map.get("for_azimutMax"));
	_val.toBeAcquiredDuration = Long_fromValue(map.get("toBeAcquiredDuration"));
	_val.toBeLostDuration = Long_fromValue(map.get("toBeLostDuration"));
}
		
// -------------------------------------------------------- EsmDefinition
// EsmDefinition is a structure
value::Value* EsmDefinition_toValue(const EsmDefinition& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("bandID",Long_toValue(_val.bandID));
		map->add("range",Real_toValue(_val.range));
		map->add("fov_deltaElevation",Real_toValue(_val.fov_deltaElevation));
		map->add("fov_deltaAzimut",Real_toValue(_val.fov_deltaAzimut));
		map->add("for_elevationMin",Real_toValue(_val.for_elevationMin));
		map->add("for_elevationMax",Real_toValue(_val.for_elevationMax));
		map->add("for_azimutMin",Real_toValue(_val.for_azimutMin));
		map->add("for_azimutMax",Real_toValue(_val.for_azimutMax));
		map->add("toBeAcquiredDuration",Long_toValue(_val.toBeAcquiredDuration));
		map->add("toBeLostDuration",Long_toValue(_val.toBeLostDuration));
	}
	return map;
}

void EsmDefinition_fromValue(const value::Value* _node, EsmDefinition& _val) {
	const value::Map& map = _node->toMap();
	_val.bandID = Long_fromValue(map.get("bandID"));
	_val.range = Real_fromValue(map.get("range"));
	_val.fov_deltaElevation = Real_fromValue(map.get("fov_deltaElevation"));
	_val.fov_deltaAzimut = Real_fromValue(map.get("fov_deltaAzimut"));
	_val.for_elevationMin = Real_fromValue(map.get("for_elevationMin"));
	_val.for_elevationMax = Real_fromValue(map.get("for_elevationMax"));
	_val.for_azimutMin = Real_fromValue(map.get("for_azimutMin"));
	_val.for_azimutMax = Real_fromValue(map.get("for_azimutMax"));
	_val.toBeAcquiredDuration = Long_fromValue(map.get("toBeAcquiredDuration"));
	_val.toBeLostDuration = Long_fromValue(map.get("toBeLostDuration"));
}
		
// -------------------------------------------------------- SensorPlot
// SensorPlot is a structure
value::Value* SensorPlot_toValue(const SensorPlot& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("date",Long_toValue(_val.date));
		map->add("sourceId",Long_toValue(_val.sourceId));
		map->add("sourceType",SensorType_toValue(_val.sourceType));
		map->add("sourceTechno",Long_toValue(_val.sourceTechno));
		map->add("elevation",Real_toValue(_val.elevation));
		map->add("azimut",Real_toValue(_val.azimut));
		map->add("distance",Real_toValue(_val.distance));
		map->add("position",Vec3_toValue(_val.position));
	}
	return map;
}

void SensorPlot_fromValue(const value::Value* _node, SensorPlot& _val) {
	const value::Map& map = _node->toMap();
	_val.date = Long_fromValue(map.get("date"));
	_val.sourceId = Long_fromValue(map.get("sourceId"));
	_val.sourceType = SensorType_fromValue(map.get("sourceType"));
	_val.sourceTechno = Long_fromValue(map.get("sourceTechno"));
	_val.elevation = Real_fromValue(map.get("elevation"));
	_val.azimut = Real_fromValue(map.get("azimut"));
	_val.distance = Real_fromValue(map.get("distance"));
	Vec3_fromValue(map.get("position"), _val.position);
}
		
// -------------------------------------------------------- SensorImage
// SensorImage is a structure
value::Value* SensorImage_toValue(const SensorImage& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("plot",SensorPlot_toValue(_val.plot));
		map->add("objects",EntityStates_toValue(_val.objects));
	}
	return map;
}

void SensorImage_fromValue(const value::Value* _node, SensorImage& _val) {
	const value::Map& map = _node->toMap();
	SensorPlot_fromValue(map.get("plot"), _val.plot);
	EntityStates_fromValue(map.get("objects"), _val.objects);
}
		
// -------------------------------------------------------- SensorImages
// SensorImages is a vector of SensorImage
value::Value* SensorImages_toValue(const SensorImages& _val) {
	value::Set* set = value::Set::create();
	if(set != NULL)
	{
		SensorImages::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			set->add(SensorImage_toValue(*it)) ;
		}
	}
	return set;
}

void SensorImages_fromValue(const value::Value* _node, SensorImages& vect) {
	vect.clear();
	const value::Set& set = _node->toSet();
	for (unsigned int i = 0; i < set.size(); i++) {
		const value::Value* val = set.get(i);
		SensorImage _val;
		SensorImage_fromValue(val, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- SensorPlotVector
// SensorPlotVector is a vector of SensorPlot
value::Value* SensorPlotVector_toValue(const SensorPlotVector& _val) {
	value::Set* set = value::Set::create();
	if(set != NULL)
	{
		SensorPlotVector::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			set->add(SensorPlot_toValue(*it)) ;
		}
	}
	return set;
}

void SensorPlotVector_fromValue(const value::Value* _node, SensorPlotVector& vect) {
	vect.clear();
	const value::Set& set = _node->toSet();
	for (unsigned int i = 0; i < set.size(); i++) {
		const value::Value* val = set.get(i);
		SensorPlot _val;
		SensorPlot_fromValue(val, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- SensorTrack
// SensorTrack is a structure
value::Value* SensorTrack_toValue(const SensorTrack& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("targetId",Long_toValue(_val.targetId));
		map->add("lastUpdateDate",Long_toValue(_val.lastUpdateDate));
		map->add("plots",SensorPlotVector_toValue(_val.plots));
		map->add("tracked",Long_toValue(_val.tracked));
		map->add("detected",Long_toValue(_val.detected));
		map->add("trackTime",Long_toValue(_val.trackTime));
		map->add("deltaAzimut",Real_toValue(_val.deltaAzimut));
		map->add("deltaElevation",Real_toValue(_val.deltaElevation));
		map->add("doNotFollow",Long_toValue(_val.doNotFollow));
	}
	return map;
}

void SensorTrack_fromValue(const value::Value* _node, SensorTrack& _val) {
	const value::Map& map = _node->toMap();
	_val.targetId = Long_fromValue(map.get("targetId"));
	_val.lastUpdateDate = Long_fromValue(map.get("lastUpdateDate"));
	SensorPlotVector_fromValue(map.get("plots"), _val.plots);
	_val.tracked = Long_fromValue(map.get("tracked"));
	_val.detected = Long_fromValue(map.get("detected"));
	_val.trackTime = Long_fromValue(map.get("trackTime"));
	_val.deltaAzimut = Real_fromValue(map.get("deltaAzimut"));
	_val.deltaElevation = Real_fromValue(map.get("deltaElevation"));
	_val.doNotFollow = Long_fromValue(map.get("doNotFollow"));
}
		
// -------------------------------------------------------- SensorTracks
// SensorTracks is a map with key type Long and value type SensorTrack
value::Value* SensorTracks_toValue(const SensorTracks& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		SensorTracks::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			const std::string& key = boost::lexical_cast<std::string>((*it).first);
			const value::Value& val = *SensorTrack_toValue((*it).second);
			map->add(key, val);
		}
	}
	return map;

}

void SensorTracks_fromValue(const value::Value* _node, SensorTracks& _map) {
	const value::Map& map = _node->toMap();
	for (value::Map::const_iterator it = map.begin(); it != map.end(); it++) {
		const Long& key = static_cast<Long>(map.getInt((*it).first));
		const value::Value* val = (*it).second;

		SensorTrack_fromValue(val, _map[key]);
	}
}


		
// -------------------------------------------------------- SensorStatus
// SensorStatus is a structure
value::Value* SensorStatus_toValue(const SensorStatus& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("lastUpdateDate",Long_toValue(_val.lastUpdateDate));
		map->add("id",Long_toValue(_val.id));
		map->add("type",SensorType_toValue(_val.type));
		map->add("available",Long_toValue(_val.available));
		map->add("doingOrderId",Long_toValue(_val.doingOrderId));
		map->add("doingOrderDuration",Long_toValue(_val.doingOrderDuration));
		map->add("endOfOrderId",Long_toValue(_val.endOfOrderId));
		map->add("errorFlag",Long_toValue(_val.errorFlag));
	}
	return map;
}

void SensorStatus_fromValue(const value::Value* _node, SensorStatus& _val) {
	const value::Map& map = _node->toMap();
	_val.lastUpdateDate = Long_fromValue(map.get("lastUpdateDate"));
	_val.id = Long_fromValue(map.get("id"));
	_val.type = SensorType_fromValue(map.get("type"));
	_val.available = Long_fromValue(map.get("available"));
	_val.doingOrderId = Long_fromValue(map.get("doingOrderId"));
	_val.doingOrderDuration = Long_fromValue(map.get("doingOrderDuration"));
	_val.endOfOrderId = Long_fromValue(map.get("endOfOrderId"));
	_val.errorFlag = Long_fromValue(map.get("errorFlag"));
}
		
// -------------------------------------------------------- SensorsStatus
// SensorsStatus is a map with key type Long and value type SensorStatus
value::Value* SensorsStatus_toValue(const SensorsStatus& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		SensorsStatus::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			const std::string& key = boost::lexical_cast<std::string>((*it).first);
			const value::Value& val = *SensorStatus_toValue((*it).second);
			map->add(key, val);
		}
	}
	return map;

}

void SensorsStatus_fromValue(const value::Value* _node, SensorsStatus& _map) {
	const value::Map& map = _node->toMap();
	for (value::Map::const_iterator it = map.begin(); it != map.end(); it++) {
		const Long& key = static_cast<Long>(map.getInt((*it).first));
		const value::Value* val = (*it).second;

		SensorStatus_fromValue(val, _map[key]);
	}
}


		
// -------------------------------------------------------- SensorOrder
// SensorOrder is a structure
value::Value* SensorOrder_toValue(const SensorOrder& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("orderId",Long_toValue(_val.orderId));
		map->add("sensorId",Long_toValue(_val.sensorId));
		map->add("func",SensorFunction_toValue(_val.func));
		map->add("fieldOfRegardNbr",Long_toValue(_val.fieldOfRegardNbr));
		map->add("fieldOfViewNbr",Long_toValue(_val.fieldOfViewNbr));
		map->add("lineOfSightElevation",Real_toValue(_val.lineOfSightElevation));
		map->add("lineOfSightAzimut",Real_toValue(_val.lineOfSightAzimut));
		map->add("duration",Long_toValue(_val.duration));
	}
	return map;
}

void SensorOrder_fromValue(const value::Value* _node, SensorOrder& _val) {
	const value::Map& map = _node->toMap();
	_val.orderId = Long_fromValue(map.get("orderId"));
	_val.sensorId = Long_fromValue(map.get("sensorId"));
	_val.func = SensorFunction_fromValue(map.get("func"));
	_val.fieldOfRegardNbr = Long_fromValue(map.get("fieldOfRegardNbr"));
	_val.fieldOfViewNbr = Long_fromValue(map.get("fieldOfViewNbr"));
	_val.lineOfSightElevation = Real_fromValue(map.get("lineOfSightElevation"));
	_val.lineOfSightAzimut = Real_fromValue(map.get("lineOfSightAzimut"));
	_val.duration = Long_fromValue(map.get("duration"));
}
		
// -------------------------------------------------------- SensorOrders
// SensorOrders is a map with key type Long and value type SensorOrder
value::Value* SensorOrders_toValue(const SensorOrders& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		SensorOrders::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			const std::string& key = boost::lexical_cast<std::string>((*it).first);
			const value::Value& val = *SensorOrder_toValue((*it).second);
			map->add(key, val);
		}
	}
	return map;

}

void SensorOrders_fromValue(const value::Value* _node, SensorOrders& _map) {
	const value::Map& map = _node->toMap();
	for (value::Map::const_iterator it = map.begin(); it != map.end(); it++) {
		const Long& key = static_cast<Long>(map.getInt((*it).first));
		const value::Value* val = (*it).second;

		SensorOrder_fromValue(val, _map[key]);
	}
}


		
// -------------------------------------------------------- SGD
// SGD is a structure
value::Value* SGD_toValue(const SGD& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("hasAB",Long_toValue(_val.hasAB));
		map->add("hasBA",Long_toValue(_val.hasBA));
		map->add("hasBA_RL",Long_toValue(_val.hasBA_RL));
		map->add("hasDist",Long_toValue(_val.hasDist));
		map->add("hasIvisi",Long_toValue(_val.hasIvisi));
		map->add("siteAB",Real_toValue(_val.siteAB));
		map->add("giseAB",Real_toValue(_val.giseAB));
		map->add("siteBA",Real_toValue(_val.siteBA));
		map->add("giseBA",Real_toValue(_val.giseBA));
		map->add("siteBA_RL",Real_toValue(_val.siteBA_RL));
		map->add("giseBA_RL",Real_toValue(_val.giseBA_RL));
		map->add("dist",Real_toValue(_val.dist));
		map->add("ivisi",Long_toValue(_val.ivisi));
		map->add("techno",Long_toValue(_val.techno));
		map->add("range",Real_toValue(_val.range));
	}
	return map;
}

void SGD_fromValue(const value::Value* _node, SGD& _val) {
	const value::Map& map = _node->toMap();
	_val.hasAB = Long_fromValue(map.get("hasAB"));
	_val.hasBA = Long_fromValue(map.get("hasBA"));
	_val.hasBA_RL = Long_fromValue(map.get("hasBA_RL"));
	_val.hasDist = Long_fromValue(map.get("hasDist"));
	_val.hasIvisi = Long_fromValue(map.get("hasIvisi"));
	_val.siteAB = Real_fromValue(map.get("siteAB"));
	_val.giseAB = Real_fromValue(map.get("giseAB"));
	_val.siteBA = Real_fromValue(map.get("siteBA"));
	_val.giseBA = Real_fromValue(map.get("giseBA"));
	_val.siteBA_RL = Real_fromValue(map.get("siteBA_RL"));
	_val.giseBA_RL = Real_fromValue(map.get("giseBA_RL"));
	_val.dist = Real_fromValue(map.get("dist"));
	_val.ivisi = Long_fromValue(map.get("ivisi"));
	_val.techno = Long_fromValue(map.get("techno"));
	_val.range = Real_fromValue(map.get("range"));
}
		
// -------------------------------------------------------- SensorMemory
// SensorMemory is a map with key type Long and value type SGD
value::Value* SensorMemory_toValue(const SensorMemory& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		SensorMemory::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			const std::string& key = boost::lexical_cast<std::string>((*it).first);
			const value::Value& val = *SGD_toValue((*it).second);
			map->add(key, val);
		}
	}
	return map;

}

void SensorMemory_fromValue(const value::Value* _node, SensorMemory& _map) {
	const value::Map& map = _node->toMap();
	for (value::Map::const_iterator it = map.begin(); it != map.end(); it++) {
		const Long& key = static_cast<Long>(map.getInt((*it).first));
		const value::Value* val = (*it).second;

		SGD_fromValue(val, _map[key]);
	}
}


		
// -------------------------------------------------------- SensorDefinitions
// SensorDefinitions is a map with key type Long and value type SensorDefinition
value::Value* SensorDefinitions_toValue(const SensorDefinitions& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		SensorDefinitions::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			const std::string& key = boost::lexical_cast<std::string>((*it).first);
			const value::Value& val = *SensorDefinition_toValue((*it).second);
			map->add(key, val);
		}
	}
	return map;

}

void SensorDefinitions_fromValue(const value::Value* _node, SensorDefinitions& _map) {
	const value::Map& map = _node->toMap();
	for (value::Map::const_iterator it = map.begin(); it != map.end(); it++) {
		const Long& key = static_cast<Long>(map.getInt((*it).first));
		const value::Value* val = (*it).second;

		SensorDefinition_fromValue(val, _map[key]);
	}
}


		
// -------------------------------------------------------- SAElementStatus
// SAElementStatus is a structure
value::Value* SAElementStatus_toValue(const SAElementStatus& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("nid",Long_toValue(_val.nid));
		map->add("type",Long_toValue(_val.type));
		map->add("doing",Long_toValue(_val.doing));
		map->add("pos",Vec3_toValue(_val.pos));
		map->add("date",Long_toValue(_val.date));
		map->add("status",Long_toValue(_val.status));
		map->add("targetId",Long_toValue(_val.targetId));
		map->add("munition",Long_toValue(_val.munition));
		map->add("updated",Long_toValue(_val.updated));
	}
	return map;
}

void SAElementStatus_fromValue(const value::Value* _node, SAElementStatus& _val) {
	const value::Map& map = _node->toMap();
	_val.nid = Long_fromValue(map.get("nid"), 0);
	_val.type = Long_fromValue(map.get("type"), 0);
	_val.doing = Long_fromValue(map.get("doing"), -1);
	Vec3_fromValue(map.get("pos"), _val.pos);
	_val.date = Long_fromValue(map.get("date"), 0);
	_val.status = Long_fromValue(map.get("status"), 0);
	_val.targetId = Long_fromValue(map.get("targetId"));
	_val.munition = Long_fromValue(map.get("munition"), 0);
	_val.updated = Long_fromValue(map.get("updated"), 0);
}
		
// -------------------------------------------------------- SAElementStatusList
// SAElementStatusList is a map with key type Long and value type SAElementStatus
value::Value* SAElementStatusList_toValue(const SAElementStatusList& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		SAElementStatusList::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			const std::string& key = boost::lexical_cast<std::string>((*it).first);
			const value::Value& val = *SAElementStatus_toValue((*it).second);
			map->add(key, val);
		}
	}
	return map;

}

void SAElementStatusList_fromValue(const value::Value* _node, SAElementStatusList& _map) {
	const value::Map& map = _node->toMap();
	for (value::Map::const_iterator it = map.begin(); it != map.end(); it++) {
		const Long& key = static_cast<Long>(map.getInt((*it).first));
		const value::Value* val = (*it).second;

		SAElementStatus_fromValue(val, _map[key]);
	}
}


		
// -------------------------------------------------------- SAElementOrder
// SAElementOrder is a structure
value::Value* SAElementOrder_toValue(const SAElementOrder& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("nid",Long_toValue(_val.nid));
		map->add("orderId",Long_toValue(_val.orderId));
		map->add("order",Long_toValue(_val.order));
		map->add("targetId",Long_toValue(_val.targetId));
	}
	return map;
}

void SAElementOrder_fromValue(const value::Value* _node, SAElementOrder& _val) {
	const value::Map& map = _node->toMap();
	_val.nid = Long_fromValue(map.get("nid"));
	_val.orderId = Long_fromValue(map.get("orderId"));
	_val.order = Long_fromValue(map.get("order"));
	_val.targetId = Long_fromValue(map.get("targetId"));
}
		
// -------------------------------------------------------- SAElementOrderList
// SAElementOrderList is a map with key type Long and value type SAElementOrder
value::Value* SAElementOrderList_toValue(const SAElementOrderList& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		SAElementOrderList::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			const std::string& key = boost::lexical_cast<std::string>((*it).first);
			const value::Value& val = *SAElementOrder_toValue((*it).second);
			map->add(key, val);
		}
	}
	return map;

}

void SAElementOrderList_fromValue(const value::Value* _node, SAElementOrderList& _map) {
	const value::Map& map = _node->toMap();
	for (value::Map::const_iterator it = map.begin(); it != map.end(); it++) {
		const Long& key = static_cast<Long>(map.getInt((*it).first));
		const value::Value* val = (*it).second;

		SAElementOrder_fromValue(val, _map[key]);
	}
}


		
// -------------------------------------------------------- SASystemState
// SASystemState is a structure
value::Value* SASystemState_toValue(const SASystemState& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("nid",Long_toValue(_val.nid));
		map->add("state",Long_toValue(_val.state));
		map->add("ordersCount",Long_toValue(_val.ordersCount));
		map->add("nbrOfV",Long_toValue(_val.nbrOfV));
		map->add("nbrOfCdT",Long_toValue(_val.nbrOfCdT));
		map->add("veilles",Longs_toValue(_val.veilles));
		map->add("cdts",Longs_toValue(_val.cdts));
		map->add("nbrOfActiveV",Long_toValue(_val.nbrOfActiveV));
		map->add("nbrOfActiveCdT",Long_toValue(_val.nbrOfActiveCdT));
	}
	return map;
}

void SASystemState_fromValue(const value::Value* _node, SASystemState& _val) {
	const value::Map& map = _node->toMap();
	_val.nid = Long_fromValue(map.get("nid"), 0);
	_val.state = Long_fromValue(map.get("state"), 0);
	_val.ordersCount = Long_fromValue(map.get("ordersCount"), 0);
	_val.nbrOfV = Long_fromValue(map.get("nbrOfV"), 0);
	_val.nbrOfCdT = Long_fromValue(map.get("nbrOfCdT"), 0);
	Longs_fromValue(map.get("veilles"), _val.veilles);
	Longs_fromValue(map.get("cdts"), _val.cdts);
	_val.nbrOfActiveV = Long_fromValue(map.get("nbrOfActiveV"), 0);
	_val.nbrOfActiveCdT = Long_fromValue(map.get("nbrOfActiveCdT"), 0);
}
		
// -------------------------------------------------------- FlightData
// FlightData is a structure
value::Value* FlightData_toValue(const FlightData& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("position",Vec3_toValue(_val.position));
		map->add("speed",Vec3_toValue(_val.speed));
		map->add("attitudes",Vec3_toValue(_val.attitudes));
		map->add("date",Long_toValue(_val.date));
	}
	return map;
}

void FlightData_fromValue(const value::Value* _node, FlightData& _val) {
	const value::Map& map = _node->toMap();
	Vec3_fromValue(map.get("position"), _val.position);
	Vec3_fromValue(map.get("speed"), _val.speed);
	Vec3_fromValue(map.get("attitudes"), _val.attitudes);
	_val.date = Long_fromValue(map.get("date"));
}
		
// -------------------------------------------------------- NavigationData
// NavigationData is a structure
value::Value* NavigationData_toValue(const NavigationData& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("position",Vec3_toValue(_val.position));
		map->add("speed",Vec3_toValue(_val.speed));
		map->add("attitudes",Vec3_toValue(_val.attitudes));
		map->add("date",Long_toValue(_val.date));
		map->add("wpId",Long_toValue(_val.wpId));
		map->add("distToNextWaypoint",Real_toValue(_val.distToNextWaypoint));
		map->add("nav",NavigationPts_toValue(_val.nav));
	}
	return map;
}

void NavigationData_fromValue(const value::Value* _node, NavigationData& _val) {
	const value::Map& map = _node->toMap();
	Vec3_fromValue(map.get("position"), _val.position);
	Vec3_fromValue(map.get("speed"), _val.speed);
	Vec3_fromValue(map.get("attitudes"), _val.attitudes);
	_val.date = Long_fromValue(map.get("date"));
	_val.wpId = Long_fromValue(map.get("wpId"));
	_val.distToNextWaypoint = Real_fromValue(map.get("distToNextWaypoint"));
	NavigationPts_fromValue(map.get("nav"), _val.nav);
}
		
// -------------------------------------------------------- NetworkDefinition
// NetworkDefinition is a structure
value::Value* NetworkDefinition_toValue(const NetworkDefinition& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("name",String_toValue(_val.name));
		map->add("id",Long_toValue(_val.id));
		map->add("isBLOS",Long_toValue(_val.isBLOS));
		map->add("maxDist",Real_toValue(_val.maxDist));
		map->add("networkBandwidth",Real_toValue(_val.networkBandwidth));
		map->add("maxSendConnectionPerAccess",Long_toValue(_val.maxSendConnectionPerAccess));
		map->add("maxRcvConnectionPerAccess",Long_toValue(_val.maxRcvConnectionPerAccess));
		map->add("maxSendBandwidthPerConnection",Real_toValue(_val.maxSendBandwidthPerConnection));
		map->add("maxRcvBandwidthPerAccess",Real_toValue(_val.maxRcvBandwidthPerAccess));
		map->add("maxConnectionInNetwork",Long_toValue(_val.maxConnectionInNetwork));
		map->add("maxNumberOfAccess",Long_toValue(_val.maxNumberOfAccess));
	}
	return map;
}

void NetworkDefinition_fromValue(const value::Value* _node, NetworkDefinition& _val) {
	const value::Map& map = _node->toMap();
	_val.name = String_fromValue(map.get("name"));
	_val.id = Long_fromValue(map.get("id"));
	_val.isBLOS = Long_fromValue(map.get("isBLOS"));
	_val.maxDist = Real_fromValue(map.get("maxDist"));
	_val.networkBandwidth = Real_fromValue(map.get("networkBandwidth"));
	_val.maxSendConnectionPerAccess = Long_fromValue(map.get("maxSendConnectionPerAccess"));
	_val.maxRcvConnectionPerAccess = Long_fromValue(map.get("maxRcvConnectionPerAccess"));
	_val.maxSendBandwidthPerConnection = Real_fromValue(map.get("maxSendBandwidthPerConnection"));
	_val.maxRcvBandwidthPerAccess = Real_fromValue(map.get("maxRcvBandwidthPerAccess"));
	_val.maxConnectionInNetwork = Long_fromValue(map.get("maxConnectionInNetwork"));
	_val.maxNumberOfAccess = Long_fromValue(map.get("maxNumberOfAccess"));
}
		
// -------------------------------------------------------- NetworkMessagePrivateHeader
// NetworkMessagePrivateHeader is a structure
value::Value* NetworkMessagePrivateHeader_toValue(const NetworkMessagePrivateHeader& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("timestamp",Long_toValue(_val.timestamp));
		map->add("sizeTransmitted",Real_toValue(_val.sizeTransmitted));
	}
	return map;
}

void NetworkMessagePrivateHeader_fromValue(const value::Value* _node, NetworkMessagePrivateHeader& _val) {
	const value::Map& map = _node->toMap();
	_val.timestamp = Long_fromValue(map.get("timestamp"));
	_val.sizeTransmitted = Real_fromValue(map.get("sizeTransmitted"));
}
		
// -------------------------------------------------------- NetworkMessageUserHeader
// NetworkMessageUserHeader is a structure
value::Value* NetworkMessageUserHeader_toValue(const NetworkMessageUserHeader& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("networkId",NetworkID_toValue(_val.networkId));
		map->add("fromId",Long_toValue(_val.fromId));
		map->add("toId",Long_toValue(_val.toId));
		map->add("networkMsgId",Long_toValue(_val.networkMsgId));
		map->add("dataSize",Long_toValue(_val.dataSize));
		map->add("category",Long_toValue(_val.category));
	}
	return map;
}

void NetworkMessageUserHeader_fromValue(const value::Value* _node, NetworkMessageUserHeader& _val) {
	const value::Map& map = _node->toMap();
	_val.networkId = NetworkID_fromValue(map.get("networkId"));
	_val.fromId = Long_fromValue(map.get("fromId"));
	_val.toId = Long_fromValue(map.get("toId"));
	_val.networkMsgId = Long_fromValue(map.get("networkMsgId"));
	_val.dataSize = Long_fromValue(map.get("dataSize"));
	_val.category = Long_fromValue(map.get("category"));
}
		
// -------------------------------------------------------- NetworkMessageUserData
///
/// ERROR NetworkMessageUserData is unrecognized by the generator - org.eclipse.emf.ecore.impl.EClassImpl@1cd6b3c (name: unionType) (instanceClassName: null) (abstract: false, interface: false)
///
		
// -------------------------------------------------------- NetworkMessage
// NetworkMessage is a structure
value::Value* NetworkMessage_toValue(const NetworkMessage& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("uheader",NetworkMessageUserHeader_toValue(_val.uheader));
		map->add("pheader",NetworkMessagePrivateHeader_toValue(_val.pheader));
		// unauthorized union type for data
	}
	return map;
}

void NetworkMessage_fromValue(const value::Value* _node, NetworkMessage& _val) {
	const value::Map& map = _node->toMap();
	NetworkMessageUserHeader_fromValue(map.get("uheader"), _val.uheader);
	NetworkMessagePrivateHeader_fromValue(map.get("pheader"), _val.pheader);
	// unauthorized union type for data
}
		
// -------------------------------------------------------- NetworkMessageDeliveryReport
// NetworkMessageDeliveryReport is a map with key type Long and value type Long
value::Value* NetworkMessageDeliveryReport_toValue(const NetworkMessageDeliveryReport& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		NetworkMessageDeliveryReport::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			const std::string& key = boost::lexical_cast<std::string>((*it).first);
			const value::Value& val = *Long_toValue((*it).second);
			map->add(key, val);
		}
	}
	return map;

}

void NetworkMessageDeliveryReport_fromValue(const value::Value* _node, NetworkMessageDeliveryReport& _map) {
	const value::Map& map = _node->toMap();
	for (value::Map::const_iterator it = map.begin(); it != map.end(); it++) {
		const Long& key = static_cast<Long>(map.getInt((*it).first));
		const value::Value* val = (*it).second;

		Long_fromValue(val, _map[key]);
	}
}


		
// -------------------------------------------------------- NetworkMessageDeliveryReports
// NetworkMessageDeliveryReports is a map with key type Long and value type NetworkMessageDeliveryReport
value::Value* NetworkMessageDeliveryReports_toValue(const NetworkMessageDeliveryReports& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		NetworkMessageDeliveryReports::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			const std::string& key = boost::lexical_cast<std::string>((*it).first);
			const value::Value& val = *NetworkMessageDeliveryReport_toValue((*it).second);
			map->add(key, val);
		}
	}
	return map;

}

void NetworkMessageDeliveryReports_fromValue(const value::Value* _node, NetworkMessageDeliveryReports& _map) {
	const value::Map& map = _node->toMap();
	for (value::Map::const_iterator it = map.begin(); it != map.end(); it++) {
		const Long& key = static_cast<Long>(map.getInt((*it).first));
		const value::Value* val = (*it).second;

		NetworkMessageDeliveryReport_fromValue(val, _map[key]);
	}
}


		
// -------------------------------------------------------- NetworkList
// NetworkList is a map with key type Long and value type Long
value::Value* NetworkList_toValue(const NetworkList& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		NetworkList::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			const std::string& key = boost::lexical_cast<std::string>((*it).first);
			const value::Value& val = *Long_toValue((*it).second);
			map->add(key, val);
		}
	}
	return map;

}

void NetworkList_fromValue(const value::Value* _node, NetworkList& _map) {
	const value::Map& map = _node->toMap();
	for (value::Map::const_iterator it = map.begin(); it != map.end(); it++) {
		const Long& key = static_cast<Long>(map.getInt((*it).first));
		const value::Value* val = (*it).second;

		Long_fromValue(val, _map[key]);
	}
}


		
// -------------------------------------------------------- NetworkMessageList
// NetworkMessageList is a vector of NetworkMessage
value::Value* NetworkMessageList_toValue(const NetworkMessageList& _val) {
	value::Set* set = value::Set::create();
	if(set != NULL)
	{
		NetworkMessageList::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			set->add(NetworkMessage_toValue(*it)) ;
		}
	}
	return set;
}

void NetworkMessageList_fromValue(const value::Value* _node, NetworkMessageList& vect) {
	vect.clear();
	const value::Set& set = _node->toSet();
	for (unsigned int i = 0; i < set.size(); i++) {
		const value::Value* val = set.get(i);
		NetworkMessage _val;
		NetworkMessage_fromValue(val, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- NetworkDefinitions
// NetworkDefinitions is a map with key type Long and value type NetworkDefinition
value::Value* NetworkDefinitions_toValue(const NetworkDefinitions& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		NetworkDefinitions::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			const std::string& key = boost::lexical_cast<std::string>((*it).first);
			const value::Value& val = *NetworkDefinition_toValue((*it).second);
			map->add(key, val);
		}
	}
	return map;

}

void NetworkDefinitions_fromValue(const value::Value* _node, NetworkDefinitions& _map) {
	const value::Map& map = _node->toMap();
	for (value::Map::const_iterator it = map.begin(); it != map.end(); it++) {
		const Long& key = static_cast<Long>(map.getInt((*it).first));
		const value::Value* val = (*it).second;

		NetworkDefinition_fromValue(val, _map[key]);
	}
}


		
// -------------------------------------------------------- test
// test is a structure
value::Value* test_toValue(const test& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("fromId",Long_toValue(_val.fromId));
		map->add("toId",Long_toValue(_val.toId));
	}
	return map;
}

void test_fromValue(const value::Value* _node, test& _val) {
	const value::Map& map = _node->toMap();
	_val.fromId = Long_fromValue(map.get("fromId"));
	_val.toId = Long_fromValue(map.get("toId"));
}
		
// -------------------------------------------------------- TestMatlabStruct2
// TestMatlabStruct2 is a structure
value::Value* TestMatlabStruct2_toValue(const TestMatlabStruct2& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("i",Long_toValue(_val.i));
		map->add("j",Long_toValue(_val.j));
		map->add("x",Real_toValue(_val.x));
	}
	return map;
}

void TestMatlabStruct2_fromValue(const value::Value* _node, TestMatlabStruct2& _val) {
	const value::Map& map = _node->toMap();
	_val.i = Long_fromValue(map.get("i"));
	_val.j = Long_fromValue(map.get("j"));
	_val.x = Real_fromValue(map.get("x"));
}
		
// -------------------------------------------------------- TestMatlabStruct2List
// TestMatlabStruct2List is a vector of TestMatlabStruct2
value::Value* TestMatlabStruct2List_toValue(const TestMatlabStruct2List& _val) {
	value::Set* set = value::Set::create();
	if(set != NULL)
	{
		TestMatlabStruct2List::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			set->add(TestMatlabStruct2_toValue(*it)) ;
		}
	}
	return set;
}

void TestMatlabStruct2List_fromValue(const value::Value* _node, TestMatlabStruct2List& vect) {
	vect.clear();
	const value::Set& set = _node->toSet();
	for (unsigned int i = 0; i < set.size(); i++) {
		const value::Value* val = set.get(i);
		TestMatlabStruct2 _val;
		TestMatlabStruct2_fromValue(val, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- TestMatlabStruct
// TestMatlabStruct is a structure
value::Value* TestMatlabStruct_toValue(const TestMatlabStruct& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("unLong",Long_toValue(_val.unLong));
		map->add("unReal",Real_toValue(_val.unReal));
		map->add("unVec3",Vec3_toValue(_val.unVec3));
		map->add("unVecteurDeLongs",Longs_toValue(_val.unVecteurDeLongs));
		map->add("uneListe",TestMatlabStruct2List_toValue(_val.uneListe));
	}
	return map;
}

void TestMatlabStruct_fromValue(const value::Value* _node, TestMatlabStruct& _val) {
	const value::Map& map = _node->toMap();
	_val.unLong = Long_fromValue(map.get("unLong"));
	_val.unReal = Real_fromValue(map.get("unReal"));
	Vec3_fromValue(map.get("unVec3"), _val.unVec3);
	Longs_fromValue(map.get("unVecteurDeLongs"), _val.unVecteurDeLongs);
	TestMatlabStruct2List_fromValue(map.get("uneListe"), _val.uneListe);
}
		
// -------------------------------------------------------- TestJavaStruct2
// TestJavaStruct2 is a structure
value::Value* TestJavaStruct2_toValue(const TestJavaStruct2& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("i",Long_toValue(_val.i));
		map->add("j",Long_toValue(_val.j));
		map->add("x",Real_toValue(_val.x));
	}
	return map;
}

void TestJavaStruct2_fromValue(const value::Value* _node, TestJavaStruct2& _val) {
	const value::Map& map = _node->toMap();
	_val.i = Long_fromValue(map.get("i"));
	_val.j = Long_fromValue(map.get("j"));
	_val.x = Real_fromValue(map.get("x"));
}
		
// -------------------------------------------------------- TestJavaStruct2List
// TestJavaStruct2List is a vector of TestJavaStruct2
value::Value* TestJavaStruct2List_toValue(const TestJavaStruct2List& _val) {
	value::Set* set = value::Set::create();
	if(set != NULL)
	{
		TestJavaStruct2List::const_iterator it = _val.begin();
		for (;it != _val.end(); it++) {
			set->add(TestJavaStruct2_toValue(*it)) ;
		}
	}
	return set;
}

void TestJavaStruct2List_fromValue(const value::Value* _node, TestJavaStruct2List& vect) {
	vect.clear();
	const value::Set& set = _node->toSet();
	for (unsigned int i = 0; i < set.size(); i++) {
		const value::Value* val = set.get(i);
		TestJavaStruct2 _val;
		TestJavaStruct2_fromValue(val, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- TestJavaStruct
// TestJavaStruct is a structure
value::Value* TestJavaStruct_toValue(const TestJavaStruct& _val) {
	value::Map* map = value::Map::create();
	if(map != NULL)
	{
		map->add("unLong",Long_toValue(_val.unLong));
		map->add("unReal",Real_toValue(_val.unReal));
		map->add("unVec3",Vec3_toValue(_val.unVec3));
		map->add("unVecX",VecX_toValue(_val.unVecX));
		map->add("unVecteurDeLongs",Longs_toValue(_val.unVecteurDeLongs));
		map->add("uneListe",TestMatlabStruct2List_toValue(_val.uneListe));
	}
	return map;
}

void TestJavaStruct_fromValue(const value::Value* _node, TestJavaStruct& _val) {
	const value::Map& map = _node->toMap();
	_val.unLong = Long_fromValue(map.get("unLong"));
	_val.unReal = Real_fromValue(map.get("unReal"));
	Vec3_fromValue(map.get("unVec3"), _val.unVec3);
	VecX_fromValue(map.get("unVecX"), _val.unVecX);
	Longs_fromValue(map.get("unVecteurDeLongs"), _val.unVecteurDeLongs);
	TestMatlabStruct2List_fromValue(map.get("uneListe"), _val.uneListe);
}
		

// 
// ------------------------------------------------------------------------------------
//
} // eof namespace generated

