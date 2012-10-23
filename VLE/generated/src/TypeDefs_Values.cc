// 
// Includes ----------------------------------------------------------------------
// 

#include <sstream>
#include <iomanip>
#include <boost/lexical_cast.hpp>
#include <iostream>

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
	value::Value* xn = (value::Value*)_val;
	return xn;
}

Pointer Pointer_fromValue(const value::Value* _node, const Pointer& _initialValue) {
	return (void*)_initialValue;
}
		
// -------------------------------------------------------- String
// basic type String
value::Value* String_toValue(const String& _val) {
	value::Value* xn = value::String::create(_val);
	return xn;
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
	value::Value* xn = value::Boolean::create(_val);
	return xn;
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
	value::Value* xn = value::Integer::create(_val);
	return xn;
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
	value::Value* xn = value::Integer::create(_val);
	return xn;
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
	value::Value* xn = value::Double::create(_val);
	return xn;
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
	value::Set* xn = value::Set::create();
	for(unsigned int _i=0; _i<3; _i++) {
		xn->add(Real_toValue(_val[_i])) ;
	}
	return xn;
}
void Vec3_fromValue(const value::Value* _node,Vec3& _val) {
	const value::Set& _xn = _node->toSet();
	for(unsigned int _i=0; _i<3; _i++) {
		_val[_i] = Real_fromValue(_xn.get(_i)) ;
	}

}

		
// -------------------------------------------------------- Vec5
// Vec5 is an array of Real
value::Value* Vec5_toValue(const Vec5& _val) {
	value::Set* xn = value::Set::create();
	for(unsigned int _i=0; _i<5; _i++) {
		xn->add(Real_toValue(_val[_i])) ;
	}
	return xn;
}
void Vec5_fromValue(const value::Value* _node,Vec5& _val) {
	const value::Set& _xn = _node->toSet();
	for(unsigned int _i=0; _i<5; _i++) {
		_val[_i] = Real_fromValue(_xn.get(_i)) ;
	}

}

		
// -------------------------------------------------------- VecX
// VecX is an array of Real
value::Value* VecX_toValue(const VecX& _val) {
	value::Set* xn = value::Set::create();
	// Conversion to Value: only one dimension arrays are accepted !
	return xn;
}
void VecX_fromValue(const value::Value* _node,VecX& _val) {
	// Conversion from Value: only one dimension arrays are accepted !

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
	value::Set* xn = value::Set::create();
	for(unsigned int _i=0; _i<_val->num_elements(); _i++) {
		xn->add(Real_toValue((*_val)[_i])) ;
	}
	return xn;
}
void VecOne_fromValue(const value::Value* _node,VecOne& _val) {
	const value::Set& _xn = _node->toSet();
	for(unsigned int _i=0; _i<_val->num_elements(); _i++) {
		(*_val)[_i] = Real_fromValue(_xn.get(_i)) ;
	}

}

		
// -------------------------------------------------------- VecY
// VecY is an array of gisement
value::Value* VecY_toValue(const VecY& _val) {
	value::Set* xn = value::Set::create();
	for(unsigned int _i=0; _i<3; _i++) {
		xn->add(Real_toValue(_val[_i])) ;
	}
	return xn;
}
void VecY_fromValue(const value::Value* _node,VecY& _val) {
	const value::Set& _xn = _node->toSet();
	for(unsigned int _i=0; _i<3; _i++) {
		_val[_i] = Real_fromValue(_xn.get(_i)) ;
	}

}

		
// -------------------------------------------------------- test3
// test3 is a structure
value::Value* test3_toValue(const test3& _val) {
	value::Map* xn = value::Map::create();
	xn->add("hello",Real_toValue(_val.hello));
	xn->add("g",gisement_toValue(_val.g));
	return xn;
}

void test3_fromValue(const value::Value* _node, test3& _val) {
	const value::Map& _xn = _node->toMap();
	_val.hello = Real_fromValue(_xn.get("hello"));
	_val.g = Real_fromValue(_xn.get("g"));
}
		
// -------------------------------------------------------- Ints
// Ints is a vector of Int
value::Value* Ints_toValue(const Ints& _val) {
	value::Set* _xn = value::Set::create();
	Ints::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		_xn->add(Int_toValue(*it)) ;
	}
	return _xn;
}

void Ints_fromValue(const value::Value* _node, Ints& vect) {
	vect.clear();
	const value::Set& _xn = _node->toSet();
	for (unsigned int _i=0; _i<_xn.size(); _i++) {
		const value::Value* _n = _xn.get(_i);
		Int _val;
		Int_fromValue(_n, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- Longs
// Longs is a vector of Long
value::Value* Longs_toValue(const Longs& _val) {
	value::Set* _xn = value::Set::create();
	Longs::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		_xn->add(Long_toValue(*it)) ;
	}
	return _xn;
}

void Longs_fromValue(const value::Value* _node, Longs& vect) {
	vect.clear();
	const value::Set& _xn = _node->toSet();
	for (unsigned int _i=0; _i<_xn.size(); _i++) {
		const value::Value* _n = _xn.get(_i);
		Long _val;
		Long_fromValue(_n, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- Reals
// Reals is a vector of Real
value::Value* Reals_toValue(const Reals& _val) {
	value::Set* _xn = value::Set::create();
	Reals::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		_xn->add(Real_toValue(*it)) ;
	}
	return _xn;
}

void Reals_fromValue(const value::Value* _node, Reals& vect) {
	vect.clear();
	const value::Set& _xn = _node->toSet();
	for (unsigned int _i=0; _i<_xn.size(); _i++) {
		const value::Value* _n = _xn.get(_i);
		Real _val;
		Real_fromValue(_n, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- EntityType
// basic type EntityType
value::Value* EntityType_toValue(const EntityType& _val) {
	value::Value* xn = value::Integer::create(_val);
	return xn;
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
	value::Value* xn = value::Integer::create(_val);
	return xn;
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
	value::Value* xn = value::Integer::create(_val);
	return xn;
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
	value::Value* xn = value::Integer::create(_val);
	return xn;
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
	value::Value* xn = value::Integer::create(_val);
	return xn;
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
	value::Map* xn = value::Map::create();
	xn->add("type",Long_toValue(_val.type));
	xn->add("id",Long_toValue(_val.id));
	xn->add("available",Long_toValue(_val.available));
	xn->add("enabled",Long_toValue(_val.enabled));
	return xn;
}

void EquipmentStatus_fromValue(const value::Value* _node, EquipmentStatus& _val) {
	const value::Map& _xn = _node->toMap();
	_val.type = Long_fromValue(_xn.get("type"));
	_val.id = Long_fromValue(_xn.get("id"));
	_val.available = Long_fromValue(_xn.get("available"), 100);
	_val.enabled = Long_fromValue(_xn.get("enabled"), 0);
}
		
// -------------------------------------------------------- EquipmentStatusList
// EquipmentStatusList is a map with key type Long and value type EquipmentStatus
value::Value* EquipmentStatusList_toValue(const EquipmentStatusList& _val) {
	value::Map* _xn = value::Map::create();
	EquipmentStatusList::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		const std::string& key = boost::lexical_cast<std::string>((*it).first);
		const value::Value& val = *EquipmentStatus_toValue((*it).second);
		_xn->add(key, val);
	}
	return _xn;

}

void EquipmentStatusList_fromValue(const value::Value* _node, EquipmentStatusList& map) {
	const value::Map& _xn = _node->toMap();
	for (value::Map::const_iterator it=_xn.begin(); it!=_xn.end(); it++) {
		const Long& key = static_cast<Long>(_xn.getInt((*it).first));
		const value::Value* _n = (*it).second;

		EquipmentStatus_fromValue(_n, map[key]);
	}
}


		
// -------------------------------------------------------- ExternalInput
// ExternalInput is a structure
value::Value* ExternalInput_toValue(const ExternalInput& _val) {
	value::Map* xn = value::Map::create();
	xn->add("id",Long_toValue(_val.id));
	xn->add("duration",Long_toValue(_val.duration));
	xn->add("available_during",Long_toValue(_val.available_during));
	xn->add("available_after",Long_toValue(_val.available_after));
	return xn;
}

void ExternalInput_fromValue(const value::Value* _node, ExternalInput& _val) {
	const value::Map& _xn = _node->toMap();
	_val.id = Long_fromValue(_xn.get("id"));
	_val.duration = Long_fromValue(_xn.get("duration"));
	_val.available_during = Long_fromValue(_xn.get("available_during"));
	_val.available_after = Long_fromValue(_xn.get("available_after"));
}
		
// -------------------------------------------------------- vExternalInput
// vExternalInput is a vector of ExternalInput
value::Value* vExternalInput_toValue(const vExternalInput& _val) {
	value::Set* _xn = value::Set::create();
	vExternalInput::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		_xn->add(ExternalInput_toValue(*it)) ;
	}
	return _xn;
}

void vExternalInput_fromValue(const value::Value* _node, vExternalInput& vect) {
	vect.clear();
	const value::Set& _xn = _node->toSet();
	for (unsigned int _i=0; _i<_xn.size(); _i++) {
		const value::Value* _n = _xn.get(_i);
		ExternalInput _val;
		ExternalInput_fromValue(_n, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- ExternalInputListForOneTypeOfEquipment
// ExternalInputListForOneTypeOfEquipment is a map with key type EquipmentType and value type vExternalInput
value::Value* ExternalInputListForOneTypeOfEquipment_toValue(const ExternalInputListForOneTypeOfEquipment& _val) {
	value::Map* _xn = value::Map::create();
	ExternalInputListForOneTypeOfEquipment::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		const std::string& key = boost::lexical_cast<std::string>((*it).first);
		const value::Value& val = *vExternalInput_toValue((*it).second);
		_xn->add(key, val);
	}
	return _xn;

}

void ExternalInputListForOneTypeOfEquipment_fromValue(const value::Value* _node, ExternalInputListForOneTypeOfEquipment& map) {
	const value::Map& _xn = _node->toMap();
	for (value::Map::const_iterator it=_xn.begin(); it!=_xn.end(); it++) {
		const EquipmentType& key = static_cast<EquipmentType>(_xn.getInt((*it).first));
		const value::Value* _n = (*it).second;

		vExternalInput_fromValue(_n, map[key]);
	}
}


		
// -------------------------------------------------------- ExternalInputList
// ExternalInputList is a map with key type Long and value type ExternalInputListForOneTypeOfEquipment
value::Value* ExternalInputList_toValue(const ExternalInputList& _val) {
	value::Map* _xn = value::Map::create();
	ExternalInputList::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		const std::string& key = boost::lexical_cast<std::string>((*it).first);
		const value::Value& val = *ExternalInputListForOneTypeOfEquipment_toValue((*it).second);
		_xn->add(key, val);
	}
	return _xn;

}

void ExternalInputList_fromValue(const value::Value* _node, ExternalInputList& map) {
	const value::Map& _xn = _node->toMap();
	for (value::Map::const_iterator it=_xn.begin(); it!=_xn.end(); it++) {
		const Long& key = static_cast<Long>(_xn.getInt((*it).first));
		const value::Value* _n = (*it).second;

		ExternalInputListForOneTypeOfEquipment_fromValue(_n, map[key]);
	}
}


		
// -------------------------------------------------------- EntityState
// EntityState is a structure
value::Value* EntityState_toValue(const EntityState& _val) {
	value::Map* xn = value::Map::create();
	xn->add("time",Long_toValue(_val.time));
	xn->add("id",Long_toValue(_val.id));
	xn->add("side",Long_toValue(_val.side));
	xn->add("type",EntityType_toValue(_val.type));
	xn->add("subtype",Long_toValue(_val.subtype));
	xn->add("subsubtype",Long_toValue(_val.subsubtype));
	xn->add("position",Vec3_toValue(_val.position));
	xn->add("speed",Vec3_toValue(_val.speed));
	xn->add("attitudes",Vec3_toValue(_val.attitudes));
	return xn;
}

void EntityState_fromValue(const value::Value* _node, EntityState& _val) {
	const value::Map& _xn = _node->toMap();
	_val.time = Long_fromValue(_xn.get("time"));
	_val.id = Long_fromValue(_xn.get("id"));
	_val.side = Long_fromValue(_xn.get("side"));
	_val.type = EntityType_fromValue(_xn.get("type"));
	_val.subtype = Long_fromValue(_xn.get("subtype"));
	_val.subsubtype = Long_fromValue(_xn.get("subsubtype"));
	Vec3_fromValue(_xn.get("position"), _val.position);
	Vec3_fromValue(_xn.get("speed"), _val.speed);
	Vec3_fromValue(_xn.get("attitudes"), _val.attitudes);
}
		
// -------------------------------------------------------- EntityStates
// EntityStates is a map with key type Long and value type EntityState
value::Value* EntityStates_toValue(const EntityStates& _val) {
	value::Map* _xn = value::Map::create();
	EntityStates::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		const std::string& key = boost::lexical_cast<std::string>((*it).first);
		const value::Value& val = *EntityState_toValue((*it).second);
		_xn->add(key, val);
	}
	return _xn;

}

void EntityStates_fromValue(const value::Value* _node, EntityStates& map) {
	const value::Map& _xn = _node->toMap();
	for (value::Map::const_iterator it=_xn.begin(); it!=_xn.end(); it++) {
		const Long& key = static_cast<Long>(_xn.getInt((*it).first));
		const value::Value* _n = (*it).second;

		EntityState_fromValue(_n, map[key]);
	}
}


		
// -------------------------------------------------------- EmitterBeam
// EmitterBeam is a structure
value::Value* EmitterBeam_toValue(const EmitterBeam& _val) {
	value::Map* xn = value::Map::create();
	xn->add("elevation",Real_toValue(_val.elevation));
	xn->add("azimut",Real_toValue(_val.azimut));
	xn->add("elevationAperture",Real_toValue(_val.elevationAperture));
	xn->add("azimutAperture",Real_toValue(_val.azimutAperture));
	xn->add("targets",Longs_toValue(_val.targets));
	return xn;
}

void EmitterBeam_fromValue(const value::Value* _node, EmitterBeam& _val) {
	const value::Map& _xn = _node->toMap();
	_val.elevation = Real_fromValue(_xn.get("elevation"));
	_val.azimut = Real_fromValue(_xn.get("azimut"));
	_val.elevationAperture = Real_fromValue(_xn.get("elevationAperture"));
	_val.azimutAperture = Real_fromValue(_xn.get("azimutAperture"));
	Longs_fromValue(_xn.get("targets"), _val.targets);
}
		
// -------------------------------------------------------- Beams
// Beams is a vector of EmitterBeam
value::Value* Beams_toValue(const Beams& _val) {
	value::Set* _xn = value::Set::create();
	Beams::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		_xn->add(EmitterBeam_toValue(*it)) ;
	}
	return _xn;
}

void Beams_fromValue(const value::Value* _node, Beams& vect) {
	vect.clear();
	const value::Set& _xn = _node->toSet();
	for (unsigned int _i=0; _i<_xn.size(); _i++) {
		const value::Value* _n = _xn.get(_i);
		EmitterBeam _val;
		EmitterBeam_fromValue(_n, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- EmitterState
// EmitterState is a structure
value::Value* EmitterState_toValue(const EmitterState& _val) {
	value::Map* xn = value::Map::create();
	xn->add("time",Long_toValue(_val.time));
	xn->add("entityID",Long_toValue(_val.entityID));
	xn->add("type",SensorType_toValue(_val.type));
	xn->add("techno",Long_toValue(_val.techno));
	xn->add("dist1m2",Real_toValue(_val.dist1m2));
	xn->add("beams",Beams_toValue(_val.beams));
	return xn;
}

void EmitterState_fromValue(const value::Value* _node, EmitterState& _val) {
	const value::Map& _xn = _node->toMap();
	_val.time = Long_fromValue(_xn.get("time"));
	_val.entityID = Long_fromValue(_xn.get("entityID"));
	_val.type = SensorType_fromValue(_xn.get("type"));
	_val.techno = Long_fromValue(_xn.get("techno"));
	_val.dist1m2 = Real_fromValue(_xn.get("dist1m2"));
	Beams_fromValue(_xn.get("beams"), _val.beams);
}
		
// -------------------------------------------------------- EmitterStates
// EmitterStates is a vector of EmitterState
value::Value* EmitterStates_toValue(const EmitterStates& _val) {
	value::Set* _xn = value::Set::create();
	EmitterStates::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		_xn->add(EmitterState_toValue(*it)) ;
	}
	return _xn;
}

void EmitterStates_fromValue(const value::Value* _node, EmitterStates& vect) {
	vect.clear();
	const value::Set& _xn = _node->toSet();
	for (unsigned int _i=0; _i<_xn.size(); _i++) {
		const value::Value* _n = _xn.get(_i);
		EmitterState _val;
		EmitterState_fromValue(_n, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- JammerState
// JammerState is a structure
value::Value* JammerState_toValue(const JammerState& _val) {
	value::Map* xn = value::Map::create();
	xn->add("time",Long_toValue(_val.time));
	xn->add("entityID",Long_toValue(_val.entityID));
	xn->add("type",Long_toValue(_val.type));
	xn->add("techno",Long_toValue(_val.techno));
	xn->add("elevation",Real_toValue(_val.elevation));
	xn->add("azimut",Real_toValue(_val.azimut));
	xn->add("apertureEl",Real_toValue(_val.apertureEl));
	xn->add("apertureAz",Real_toValue(_val.apertureAz));
	xn->add("powerOrDistance",Real_toValue(_val.powerOrDistance));
	return xn;
}

void JammerState_fromValue(const value::Value* _node, JammerState& _val) {
	const value::Map& _xn = _node->toMap();
	_val.time = Long_fromValue(_xn.get("time"));
	_val.entityID = Long_fromValue(_xn.get("entityID"));
	_val.type = Long_fromValue(_xn.get("type"));
	_val.techno = Long_fromValue(_xn.get("techno"));
	_val.elevation = Real_fromValue(_xn.get("elevation"));
	_val.azimut = Real_fromValue(_xn.get("azimut"));
	_val.apertureEl = Real_fromValue(_xn.get("apertureEl"));
	_val.apertureAz = Real_fromValue(_xn.get("apertureAz"));
	_val.powerOrDistance = Real_fromValue(_xn.get("powerOrDistance"));
}
		
// -------------------------------------------------------- JammerStates
// JammerStates is a vector of JammerState
value::Value* JammerStates_toValue(const JammerStates& _val) {
	value::Set* _xn = value::Set::create();
	JammerStates::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		_xn->add(JammerState_toValue(*it)) ;
	}
	return _xn;
}

void JammerStates_fromValue(const value::Value* _node, JammerStates& vect) {
	vect.clear();
	const value::Set& _xn = _node->toSet();
	for (unsigned int _i=0; _i<_xn.size(); _i++) {
		const value::Value* _n = _xn.get(_i);
		JammerState _val;
		JammerState_fromValue(_n, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- Detonation
// Detonation is a structure
value::Value* Detonation_toValue(const Detonation& _val) {
	value::Map* xn = value::Map::create();
	xn->add("time",Long_toValue(_val.time));
	xn->add("shooterID",Long_toValue(_val.shooterID));
	xn->add("weaponType",Long_toValue(_val.weaponType));
	xn->add("targets",Longs_toValue(_val.targets));
	xn->add("position",Vec3_toValue(_val.position));
	return xn;
}

void Detonation_fromValue(const value::Value* _node, Detonation& _val) {
	const value::Map& _xn = _node->toMap();
	_val.time = Long_fromValue(_xn.get("time"));
	_val.shooterID = Long_fromValue(_xn.get("shooterID"));
	_val.weaponType = Long_fromValue(_xn.get("weaponType"));
	Longs_fromValue(_xn.get("targets"), _val.targets);
	Vec3_fromValue(_xn.get("position"), _val.position);
}
		
// -------------------------------------------------------- Detonations
// Detonations is a map with key type Long and value type Detonation
value::Value* Detonations_toValue(const Detonations& _val) {
	value::Map* _xn = value::Map::create();
	Detonations::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		const std::string& key = boost::lexical_cast<std::string>((*it).first);
		const value::Value& val = *Detonation_toValue((*it).second);
		_xn->add(key, val);
	}
	return _xn;

}

void Detonations_fromValue(const value::Value* _node, Detonations& map) {
	const value::Map& _xn = _node->toMap();
	for (value::Map::const_iterator it=_xn.begin(); it!=_xn.end(); it++) {
		const Long& key = static_cast<Long>(_xn.getInt((*it).first));
		const value::Value* _n = (*it).second;

		Detonation_fromValue(_n, map[key]);
	}
}


		
// -------------------------------------------------------- EnvironmentInteractions
// EnvironmentInteractions is a structure
value::Value* EnvironmentInteractions_toValue(const EnvironmentInteractions& _val) {
	value::Map* xn = value::Map::create();
	xn->add("entities",EntityStates_toValue(_val.entities));
	xn->add("emitters",EmitterStates_toValue(_val.emitters));
	xn->add("jammers",JammerStates_toValue(_val.jammers));
	xn->add("detonations",Detonations_toValue(_val.detonations));
	return xn;
}

void EnvironmentInteractions_fromValue(const value::Value* _node, EnvironmentInteractions& _val) {
	const value::Map& _xn = _node->toMap();
	EntityStates_fromValue(_xn.get("entities"), _val.entities);
	EmitterStates_fromValue(_xn.get("emitters"), _val.emitters);
	JammerStates_fromValue(_xn.get("jammers"), _val.jammers);
	Detonations_fromValue(_xn.get("detonations"), _val.detonations);
}
		
// -------------------------------------------------------- AngularBounds
// AngularBounds is a structure
value::Value* AngularBounds_toValue(const AngularBounds& _val) {
	value::Map* xn = value::Map::create();
	xn->add("symetric",Long_toValue(_val.symetric));
	xn->add("elevationMin",Real_toValue(_val.elevationMin));
	xn->add("elevationMax",Real_toValue(_val.elevationMax));
	xn->add("azimutMin",Real_toValue(_val.azimutMin));
	xn->add("azimutMax",Real_toValue(_val.azimutMax));
	return xn;
}

void AngularBounds_fromValue(const value::Value* _node, AngularBounds& _val) {
	const value::Map& _xn = _node->toMap();
	_val.symetric = Long_fromValue(_xn.get("symetric"));
	_val.elevationMin = Real_fromValue(_xn.get("elevationMin"));
	_val.elevationMax = Real_fromValue(_xn.get("elevationMax"));
	_val.azimutMin = Real_fromValue(_xn.get("azimutMin"));
	_val.azimutMax = Real_fromValue(_xn.get("azimutMax"));
}
		
// -------------------------------------------------------- AngularDelta
// AngularDelta is a structure
value::Value* AngularDelta_toValue(const AngularDelta& _val) {
	value::Map* xn = value::Map::create();
	xn->add("deltaElevation",Real_toValue(_val.deltaElevation));
	xn->add("deltaAzimut",Real_toValue(_val.deltaAzimut));
	return xn;
}

void AngularDelta_fromValue(const value::Value* _node, AngularDelta& _val) {
	const value::Map& _xn = _node->toMap();
	_val.deltaElevation = Real_fromValue(_xn.get("deltaElevation"));
	_val.deltaAzimut = Real_fromValue(_xn.get("deltaAzimut"));
}
		
// -------------------------------------------------------- SensorAngularBounds
// SensorAngularBounds is a vector of AngularBounds
value::Value* SensorAngularBounds_toValue(const SensorAngularBounds& _val) {
	value::Set* _xn = value::Set::create();
	SensorAngularBounds::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		_xn->add(AngularBounds_toValue(*it)) ;
	}
	return _xn;
}

void SensorAngularBounds_fromValue(const value::Value* _node, SensorAngularBounds& vect) {
	vect.clear();
	const value::Set& _xn = _node->toSet();
	for (unsigned int _i=0; _i<_xn.size(); _i++) {
		const value::Value* _n = _xn.get(_i);
		AngularBounds _val;
		AngularBounds_fromValue(_n, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- SensorAngularDelta
// SensorAngularDelta is a vector of AngularDelta
value::Value* SensorAngularDelta_toValue(const SensorAngularDelta& _val) {
	value::Set* _xn = value::Set::create();
	SensorAngularDelta::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		_xn->add(AngularDelta_toValue(*it)) ;
	}
	return _xn;
}

void SensorAngularDelta_fromValue(const value::Value* _node, SensorAngularDelta& vect) {
	vect.clear();
	const value::Set& _xn = _node->toSet();
	for (unsigned int _i=0; _i<_xn.size(); _i++) {
		const value::Value* _n = _xn.get(_i);
		AngularDelta _val;
		AngularDelta_fromValue(_n, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- JammerDefinition
// JammerDefinition is a structure
value::Value* JammerDefinition_toValue(const JammerDefinition& _val) {
	value::Map* xn = value::Map::create();
	xn->add("id",Long_toValue(_val.id));
	xn->add("domainId",Long_toValue(_val.domainId));
	xn->add("type",Long_toValue(_val.type));
	xn->add("techno",Long_toValue(_val.techno));
	xn->add("maxPowerAllocation",Real_toValue(_val.maxPowerAllocation));
	xn->add("bounds",AngularBounds_toValue(_val.bounds));
	xn->add("maxTargetNumber",Long_toValue(_val.maxTargetNumber));
	xn->add("apertureEl",Real_toValue(_val.apertureEl));
	xn->add("apertureAz",Real_toValue(_val.apertureAz));
	return xn;
}

void JammerDefinition_fromValue(const value::Value* _node, JammerDefinition& _val) {
	const value::Map& _xn = _node->toMap();
	_val.id = Long_fromValue(_xn.get("id"));
	_val.domainId = Long_fromValue(_xn.get("domainId"));
	_val.type = Long_fromValue(_xn.get("type"));
	_val.techno = Long_fromValue(_xn.get("techno"));
	_val.maxPowerAllocation = Real_fromValue(_xn.get("maxPowerAllocation"));
	AngularBounds_fromValue(_xn.get("bounds"), _val.bounds);
	_val.maxTargetNumber = Long_fromValue(_xn.get("maxTargetNumber"));
	_val.apertureEl = Real_fromValue(_xn.get("apertureEl"));
	_val.apertureAz = Real_fromValue(_xn.get("apertureAz"));
}
		
// -------------------------------------------------------- EmitterJammed
// EmitterJammed is a structure
value::Value* EmitterJammed_toValue(const EmitterJammed& _val) {
	value::Map* xn = value::Map::create();
	xn->add("entityID",Long_toValue(_val.entityID));
	xn->add("powerAllocation",Real_toValue(_val.powerAllocation));
	return xn;
}

void EmitterJammed_fromValue(const value::Value* _node, EmitterJammed& _val) {
	const value::Map& _xn = _node->toMap();
	_val.entityID = Long_fromValue(_xn.get("entityID"));
	_val.powerAllocation = Real_fromValue(_xn.get("powerAllocation"));
}
		
// -------------------------------------------------------- EmitterJammList
// EmitterJammList is a vector of EmitterJammed
value::Value* EmitterJammList_toValue(const EmitterJammList& _val) {
	value::Set* _xn = value::Set::create();
	EmitterJammList::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		_xn->add(EmitterJammed_toValue(*it)) ;
	}
	return _xn;
}

void EmitterJammList_fromValue(const value::Value* _node, EmitterJammList& vect) {
	vect.clear();
	const value::Set& _xn = _node->toSet();
	for (unsigned int _i=0; _i<_xn.size(); _i++) {
		const value::Value* _n = _xn.get(_i);
		EmitterJammed _val;
		EmitterJammed_fromValue(_n, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- JammerStatus
// JammerStatus is a structure
value::Value* JammerStatus_toValue(const JammerStatus& _val) {
	value::Map* xn = value::Map::create();
	xn->add("lastUpdateDate",Long_toValue(_val.lastUpdateDate));
	xn->add("id",Long_toValue(_val.id));
	xn->add("type",Long_toValue(_val.type));
	xn->add("techno",Long_toValue(_val.techno));
	xn->add("available",Long_toValue(_val.available));
	xn->add("endOfOrderId",Long_toValue(_val.endOfOrderId));
	xn->add("doingOrderId",Long_toValue(_val.doingOrderId));
	xn->add("doingOrderDuration",Long_toValue(_val.doingOrderDuration));
	xn->add("errorFlag",Long_toValue(_val.errorFlag));
	xn->add("nbrOfJammOps",Long_toValue(_val.nbrOfJammOps));
	return xn;
}

void JammerStatus_fromValue(const value::Value* _node, JammerStatus& _val) {
	const value::Map& _xn = _node->toMap();
	_val.lastUpdateDate = Long_fromValue(_xn.get("lastUpdateDate"));
	_val.id = Long_fromValue(_xn.get("id"));
	_val.type = Long_fromValue(_xn.get("type"));
	_val.techno = Long_fromValue(_xn.get("techno"));
	_val.available = Long_fromValue(_xn.get("available"));
	_val.endOfOrderId = Long_fromValue(_xn.get("endOfOrderId"));
	_val.doingOrderId = Long_fromValue(_xn.get("doingOrderId"));
	_val.doingOrderDuration = Long_fromValue(_xn.get("doingOrderDuration"));
	_val.errorFlag = Long_fromValue(_xn.get("errorFlag"));
	_val.nbrOfJammOps = Long_fromValue(_xn.get("nbrOfJammOps"));
}
		
// -------------------------------------------------------- JammersStatus
// JammersStatus is a map with key type Long and value type JammerStatus
value::Value* JammersStatus_toValue(const JammersStatus& _val) {
	value::Map* _xn = value::Map::create();
	JammersStatus::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		const std::string& key = boost::lexical_cast<std::string>((*it).first);
		const value::Value& val = *JammerStatus_toValue((*it).second);
		_xn->add(key, val);
	}
	return _xn;

}

void JammersStatus_fromValue(const value::Value* _node, JammersStatus& map) {
	const value::Map& _xn = _node->toMap();
	for (value::Map::const_iterator it=_xn.begin(); it!=_xn.end(); it++) {
		const Long& key = static_cast<Long>(_xn.getInt((*it).first));
		const value::Value* _n = (*it).second;

		JammerStatus_fromValue(_n, map[key]);
	}
}


		
// -------------------------------------------------------- JammOp
// JammOp is a structure
value::Value* JammOp_toValue(const JammOp& _val) {
	value::Map* xn = value::Map::create();
	xn->add("target_id",Long_toValue(_val.target_id));
	xn->add("azimut",Real_toValue(_val.azimut));
	xn->add("elevation",Real_toValue(_val.elevation));
	return xn;
}

void JammOp_fromValue(const value::Value* _node, JammOp& _val) {
	const value::Map& _xn = _node->toMap();
	_val.target_id = Long_fromValue(_xn.get("target_id"));
	_val.azimut = Real_fromValue(_xn.get("azimut"));
	_val.elevation = Real_fromValue(_xn.get("elevation"));
}
		
// -------------------------------------------------------- JammOperationList
// JammOperationList is a vector of JammOp
value::Value* JammOperationList_toValue(const JammOperationList& _val) {
	value::Set* _xn = value::Set::create();
	JammOperationList::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		_xn->add(JammOp_toValue(*it)) ;
	}
	return _xn;
}

void JammOperationList_fromValue(const value::Value* _node, JammOperationList& vect) {
	vect.clear();
	const value::Set& _xn = _node->toSet();
	for (unsigned int _i=0; _i<_xn.size(); _i++) {
		const value::Value* _n = _xn.get(_i);
		JammOp _val;
		JammOp_fromValue(_n, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- JammerOrder
// JammerOrder is a structure
value::Value* JammerOrder_toValue(const JammerOrder& _val) {
	value::Map* xn = value::Map::create();
	xn->add("orderId",Long_toValue(_val.orderId));
	xn->add("jammerId",Long_toValue(_val.jammerId));
	xn->add("func",Long_toValue(_val.func));
	xn->add("duration",Long_toValue(_val.duration));
	xn->add("jammList",JammOperationList_toValue(_val.jammList));
	return xn;
}

void JammerOrder_fromValue(const value::Value* _node, JammerOrder& _val) {
	const value::Map& _xn = _node->toMap();
	_val.orderId = Long_fromValue(_xn.get("orderId"));
	_val.jammerId = Long_fromValue(_xn.get("jammerId"));
	_val.func = Long_fromValue(_xn.get("func"));
	_val.duration = Long_fromValue(_xn.get("duration"));
	JammOperationList_fromValue(_xn.get("jammList"), _val.jammList);
}
		
// -------------------------------------------------------- JammersOrders
// JammersOrders is a map with key type Long and value type JammerOrder
value::Value* JammersOrders_toValue(const JammersOrders& _val) {
	value::Map* _xn = value::Map::create();
	JammersOrders::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		const std::string& key = boost::lexical_cast<std::string>((*it).first);
		const value::Value& val = *JammerOrder_toValue((*it).second);
		_xn->add(key, val);
	}
	return _xn;

}

void JammersOrders_fromValue(const value::Value* _node, JammersOrders& map) {
	const value::Map& _xn = _node->toMap();
	for (value::Map::const_iterator it=_xn.begin(); it!=_xn.end(); it++) {
		const Long& key = static_cast<Long>(_xn.getInt((*it).first));
		const value::Value* _n = (*it).second;

		JammerOrder_fromValue(_n, map[key]);
	}
}


		
// -------------------------------------------------------- JammerDefinitions
// JammerDefinitions is a map with key type Long and value type JammerDefinition
value::Value* JammerDefinitions_toValue(const JammerDefinitions& _val) {
	value::Map* _xn = value::Map::create();
	JammerDefinitions::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		const std::string& key = boost::lexical_cast<std::string>((*it).first);
		const value::Value& val = *JammerDefinition_toValue((*it).second);
		_xn->add(key, val);
	}
	return _xn;

}

void JammerDefinitions_fromValue(const value::Value* _node, JammerDefinitions& map) {
	const value::Map& _xn = _node->toMap();
	for (value::Map::const_iterator it=_xn.begin(); it!=_xn.end(); it++) {
		const Long& key = static_cast<Long>(_xn.getInt((*it).first));
		const value::Value* _n = (*it).second;

		JammerDefinition_fromValue(_n, map[key]);
	}
}


		
// -------------------------------------------------------- LocalisationInit
// LocalisationInit is a structure
value::Value* LocalisationInit_toValue(const LocalisationInit& _val) {
	value::Map* xn = value::Map::create();
	xn->add("pos",Vec3_toValue(_val.pos));
	xn->add("heading",Real_toValue(_val.heading));
	xn->add("mach",Real_toValue(_val.mach));
	xn->add("v",Real_toValue(_val.v));
	return xn;
}

void LocalisationInit_fromValue(const value::Value* _node, LocalisationInit& _val) {
	const value::Map& _xn = _node->toMap();
	Vec3_fromValue(_xn.get("pos"), _val.pos);
	_val.heading = Real_fromValue(_xn.get("heading"));
	_val.mach = Real_fromValue(_xn.get("mach"));
	_val.v = Real_fromValue(_xn.get("v"), 0.);
}
		
// -------------------------------------------------------- LocalisationConst
// LocalisationConst is a structure
value::Value* LocalisationConst_toValue(const LocalisationConst& _val) {
	value::Map* xn = value::Map::create();
	xn->add("irs_deriv",Real_toValue(_val.irs_deriv));
	xn->add("ralt_factor",Real_toValue(_val.ralt_factor));
	xn->add("max_dxy_gps",Real_toValue(_val.max_dxy_gps));
	xn->add("max_dz_gps",Real_toValue(_val.max_dz_gps));
	xn->add("max_dxy_ter",Real_toValue(_val.max_dxy_ter));
	xn->add("max_dz_ter",Real_toValue(_val.max_dz_ter));
	return xn;
}

void LocalisationConst_fromValue(const value::Value* _node, LocalisationConst& _val) {
	const value::Map& _xn = _node->toMap();
	_val.irs_deriv = Real_fromValue(_xn.get("irs_deriv"));
	_val.ralt_factor = Real_fromValue(_xn.get("ralt_factor"));
	_val.max_dxy_gps = Real_fromValue(_xn.get("max_dxy_gps"));
	_val.max_dz_gps = Real_fromValue(_xn.get("max_dz_gps"));
	_val.max_dxy_ter = Real_fromValue(_xn.get("max_dxy_ter"));
	_val.max_dz_ter = Real_fromValue(_xn.get("max_dz_ter"));
}
		
// -------------------------------------------------------- LocalisationState
// LocalisationState is a structure
value::Value* LocalisationState_toValue(const LocalisationState& _val) {
	value::Map* xn = value::Map::create();
	xn->add("isValid",Long_toValue(_val.isValid));
	xn->add("mach",Real_toValue(_val.mach));
	xn->add("position",Vec3_toValue(_val.position));
	xn->add("attitudes",Vec3_toValue(_val.attitudes));
	xn->add("speed",Vec3_toValue(_val.speed));
	xn->add("alt_ralt",Real_toValue(_val.alt_ralt));
	return xn;
}

void LocalisationState_fromValue(const value::Value* _node, LocalisationState& _val) {
	const value::Map& _xn = _node->toMap();
	_val.isValid = Long_fromValue(_xn.get("isValid"));
	_val.mach = Real_fromValue(_xn.get("mach"));
	Vec3_fromValue(_xn.get("position"), _val.position);
	Vec3_fromValue(_xn.get("attitudes"), _val.attitudes);
	Vec3_fromValue(_xn.get("speed"), _val.speed);
	_val.alt_ralt = Real_fromValue(_xn.get("alt_ralt"));
}
		
// -------------------------------------------------------- LocalisationError
// LocalisationError is a structure
value::Value* LocalisationError_toValue(const LocalisationError& _val) {
	value::Map* xn = value::Map::create();
	xn->add("incertitude_dxy",Real_toValue(_val.incertitude_dxy));
	xn->add("incertitude_dz",Real_toValue(_val.incertitude_dz));
	xn->add("incertitude_ralt",Real_toValue(_val.incertitude_ralt));
	return xn;
}

void LocalisationError_fromValue(const value::Value* _node, LocalisationError& _val) {
	const value::Map& _xn = _node->toMap();
	_val.incertitude_dxy = Real_fromValue(_xn.get("incertitude_dxy"));
	_val.incertitude_dz = Real_fromValue(_xn.get("incertitude_dz"));
	_val.incertitude_ralt = Real_fromValue(_xn.get("incertitude_ralt"));
}
		
// -------------------------------------------------------- LocalisationEquipmentState
// LocalisationEquipmentState is a structure
value::Value* LocalisationEquipmentState_toValue(const LocalisationEquipmentState& _val) {
	value::Map* xn = value::Map::create();
	xn->add("gps_available",Long_toValue(_val.gps_available));
	xn->add("irs_available",Long_toValue(_val.irs_available));
	xn->add("ralt_available",Long_toValue(_val.ralt_available));
	xn->add("ternum_available",Long_toValue(_val.ternum_available));
	return xn;
}

void LocalisationEquipmentState_fromValue(const value::Value* _node, LocalisationEquipmentState& _val) {
	const value::Map& _xn = _node->toMap();
	_val.gps_available = Long_fromValue(_xn.get("gps_available"));
	_val.irs_available = Long_fromValue(_xn.get("irs_available"));
	_val.ralt_available = Long_fromValue(_xn.get("ralt_available"));
	_val.ternum_available = Long_fromValue(_xn.get("ternum_available"));
}
		
// -------------------------------------------------------- LocDefinitions
// LocDefinitions is a map with key type Long and value type LocalisationConst
value::Value* LocDefinitions_toValue(const LocDefinitions& _val) {
	value::Map* _xn = value::Map::create();
	LocDefinitions::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		const std::string& key = boost::lexical_cast<std::string>((*it).first);
		const value::Value& val = *LocalisationConst_toValue((*it).second);
		_xn->add(key, val);
	}
	return _xn;

}

void LocDefinitions_fromValue(const value::Value* _node, LocDefinitions& map) {
	const value::Map& _xn = _node->toMap();
	for (value::Map::const_iterator it=_xn.begin(); it!=_xn.end(); it++) {
		const Long& key = static_cast<Long>(_xn.getInt((*it).first));
		const value::Value* _n = (*it).second;

		LocalisationConst_fromValue(_n, map[key]);
	}
}


		
// -------------------------------------------------------- Waypoint
// Waypoint is a structure
value::Value* Waypoint_toValue(const Waypoint& _val) {
	value::Map* xn = value::Map::create();
	xn->add("id",Long_toValue(_val.id));
	xn->add("g",Real_toValue(_val.g));
	xn->add("heading",Real_toValue(_val.heading));
	xn->add("mode",Long_toValue(_val.mode));
	xn->add("position",Vec3_toValue(_val.position));
	xn->add("pmax",Real_toValue(_val.pmax));
	xn->add("t",Long_toValue(_val.t));
	xn->add("dt",Long_toValue(_val.dt));
	xn->add("v",Real_toValue(_val.v));
	xn->add("mach",Real_toValue(_val.mach));
	xn->add("vmin",Real_toValue(_val.vmin));
	xn->add("vmax",Real_toValue(_val.vmax));
	xn->add("dv",Real_toValue(_val.dv));
	return xn;
}

void Waypoint_fromValue(const value::Value* _node, Waypoint& _val) {
	const value::Map& _xn = _node->toMap();
	_val.id = Long_fromValue(_xn.get("id"));
	_val.g = Real_fromValue(_xn.get("g"), 2.);
	_val.heading = Real_fromValue(_xn.get("heading"));
	_val.mode = Long_fromValue(_xn.get("mode"), 1);
	Vec3_fromValue(_xn.get("position"), _val.position);
	_val.pmax = Real_fromValue(_xn.get("pmax"), 10.);
	_val.t = Long_fromValue(_xn.get("t"), 0);
	_val.dt = Long_fromValue(_xn.get("dt"), 20);
	_val.v = Real_fromValue(_xn.get("v"), 0.);
	_val.mach = Real_fromValue(_xn.get("mach"), 0.7);
	_val.vmin = Real_fromValue(_xn.get("vmin"), 100.);
	_val.vmax = Real_fromValue(_xn.get("vmax"), 200.);
	_val.dv = Real_fromValue(_xn.get("dv"), 30.);
}
		
// -------------------------------------------------------- NavigationPts
// NavigationPts is a vector of Waypoint
value::Value* NavigationPts_toValue(const NavigationPts& _val) {
	value::Set* _xn = value::Set::create();
	NavigationPts::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		_xn->add(Waypoint_toValue(*it)) ;
	}
	return _xn;
}

void NavigationPts_fromValue(const value::Value* _node, NavigationPts& vect) {
	vect.clear();
	const value::Set& _xn = _node->toSet();
	for (unsigned int _i=0; _i<_xn.size(); _i++) {
		const value::Value* _n = _xn.get(_i);
		Waypoint _val;
		Waypoint_fromValue(_n, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- FlightConfig
// FlightConfig is a structure
value::Value* FlightConfig_toValue(const FlightConfig& _val) {
	value::Map* xn = value::Map::create();
	xn->add("emptyWeight",Real_toValue(_val.emptyWeight));
	xn->add("payloadWeight",Real_toValue(_val.payloadWeight));
	xn->add("fuelWeight",Real_toValue(_val.fuelWeight));
	xn->add("min_speed",Real_toValue(_val.min_speed));
	xn->add("max_speed",Real_toValue(_val.max_speed));
	xn->add("dv",Real_toValue(_val.dv));
	xn->add("dt",Long_toValue(_val.dt));
	xn->add("altMin",Real_toValue(_val.altMin));
	xn->add("altMax",Real_toValue(_val.altMax));
	return xn;
}

void FlightConfig_fromValue(const value::Value* _node, FlightConfig& _val) {
	const value::Map& _xn = _node->toMap();
	_val.emptyWeight = Real_fromValue(_xn.get("emptyWeight"));
	_val.payloadWeight = Real_fromValue(_xn.get("payloadWeight"));
	_val.fuelWeight = Real_fromValue(_xn.get("fuelWeight"));
	_val.min_speed = Real_fromValue(_xn.get("min_speed"));
	_val.max_speed = Real_fromValue(_xn.get("max_speed"));
	_val.dv = Real_fromValue(_xn.get("dv"));
	_val.dt = Long_fromValue(_xn.get("dt"));
	_val.altMin = Real_fromValue(_xn.get("altMin"));
	_val.altMax = Real_fromValue(_xn.get("altMax"));
}
		
// -------------------------------------------------------- NavigationUpdate
// NavigationUpdate is a structure
value::Value* NavigationUpdate_toValue(const NavigationUpdate& _val) {
	value::Map* xn = value::Map::create();
	xn->add("updated",Long_toValue(_val.updated));
	xn->add("initialIndex",Long_toValue(_val.initialIndex));
	xn->add("nav",NavigationPts_toValue(_val.nav));
	return xn;
}

void NavigationUpdate_fromValue(const value::Value* _node, NavigationUpdate& _val) {
	const value::Map& _xn = _node->toMap();
	_val.updated = Long_fromValue(_xn.get("updated"));
	_val.initialIndex = Long_fromValue(_xn.get("initialIndex"));
	NavigationPts_fromValue(_xn.get("nav"), _val.nav);
}
		
// -------------------------------------------------------- NavigationState
// NavigationState is a structure
value::Value* NavigationState_toValue(const NavigationState& _val) {
	value::Map* xn = value::Map::create();
	xn->add("nav_updated",Long_toValue(_val.nav_updated));
	xn->add("oldNavIndex",Long_toValue(_val.oldNavIndex));
	xn->add("navIndex",Long_toValue(_val.navIndex));
	xn->add("wpId",Long_toValue(_val.wpId));
	xn->add("distToNextWaypoint",Real_toValue(_val.distToNextWaypoint));
	xn->add("nav",NavigationPts_toValue(_val.nav));
	return xn;
}

void NavigationState_fromValue(const value::Value* _node, NavigationState& _val) {
	const value::Map& _xn = _node->toMap();
	_val.nav_updated = Long_fromValue(_xn.get("nav_updated"));
	_val.oldNavIndex = Long_fromValue(_xn.get("oldNavIndex"));
	_val.navIndex = Long_fromValue(_xn.get("navIndex"));
	_val.wpId = Long_fromValue(_xn.get("wpId"));
	_val.distToNextWaypoint = Real_fromValue(_xn.get("distToNextWaypoint"));
	NavigationPts_fromValue(_xn.get("nav"), _val.nav);
}
		
// -------------------------------------------------------- SStateVector
// SStateVector is a structure
value::Value* SStateVector_toValue(const SStateVector& _val) {
	value::Map* xn = value::Map::create();
	xn->add("isValid",Long_toValue(_val.isValid));
	xn->add("Id",Long_toValue(_val.Id));
	xn->add("mode",Long_toValue(_val.mode));
	xn->add("Latitude",Real_toValue(_val.Latitude));
	xn->add("Longitude",Real_toValue(_val.Longitude));
	xn->add("Altitude",Real_toValue(_val.Altitude));
	xn->add("SpeedN",Real_toValue(_val.SpeedN));
	xn->add("SpeedE",Real_toValue(_val.SpeedE));
	xn->add("SpeedD",Real_toValue(_val.SpeedD));
	xn->add("Heading",Real_toValue(_val.Heading));
	xn->add("Pitch",Real_toValue(_val.Pitch));
	xn->add("Roll",Real_toValue(_val.Roll));
	xn->add("Mach",Real_toValue(_val.Mach));
	xn->add("CAS",Real_toValue(_val.CAS));
	xn->add("wpID",Long_toValue(_val.wpID));
	xn->add("wpDist",Real_toValue(_val.wpDist));
	return xn;
}

void SStateVector_fromValue(const value::Value* _node, SStateVector& _val) {
	const value::Map& _xn = _node->toMap();
	_val.isValid = Long_fromValue(_xn.get("isValid"));
	_val.Id = Long_fromValue(_xn.get("Id"));
	_val.mode = Long_fromValue(_xn.get("mode"));
	_val.Latitude = Real_fromValue(_xn.get("Latitude"));
	_val.Longitude = Real_fromValue(_xn.get("Longitude"));
	_val.Altitude = Real_fromValue(_xn.get("Altitude"));
	_val.SpeedN = Real_fromValue(_xn.get("SpeedN"));
	_val.SpeedE = Real_fromValue(_xn.get("SpeedE"));
	_val.SpeedD = Real_fromValue(_xn.get("SpeedD"));
	_val.Heading = Real_fromValue(_xn.get("Heading"));
	_val.Pitch = Real_fromValue(_xn.get("Pitch"));
	_val.Roll = Real_fromValue(_xn.get("Roll"));
	_val.Mach = Real_fromValue(_xn.get("Mach"));
	_val.CAS = Real_fromValue(_xn.get("CAS"));
	_val.wpID = Long_fromValue(_xn.get("wpID"));
	_val.wpDist = Real_fromValue(_xn.get("wpDist"));
}
		
// -------------------------------------------------------- SensorTechno
// SensorTechno is a structure
value::Value* SensorTechno_toValue(const SensorTechno& _val) {
	value::Map* xn = value::Map::create();
	xn->add("id",Long_toValue(_val.id));
	xn->add("range",Real_toValue(_val.range));
	return xn;
}

void SensorTechno_fromValue(const value::Value* _node, SensorTechno& _val) {
	const value::Map& _xn = _node->toMap();
	_val.id = Long_fromValue(_xn.get("id"));
	_val.range = Real_fromValue(_xn.get("range"));
}
		
// -------------------------------------------------------- SensorTechnos
// SensorTechnos is a vector of SensorTechno
value::Value* SensorTechnos_toValue(const SensorTechnos& _val) {
	value::Set* _xn = value::Set::create();
	SensorTechnos::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		_xn->add(SensorTechno_toValue(*it)) ;
	}
	return _xn;
}

void SensorTechnos_fromValue(const value::Value* _node, SensorTechnos& vect) {
	vect.clear();
	const value::Set& _xn = _node->toSet();
	for (unsigned int _i=0; _i<_xn.size(); _i++) {
		const value::Value* _n = _xn.get(_i);
		SensorTechno _val;
		SensorTechno_fromValue(_n, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- SensorDefinition
// SensorDefinition is a structure
value::Value* SensorDefinition_toValue(const SensorDefinition& _val) {
	value::Map* xn = value::Map::create();
	xn->add("id",Long_toValue(_val.id));
	xn->add("type",SensorType_toValue(_val.type));
	xn->add("worksWithEntities",Long_toValue(_val.worksWithEntities));
	xn->add("worksWithEntityTypes",Longs_toValue(_val.worksWithEntityTypes));
	xn->add("technos",SensorTechnos_toValue(_val.technos));
	xn->add("usesLineOfSight",Long_toValue(_val.usesLineOfSight));
	xn->add("fieldOfRegard",SensorAngularBounds_toValue(_val.fieldOfRegard));
	xn->add("fieldOfView",SensorAngularDelta_toValue(_val.fieldOfView));
	xn->add("intervisiType",Long_toValue(_val.intervisiType));
	xn->add("resolution",Vec3_toValue(_val.resolution));
	xn->add("toBeAcquiredDuration",Long_toValue(_val.toBeAcquiredDuration));
	xn->add("toBeLostDuration",Long_toValue(_val.toBeLostDuration));
	xn->add("canBeJammed",Long_toValue(_val.canBeJammed));
	xn->add("historyLenght",Long_toValue(_val.historyLenght));
	xn->add("isEmitter",Long_toValue(_val.isEmitter));
	return xn;
}

void SensorDefinition_fromValue(const value::Value* _node, SensorDefinition& _val) {
	const value::Map& _xn = _node->toMap();
	_val.id = Long_fromValue(_xn.get("id"));
	_val.type = SensorType_fromValue(_xn.get("type"));
	_val.worksWithEntities = Long_fromValue(_xn.get("worksWithEntities"));
	Longs_fromValue(_xn.get("worksWithEntityTypes"), _val.worksWithEntityTypes);
	SensorTechnos_fromValue(_xn.get("technos"), _val.technos);
	_val.usesLineOfSight = Long_fromValue(_xn.get("usesLineOfSight"));
	SensorAngularBounds_fromValue(_xn.get("fieldOfRegard"), _val.fieldOfRegard);
	SensorAngularDelta_fromValue(_xn.get("fieldOfView"), _val.fieldOfView);
	_val.intervisiType = Long_fromValue(_xn.get("intervisiType"));
	Vec3_fromValue(_xn.get("resolution"), _val.resolution);
	_val.toBeAcquiredDuration = Long_fromValue(_xn.get("toBeAcquiredDuration"));
	_val.toBeLostDuration = Long_fromValue(_xn.get("toBeLostDuration"));
	_val.canBeJammed = Long_fromValue(_xn.get("canBeJammed"));
	_val.historyLenght = Long_fromValue(_xn.get("historyLenght"));
	_val.isEmitter = Long_fromValue(_xn.get("isEmitter"));
}
		
// -------------------------------------------------------- RadarDefinition
// RadarDefinition is a structure
value::Value* RadarDefinition_toValue(const RadarDefinition& _val) {
	value::Map* xn = value::Map::create();
	xn->add("bandID",Long_toValue(_val.bandID));
	xn->add("range",Real_toValue(_val.range));
	xn->add("fov_deltaElevation",Real_toValue(_val.fov_deltaElevation));
	xn->add("fov_deltaAzimut",Real_toValue(_val.fov_deltaAzimut));
	xn->add("for_elevationMin",Real_toValue(_val.for_elevationMin));
	xn->add("for_elevationMax",Real_toValue(_val.for_elevationMax));
	xn->add("for_azimutMin",Real_toValue(_val.for_azimutMin));
	xn->add("for_azimutMax",Real_toValue(_val.for_azimutMax));
	xn->add("toBeAcquiredDuration",Long_toValue(_val.toBeAcquiredDuration));
	xn->add("toBeLostDuration",Long_toValue(_val.toBeLostDuration));
	return xn;
}

void RadarDefinition_fromValue(const value::Value* _node, RadarDefinition& _val) {
	const value::Map& _xn = _node->toMap();
	_val.bandID = Long_fromValue(_xn.get("bandID"));
	_val.range = Real_fromValue(_xn.get("range"));
	_val.fov_deltaElevation = Real_fromValue(_xn.get("fov_deltaElevation"));
	_val.fov_deltaAzimut = Real_fromValue(_xn.get("fov_deltaAzimut"));
	_val.for_elevationMin = Real_fromValue(_xn.get("for_elevationMin"));
	_val.for_elevationMax = Real_fromValue(_xn.get("for_elevationMax"));
	_val.for_azimutMin = Real_fromValue(_xn.get("for_azimutMin"));
	_val.for_azimutMax = Real_fromValue(_xn.get("for_azimutMax"));
	_val.toBeAcquiredDuration = Long_fromValue(_xn.get("toBeAcquiredDuration"));
	_val.toBeLostDuration = Long_fromValue(_xn.get("toBeLostDuration"));
}
		
// -------------------------------------------------------- EsmDefinition
// EsmDefinition is a structure
value::Value* EsmDefinition_toValue(const EsmDefinition& _val) {
	value::Map* xn = value::Map::create();
	xn->add("bandID",Long_toValue(_val.bandID));
	xn->add("range",Real_toValue(_val.range));
	xn->add("fov_deltaElevation",Real_toValue(_val.fov_deltaElevation));
	xn->add("fov_deltaAzimut",Real_toValue(_val.fov_deltaAzimut));
	xn->add("for_elevationMin",Real_toValue(_val.for_elevationMin));
	xn->add("for_elevationMax",Real_toValue(_val.for_elevationMax));
	xn->add("for_azimutMin",Real_toValue(_val.for_azimutMin));
	xn->add("for_azimutMax",Real_toValue(_val.for_azimutMax));
	xn->add("toBeAcquiredDuration",Long_toValue(_val.toBeAcquiredDuration));
	xn->add("toBeLostDuration",Long_toValue(_val.toBeLostDuration));
	return xn;
}

void EsmDefinition_fromValue(const value::Value* _node, EsmDefinition& _val) {
	const value::Map& _xn = _node->toMap();
	_val.bandID = Long_fromValue(_xn.get("bandID"));
	_val.range = Real_fromValue(_xn.get("range"));
	_val.fov_deltaElevation = Real_fromValue(_xn.get("fov_deltaElevation"));
	_val.fov_deltaAzimut = Real_fromValue(_xn.get("fov_deltaAzimut"));
	_val.for_elevationMin = Real_fromValue(_xn.get("for_elevationMin"));
	_val.for_elevationMax = Real_fromValue(_xn.get("for_elevationMax"));
	_val.for_azimutMin = Real_fromValue(_xn.get("for_azimutMin"));
	_val.for_azimutMax = Real_fromValue(_xn.get("for_azimutMax"));
	_val.toBeAcquiredDuration = Long_fromValue(_xn.get("toBeAcquiredDuration"));
	_val.toBeLostDuration = Long_fromValue(_xn.get("toBeLostDuration"));
}
		
// -------------------------------------------------------- SensorPlot
// SensorPlot is a structure
value::Value* SensorPlot_toValue(const SensorPlot& _val) {
	value::Map* xn = value::Map::create();
	xn->add("date",Long_toValue(_val.date));
	xn->add("sourceId",Long_toValue(_val.sourceId));
	xn->add("sourceType",SensorType_toValue(_val.sourceType));
	xn->add("sourceTechno",Long_toValue(_val.sourceTechno));
	xn->add("elevation",Real_toValue(_val.elevation));
	xn->add("azimut",Real_toValue(_val.azimut));
	xn->add("distance",Real_toValue(_val.distance));
	xn->add("position",Vec3_toValue(_val.position));
	return xn;
}

void SensorPlot_fromValue(const value::Value* _node, SensorPlot& _val) {
	const value::Map& _xn = _node->toMap();
	_val.date = Long_fromValue(_xn.get("date"));
	_val.sourceId = Long_fromValue(_xn.get("sourceId"));
	_val.sourceType = SensorType_fromValue(_xn.get("sourceType"));
	_val.sourceTechno = Long_fromValue(_xn.get("sourceTechno"));
	_val.elevation = Real_fromValue(_xn.get("elevation"));
	_val.azimut = Real_fromValue(_xn.get("azimut"));
	_val.distance = Real_fromValue(_xn.get("distance"));
	Vec3_fromValue(_xn.get("position"), _val.position);
}
		
// -------------------------------------------------------- SensorImage
// SensorImage is a structure
value::Value* SensorImage_toValue(const SensorImage& _val) {
	value::Map* xn = value::Map::create();
	xn->add("plot",SensorPlot_toValue(_val.plot));
	xn->add("objects",EntityStates_toValue(_val.objects));
	return xn;
}

void SensorImage_fromValue(const value::Value* _node, SensorImage& _val) {
	const value::Map& _xn = _node->toMap();
	SensorPlot_fromValue(_xn.get("plot"), _val.plot);
	EntityStates_fromValue(_xn.get("objects"), _val.objects);
}
		
// -------------------------------------------------------- SensorImages
// SensorImages is a vector of SensorImage
value::Value* SensorImages_toValue(const SensorImages& _val) {
	value::Set* _xn = value::Set::create();
	SensorImages::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		_xn->add(SensorImage_toValue(*it)) ;
	}
	return _xn;
}

void SensorImages_fromValue(const value::Value* _node, SensorImages& vect) {
	vect.clear();
	const value::Set& _xn = _node->toSet();
	for (unsigned int _i=0; _i<_xn.size(); _i++) {
		const value::Value* _n = _xn.get(_i);
		SensorImage _val;
		SensorImage_fromValue(_n, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- SensorPlotVector
// SensorPlotVector is a vector of SensorPlot
value::Value* SensorPlotVector_toValue(const SensorPlotVector& _val) {
	value::Set* _xn = value::Set::create();
	SensorPlotVector::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		_xn->add(SensorPlot_toValue(*it)) ;
	}
	return _xn;
}

void SensorPlotVector_fromValue(const value::Value* _node, SensorPlotVector& vect) {
	vect.clear();
	const value::Set& _xn = _node->toSet();
	for (unsigned int _i=0; _i<_xn.size(); _i++) {
		const value::Value* _n = _xn.get(_i);
		SensorPlot _val;
		SensorPlot_fromValue(_n, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- SensorTrack
// SensorTrack is a structure
value::Value* SensorTrack_toValue(const SensorTrack& _val) {
	value::Map* xn = value::Map::create();
	xn->add("targetId",Long_toValue(_val.targetId));
	xn->add("lastUpdateDate",Long_toValue(_val.lastUpdateDate));
	xn->add("plots",SensorPlotVector_toValue(_val.plots));
	xn->add("tracked",Long_toValue(_val.tracked));
	xn->add("detected",Long_toValue(_val.detected));
	xn->add("trackTime",Long_toValue(_val.trackTime));
	xn->add("deltaAzimut",Real_toValue(_val.deltaAzimut));
	xn->add("deltaElevation",Real_toValue(_val.deltaElevation));
	xn->add("doNotFollow",Long_toValue(_val.doNotFollow));
	return xn;
}

void SensorTrack_fromValue(const value::Value* _node, SensorTrack& _val) {
	const value::Map& _xn = _node->toMap();
	_val.targetId = Long_fromValue(_xn.get("targetId"));
	_val.lastUpdateDate = Long_fromValue(_xn.get("lastUpdateDate"));
	SensorPlotVector_fromValue(_xn.get("plots"), _val.plots);
	_val.tracked = Long_fromValue(_xn.get("tracked"));
	_val.detected = Long_fromValue(_xn.get("detected"));
	_val.trackTime = Long_fromValue(_xn.get("trackTime"));
	_val.deltaAzimut = Real_fromValue(_xn.get("deltaAzimut"));
	_val.deltaElevation = Real_fromValue(_xn.get("deltaElevation"));
	_val.doNotFollow = Long_fromValue(_xn.get("doNotFollow"));
}
		
// -------------------------------------------------------- SensorTracks
// SensorTracks is a map with key type Long and value type SensorTrack
value::Value* SensorTracks_toValue(const SensorTracks& _val) {
	value::Map* _xn = value::Map::create();
	SensorTracks::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		const std::string& key = boost::lexical_cast<std::string>((*it).first);
		const value::Value& val = *SensorTrack_toValue((*it).second);
		_xn->add(key, val);
	}
	return _xn;

}

void SensorTracks_fromValue(const value::Value* _node, SensorTracks& map) {
	const value::Map& _xn = _node->toMap();
	for (value::Map::const_iterator it=_xn.begin(); it!=_xn.end(); it++) {
		const Long& key = static_cast<Long>(_xn.getInt((*it).first));
		const value::Value* _n = (*it).second;

		SensorTrack_fromValue(_n, map[key]);
	}
}


		
// -------------------------------------------------------- SensorStatus
// SensorStatus is a structure
value::Value* SensorStatus_toValue(const SensorStatus& _val) {
	value::Map* xn = value::Map::create();
	xn->add("lastUpdateDate",Long_toValue(_val.lastUpdateDate));
	xn->add("id",Long_toValue(_val.id));
	xn->add("type",SensorType_toValue(_val.type));
	xn->add("available",Long_toValue(_val.available));
	xn->add("doingOrderId",Long_toValue(_val.doingOrderId));
	xn->add("doingOrderDuration",Long_toValue(_val.doingOrderDuration));
	xn->add("endOfOrderId",Long_toValue(_val.endOfOrderId));
	xn->add("errorFlag",Long_toValue(_val.errorFlag));
	return xn;
}

void SensorStatus_fromValue(const value::Value* _node, SensorStatus& _val) {
	const value::Map& _xn = _node->toMap();
	_val.lastUpdateDate = Long_fromValue(_xn.get("lastUpdateDate"));
	_val.id = Long_fromValue(_xn.get("id"));
	_val.type = SensorType_fromValue(_xn.get("type"));
	_val.available = Long_fromValue(_xn.get("available"));
	_val.doingOrderId = Long_fromValue(_xn.get("doingOrderId"));
	_val.doingOrderDuration = Long_fromValue(_xn.get("doingOrderDuration"));
	_val.endOfOrderId = Long_fromValue(_xn.get("endOfOrderId"));
	_val.errorFlag = Long_fromValue(_xn.get("errorFlag"));
}
		
// -------------------------------------------------------- SensorsStatus
// SensorsStatus is a map with key type Long and value type SensorStatus
value::Value* SensorsStatus_toValue(const SensorsStatus& _val) {
	value::Map* _xn = value::Map::create();
	SensorsStatus::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		const std::string& key = boost::lexical_cast<std::string>((*it).first);
		const value::Value& val = *SensorStatus_toValue((*it).second);
		_xn->add(key, val);
	}
	return _xn;

}

void SensorsStatus_fromValue(const value::Value* _node, SensorsStatus& map) {
	const value::Map& _xn = _node->toMap();
	for (value::Map::const_iterator it=_xn.begin(); it!=_xn.end(); it++) {
		const Long& key = static_cast<Long>(_xn.getInt((*it).first));
		const value::Value* _n = (*it).second;

		SensorStatus_fromValue(_n, map[key]);
	}
}


		
// -------------------------------------------------------- SensorOrder
// SensorOrder is a structure
value::Value* SensorOrder_toValue(const SensorOrder& _val) {
	value::Map* xn = value::Map::create();
	xn->add("orderId",Long_toValue(_val.orderId));
	xn->add("sensorId",Long_toValue(_val.sensorId));
	xn->add("func",SensorFunction_toValue(_val.func));
	xn->add("fieldOfRegardNbr",Long_toValue(_val.fieldOfRegardNbr));
	xn->add("fieldOfViewNbr",Long_toValue(_val.fieldOfViewNbr));
	xn->add("lineOfSightElevation",Real_toValue(_val.lineOfSightElevation));
	xn->add("lineOfSightAzimut",Real_toValue(_val.lineOfSightAzimut));
	xn->add("duration",Long_toValue(_val.duration));
	return xn;
}

void SensorOrder_fromValue(const value::Value* _node, SensorOrder& _val) {
	const value::Map& _xn = _node->toMap();
	_val.orderId = Long_fromValue(_xn.get("orderId"));
	_val.sensorId = Long_fromValue(_xn.get("sensorId"));
	_val.func = SensorFunction_fromValue(_xn.get("func"));
	_val.fieldOfRegardNbr = Long_fromValue(_xn.get("fieldOfRegardNbr"));
	_val.fieldOfViewNbr = Long_fromValue(_xn.get("fieldOfViewNbr"));
	_val.lineOfSightElevation = Real_fromValue(_xn.get("lineOfSightElevation"));
	_val.lineOfSightAzimut = Real_fromValue(_xn.get("lineOfSightAzimut"));
	_val.duration = Long_fromValue(_xn.get("duration"));
}
		
// -------------------------------------------------------- SensorOrders
// SensorOrders is a map with key type Long and value type SensorOrder
value::Value* SensorOrders_toValue(const SensorOrders& _val) {
	value::Map* _xn = value::Map::create();
	SensorOrders::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		const std::string& key = boost::lexical_cast<std::string>((*it).first);
		const value::Value& val = *SensorOrder_toValue((*it).second);
		_xn->add(key, val);
	}
	return _xn;

}

void SensorOrders_fromValue(const value::Value* _node, SensorOrders& map) {
	const value::Map& _xn = _node->toMap();
	for (value::Map::const_iterator it=_xn.begin(); it!=_xn.end(); it++) {
		const Long& key = static_cast<Long>(_xn.getInt((*it).first));
		const value::Value* _n = (*it).second;

		SensorOrder_fromValue(_n, map[key]);
	}
}


		
// -------------------------------------------------------- SGD
// SGD is a structure
value::Value* SGD_toValue(const SGD& _val) {
	value::Map* xn = value::Map::create();
	xn->add("hasAB",Long_toValue(_val.hasAB));
	xn->add("hasBA",Long_toValue(_val.hasBA));
	xn->add("hasBA_RL",Long_toValue(_val.hasBA_RL));
	xn->add("hasDist",Long_toValue(_val.hasDist));
	xn->add("hasIvisi",Long_toValue(_val.hasIvisi));
	xn->add("siteAB",Real_toValue(_val.siteAB));
	xn->add("giseAB",Real_toValue(_val.giseAB));
	xn->add("siteBA",Real_toValue(_val.siteBA));
	xn->add("giseBA",Real_toValue(_val.giseBA));
	xn->add("siteBA_RL",Real_toValue(_val.siteBA_RL));
	xn->add("giseBA_RL",Real_toValue(_val.giseBA_RL));
	xn->add("dist",Real_toValue(_val.dist));
	xn->add("ivisi",Long_toValue(_val.ivisi));
	xn->add("techno",Long_toValue(_val.techno));
	xn->add("range",Real_toValue(_val.range));
	return xn;
}

void SGD_fromValue(const value::Value* _node, SGD& _val) {
	const value::Map& _xn = _node->toMap();
	_val.hasAB = Long_fromValue(_xn.get("hasAB"));
	_val.hasBA = Long_fromValue(_xn.get("hasBA"));
	_val.hasBA_RL = Long_fromValue(_xn.get("hasBA_RL"));
	_val.hasDist = Long_fromValue(_xn.get("hasDist"));
	_val.hasIvisi = Long_fromValue(_xn.get("hasIvisi"));
	_val.siteAB = Real_fromValue(_xn.get("siteAB"));
	_val.giseAB = Real_fromValue(_xn.get("giseAB"));
	_val.siteBA = Real_fromValue(_xn.get("siteBA"));
	_val.giseBA = Real_fromValue(_xn.get("giseBA"));
	_val.siteBA_RL = Real_fromValue(_xn.get("siteBA_RL"));
	_val.giseBA_RL = Real_fromValue(_xn.get("giseBA_RL"));
	_val.dist = Real_fromValue(_xn.get("dist"));
	_val.ivisi = Long_fromValue(_xn.get("ivisi"));
	_val.techno = Long_fromValue(_xn.get("techno"));
	_val.range = Real_fromValue(_xn.get("range"));
}
		
// -------------------------------------------------------- SensorMemory
// SensorMemory is a map with key type Long and value type SGD
value::Value* SensorMemory_toValue(const SensorMemory& _val) {
	value::Map* _xn = value::Map::create();
	SensorMemory::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		const std::string& key = boost::lexical_cast<std::string>((*it).first);
		const value::Value& val = *SGD_toValue((*it).second);
		_xn->add(key, val);
	}
	return _xn;

}

void SensorMemory_fromValue(const value::Value* _node, SensorMemory& map) {
	const value::Map& _xn = _node->toMap();
	for (value::Map::const_iterator it=_xn.begin(); it!=_xn.end(); it++) {
		const Long& key = static_cast<Long>(_xn.getInt((*it).first));
		const value::Value* _n = (*it).second;

		SGD_fromValue(_n, map[key]);
	}
}


		
// -------------------------------------------------------- SensorDefinitions
// SensorDefinitions is a map with key type Long and value type SensorDefinition
value::Value* SensorDefinitions_toValue(const SensorDefinitions& _val) {
	value::Map* _xn = value::Map::create();
	SensorDefinitions::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		const std::string& key = boost::lexical_cast<std::string>((*it).first);
		const value::Value& val = *SensorDefinition_toValue((*it).second);
		_xn->add(key, val);
	}
	return _xn;

}

void SensorDefinitions_fromValue(const value::Value* _node, SensorDefinitions& map) {
	const value::Map& _xn = _node->toMap();
	for (value::Map::const_iterator it=_xn.begin(); it!=_xn.end(); it++) {
		const Long& key = static_cast<Long>(_xn.getInt((*it).first));
		const value::Value* _n = (*it).second;

		SensorDefinition_fromValue(_n, map[key]);
	}
}


		
// -------------------------------------------------------- SAElementStatus
// SAElementStatus is a structure
value::Value* SAElementStatus_toValue(const SAElementStatus& _val) {
	value::Map* xn = value::Map::create();
	xn->add("nid",Long_toValue(_val.nid));
	xn->add("type",Long_toValue(_val.type));
	xn->add("doing",Long_toValue(_val.doing));
	xn->add("pos",Vec3_toValue(_val.pos));
	xn->add("date",Long_toValue(_val.date));
	xn->add("status",Long_toValue(_val.status));
	xn->add("targetId",Long_toValue(_val.targetId));
	xn->add("munition",Long_toValue(_val.munition));
	xn->add("updated",Long_toValue(_val.updated));
	return xn;
}

void SAElementStatus_fromValue(const value::Value* _node, SAElementStatus& _val) {
	const value::Map& _xn = _node->toMap();
	_val.nid = Long_fromValue(_xn.get("nid"), 0);
	_val.type = Long_fromValue(_xn.get("type"), 0);
	_val.doing = Long_fromValue(_xn.get("doing"), -1);
	Vec3_fromValue(_xn.get("pos"), _val.pos);
	_val.date = Long_fromValue(_xn.get("date"), 0);
	_val.status = Long_fromValue(_xn.get("status"), 0);
	_val.targetId = Long_fromValue(_xn.get("targetId"));
	_val.munition = Long_fromValue(_xn.get("munition"), 0);
	_val.updated = Long_fromValue(_xn.get("updated"), 0);
}
		
// -------------------------------------------------------- SAElementStatusList
// SAElementStatusList is a map with key type Long and value type SAElementStatus
value::Value* SAElementStatusList_toValue(const SAElementStatusList& _val) {
	value::Map* _xn = value::Map::create();
	SAElementStatusList::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		const std::string& key = boost::lexical_cast<std::string>((*it).first);
		const value::Value& val = *SAElementStatus_toValue((*it).second);
		_xn->add(key, val);
	}
	return _xn;

}

void SAElementStatusList_fromValue(const value::Value* _node, SAElementStatusList& map) {
	const value::Map& _xn = _node->toMap();
	for (value::Map::const_iterator it=_xn.begin(); it!=_xn.end(); it++) {
		const Long& key = static_cast<Long>(_xn.getInt((*it).first));
		const value::Value* _n = (*it).second;

		SAElementStatus_fromValue(_n, map[key]);
	}
}


		
// -------------------------------------------------------- SAElementOrder
// SAElementOrder is a structure
value::Value* SAElementOrder_toValue(const SAElementOrder& _val) {
	value::Map* xn = value::Map::create();
	xn->add("nid",Long_toValue(_val.nid));
	xn->add("orderId",Long_toValue(_val.orderId));
	xn->add("order",Long_toValue(_val.order));
	xn->add("targetId",Long_toValue(_val.targetId));
	return xn;
}

void SAElementOrder_fromValue(const value::Value* _node, SAElementOrder& _val) {
	const value::Map& _xn = _node->toMap();
	_val.nid = Long_fromValue(_xn.get("nid"));
	_val.orderId = Long_fromValue(_xn.get("orderId"));
	_val.order = Long_fromValue(_xn.get("order"));
	_val.targetId = Long_fromValue(_xn.get("targetId"));
}
		
// -------------------------------------------------------- SAElementOrderList
// SAElementOrderList is a map with key type Long and value type SAElementOrder
value::Value* SAElementOrderList_toValue(const SAElementOrderList& _val) {
	value::Map* _xn = value::Map::create();
	SAElementOrderList::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		const std::string& key = boost::lexical_cast<std::string>((*it).first);
		const value::Value& val = *SAElementOrder_toValue((*it).second);
		_xn->add(key, val);
	}
	return _xn;

}

void SAElementOrderList_fromValue(const value::Value* _node, SAElementOrderList& map) {
	const value::Map& _xn = _node->toMap();
	for (value::Map::const_iterator it=_xn.begin(); it!=_xn.end(); it++) {
		const Long& key = static_cast<Long>(_xn.getInt((*it).first));
		const value::Value* _n = (*it).second;

		SAElementOrder_fromValue(_n, map[key]);
	}
}


		
// -------------------------------------------------------- SASystemState
// SASystemState is a structure
value::Value* SASystemState_toValue(const SASystemState& _val) {
	value::Map* xn = value::Map::create();
	xn->add("nid",Long_toValue(_val.nid));
	xn->add("state",Long_toValue(_val.state));
	xn->add("ordersCount",Long_toValue(_val.ordersCount));
	xn->add("nbrOfV",Long_toValue(_val.nbrOfV));
	xn->add("nbrOfCdT",Long_toValue(_val.nbrOfCdT));
	xn->add("veilles",Longs_toValue(_val.veilles));
	xn->add("cdts",Longs_toValue(_val.cdts));
	xn->add("nbrOfActiveV",Long_toValue(_val.nbrOfActiveV));
	xn->add("nbrOfActiveCdT",Long_toValue(_val.nbrOfActiveCdT));
	return xn;
}

void SASystemState_fromValue(const value::Value* _node, SASystemState& _val) {
	const value::Map& _xn = _node->toMap();
	_val.nid = Long_fromValue(_xn.get("nid"), 0);
	_val.state = Long_fromValue(_xn.get("state"), 0);
	_val.ordersCount = Long_fromValue(_xn.get("ordersCount"), 0);
	_val.nbrOfV = Long_fromValue(_xn.get("nbrOfV"), 0);
	_val.nbrOfCdT = Long_fromValue(_xn.get("nbrOfCdT"), 0);
	Longs_fromValue(_xn.get("veilles"), _val.veilles);
	Longs_fromValue(_xn.get("cdts"), _val.cdts);
	_val.nbrOfActiveV = Long_fromValue(_xn.get("nbrOfActiveV"), 0);
	_val.nbrOfActiveCdT = Long_fromValue(_xn.get("nbrOfActiveCdT"), 0);
}
		
// -------------------------------------------------------- FlightData
// FlightData is a structure
value::Value* FlightData_toValue(const FlightData& _val) {
	value::Map* xn = value::Map::create();
	xn->add("position",Vec3_toValue(_val.position));
	xn->add("speed",Vec3_toValue(_val.speed));
	xn->add("attitudes",Vec3_toValue(_val.attitudes));
	xn->add("date",Long_toValue(_val.date));
	return xn;
}

void FlightData_fromValue(const value::Value* _node, FlightData& _val) {
	const value::Map& _xn = _node->toMap();
	Vec3_fromValue(_xn.get("position"), _val.position);
	Vec3_fromValue(_xn.get("speed"), _val.speed);
	Vec3_fromValue(_xn.get("attitudes"), _val.attitudes);
	_val.date = Long_fromValue(_xn.get("date"));
}
		
// -------------------------------------------------------- NavigationData
// NavigationData is a structure
value::Value* NavigationData_toValue(const NavigationData& _val) {
	value::Map* xn = value::Map::create();
	xn->add("position",Vec3_toValue(_val.position));
	xn->add("speed",Vec3_toValue(_val.speed));
	xn->add("attitudes",Vec3_toValue(_val.attitudes));
	xn->add("date",Long_toValue(_val.date));
	xn->add("wpId",Long_toValue(_val.wpId));
	xn->add("distToNextWaypoint",Real_toValue(_val.distToNextWaypoint));
	xn->add("nav",NavigationPts_toValue(_val.nav));
	return xn;
}

void NavigationData_fromValue(const value::Value* _node, NavigationData& _val) {
	const value::Map& _xn = _node->toMap();
	Vec3_fromValue(_xn.get("position"), _val.position);
	Vec3_fromValue(_xn.get("speed"), _val.speed);
	Vec3_fromValue(_xn.get("attitudes"), _val.attitudes);
	_val.date = Long_fromValue(_xn.get("date"));
	_val.wpId = Long_fromValue(_xn.get("wpId"));
	_val.distToNextWaypoint = Real_fromValue(_xn.get("distToNextWaypoint"));
	NavigationPts_fromValue(_xn.get("nav"), _val.nav);
}
		
// -------------------------------------------------------- NetworkDefinition
// NetworkDefinition is a structure
value::Value* NetworkDefinition_toValue(const NetworkDefinition& _val) {
	value::Map* xn = value::Map::create();
	xn->add("name",String_toValue(_val.name));
	xn->add("id",Long_toValue(_val.id));
	xn->add("isBLOS",Long_toValue(_val.isBLOS));
	xn->add("maxDist",Real_toValue(_val.maxDist));
	xn->add("networkBandwidth",Real_toValue(_val.networkBandwidth));
	xn->add("maxSendConnectionPerAccess",Long_toValue(_val.maxSendConnectionPerAccess));
	xn->add("maxRcvConnectionPerAccess",Long_toValue(_val.maxRcvConnectionPerAccess));
	xn->add("maxSendBandwidthPerConnection",Real_toValue(_val.maxSendBandwidthPerConnection));
	xn->add("maxRcvBandwidthPerAccess",Real_toValue(_val.maxRcvBandwidthPerAccess));
	xn->add("maxConnectionInNetwork",Long_toValue(_val.maxConnectionInNetwork));
	xn->add("maxNumberOfAccess",Long_toValue(_val.maxNumberOfAccess));
	return xn;
}

void NetworkDefinition_fromValue(const value::Value* _node, NetworkDefinition& _val) {
	const value::Map& _xn = _node->toMap();
	_val.name = String_fromValue(_xn.get("name"));
	_val.id = Long_fromValue(_xn.get("id"));
	_val.isBLOS = Long_fromValue(_xn.get("isBLOS"));
	_val.maxDist = Real_fromValue(_xn.get("maxDist"));
	_val.networkBandwidth = Real_fromValue(_xn.get("networkBandwidth"));
	_val.maxSendConnectionPerAccess = Long_fromValue(_xn.get("maxSendConnectionPerAccess"));
	_val.maxRcvConnectionPerAccess = Long_fromValue(_xn.get("maxRcvConnectionPerAccess"));
	_val.maxSendBandwidthPerConnection = Real_fromValue(_xn.get("maxSendBandwidthPerConnection"));
	_val.maxRcvBandwidthPerAccess = Real_fromValue(_xn.get("maxRcvBandwidthPerAccess"));
	_val.maxConnectionInNetwork = Long_fromValue(_xn.get("maxConnectionInNetwork"));
	_val.maxNumberOfAccess = Long_fromValue(_xn.get("maxNumberOfAccess"));
}
		
// -------------------------------------------------------- NetworkMessagePrivateHeader
// NetworkMessagePrivateHeader is a structure
value::Value* NetworkMessagePrivateHeader_toValue(const NetworkMessagePrivateHeader& _val) {
	value::Map* xn = value::Map::create();
	xn->add("timestamp",Long_toValue(_val.timestamp));
	xn->add("sizeTransmitted",Real_toValue(_val.sizeTransmitted));
	return xn;
}

void NetworkMessagePrivateHeader_fromValue(const value::Value* _node, NetworkMessagePrivateHeader& _val) {
	const value::Map& _xn = _node->toMap();
	_val.timestamp = Long_fromValue(_xn.get("timestamp"));
	_val.sizeTransmitted = Real_fromValue(_xn.get("sizeTransmitted"));
}
		
// -------------------------------------------------------- NetworkMessageUserHeader
// NetworkMessageUserHeader is a structure
value::Value* NetworkMessageUserHeader_toValue(const NetworkMessageUserHeader& _val) {
	value::Map* xn = value::Map::create();
	xn->add("networkId",NetworkID_toValue(_val.networkId));
	xn->add("fromId",Long_toValue(_val.fromId));
	xn->add("toId",Long_toValue(_val.toId));
	xn->add("networkMsgId",Long_toValue(_val.networkMsgId));
	xn->add("dataSize",Long_toValue(_val.dataSize));
	xn->add("category",Long_toValue(_val.category));
	return xn;
}

void NetworkMessageUserHeader_fromValue(const value::Value* _node, NetworkMessageUserHeader& _val) {
	const value::Map& _xn = _node->toMap();
	_val.networkId = NetworkID_fromValue(_xn.get("networkId"));
	_val.fromId = Long_fromValue(_xn.get("fromId"));
	_val.toId = Long_fromValue(_xn.get("toId"));
	_val.networkMsgId = Long_fromValue(_xn.get("networkMsgId"));
	_val.dataSize = Long_fromValue(_xn.get("dataSize"));
	_val.category = Long_fromValue(_xn.get("category"));
}
		
// -------------------------------------------------------- NetworkMessageUserData
///
/// ERROR NetworkMessageUserData is unrecognized by the generator - org.eclipse.emf.ecore.impl.EClassImpl@12297aa (name: unionType) (instanceClassName: null) (abstract: false, interface: false)
///
		
// -------------------------------------------------------- NetworkMessage
// NetworkMessage is a structure
value::Value* NetworkMessage_toValue(const NetworkMessage& _val) {
	value::Map* xn = value::Map::create();
	xn->add("uheader",NetworkMessageUserHeader_toValue(_val.uheader));
	xn->add("pheader",NetworkMessagePrivateHeader_toValue(_val.pheader));
	// unauthorized union type for data
	return xn;
}

void NetworkMessage_fromValue(const value::Value* _node, NetworkMessage& _val) {
	const value::Map& _xn = _node->toMap();
	NetworkMessageUserHeader_fromValue(_xn.get("uheader"), _val.uheader);
	NetworkMessagePrivateHeader_fromValue(_xn.get("pheader"), _val.pheader);
	// unauthorized union type for data
}
		
// -------------------------------------------------------- NetworkMessageDeliveryReport
// NetworkMessageDeliveryReport is a map with key type Long and value type Long
value::Value* NetworkMessageDeliveryReport_toValue(const NetworkMessageDeliveryReport& _val) {
	value::Map* _xn = value::Map::create();
	NetworkMessageDeliveryReport::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		const std::string& key = boost::lexical_cast<std::string>((*it).first);
		const value::Value& val = *Long_toValue((*it).second);
		_xn->add(key, val);
	}
	return _xn;

}

void NetworkMessageDeliveryReport_fromValue(const value::Value* _node, NetworkMessageDeliveryReport& map) {
	const value::Map& _xn = _node->toMap();
	for (value::Map::const_iterator it=_xn.begin(); it!=_xn.end(); it++) {
		const Long& key = static_cast<Long>(_xn.getInt((*it).first));
		const value::Value* _n = (*it).second;

		Long_fromValue(_n, map[key]);
	}
}


		
// -------------------------------------------------------- NetworkMessageDeliveryReports
// NetworkMessageDeliveryReports is a map with key type Long and value type NetworkMessageDeliveryReport
value::Value* NetworkMessageDeliveryReports_toValue(const NetworkMessageDeliveryReports& _val) {
	value::Map* _xn = value::Map::create();
	NetworkMessageDeliveryReports::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		const std::string& key = boost::lexical_cast<std::string>((*it).first);
		const value::Value& val = *NetworkMessageDeliveryReport_toValue((*it).second);
		_xn->add(key, val);
	}
	return _xn;

}

void NetworkMessageDeliveryReports_fromValue(const value::Value* _node, NetworkMessageDeliveryReports& map) {
	const value::Map& _xn = _node->toMap();
	for (value::Map::const_iterator it=_xn.begin(); it!=_xn.end(); it++) {
		const Long& key = static_cast<Long>(_xn.getInt((*it).first));
		const value::Value* _n = (*it).second;

		NetworkMessageDeliveryReport_fromValue(_n, map[key]);
	}
}


		
// -------------------------------------------------------- NetworkList
// NetworkList is a map with key type Long and value type Long
value::Value* NetworkList_toValue(const NetworkList& _val) {
	value::Map* _xn = value::Map::create();
	NetworkList::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		const std::string& key = boost::lexical_cast<std::string>((*it).first);
		const value::Value& val = *Long_toValue((*it).second);
		_xn->add(key, val);
	}
	return _xn;

}

void NetworkList_fromValue(const value::Value* _node, NetworkList& map) {
	const value::Map& _xn = _node->toMap();
	for (value::Map::const_iterator it=_xn.begin(); it!=_xn.end(); it++) {
		const Long& key = static_cast<Long>(_xn.getInt((*it).first));
		const value::Value* _n = (*it).second;

		Long_fromValue(_n, map[key]);
	}
}


		
// -------------------------------------------------------- NetworkMessageList
// NetworkMessageList is a vector of NetworkMessage
value::Value* NetworkMessageList_toValue(const NetworkMessageList& _val) {
	value::Set* _xn = value::Set::create();
	NetworkMessageList::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		_xn->add(NetworkMessage_toValue(*it)) ;
	}
	return _xn;
}

void NetworkMessageList_fromValue(const value::Value* _node, NetworkMessageList& vect) {
	vect.clear();
	const value::Set& _xn = _node->toSet();
	for (unsigned int _i=0; _i<_xn.size(); _i++) {
		const value::Value* _n = _xn.get(_i);
		NetworkMessage _val;
		NetworkMessage_fromValue(_n, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- NetworkDefinitions
// NetworkDefinitions is a map with key type Long and value type NetworkDefinition
value::Value* NetworkDefinitions_toValue(const NetworkDefinitions& _val) {
	value::Map* _xn = value::Map::create();
	NetworkDefinitions::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		const std::string& key = boost::lexical_cast<std::string>((*it).first);
		const value::Value& val = *NetworkDefinition_toValue((*it).second);
		_xn->add(key, val);
	}
	return _xn;

}

void NetworkDefinitions_fromValue(const value::Value* _node, NetworkDefinitions& map) {
	const value::Map& _xn = _node->toMap();
	for (value::Map::const_iterator it=_xn.begin(); it!=_xn.end(); it++) {
		const Long& key = static_cast<Long>(_xn.getInt((*it).first));
		const value::Value* _n = (*it).second;

		NetworkDefinition_fromValue(_n, map[key]);
	}
}


		
// -------------------------------------------------------- test
// test is a structure
value::Value* test_toValue(const test& _val) {
	value::Map* xn = value::Map::create();
	xn->add("fromId",Long_toValue(_val.fromId));
	xn->add("toId",Long_toValue(_val.toId));
	return xn;
}

void test_fromValue(const value::Value* _node, test& _val) {
	const value::Map& _xn = _node->toMap();
	_val.fromId = Long_fromValue(_xn.get("fromId"));
	_val.toId = Long_fromValue(_xn.get("toId"));
}
		
// -------------------------------------------------------- TestMatlabStruct2
// TestMatlabStruct2 is a structure
value::Value* TestMatlabStruct2_toValue(const TestMatlabStruct2& _val) {
	value::Map* xn = value::Map::create();
	xn->add("i",Long_toValue(_val.i));
	xn->add("j",Long_toValue(_val.j));
	xn->add("x",Real_toValue(_val.x));
	return xn;
}

void TestMatlabStruct2_fromValue(const value::Value* _node, TestMatlabStruct2& _val) {
	const value::Map& _xn = _node->toMap();
	_val.i = Long_fromValue(_xn.get("i"));
	_val.j = Long_fromValue(_xn.get("j"));
	_val.x = Real_fromValue(_xn.get("x"));
}
		
// -------------------------------------------------------- TestMatlabStruct2List
// TestMatlabStruct2List is a vector of TestMatlabStruct2
value::Value* TestMatlabStruct2List_toValue(const TestMatlabStruct2List& _val) {
	value::Set* _xn = value::Set::create();
	TestMatlabStruct2List::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		_xn->add(TestMatlabStruct2_toValue(*it)) ;
	}
	return _xn;
}

void TestMatlabStruct2List_fromValue(const value::Value* _node, TestMatlabStruct2List& vect) {
	vect.clear();
	const value::Set& _xn = _node->toSet();
	for (unsigned int _i=0; _i<_xn.size(); _i++) {
		const value::Value* _n = _xn.get(_i);
		TestMatlabStruct2 _val;
		TestMatlabStruct2_fromValue(_n, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- TestMatlabStruct
// TestMatlabStruct is a structure
value::Value* TestMatlabStruct_toValue(const TestMatlabStruct& _val) {
	value::Map* xn = value::Map::create();
	xn->add("unLong",Long_toValue(_val.unLong));
	xn->add("unReal",Real_toValue(_val.unReal));
	xn->add("unVec3",Vec3_toValue(_val.unVec3));
	xn->add("unVecteurDeLongs",Longs_toValue(_val.unVecteurDeLongs));
	xn->add("uneListe",TestMatlabStruct2List_toValue(_val.uneListe));
	return xn;
}

void TestMatlabStruct_fromValue(const value::Value* _node, TestMatlabStruct& _val) {
	const value::Map& _xn = _node->toMap();
	_val.unLong = Long_fromValue(_xn.get("unLong"));
	_val.unReal = Real_fromValue(_xn.get("unReal"));
	Vec3_fromValue(_xn.get("unVec3"), _val.unVec3);
	Longs_fromValue(_xn.get("unVecteurDeLongs"), _val.unVecteurDeLongs);
	TestMatlabStruct2List_fromValue(_xn.get("uneListe"), _val.uneListe);
}
		
// -------------------------------------------------------- TestJavaStruct2
// TestJavaStruct2 is a structure
value::Value* TestJavaStruct2_toValue(const TestJavaStruct2& _val) {
	value::Map* xn = value::Map::create();
	xn->add("i",Long_toValue(_val.i));
	xn->add("j",Long_toValue(_val.j));
	xn->add("x",Real_toValue(_val.x));
	return xn;
}

void TestJavaStruct2_fromValue(const value::Value* _node, TestJavaStruct2& _val) {
	const value::Map& _xn = _node->toMap();
	_val.i = Long_fromValue(_xn.get("i"));
	_val.j = Long_fromValue(_xn.get("j"));
	_val.x = Real_fromValue(_xn.get("x"));
}
		
// -------------------------------------------------------- TestJavaStruct2List
// TestJavaStruct2List is a vector of TestJavaStruct2
value::Value* TestJavaStruct2List_toValue(const TestJavaStruct2List& _val) {
	value::Set* _xn = value::Set::create();
	TestJavaStruct2List::const_iterator it = _val.begin();
	for (;it != _val.end(); it++) {
		_xn->add(TestJavaStruct2_toValue(*it)) ;
	}
	return _xn;
}

void TestJavaStruct2List_fromValue(const value::Value* _node, TestJavaStruct2List& vect) {
	vect.clear();
	const value::Set& _xn = _node->toSet();
	for (unsigned int _i=0; _i<_xn.size(); _i++) {
		const value::Value* _n = _xn.get(_i);
		TestJavaStruct2 _val;
		TestJavaStruct2_fromValue(_n, _val) ;
		vect.push_back(_val);
	}
}


		
// -------------------------------------------------------- TestJavaStruct
// TestJavaStruct is a structure
value::Value* TestJavaStruct_toValue(const TestJavaStruct& _val) {
	value::Map* xn = value::Map::create();
	xn->add("unLong",Long_toValue(_val.unLong));
	xn->add("unReal",Real_toValue(_val.unReal));
	xn->add("unVec3",Vec3_toValue(_val.unVec3));
	xn->add("unVecX",VecX_toValue(_val.unVecX));
	xn->add("unVecteurDeLongs",Longs_toValue(_val.unVecteurDeLongs));
	xn->add("uneListe",TestMatlabStruct2List_toValue(_val.uneListe));
	return xn;
}

void TestJavaStruct_fromValue(const value::Value* _node, TestJavaStruct& _val) {
	const value::Map& _xn = _node->toMap();
	_val.unLong = Long_fromValue(_xn.get("unLong"));
	_val.unReal = Real_fromValue(_xn.get("unReal"));
	Vec3_fromValue(_xn.get("unVec3"), _val.unVec3);
	VecX_fromValue(_xn.get("unVecX"), _val.unVecX);
	Longs_fromValue(_xn.get("unVecteurDeLongs"), _val.unVecteurDeLongs);
	TestMatlabStruct2List_fromValue(_xn.get("uneListe"), _val.uneListe);
}
		

// 
// ------------------------------------------------------------------------------------
//
} // eof namespace generated

